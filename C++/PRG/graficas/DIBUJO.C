

# include <stdio.h>
# include <graphics.h>
# include <conio.h>
int n,x,y,i,a;
char *res[8]={"CASA","NUBE","CASA3","MONTANA","TRONCOS"," PRADO","ARBOLES","CIELO"};

main()
{
graficos();
presentacion();
dibujo();
getch();
}
 graficos ()
{
int error,tarjeta=DETECT,modo=0;
initgraph(& tarjeta,&modo,"C:\\borlandc\\bgi");
error=graphresult();
if(error!=grOk)
{
 printf(" error grafico: %s\n" , grapherrormsg (error));
 getch();
 exit(1);
 }
}
presentacion()
{
setbkcolor(1);
setcolor(9);
rectangle(0,0,639,479);
setfillstyle(1,1);
floodfill(1,639,15);
setcolor(5);
settextstyle(4,0,5);
outtextxy(20,80,"INGENIERIA DE SISTEMAS");
setcolor(15);
settextstyle(2,0,5);
outtextxy(80,200,"DIVIERTETE PINTANDO:");
setcolor(15);
rectangle(80,250,300,380);
setfillstyle(1,1);
floodfill(101,350,15);
setcolor(15);
settextstyle(2,0,5);
outtextxy(85,270,"A CONTINUACION  ENCONTRARAS ");
outtextxy(85,285,"UN DIVERTIDO DIBUJO EL CUAL");
outtextxy(85,300,"PODRAS  PINTAR  A  TU GUSTO");
outtextxy(85,315,"SELECCIONANDO  LA  FIGURA Y ");
outtextxy(85,330,"EL COLOR QUE DESEES...");
outtextxy(85,360,"PRESIONE <ENTER>. ");
outtextxy(350,250,"UNIVERSIDAD  ANTONIO  NARINO");
outtextxy(350,270," PROGRAMACION ESTRUCTURADA");
outtextxy(420,290,"  1.997 ");
getch();
}
   dibujo()
  {
  cleardevice();
  setbkcolor(0);
  setcolor(15);
  rectangle(0,0,635,405);
  line(20,200,20,250);
  line(20,250,40,260);
  line(40,260,40,210);
  line(40,210,20,200);
  line(90,260,100,270);
  line(100,270,100,170);
  line(100,170,90,160);
  line(90,160,90,260);
  line(100,170,120,170);
  line(120,170,110,110);
  line(110,110,100,170);
  line(90,160,110,110);
  line(100,170,110,110);
  line(90,160,110,110);
  line(90,160,100,170);
  line(120,270,120,170);
  line(100,270,120,270);
  line(120,260,170,260);
  line(170,260,170,210);
  line(170,210,160,210);
  line(160,210,160,220);
  line(160,220,150,220);
  line(150,220,150,210);
  line(150,210,140,210);
  line(140,210,140,220);
  line(140,220,130,220);
  line(130,220,130,210);
  line(130,210,120,210);
  line(90,210,80,210);
  line(80,210,80,220);
  line(80,220,70,220);
  line(70,220,70,210);
  line(70,210,60,210);
  line(60,210,60,220);
  line(60,220,50,220);
  line(50,220,50,210);
  line(50,210,40,210);
  ellipse(70,250,0,180,10,10);
  line(60,260,60,250);
  line(80,260,80,250);
  line(40,260,60,260);
  line(80,260,90,260);
  line(170,210,160,200);
  line(160,200,120,200);
  line(90,200,20,200);
  line(80,260,60,248);
  rectangle(140,230,155,240);
  circle(110,180,5);        /*pinta la primera casa*/
  putpixel(326,250,9);
  line(0,160,150,70);
  line(149,70,240,130);
  line(230,133,350,90);
  line(349,90,400,140);
  line(380,119,440,80);
  line(439,80,636,160);
  line(0,180,91,180);
  line(117,180,635,180);
  line(579,180,635,180); /*MONTANAS*/

  ellipse(82,29,360,185,23,20);
  ellipse(55,40,80,271,15,10);
  ellipse(74,52,170,0,19,18);
  ellipse(120,30,0,180,15,14);
  ellipse(137,44,260,95,20,15);
  ellipse(112,64,180,15,22,19);  /*NUBE*/

/*  line(440,250,440,140);
  line(440,140,470,140);
  line(440,250,470,250);
  line(470,250,470,140);
  line(470,250,480,240);
  line(470,140,480,130);
  line(480,240,480,130);
  line(480,130,460,100);
  line(440,140,460,100);
  line(470,137,460,100);
  line(550,240,580,230);
  line(580,230,580,170);
  line(580,170,570,174);
  line(570,174,570,184);
  line(570,184,560,188);
  line(560,188,560,179);
  line(560,179,550,180);
  line(550,180,550,240);
  line(520,240,550,240);
  line(550,180,540,180);
  line(540,180,540,190);
  line(540,190,530,190);
  line(530,190,530,180);
  line(530,180,520,180);
  line(520,180,520,190);
  line(520,190,510,190);
  line(510,190,510,180);
  line(510,180,500,180);
  line(500,180,500,190);
  line(500,190,490,190);
  line(490,190,490,180);
  line(490,180,480,180);
  line(480,240,500,240);
  ellipse(510,220,0,180,10,10);
  line(500,240,500,220);
  line(520,240,520,220);
  line(440,180,430,180);
  line(430,180,430,190);
  line(430,190,420,190);
  line(420,190,420,180);
  line(420,180,410,180);
  line(410,180,410,190);
  line(410,190,410,180);
  line(410,190,400,190);
  line(400,190,400,180);
  line(400,180,390,180);
  line(390,180,390,240);
  line(390,240,440,240);
  line(580,170,480,170);
  line(440,170,400,170);
  line(401,170,390,180);
  circle(452,160,3);         pinta la segunda casa*/

  circle(570,90,30);      /*pinta el sol*/

  rectangle(320,240,330,260);
  ellipse(320,230,90,270,15,10);
  ellipse(320,210,90,270,10,10);
  ellipse(325,200,0,180,10,15);
  ellipse(330,210,270,90,10,10);
  ellipse(330,230,270,90,15,10);
  rectangle(540,360,550,380);
  ellipse(540,350,90,270,15,10);
  ellipse(540,330,90,270,10,10);
  ellipse(545,320,0,180,10,15);
  ellipse(550,330,270,90,10,10);
  ellipse(550,350,270,90,15,10);
  rectangle(580,300,590,320);
  ellipse(580,290,90,270,15,10);
  ellipse(580,270,90,270,10,10);
  ellipse(585,260,0,180,10,15);
  ellipse(590,270,270,90,10,10);
  ellipse(590,290,270,90,15,10);
  rectangle(310,340,320,360);
  ellipse(310,330,90,270,15,10);
  ellipse(310,310,90,270,10,10);
  ellipse(315,300,0,180,10,15);
  ellipse(320,310,270,90,10,10);
  ellipse(320,330,270,90,15,10);       /* pinta los 4 arboles*/


  line(370,340,360,350);
  line(360,350,360,400);
  line(360,400,390,400);
  line(410,400,440,400);
  line(440,400,460,394);
  line(460,394,460,344);
  line(460,344,450,340);
  line(450,340,370,340);
  line(450,340,440,348);
  line(460,344,442,350);
  line(440,350,363,350);
  line(410,400,410,390);
  line(390,400,390,390);
  line(440,400,440,350);
  ellipse(400,390,0,180,10,10);
  rectangle(415,365,433,380);
  line(420,340,420,280);
  line(420,280,430,260);
  line(420,280,438,280);
  line(442,280,450,274);
  line(450,274,430,260);
  line(440,278,430,260);
  line(440,280,440,339);
  line(450,274,450,340);
  line(510,394,510,298);
  line(500,298,500,308);
  line(500,308,490,308);
  line(490,308,490,298);
  line(510,298,500,298);
  line(490,298,480,298);
  line(480,298,480,308);
  line(480,308,470,308);
  line(470,308,470,298);
  line(470,298,460,298);

  line(460,298,460,308);
  line(460,308,450,308);
  line(450,308,450,298);
  line(450,298,450,308);
  line(460,394,510,394);
  line(420,308,410,308);
  line(410,308,410,298);
  line(410,298,400,298);
  line(400,298,400,308);
  line(400,308,390,308);
  line(390,308,390,298);
  line(390,298,380,298);
  line(450,340,370,340);
  line(380,340,380,274);
  line(420,340,420,280);
  line(350,280,350,390);
  line(350,280,368,280);
  line(350,280,360,260);
  line(370,280,360,260);
  line(350,390,360,390);
  line(370,280,370,338);
  line(380,340,380,274);
  line(378,276,370,280);
  line(380,274,360,260);
  circle(430,300,5);
  circle(360,300,5);           /* pinta la tercera casa*/

  ellipse(320,70,3,100,35,9);
  ellipse(362,74,3,100,35,9);       /*paloma*/

/*  line(60,350,70,340);           line(70,340,100,341);
  line(110,341,132,338);         line(132,338,150,348);
  line(158,350,164,352);         line(164,352,160,372);
  line(160,372,152,372);
  ellipse(143,372,0,180,9,14);
  arc(59,364,0,90,12);
  line(71,366,72,390);
  line(76,390,79,366);
  line(81,366,84,390);
  line(88,390,92,365);
  line(133,372,132,390);         line(127,390,124,366);
  line(124,366,120,390);         line(117,390,114,366);
  line(92,366,100,366);
  ellipse(150,365,145,287,5,8);
  line(100,341,102,371);         line(106,368,110,341);
  line(102,371,110,371);         line(110,371,106,368);
  ellipse(72,394,0,180,3,4);     line(69,394,75,394);
  ellipse(86,394,0,180,3,4);     line(83,394,89,393);
  ellipse(118,394,0,180,3,4);    line(115,394,121,394);
  ellipse(130,394,0,180,3,4);    line(127,394,133,394);

  line(110,341,107,310);
  ellipse(58,370,66,180,15,30);
  ellipse(59,371,66,180,10,30);
  ellipse(63,368,66,181,10,25);
  circle(105,307,4);
  line(100,341,103,310);         line(103,313,93,330);
  line(93,330,100,332);          line(107,313,115,332);
  line(111,332,160,332);         line(100,332,80,332);
  line(160,329,160,335);         line(160,335,170,332);
  line(170,332,160,329);
  line(150,348,160,340);         line(160,340,158,350);
  circle(158,356,1);              caballo y se¤or*/


  line(220,40,250,40);
  line(220,36,217,36);
  line(220,36,220,44);
  line(220,44,217,44);
  line(220,40,217,40);
  line(242,37,234,37);
  line(238,48,242,37);
  line(234,37,240,26);
  circle(242,24,2);
  line(238,30,245,40);
  line(240,26,225,36);
  line(225,36,234,36);
  line(241,22,242,15);
  line(242,15,243,22);   /*bruja*/
  menu1();
  getch();
  }

