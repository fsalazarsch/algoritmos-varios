/*
   PHONE.C    Tel‚fono electr¢nico!

   Comunicaci¢n entre dos computadores por medio de un MODEM NULO, utilizando
   la l¡nea del RS-232 y la interrupci¢n 0x14 del BIOS.

   Estado del puerto serie :
   --------------------------------------------------------------------------
	 Bit                              Significado
   7 6 5 4 3 2 1 0
   --------------------------------------------------------------------------
   Registro AH (estado de l¡nea)
   1 . . . . . . .          Error de exceso de tiempo (Time Out).
   . 1 . . . . . .          Registro temporal de transmisi¢n vac¡o (TSR).
   . . 1 . . . . .          Buffer de transmisi¢n vac¡o (THR).
   . . . 1 . . . .          Error de detecci¢n de ruptura (Break).
   . . . . 1 . . .          Error de formato de trama (Framming).
   . . . . . 1 . .          Error de paridad.
   . . . . . . 1 .          Error de sobrepaso de capacidad (OverRun).
   . . . . . . . 1          Dato preparado.

   El registro AL almacena la informaci¢n del estado del MODEM.

*/

#include <conio.h>
#include <dos.h>
#include <graphics.h>

#define TRUE       1
#define FALSE      0
#define ALT_X     45   /* Valor num‚rico combinaci¢n de teclas Alt-X */
#define LFEED    '\n'  /* Avance de linea */
#define RETURN   '\r'  /* Retorno de carro */
#define BKSP       8   /* Valor ASCII tecla BackSpace */
#define UP      0x06   /* Servicio deslizamiento hacia arriba */
#define DOWN    0x07   /* Servicio deslizamiento hacia abajo  */

	 /* valores ASCII caracteres gr ficos.  */
#define ULCORNER 218   /* Up Left Corner   */
#define URCORNER 191   /* Up Right Corner  */
#define LLCORNER 192   /* Low Left Corner  */
#define LRCORNER 217   /* Low Right Corner */
#define HBAR     196   /* Horizontal Bar   */
#define VBAR     179   /* Vertical Bar     */

	 /* Capacidad de la ventana donde se visualiza la informaci¢n
	    recibida.
	 */
#define NCOLS     78   /* N£mero de columnas */
#define NROWS     10   /* N£mero de filas */

	 /* Constantes que identifican el n£mero del puerto y sus
	    posibles errores.  */
#define COM1       0   /* Puerto de comunicaciones n£mero 1 */
#define COM2       1   /* Puerto de comunicaciones n£mero 2 */
#define COM3       2   /* Puerto de comunicaciones n£mero 3 */
#define COM_OK  0x60   /* Estado del puerto OK. */
#define E_ET    0x80   /* Error de Exceso de Tiempo. */
#define E_LT    0x10   /* Error en la L¡nea de Transmisi¢n o Ruptura */
#define E_FT    0x08   /* Error de Formato de Trama */
#define E_P     0x04   /* Error de Paridad */
#define E_SC    0x02   /* Error de Sobrecarga de datos en el puerto */
#define DP      0x01   /* Dato preparado para lectura */

     /*** Definici¢n de datos y estructuras globales ***/
union REGS regs_in, regs_out;
int   col =  1,
      row = 14;  /* Posici¢n del cursor en la segunda ventana */

     /*** Prototipos de funciones ***/
void f_init_rs(void);
int  f_error(void);
int  f_test_rs(void);
char f_leer(void);
void f_escribir(char c);
void f_init(void);
void f_Status(char *str);
void f_DrawBox(int x1, int y1, int x2, int y2);
void f_beep(void);
void f_wait(char msg[]);
void f_DrawLine(int xini,int y,int xfin,int c_izq,char c_inter,int c_der);
void f_scroll(int x1, int y1, int x2, int y2, int rows, int direction);
void f_display(char ch);

