#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int i, j ,h; 
//int Matriz[8] ={260,150,10,150,10,220,10,310};
void pantalla();
void otro();
void arbol();

void pantalla()
	{
	setbkcolor(1);
	settextstyle(0,0,2);
		 while(!kbhit())
		 {
	 setcolor( 15);
	 outtextxy(75,getmaxy()/2,"JOAQUIN  GUILLERMO  DIAZ  C   UDES");
	 delay(290);
	 setcolor(2);
	 outtextxy(75,getmaxy()/2,"JOAQUIN  GUILLERMO  DIAZ  C   UDES");
	 delay(500);
	}
	}




void arbol()
	 {
	int gdriver = DETECT, gmode, errorcode;
	char msg[80];

	initgraph(&gdriver, &gmode, "");

	  if (errorcode != grOk)
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
	}

	moveto(180, 50);

	lineto(130, 100);
	lineto(150, 100);
	lineto(90, 150);
	lineto(120, 150);
	lineto(75, 190);
	lineto(130, 190);//l_no_se
	lineto(160, 250);
	lineto(110,250);
	lineto(110, 260);
	lineto(240, 260); //linea_centro
	lineto(240,250);
	lineto(190, 250);
	lineto(210, 190);

	moveto(180, 50); //linea_arriba

	 lineto(225, 100);


	lineto(207, 100);
	lineto(250 ,150);
	lineto(225, 150);
	lineto(260, 189);
	lineto(210, 189);

	getch();
	closegraph();
  
}









void main()

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
	outtextxy(70,5,"Modelos de Programacion II");
	settextstyle(1,0,3);
	outtextxy(90,80,"    Parcial final - 27 de Noviembre ");
	settextstyle(2,0,7);
	outtextxy(215,150,"M o d o  G r a f i c o ");
   
	pantalla();
   
	setbkcolor(4);
	settextstyle(0,0,1);
   
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
		 outtextxy(90+i,230,"BRASILIA");
		 setcolor(14);
		 
		}
	 
	getch();
	closegraph();
	 
   arbol();
}




