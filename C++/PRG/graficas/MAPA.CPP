#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void imprimir();
void mapa();

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int i, maxx, maxy;


   initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }

   imprimir();
   mapa();

   closegraph();
   return 0;
}


void mapa()
{ int i,poly[20];
/* 640  480 */
   poly[0] = 40;        /* 1st vertex */
   poly[1] = 360;

   poly[2] = 70;        /* 1st vertex */
   poly[3] = 250;

   poly[4] = 160;        /* 1st vertex */
   poly[5] = 130;

   poly[6] = 510;        /* 1st vertex */
   poly[7] = 20;

   poly[8] = 590;        /* 1st vertex */
   poly[9] = 20;

   poly[10] = 590;        /* 1st vertex */
   poly[11] = 60;

   poly[12] = 490;        /* 1st vertex */
   poly[13] = 90;

   poly[14] = 350;        /* 1st vertex */
   poly[15] = 340;

   poly[16] = 50;        /* 1st vertex */
   poly[17] = 360;

   for (i=EMPTY_FILL; i<USER_FILL; i++)
   {

      setfillstyle(i, getmaxcolor());

      fillpoly(9, poly);

      getch();
   }
}

void imprimir()
{ setcolor(15);
  rectangle(1,380,639,467);
  setfillstyle (SOLID_FILL,4);
  bar(3,382,637,397);
  rectangle(1,2,639,380);
  rectangle(1,380,639,399);
  setfillstyle (INTERLEAVE_FILL,7);
  bar(3,401,637,465);
}
