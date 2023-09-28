#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <stddef.h>

void presentacion();
void inicializa();
void menu();
void punto();
void menulinea();
void pinlinea();
void linea();
void menucirculo();
void pincircu();
void circulo();
void pinta_circulo();
void traslacircu();
void rotarcircu();
void llenarcircu();
void menuelipse();
void elipse();
void pinelipse();
void menucuadrado();
void pincuadra();
void cuadrado();
void traslacuadra();
void rotarcuadra();
void llenarcuadra();
void menurectangulo();
void pinrectan();
void rectangulo();
void traslarectan();
void rotarrectan();
void llenarrectan();
void menutriangulo();
void pintriang();
void triangulo();
void traslatriang();
void rotartriang();
void llenartriang();
void menuestrella();
void pinestrella();
void estrella();
struct palettetype palette;
float razon, PI;
int MaxX, MaxY, colorfondo;
float d, x_c, y_c, p1, p2;
int radio, dl, xf, yf;
int r, color, xt, yt;
int punto1, punto2, i, j, px1, py1, px2, py2, x1, y1;
int a, b, c, w, y, x, x_cen, y_cen, pto1, pto2, xt, yt;
/***********************************************************************/
/*                       DETECTA EL MODO GRAFICO                       */
/***********************************************************************/

void inicializa(void)
{
 int MaxColor;
 /*int MaxX;
 int MaxY;*/
 int dispgraf = DETECT, modigraf,coderror;
initgraph(&dispgraf, &modigraf, "c:\\borlandc\\bgi");
 coderror =graphresult();
 if(coderror != grOk)
   {
    printf("Error de a funci¢n gr dfica: ", grapherrormsg(coderror));
    printf("Pulse cualquier letra para continuar ");
    getch();
    exit(1);
   }
 getpalette(&palette);		     /* Lee la paleta */
 MaxColor = getmaxcolor()+1;	     /* Lee el # maximo de colores */
 setbkcolor(DARKGRAY);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
 setcolor(YELLOW);
 outtextxy(130,70, " CONFIGURACION DE LA PANTALLA ");
 setcolor(BLUE);
 line(0,150, 640, 150);
 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
 setcolor(YELLOW);
 gotoxy(25,14); printf("Numero de colores = %d  ", MaxColor);
 MaxX = getmaxx();		    /* Lee tama¤o de la pantalla */
 MaxY = getmaxy();
 gotoxy(25,16);
 printf("La longitud de la pantalla  : %d,  %d", MaxX, MaxY);
 }

 /*************************************************************************/
 /*                            MENU  PRINCIPAL                            */
 /*************************************************************************/
 void main()
 {
  PI = 3.1416;
  clrscr();
  inicializa();
  getch();
  cleardevice();
  presentacion();
  setbkcolor(BLACK);
  menu();
  cleardevice();
 }

/***********************************************************************/
/*                          RUTINA PRESENTACION                        */
/***********************************************************************/

void presentacion()
{
  char n;
   setbkcolor(DARKGRAY);
   setcolor(BLUE);
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
   outtextxy(30, 20,  "    UNIVERSIDAD ANTONIO NARINO  ");
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
   setcolor(LIGHTMAGENTA);
   outtextxy(136, 58,  "    INGENIERIA DE SISTEMAS    ");
   outtextxy(125, 80,  "        OCTAVO  SEMESTRE       ");
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 5);
   setcolor(YELLOW);
   outtextxy(5, 202, "  COMPUTACION  GRAFICA  ");
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   setcolor(BLUE);
   outtextxy(150, 320, "       PRESENTADO   POR   :     ");
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
   setcolor(LIGHTMAGENTA);
   outtextxy(76, 390, "       STELLA Y MARISOL    ");
   getch();
   cleardevice();
 }
/***********************************************************************/
/*                          RUTINA MENU                                */
/***********************************************************************/

