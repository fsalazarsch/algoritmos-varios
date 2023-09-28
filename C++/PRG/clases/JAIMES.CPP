#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void circulo(void);
void cir(void);
void eli(void);
void carro(void);
void arbol(void);
void pre(void);
int unidad=0,modo;
int x,y,salir,s;

void pre(void)
{
   initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
	 {
	  printf("Error al tratar de pasar al modo grafico \n");
	  printf("presione una tecla para continuar :");
	  getch();
	  exit(1);
	 }
	 else
	 {
	  settextstyle(TRIPLEX_FONT,0,5);
	  outtextxy(20,50,"MODELOS DE PROGRAMACION");
	  outtextxy(150,100,"PROGRAMADOR");
	  outtextxy(10,200,"JULIAN C. JAIMES MALDONADO");
	  outtextxy(200,300,"CURSO S3E");
	  delay(1000);

	  }
	closegraph();
}
void arbol(void)
{
  initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
	 {
	  printf("Error al tratar de pasar al modo grafico \n");
	  printf("presione una tecla para continuar :");
	  getch();
	  exit(1);
	 }
	 else
	 {
	
	 }
       closegraph();
}
void  carro(void)
{
initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
	 {
	  printf("Error al tratar de pasar al modo grafico \n");
	  printf("presione una tecla para continuar :");
	  getch();
	  exit(1);
	 }
	 else
	 {
	  setpalette (8,YELLOW);//inicializa lapaleta de colores
	  setcolor(8);//color amarillo
	  setcolor(1);
	  line(1,340,650,340);
	  setcolor(YELLOW);
	  line(25,50,25,300);
	  setcolor(BLUE);
	  arc(130,200,0,180,50);
	  circle(180,300,40);
	  circle(530,300,40);
	  setcolor(GREEN);
	  line(30,200,600,200);
	  line(25,300,140,300);
	  line(30,200,30,300);
	  line(220,300,490,300);
	  line(220,200,340,100);//barras
	  line(230,200,340,110);//b
	  line(340,100,340,300);
	  line(345,100,345,300);
	  line(340,100,410,100);
	  line(340,105,405,105);
	  line(405,105,440,195);
	  line(345,195,440,195);
	  line(410,100,450,200);
	  line(450,200,450,300);
	  rectangle(350,240,360,245);
	  line(600,200,600,300);
	  line(570,300,620,300);
	  rectangle(610,250,620,300);
	  

	  delay(1000);
	  closegraph();
	 }
  }	 
void eli(void)
{
int unidad=0,modo;
int a,b,c;
initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
	{
	  printf("Error al tratar de pasar al modo grafico \n");
	  printf("presione una tecla para continuar :");
	  getch();
	  exit(1);
	 }
	 else
	 {
	  for(int z=1;z<=5000;z++)
	  {
		a=random(640);
		b=random(480);
		c=random(16);
		putpixel(a,b,c);
	  }
	  delay(1000);
	  closegraph();
	  }
}
void circulo(void)
{
int unidad=0,modo;
int r1,x,y,salir,s,x1,y1;
int r=10;

initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
	{
	  printf("Error al tratar de pasar al modo grafico \n");
	  printf("presione una tecla para continuar :");
	  getch();
	  exit(1);
	 }
	 else
	 {
	  clrscr();
	  s=1;
	  r1=2;x1=300;y1=200;
	  while(s<40)//for(s=1;s<40;s++)
		{
		x=320;
		y=240;
		r=0;
		cleardevice();
		setcolor(GREEN);
		circle(x1,y1,r1);
		putimage(x1,y1,circle,20);
		x1=x1+2;
		y1=y1+2;
		setcolor(YELLOW);
		circle(320,240,60);
		setbkcolor(RED);
		setcolor(BLUE);
		for(salir=1;salir<12;salir++)
		{
		 circle(x,y,r);
		 r=r+salir;
		 delay(10);
		 }
		if(x1>370)
		 {
		circle(x1,y1,r1);
		 cleardevice();
		 s=50;
		}
	}
	  printf("Fuera del perimetro");
	  delay(1000);
	  closegraph();
	 }
}
 void cir(void)
 {
  int unidad=0,modo;
  int r1,x1,y1,v;
   clrscr();

initgraph(&unidad,&modo,"C:\\tcmas\\bgi");
  if(graphresult()!=0)
   {
     printf("Error al tratar de pasar al modo grafico \n");
     printf("presione una tecla para continuar :");
     getch();
     exit(1);
    }
	 else
    {
     x1=150;y1=200;
     for(v=1;v<2;v++)
     {
		setcolor(YELLOW);
      circle(320,220,60);
      setcolor(RED);
       do
	 {
	 setcolor(RED);
	 circle(320,220,60);
	 setcolor(YELLOW);
	 circle(x1,y1,30);
	 putimage(x1,y1,circle,20);
	 x1=x1+5;
	 y1=y1-5;
	 delay(40);
	 cleardevice();
	 }while(x1<=310);
	do
	{
	 setcolor(RED);
	 circle(320,220,60);
	 setcolor(YELLOW);
	 circle(x1,y1,30);
	 putimage(x1,y1,circle,20);
	 x1=x1+8;
	 y1=y1+5;
	 delay(40);
	 cleardevice();
	 } while(y1<200);
	 do
	 {
	  setcolor(RED);
	  circle(320,220,60);
	  setcolor(YELLOW);
	  circle(x1,y1,30);
	  putimage(x1,y1,circle,20);
	  x1=x1-8;
	  y1=y1+5;
	  delay(40);
	  cleardevice();
	  } while(x1>300);
	 do{
	  setcolor(RED);
	  circle(320,220,60);
	 setcolor(YELLOW);
	 circle(x1,y1,30);
	 putimage(x1,y1,circle,20);
	 x1=x1-8;
	 y1=y1-5;
	 delay(40);
	 cleardevice();
	 } while(x1>=150);
	 circle(x1,y1,30);
	 setcolor(RED);
	 circle(320,220,60);
    }
    closegraph();
   delay(1000);
  }
 }

int main(void)
{

 pre();
 eli();
 carro();
 circulo();
 cir();
 return 0;
}
