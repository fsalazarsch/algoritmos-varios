#include<ctype.h>
#include <conio.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
sonar(),jugando();ayuda1();sonoro(int a,int b);
ayuda(),linea(),circulo(),relleno(),rectangulo(),barras(),timoteo();
menu_ppal(),grafica(),logo(),editor();
int puntos=0,x,y,j,tec,estilo,color;
long int i;
main()
{
grafica();
//timoteo();
logo();
editor();
cleardevice();
closegraph();
return 0;
}

timoteo()
{
char a;int i,j,tecla=0;
cleardevice();
setbkcolor(0);
setcolor(11);
settextstyle(3,0,4);
outtextxy(83,76,"He aqu¡ a.... *.*. Timoteo .*.*");

/*for(i=1;i<=10000;i++)
{
do
x=random(getmaxx());
while(x<=75 || x>=getmaxx()-100);
do
y=random(getmaxy());
while(y<=127 || y>=getmaxy()-50);
putpixel(x,y,random(i));
}*/
setcolor(1);
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

a='1';
while(a!='0')
{
 setfillstyle(1,4);
 bar(23,25,getmaxx()-25,75);
 setcolor(15);
 settextstyle(2,0,5);
 rectangle(26,27,getmaxx()-27,72);
 outtextxy(30,30,"A Sombrero  B Cinta Sombrero  C Cabello   D Cara   E Chamarra   F Luna   ");
 outtextxy(30,50,"G Zapatos   H Nubes   I Pantal¢n   J Fondo   0 terminar");
 a=getch();
 a=toupper(a);
 if(a=='0')
 {
  setfillstyle(1,0);
  bar(0,0,getmaxx(),getmaxy());
  menu_ppal();
  return 0;
 }
 else
 {
  bar(23,15,getmaxx()-25,75);
  estilo=1;
  for(i=1;i<=56;i=i+5)
 {
  setfillstyle(estilo++,15);
  bar(i*10,14,i*10+30,40);
 }
 estilo=1;
 setfillstyle(estilo,14);
 bar(10,14,40,40);
 i=1;
 tecla=0;
 while(tecla!=13)
 {
  tecla=getch();
  if(tecla==0)
 {
 setfillstyle(estilo,15);
 bar(i*10,14,i*10+30,40);
 tecla=getch();
 if(tecla==77)
  if(i==56)
  {
   i=1;
   estilo=1;
  }
  else
  {
   i=i+5;
   estilo++;
  }
   else
    if(tecla==75)
     if(i==1)
     {
      i=56;
      estilo=12;
     }
     else
     {
      i=i-5;
      estilo--;
     }
  setfillstyle(estilo,14);
  bar(i*10,14,i*10+30,40);
  }
 }
 setfillstyle(1,0);
 //bar(23,25,getmaxx()-25,75);
 bar(23,15,getmaxx()-25,75);
 //bar(0,0,getmaxx(),55);
 color=0;
 for(i=1;i<=46;i=i+3)
 {
  setfillstyle(1,color++);
  bar(i*10,14,i*10+25,40);
 }
 setcolor(15);
 rectangle(10,14,10+25,40);
 i=1;
 color=0;
 tecla=0;
 while(tecla!=13)
 {
  tecla=getch();
  if(tecla==0)
  {
   setcolor(color);
   rectangle(i*10,14,i*10+25,40);
   tecla=getch();
   if(tecla==77)
    if(i==46)
    {
     i=1;
     color=1;
    }
    else
    {
     i=i+3;
     color++;
    }
   else
    if(tecla==75)
     if(i==1)
     {
      i=46;
      color=15;
     }
     else
     {
      i=i-3;
      color--;
     }
   setcolor(15);
   rectangle(i*10,14,i*10+25,40);
  }
 }
setfillstyle(estilo,color);
if(a=='A')
 {
  //sombrero
  floodfill(325,120,1);
  floodfill(325,130,1);
  floodfill(325,165,1);
 }
 else
 if(a=='B')
 {
  //cinta sombrero setfillstyle(1,7);
  floodfill(325,150,1);
 }
 else
 if(a=='C')
 {
  //cabello setfillstyle(1,0);
  floodfill(325,175,1);
 }
 else
 if(a=='D')
 {
  //cara setfillstyle(1,14);
  floodfill(250,175,1);
 }
 else
 if(a=='E')
 {
  //chamarra setfillstyle(1,2);
  floodfill(325,250,1);
  floodfill(280,270,1);
 }
 else
 if(a=='F')
 {
  //luna setfillstyle(1,15);
  floodfill(550,350,1);
  floodfill(190,410,1);
 }
 else
 if(a=='G')
 {
  //zapatos setfillstyle(1,8);
  floodfill(250,400,1);
  floodfill(340,395,1);
 }
 else
 if(a=='H')
 {
  //nubes setfillstyle(1,9);
  floodfill(250,450,1);
 }
 else
 if(a=='I')
 {
  //el pantal¢n setfillstyle(1,4);
  floodfill(358,339,1);
  floodfill(340,350,1);
 }
 else
 if(a=='J')
 {
  //fondo setfillstyle(1,9);
  floodfill(30,50,1);
 }
 }
 }

/*setcolor(11);
settextstyle(3,0,4);
outtextxy(83,36,"He aqu¡ a.... *.*. Timoteo .*.*");*/
getch();
//exit(1);
return(0);
}

