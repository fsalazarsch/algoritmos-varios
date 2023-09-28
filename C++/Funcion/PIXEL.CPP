#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define PIXEL_COUNT 1000
#define DELAY_TIME  100  /* in milliseconds */

int main(void)
{  char p[5];
   /* request autodetection */
   int gdriver = DETECT, gmode, errorcode;
   int i, x, y, color, maxx, maxy, maxcolor, seed;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "\\borlandc\\BGI\\");

   /* read result of initialization */
   errorcode = graphresult();
   gotoxy(20,20);cprintf("hola");
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   maxx = getmaxx() + 1;
   maxy = getmaxy() + 1;
   maxcolor = getmaxcolor() + 1;
   gotoxy(20,20);cprintf("hola");
   while (!kbhit())
   {  gotoxy(20,20);cprintf("hola");
	     
      /*the random number generator */
      seed = random(32767);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
         x = random(maxx);
         y = random(maxy);
         color = random(maxcolor);
	 putpixel(x, y, color);
	 gotoxy(20,20);cprintf("hola");
      }

      delay(DELAY_TIME);
      srand(seed);
      for (i=0; i<PIXEL_COUNT; i++)
      {
         x = random(maxx);
         y = random(maxy);
	 color = random(maxcolor);
	 gotoxy(20,20);cprintf("hola");
	 if (color == getpixel(x, y))
	    putpixel(x, y,WHITE);
	   // p="hola";
	    //putpixel(x,y,p);
	   gotoxy(20,20);cprintf("hola");
      }
   }

   /* clean up */
   getch();
   closegraph();
   return 0;
}

