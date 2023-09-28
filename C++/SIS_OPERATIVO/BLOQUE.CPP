#include <time.h>
#include <complex.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream.h>
#include <alloc.h>
#include <dos.h>
#define LON 5
#include "math.h"
#ifdef __TINY__
#error BGIDEMO will not run in the tiny model.
#endif
#include <stdarg.h>
#define ESC	0x1b
#define OFF	0
void DrawBorder(void);
int    GraphDriver;
int    GraphMode;
int    MaxX, MaxY;
int    MaxColors;
int    ErrorCode;
struct palettetype palette;
void Initialize(void);
void BarDemo(void);
void PutPixelDemo(void);
void PutImageDemo(void);
void Pause(void);
void MainWindow(char *header);
void StatusLine(char *msg);
void introduccion();
void graficos ();
void presentacion();
void logo();

int bloque,y=0;
char aa[LON];
void *a;


typedef struct PILA{
     int listo[LON];
     int ejec[LON];
     int tope_listo,tope_ejec,tope_min_listo,tope_min_ejec;
     }PILA;
     PILA pila;
void llenar_lis();
void mover_carta(int,int,int,int,void *);
void dibujo2();
void llenar_list();
int b=0,f=0,i=0,j=0;
void ejecutar();
int azar(void);
void dibujo();
void dibujo1();
void modo();
void menu();
void sacar_de_ejec();
void portada();
void main()
   {
presentacion();
Initialize();
PutPixelDemo();
PutImageDemo();
introduccion();
menu();
 }

void llenar_lis()
     {
      for(int a=0;a<LON;a++)
	 {
	  pila.listo[a]=azar();

	  }
     }

