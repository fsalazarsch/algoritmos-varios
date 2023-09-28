#include <graphics.h>
#include <bios.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <io.h>
#include <fcntl.h>
#define PIXEL_COUNT 1000
#define DELAY_TIME  100  
/*********************************procedimiento dise¤o*******************/
char opc;
int i,x,y,j,h;
void diseno();
void diseno()
{
  int i;
  clrscr();
  textcolor(15);textbackground(4);
  i=1;
  gotoxy(i,1);printf("É");
  gotoxy(80,i);printf("»");
  gotoxy(1,24);printf("¼");
  gotoxy(80,24);printf("¼");
  for(i=1;i<=79;i++)
  {
    gotoxy(i,1);printf("Í");
    gotoxy(i,24);printf("Í");
    gotoxy(23,22);printf("<<PRESIONE <ENTER> PARA VISUALIZAR EL MENU>>");
  }
  for(i=2;i<=23;i++)
  {
      gotoxy(1,i);printf("º");
      gotoxy(80,i);printf("º");
   }
   gotoxy(10,5);printf("É");
   gotoxy(69,5);printf("»");
   gotoxy(10,20);printf("È");
   gotoxy(69,20);printf("¼");
   for (i=6;i<=19;i++)
   {
      gotoxy(10,i);printf("º");
      gotoxy(69,i);printf("º");
    }
   for (i=11;i<=68;i++)
   {
     gotoxy(i,5);printf("Í");
     gotoxy(i,20);printf("Í");
     gotoxy(23,7);printf("<< PROGRAMA DE MODULO DE GRAFICOS  >>");
     gotoxy(i,8);printf("Í");
     gotoxy(23,10);printf("<<M O D E L O  DE P R O G R A M A C I O N>>");
     gotoxy(25,12);printf("CLAUDIA NU¥EZ PADILLA:    97132515" );
     gotoxy(23,15);printf("PRESENTADO AL PROFESOR: ROBERTO FERNANDEZ");
     gotoxy(23,17);printf("<<FACULTAD DE INGENIERIA DE SISTEMAS>>");
     gotoxy(35,18);printf("<<CURSO S3E>>");
   }
   getch();
}
void arbol();
void arbol()
{
struct Figura{
int x,y,x1,y1;
int clase,v;
}reg;
int i, x, y, color, maxx, maxy, maxcolor, seed,midx;
int salir,s,x1,y1,a,b,c,z;


   int gdriver = DETECT, gmode, errorcode;
	//int i=0,j,id;
	 //	int stangle = 45, endangle = 135;
	int op;
	initgraph(&gdriver, &gmode, "c:\tc\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}

	//midx = getmaxx() / 2;
setcolor(GREEN);
setbkcolor(15);
cleardevice();
settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
setbkcolor(0);
	//midx = 100;
	setbkcolor(0);
	/***********************************/
	setfillstyle(SOLID_FILL,BROWN);
	circle(350,150,5);
	circle(320,150,5);
	circle(340,130,5);
	circle(280,140,5);
	circle(300,150,5);
	circle(300,160,5);
	circle(300,170,5);
	circle(300,180,5);
	circle(330,190,5);
	circle(300,200,5);
	circle(305,205,5);
	circle(312,215,5);
	circle(306,220,5);
	rectangle(250,300,305,430);
	line(100,300,335,-80);
	line(450,300,290,-1);
	line(450,300,100,300);
   maxx = getmaxx() + 1;
   maxy = getmaxy() + 1;
   maxcolor = getmaxcolor() + 1;

   while (!kbhit())
   {
      /* seed the random number generator */
      seed = random(32767);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 putpixel(x, y, color);
      }

      delay(DELAY_TIME);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
	 x = random(maxx);
	 y = random(maxy);
	 color = random(maxcolor);
	 if (color == getpixel(x, y))
	    putpixel(x, y, 0);

 }
  }
   getch();
   bioskey(1);
   closegraph();
}

void avion();
void avion()
{
}

