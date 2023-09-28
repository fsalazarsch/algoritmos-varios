#include<dos.h>
#include<graphics.h>
#include<conio.h>

void presentacion1();

 void presentacion1()
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
  settextstyle(7,0,3);
  setcolor(LIGHTBLUE);
  outtextxy(xmax/2-175,19*ymax/64,"TUTOR DE PROGRAMACION");

  settextstyle(0,0,1);

  for (i=6*xmax/8-43;i>2*80/8+3;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/8,"  ALVARO A. CARRILLO   ");
     setcolor(BLACK);
     outtextxy(i,5*ymax/8,"  ALVARO A. CARRILLO   ");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/8,"  ALVARO A. CARRILLO ");


  settextstyle(0,0,1);
  for (i=6*xmax/8-43;i>1*xmax/8+400;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/8,"  MIGUEL MONTENEGRO");
     setcolor(BLACK);
     outtextxy(i,5*ymax/8,"  MIGUEL MONTENEGRO");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/8,"  MIGUEL MONTENEGRO");

    settextstyle(0,0,1);
    for (i=6*xmax/8-43;i>2*80/8+3;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/7," JORGE CARLOS JIMENEZ ");
     setcolor(BLACK);
     outtextxy(i,5*ymax/7," JORGE CARLOS JIMENEZ   ");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/7," JORGE CARLOS JIMENEZ ");

  settextstyle(0,0,1);
  for (i=6*xmax/8-43;i>1*xmax/8+400;i-=1)
  {
     setcolor(LIGHTBLUE);
     outtextxy(i,5*ymax/7,"  LIBANNYS ARGUELLES");
     setcolor(BLACK);
     outtextxy(i,5*ymax/7,"  LIBANNYS ARGUELLES");
  }
  setcolor(LIGHTBLUE);
  outtextxy(i,5*ymax/7,"  LIBANNYS ARGUELLES");

  for (i=10;i<2*xmax/8+50;i+=1)
   {
     setcolor(LIGHTBLUE);
     outtextxy(i,6*ymax/8,"  EGOSYSTEM LTDA");
     setcolor(BLACK);
     outtextxy(i,6*ymax/8,"  EGOSYSTEM LTDA");
   }
  setcolor(LIGHTBLUE);
  outtextxy(i,6*ymax/8,"     EGOSYSTEM LTDA");

  for (i=ymax-20;i>6*ymax/8+20;i-=1)
   {
     setcolor(LIGHTRED);
     outtextxy(xmax/2-95,i,"INGENIEROS DE SISTEMAS");
     setcolor(BLACK);
     outtextxy(xmax/2-95,i,"INGENIEROS DE SISTEMAS");
   }
  setcolor(LIGHTRED);
  outtextxy(xmax/2-95,i,"INGENIEROS DE SISTEMAS");

  do{
     setcolor(GREEN);
     outtextxy(xmax/2-140,ymax-50,"Presione una tecla para continuar");
     setcolor(LIGHTGREEN);
     outtextxy(xmax/2-140,ymax-50,"Presione una tecla para continuar");
    }while(!kbhit());
 }