void ejecutar()
    {
      for(int a=0;a<LON;a++)
	 {
	  pila.ejec[0]=pila.listo[0];
	  sacar_de_ejec();
	  //mostrar dibujo de paso de tareas a ejecutar
	 }
	  closegraph();
	  //delay(30);
	  menu();
	  getch();
      }

 void menu()
  {
   int captura;
     char *reporte[]={
	"1.Ingresar Nueva Tarea      ",
	"                            ",
	"2.Ejecutar Tarea            ",
	"                            ",
	"3.Terminar El Programa      ",};
     int i,j,luz=0,tecla=10;
     textbackground(LIGHTBLUE);textcolor(0);
     clrscr();
     gotoxy(10,5);
     for(i=4;i<=22;i++)
	{
	 for(j=10;j<=65;j++)
	    {
	     gotoxy(j,i);
	     cprintf("Û");
	    }
	}
     textcolor(BROWN);
     for(i=3;i<=21;i++)
	{
	 for(j=13;j<=68;j++)
	    {
	     gotoxy(j,i);
	     cprintf("Û");
	    }
	}
	 for(i=0;i<5;i++)
	    {
	     textcolor(GREEN);
	     gotoxy(26,i+10);
	     cprintf("%s",reporte[i]);
	    }
	 gotoxy(38,7);
	 cprintf("MENU");
	 textbackground(CYAN);textcolor(YELLOW+128);
	 gotoxy(26,tecla);
	 cprintf("%s",reporte[luz]);
	 while(captura!=27)
	      {
	       captura=getch();
	       if(captura==0)
		 {
		  captura=getch();
		  if(captura==80||captura==72)
		    {
		     textbackground(BLUE);textcolor(GREEN);
		     gotoxy(26,tecla);
		     cprintf("%s",reporte[luz]);
		     switch(captura)
			{
			 case 80: if(tecla>=14)
				    {
				     textbackground(CYAN);textcolor(YELLOW+128);
				     tecla=10;
				     gotoxy(26,tecla);
				     cprintf("%s",reporte[0]);
				     luz=0;
				     break;
				    }
				  else
				    {
				     luz+=2;tecla+=2;
				     textbackground(CYAN);textcolor(YELLOW+128);
				     gotoxy(26,tecla);
				     cprintf("%s",reporte[luz]);
				     break;
				    }
			 case 72: if(tecla==10)
				    {
				     textbackground(BLUE);textcolor(GREEN);
				     gotoxy(26,tecla);
				     cprintf("%s",reporte[luz]);
				     tecla=14;
				     textbackground(CYAN);textcolor(YELLOW+128);
				     luz=4;
				     gotoxy(26,tecla);
				     cprintf("%s",reporte[luz]);
				    }
				  else
				    {
				     tecla-=2;
				     luz-=2;
				     textbackground(CYAN);textcolor(YELLOW+128);
				     gotoxy(26,tecla);
				     cprintf("%s",reporte[luz]);
				    }
			}
		    }
		  else
		    {
		     printf("\a");
		    }
		 }
	       else
		 {
		  if(captura!=27 && captura!=13)
		    {
		     printf("\a");
		    }
		  else
		    {
		     if(captura==13)
		       {
			switch(tecla)
			      {
			       case 10: llenar_list();
					if(pila.tope_listo==1)
					  {
					   dibujo();
					   dibujo1();
					   int c,e;
					   c=imagesize(7,8,60,35);
					   a=malloc(c);
					   getimage(7,8,60,35,a);
					   // putimage(100,400,a,COPY_PUT);
					   for(e=0;e<121;e++)
					      {
					       putimage(120,10+e,a,COPY_PUT);
					       delay(3);
					      }
					  }
					else if(pila.tope_listo==2)
					  {
					   dibujo();
					   dibujo1();
					   int c,e;
					   c=imagesize(7,8,60,35);
					   a=malloc(c);
					   getimage(7,8,60,35,a);
					   putimage(120,130,a,COPY_PUT);
					   for(e=0;e<111;e++)
					      {
					       putimage(120,10+e,a,COPY_PUT);
					       delay(3);
					      }
					  }
					else if(pila.tope_listo==3)
					  {
					   dibujo();
					   dibujo1();
					   int c,e;
					   c=imagesize(7,8,60,35);
					   a=malloc(c);
					   getimage(7,8,60,35,a);
					   putimage(120,130,a,COPY_PUT);
					   putimage(120,120,a,COPY_PUT);
					   for(e=0;e<101;e++)
					      {
					       putimage(120,10+e,a,COPY_PUT);
					       delay(3);
					      }
					  }
					else if(pila.tope_listo==4)
					  {
					   dibujo();
					   dibujo1();
					   int c,e;
					   c=imagesize(7,8,60,35);
					   a=malloc(c);
					   getimage(7,8,60,35,a);
					   putimage(120,130,a,COPY_PUT);
					   putimage(120,120,a,COPY_PUT);
					   putimage(120,110,a,COPY_PUT);
					   for(e=0;e<91;e++)
					      {
					       putimage(120,10+e,a,COPY_PUT);
					       delay(5);
					      }
					  }
					else if(pila.tope_listo==5)
					  {
					   dibujo();
					   dibujo1();
					   int c,e;
					   c=imagesize(7,8,60,35);
					   a=malloc(c);
					   getimage(7,8,60,35,a);
					   putimage(120,130,a,COPY_PUT);
					   putimage(120,120,a,COPY_PUT);
					   putimage(120,110,a,COPY_PUT);
					   putimage(120,100,a,COPY_PUT);
					   for(e=0;e<81;e++)
					      {
					       putimage(120,10+e,a,COPY_PUT);
					       delay(5);
					      }
					  }
					getch();
					closegraph();
					menu();
			       case 12: clrscr();
					modo();
					ejecutar();
					exit(0);
			       case 14: exit(0);					exit(0);
			      }
		       }
		    }
		 }
	      }
	  }

