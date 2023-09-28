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
 outtextxy(25,300,"OCTAVIO FIGUEROA SOLANO");
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
rectangle(1+i,380,200+i,350);
      rectangle(203+i,280,250+i,350);
      rectangle(203+i,380,250+i,380);
      circle(40+i,399,15);circle(80+i,399,15);circle(170+i,399,15); circle(220+i,399,15);
getchar();
}