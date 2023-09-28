/*PROGRAMA DE SISTEMAS OPERATIVOS,EL CUAL REALIZA LA SIMULACION
DE UN BLOQUEO MUTUO,LOS BLOQUEOS MUTUOS PUEDEN APARECER EN MUCHAS
FORMAS.PERO EL QUE SE PRESENTA CON ESTAS LINEAS DE PROGRAMACION
ES UN BLOQUEO MUTUO DE TRAFICO...
REALIZADO POR:
	      LUIS ALBERTO MENDOZA    494386
	      OSCAR NIXON RODRIGUEZ   494588
	      HERNAN GIOVANNY RIOS     494108 */

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int k,f,t,m,j,k,i,a,l;

main()
{
 abrir();
 while(!kbhit())
 {
  m=random(6);
  if(m==1||m==4)
  dibujo();
setcolor(12);
settextstyle(7,0,2);
outtextxy(340,430,"* ENTER PARA CONTINUAR *");
  if(m==2||m==5)
  dibujo1();
  if(m==3||m==6)
  dibujo2();
  }
   presentacion();
   carretera();
   exit(1);
   return 0;
}

abrir()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("presione cualquier tecla para continuar\n");
      printf("DIRECCIONE EL MODO GRAFICO,TARJETA BGI..");
      getch();
      exit(1);    /* terminate with an error code */
   }
   return 0;
}


dibujo()
{
t=random(16);
setcolor(t);
for(i=0,j=320;i<=240;i=i+8,j=j+8)
{
 line(320,i,j,240);
 line(320,i,320-i,240);
 line(320,480-i,320-i,240);
 line(320,480-i,320+i,240);
 delay(50);
}
return 0;
}


dibujo1()
{
 t=random(16);
 setcolor(t);
 for(k=0;k<=500;k=k+6)
{
 circle(0,0,k);
 circle(640,0,k);
 circle(0,480,k);
 circle(640,480,k);
}
return 0;
}

dibujo2()
{
 t=random(16);
 setcolor(t);
 for(i=0;i<400;i=i+6)
{
 circle(320,240,i);
 delay(20);
}
return 0;
}

presentacion()
{
int p;
cleardevice();
setcolor(3);
for(p=0;p<500;p=p+2)
{
circle(0,0,p);
circle(640,0,p);
circle(0,480,p);
circle(640,480,p);
}
setcolor(15);
rectangle(120,140,520,340);
setfillstyle(1,7);floodfill(320,240,15);
setcolor(8);
line(120,140,520,140);
line(520,140,520,340);
setcolor(15);
settextstyle(3,0,3);
outtextxy(160,140,"BLOQUEO MUTUO DE TRAFICO");
setcolor(3);
outtextxy(162,140,"BLOQUEO MUTUO DE TRAFICO");
setcolor(15);
settextstyle(2,0,5);
outtextxy(200,180,"        PRESENTADO POR");
setcolor(1);
outtextxy(200,220,"LUIS ALBERTO MENDOZA    494386");
outtextxy(200,260,"OSCAR NIXON RODRIGUEZ   494588 ");
outtextxy(200,300,"HERNAN GIOVANNY RIOS     494108 ");
setcolor(15);
outtextxy(202,220,"LUIS ALBERTO MENDOZA    494386");
outtextxy(202,260,"OSCAR NIXON RODRIGUEZ   494588");
outtextxy(202,300,"HERNAN GIOVANNY RIOS     494108");

delay(2500);
getch();
return 0;
}