void sacar_de_ejec()
   {
   dibujo();
   dibujo1();
   void *a,*f;
   char fontstr[20];
   int c,e,g;
   c=imagesize(7,8,60,35);
   a=malloc(c);
   getimage(7,8,60,35,a);
   putimage(120,130,a,COPY_PUT);
   g=imagesize(500,0,578,72);
   f=malloc(g);
   getimage(500,0,578,72,f);
   putimage(25,0,f,COPY_PUT);
    if(pila.listo[1]>0)
    putimage(120,130,a,COPY_PUT);
    if(pila.listo[2]>0)
    putimage(120,120,a,COPY_PUT);
    if(pila.listo[3]>0)
    putimage(120,110,a,COPY_PUT);
    if(pila.listo[4]>0)
    putimage(120,100,a,COPY_PUT);
    if(pila.listo[5]>0)
    putimage(120,90,a,COPY_PUT);

    if(pila.ejec[0]>10&&pila.listo[1]>10)
      {
       //mostrar grafico de despacho de tarea de e/s
       pila.ejec[0]=0;
       for(int b=0;b<LON;b++)
	  {
	   pila.listo[b]=pila.listo[b+1];
	  }
      mover_carta(3,410,120,10,a);
      mover_carta(2,210,120,420,a);
// pila.listo[pila.tope_listo]=azar();
      setcolor(YELLOW);
      settextstyle(3,0,3);
      moveto(250,250);
      outtext("Este proceso E/S dura ");
      itoa(pila.listo[0],fontstr, 5);
      outtextxy(200,250,fontstr);
      moveto(250,260);
      outtext("En ejecucion");
      delay(100*pila.listo[pila.tope_listo]);
      mover_carta(1,120,330,420,a);
      mover_carta(2,500,330,300,a);
      }
    else
    if(pila.ejec[0]<=10&&pila.listo[1]>10)
      {
       bloque=pila.ejec[0];
       pila.ejec[0]=pila.listo[1];

       //sale la tarea de e/s
       pila.ejec[0]=0;
       for(int b=0;b<LON;b++)
	  {
	   pila.listo[b]=pila.listo[b+1];
	  }
      pila.listo[0]=bloque;
      mover_carta(3,410,120,10,a);
      mover_carta(2,210,120,420,a);
      mover_carta(1,350,330,420,a);
      mover_carta(2,130,330,70,a);
      mover_carta(3,300,120,120,a);
      mover_carta(2,210,120,420,a);
      mover_carta(1,120,330,420,a);
      mover_carta(2,500,330,300,a);
      mover_carta(4,340,460,70,a);
      mover_carta(3,20,120,70,a);
      outtext("Este proceso E/S dura ");
      itoa(pila.listo[1],fontstr, 5);
      outtextxy(200,250,fontstr);
      moveto(250,260);
      outtext("En ejecucion");
      delay(100*pila.listo[pila.tope_listo]);
      }
    else
    if(pila.ejec[0]<10&&pila.listo[1]<=10)
      {
       pila.ejec[0]=0;

       for(int b=0;b<LON;b++)
	  {
	   pila.listo[b]=pila.listo[b+1];
	  }
      mover_carta(3,410,120,10,a);
      mover_carta(2,210,120,420,a);
      mover_carta(1,120,330,420,a);
      mover_carta(2,500,330,300,a);
      outtext("Este proceso E/S dura ");
      itoa(pila.listo[2],fontstr, 5);
      outtextxy(200,250,fontstr);
      moveto(250,260);
      outtext("En ejecucion");
      delay(100*pila.listo[pila.tope_listo]);

      }
    else
    if(pila.ejec[0]>=10&&pila.listo[1]<=10)
      {
       pila.ejec[0]=0;

       for(int b=0;b<LON;b++)
	  {
	   pila.listo[b]=pila.listo[b+1];
	  }
      mover_carta(3,410,120,10,a);
      mover_carta(2,210,120,420,a);
      mover_carta(1,120,330,420,a);
      mover_carta(2,500,330,300,a);
      outtext("Este proceso E/S dura ");
      itoa(pila.listo[4],fontstr, 5);
      outtextxy(200,250,fontstr);
      moveto(250,260);
      outtext("En ejecucion");
      delay(100*pila.listo[pila.tope_listo]);
      }

   }

int azar(void)
{
   int i,b,e;

   randomize();
   e= rand() % 30;
   b= rand() % e;
   if(b==0)
   b++;
   return b;
}


void modo()
{
 int gd=DETECT,gm=0;
 initgraph(&gd,&gm,"c:\\borlandc\\bgi");
}