menu1()
{
   char terminar=0;
   int cursor;
   int n;
   sobreponga();
   setcolor(15);
   rectangle(0,410,635,470);
   setfillstyle(1,1);
   floodfill(5,430,15);
   setcolor(15);
   settextstyle(2,0,5);
  /* outtextxy(10,400,n); */
   outtextxy(200,415,"DIGITE NUMERO DE FIGURA A COLOREAR: ");
   setcolor(14);
   outtextxy(40,432,"0.CASA       1.NUBE      2.SOL         3.CASA3     4.CIELO");
   outtextxy(40,452,"5.MONTANA    6.TRONCOS   7.ARBOLES     8.PRADO     9.TERMINAR ");
   cursor=getch();

   if(cursor>='0' && cursor<='9')
     {
       cursor=cursor-48;
     }

   switch(cursor)
     {

    case 0:  {/* CASA */
	     pintar();
	     setfillstyle(1,a);
	     floodfill(110,245,15);
	     floodfill(70,245,15);
	     floodfill(50,230,15);
	     floodfill(30,240,15);
	     floodfill(38,205,15);
	     floodfill(150,245,15);
	     floodfill(95,250,15);
	     floodfill(134,208,15);
	     floodfill(110,160,15);
	     floodfill(96,160,15);
	     menu1();
	     }

     case 1: {/* NUBE */
	     pintar();
	     setfillstyle(1,a);
	     floodfill(90,35,15);
	     menu1();
	     }

     case 2: {/* SOL */
	     pintar();
	     setfillstyle(1,a);
	     floodfill(570,90,15);
	     menu1();
	     }

     case 3: { /*CASA3*/
	     pintar();
	     setfillstyle(1,a);
	     floodfill(360,285,15);
	     floodfill(480,360,15);
	     floodfill(408,320,15);
	     floodfill(429,310,15);
	     floodfill(390,375,15);
	     menu1();
	     }
     case 4:
	     {/*CIELO*/
	      pintar();
	      setfillstyle(1,a);
	      floodfill(500,90,15);
	      menu1();
	      }

    case 5:  { /*MONTANA*/
	     pintar();
	     setfillstyle(1,a);
	     floodfill(350,120,15);
	     menu1();
	     }

     case 6: { /*TRONCOS*/
	     pintar();
	     setfillstyle(1,a);
	     floodfill(544,365,15);
	     floodfill(585,310,15);
	     floodfill(315,350,15);
	     floodfill(326,250,15);
	     menu1();
	     }

     case 7: { /*ARBOLES*/
	     pintar();
	     setfillstyle(1,a);
	     floodfill(322,220,15);
	     floodfill(315,320,15);
	     floodfill(548,325,15);
	     floodfill(583,265,15);
	     menu1();
	     }

       case 8: {/* PRADO*/
	     pintar();
	     setfillstyle(1,a);
	     floodfill(10,300,15);
	     menu1();
	     sobreponga();
	     }

     case 9: {
	      terminar=1;
	      closegraph();
	      exit(1);}
	      default: putchar(7);
	      sobreponga();
	      }
	     }

pintar()
  {
   sobreponga();
   setcolor(15);
   rectangle(0,410,635,470);
   setcolor(15);
   settextstyle(2,0,5);
   outtextxy(200,415,"DIGITE NUMERO DE COLOR");
   setcolor(14);
   outtextxy(40,432,"1.AZUL            2.VERDE            3.CYAN       4.ROJO");
   outtextxy(40,452,"5.MAGENTA         6.AMARILLO         7.GRIS       9.AZUL CLARO");
   a=getch();

  if(a>='0' && a<='9')
    {
     a=a-48;
    }
  sobreponga();
  menu1();
   }

sobreponga()
{
bar(1,410,635,470);
/*setfillstyle(1,1);
floodfill(5,415,15);*/
}