void balon();
void balon()
{
struct Figura{
int x,y,x1,y1;
int relleno;
}reg;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy,i,j;
   int radius = 100;
   int op,id;
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
		 i=5;
 outtextxy(10,20,"CLAUDIA NU¥EZ");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 outtextxy(20,50,"Profesor Roberto Fern ndez");
 settextstyle(SMALL_FONT,HORIZ_DIR,0);
 outtextxy(30,90,"Ingenieria De Sistemas");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,0);
 outtextxy(40,100,"Semestre III");
 settextstyle(GOTHIC_FONT,HORIZ_DIR,0);
 outtextxy(50,150,"Modelo De Programacion II");
 settextstyle(4,HORIZ_DIR,0);
 outtextxy(50,200,"Corporacion Universitaria Del Santander");
	delay(3000);
	cleardevice();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
   setbkcolor(BLUE);
   do{
	 setcolor(WHITE);
	  setfillstyle(SOLID_FILL, LIGHTRED);
	  fillellipse(midx,midy,radius,radius);
	   
	   setfillstyle(SOLID_FILL, LIGHTBLUE);
	  fillellipse(midx,midy,radius-10,radius-10);
	   
	   setfillstyle(SOLID_FILL, RED);
	  fillellipse(midx,midy,radius-20,radius-20);
	   
	   setfillstyle(SOLID_FILL,GREEN);
	   fillellipse(midx,midy,radius-30,radius-30);
	   
	   setfillstyle(SOLID_FILL, LIGHTGREEN);
	   fillellipse(midx,midy,radius-40,radius-40);
	   
	   setfillstyle(SOLID_FILL, YELLOW);
	  fillellipse(midx,midy,radius-50,radius-50);
	   
	   setfillstyle(SOLID_FILL, MAGENTA);
	   fillellipse(midx,midy,radius-60,radius-60);
	   
	   setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	   fillellipse(midx,midy,radius-70,radius-70);
	   
	   outtextxy(midx-23,midy,"MIKASA");
  
    op=getch();
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(midx,midy,radius,radius);
    switch(op){
     case 72:{
	 midy-=i;
	 break;
	 }
     case 80:{

	  midy+=i;

	  break;
	  }
      case 77:{
	   midx+=i;

	   break;
	  }
      case 75:{

	   midx-=i;

	   break;
	   }
      case 73: { i+=5;break;}
	}
   

	   
 }while(op!=27);
	 if((id=_creat("balon",FA_ARCH))==-1){
    outtext("Error");
    getch();
    getch();
    getch();
    }
    else
    {

	  reg.relleno= LIGHTRED;
	  reg.x=midx;reg.y=midy;reg.y1=radius;reg.x1=radius;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= LIGHTBLUE;
	  reg.x=midx;reg.y=midy;reg.y1=radius-10;reg.x1=radius-10;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= RED;
	  reg.x=midx;reg.y=midy;reg.y1=radius-20;reg.x1=radius-20;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno=GREEN;
	   reg.x=midx;reg.y=midy;reg.y1=radius-30;reg.x1=radius-30;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= LIGHTGREEN;
	   reg.x=midx;reg.y=midy;reg.y1=radius-40;reg.x1=radius-40;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= YELLOW;
	  reg.x=midx;reg.y=midy;reg.y1=radius-50;reg.x1=radius-50;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= MAGENTA;
	   reg.x=midx;reg.y=midy;reg.y1=radius-60;reg.x1=radius-60;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno= LIGHTMAGENTA;
	   reg.x=midx;reg.y=midy;reg.y1=radius-70;reg.x1=radius-70;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }
	   reg.relleno=WHITE;
	   reg.x=midx-23;reg.y=midy;
			if(_write(id,&reg,sizeof(reg))==-1){
		   outtextxy(0,0,"Error de escritura");
		   bioskey(0);
		   exit(0);
		   }

   }
   close(id);
    cleardevice();
   
	if((id=_open("balon",4))!=-1) 
	while(!eof(id)){
	if(read(id,&reg,sizeof(reg))==-1)
	 {
	 outtextxy(0,0,"Error de lectura");
	 getch();
	 exit(1);
	 }
	
	if(reg.relleno!=WHITE){
	setfillstyle(SOLID_FILL,reg.relleno); fillellipse(reg.x,reg.y,reg.x1,reg.y1);
	}else{
	setcolor(reg.relleno);
	outtextxy(reg.x,reg.y,"MIKASA");
	}

	
   }

   getch();		
   bioskey(1);	
   closegraph();
}