void dibujo()
   {
    modo();
    cleardevice();
    setcolor(LIGHTBLUE);
    setfillstyle(SOLID_FILL,LIGHTBLUE);
    rectangle(0,0,getmaxx(),getmaxy());
    setcolor(1);
    floodfill(5,5,LIGHTBLUE);
    setcolor(4);
    rectangle(90,100,100,200);
    rectangle(190,100,200,200);
    rectangle(590,270,630,280);
    rectangle(590,330,630,340);
    setcolor(6);
    setfillstyle(3,6);
    floodfill(95,110,4);
    setfillstyle(4,6);
    floodfill(195,110,4);
    setcolor(14);
    setfillstyle(1,14);
    floodfill(595,275,4);
    floodfill(595,335,4);
    setcolor(YELLOW);
    settextstyle(GOTHIC_FONT,0,4);
    moveto(550,230);
    outtext("Salida");
    setcolor(YELLOW);
    settextstyle(GOTHIC_FONT,0,3);
    moveto(5,100);
    outtext("Entrada");
    moveto(20,120);
    outtext("de");
    moveto(5,140);
    outtext("Tareas");

    //cpu
    setcolor(0);
    line(300,340,330,340);
    line(300,340,300,420);
    line(300,460,385,460);
    line(385,460,385,340);
    circle(310,360,7);
    circle(310,375,7);
    circle(310,390,7);
    setcolor(2);
    setfillstyle(1,2);
    floodfill(311,359,0);
    setcolor(14);
    setfillstyle(1,14);
    floodfill(311,374,0);
    setcolor(4);
    setfillstyle(1,4);
    floodfill(311,389,0);
    setcolor(YELLOW);
    settextstyle(GOTHIC_FONT,0,4);
    moveto(390,400);
    outtext("C P U");

    //pare
    setcolor(0);
    line(400,70,440,40);
    line(440,40,500,40);
    line(500,40,540,70);
    line(400,100,440,130);
    line(440,130,500,130);
    line(500,130,540,100);
    setcolor(YELLOW);
    settextstyle(GOTHIC_FONT,0,3);
    moveto(430,140);
    outtext("Proceso Bloqueado");

   }

void dibujo2()
{
    dibujo();
    dibujo1();
    void *a;
	  int c,e;
	  c=imagesize(7,8,60,35);
	  a=malloc(c);
	  getimage(7,8,60,35,a);
	  putimage(120,130,a,COPY_PUT);
	  putimage(120,120,a,COPY_PUT);
	  putimage(120,110,a,COPY_PUT);
	  putimage(120,100,a,COPY_PUT);
	  putimage(120,90,a,COPY_PUT);

}

void dibujo1()
{
    //sobre
    setcolor(0);
    rectangle(10,10,55,35);
    line(10,10,29,25);
    line(29,25,55,10);
    setcolor(15);
    setfillstyle(SOLID_FILL,15);
    floodfill(14,27,0);
    floodfill(17,12,0);
}

void llenar_list()
   {

    if(pila.tope_listo>=LON)
      {
       dibujo2();
       setcolor(YELLOW);
       settextstyle(GOTHIC_FONT,0,3);
       moveto(250,250);
       outtext("Tareas Llenas");
       cout<<"\a";
       delay(1000);
       getch();
       closegraph();
       menu();
      }
     else
      {
       b=azar();
       pila.listo[pila.tope_listo]=b;
       aa[y]=b;
       pila.tope_listo++;y++;
      }
   }

void mover_carta(int w,int x,int y,int z,void *m)
   {
    if(w==1)
       {
	for(int e=0;e<x;e++)
	  {
	   putimage(y,z-e,m,COPY_PUT);
	   delay(3);
	  }
       }
      else if(w==2)
       {
	for(int e=0;e<x;e++)
	  {
	   putimage(y+e,z,m,COPY_PUT);
	   delay(3);
	  }
       }
      else if(w==3)
       {
	for(int e=0;e<x;e++)
	  {
	   putimage(y,z+e,m,COPY_PUT);
	   delay(3);
	  }
       }
      else if(w==4)
       {
	for(int e=0;e<x;e++)
	  {
	   putimage(y-e,z,m,COPY_PUT);
	   delay(3);
	  }
       }
   }

void presentacion()
{

modo();
logo();
setbkcolor (LIGHTCYAN);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy(200,250,"GRUPO 49");
outtextxy(200,300,"PROFESOR: ROBERTO FERNANDEZ");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4.7);
outtextxy(91,120,"UNIVERSIDAD ANTONIO NARI¥O");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
outtextxy(200,200,"SISTEMAS OPERACIONALES");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(200,370,"ANA CECILIA TORRES AMAYA   499515470");
outtextxy(200,385,"NUBIA LILIANA ROJAS DIAZ   499515298");
outtextxy(200,400,"JESUS REITHER CORDOBA      499515014");
settextstyle(SMALL_FONT,HORIZ_DIR,3);
outtextxy(450,450,"E N T E R  P A R A  C O N T I N U A R");
   getch();
   closegraph();
}

    /*****************LOGOTIPO**************************/