grafica()
{
int tarjeta=DETECT,modo=0,error;
initgraph(&tarjeta,&modo,"c:\\borlandc\\bgi");
error=graphresult();
if(error!=grOk)
  {
  printf("Fracaso...al abrir modo gr fico.");
  getch();
  exit(0);
  }
 return 0;
}

editor()
{
/*setcolor(0);*/
setfillstyle(1,7);
bar(0,0,getmaxx(),getmaxy());
setlinestyle(1,5,10);
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(5,5,getmaxx()-5,getmaxy()-5);
setfillstyle(1,1);
bar(6,getmaxy()-50,getmaxx()-6,getmaxy()-6);
for(i=1;i<=10000;i++)
{
do
x=random(getmaxx());
while(x<=7 || x>=getmaxx()-7);
do
y=random(getmaxy()-50);
while(y<=7 || y>=getmaxy()-50);
putpixel(x,y,i);
}
settextstyle(3,0,4);
setcolor(5);
outtextxy(80,36,"Este programa te ayudara a:");
outtextxy(80,106,".*.*.*   Pintar   *.*.*.");


for(i=0;i<=60;i++)
{
setcolor(i);
rectangle((int)getmaxx()/2-i*4,getmaxy()-200-i*2,
	   (int)getmaxx()/2+i*4,getmaxy()-200+i*2);
	   }
sonoro(4,7);
setfillstyle(1,1);
bar(80,160,560,400);
setcolor(15);
setlinestyle(3,3,3);
rectangle(85,165,555,395);
setlinestyle(0,3,2);
for(i=170;i<=230;i++)
{
setcolor(1);
line(150,i-1,490,i-1);
setcolor(6);
line(150,i,490,i);
}
sonoro(5,9);
for(i=270;i<=325;i++)
{
setcolor(1);
line(350,650-i+1,490,650-i+1);
line(150,i-1,350,i-1);
setcolor(6);
line(350,650-i,490,650-i);
line(150,i,350,i);
}
sonoro(6,9);
for(i=300;i<=490;i++)
{
setcolor(1);
line(i-1,231,i-1,324);
line(640-i+1,231,640-i+1,324);
setcolor(6);
line(i,231,i,324);
line(640-i,231,640-i,324);
}
sonoro(8,12);
for(i=180;i<=250;i++)
{
setfillstyle(1,1);
bar(100,i-1,120,i-1+60);
setfillstyle(1,6);
bar(100,i,120,i+60);
}
sonoro(3,12);
setfillstyle(1,1);
bar(100,250,120,310);
setfillstyle(1,1);
bar(140,250,160,310);
setcolor(15);
moveto(150,250);
lineto(160,255);
lineto(140,260);
lineto(160,265);
lineto(140,270);
lineto(160,275);
lineto(140,280);
lineto(160,285);
lineto(140,290);
lineto(160,295);
lineto(140,300);
lineto(160,305);
lineto(150,310);
sonoro(20,25);
for(i=180;i<=260;i++)
{
setfillstyle(1,1);
bar(i-1,180,i+100-1,200);
setfillstyle(1,6);
bar(i,180,i+100,200);
}
//sonoro(10,18);
setfillstyle(1,1);
bar(260,220,365,230);
bar(260,180,370,200);
setcolor(15);
for(i=1;i<=100;i=i+5)
{
circle(i+260,230,10);
}
//sonoro(5,15);
bar(320,305,360,345);
circle(340,325,20);
setcolor(1);
line(490,270,490,280);
setcolor(15);
line(480,270,500,270);
line(485,280,495,280);
for(i=270;i>=230;i--)
{
putpixel(490,i,14);
 }
 //sonoro(5,11);
for(i=490;i>=360;i--)
{
putpixel(i,230,14);
delay(30);
 }
 //sonoro(1,4);
 for(j=1;j<=3;j++)
 {
for(i=1;i<=100;i=i+5)
{
setcolor(6);
circle(360-i+1,230,10);
setcolor(14);
circle(360-i,230,10);
}
//sonoro(2,6);
setcolor(0);
for(i=1;i<=100;i=i+5)
{
circle(i+260,230,10);
}
//sonoro(8,12);
for(i=1;i<=100;i=i+5)
{
setcolor(14);
circle(360-i+1,230,10);
setcolor(15);
circle(360-i,230,10);
delay(20);
}
//sonoro(3,4);
}
for(i=260;i>=150;i--)
{
putpixel(i,230,14);
delay(10);
}
//sonoro(7,9);
for(i=230;i<=250;i++)
{
putpixel(150,i,14);
delay(10);
 }
 //sonoro(21,26);
 for(i=1;i<=10;i++)
{
setcolor(1);
moveto(150,250);
lineto(160,255);
lineto(140,260);
lineto(160,265);
lineto(140,270);
lineto(160,275);
lineto(140,280);
lineto(160,285);
lineto(140,290);
lineto(160,295);
lineto(140,300);
lineto(160,305);
lineto(150,310);
delay(100);
setcolor(14);
moveto(150,250);
lineto(160,255);
lineto(140,260);
lineto(160,265);
lineto(140,270);
lineto(160,275);
lineto(140,280);
lineto(160,285);
lineto(140,290);
lineto(160,295);
lineto(140,300);
lineto(160,305);
lineto(150,310);
delay(100);
}
//sonoro(23,31);
for(i=310;i<=325;i++)
{
putpixel(150,i,14);
delay(10);
 }
// sonoro(6,12);
for(i=150;i<=320;i++)
{
putpixel(i,325,14);
delay(10);

 }
 for(i=1;i<=3;i++)
 for(j=1;j<=5;j++)
 {

 setcolor(1);
 circle(340,325,j*3);
 delay(10);
 setcolor(14);
 circle(340,325,j*3);
 delay(10);
 //sonoro(13,15);
 }
 //sonoro(10,14);
 for(i=360;i<=490;i++)
{
putpixel(i,325,14);
delay(10);

 }
 for(i=325;i>=280;i--)
{
putpixel(490,i,14);
delay(10);

 }
 setcolor(15);
 settextstyle(0,0,2);
outtextxy(50,445,"UN PROGRAMA PARA APRENDER JUGANDO!");
setcolor(4);
outtextxy(52,443,"UN PROGRAMA PARA APRENDER JUGANDO!");
delay(1000);
menu_ppal();
return 0;
}


