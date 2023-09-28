#include <graphics.h>
#include <bios.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <io.h>
#include <fcntl.h>
struct Figura{
int a,b,c,z;
}reg;
int style,a,b,c;
void main(void)
{

   int gdriver = DETECT, gmode, errorcode;
	int midx, midy,i=0,j,id;
	int stangle = 45, endangle = 135;
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
    for(int z=1;z<=5000;z++)//dibuja 5000 puntos en el lvideo
	  {
	    a=random(680);
	    b=random(100);
	    c=random(16);
	    putpixel(a,b,c);// x and y el color
	  }
    rectangle(300,350,50,250);
    rectangle(300,350,50,300);
    rectangle(300,350,50,270);
    rectangle(350,300,300,350);
    setcolor(RED);
    circle(70,350,10); 
    circle(120,350,10);
    circle(170,350,10);
    circle(220,350,10);
    circle(270,350,10);
    circle(320,350,10);
    setcolor(YELLOW);
    circle(350,310,5);
    setcolor(BLUE);
    circle(283,287,5);
    line(260,270,260,300);
    line(220,270,220,300);
    line(180,270,180,300);
    line(140,270,140,300);
    line(100,270,100,300);
    line(295,295,280,283);
    setcolor(GREEN);
    line(380,150,420,75);
    line(390,75,450,150);
    line(375,156,407,139);
    line(418,139,449,156);
    line(400,145,370,250);
    line(455,250,430,145);
    line(374,250,458,250);
    setcolor(LIGHTMAGENTA );
    circle(407,80,15);
    setcolor(LIGHTRED );
    circle(370,154,10);
    setcolor(LIGHTBLUE);
    circle(450,154,10);
    setcolor(LIGHTGRAY );
    arc(120,70,70,300,30);
    arc(140,70,100,250,30);
    setcolor(LIGHTMAGENTA);
    line(150,150,480,300);
    line(450,400,100,400);
    outtextxy(130,254,"FELIZ NAVIDAD");
    settextstyle(style, HORIZ_DIR, 2); 
    setcolor( LIGHTCYAN); 
    outtextxy(280,30,"LUISA SANABRIA");
getch();



closegraph();

}

/*{BLACK       DARKGRAY
BLUE        LIGHTBLUE
GREEN       LIGHTGREEN
CYAN        LIGHTCYAN
RED         LIGHTRED
MAGENTA     LIGHTMAGENTA
BROWN       YELLOW
LIGHTGRAY   WHITE  } */