void logo()
{modo();
  int tamano1;
	  int o=0;

	  for (o=0;o<=30;o++)
	      {
	       setcolor (4);
	       line (90+o,190,110+o,229);
	      }
	  for (o=0;o<=20;o++)
	      {
	       line (120-o,190-o,75+o,190-o);
	      }
	  for (o=0;o<=20;o++)
	      {
	       line (90+o,170+o,110+o,170+o+o);
	      }
	  for (o=0;o<=10;o++)
	      {
	       line (110-o,170,120-o,190);
	      }
	  for (o=0;o<=15;o++)
	      {
	       line (90+o,170,60+o,210);
	       line (78,200,78,210);
	       line (77,200,77,210);
	      }
	  for (o=0;o<=40;o++)
	      {
	       line (59+o,210,59+o,230);
	       line (58,213,58,229);
	       line (160-o,170,160-o,190);
	      }
	  for (o=0;o<=15;o++)
	      {
	       line (140-o,230,160-o,190);
	      }
	  for (o=0;o<=10;o++)
	      {
	       line (137+o,190,137+o,204);
	       line (136,190,136,193);
	      }
	  setcolor (1);
	  line (100,230,60,230);
	  line (100,230,100,210);
	  line (90,190,110,230);
	  line (100,210,80,210);
	  arc  (100,210,110,180,21);
	  line (110,230,140,230);
	  line (140,230,160,190);
	  line (160,170,120,170);
	  arc (131,180,340,20,30);
	  line (120,170,120,190);
	  line (120,190,135,190);
	  line (130,210,110,170);
	  arc (121,200,310,30,16);
	  line (110,170,90,170);
	  line (90,170,60,210);
	  arc (87,220,160,200,30);
	 }

void DrawBorder(void)
{
  struct viewporttype vp;

  setcolor( MaxColors - 1 );

  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

  getviewsettings( &vp );
  rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}


void introduccion()
 {
  clrscr();
  modo();
  DrawBorder();
  setcolor(6);
  setpalette(0,DARKGRAY);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  outtextxy(200,7," P C B");
  gotoxy(11,8);
  cout<<" ES UNA ESTRUCTURA DE DATOS QUE  PERMITE AL SISTEMA OPERATIVO ";
  gotoxy(11,9);
  cout<<"LOCALIZAR TODA LA INFORMACION IMPORTANTE DEL PCB";
  gotoxy(11,10);
  cout<<" ";
  gotoxy(11,12);
  cout<<"ESTE PROGRAMA MUESTRA LOS TRES PROCESOS BASICOS DEL PCB COMO SON:";
  gotoxy(11,14);
  cout<<"EJECUCION:Estado de ejecucion de la CPU";
  gotoxy(11,16);
  cout<<"LISTO: Evento que puede utilizar la CPU en caso de haber " ;
  gotoxy(11,17);
  cout<<"       una disponible. ";
  gotoxy(11,19);
  cout<<"BLOQUEADO: Esperando que suceda un proceso como de entrada y de ";
  gotoxy(11,20);
  cout<<"       salida antes de proseguir su ejecucion";
  gotoxy(70,25);
  settextstyle(SMALL_FONT,HORIZ_DIR,4);
outtextxy(290,450,"D I G I T E  E N T E R  P A R A  C O N T I N U A R");
  getch();
  closegraph();
  menu();
  }

  void Initialize(void)
{
  int xasp, yasp,MaxX,MaxY;

  GraphDriver = DETECT;
  initgraph( &GraphDriver, &GraphMode, "" );
  ErrorCode = graphresult();
  if( ErrorCode != grOk ){
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );
  }

  getpalette( &palette );
  MaxColors = getmaxcolor() + 1;
  getaspectratio( &xasp, &yasp );

}
void RandomBars(void)
{
  int color;

  MainWindow( "Random Bars" );
  StatusLine( "Esc aborts or press a key..." );
while( !kbhit() ){
color = random( MaxColors-1 )+1;
    setcolor( color );
    setfillstyle( random(11)+1, color );
    bar3d( random( getmaxx() ), random( getmaxy() ),
	   random( getmaxx() ), random( getmaxy() ), 0, OFF);
  }

  Pause();

}

 void PutPixelDemo(void)
{
  int seed = 1958;
  int i, x, y, h, w, color;
  struct viewporttype vp;

  MainWindow( "PutPixel / GetPixel Demonstration" );

  getviewsettings( &vp );
  h = vp.bottom - vp.top;
  w = vp.right	- vp.left;

  setcolor(2);
  setpalette(0,DARKGRAY);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,15);
  outtextxy(280,186,"  I N T R O D U C C I O N");
  settextstyle(SMALL_FONT,HORIZ_DIR,4);
