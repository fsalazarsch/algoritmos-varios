#include<stdlib.h>
#include<process.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void DIBUJO(void);
void procesador1(int);
void procesador2(int);
void graficos(void);
void perifericos(void);
void LETRERO(int,int,int,char*);
void presentacion(void);
void flecha(void);
void memoria(void);
void vacioa(void);
void vaciob(void);
void vacioc(void);
void vaciod(void);
void vacio1(void);
void vacio2(void);
void lleno(void);
void llenoa(void);
void llenob(void);
void llenoc(void);
void lleno1(void);
void lleno2(void);
void recuadro(void);
void salida1(void);
void salida2(void);
void salida3(void);
void menu1(void);
void menu2(void);
void inicia(void);
void desarrollo(void);
void fin(void);
void secuen1(void);
void secuen2(void);
void *bike;

char t[30];
const int STEP = 1;

void main()
   {
    int op2=0,sw;
    graficos();
    presentacion();
    getch();
    graficos();
    while(op2==0)
     {
      cleardevice();
      recuadro();
      LETRERO(280,30,11,"MENU");
      LETRERO(200,80,10,"1. PARALELO EN DATOS");
      LETRERO(200,130,10,"2. PARALELO EN PROCESOS");
      LETRERO(200,180,10,"3. SALIR");
      LETRERO(200,230,14,"DIGITE SU OPCION =");
      scanf("%d",&sw);
      switch(sw)
       {
	case 1:
		  menu2();
		  break;
	case 2:
		  menu1();
		  break;
	case 3:
		  op2=1;
		  break;
	default:
		  break;
       }
     }
   }

void menu2()
   {
    cleardevice();
    recuadro();
    inicia();
    delay(2000);
    secuen1();
    desarrollo();
    delay(2000);
    secuen2();
    fin();
    getch();
   }

void secuen2()
   {
    line(175,300,275,350);
    line(375,350,475,300);
    delay(2000);
   }

void secuen1()
   {
    setcolor(10);
    line(100,150,175,200);
    line(175,200,250,150);
    line(390,150,475,200);
    line(475,200,550,150);
    delay(2000);
   }

void fin()
   {
    setcolor(12);
    rectangle(275,350,375,450);
    delay(1000);
    setcolor(13);
    settextstyle(4,0,7);
    moveto(295,350);
    outtext("13");
   }

void desarrollo()
   {
    setcolor(9);
    rectangle(125,200,225,300);
    rectangle(425,200,525,300);
    delay(1000);
    setcolor(13);
    settextstyle(4,0,7);
    moveto(160,200);
    outtext("6   +    7");
   }

void inicia()
   {
    setcolor(14);
    rectangle(50,50,150,150);
    rectangle(200,50,300,150);
    rectangle(340,50,440,150);
    rectangle(500,50,600,150);
    delay(1000);
    setcolor(13);
    settextstyle(4,0,7);
    moveto(85,50);
    outtext("2 + 4   6 + 1 ");
   }