hace_menu()
{
  int i;
  setfillstyle(1,15);
  bar(0,getmaxy()-52,getmaxx(),getmaxy()-6);
  setfillstyle(1,1);
  bar(6,getmaxy()-52,getmaxx()-12,getmaxy()-6);
  setcolor(0);
  line(0,getmaxy()-63,getmaxx(),getmaxy()-63);
  setfillstyle(1,15);
  setcolor(0);
  for(i=1;i<=61;i=i+7)
  {
    bar(i*10,getmaxy()-48,i*10+50,getmaxy()-10);
    rectangle(i*10+2,getmaxy()-46,i*10+50-2,getmaxy()-12);
  }
  setfillstyle(1,6);
bar(10,getmaxy()-48,10+50,getmaxy()-10);
rectangle(10+2,getmaxy()-46,10+50-2,getmaxy()-12);
setcolor(0);
settextstyle(1,0,4);
outtextxy(30,getmaxy()-48,"?");
settextstyle(0,0,1);outtextxy(15,getmaxy()-60,"AYUDA");
setfillstyle(1,14);
bar3d(90,getmaxy()-33,113,getmaxy()-18,6,1);
line(157,getmaxy()-17,190,getmaxy()-43);
circle(246,getmaxy()-29,13);
setfillstyle(7,5);bar(297,getmaxy()-36,334,getmaxy()-20);
rectangle(370,getmaxy()-40,400,getmaxy()-20);
setfillstyle(1,11);
bar(440,getmaxy()-40,470,getmaxy()-35);
setfillstyle(1,2);
bar(440,getmaxy()-33,470,getmaxy()-28);
setfillstyle(1,6);
bar(440,getmaxy()-21,470,getmaxy()-15);
setcolor(0);
moveto(505,getmaxy()-35);
lineto(508,getmaxy()-30);
lineto(511,getmaxy()-35);
lineto(514,getmaxy()-30);
lineto(517,getmaxy()-35);
lineto(520,getmaxy()-30);
lineto(523,getmaxy()-35);
lineto(526,getmaxy()-35);
lineto(529,getmaxy()-35);
circle(539,getmaxy()-33,3);
bar(515,getmaxy()-25,539,getmaxy()-20);
rectangle(585,getmaxy()-40,600,getmaxy()-20);
setfillstyle(1,11);
floodfill(590,getmaxy()-25,0);
moveto(600,getmaxy()-40);
lineto(615,getmaxy()-45);
lineto(615,getmaxy()-25);
lineto(600,getmaxy()-20);
setfillstyle(1,5);
floodfill(603,getmaxy()-39,0);
return 0;
}