carretera()
{
int r;
cleardevice();
setbkcolor(3);
setcolor(4);
rectangle(0,0,640,480);
setcolor(5);
settextstyle(3,0,2);
outtextxy(170,20," * BLOQUEO MUTUO * ");
outtextxy(40,80,"ES CUANDO UN PROCESO DE UN SISTEMA DE");
outtextxy(40,120,"MULTIPROGRAMACION ESPERA EN BALDE A QUE SE PRESENTE");
outtextxy(40,160,"UN EVENTO ESPECIFICO,LOS BLOQUEOS MUTUOS PUEDEN");
outtextxy(40,200,"APARECER EN MUCHAS FORMAS.SI A UN PROCESO SE LE");
outtextxy(40,240,"ASIGNA LA TAREA DE ESPERAR A QUE OCURRA UN EVENTO");
outtextxy(40,280,"Y EL SISTEMA NO INCLUYE PROVIDENCIAS PARA SE¥ALAR");
outtextxy(40,320,"LA OCURRENCIA DE DICHO EVENTO,HABRA UN BLOQUEO");
outtextxy(40,360,"MUTUO CON UN SOLO PROCESO...A CONTINUACION");
outtextxy(42,400,"EJEMPLO COMUN DE BLOQUEO MUTUO DE TRAFICO.");
outtextxy(80,440,"** DIGITE ENTER PARA CONTINUAR **");
setcolor(15);
outtextxy(172,22," * BLOQUEO MUTUO * ");
outtextxy(42,82,"ES CUANDO UN PROCESO DE UN SISTEMA DE");
outtextxy(42,122,"MULTIPROGRAMACION ESPERA EN BALDE A QUE SE PRESENTE");
outtextxy(42,162,"UN EVENTO ESPECIFICO,LOS BLOQUEOS MUTUOS PUEDEN");
outtextxy(42,202,"APARECER EN MUCHAS FORMAS.SI A UN PROCESO SE LE");
outtextxy(42,242,"ASIGNA LA TAREA DE ESPERAR A QUE OCURRA UN EVENTO");
outtextxy(42,282,"Y EL SISTEMA NO INCLUYE PROVIDENCIAS PARA SE¥ALAR");
outtextxy(42,322,"LA OCURRENCIA DE DICHO EVENTO,HABRA UN BLOQUEO");
outtextxy(42,362,"MUTUO CON UN SOLO PROCESO...A CONTINUACION");
outtextxy(42,402,"EJEMPLO COMUN DE BLOQUEO MUTUO DE TRAFICO.");
outtextxy(82,442,"** DIGITE ENTER PARA CONTINUAR **");
getch();

/*Segundo procedimiento del ejemplo del bloquo mutuo de trafico*/
cleardevice();
setbkcolor(3);
setcolor(4);
rectangle(0,0,640,480);
setcolor(5);
settextstyle(3,0,2);
outtextxy(150,40,"BLOQUEO MUTUO DE TRAFICO ");
outtextxy(40,100,"EL  SIGUIENTE  PROGRAMA  ILUSTRA  EL BLOQUEO");
outtextxy(40,140,"MUTUO QUE  A  VECES  SE  PRESENTA  EN LAS CIUDADES.");
outtextxy(40,180,"VARIOS AUTOMOVILES TRATAN DE  TRANSITAR  POR");
outtextxy(40,220,"UNA PARTE MUY CONCURRIDA DE UNA CIUDAD, PERO");
outtextxy(40,260,"EL  TRAFICO  SE  HA  DESQUICIADO  TOTALMENTE");
outtextxy(40,300,"EN ALGUN MOMENTO EL TRAFICO COMIENZA A FLUIR CON");
outtextxy(40,340,"NORMALIDAD,PERO NO SIN ANTES HABER PROVOCADO MOLESTIAS,");
outtextxy(40,380,"MOVILIZACIONES Y UNA CONSIDERABLE PERDIDA DE TIEMPO.");
outtextxy(90,420,"** DIGITE ENTER PARA CONTINUAR **");

setcolor(15);
outtextxy(152,42,"BLOQUEO MUTUO DE TRAFICO ");
outtextxy(42,102,"EL  SIGUIENTE  PROGRAMA  ILUSTRA  EL BLOQUEO");
outtextxy(42,142,"MUTUO QUE  A  VECES  SE  PRESENTA  EN LAS CIUDADES.");
outtextxy(42,182,"VARIOS AUTOMOVILES TRATAN DE  TRANSITAR  POR");
outtextxy(42,222,"UNA PARTE MUY CONCURRIDA DE UNA CIUDAD, PERO");
outtextxy(42,262,"EL  TRAFICO  SE  HA  DESQUICIADO  TOTALMENTE");
outtextxy(42,302,"EN ALGUN MOMENTO EL TRAFICO COMIENZA A FLUIR CON");
outtextxy(42,342,"NORMALIDAD,PERO NO SIN ANTES HABER PROVOCADO MOLESTIAS,");
outtextxy(42,382,"MOVILIZACIONES Y UNA CONSIDERABLE PERDIDA DE TIEMPO.");
outtextxy(92,422,"** DIGITE ENTER PARA CONTINUAR **");
getch();
cleardevice();
setbkcolor(8);
rectangle(-4,-4,100,100);
setfillstyle(1,1);floodfill(4,4,15);
rectangle(644,-4,540,100);
setfillstyle(1,1);floodfill(600,15,15);
rectangle(-4,484,100,380);
setfillstyle(1,1);floodfill(4,475,15);
rectangle(644,484,540,380);
setfillstyle(1,1);floodfill(635,475,15);
rectangle(170,170,470,310);
setfillstyle(1,7);floodfill(175,175,15);
rectangle(170,-4,470,100);
setfillstyle(1,7);floodfill(175,8,15);
rectangle(-4,170,100,310);
setfillstyle(1,7);floodfill(1,180,15);
rectangle(170,380,470,644);
setfillstyle(1,7);floodfill(175,385,15);
rectangle(540,170,644,310);
setfillstyle(1,7);floodfill(545,200,15);
setcolor(2);
for(a=1;a<20;a++)
{
circle(320,240,a);
}
setcolor(4);

for(f=1,r=1;r<480;f=f+45,r=r+45)
{
delay(90);
sound(f*20);
if(f<310)
{
rectangle(120,f,140,f+35);
m=random(6);
setfillstyle(1,m+1);floodfill(121,f+2,4);
rectangle(520,480-f,500,445-f);
m=random(6);
setfillstyle(1,m+1);floodfill(505,445-f+2,4);
}
rectangle(r,340,r+35,360);
m=random(6);
setfillstyle(1,m+1);floodfill(r+2,345,4);
rectangle(640-r,120,640-r-35,140);
m=random(6);
setfillstyle(1,m+1);floodfill(640-r-2,125,4);
delay(500);
}
nosound();
getch();
return 0;
}