void bus();
void bus()
{
 int radio,rectangle;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
    }
 settextstyle(4,0,5);

   outtextxy(10,10,"MODELOS DE PROGRAMACION II");
   settextstyle(1,0,3);
   outtextxy(90,80,"PARCIAL FINAL");
   settextstyle(2,0,7);
   outtextxy(215,150,"MODO GRAFICO");
   setbkcolor(1);
   settextstyle(0,0,1);
   getch();
   for(i=0;i<getmaxx()-8;i+=3) 
      {   i+=3;
       cleardevice();
       line(10+i,150,230+i,150);
       line(10+i,150,10+i,270);
       line(10+i,270,70+i,270);
       line(110+i,270,230+i,270);
       line(270+i,270,350+i,270);
       line(10+i,210,230+i,210);
       line(60+i,150,60+i,210);
       line(165+i,150,165+i,210);
       arc(230+i,270,0,15,120);
       setfillstyle(0,0);
       sector(230+i,240,0,90,115,90);
       circle(90+i,270,20);
       circle(90+i,270,12);
       circle(250+i,270,20);
       circle(250+i,270,12);
       setcolor(15);
       outtextxy(90+i,230,"COOPETRAN");
       setcolor(14);
       delay(200);
      }
   getch();
   closegraph();
 
}

int bicicleta(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode=VGAHI, errorcode;
   int i, j, x, y, color, maxx, maxy, maxcolor, seed;


   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }
 
clearviewport(); 

for( i=47;i<580;i++)
{
 i=i+6;
 setcolor(LIGHTRED);
 delay(5);
 circle(i,60,50);
 circle(i,390,50);

 sound((i*15)/5); 
}
nosound();

 for(i=55;i<380;i--)
 {
 i=i+15;
 setcolor(BLUE);
 delay(5);
 circle(50,i,50);
 circle(590,i,50);
 sound((i*14)/2); 
  }
 nosound();           

for(i=200;i<=450;i++)
{
 i=i+3;
 setcolor(1);
 delay(5);
 circle(i,200,20);
 circle(i,300,20);
 sound((i*45)/6); 
  }
 nosound();              
for(i=100;i<=310;i--)
 {
 i=i+10;
 setcolor(11);
 delay(5);
 circle(160,i,20);
 circle(490,i,20);
 sound((i*50)/10);  
  }
 nosound();             
 for(i=190;i<=200;i++)
{      
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,8);
   setcolor(11);
   delay(10);
   outtextxy(i,210,"CLAUDIA");
   setcolor(0);
   outtextxy(i-10,210,"CLAUDIA");

}
getch();
clearviewport();
for(i=0;i<=800;i++)
{
   i=i+4;
   setbkcolor(1);
   setcolor(15);
   cleardevice();
   circle(40+i,400,30);    /*circ1*/
   circle(200+i,400,30);   /*circ2*/
   circle(40+i,400,27); /*circ3*/
   circle(200+i,400,27);/*circ4*/
   circle(200+i,400,8);/*circ5*/
   circle(40+i,400,8);/*circ6*/
   line(40+i,400,60+i,350);  /*line1diagon*/
   line(200+i,400,170+i,350);/*line2diagon*/
   line(40+i,400,100+i,390);/*cadena*/
   line(40+i,400,100+i,410);/*cadena2*/  
   line(40+i,400,110+i,400); /*barra1*/
   line(182+i,370,110+i,400); /*barra2*/
   line(40+i,400,20+i,200);  /*banderita*/
   line(20+i,210,70+i,200); /*bande1*/
   line(20+i,200,70+i,200); /*bande2*/
   line(110+i,400,110+i,370); /*viela*/
   line(60+i,350,170+i,350); /*line1horz*/
   line(52+i,370,182+i,370); /*line2horiz*/
   line(60+i,350,60+i,335);  /*tubosill*/
   line(170+i,350,170+i,300); /*espiga*/
   line(170+i,300,150+i,320);/*cachos*/
   line(170+i,300,190+i,320);/*cachos*/
   line(200+i,320,150+i,320);/*cachos*/
   line(200+i,320,190+i,320); /*manurio1*/
   line(140+i,320,150+i,320); /*manurio2*/
   ellipse(60+i,325,180+i,200,20,10); /*silla*/
   ellipse(110+i,400,210+i,190,20,10);/*pedal*/	  
   settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
   sound((i*80)/2);
}   
nosound(); 
getch();
return 0;

}