menu_ppal()
{
setfillstyle(1,7);
bar(70,150,600,getmaxy()-70);
for(i=1;i<=10000;i++)
{
do
x=random(getmaxx());
while(x<=70 || x>=getmaxx()-60);
do
y=random(getmaxy()-50);
while(y<=150 || y>=getmaxy()-70);
putpixel(x,y,i);
}
settextstyle(0,0,2);
setfillstyle(1,14);
for(i=1;i<=1000;i++)
{
do
x=random(getmaxx()-100);
while(x<=100 || x>=getmaxx()-100);
do
y=random(getmaxy()-200);
while(y<200 || y>=getmaxy()-150);
bar(x,y,x+10,y+10);
}

/*do
x=random(getmaxx()-200);
while(x<=110 || x>=getmaxx()-110);
do
y=random(getmaxy()-200);
while(y<210 || y>=getmaxy()-110);
bar(x,y,x+5,y+5);
}
setcolor(0);
outtextxy(220,219,"  UNIVERSIDAD:");
outtextxy(220,249,"ANTONIO  NARINO");
setcolor(12);
outtextxy(222,221,"  UNIVERSIDAD:");
outtextxy(222,251,"ANTONIO  NARINO");
delay(1000);
for(i=1;i<=10000;i++)
{
do
x=random(getmaxx()-100);
while(x<=110 || x>=getmaxx()-10);
do
y=random(getmaxy()-200);
while(y<210 || y>=getmaxy()-110);
bar(x,y,x+5,y+5);
}
setcolor(0);
outtextxy(180,219,"SANTAFE  DE  BOGOTA");
outtextxy(180,249," MAYO 22  DE 1997");
setcolor(3);
outtextxy(182,221,"SANTAFE  DE  BOGOTA");
outtextxy(182,251," MAYO 22  DE 1997");
delay(1500);*/
hace_menu();
i=1;
while(tec!=2)
{
tec=getch();
if(tec==0)
{
  setcolor(0);
  setfillstyle(1,15);
  bar(i*10,getmaxy()-48,i*10+50,getmaxy()-10);
  rectangle(i*10+2,getmaxy()-46,i*10+50-2,getmaxy()-12);
switch(i)
{
case 1:{settextstyle(1,0,4);outtextxy(25,getmaxy()-48,"?");
	settextstyle(0,0,1);outtextxy(15,getmaxy()-60,"AYUDA");break;}
case 8:{setfillstyle(1,14);bar3d(90,getmaxy()-33,113,getmaxy()-18,6,1);
	break;}
case 15:{line(157,getmaxy()-17,190,getmaxy()-43);break;}
case 22:{circle(246,getmaxy()-29,13);break;}
case 29:{setfillstyle(7,5);bar(297,getmaxy()-36,334,getmaxy()-20);break;}
case 50:{setcolor(0);
	 moveto(505,getmaxy()-35);
	 lineto(508,getmaxy()-30);
	 lineto(511,getmaxy()-35);
	 lineto(514,getmaxy()-30);
	 lineto(517,getmaxy()-35);
	 lineto(520,getmaxy()-30);
	 lineto(523,getmaxy()-35);
	 lineto(526,getmaxy()-35);
	 lineto(529,getmaxy()-35);
	 circle(539,getmaxy()-33,3);
	 setfillstyle(1,13);
	 bar(515,getmaxy()-25,539,getmaxy()-20);
	break;}
case 43:{setfillstyle(1,11);
	 bar(440,getmaxy()-40,470,getmaxy()-35);
	 setfillstyle(1,2);
	 bar(440,getmaxy()-33,470,getmaxy()-28);
	 setfillstyle(1,6);
	 bar(440,getmaxy()-21,470,getmaxy()-15);
	 break;
	 }
case 36:{rectangle(370,getmaxy()-40,400,getmaxy()-20);break;}
case 57:{rectangle(585,getmaxy()-40,600,getmaxy()-20);
	 setfillstyle(1,11);
	 floodfill(590,getmaxy()-25,0);
	 moveto(600,getmaxy()-40);
	 lineto(615,getmaxy()-45);
	 lineto(615,getmaxy()-25);
	 lineto(600,getmaxy()-20);
	 setfillstyle(1,5);
	 floodfill(603,getmaxy()-39,0);
	 break;
	  }
}
tec=getch();
if(tec==77)
  if(i==57) i=1;
  else i=i+7;
else if(tec==75)
     if(i==1) i=57;
     else i=i-7;
      setfillstyle(1,6);
      bar(i*10,getmaxy()-48,i*10+50,getmaxy()-10);
      rectangle(i*10+2,getmaxy()-46,i*10+50-2,getmaxy()-12);
      setfillstyle(1,15);
      settextstyle(0,0,1);
      bar(0,getmaxy()-62,getmaxx(),getmaxy()-52);
      switch(i)
{
case 1:{settextstyle(1,0,4);outtextxy(25,getmaxy()-48,"?");
	settextstyle(0,0,1);outtextxy(15,getmaxy()-60,"AYUDA");break;}
case 8:{outtextxy(74,getmaxy()-60,"BORRADOR");setfillstyle(1,14);
	bar3d(90,getmaxy()-33,113,getmaxy()-18,6,1);break;}
case 15:{outtextxy(154,getmaxy()-60,"LINEAS");
	line(157,getmaxy()-17,190,getmaxy()-43);break;}
case 22:{outtextxy(215,getmaxy()-60,"CIRCULOS");circle(246,getmaxy()-29,13);
	 break;}
case 29:{outtextxy(288,getmaxy()-60,"RELLENO");
	setfillstyle(7,5);bar(297,getmaxy()-36,334,getmaxy()-20);break;}
case 36:{outtextxy(343,getmaxy()-60,"RECTANGULOS");
	 rectangle(370,getmaxy()-40,400,getmaxy()-20);break;}
case 43:{outtextxy(432,getmaxy()-60,"BARRAS");
	 setfillstyle(1,11);
	 bar(440,getmaxy()-40,470,getmaxy()-35);
	 setfillstyle(1,2);
	 bar(440,getmaxy()-33,470,getmaxy()-28);
	 setfillstyle(1,14);
	 bar(440,getmaxy()-21,470,getmaxy()-15);
	 break;
	 }
case 50:{outtextxy(500,getmaxy()-60,"DIBUJOS");
	 setcolor(0);
	 moveto(505,getmaxy()-35);
	 lineto(508,getmaxy()-30);
	 lineto(511,getmaxy()-35);
	 lineto(514,getmaxy()-30);
	 lineto(517,getmaxy()-35);
	 lineto(520,getmaxy()-30);
	 lineto(523,getmaxy()-35);
	 lineto(526,getmaxy()-35);
	 lineto(529,getmaxy()-35);
	 circle(539,getmaxy()-33,3);
	 setfillstyle(1,13);
	 bar(515,getmaxy()-25,539,getmaxy()-20);
	break;}
case 57:{outtextxy(565,getmaxy()-60,"TERMINAR");
	rectangle(585,getmaxy()-40,600,getmaxy()-20);
	 setfillstyle(1,11);
	 floodfill(590,getmaxy()-25,0);
	 moveto(600,getmaxy()-40);
	 lineto(615,getmaxy()-45);
	 lineto(615,getmaxy()-25);
	 lineto(600,getmaxy()-20);
	 setfillstyle(1,5);
	 floodfill(603,getmaxy()-39,0);
	 break;
	  }


	  }
 }
 if(tec==13)
 switch(i)
 {
 case 1:ayuda();break;
 case 8:break;
 case 15:linea();break;
 case 22:circulo();break;
 case 29:relleno();break;
 case 36:rectangulo();break;
 case 43:barras();break;
 case 50:timoteo();break;
 case 57:tec=2;
 break;
 }

	   }
return 0;
}

