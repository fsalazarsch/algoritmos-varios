#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PIXEL_COUNT 100
#define DELAY_TIME  10  /* in milliseconds */

int main(void)
{
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   int i, x, y, color, maxx, maxy, maxcolor, seed;
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
       setcolor(15);
       line(10,150,230,150);
       line(10,150,10,270);
       line(10,270,70,270);
       line(110,270,230,270);
       line(270,270,350,270);
       line(10,210,230,210);
       line(60,150,60,210);
       line(165,150,165,210);
       arc(230,270,0,15,120);
       setfillstyle(0,0);
       sector(230,240,0,90,115,90);
       circle(90,270,20);
	circle(90,270,12);
       circle(250,270,20);
       circle(250,270,12);
     setfillstyle(9,3);
    floodfill(11,260,15);
   line(350+100,150,390+100,250);
   line(350+100,150,310+100,250);
   line(365+100,240,390+100,250);
   line(335+100,240,310+100,250);
   line(365+100,240,415+100,310);
   line(335+100,240,285+100,310);
   line(375+100,290,415+100,310);//linea IZQ
   line(325+100,290,285+100,310);//linea DER
   line(375+100,290,440+100,370);
   line(325+100,290,260+100,370);
   line(345+100,345,440+100,370);
   line(355+100,345,260+100,370);
   setfillstyle(6,2);
   floodfill(350+100,160,15);
   setfillstyle(6,6);
   bar(340+100,345,360+100,370);
   setcolor(4);
   outtextxy(90,230,"COTRACEGUA");
   }
   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}