outtextxy(290,450,"D I G I T E  E N T E R  P A R A  C O N T I N U A R");

  srand( seed );

  for( i=0 ; i<10000 ; ++i ){
    x = 1 + random( w - 1 );
    y = 1 + random( h - 1 );
    color = random( MaxColors );
    putpixel( x, y, color );
  }

  srand( seed );

  for( i=0 ; i<5000 ; ++i ){
    x = 1 + random( w - 1 );
    y = 1 + random( h - 1 );
    color = getpixel( x, y );
    if( color == random( MaxColors ) )
      putpixel( x, y, 5 );

  }

  Pause();

}


 void PutImageDemo(void)
{
  static int r	    = 30;
  static int StartX = 100;
  static int StartY = 50;

  struct viewporttype vp;
  int PauseTime, x, y, ulx, uly, lrx, lry, size, i, width, height, step,MaxX,MaxY;
  void *Saucer;


  MainWindow("GetImage / PutImage Demonstration");
  getviewsettings( &vp );

  /* Draw Saucer */
setfillstyle( SOLID_FILL, getmaxcolor() );
  fillellipse(StartX, StartY, r, (r/3)+2);
  ellipse(StartX, StartY-4, 190, 357, r, r/3);
   setcolor(2);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(280,86," P C B");
 outtextxy(290,206," EL BLOQUE DE CONTROL DE PROCESO");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 // settextstyle(SMALL_FONT,HORIZ_DIR,0);
outtextxy(290,450,"D I G I T E  E N T E R  P A R A  C O N T I N U A R");
  line(StartX+7, StartY-6, StartX+10, StartY-12);
  circle(StartX+10, StartY-12, 2);
  line(StartX-7, StartY-6, StartX-10, StartY-12);
  circle(StartX-10, StartY-12, 2);


  /* Read saucer image */
  ulx = StartX-(r+1);
  uly = StartY-14;
  lrx = StartX+(r+1);
  lry = StartY+(r/3)+3;
  width = lrx - ulx + 1;
  height = lry - uly + 1;
  size = imagesize(ulx, uly, lrx, lry);

  Saucer = malloc( size );
  getimage(ulx, uly, lrx, lry, Saucer);
  putimage(ulx, uly, Saucer, XOR_PUT);

for ( i=0 ; i<1000; ++i )
    putpixel(random(MaxX), random(MaxY), random( MaxColors-1 )+1);
  x = MaxX / 2;
  y = MaxY / 2;
  PauseTime = 70;

  while ( !kbhit() ) {
  putimage(x, y, Saucer, XOR_PUT);
 delay(PauseTime);
 putimage(x, y, Saucer, XOR_PUT);
 step = random( 2*r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    x = x + step;
    step = random( r );
    if ((step/2) % 2 != 0 )
      step = -1 * step;
    y = y + step;

    if (vp.left + x + width - 1 > vp.right)
      x = vp.right-vp.left-width + 1;
    else
      if (x < 0)
	x = 0;
    if (vp.top + y + height - 1 > vp.bottom)
      y = vp.bottom-vp.top-height + 1;
    else
      if (y < 0)
	y = 0;
  }
  free( Saucer );
  Pause();
}
void Pause(void)
{
  static char msg[] = "Esc aborts or press a key...";
  int c;

  StatusLine( msg );

  c = getch();

  if( ESC == c ){
    closegraph();
    exit( 1 );
  }

  if( 0 == c ){
    c = getch();
  }

  cleardevice();

}


void MainWindow( char *header )
{
  int height,MaxX,MaxY;

  cleardevice();
  setcolor( MaxColors - 1 );
  setviewport( 0, 0, MaxX, MaxY, 1 );
  height = textheight( "H" );
  settextjustify( CENTER_TEXT, TOP_TEXT );
  outtextxy( MaxX/2, 2, header );
  setviewport( 0, height+4, MaxX, MaxY-(height+4), 1 );
  DrawBorder();
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}


void StatusLine( char *msg )
{
  int height,MaxX,MaxY;

  setviewport( 0, 0, MaxX, MaxY, 1 );

  settextjustify( CENTER_TEXT, TOP_TEXT );
  setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
  setfillstyle( EMPTY_FILL, 0 );

  height = textheight( "H" );
  bar( 0, MaxY-(height+4), MaxX, MaxY );
  rectangle( 0, MaxY-(height+4), MaxX, MaxY );
  outtextxy( MaxX/2, MaxY-(height+2), msg );
  setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}