sonoro(int a,int b)
{
int f;
for(f=a;f<=b;f++)
{
sound(f*301+a*b);
delay(50);
nosound();
}
return 0;
}
ayuda()
{
return 0;
}

linea()
{
/*int i=0,x=getmaxx()/2,y=getmaxy()/2,j,tecla=0,x1=0,y1=0;
line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
while(tecla!=27)
{
tecla=getch();
if(tecla==0)
  {
   setcolor(15);
   line(x-5,y,x+5,y);
   line(x,y-5,x,y+5);
   line(x1,y1,x,y);
   tecla=getch();
   if(tecla==77)
    if(x>=getmaxx()-5) putchar(7);
    else x=x+5;
   else if(tecla==75)
	    if(x<5) putchar(7);
	    else x=x-5;
	else if(tecla==80)
		  if(y>=getmaxy()-60) putchar(7);
		  else y=y+5;
		  else if(tecla==72)
			   if(y<5) putchar(7);
			   else y=y-5;
	setcolor(0);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
	if(i==1)
	line(x1,y1,x,y);
	}
   else if(tecla==13)
	    {
	    x1=x;
	    y1=y;
	    line(x1,y1,x,y);
	    i=1;
	    }
}*/
return 0;
}

relleno()
{
int j,i,tecla=0;
int x=getmaxx()/2,y=getmaxy()/2;
setfillstyle(1,0);
bar(6,getmaxy()-52,getmaxx()-12,getmaxy()-6);
estilo=1;
for(i=1;i<=56;i=i+5)
{
setfillstyle(estilo++,15);
bar(i*10,getmaxy()-48,i*10+30,getmaxy()-10);
}
estilo=1;
setfillstyle(estilo,14);
bar(10,getmaxy()-48,10+30,getmaxy()-10);
i=1;
while(tecla!=13)
{
tecla=getch();
if(tecla==0)
{
setfillstyle(estilo,15);
bar(i*10,getmaxy()-48,i*10+30,getmaxy()-10);
tecla=getch();
if(tecla==77)
  if(i==56) {i=1;estilo=1;}
  else {i=i+5;estilo++;}
else if(tecla==75)
     if(i==1) {i=56;estilo=12;}
     else {i=i-5;estilo--;}
      setfillstyle(estilo,14);
      bar(i*10,getmaxy()-48,i*10+30,getmaxy()-10);
}
}
setfillstyle(1,0);
bar(0,getmaxy()-52,getmaxx(),getmaxy()-6);
color=0;
for(i=1;i<=46;i=i+3)
{
setfillstyle(1,color++);
bar(i*10,getmaxy()-48,i*10+25,getmaxy()-10);
}
setcolor(15);
rectangle(10,getmaxy()-48,10+25,getmaxy()-10);
i=1;
color=0;
tecla=0;
while(tecla!=13)
{
tecla=getch();
if(tecla==0)
{
setcolor(color);
rectangle(i*10,getmaxy()-48,i*10+25,getmaxy()-10);
tecla=getch();
if(tecla==77)
  if(i==46) {i=1;color=1;}
  else {i=i+3;color++;}
else if(tecla==75)
     if(i==1) {i=46;color=15;}
     else {i=i-3;color--;}
      setcolor(15);
      rectangle(i*10,getmaxy()-48,i*10+25,getmaxy()-10);
}
}
line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
tecla=0;
while(tecla!=13)
{
tecla=getch();
if(tecla==0)
  {
   setcolor(15);
   line(x-5,y,x+5,y);
   line(x,y-5,x,y+5);
   tecla=getch();
   if(tecla==77)
    if(x>=getmaxx()-5) putchar(7);
    else x=x+5;
   else if(tecla==75)
	    if(x<5) putchar(7);
	    else x=x-5;
	else if(tecla==80)
		  if(y>=getmaxy()-60) putchar(7);
		  else y=y+5;
		  else if(tecla==72)
			   if(y<5) putchar(7);
			   else y=y-5;
	setcolor(0);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
	}
   else if(tecla==13)
   {
	   setfillstyle(estilo,color);
	   floodfill(x,y,0);
   }
}
hace_menu();
return 0;
}

