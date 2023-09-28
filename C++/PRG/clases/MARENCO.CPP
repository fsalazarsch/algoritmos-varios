#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void main(void)
{

   int gdriver = DETECT, gmode, errorcode;
	 int midx, midy,i=0,j;
	 int stangle = 45, endangle = 135;

	 int op;
	 initgraph(&gdriver, &gmode, "");
	 errorcode = graphresult();
	if (errorcode != grOk)  /* occurre un error */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminar */
	}

	midx = getmaxx() / 2;
	midy = getmaxy() / 2;
//PRESENTACION..............
 setcolor(GREEN);
 setbkcolor(15);
 settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
 outtextxy(120,20,"U     D     E     S");
 settextstyle(3,HORIZ_DIR,0);
 outtextxy(85,80,"MODELO DE PROGRAMACION I");
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,0);
 outtextxy(200,140,"III  SEMESTRE");
 settextstyle(SMALL_FONT,HORIZ_DIR,-2);
 outtextxy(55,180,"PROFESOR  ROBERTO FERNADEZ");
 settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
 outtextxy(150,240,"INGENIERIA DE SISTEMAS");
 settextstyle(4,HORIZ_DIR,0);
 outtextxy(25,300,"JONATHAN OSWALDO MARENCO");
 settextstyle(8,HORIZ_DIR,4);
 outtextxy(280,375,"VALLEDUPAR");
 settextstyle(6,HORIZ_DIR,4);
 outtextxy(293,420,"1 9 9 8");
 cleardevice();
 settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
 setbkcolor(0);
 /***********************************/
   //NUVES..........
  while(!kbhit()){
  cleardevice();
  setcolor(15);
  arc(midx+i,100, stangle, endangle,40);
  arc(midx+50+i,100,stangle+10, endangle+10,40);
  arc(midx+100+i,100,stangle+10, endangle+10,40);
  arc(midx+i,100,stangle+30, endangle+30,40);
  arc(midx+110+i,105,endangle+100,stangle+30,40);
  arc(midx+i,100,150,320,40);
  arc(midx+60+i,100,220,305,50);
  /*************************************/
   //NUVES..........
   arc(midx+200+i,100, stangle, endangle,40);
   arc(midx+250+i,100,stangle+10, endangle+10,40);
   arc(midx+300+i,100,stangle+10, endangle+10,40);
   arc(midx+200+i,100,stangle+30, endangle+30,40);
   arc(midx+310+i,105,endangle+100,stangle+30,40);
   arc(midx+200+i,100,150,320,40);
   arc(midx+260+i,100,220,305,50);
   //SOL........
   setcolor(YELLOW);
   fillellipse(520,90,90,90);
   setcolor(15);
   setfillstyle(1,YELLOW);
   setfillstyle(SOLID_FILL,LIGHTGREEN);
   bar(midx-i,midy,midx-i+250,midy+100);
   setcolor(0);
   rectangle(midx-i+10,midy+10,midx-i+50,midy+50);
   rectangle(midx-i+70,midy+10,midx-i+120,midy+50);
   rectangle(midx-i+155,midy+10,midx-i+215,midy+50);
   rectangle(midx-i+160,midy+10,midx-i+220,midy+50);
   rectangle(midx-i+20,midy+60,midx-i+230,midy+70);
   /***************************************/
   setfillstyle(SOLID_FILL,LIGHTBLUE);
   bar(midx-i+1,midy,midx-i+5,midy+100);
   setfillstyle(SOLID_FILL,LIGHTBLUE);
   bar(midx-i+245,midy,midx-i+250,midy+100);
   setcolor(15);
   line(10,479,367,380);// LINEAS DE LA CARRECTERA
   line(200,485,385,380);
   line(376,380,330,400);
   line(310,410,220,450);
   line(200,460,180,470);
   line(10,380,700,380);
   /*****************************************/
   setcolor(2);
   line(midx-i-10,midy,midx-i-50,midy);
   line(midx-i-10,midy+10,midx-i-50,midy+10);
   line(midx-i-15,midy+15,midx-i-50,midy+15);
   line(midx-i-50,midy,midx-i-100, midy+50);
   line(midx-i-50,midy+10,midx-i-90,midy+50);
   line(midx-i-50,midy+15,midx-i-85,midy+50);
   line(midx-i-85,midy+50,midx-i-15,midy+50);
   line(midx-i-15,midy+50,midx-i-15,midy+15);
   line(midx-i-90,midy+50,midx-i-90,midy+90);
	line(midx-i-10,midy,midx-i,midy+10);  //lineas del carro
	line(midx-i-100,midy+50,midx-i-150,midy+50);
	line(midx-i-150,midy+50,midx-i-150,midy+100);
	line(midx-i-150,midy+100,midx-i,midy+100);
	line(midx-i-90,midy+90,midx-i-10,midy+90);
	line(midx-i-10,midy+90,midx-i-10,midy+10);
 /*********************************************/
	fillellipse(midx-i-95,midy+100,25,25);  //llantas del carro
	fillellipse(midx-i+100,midy+100,25,25);
	fillellipse(midx-i+165,midy+100,25,25);
	setcolor(0);
	fillellipse(midx-i+165,midy+100,20,20); //rin del carro
	fillellipse(midx-i+100,midy+100,20,20);
	fillellipse(midx-i-95,midy+100,20,20);
	i+=5;
	outtextxy(midx-i+40,midy+62,"LAS VAINAS DE MI PUEBLO"); //letrero del carro
	if(i>getmaxx()){
	  i=10;
	  midx<getmaxx();
	  getch();
	  }
	}
 closegraph();
 }