/******************************************************************************
										PROGRAMA DE REDES DE COMUNICACION
										REALIZADO POR:
										ALEXANDER DARIO FLOREZ BRUN
										RICARDO BALLESTEROS BELTRAN
										AÑO 1996
*******************************************************************************/
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <bios.h>

#define DTR         0x01    /* Encendido y preparado*/
#define RTS         0x02    /* Listo para enviar*/
#define COM1PORT    0x0000  /* Localizacion puerto COM1*/
#define COM2PORT    0x0002  /* Localizacion puerto COM2*/
#define COM1        0
#define COM2        1
#define DATA_READY  0x100
#define FALSE       0
#define TRUE        !FALSE
#define SETTINGS ( 0xE0 | 0x00 | 0x02 | 0x00)  /* 9600,N,7,1*/


void Initialize(void);
void cuadro();
void nombres(void);
void menu(void);
Obt_tecla (void);
int enviar_mensaje(void);
int enviar_archivo(void);
int abrir_archivo(void);
int recibir_archivo(void);

int GraphDriver;
int GraphMode;
int ErrorCode;
int maxx;
int maxy;
unsigned char * (fillpattern[12])=
			{"\x00\x20\x00\x00\x00\x02\x00\x00",
			"\x20\x00\x02\x00\x80\x00\x08\x00",
			"\x20\x02\x80\x08\x20\x02\x80\x08",
			"\x44\x11\x44\x11\x44\x11\x44\x11",
			"\xAA\x44\xAA\x11\xAA\x44\xAA\x11",
			"\x55\xAA\x55\xAA\x55\xAA\x55\xAA",
			"\x55\xBB\x55\xEE\x55\xBB\x55\xEE",
			"\xBB\xEE\xBB\xEE\xBB\xEE\xBB\xEE",
			"\xDF\xFF\x7F\xF7\xDF\xFD\x7F\xF7",
			"\xDF\xFF\xFD\xFF\x7F\xFF\xF7\xFF",
			"\xFF\xDF\xFF\xFF\xFF\xFD\xFF\xFF",
			"\xFF\xFF\xFF\xFF\xFF\xFF\xFF\xFF"};

/******************************************************************************
										FUNCION MAIN
*******************************************************************************/
void main()
{
	Initialize();
	nombres();
	closegraph();
	menu();
}


/******************************************************************************
										PANTALLA INICIAL
*******************************************************************************/
void nombres(void)
{
	int i,n;
	n=0;
	maxx=getmaxx();
	maxy=getmaxy();
	setcolor(9);
	for(i=1; i<3; i=i+2)
	{
	  line(0+n,0+n,maxx,0+n);
	  line(0+n,0+n,0+n,maxy);
	  line(maxx,0+n,maxx,maxy);
	  line(0+n,maxy,maxx,maxy);
	  setfillpattern(fillpattern[i],1);
	  floodfill((maxx/2),(maxy/2),9);
	  delay(100);
	  n=n+20;
	}
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(BROWN);
	outtextxy(200,40,"SOFTWARE DE COMUNICACION");
	setcolor(YELLOW);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(100,140,"MARIO SALAMANCA V     COD: 492756");
	outtextxy(100,160,"MANUEL SANTAMARIA     COD: 490574");
	outtextxy(100,180,"MARIA CRISTINA VIECCO COD: 492848");
	setcolor(WHITE);
	setcolor(YELLOW);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(120,250,"PROFESOR: ING.ROBERTO FERNANDEZ ");
	setcolor(GREEN);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(140,320,"UNIVERSIDAD ANTONIO NARI¥O");
	outtextxy(120,360,"FACULTAD INGENIERIA DE SISTEMAS");
	outtextxy(300,380,"1997");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(YELLOW);
	outtextxy(280,450,"DIGITE UNA TECLA PARA CONTINUAR.");
	getch();
}

/******************************************************************************
										FUNCION INICIALIZAR MODO GRAFICO
*******************************************************************************/

void Initialize(void)
{
	GraphDriver = DETECT;
	initgraph( &GraphDriver, &GraphMode, "" );
	ErrorCode = graphresult();
	if( ErrorCode != grOk ){
		printf(" Erro del sistema grafico: %s\n", grapherrormsg( ErrorCode ) );
		exit( 1 );
	}
}
/******************************************************************************
										CUADRO PARA PANTALLAS
*******************************************************************************/
void cuadro(void)
{
	cleardevice();
	maxx=getmaxx();
	maxy=getmaxy();
	setbkcolor(12);
	setcolor(RED);
	rectangle(50,40,600,450);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(142,102,RED);
	setfillstyle(SOLID_FILL,BLUE);
	floodfill(162,122,RED);
}