void camion();
void camion()
{
	 int gdriver = DETECT, gmode, errorcode;
	 int midx, midy,i=0,j;
	int op;
	initgraph(&gdriver, &gmode, "");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
 cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
 setbkcolor(WHITE);
 while(!kbhit()){
	cleardevice();
	setfillstyle(SOLID_FILL,LIGHTRED);
	bar(midx-i,midy,midx-i+250,midy+100);
	line(midx-i-10,midy,midx-i-50,midy);
	line(midx-i-10,midy+10,midx-i-50,midy+10);
	line(midx-i-15,midy+15,midx-i-50,midy+15);
	line(midx-i-50,midy,midx-i-100, midy+50);
	line(midx-i-50,midy+10,midx-i-90,midy+50);
	line(midx-i-50,midy+15,midx-i-85,midy+50);
	line(midx-i-85,midy+50,midx-i-15,midy+50);
	line(midx-i-15,midy+50,midx-i-15,midy+15);
	line(midx-i-90,midy+50,midx-i-90,midy+90);
	line(midx-i-10,midy,midx-i,midy+10);
	line(midx-i-100,midy+50,midx-i-150,midy+50);
	line(midx-i-150,midy+50,midx-i-150,midy+100);
	line(midx-i-150,midy+100,midx-i,midy+100);
	line(midx-i-90,midy+90,midx-i-10,midy+90);
	line(midx-i-10,midy+90,midx-i-10,midy+10);
	fillellipse(midx-i-95,midy+100,25,25);
	fillellipse(midx-i+100,midy+100,25,25);
	fillellipse(midx-i+165,midy+100,25,25);
	i+=5;
	setbkcolor(BLACK);
	outtextxy(midx-i+100,midy+50,"COCA-COLA");
	if(i>getmaxx()){
	  i=0;
	  midx=getmaxx();
	  }
	}
 closegraph();
}