void main(void)
{
   int  st;  /* Status */
   char c;
   int posy, cont;

   f_init();
   cont = 0;  /* Contador de iteraciones del n£mero de errores */
   do
   {
      f_init_rs();    /* Inicializaci¢n de la l¡nea RS-232 */
      cont++;
      if (cont == 3)
      {
	window(1,1,80,25);
	clrscr();
	cprintf("Impos¡ble inicializar el puerto de comunicaciones 2\n");
	exit(1);
      }
   } while (f_error() == TRUE);
   while(TRUE)
   {
      st = f_test_rs();   /* Comprueba la l¡nea RS-232 */
      if (st == DP)
      {                /* Caracter listo para RS-232 */
	 c = f_leer();  /* Lee car. de la l¡nea RS-232 */
	 if (f_error() == FALSE)
	    f_display(c);
      }
      if (kbhit())    /* Se ha presionado el teclado ? */
      {
	 c = getch();  /* Captura caracter digitado. */
	 if (c == 0)   /* Es una tecla extendida ? */
	 {
	    if (getch() == ALT_X)  /* Es Alt-X ? */
	    {
	       window(1,1,80,25);
	       clrscr();
	       cprintf("Chao Eduardo.   PHONE.EXE\n\n\n");
	       exit(0);
	    }
	    else
	       f_beep();
	 }
	 else
	 {
	    f_escribir(c);     /* Env¡a caracter a RS-232 */
	    if (f_error() == TRUE)
	       continue;
	    if (c == LFEED || c == RETURN)
	    {
	       posy = wherey();
	       gotoxy(1, ++posy);
	       if (posy > NROWS)
	       {
		  f_scroll(1,2,78,11,1,UP);  /* Desliza texto arriba */
		  gotoxy(1, wherey());
	       }
	    }
	    else
	       putch(c);  /* Env¡a caracter a la pantalla */
	 }
      }
   }
}


void f_init_rs(void)   /* Inicializaci¢n de la l¡nea RS-232 */
{

   regs_in.h.ah = 0;      /* N£mero de la funci¢n */
   regs_in.x.dx = COM2;
   regs_in.h.al = 0xFE;  /* 9600 bps, Paridad par, 2 bits de parada,
			       7 bits de transmisi¢n */
   int86(0x14, &regs_in, &regs_out);
}


void f_escribir(char c)
{

   regs_in.h.ah = 1;            /* N£mero de la funci¢n */
   regs_in.h.al = c;      /* Caracter a enviar a RS-232 */
   regs_in.x.dx = COM2;
   int86(0x14, &regs_in, &regs_out);
}


char f_leer(void)   /* Lee el caracter que hay en RS-232	 */
{

   regs_in.h.ah = 2;      /* N£mero de la funci¢n */
   regs_in.x.dx = COM2;
   int86(0x14, &regs_in, &regs_out);
   return(regs_out.h.al);
}


int f_test_rs(void)  /* Comprueba si car. en la l¡nea RS-232 */
{

   regs_in.h.ah = 3;      /* N£mero de la funci¢n */
   regs_in.x.dx = COM2;
   int86(0x14, &regs_in, &regs_out);
   return(regs_out.h.ah & DP);    /* Devuelve 1 si caracter est  listo */
}


int f_error(void)
{

  int sw;
  int oldx, oldy;

   oldx = wherex();   /* Captura columna de posici¢n del cursor */
   oldy = wherey();   /* Captura fila de posici¢n del cursor */
   sw = FALSE;
   if ((regs_out.h.ah & E_ET) == E_ET)
   {
      f_wait(" Error de Tiempo Excedido (Time Out).  Presione una tecla ");
      sw = TRUE;
   }
   if ((regs_out.h.ah & E_LT) == E_LT)
   {
      f_wait(" Error en la l¡nea de transmisi¢n.  Presione una tecla ");
      sw = TRUE;
   }
   if ((regs_out.h.ah & E_FT) == E_FT)
   {
      f_wait(" Error en el formato de la trama.  Presione una tecla ");
      sw = TRUE;
   }
   if ((regs_out.h.ah & E_P) == E_P)
   {
      f_wait(" Error en la paridad.  Presione una tecla ");
      sw = TRUE;
   }
   if ((regs_out.h.ah & E_SC) == E_SC)
   {
      f_wait("Error de Sobrecarga de datos en el puerto.  Presione una tecla");
      sw = TRUE;
   }
   if (sw == TRUE)
   {
      f_Status(" Presione : Ctrl-D Terminar Mensaje  Alt-X Salir ");
      window(2, 3, 79, 12);
      gotoxy(oldx, oldy);
   }
   return (sw);
}


void f_display(char ch)
{
   int oldx, oldy;

   oldx = wherex();   /* Captura columna de posici¢n del cursor */
   oldy = wherey();   /* Captura fila de posici¢n del cursor */
   switch (ch)
   {
      case RETURN :
      case LFEED  : row++;
		    col = 1;
		    break;
      default     : if (++col > NCOLS + 1)
		    {       /* Saltar a la siguiente linea */
		       row++;
		       col = 2;
		    }
   }
   if (row > NROWS + 13)
   {
      f_scroll(1, 13, 78, 22, 1, UP);
      row = NROWS + 13;
   }
   window(1, 1, 80, 25);
   gotoxy(col, row);
   putch(ch);
   window(2, 3, 79, 12);
   gotoxy(oldx, oldy);
}