void menu1()
   {
    cleardevice();
    DIBUJO();
    lleno();
    getch();
    vacioa();
    salida1();
    llenoa();
    getch();
    salida2();
    getch();
    salida3();
    llenoc();
    getch();
    vaciod();
    salida1();
    getch();
    llenob();
    getch();
   }

 void DIBUJO()
    {
      recuadro();
      procesador1(14);
      procesador2(10);
      LETRERO(35,15,2,"PROCESADOR1");
      LETRERO(35,160,2,"PROCESADOR2");
      LETRERO(445,15,9,"MEMORIA");
      setcolor(4);
      memoria();
      perifericos();
    }

 void graficos()
  {
   int uni,mod;
   detectgraph(&uni,&mod);
   initgraph(&uni,&mod,"c:\\borlandc\\bgi");
  }

 void recuadro()
  {
   line(5,5,635,5);
   line(5,7,635,7);
   line(5,474,635,474);
   line(5,476,635,476);
   line(5,5,5,476);
   line(7,5,7,476);
   line(633,5,633,476);
   line(635,5,635,476);
 }

 void perifericos()
   {
    setcolor(9);
    circle(200,380,50);
    circle(330,380,50);
    floodfill(200,380,9);
    floodfill(330,380,9);
    LETRERO(210,440,13,"PERIFERICOS");
    LETRERO(165,370,4,"SALIDA");
    LETRERO(290,370,4,"ENTRADA");
   }

  void flecha(void)
   {
    setcolor(10);
    line(365,120,390,120);
    line(365,120,375,115);
    line(365,120,375,125);
    line(375,115,375,125);
    line(380,115,380,125);
    line(380,115,390,120);
    line(380,125,390,120);
    bike=malloc(imagesize(363,110,395,130));
      if(bike==NULL)
	{
	 closegraph();
	 printf("\nFALLA EN MEMORIA\n");
	 exit(1);
	}
    getimage(363,110,395,130,bike);
   }

 void salida1()
     {
      int i,a,s;
      flecha();
      for(a=1;a<=5;a++)
       {
	for(i=getmaxx()-294;i>=120;i-=STEP)
	{
	 putimage(18+i,60,bike,COPY_PUT);
	 putimage(18+STEP+i,60,bike,COPY_PUT);
	 putimage(18+i,190,bike,COPY_PUT);
	 putimage(18+STEP+i,190,bike,COPY_PUT);
	 delay(1);
	}
       }
       getch();
       lleno1();
       lleno2();
       getch();
       vacio1();
       vacio2();
       for(s=0;s<=5;s++)
	{
	for(i=120;i<=getmaxx()-300;i+=STEP)
	 {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,191-a,bike,COPY_PUT);
	  putimage(18+STEP+i,191-a,bike,COPY_PUT);
	  delay(1);
	 }
	}
    }

   void salida2()
     {
      int i,a,s;
      vaciob();
      getch();
      flecha();
      for(a=1;a<=5;a++)
       {
	for(i=getmaxx()-294;i>=120;i-=STEP)
	 {
	  putimage(18+i,60,bike,COPY_PUT);
	  putimage(18+STEP+i,60,bike,COPY_PUT);
	  putimage(18+i,190,bike,COPY_PUT);
	  putimage(18+STEP+i,190,bike,COPY_PUT);
	  delay(1);
	 }
       }
       getch();
       lleno1();
       lleno2();
       getch();
       for(s=0;s<=2;s++)
	{
	 for(i=120;i<=getmaxx()-450;i+=STEP)
	  {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,191-a,bike,COPY_PUT);
	  putimage(18+STEP+i,191-a,bike,COPY_PUT);
	  delay(1);
	 }
       }
      for(s=1;s<=2;s++)
       {
	for(a=5;a>=-210;a--)
	 {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,101-a,bike,COPY_PUT);
	  putimage(18+STEP+i,101-a,bike,COPY_PUT);
	  delay(1);
	 }
       }
       getch();
       vacio1();
       vacio2();
     }

  void salida3()
     {
      int i,a,s,j;
      vacioc();
      flecha();
      for(a=1;a<=5;a++)
       {
	for(i=getmaxx()-294;i>=120;i-=STEP)
	 {
	  putimage(18+i,60,bike,COPY_PUT);
	  putimage(18+STEP+i,60,bike,COPY_PUT);
	  putimage(18+i,190,bike,COPY_PUT);
	  putimage(18+STEP+i,190,bike,COPY_PUT);
	  delay(1);
	 }
       }
       lleno1();
       lleno2();
       for(s=0;s<=2;s++)
	{
	 for(i=120;i<=getmaxx()-350;i+=STEP)
	  {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,191-a,bike,COPY_PUT);
	  putimage(18+STEP+i,191-a,bike,COPY_PUT);
	  delay(1);
	 }
       }
      for(s=1;s<=2;s++)
       {
	for(a=5;a>=-205;a--)
	 {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,101-a,bike,COPY_PUT);
	  putimage(18+STEP+i,101-a,bike,COPY_PUT);
	  delay(1);
	 }
       }
       for(j=1;j<=5;j++)
       {
	for(a=-250;a<=5;a++)
	   {
	    putimage(18+i,61-a,bike,COPY_PUT);
	    putimage(18+STEP+i,61-a,bike,COPY_PUT);
	    delay(1);
	   }
	}
      for(a=1;a<=5;a++)
       {
	for(i=getmaxx()-304;i>=120;i-=STEP)
	 {
	  putimage(18+i,60,bike,COPY_PUT);
	  putimage(18+STEP+i,60,bike,COPY_PUT);
	  putimage(18+i,190,bike,COPY_PUT);
	  putimage(18+STEP+i,190,bike,COPY_PUT);
	  delay(1);
	 }
       }
      vacio1();
      vacio2();
      for(s=0;s<=5;s++)
	{
	for(i=120;i<=getmaxx()-300;i+=STEP)
	 {
	  putimage(18+i,61-a,bike,COPY_PUT);
	  putimage(18+STEP+i,61-a,bike,COPY_PUT);
	  putimage(18+i,191-a,bike,COPY_PUT);
	  putimage(18+STEP+i,191-a,bike,COPY_PUT);
	  delay(1);
	 }
	}
     }

  void procesador1(int m)
   {
    setcolor(m);
    rectangle(30,50,130,140);
   }

  void procesador2(int m)
   {
    setcolor(m);
    rectangle(30,185,130,275);
   }

 void LETRERO(int col,int fil,int cl,char* t)
  {
   setcolor(cl);
   settextstyle(2,0,7);
   moveto(col,fil);
   outtext(t);
  }

