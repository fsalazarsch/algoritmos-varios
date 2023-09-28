#include <graphics.h>
#include <bios.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <io.h>
#include <fcntl.h>
#define PIXEL_COUNT 1000
#define DELAY_TIME  100  /* in milliseconds */

struct Figura{
int x,y,x1,y1;
int clase,v;
}reg;
int i, x, y, color, maxx, maxy, maxcolor, seed,midx;
int salir,s,x1,y1,a,b,c,z;
int B;
void main(void)
{

   int gdriver = DETECT, gmode, errorcode;
	int i=0,j,id;
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
setcolor(GREEN);
 setbkcolor(15);
 /*settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(120,20,"U     D     E     S");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(30,80,"MODELO DE PROGRAMACION II");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(190,140,"III SEMESTRE");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(1,180,"PROFESOR  ROBERTO FERNADEZ");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(100,240,"INGENIERIA DE SISTEMAS");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(25,300,"JONATHAN OSWALDO MARENCO");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(210,375,"VALLEDUPAR");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
 outtextxy(240,420,"1 9 9 8");
 setcolor(125);
 rectangle(638,1,1,630);
 delay(2000);
 cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
 setbkcolor(0);
	midx = 100;
	setbkcolor(0);*/
	/***********************************/
	setfillstyle(SOLID_FILL,BROWN);
	bar(220,300,325,430);
	/*for(i=260;i<=265;i++);
	{
	circle(22+i,i-265,7);
	}*/

	circle(500,350,20);
	circle(500,400,30);
	setcolor(YELLOW);circle(500,398,4);
	circle(500,380,4);
	circle(500,415,4);
	setcolor(BROWN);circle(495,340,2);
		setcolor(BROWN);circle(505,340,2);
		setcolor(BROWN);circle(495,340,5);
	rectangle(220,300,325,430);
	setcolor(GREEN);delay(300);line(100,300,335,-80);
	line(450,300,290,-1);
	line(450,300,100,300);
	setcolor(RED);delay(300);line(120,300,330,-80);
	delay(300);line(430,300,290,-1);
	setcolor(GREEN);delay(300);line(140,300,326,-80);
	delay(300);line(410,300,290,-1);
	setcolor(RED);delay(300);line(160,300,322,-80);
	delay(300);line(390,300,290,-1);
	setcolor(GREEN);delay(300);line(180,300,318,-80);
	delay(300);line(370,300,290,-1);
	setcolor(RED);delay(300);line(200,300,314,-80);
	delay(300);line(350,300,290,-1);
	setcolor(GREEN);delay(300);line(220,300,306,-80);
	delay(300);line(330,300,290,-1);
	setcolor(RED);delay(300);line(240,300,302,-80);
	delay(300);line(310,300,290,-1);
	setcolor(GREEN);delay(300);line(260,300,296,-80);
	delay(300);line(290,300,290,-1);
	setcolor(RED);delay(300);line(275,300,294,-80);


	setlinestyle(SOLID_LINE,1,1);
	setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
	sector(getmaxx()/2,560, 360,180 , 100+20*12, 50+20*5);
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