barras()
{
/*int i=0,j,x=getmaxx()/2,y=getmaxy()/2,tecla=0,x1=0,y1=0;

line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
while(tecla!=27)
{
tecla=getch();
if(tecla==0)
  {
   setfillstyle(1,15);
   setcolor(15);
   line(x-5,y,x+5,y);
   line(x,y-5,x,y+5);
   bar(x1,y1,x,y);
   tecla=getch();
   if(tecla==77)
    if(x>=getmaxx()-5) putchar(7);
    else x=x+5;
   else if(tecla==75)
	    if(x<5) putchar(7);
	    else x=x-5;
	else if(tecla==80)
		  if(y>=getmaxy()-60) putchar(7);
		  else y=y+5;
		  else if(tecla==72)
			   if(y<5) putchar(7);
			   else y=y-5;
	setfillstyle(1,0);;
	setcolor(0);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
	if(i==1)
	bar(x1,y1,x,y);
	}
   else if(tecla==13)
	    {
	    x1=x;
	    y1=y;
	    bar(x1,y1,x,y);
	    i=1;
	    }
}*/
return 0;
}
circulo()
{
/*int i=0,x=getmaxx()/2,y=getmaxy()/2,j,tecla=0;
line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
while(tecla!=27)
{
tecla=getch();
if(tecla==0)
  {
   setcolor(15);
   line(x-5,y,x+5,y);
   line(x,y-5,x,y+5);
   tecla=getch();
   if(tecla==77)
    if(x>=getmaxx()-5) putchar(7);
    else x=x+5;
   else if(tecla==75)
	    if(x<5) putchar(7);
	    else x=x-5;
	else if(tecla==80)
		  if(y>=getmaxy()-60) putchar(7);
		  else y=y+5;
		  else if(tecla==72)
			   if(y<5) putchar(7);
			   else y=y-5;
	setcolor(0);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
	}
   else if(tecla==13)
	    {
	     i=0;
	     tecla=0;
	     while(tecla!=27)
		{
		tecla=getch();
		if(tecla==0)
		{
		setcolor(15);
   circle(x,y,i);
   tecla=getch();
   if(tecla==77)
    if(i>=getmaxx()-5) putchar(7);
    else i=i+5;
   else if(tecla==75)
	    if(i<5) putchar(7);
	    else i=i-5;
	else putchar(7);
	setcolor(0);
	circle(x,y,i);
	}
	}

}}*/
return 0;    }

