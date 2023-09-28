#include<ctype.h>
#include <conio.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>



void main()
{
char a;int i,j,tecla=0;
int tarjeta=DETECT,modo=0,error;
initgraph(&tarjeta,&modo,"c:\\borlandc\\bgi");
error=graphresult();
if(error!=grOk)
  {
  printf("Fracaso...al abrir modo gr fico.");
  getch();
  exit(0);
 }
setcolor(1);
line(50,50,70,50);
line(50,65,70,65);

line(70,50,70,65);
line(50,50,50,65);
floodfill(60,60,1);
//rectangle(50,50,200,300);
line(50,50,60,60);
line(70,50,60,60);


getch();
}