void colectivo();
void colectivo()
{
 struct Figura{
int x,y,x1,y1;
int clase,v;
}reg;
int a,B,c;

   int gdriver = DETECT, gmode, errorcode;
	int midx, midy,i=0,j,id;
	int op;
	initgraph(&gdriver, &gmode, "c:\tc\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
 setcolor(WHITE);
 setbkcolor(4);
 settextstyle(3,HORIZ_DIR,0);
 outtextxy(85,80,"MODELO DE PROGRAMACION II");
 outtextxy(85,150,"PROFESOR  ROBERTO FERNANDEZ");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
 outtextxy(85,240,"INGENIERIA DE SISTEMAS");
 settextstyle(4,HORIZ_DIR,0);
 outtextxy(18,350,"CLAUDIA PATRICIA NU¥EZ PADILLA");
 settextstyle(8,HORIZ_DIR,4);
 delay(2500);
 cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
 setbkcolor(0);
 setcolor(YELLOW);
 setbkcolor(1);
 while(!kbhit()){
cleardevice();
	rectangle(midx-i+20,midy+10,midx-i+50,midy+50);
	rectangle(midx-i+70,midy+10,midx-i+100,midy+50);
	rectangle(midx-i+120,midy+10,midx-i+150,midy+50);
	rectangle(midx-i+20,midy+60,midx-i+150,midy+70);
	line(midx-i+150,midy,midx-i-50,midy);
	line(midx-i-10,midy+10,midx-i-50,midy+10);
	line(midx-i-15,midy+15,midx-i-50,midy+15);
	line(midx-i-50,midy,midx-i-100, midy+50);
	line(midx-i-100,midy+50,midx-100-i,midy+100);//
	line(midx-i-100,midy+100,midx-i+150,midy+100);//linea abajo
	line(midx-i+165,midy+10,midx-i+165,midy+90);//
	line(midx-i+165,midy+10,midx-i+150,midy);//
	line(midx-i+165,midy+90,midx-i+150,midy+100);//
	line(midx-i-50,midy+10,midx-i-90,midy+50);
	line(midx-i-50,midy+15,midx-i-85,midy+50);
	line(midx-i-85,midy+50,midx-i-15,midy+50);
	line(midx-i-15,midy+50,midx-i-15,midy+15);
	line(midx-i-90,midy+50,midx-i-90,midy+90);
	line(midx-i-90,midy+90,midx-i-10,midy+90);
	line(midx-i-10,midy+90,midx-i-10,midy+10);
	setbkcolor(0);
	fillellipse(midx-i-50,midy+100,25,25);
	fillellipse(midx-i+100,midy+100,25,25);

/********************************************************************/
	i+=5;
	if(i>getmaxx()){
	  i=0;
	  midx=getmaxx();
	  }
	}
   
	line(midx-i-100,midy+100,midx-i+150,midy+100);//linea abajo
	line(midx-i+150,midy,midx-i-50,midy);
 bioskey(1);
closegraph();

}

void despedida();
void despedida()
{
 clrscr();
 textcolor(15);textbackground(4);
 textmode(C40);
 gotoxy(2,10);printf("GRACIAS POR ACCESAR A NUESTRO SISTEMA");
 gotoxy(10,12);printf("HASTA LA PROXIMA");
 getch();
 textcolor(15);textbackground(4);
}




void menu();
void menu()
{
 
 while(1)
  {
    clrscr();
    gotoxy(18,3); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    gotoxy(18,4); printf("³  CORPORACION UNIVERSITARIA DE SANTANDER    ³");
    gotoxy(18,5); printf("³    FACULTAD DE INGENIERIA DE SISTEMAS      ³");
    gotoxy(18,6) ;printf("³              CURSO S3E                     ³");
    gotoxy(18,7); printf("³                                            ³");
    gotoxy(18,8); printf("³        MENU PRINCIPAL DE OPCIONES          ³");
    gotoxy(18,9); printf("³ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ³");
    gotoxy(18,10);printf("³       1. GRAFICO ARBOL DE NAVIDAD          ³");
    gotoxy(18,11);printf("³       2. GRAFICO AVION                     ³");
    gotoxy(18,12);printf("³       3. GRAFICO BALON                     ³");
    gotoxy(18,13);printf("³       4. GRAFICO BUS                       ³");
    gotoxy(18,14);printf("³       5. GRAFICO BICICLETA                 ³");
    gotoxy(18,15);printf("³       6. GRAFICO CAMION                    ³");
    gotoxy(18,16);printf("³       7. GRAFICO COLECTVO                  ³");
    gotoxy(18,17);printf("³       8. SALIR DEL PROGRAMA                ³");
    gotoxy(18,18);printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(25,21);printf("ELIJA UNA OPCION DE [1 A 8]...[ ]");
    gotoxy(56,21);opc=getchar();
    if(opc>'9')
    {
     gotoxy(20,23);printf("OPCION ERRADA, DIGITE SOLO NUMEROS DE [1 A 8]");
    }
    switch(opc)
    {
      case '1': arbol();break;
      case '2': avion();break;
      case '3': balon();break;
      case '4': bus();break;
      case '5': bicicleta();break;
      case '6': camion();break;
      case '7': colectivo();break;
      case '8': despedida();break;
    }
    getch();
  }
}

void main()
{
 textcolor(15);textbackground(4);
 diseno();
 menu();
}