rectangulo()
{
/*comienza el juego*/
int x,i,j,salir=0,tecla;
setfillstyle(1,15);
bar(0,0,getmaxx(),getmaxy());
setcolor(0);
rectangle(50,50,getmaxx()-50,getmaxy()-50);
setcolor(1);
settextstyle(1,0,20);
setusercharsize(2,1,2,1);
outtextxy(100,70,"  S U P E R ");
outtextxy(240,300,"3 3 3 ");
for(i=1;i<=3;i++)
{setfillstyle(1,6);
bar(i*130,140,i*130+120,250);
}
setfillstyle(1,5);
bar(130,440,230,470);
bar(280,440,380,470);
bar(430,440,520,470);
x=130;
settextstyle(3,0,2);
setcolor(15);
outtextxy(148,445,"JUEGO");
outtextxy(298,445,"AYUDA");
outtextxy(460,445,"FIN");
settextstyle(3,0,2);
setfillstyle(1,3);
setcolor(15);
bar(130,440,230,470);
outtextxy(148,445,"JUEGO");
sonar();
while(!salir)
{
tecla=getch();
if(tecla==0)
{
setfillstyle(1,5);
setcolor(15);
bar(x,440,x+100,470);
if (x==130)
outtextxy(148,445,"JUEGO");
else
  if(x==280)
outtextxy(298,445,"AYUDA");
else
outtextxy(460,445,"FIN");
tecla=getch();
if(tecla==75)
 {    if(x==130)
	 x=430;
     else x=x-150; }
else
  if(tecla==77)
     {if(x==430) x=130;
     else x=x+150;}
  else putchar(7);
setfillstyle(1,3);
setcolor(15);
bar(x,440,x+100,470);
if (x==130)
outtextxy(148,445,"JUEGO");
else
  if(x==280)
outtextxy(298,445,"AYUDA");
else
outtextxy(460,445,"FIN");
}
else
  if(tecla==32) jugando();

  else if(tecla==13)
	   switch(x)
     {
     case 280:ayuda1();break;
     case 430:salir=1;
	      menu_ppal();
	      break;
     }

}
return 0;
}

