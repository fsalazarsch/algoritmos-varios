#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

void main()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy,a,c,t;

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
	  setpalette(3,BLUE);setcolor(1);
	  settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
     outtextxy(55,30,"PARCIAL FINAL MODELOS DE PROGRAMACION III.");


	  setpalette(4,WHITE);setcolor(WHITE);
	  settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
     outtextxy(90,150,"HECTOR THOMAS MOLINA");
	  setpalette(4,WHITE);setcolor(WHITE);
	  


      setpalette(6,WHITE);setcolor(WHITE);
	  settextstyle(SMALL_FONT,HORIZ_DIR,6);
     outtextxy(150,350,"CORPORACION UNIVERSITARIA DE SANTANDER ");

      setpalette(3,GREEN);setcolor(GREEN);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
     outtextxy(115,365,"FACULTAD DE INGENIERIA DE SISTEMAS");

      setpalette(7,YELLOW);setcolor(1);
	  settextstyle(SMALL_FONT,HORIZ_DIR,7);
     outtextxy(280,300,"CURSO S3E");

     setpalette(2,WHITE);setcolor(WHITE);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
     outtextxy(280,400,"VALLEDUPAR");

     setpalette(3,BLUE);setcolor(BLUE);
	  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
     outtextxy(300,420,"1.998");

     getche();
     textbackground(8);
     cleardevice();



   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());
   setcolor(0);

   setfillstyle(6,7);
   fillellipse(300,400,800,100);
   setfillstyle(1,14);
   fillellipse(300,300,50,30);
   setfillstyle(1,9);
   fillellipse(300,350,480,50);
	for(t=1;t<=10;t++){
for(c=1;c<=10;c++){
   for(a=1;a<=10;a++){
   delay(3);


   putpixel(300+a+c+t*a*c*t/14,300+c/a*t,14);
   putpixel(300-a-c-t*a*c*t/14,300+c/a*t,14);
   putpixel(300+a+c+t*a*c*t/14,300-c/a*t,14);
   putpixel(300-a-c-t*a*c*t/14,300-c/a*t,14);

     }
   } }


   /* draw the circle */
   for(a=1;a<=700;a++){
   delay(0);
   setcolor(4);
   circle(50+a,100, 50);
   setcolor(15);
   line(5+a,120,30+a,200);
   setcolor(15);
   line(95+a,120,70+a,200);
   setcolor(15);
   line(50+a,140,50+a,210);
   setcolor(15);
  ellipse(50+a,200,0,360,20,10);
   setcolor(15);
  ellipse(50+a,220,180,360,20,10);
   setcolor(15);
   line(29+a,200,29+a,220);
   setcolor(15);
   line(71+a,200,71+a,220);
  setcolor(4);
  arc(60+a,100,90,270,50);
  setcolor(4);
  arc(90+a,100,128,232,65);
  setcolor(4);
  arc(10+a,100,128-180,232-180,65);
  setcolor(4);
  arc(39+a,100,90-180,270-180,50);
  setcolor(4);
   line(50+a,50,50+a,150);
   setcolor(0);
   setfillstyle(1,8);
   fillellipse(50+a,350,50,10);

   /*borran*/
   setcolor(0);
   circle(50+a-2,100, 50);
   setcolor(0);
   line(5+a-1,120,30+a-1,200);
   setcolor(0);
   line(95+a-1,120,70+a-1,200);
   setcolor(0);
   line(50+a-1,140,50+a-1,210);
   setcolor(0);
  ellipse(50+a-1,200,0,360,20,10);
   setcolor(0);
  ellipse(50+a-1,220,180,360,20,10);
   setcolor(0);
   line(29+a-1,200,29+a-1,220);
   setcolor(0);
   line(71+a-1,200,71+a-1,220);
  setcolor(0);
  arc(60+a-1,100,90,270,50);
  setcolor(0);
  arc(90+a-1,100,128,232,65);
  setcolor(0);
  arc(10+a-1,100,128-180,232-180,65);
 setcolor(0);
  arc(39+a-1,100,90-180,270-180,50);
  setcolor(0);
   line(50+a-1,50,50+a-1,150);
   setcolor(9);
   setfillstyle(1,9);
   fillellipse(50+a-1,350,50,10);



   }
   nosound();

   setcolor(15);
   getch();
   closegraph();
}
