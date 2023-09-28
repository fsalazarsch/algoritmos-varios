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
	initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
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
	/***********************************/
	setfillstyle(SOLID_FILL,BROWN);
	bar(250,300,305,430);
	/*for(i=260;i<=265;i++);
	{
	circle(22+i,i-265,7);
	}*/
	rectangle(250,300,305,430);
	line(100,300,335,-80);
	line(450,300,290,-1);
	line(450,300,100,300);

	setfillstyle(1,BLUE);
	 setcolor(14);
	 fillellipse(450,90,30,20);
	 fillellipse(490,90,30,20);
	 fillellipse(535,90,30,20);

	/*line(120,300,330,-80);
	line(430,300,290,-1);*/






	//setlinestyle(SOLID_LINE,1,1);
	//setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
	//sector(getmaxx()/2,560, 360,180 , 100+20*12, 50+20*5);
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


	  setcolor(2);
	 setfillstyle(SOLID_FILL,RED);

	 circle(200,200,5);
	  setcolor(13);
	  circle(300,200,5);
	  circle(330,299,5);
		circle(280,98,5);
	  circle(300,80,5);
	  circle(280,40,5);
	  circle(280,100,5);
	  circle(300,200,5);
	  circle(280,330,5);
	  circle(330,200,5);
	  circle(330,299,5);
	  circle(305,290,5);
	  circle(290,299,5);
	  circle(270,286,5);
	  circle(270,240,5);
	  circle(290,10,5);

	  circle(330,150,5);
	  circle(305,150,5);
	  circle(290,150,5);
	  circle(270,120,5);
	  circle(270,248,5);
	  circle(290,258,5);

	  circle(330,249,5);
	  circle(305,237,5);
	  circle(290,257,5);
	  circle(260,178,5);
	  circle(260,268,5);
	  circle(260,228,5);
	  circle(200,228,5);
	  circle(200,240,5);
	  circle(160,299,5);
	  circle(150,296,5);
	  circle(140,276,5);
	  circle(350,228,5);
	  circle(360,240,5);
	  circle(370,299,5);
	  circle(350,296,5);
	  circle(380,276,5);
	  circle(380,230,5);
		 /////////
	  setcolor(6);
	  circle(280,98,5);
	  circle(300,80,5);
	  circle(280,40,5);
	  circle(280,100,5);
	  circle(300,200,5);
	  circle(280,330,5);
	  circle(330,200,5);
	  setcolor(9);
	  circle(330,299,5);
	  circle(305,290,5);
	  circle(290,299,5);
	  circle(270,286,5);
	  circle(270,240,5);
	  circle(290,10,5);

	  circle(330,150,5);
	  circle(305,150,5);
	  circle(290,150,5);
	  circle(270,120,5);
	  circle(270,248,5);
	  circle(290,258,5);

	  circle(330,249,5);
	  circle(305,237,5);
	  circle(290,257,5);
	  circle(260,178,5);
	  circle(260,268,5);
	  circle(260,228,5);
	  setcolor(14);
	  circle(200,228,5);
	  circle(200,240,5);
	  circle(160,299,5);
	  circle(150,296,5);
	  circle(140,276,5);

	  circle(350,228,5);
	  circle(360,240,5);
	  circle(370,299,5);
	  circle(350,296,5);
	  circle(380,276,5);
	  circle(380,230,5);


}
}



getch();


bioskey(1);
closegraph();
}