jugando()
{
int i,j,t,t1;
for(i=1;i<=3;i++)
{setfillstyle(1,6);
bar(i*130,140,i*130+120,250);
}
randomize();
do
i=random(3);
while(i<0 || i>2);
do
j=random(3);
while(j<0 || j>2);
do
t1=random(3);
while(t1<0 || t1>2);
settextstyle(4,0,9);
if(i==0)

outtextxy(170,140,"$");
else
  if(i==1)
      outtextxy(170,140,"&");
else  outtextxy(170,140,"@");

if(j==0)

outtextxy(300,140,"$");
else
  if(j==1)
      outtextxy(300,140,"&");
else  outtextxy(300,140,"@");
if(t1==0)

outtextxy(420,140,"$");
else
  if(t1==1)
      outtextxy(420,140,"&");
else  outtextxy(420,140,"@");
if((i==j) && (j==t1)) {sonar();sonar();sonar();}
settextstyle(3,0,2);
setcolor(0);
puntos=puntos+100;
gotoxy(8,10);
printf("%d",puntos);
return 0;
}
ayuda1()
{
setfillstyle(1,9);
setcolor(15);
bar(80,280,getmaxx()-80,400);
rectangle(85,285,getmaxx()-85,395);
getch();
setfillstyle(1,15);
bar(80,280,getmaxx()-80,400);
setcolor(1);
settextstyle(1,0,20);
setusercharsize(2,1,2,1);
outtextxy(240,300,"3 3 3 ");
settextstyle(3,0,2);
return 0;
}
sonar()
{
int i;
for(i=280;i<=300;i++)
{
sound(i*10);
delay(5);
nosound();
}
return 0;
}

/*

int i=0,x=getmaxx()/2,y=getmaxy()/2,j,tecla=0,x1=0,y1=0;
line(x-5,y,x+5,y);
line(x,y-5,x,y+5);
while(tecla!=27)
{
tecla=getch();
if(tecla==0)
  {
   setcolor(15);
   line(x-5,y,x+5,y);
   line(x,y-5,x,y+5);
   rectangle(x1,y1,x,y);
   tecla=getch();
   if(tecla==77)
    if(x>=getmaxx()-5) putchar(7);
    else x=x+5;
   else if(tecla==75)
	    if(x<5) putchar(7);
	    else x=x-5;
	else if(tecla==80)
		  if(y>=getmaxy()-60) putchar(7);
		  else y=y+5;
		  else if(tecla==72)
			   if(y<5) putchar(7);
			   else y=y-5;
	setcolor(0);
	line(x-5,y,x+5,y);
	line(x,y-5,x,y+5);
	if(i==1)
	rectangle(x1,y1,x,y);
	}
   else if(tecla==13)
	    {
	    x1=x;
	    y1=y;
	    rectangle(x1,y1,x,y);
	    i=1;
	    }
}
}*/


logo()
{
setcolor(0);
setfillstyle(1,15);
bar(0,0,getmaxx(),getmaxy());
setlinestyle(0,5,10);
rectangle(3,3,getmaxx()-3,getmaxy()-3);
rectangle(5,5,getmaxx()-5,getmaxy()-5);
/*setfillstyle(1,2);
bar(6,getmaxy()-50,getmaxx()-6,getmaxy()-6);*/
settextstyle(6,0,4);
setcolor(5);
outtextxy(80,36,"Facultad de Ingenier¡a de Electronica");

for(i=1;i<=10000;i++)
{
do
x=random(getmaxx());
while(x<=75 || x>=265);
do
y=random(getmaxy());
while(y<=127 || y>=255);
putpixel(x,y,random(i));
}

setlinestyle(0,9,0);
line(133,205,150,205);
line(150,205,150,240);
line(115,240,150,240);
arc(115,210,140,270,30);
line(93,190,130,143);
line(130,143,165,143);
line(165,143,165,128);
line(180,128,180,143);
arc(133,185,140,270,20);
line(117,172,132,151);
line(132,151,165,240);
line(165,240,165,255);
line(180,240,180,255);
line(180,240,210,240);
line(210,240,247,193);
arc(225,173,315,90,30);
line(193,143,224,143);
line(193,143,193,178);
line(193,178,210,178);
arc(210,198,315,90,20);
line(224,212,208,232);
line(208,232,180,143);
line(180,128,265,128);
line(165,128,75,128);
line(75,128,75,235);
line(265,128,265,235);
line(180,255,245,255);
line(95,255,165,255);
arc(95,235,180,270,20);
arc(245,235,270,0,20);
rectangle(50,105,getmaxx()-350,getmaxy()-200);
setfillstyle(1,5);
floodfill(179,254,5);

/*rectangle(50,70,getmaxx()-300,getmaxy()-200);
/*rectangle(getmaxx()-100,getmaxy()-100,getmaxx()-50,getmaxy()-70);*/
/*circle(224,223,45);
circle(212,245,78);*/
settextstyle(7,0,4);
setcolor(5);
outtextxy(350,200,"UNIVERSIDAD");
outtextxy(375,250,"ANTONIO");
outtextxy(400,300,"NARINO");
settextstyle(3,0,3);
outtextxy(20,400,"*.*  ALEXANDER ROA. *.*");
outtextxy(20,425,"CODIGO  443605");


getch();
//exit(1);
return 0;
}