void f_init(void)
{

   clrscr();
   f_DrawBox(1, 2, 80, 24);
   gotoxy(2, 2);  cprintf(" Enviando : ");
   f_DrawLine(1, 13, 80, 'Æ', 'Í','µ');
   gotoxy(32, 1); cprintf("PHONE.EXE ON COM2");
   gotoxy(2, 13); cprintf(" Recibiendo : ");
   f_Status("  Quit    Alt-X  ");
   window(2, 3, 79, 12);
}


void f_Status(char *str)
/*  Visualiza la linea de estado para modo texto.  */
{
   window(1, 1, 80, 25);
   gotoxy(1,25);
   clreol();    /*  Borra el anterior mensaje de estado  */
   textcolor(BLACK);
   textbackground(WHITE);
   gotoxy((80 - strlen(str)) / 2, 25);
   cprintf("%s", str);
   textcolor(WHITE);
   textbackground(BLACK);
}


void f_DrawBox(int x1, int y1, int x2, int y2)
 /*  Draw a box in text mode.  */
{
   int i;

   gotoxy(x1,y1);
   cprintf("%c", ULCORNER);
   gotoxy(x1,y2);
   cprintf("%c", LLCORNER);
   for(i = x1+1; i < x2; i++)
   {
     gotoxy(i,y1);
     cprintf("%c", HBAR);
     gotoxy(i,y2);
     cprintf("%c", HBAR);
   }
   cprintf("%c", LRCORNER);
   gotoxy(i,y1);
   cprintf("%c", URCORNER);
   for(i = y1+1; i < y2; i++)
   {
     gotoxy(x1,i);
     cprintf("%c", VBAR);
     gotoxy(x2,i);
     cprintf("%c", VBAR);
   }
}


void f_beep()
/*  Turn on speaker */
{
   sound(400);
   delay(25);
   nosound();
}


void f_wait(char msg[])
/* Visualiza un mensaje y espera a que se presione una tecla. */
{

   f_beep();
   f_Status(msg);
   getch();
}


void f_DrawLine(int xini,int y,int xfin,int c_izq,char c_inter,int c_der)
/* Dibuja una linea en las posiciones indicadas. */
{

   gotoxy(xini++, y);
   cprintf("%c", c_izq); /* Imprime caracter izquierdo */
   for (;xini < xfin; xini++)
      cprintf("%c", c_inter); /* Imprime caracter intermedio */
   cprintf("%c", c_der); /* Imprime caracter derecho */
}


void f_scroll(int x1, int y1, int x2, int y2, int rows, int direction)
/* Desliza el texto de la ventana hacia arriba */
{
   union REGS Regs;

   Regs.h.ah = direction; /* Servicio deslizamiento Arriba/Abajo */
   Regs.h.al = rows; /* N£mero de filas a deslizar */
   Regs.h.ch = y1;   /* Fila del extremo superior izquierdo */
   Regs.h.cl = x1;   /* Columna del extremo superior izquierdo */
   Regs.h.dh = y2;   /* Fila del extremo inferior derecho */
   Regs.h.dl = x2;   /* Columna del extremo inferior derecho */
   Regs.h.bh = 0x07; /* Atributo normal para la l¡nea en blanco */
   int86(0x10, &Regs, &Regs);   /* Desliza hacia arriba */
}

void menu(void)
{
union tecla
{
int op;
char ch[2];
}
tec;
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(YELLOW);
outtextxy(300,80,"MENU");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(200,140,"F1:Fuego");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(200,180,"F2:Inundacion");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(200,220,"F3:Caida de Fluido");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(200,260,"F4:Fallas en el sistema operacional");
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(WHITE);
outtextxy(200,300,"F5:Salir");
do
{
tec.op=Obt_tecla();
if(tec.ch[0]==0) /*Tecla especial*/
{
if (tec.ch[1]==59)
{
cleardevice();
fuego();
}
else
if (tec.ch[1]==60)
{
cleardevice();
inundacion();
}
else
if(tec.ch[1]==61)
{
cleardevice();
caidafluido();
}
else
if(tec.ch[1]==62)
{
cleardevice();
sistopera();
}
else
menu();
}
}
while(tec.ch[1]!=63);
cleardevice();
}

/*FUEGO*/
fuego(void)
{
printf("auxilio");
}

/*INUNDACION*/
inundacion(void)
{
printf("aguuuuuuuua");
}

/*FLUIDO */
caidafluido(void)
{
printf("sinnnnnn luuuuuuuz");
}

/*OPERATIVO*/
sistopera(void)
{
printf("hippppppp.......");
}

/*FUNCION PARA RECONOCER
TECLAS */
Obt_tecla(void)
{
union REGS r;
r.h.ah=0;
return int86(0x16, &r, &r);
}