void menu()
{
 char n=0;
 while(n!='9')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   gotoxy(25,3);   printf("  UNIVERSIDAD ANTONIO NARI¥O  ");
   gotoxy(25,4);   printf("    INGENIERIA DE SISTEMAS    ");
   gotoxy(25,6);   printf("     COMPUTACION  GRAFICA     ");
   setcolor(BLUE);
   line(2, 101, 630, 101);
   gotoxy(30,13);  printf(" 1.   Linea   ");
   gotoxy(30,14);  printf(" 2.   C¡rculo");
   gotoxy(30,15);  printf(" 3.   Elipse");
   gotoxy(30,16);  printf(" 4.   Cuadrado");
   gotoxy(30,17);  printf(" 5.   Rectangulo");
   gotoxy(30,18);  printf(" 6.   Tri ngulo");
   gotoxy(30,19);  printf(" 7.   Estrella de David ");
   gotoxy(30,20);  printf(" 8.   Salir           ");
   setcolor(BLUE);
   line(2, 375, 630, 375);
   gotoxy(28,25);  printf(" Digite su opci¢n  [ ]");
   gotoxy(48,23);  n=getche();
   switch (n)
    {
     case '1' : menulinea(); break;
     case '2' : menucirculo(); break;
     case '3' : menuelipse(); break;
     case '4' : menucuadrado(); break;
     case '5' : menurectangulo(); break;
     case '6' : menutriangulo(); break;
     case '7' : menuestrella(); break;
     case '8' : exit(1);    break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

 /***********************************************************************/
 /*                      RUTINA DIBUJA EL PUNTO                         */
 /***********************************************************************/

 void punto(int x, int y, int color)
 {
  union REGS r;
  r.h.ah = 0x0c;
  r.h.al = color;
  r.h.bh = 0;
  r.x.dx = y;
  r.x.cx = x;
  int86(0x10, &r, &r);
}

/***********************************************************************/
/*                         MENU DE LA LINEA                            */
/***********************************************************************/
void menulinea()
{
 char n=0;
 while(n!='4')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);   printf(" MENU DE OPCIONES DE LA LINEA");
   gotoxy(30,12);   printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,20);  printf(" Digite su opci¢n  [ ]");
   gotoxy(65,20);  n=getche();
   switch (n)
    {
     case '1' : pinlinea();    break;
     /*case '2' : traslalinea(); break;
     case '3' : rotarlinea();  break;*/
     case '4' : menu(1);       break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

/*************************************************************************/
/*                  RUTINA CAPTURA DATOS PARA LA LINEA                   */
/*************************************************************************/

void pinlinea()
{
 int x, y, x1, y1, dtras;
 int color;
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(25,4); printf("D I B U J O  D E  LA  L I N E A");
 linea(2,101, 630, 101, 5);
 gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
 gotoxy(35,10); scanf("%d", &x);
 gotoxy(47,10); scanf("%d", &y);
 if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
    }
 gotoxy(15,12); printf("Punto final    X1=        Y1=   ");
 gotoxy(35,12); scanf("%d", &x1);
 gotoxy(47,12); scanf("%d", &y1);
 if(x1 > MaxX || x1 < 0 || y1 > MaxY || y1 < 0)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
    }
 gotoxy(15,14); printf("Escriba el n£mero del color =    ");
 gotoxy(45,14); scanf("%d", &color);
 if(color > 16 || color < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 gotoxy(15,16); printf("distancia de traslaci¢n  =    ");
 gotoxy(35,16); scanf("%d", &dtras);
 if(dtras > MaxX || dtras < 0)
    {
       gotoxy(20,24); printf("error en el punto de traslaci¢n");
       getch();
       return;
    }
 cleardevice();
 linea(x, y, x1, y1, color);
 getch();
 linea(x+dtras, y+dtras, x1+dtras, y1+dtras, color);
 getch();
 }
 /************************************************************************/
 /*                    LINEA METODO DE BRESSENHAM                        */
 /************************************************************************/

 void linea(int x, int y, int x1, int y1, int color)
 {
  register int r, distancia;
  int xerr=0, yerr=0, dx, dy;
  int incx, incy;
  /* calcula las distancias en ambas direcciones */
  dx=x1-x;
  dy=y1-y;

  /* calcula la direcci¢n del incremento */

  if(dx > 0)
       incx = 1;
  else
       if(dx==0)
	 incx=0;
       else incx=-1;
  if(dy > 0)
       incy=1;
  else
      if(dy==0)
	  incy=0;
      else
	 incy=-1;
   /* determina que distancia es mayor  */

  dx=abs(dx);
  dy=abs(dy);
  if(dx>dy)
      distancia=dx;
  else
      distancia=dy;

   /* dibuja la linea */

  for(r=0; r<=distancia+1; r++)
   {
     putpixel(x, y, color);
     xerr+=dx;
     yerr+=dy;
     if(xerr>distancia)
      {
       xerr-=distancia;
       x+=incx;
      }
     if(yerr>distancia)
      {
       yerr-=distancia;
       y+=incy;
      }
   }
 }

/***********************************************************************/
/*                         MENU DEL CIRCULO                            */
/***********************************************************************/
void menucirculo()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);   printf(" MENU DE OPCIONES DEL CIRCULO");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(40,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(60,22);  n=getche();
   switch (n)
    {
     case '1' : pincircu();    break;
     case '2' : traslacircu(); break;
     case '3' : rotarcircu();  break;
     case '4' : llenarcircu(); break;
     case '5' : menu(1);       break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

 /*******************************************************************/
 /*              RUTINA QUE CAPTURA LOS DATOS DEL CIRCULO           */
 /*******************************************************************/

void pincircu()
{
 /*int x, y, radio;
 int color;*/
 cleardevice();
 setcolor(MAGENTA);
 rectangle(3, 3, 630, 465);
 gotoxy(22,4); printf("D I B U J O   D E L   C I R C U L O");
 setcolor(MAGENTA);
 line(2,101, 630, 101);
 gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
 gotoxy(35,10); scanf("%d", &x);
 gotoxy(47,10); scanf("%d", &y);
 if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
     }
 gotoxy(15,12);  printf("Escriba el radio  =  ");
 gotoxy(35,12);  scanf("%d",&radio);
 if (radio+x > MaxX || radio+y > MaxY || x-radio<0 || y-radio<0)
    {
      gotoxy(20,24);   printf("radio muy grande");
      getch();
      return;
     }
 gotoxy(15,14); printf("Escriba el numero del color =    ");
 gotoxy(45,14); scanf("%d", &color);
 if(color > 16 || color < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 cleardevice();
 circulo(x, y, radio, color);
 getch();
 cleardevice();
 }

 /*******************************************************************/
 /*                 RUTINA QUE DIBUJA EL CIRCULO                    */
 /*******************************************************************/

 void circulo(int coordX, int coordY, int radio, int color)
 {
   int x1, y1, teta;
   razon = 1.0;
   y1 = radio;
   teta = 3 - 2*radio;
   for(x1=0; x1<y1;)
     {
       pinta_circulo(x1, y1, coordX, coordY, color);
       if (teta < 0)
	   teta += 4*x1+6;
       else
	 {
	   teta += 4 * (x1-y1)+10;
	   y1--;
	 }
       x1++;
     }
     x1 = y1;
     if(y1)pinta_circulo(x1, y1, coordX, coordY, color);
 }

/**********************************************************************/
/*                RUTINA QUE HACE EL CIRCULO                          */
/**********************************************************************/

void pinta_circulo(int xl, int yl, int x_centro, int y_centro, int color1)
{
   putpixel (x_centro+xl, y_centro+yl, color1);
   putpixel (x_centro-xl, y_centro+yl, color1);
   putpixel (x_centro+xl, y_centro-yl, color1);
   putpixel (x_centro-xl, y_centro-yl, color1);
   putpixel (x_centro+yl, y_centro+xl, color1);
   putpixel (x_centro-yl, y_centro+xl, color1);
   putpixel (x_centro+yl, y_centro-xl, color1);
   putpixel (x_centro-yl, y_centro-xl, color1);
   delay(30);
 }
/***********************************************************************/
/*                         RUTINA DE TRASLADAR                         */
/***********************************************************************/
void traslacircu()
{
 int px=0, py=0, j, i, col;
 pincircu();
 cleardevice();
 gotoxy(40,8); printf("TRASLACION DEL CIRCULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&px);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&py);
 getch();
 cleardevice();
 circulo(x, y, radio, color);
 for(i = x-radio; i <= (x+radio); i++)
  {
   for(j = y-radio; j <= (y+radio); j++)
     {
       col = getpixel(i,j);
       if(col!=0)
	{
	 putpixel(i-x+px, j-y+py, col);
	 delay(20);
	}
     }
  }
}
/***********************************************************************/
/*                         RUTINA DE ROTAR CIRCULO                     */
/***********************************************************************/
void rotarcircu()
{
 int angulo = 0;
 int px, py, i, j, posx, posy, col;
 float radian;
 pincircu();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(40,8);  printf("ROTACION DEL CIRCULO ");
 gotoxy(30,12); printf("Angulo de rotaci¢n =  ");
 gotoxy(45,12); scanf("%d",&angulo);
 gotoxy(30,14); printf("Punto en X =  ");
 gotoxy(45,14); scanf("%d",&px);
 gotoxy(30,16); printf("Punto en Y =  ");
 gotoxy(45,16); scanf("%d",&py);
 getch();
 cleardevice();
 circulo(x_c, y_c, radio, color);
 radian=(float)((3.1416/180)*angulo);
 for(j = y_c-r; j <= (y_c+r); j++)
  for(i = x_c-r; i <= (x_c+r); i++);
   {
    col= getpixel(i,j);
    if(col!=0)
     {
       posx = px + (int) ((i-x_c)*cos(radian)+(j-y_c)*sin(radian));
       posy = py + (int) ((j-y_c)*cos(radian)-(i-x_c)*sin(radian));
       putpixel(posx, posy, col);
       getch();
     }
   }
}
/***********************************************************************/
/*                 RUTINA DE LLENADO DEL CIRCULO                       */
/***********************************************************************/
void llenarcircu()
{
 int x1 = getmaxx();
 int y1 = getmaxy();
 d=0;
 pincircu();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(40,8); printf("LLENADO DEL CIRCULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&p1);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&p2);
 gotoxy(30,16); printf("Escriba el color de fondo =    ");
 gotoxy(60,16); scanf("%d", &colorfondo);
 if(colorfondo > 16 || colorfondo < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 circulo(x, y, radio, color);
 putpixel(p1, p2, colorfondo);
 getch();
 d=sqrt(((p1-x)*(p1-x))+((p2-y)*(p2-y)));
 if(d>r)
  {
   for(a=0; a<=x1; a++)
    for(b=0; b<=y1; b++)
     {
       d=sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
       if(d>r)
	 putpixel(a,b, colorfondo);
       else
	 putpixel(a,b, BLACK);
      }
   }
  else
   {
    for(a=0; a<=x1; a++)
      for(b=0; b <= y1; b++)
       {
	d=sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
	if(d>r)
	  putpixel(a,b, BLACK);
	else
	  putpixel(a,b, colorfondo);
	}
    }
 }

/***********************************************************************/
/*                         MENU DE LA ELIPSE                           */
/***********************************************************************/
void menuelipse()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);   printf(" MENU DE OPCIONES DE LA ELIPSE");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(60,22);  n=getche();
   switch (n)
    {
     case '1' : pinelipse();    break;
     /*case '2' : traslaelipse(); break;
     case '3' : rotarelipse();  break;
     case '4' : llenarelipse(); break;*/
     case '5' : menu(1);        break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }
 /******************************************************************/
 /*           RUTINA QUE CAPTURA LOS DATOS DE LA ELIPSE            */
 /******************************************************************/

void pinelipse()
{
 int a, b, xtras, ytras;
 int color;
 x1=0;
 y1=360;
 cleardevice();
 setcolor(LIGHTBLUE);
 rectangle(3, 3, 630, 465);
 gotoxy(23,4); printf("D I B U J O   D E  L A  E L I P S E");
 line(2,101, 630, 101);
 gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
 gotoxy(35,10); scanf("%d", &x);
 gotoxy(47,10); scanf("%d", &y);
 if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
    }/*
 gotoxy(3,22); printf("Los valores de X1 y Y1 se dan en grados, cuando X1  sea 0, Y1 debe ser 360");
 gotoxy(3,23); printf("y cuando X1 sea 360, Y1 debe ser 0, para que se muestra la elipse completa ");
 getch();
 gotoxy(3,22); printf("                                                                           ");
 gotoxy(3,23); printf("                                                                           ");
 gotoxy(15,12); printf("Inicio y Fin en grados   X1=      Y1=  ");
 gotoxy(44,12); scanf("%d", &x1);
 gotoxy(53,12); scanf("%d", &y1);
 if(x1 != 0 || x1 != 360 || y1 != 0 || y1 !=360)
    {
       gotoxy(20,24); printf("error en los grados");
       getch();
       return;
    }*/
 gotoxy(15,14);  printf("Radio en X =  ");
 gotoxy(35,14);  scanf("%d",&a);
 if(a+x > MaxX || x-a < 0)
    {
      gotoxy(20,24);  printf("Radio en la coordenada X grande");
      getch();
      return;
    }
 gotoxy(15,16);  printf("Radio en Y =   ");
 gotoxy(35,16);  scanf("%d", &b);
 if(b+y > MaxY || y-b < 0)
   {
     gotoxy(20,24);  printf("Radio en la coordenada Y grande");
     getch();
     return;
   }
 gotoxy(15,18); printf("Escriba el numero del color =    ");
 gotoxy(45,18); scanf("%d", &color);
 if(color > 16 || color < 0)
    {
       gotoxy(20,24); printf("Error en el n£mero del color");
       getch();
       return;
    }
 gotoxy(15,16); printf("Punto traslaci¢nl  X =        Y =   ");
 gotoxy(35,16); scanf("%d", &xtras);
 /*gotoxy(47,16); scanf("%d", &ytras);*/
 if(xtras > MaxX || xtras < 0 /*|| ytras > MaxY || ytras < 0*/)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
    }

 cleardevice();
 setcolor(color);
 elipse(x, y, a, b, color);
 getch();
 cleardevice();
 }

 /*******************************************************************/
 /*                    RUTINA QUE DIBUJA LA ELIPSE                  */
 /*******************************************************************/

 void elipse(int x, int y, int a, int b)
 {
  register xx, yy;
  float i, teta;
  i=0.95/(a+b);
  for(teta=0; teta<(PI/2.0); teta+=i)
   {
     xx = (int) (a*cos(teta));
     yy = (int) (b*sin(teta));
     punto(xx+x,  -yy+y, 2);
     punto(xx+x,  yy+y, 2);
     punto(-xx+x, -yy+y, 2);
     punto(-xx+x, yy+y, 2);
    }
 }
/***********************************************************************/
/*                         MENU DEL CUADRADO                           */
/***********************************************************************/
void menucuadrado()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(30,8);  printf(" MENU DE OPCIONES DEL CUADRADO");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(30,22);  n=getche();
   switch (n)
    {
     case '1' : pincuadra();    break;
     case '2' : traslacuadra(); break;
     case '3' : rotarcuadra();  break;
     case '4' : llenarcuadra(); break;
     case '5' : menu(1);        break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }


/*******************************************************************/
/*             RUTINA QUE CAPTURA LOS DATOS DEL CUADRADO           */
/*******************************************************************/
void pincuadra()
 {
  /*int x, y, dl;
  int color;*/
  cleardevice();
  setcolor(RED);
  rectangle(3, 3, 630, 465);
  gotoxy(22,4); printf("D I B U J O   D E L   C U A D R A D O");
  linea(2,101, 630, 101, 9);
  gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
  gotoxy(35,10); scanf("%d", &x);
  gotoxy(45,10); scanf("%d", &y);
  if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("Error en la coordenada");
       getch();
       return;
    }
  gotoxy(15,12); printf("Escriba la distancia =   ");
  gotoxy(39,12); scanf("%d", &dl);
  if(d > MaxX || d < 0 || d > MaxY || d+x > MaxX || d+y > MaxY)
    {
       gotoxy(20,24); printf("Distancia errada");
       getch();
       return;
     }
  gotoxy(15,14); printf("Escriba el n£mero del color =    ");
  gotoxy(45,14); scanf("%d", &color);
  if(color > 16 || color < 0)
     {
       gotoxy(20,24); printf("Error en el n£mero del color");
       getch();
       return;
     }
  cleardevice();
  cuadrado(x, y, x+dl, y+dl, color);
  getch();
  cleardevice();
 }

 /*******************************************************************/
 /*                 RUTINA QUE DIBUJA EL CUADRADO                   */
 /*******************************************************************/

 void cuadrado(comienzaX, comienzaY, finX, finY, color)
 {
   linea(comienzaX, comienzaY, finX, comienzaY, color);
   linea(comienzaX, comienzaY, comienzaX, finY, color);
   linea(comienzaX, finY, finX, finY, color);
   linea(finX, comienzaY, finX, finY, color);
 }

/***********************************************************************/
/*                 RUTINA DE TRASLACION DEL CUADRADO                   */
/***********************************************************************/
void traslacuadra()
{
 int  i, j, r;
 int px=0, py=0;
 pincuadra();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("TRASLACION DEL CUADRADO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&px);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&py);
 getch();
 cleardevice();
 cuadrado(x, y, x+dl, y+dl, color);
 for(i=x; i <= x+dl; i++)
   for(j=y; j <= y+dl; j++)
    {
     color=getpixel(i,j);
     if(color!=0)
      {
       putpixel(i-x+px, j-y+py, color);
       delay(20);
      }
    }
}
/***********************************************************************/
/*                 RUTINA DE ROTACION DEL CUADRADO                    */
/***********************************************************************/
void rotarcuadra()
{
 int angulo=0;
 int px, py, i, j, posx, posy;
 float radian;
 pincuadra();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("ROTACION DEL CUADRADO");
 gotoxy(30,12); printf("Angulo de rotaci¢n =  ");
 gotoxy(45,12); scanf("%d",&angulo);
 gotoxy(30,14); printf("Punto en X =  ");
 gotoxy(45,14); scanf("%d",&px);
 gotoxy(30,16); printf("Punto en Y =  ");
 gotoxy(45,16); scanf("%d",&py);
 getch();
 cleardevice();
 cuadrado(x, y, x+d, y+d, color);
 radian=(float)((3.1416/180)*angulo);
 for(j = y; j <= y+d; j++)
  for(i = x; i<= x+d; i++)
   {
    color=getpixel(i,j);
      if(color!=0)
	{
	 posx= px + (int)((i-x)*cos(radian)+(j-y)*sin(radian));
	 posy= py + (int)((j-y)*cos(radian)-(i-x)*sin(radian));
	 putpixel(posx, posy, color);
	 getch();
	}
   }
}

/***********************************************************************/
/*                 RUTINA DE LLENADO DEL CUADRADO                      */
/***********************************************************************/
void llenarcuadra()
{
 cleardevice();
 pincuadra();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(10,8); printf("LLENADO DEL CUADRADO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&pto1);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&pto2);
 gotoxy(30,16); printf("Escriba el color de fondo =    ");
 gotoxy(60,16); scanf("%d", &colorfondo);
 if(colorfondo > 16 || colorfondo < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 cleardevice();
 cuadrado(x, y, x+d, y+d, color);
 if(pto1 > x && pto1 < x+d && pto2 > y && pto2 < y+d)
   {
    putpixel(pto1, pto2, colorfondo);
    for(i=0; i<=x+d; i++)
      for(j=0; j<=y+d; j++)
       {
	 if((i > x && i < x+d && j > y && j < y+d))
	    putpixel(i, j, colorfondo);
	 else
	    putpixel(i, j, BLACK);
	}
     }
  else
   {
    putpixel(pto1, pto2, colorfondo);
    for(i=0; i<=x+d; i++)
      for(j=0; j<=y+d; j++)
       {
	 if((i > x && i < x+d && j > y && j < y+d))
	    putpixel(i, j, BLACK);
	 else
	    putpixel(i, j, colorfondo);
	}
    }
 }


/***********************************************************************/
/*                         MENU DEL RECTANGULO                          */
/************************************************************************/
void menurectangulo()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);  printf(" MENU DE OPCIONES DEL RECTANGULO");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(60,22);  n=getche();
   switch (n)
    {
     case '1' : pinrectan();    break;
     case '2' : traslarectan(); break;
     case '3' : rotarrectan();  break;
     case '4' : llenarrectan(); break;
     case '5' : menu(1);        break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

/*********************************************************************/
/*            RUTINA QUE CAPTURA LOS DATOS DEL RECTANGULO            */
/*********************************************************************/
void pinrectan()
{
 /*int x, y, x1, y1, d;
 int color, colorfondo;*/
 cleardevice();
 setcolor(GREEN);
 rectangle(3, 3, 630, 465);
 gotoxy(22,4); printf("D I B U J O  D E L  R E C T A N G U L O");
 line(2,101, 630, 101);
 gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
 gotoxy(35,10); scanf("%d", &x);
 gotoxy(45,10); scanf("%d", &y);
 if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("Error en la coordenada");
       getch();
       return;
    }
 gotoxy(15,12); printf("Punto final    X1=        Y1=   ");
 gotoxy(35,12); scanf("%d", &x1);
 gotoxy(45,12); scanf("%d", &y1);
 if(x1 > MaxX || x1 < 0 || y1 > MaxY || y1 < 0)
    {
       gotoxy(20,24); printf("Error en la coordenada");
       getch();
       return;
    }
 gotoxy(15,14); printf("Escriba el n£mero del color =    ");
 gotoxy(45,14); scanf("%dl", &color);
 if(color > 16 || color < 0)
    {
       gotoxy(20,24); printf("Error en el n£mero del color");
       getch();
       return;
    }
 cleardevice();
 rectangulo(x, y, x1, y1, color);
 getch();
 cleardevice();
 }

 /*********************************************************************/
 /*                  RUTINA QUE DIBUJA EL RECTANGULO                  */
 /*********************************************************************/

 void rectangulo(comienzaX, comienzaY, finX, finY, color)
 {
   linea(comienzaX, comienzaY, finX, comienzaY, color);
   linea(comienzaX, comienzaY, comienzaX, finY, color);
   linea(comienzaX, finY, finX, finY, color);
   linea(finX, comienzaY, finX, finY, color);
 }
/*********************************************************************/
/*                RUTINA DE TRASLACION DEL RECTANGULO                */
/*********************************************************************/
 void traslarectan()
{
 int i, j;
 int px=0, py=0;
 pinrectan();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("TRASLACION DEL RECTANGULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&px);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&py);
 getch();
 cleardevice();
 rectangulo(x, y, x1, y1, color);
 for(i=x; i <= x1; i++)
  {
    for(j=y; j <= y1; j++)
    {
      color=getpixel(i,j);
      if(color!=0)
      {
	putpixel(i-x+px, j-y+py, color);
	delay(120);
       }
    }
  }
}
/***********************************************************************/
/*                 RUTINA DE ROTACION DEL RECTANGULO                   */
/***********************************************************************/
void rotarrectan()
{
 int angulo = 0;
 int px, py, i, j, posx, posy;
 float radian;
 pinrectan();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("ROTACION DEL RECTANGULO");
 gotoxy(30,12); printf("Angulo de rotaci¢n =  ");
 gotoxy(45,12); scanf("%d",&angulo);
 gotoxy(30,14); printf("Punto en X =  ");
 gotoxy(45,14); scanf("%d",&px);
 gotoxy(30,16); printf("Punto en Y =  ");
 gotoxy(45,16); scanf("%d",&py);
 getch();
 cleardevice();
 rectangulo(x, y, x1, y1, color);
 radian=(float)((3.1416/180)*angulo);
 for(j = y; j <= y1; j++)
  for(i = x; i<= x1; i++)
   {
    color=getpixel(i,j);
    posx = px + (int)((i-x)*cos(radian)+(j-y)*sin(radian));
    posy = py + (int)((j-y)*cos(radian)-(i-x)*sin(radian));
    putpixel(posx, posy, color);
    getch();
   }
}

/***********************************************************************/
/*                 RUTINA DE LLENADO DEL RECTANGULO                    */
/***********************************************************************/
void llenarrectan()
{
 int i, j, colorfondo;
 cleardevice();
 pinrectan();
 rectangle(x, y, x1, y1);
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("LLENADO DEL RECTANGULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&pto1);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&pto2);
 gotoxy(30,16); printf("Escriba el color de fondo =    ");
 gotoxy(60,16); scanf("%d", &colorfondo);
 if(colorfondo > 16 || colorfondo < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 rectangulo(x, y, x1, y1, color);
 if(pto1 > x && pto1 < x1 && pto2 > y && pto2 < y1)
   {
    putpixel(pto1, pto2, colorfondo);
    for(i=0; i<=xt; i++)
      for(j=0; j<=yt; j++)
       {
	 if((i > x && i < x1 && j > y && j < y1))
	    putpixel(i, j, colorfondo);
	 else
	    putpixel(i, j, BLACK);
	}
     }
  else
   {
    putpixel(pto1, pto2, colorfondo);
    for(i=0; i<=xt; i++)
      for(j=0; j<=yt; j++)
       {
	 if((i > x && i < x1 && j > y && j < y1))
	    putpixel(i, j, BLACK);
	 else
	    putpixel(i, j, colorfondo);
	}
    }
 }


 /***********************************************************************/
/*                         MENU DEL TRIANGULO                           */
/************************************************************************/
void menutriangulo()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);  printf(" MENU DE OPCIONES DEL TRAINGULO");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(75,22);  n=getche();
   switch (n)
    {
     case '1' : pintriang();    break;
     case '2' : traslatriang(); break;
     case '3' : rotartriang();  break;
     case '4' : llenartriang(); break;
     case '5' : menu(1);        break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

/*********************************************************************/
/*         RUTINA QUE CAPTURA LOS DATOS DEL TRIANGULO                */
/*********************************************************************/
void pintriang()
 {
/*  int x, y, d, m;
  int color;*/
  cleardevice();
  rectangle(3, 3, 630, 465);
  gotoxy(21,4); printf("D I B U J O   D E L   T R I A N G U L O");
  line(2,101, 630, 101);
  gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
  gotoxy(35,10); scanf("%d", &x);
  gotoxy(45,10); scanf("%d", &y);
  if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("Error en la coordenada");
       getch();
       return;
    }
  gotoxy(15,12); printf("Escriba la distancia =   ");
  gotoxy(39,12); scanf("%d", &dl);
  if(dl > MaxX || dl < 0 || dl > MaxY || y-dl < 0)
    {
       gotoxy(20,24); printf("Distancia muy grande");
       getch();
       return;
    }
  gotoxy(15,14); printf("Escriba el n£mero del color =    ");
  gotoxy(45,14); scanf("%d", &color);
  if(color > 16 || color < 0)
     {
       gotoxy(20,24); printf("Error en el n£mero del color");
       getch();
       return;
     }
  cleardevice();
  triangulo(x, y, x+dl, y, dl, color);
  getch();
  cleardevice();
 }
 /*******************************************************************/
 /*                    RUTINA QUE DIBUJA EL TRIANGULO               */
 /*******************************************************************/

void triangulo(comienzaX, comienzaY, finX, finY, dl, color)
{
  linea(comienzaX, comienzaY, finX, comienzaY, color);
  linea(comienzaX, comienzaY, comienzaX+dl/2, finY-dl, color);
  linea(comienzaX+dl/2, finY-dl, finX, finY, color);
}
/*   triangulo rectangulo
{
  linea(comienzaX, comienzaY, finX, comienzaY, color);
  linea(comienzaX, comienzaY, comienzaX, finY-d, color);
  linea(comienzaX, finY-d, finX, finY, color);
}                      */

/*********************************************************************/
/*                RUTINA DE TRASLACION DEL TRIANGULO                 */
/*********************************************************************/
void traslatriang()
{
 int i, j;
 int px=0, py=0;
 pintriang();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("TRASLACION DEL TRIANGULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&px);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&py);
 getch();
 cleardevice();
 triangulo(x, y, x+dl, y, dl, color);
 for(i = x; i <= x+dl ; i++)
  for(j=y; j <=y; j++)
   {
     color= getpixel(i,j);
     if(color!=0)
	{
	  putpixel(i-a+px, j-b+py, color);
	  delay(200);
	}
   }
}

/***********************************************************************/
/*                 RUTINA DE ROTACION DEL TRIANGULO                    */
/***********************************************************************/
void rotartriang()
{
 int angulo = 0;
 int px, py, i, j, posx, posy, color;
 float radian;
 pintriang();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("ROTACION DEL TRIANGULO");
 gotoxy(30,12); printf("Angulo de rotaci¢n =  ");
 gotoxy(45,12); scanf("%d",&angulo);
 gotoxy(30,14); printf("Punto en X =  ");
 gotoxy(45,14); scanf("%d",&px);
 gotoxy(30,16); printf("Punto en Y =  ");
 gotoxy(45,16); scanf("%d",&py);
 getch();
 cleardevice();
 triangulo();
 radian=(float)((3.1416/180)*angulo);
 for(j = b; j <= d; j++)
  for(i = a; i<= c; i++)
   {
    color=getpixel(i,j);
    posx = px + (int)((i-a)*cos(radian)+(j-b)*sin(radian));
    posy = py + (int)((j-b)*cos(radian)-(i-a)*sin(radian));
    putpixel(posx, posy, color);
    getch();
   }
}

/***********************************************************************/
/*                 RUTINA DE LLENADO DEL TRIANGULO                      */
/***********************************************************************/
void llenartriang()
{
 int xl, yl, i, j, colorfondo;
 cleardevice();
 pintriang();
 triangulo();
 cleardevice();
 rectangle(3, 3, 630, 465);
 gotoxy(20,8); printf("LLENADO DEL TRIANGULO");
 gotoxy(30,12); printf("Punto en X =  ");
 gotoxy(45,12); scanf("%d",&xl);
 gotoxy(30,14); printf("Punto en Y =  ");
 gotoxy(45,14); scanf("%d",&yl);
 gotoxy(30,16); printf("Escriba el color de fondo =    ");
 gotoxy(60,16); scanf("%d", &colorfondo);
 if(colorfondo > 16 || colorfondo < 0)
    {
       gotoxy(20,24); printf("error en el n£mero del color");
       getch();
       return;
    }
 triangulo();
 if(xl > x && xl < x1 && yl > y && yl < y1)
   {
    putpixel(xl, yl, colorfondo);
    for(i=0; i<=xl; i++)
      for(j=0; j<=yl; j++)
       {
	 if((i > x && i < x+d && j > y && j < y+d))
	    putpixel(i, j, colorfondo);
	 else
	    putpixel(i, j, BLACK);
	}
     }
  else
   {
    putpixel(xl, yl, colorfondo);
    for(i=0; i<=xl; i++)
      for(j=0; j<=yl; j++)
       {
	 if((i > x && i < x+d && j > y && j < y+d))
	    putpixel(i, j, BLACK);
	 else
	    putpixel(i, j, colorfondo);
	}
    }
 }

/************************************************************************/
/*                         MENU DE LA ESTRELLA DE DAVID                 */
/************************************************************************/
void menuestrella()
{
 char n=0;
 while(n!='5')
 {
   cleardevice();
   rectangle(3, 3, 630, 465);
   setcolor(BLUE);
   gotoxy(20,8);  printf(" MENU DE OPCIONES DE LA ESTRELLA DE DAVID");
   gotoxy(30,12);  printf(" 1.   Dibujar       ");
   gotoxy(30,14);  printf(" 2.   Trasladar     ");
   gotoxy(30,16);  printf(" 3.   Rotar         ");
   gotoxy(30,18);  printf(" 4.   Llenado       ");
   gotoxy(30,20);  printf(" 5.   Salir         ");
   setcolor(BLUE);
   gotoxy(30,22);  printf(" Digite su opci¢n  [ ]");
   gotoxy(60,22);  n=getche();
   switch (n)
    {
     case '1' : pinestrella();    break;
/*     case '2' : traslaestrella(); break;
     case '3' : rotarestrella();  break;
     case '4' : llenarestrella(); break;*/
     case '5' : menu(1);          break;
     default  : gotoxy(15,22); printf("Opci¢n errada");
    }
  }
 }

/*********************************************************************/
/*       RUTINA QUE CAPTURA LOS DATOS DE LA ESTRELLA DE DAVID        */
/*********************************************************************/
void pinestrella()
 {
  int x, y, d, m;
  int color;
  cleardevice();
  rectangle(3, 3, 630, 465);
  gotoxy(21,4); printf("D I B U J O  E S T R E L L A   D E  D A V I D");
  linea(2,101, 630, 101, 9);
  gotoxy(15,10); printf("Punto inicial  X =        Y =   ");
  gotoxy(35,10); scanf("%d", &x);
  gotoxy(45,10); scanf("%d", &y);
  if(x > MaxX || x < 0 || y > MaxY || y < 0)
    {
       gotoxy(20,24); printf("error en la coordenada");
       getch();
       return;
    }
  gotoxy(15,12); printf("Escriba la distancia =   ");
  gotoxy(39,12); scanf("%d", &d);
  if(d > MaxX || d < 0 || d > MaxY || y-d < 0 || x+d > MaxX || y+d > MaxY)
    {
       gotoxy(20,24); printf("distancia muy grande");
       getch();
       return;
    }
  gotoxy(15,14); printf("Escriba el n£mero del color =    ");
  gotoxy(45,14); scanf("%d", &color);
  if(color > 16 || color < 0)
     {
       gotoxy(20,24); printf("Error en el n£mero del color");
       getch();
       return;
     }
 gotoxy(15,15); printf("Distancia de traslaci¢n =   ");
 gotoxy(39,15); scanf("%d", &m);
 if(m > MaxX || m < 0 || m > MaxY || m+x > MaxX || m+y > MaxY)
    {
       gotoxy(20,24); printf("Distancia errada");
       getch();
       return;
     }
  cleardevice();
  estrella(x, y, x+d, y, d, color);
  getch();
  cleardevice();
  estrella(x+m, y+m, x+m+d, y+m, d, color);
  getch();
  cleardevice();
 }
 /*******************************************************************/
 /*              RUTINA QUE DIBUJA LA ESTRELLA DE DAVID             */
 /*******************************************************************/

void estrella(comienzaX, comienzaY, finX, finY, d, color)
{
  linea(comienzaX, comienzaY, finX, comienzaY, color);
  linea(comienzaX, comienzaY, comienzaX+d/2, finY-d, color);
  linea(comienzaX+d/2, finY-d, finX, finY, color);
  linea(comienzaX, comienzaY-d*0.70, finX, comienzaY-d*0.70, color);
  linea(comienzaX, comienzaY-d*0.70, comienzaX+d/2, finY-d*0.70+d, color);
  linea(comienzaX+d/2, finY-d*0.70+d, finX, comienzaY-d*0.70, color);
}




/********************************************************************/
/*                  RUTINA DE ESPEJO                                */
/********************************************************************/

/********************************************************************/
/*                  RUTINA DE RECORTE                               */
/********************************************************************/