void lleno1()
  {
   int i,j;
   for(j=51;j<=139;j++)
     {
      for(i=31;i<=129;i++)
      {
       putpixel(i,j,14);
       delay(0);
      }
     }
   }

void vacio1()
  {
   int i,j;
   for(j=51;j<=139;j++)
     {
      for(i=31;i<=129;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }

void lleno2()
  {
   int i,j;
   for(j=186;j<=274;j++)
     {
      for(i=31;i<=129;i++)
      {
       putpixel(i,j,2);
       delay(0);
      }
     }
   }
void vacio2()
  {
   int i,j;
   for(j=186;j<=274;j++)
     {
      for(i=31;i<=129;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }

void lleno()
  {
   int i,j,CL=1,c=1;
   for(j=50;j<=250;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,CL);
       delay(0);
      }
      c++;
      if(c==26)
	{
	 c=1;
	 CL=CL+1;
	}
     }
   }

 void llenoa()
  {
   int i,j,CL=1,c=1;
   for(j=50;j<=100;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,CL);
       delay(0);
      }
      c++;
      if(c==27)
	{
	 c=1;
	 CL=CL+1;
	}
     }
   }

  void llenob()
  {
   int i,j,CL=7,c=1;
   for(j=101;j<=152;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,CL);
       delay(0);
      }
      c++;
      if(c==27)
	{
	 c=1;
	 CL=CL+1;
	}
     }
   }

  void llenoc()
  {
   int i,j,CL=5,c=1;
   for(j=152;j<=203;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,CL);
       delay(0);
      }
      c++;
      if(c==27)
	{
	 c=1;
	 CL=CL+1;
	}
     }
   }

 void vacioa()
  {
   int i,j;
   for(j=50;j<=100;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }

 void vaciob()
  {
   int i,j;
   for(j=101;j<=152;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }

 void vacioc()
  {
   int i,j;
   for(j=153;j<=204;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }
 void vaciod()
  {
   int i,j;
   for(j=206;j<=250;j++)
     {
      for(i=401;i<=599;i++)
      {
       putpixel(i,j,0);
       delay(0);
      }
     }
   }


 void memoria()
  {
   setcolor(15);
   rectangle(400,49,600,275);
   setcolor(4);
   rectangle(401,251,599,274);
   floodfill(403,253,4);
   LETRERO(480,254,4,"S.O.");
  }

  void presentacion()
  {
  int i,ymax,xmax;
  xmax=getmaxx();
  ymax=getmaxy();
  cleardevice();
  setcolor(RED);
  rectangle(0,0,xmax,ymax);
  rectangle(1,1,xmax-1,ymax-1);
  rectangle(2,2,xmax-2,ymax-2);
  rectangle(3,3,xmax-3,ymax-3);

  setcolor(DARKGRAY);
  rectangle(12*xmax/64,12*ymax/64,50*xmax/64,30*ymax/64);
  rectangle(13*xmax/64-2,13*ymax/64,49*xmax/64+2,29*ymax/64);
  line(50*xmax/64,30*ymax/64,49*xmax/64+2,29*ymax/64);
  line(50*xmax/64,12*ymax/64,49*xmax/64+2,13*ymax/64);
  line(12*xmax/64,30*ymax/64,13*xmax/64-2,29*ymax/64);
  setfillstyle(SOLID_FILL,DARKGRAY);
  floodfill(49*xmax/64,29*ymax/64+2,DARKGRAY);
  floodfill(49*xmax/64+4,29*ymax/64,DARKGRAY);
  setfillstyle(SOLID_FILL,WHITE);
  floodfill(12*xmax/64+2,12*ymax/64+2,DARKGRAY);
  setfillstyle(SOLID_FILL,LIGHTGRAY);
  floodfill(13*xmax/64,13*ymax/64+2,DARKGRAY);
  setcolor(WHITE);
  rectangle(14*xmax/64,14*ymax/64,48*xmax/64,28*ymax/64);
  setcolor(DARKGRAY);
  rectangle(14*xmax/64+1,14*ymax/64+1,48*xmax/64-1,28*ymax/64-1);
  settextstyle(3,0,4);
  setcolor(LIGHTBLUE);
  outtextxy(xmax/2-175,19*ymax/64,"SISTEMAS OPERATIVOS");

  settextstyle(0,0,1);
  for (i=6*xmax/8-43;i>2*80/8+3;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/8,"  GUILLERMO BECERRA   ");
     setcolor(BLACK);
     outtextxy(i,5*ymax/8,"  GUILLERMO BECERRA ");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/8,"  GUILLERMO BECERRA ");

  settextstyle(0,0,1);
  for (i=6*xmax/8-43;i>1*xmax/8+400;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/8,"  YULI SOLER");
     setcolor(BLACK);
     outtextxy(i,5*ymax/8,"  YULI SOLER");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/8,"  YULI SOLER");

  for (i=ymax-20;i>5*ymax/8+20;i-=1)
   {
     setcolor(LIGHTRED);
     outtextxy(xmax/2-260,i,"Cod. 493356                                      Cod. 494276");
     setcolor(BLACK);
     outtextxy(xmax/2-260,i,"Cod. 493356                                      Cod. 494276");
   }
  setcolor(LIGHTRED);
  outtextxy(xmax/2-260,i,"Cod. 493356                                      Cod. 494276");


  for (i=10;i<2*xmax/8+50;i+=1)
   {
     setcolor(LIGHTBLUE);
     outtextxy(i,6*ymax/8,"UNIVERSIDAD ANTONIO NARI¥O");
     setcolor(BLACK);
     outtextxy(i,6*ymax/8,"UNIVERSIDAD ANTONIO NARI¥O");
   }
  setcolor(LIGHTBLUE);
  outtextxy(i,6*ymax/8,"UNIVERSIDAD ANTONIO NARI¥O");

  for (i=ymax-20;i>6*ymax/8+20;i-=1)
   {
     setcolor(LIGHTRED);
     outtextxy(xmax/2-95,i,"INGENIERIA DE SISTEMAS");
     setcolor(BLACK);
     outtextxy(xmax/2-95,i,"INGENIERIA DE SISTEMAS");
   }
  setcolor(LIGHTRED);
  outtextxy(xmax/2-95,i,"INGENIERIA DE SISTEMAS");

  do{
     setcolor(GREEN);
     outtextxy(xmax/2-140,ymax-50,"Presione una tecla para continuar");
     setcolor(LIGHTGREEN);
     outtextxy(xmax/2-140,ymax-50,"Presione una tecla para continuar");
    }while(!kbhit());
  closegraph();
 }
