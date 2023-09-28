#include "conio.h"
#include "iostream.h"
#include "graphics.h"

#define rellena_objeto(x,y,color,borde) {setfillstyle(1,color);floodfill(x,y,borde);}
void iniciar_modo_grafico();
void guante(int x,int y);

void guante(int x,int y)
{ int i=8,c=7;
  setcolor(BLUE);
  line(50,50,70,100);
  line(50,100,70,50);
 // arc(60,60,50,130,14);
  ellipse(60,50,0,360,10,5);
  ellipse(60,100,0,360,10,5);
  floodfill(65,55,1);
  setcolor(i);
  arc(x,y,0,180,1);
  arc(x-4,y+6,0,180,1);
  arc(x-8,y+7,0,180,1);
  arc(x-11,y+11,0,180,1);
  arc(x+2,y+12,0,90,4);
  line(x+1,y+10,x+1,y+1);
  line(x-2,y+10,x-2,y+1);
  line(x-6,y+7,x-6,y+10);
  line(x-9,y+8,x-9,y+10);
  line(x-13,y+12,x-13,y+15);
  line(x+6,y+15,x+6,y+12);
  line(x+6,y+15,x+2,y+21);
  line(x+2,y+24,x+2,y+21);
  line(x-13,y+15,x-9,y+21);
  line(x-9,y+21,x-9,y+24);
  line(x-9,y+24,x+2,y+24);
  rellena_objeto(x,y,c,i);
  //lo_rellena (x,y,color,borde) {setfillstyle(1,color);floodfill(x,y,borde);}

}

void iniciar_modo_grafico()
{
  int unidad =DETECT,modo;
  initgraph (&unidad,&modo,"c:\\borlandc\\bgi");
  if (graphresult() != 0)
  {
   cout << "Error al tratar de pasar al modo grafico\n";
   getch();
  }
}

void main(void)
{
iniciar_modo_grafico();
guante(200,200);
getch();
closegraph();
}