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
settextstyle(3,0,4);
setbkcolor(2);
setcolor(1);
outtextxy(83,76,"He aqu¡ a.... *.*. Timoteo .*.*");

setcolor(4);
rectangle(10,10,getmaxx()-10,getmaxy()-10);
rectangle(20,20,getmaxx()-20,getmaxy()-20);
setfillstyle(6,11);
floodfill(21,11,1);
setcolor(1);
arc(307,-30,253,296,200);
arc(307,-40,261,290,200);
arc(305,-53,261,290,200);
arc(303,-70,261,290,200);
line(272,128,276,158);
line(276,158,250,161);
line(372,118,376,148);
line(376,148,394,150);
arc(343,315,82,111,200);
ellipse(310,215,115,255,100,55);
line(321,170,293,200);
arc(312,207,155,275,20);
arc(387,201,270,360,20);
arc(270,219,5,30,120);
arc(255,223,5,30,120);
arc(240,227,5,30,120);
line(337,168,335,215);
arc(435,219,155,180,120);
line(383,155,407,200);
line(386,221,275,231);
line(386,221,376,245);
line(376,245,410,345);
arc(300,678,72,108,350);
line(275,231,305,251);
line(305,251,270,258);
line(270,258,295,275);
line(295,275,190,345);
line(260,263,280,275);
line(280,275,260,281);
line(260,281,268,285);
line(268,285,263,295);
arc(320,260,280,304,90);
arc(320,260,231,240,90);
line(275,338,265,350);
line(265,350,255,370);
line(336,348,325,365);
line(325,365,335,391);
arc(320,283,233,278,110);
ellipse(255,404,90,266,55,33);
arc(290,560,55,120,130);
arc(305,418,329,45,40);
arc(365,346,180,275,20);
arc(332,346,272,330,40);
ellipse(345,397,340,67,55,33);
arc(402,510,45,125,100);
arc(310,295,335,55,20);
ellipse(310,300,327,55,67,40);
arc(390,225,225,265,100);
arc(397,135,242,265,190);
arc(490,555,55,103,130);
arc(560,533,55,92,90);
arc(210,503,94,150,90);
arc(370,431,125,180,215);
arc(370,431,356,83,215);
getch();
}