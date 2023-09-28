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
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
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
	setbkcolor(0);
	/***********************************/
	setfillstyle(SOLID_FILL,BROWN);
	bar(250,300,305,430);
	for(i=0;i<=15;i++)
	{
	setcolor(0+i);
	circle(288+i,55+i,7);circle(288+i,65+i,7);circle(288+i,75+i,7);
	circle(200+i,155+i,7);circle(200+i,165+i,7);circle(200+i,175+i,7);
	circle(200+i,185+i,7);circle(258+i,65+i,7);circle(258+i,75+i,7);
	circle(258+i,55+i,7);circle(258+i,65+i,7);circle(258+i,75+i,7);
	setcolor(15+i);
	circle(288+i,155+i,7);circle(288+i,165+i,7);circle(288+i,175+i,7);
	circle(288+i,185+i,7);circle(350+i,155+i,7);circle(350+i,165+i,7);
	circle(350+i,175+i,7);circle(350+i,185+i,7);
	circle(180+i,220+i,7);circle(180+i,230+i,7);circle(180+i,240+i,7);
	circle(180+i,255+i,7);circle(180+i,465+i,7);circle(180+i,475+i,7);
	circle(180+i,485+i,7);circle(280+i,220+i,7);circle(280+i,230+i,7);
	circle(280+i,240+i,7);circle(280+i,255+i,7);circle(280+i,465+i,7);
	circle(280+i,475+i,7);circle(280+i,485+i,7);circle(350+i,220+i,7);
	circle(350+i,230+i,7);circle(350+i,240+i,7);circle(350+i,255+i,7);
	circle(350+i,465+i,7);circle(350+i,475+i,7);circle(350+i,485+i,7);
	}
	rectangle(250,300,305,430);
	line(100,300,335,-80);
	line(450,300,290,-1);
	line(450,300,100,300);

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