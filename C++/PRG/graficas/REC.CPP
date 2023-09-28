#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int left, top, right, bottom, i, j;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   settextstyle(1,0,2);
   setcolor(7);
   setbkcolor(0);
   outtextxy(200,20,"NOMBRE");
   rectangle(300,10,500,40);
   floodfill(1,1,7);
   gotoxy(40,2);cin>>j;
   getch();
   closegraph();
   return 0;
}