/******************************************************************************
										MENU PRINCIPAL
*******************************************************************************/
void menu(void)
{
	union tecla
	{
		int op;
		char ch[2];
	}tec;
	Initialize();
	cuadro();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(YELLOW);
	outtextxy(300,80,"M E N U");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(WHITE);
	outtextxy(200,140,"F1: Enviar mensaje");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(WHITE);
	outtextxy(200,180,"F2: Enviar archivo");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(WHITE);
	outtextxy(200,220,"F3: Recibir Archivo");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(WHITE);
	outtextxy(200,260,"F4: Salir");
	do
	{
		tec.op=Obt_tecla();
		if (tec.ch[0]==0)/*Tecla especial*/
		{
			if (tec.ch[1]==59)
			{
				cleardevice();
				enviar_mensaje();
			}
				else
					if (tec.ch[1]==60)
					{
						cleardevice();
						enviar_archivo();
					}
					else
						if (tec.ch[1]==61)
						{
							cleardevice();
							recibir_archivo();
						}
		}
		else
			menu();
	}
	while (tec.ch[1]!=62);
	cleardevice();
}

/******************************************************************************
										FUNCION PARA RECONOCER
												TECLAS
*******************************************************************************/
Obt_tecla (void)
{
	union REGS r;
	r.h.ah=0;
	return int86(0x16,&r,&r);
}
/******************************************************************************
										FUNCION ENVIAR MENSAJE
*******************************************************************************/
int enviar_mensaje(void)
{
	int entrada,
		 salida,
		 estado,
		 HECHO = FALSE,
		 far *RS232_Addr;

  cleardevice();
  /*  Determina la localizacion del puerto COM2.
		0x40:0x00 = COM1 I/O direccion del puerto
		0x40:0x02 = COM2 I/O direccion del puerto*/
  RS232_Addr = MK_FP( 0x0040, COM2PORT );
  if( !*RS232_Addr )
	 return -1;

  bioscom( 0, SETTINGS, COM2 );
  printf( "... BIOSCOM [ESC] para salir ...\n" );

  while( !HECHO )
  {
	 outportb( *RS232_Addr + 4, DTR | RTS );
	 estado = bioscom( 3, 0, COM2 ); 	 /*  Muestra el estado del pueto*/
	 if( estado & DATA_READY )
		if( (salida = bioscom( 2, 0, COM2 ) & 0x7F) != 0 )
		  putchar( salida ); /* Hay un caracter en el puerto y lo muestra*/
	 if( kbhit() ) /*  Envia al puerto cuando se digita una tecla*/
		if( (entrada = getch()) == '\x1B' )
		  HECHO = TRUE; /* Presione ESC para no enviar al puerto*/
		else
		{
			putchar(entrada);
			bioscom( 1, entrada, COM2 ); /*  Envia el caracter al puerto*/
		}
  }
  return 0;
}
/******************************************************************************
										FUNCION ENVIAR ARCHIVO
*******************************************************************************/
int enviar_archivo(void)
{
	#define CMD    2    /* read sector command */
	#define DRIVE  0    /* drive number for A: */
	#define HEAD   0    /* disk head number */
	#define TRACK  1    /* track number */
	#define SECT   1    /* sector number */
	#define NSECT  1    /* sector count */

	int result;
	char buffer[512];
	result = biosdisk(CMD, DRIVE, HEAD, TRACK, SECT, NSECT, buffer);
	if (result == 0)
		abrir_archivo();
		else
			printf("No hay disquete.\n");
	return 0;
}
/******************************************************************************
										FUNCION ABRIR ARCHIVO
*******************************************************************************/
int abrir_archivo(void)
{
	FILE *arch;
	char caract;
	int HECHO = FALSE,
		 far *RS232_Addr;

	if ((arch=fopen("a:\prueba.txt","r"))==NULL)
	{
		printf("No se puede abrir el archivo\n");
		exit (1);
	}
	caract=getc(arch);
	/*  Determina la localizacion del puerto COM2.
	0x40:0x00 = COM1 I/O direccion del puerto
	0x40:0x02 = COM2 I/O direccion del puerto*/
	RS232_Addr = MK_FP( 0x0040, COM2PORT );
	if( !*RS232_Addr )
		 return (-1);
	bioscom( 0, SETTINGS, COM2 );
	while( !HECHO )
	{
	  if(caract==64)
		HECHO = TRUE;
		else
		{
			bioscom( 1, caract, COM2 ); /*  Envia el caracter al puerto*/
			putchar(caract);
			caract=getc(arch);
		}
	}
	fclose (arch);
	delay (5000);
	menu();
	return 0;
}
/******************************************************************************
										FUNCION RECIBIR ARCHIVO
*******************************************************************************/
int recibir_archivo(void)
{
  int salida,
		estado,
		far *RS232_Addr;


	/*  Determina la localizacion del puerto COM2.
	0x40:0x00 = COM1 I/O direccion del puerto
	0x40:0x02 = COM2 I/O direccion del puerto*/
	RS232_Addr = MK_FP( 0x0040, COM2PORT );
	if( !*RS232_Addr )
		 return (-1);
	bioscom( 0, SETTINGS, COM2 );
	outportb( *RS232_Addr + 4, DTR | RTS );
	estado = bioscom( 3, 0, COM2 ); 	 /*  Muestra el estado del pueto*/
	if( estado & DATA_READY )
	if( (salida = bioscom( 2, 0, COM2 ) & 0x7F) != 0 )
	if(salida!=64)
	  putch( salida ); /* Hay un caracter en el puerto y lo muestra*/
	return 0;
}
