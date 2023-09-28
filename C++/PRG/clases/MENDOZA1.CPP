# include "conio.h"
# include "stdio.h"
# include "graphics.h"
//# include "iostream.h"
# include "dos.h"

void ciudad();

void main()
{
  int i,j,a, unidad=DETECT,modo;

  initgraph(&unidad,&modo,"c:\\tc\\bgi");
	 setfillstyle(1,YELLOW);
	 fillellipse(150,450,1000,550);
	 setpalette(2,YELLOW);
	 setcolor(2);
	 settextstyle(DEFAULT_FONT, HORIZ_DIR,4);
	 outtextxy(120,30,"CARRO");
	 getchar();
	 setpalette(3,BLUE);
	 setcolor(3);
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	 outtextxy(80,150,"CARLOS ALBERTO");
	 getchar();
	 setpalette(4,BLUE);
	 setcolor(4);
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	 outtextxy(120,190,"MENDOZA ALVAREZ");
	// getchar();
	 setpalette(5,RED);
	 setcolor(5);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 outtextxy(130,290,"FACULTAD DE ING. DE SISTEMAS");
	 getchar();
	 setpalette(6,MAGENTA);
	 setcolor(6);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 outtextxy(240,320,"III SEMESTRE");
	 getchar();
	 setpalette(7,GREEN);
	 setcolor(7);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 outtextxy(80,350,"PROGRAMACION ORIENTADA A ODJETOS");
	 getchar();
	 setpalette(8,CYAN);
	 setcolor(8);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 outtextxy(228,380,"ROBERTO");
	 getchar();
	 setpalette(9,LIGHTRED);
	 setcolor(9);
	 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	 outtextxy(280,420,"1998");
	 getchar();

	 for(i=1;i<=180;i=i+9)
	 {
  cleardevice();
	 setfillstyle(1,8);
	 fillellipse(150,450,1000,550);
	 setpalette(2,8);


		setfillstyle(1,14);

		fillellipse(9+i,30,30,20);
		delay(100);
		setcolor(6);
		ciudad();
		outtextxy(80+i,345," C + +");
		setfillstyle(1,WHITE);
		rectangle(1+i,380,200+i,350);
		rectangle(203+i,280,250+i,350);
		rectangle(203+i,380,250+i,380);
		fillellipse(251+i,350,50,30);

		circle(40+i,399,15);circle(80+i,399,15);circle(170+i,399,15); circle(220+i,399,15);

		setcolor(4);
	circle(50+i,100, 50);
	setcolor(15);
	line(5+i,120,30+i,200);
	setcolor(15);
	line(95+i,120,70+i,200);
	setcolor(15);
	line(50+i,140,50+i,210);
	setcolor(15);
  ellipse(50+i,200,0,360,20,10);
	setcolor(15);
  ellipse(50+i,220,180,360,20,10);
	setcolor(15);
	line(29+i,200,29+i,220);
	setcolor(15);
	line(71+i,200,71+i,220);
  setcolor(4);
  arc(60+i,100,90,270,50);
  setcolor(4);
  arc(90+i,100,128,232,65);
  setcolor(4);
  arc(10+i,100,128-180,232-180,65);
  setcolor(4);
  arc(39+i,100,90-180,270-180,50);
  setcolor(4);
	line(50+i,50,50+i,150);

		sound(90+i);delay(80);
		sound(2+i);delay(80);


		 }
	  nosound();

	 getchar();

}


 void ciudad()
 {
	 int left, top, right, bottom,i;



	 setfillstyle(1,7);//7
	 fillellipse(9,300,30,20);
	 setfillstyle(3,6);//
	 rectangle(5,302,10,415);
	 setfillstyle(1,11);//10
	 fillellipse(10,550,450,150);
	 setfillstyle(1,10);
	 fillellipse(380,550,450,100);
	 setfillstyle(1,BLUE);
	 fillellipse(9,90,30,20);
	  setfillstyle(1,BLUE);
	 fillellipse(55,90,30,20);
	  setfillstyle(1,BLUE);
	 fillellipse(95,90,30,20);
	  setfillstyle(1,BLUE);
	 fillellipse(250,90,30,20);
	 fillellipse(290,90,30,20);
	 fillellipse(335,90,30,20);
	 setfillstyle(2,7);
	 fillellipse(550,450,80,250);

	 setfillstyle(1,BLUE);
	 fillellipse(450,90,30,20);
	 fillellipse(490,90,30,20);
	 fillellipse(535,90,30,20);


	  }
