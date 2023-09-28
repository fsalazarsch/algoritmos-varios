#include "stdlib.h"
#include "graphics.h"
#include "stdio.h"         /******ESTR4578*****/
#include "conio.h"         /******PRINCIPAL****/
//# include "a:\programa\cuarto.h"
# define relleno{int b,t;setcolor (BLUE);for (b=0; b<=400;b=b+2)for (t=0; t<70;t=t+1) line(100,350,100+b,350+t);}
# define cuadro1(c){int a,b; for(a=5;a<=620;a=a+4)for(b=5;b<=460;b=b+5){setcolor(c);circle(a,b,1);}}
#define escriba(t,tm,c,x,y,cad) {setcolor(c);settextstyle(t,0,tm);outtextxy(x,y,cad);}
/*
escriba(t,tm,c,x,y,cad)
t    Tipo de letra
tm   TmaЄo de la letra
c    Color de la letra
x  Coordenada en X
y  Coordenada en Y
cad Cadena
*/


#define cuadro(c)  {setcolor(c);setfillstyle(1,c);rectangle(5,5,620,460);floodfill(6,6,c);}
#define escriba(t,tm,c,x,y,cad) {setcolor(c);settextstyle(t,0,tm);outtextxy(x,y,cad);}

void principal(void)
{cleardevice(),setfillstyle(6,2);
floodfill(30,40,8);
outtextxy(50,100,"    лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
outtextxy(50,110,"    л                                                          л");
outtextxy(50,120,"    л                                                          л");
outtextxy(50,130,"    л                                                          л");
outtextxy(50,140,"    л                                                          л");
outtextxy(50,150,"    л                                                          л");
outtextxy(50,160,"    л                                                          л");
outtextxy(50,170,"    л                                                          л");
outtextxy(50,180,"    л                                                          л");
outtextxy(50,190,"    л                                                          л");
outtextxy(50,200,"    л                                                          л");
outtextxy(50,210,"    л                                                          л");
outtextxy(50,220,"    л                                                          л");
outtextxy(50,230,"    л                                                          л");
outtextxy(50,240,"    л                                                          л");
outtextxy(50,250,"    л                                                          л");
outtextxy(50,260,"    л                                                          л");
outtextxy(50,270,"    л                                                          л");
outtextxy(50,280,"    л                                                          л");
outtextxy(50,290,"    л                                                          л");
outtextxy(50,300,"    л                                                          л");
outtextxy(50,310,"    л                                                          л");
outtextxy(50,320,"    л                                                          л");
outtextxy(50,330,"    л                                                          л");
outtextxy(50,340,"    л                                                          л");
outtextxy(50,350,"    л                                                          л");
outtextxy(50,360,"    л                                                          л");
outtextxy(50,370,"    л                                                          л");
outtextxy(50,380,"    л                                                          л");
outtextxy(50,390,"    л                                                          л");
outtextxy(50,400,"    лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
escriba(4,3,5,100,140,"  UNIVERSIDAD ANTONIO NARIЅO");
escriba(4,3,15,100,137,"  UNIVERSIDAD ANTONIO NARIЅO");
escriba(4,2,5,90,180,"  FACULTAD INGENIERIA DE SISTEMAS");
escriba(4,2,15,90,177,"  FACULTAD INGENIERIA DE SISTEMAS");
escriba(4,3,5,120,220,"     ESTRUCTURA DE DATOS");
escriba(4,3,15,120,217,"     ESTRUCTURA DE DATOS");
escriba(4,3,5,100,260,"  ALEJANDRO SUAREZ COD 494578");escriba(4,3,15,100,257,"  ALEJANDRO SUAREZ COD 494578");
escriba(4,3,5,100,300,"  ARTURO BUSTOS     COD 493436");escriba(4,3,15,100,297,"  ARTURO BUSTOS     COD 493436"); escriba(4,3,5,190,340,"  MAYO 3 DE 1.996  ");escriba(4,3,15,190,337,"  MAYO 3 DE 1.996 ");
escriba(4,3,16,135,430,"  ЎDigite una tecla para continuarЏ");getch();}


  void graficos (void){
 int error,tarjeta=DETECT,modo=0;
  setgraphbufsize(2048);
  initgraph(&tarjeta,&modo,"c:\\borlandc\\bgi");
  error=graphresult();
  if(error != grOk){
   printf ("error grafico:%s\n",grapherrormsg(error));
   delay(4000);
   setgraphbufsize(2048);
   exit(0);  }}



void opciones(void){ int opc;cleardevice();cuadro(3);
  do{  setcolor(1); setfillstyle(9,1);
  rectangle(100,70,520,400);
  floodfill(220,120,1);
 escriba(1,4,7,100,80,"         OPCIONES");
  escriba(1,1,7,105,140," 1. QUE ES UN ARBOL BINARIO");
  escriba(1,1,7,105,180," 2. DEFINICIONES");
  escriba(1,1,7,105,220," 3. ESTRUCTURA DE UN ARBOL BINARIO");
  escriba(1,1,7,105,260," 4. FORMAS DE RECORRER UN ARBOL BINARIO");
  escriba(1,1,7,105,300," 5. SALIR ");
  escriba(1,1,7,105,347,"            DIGITE SU OPCION: ");
  gotoxy(50,23);
  scanf("%d",&opc);
    switch(opc){
       case 1:{  clrscr(); /*arbol();*/printf("yasmin");      clrscr ();	  break;}
       case 2:{	 clrscr();/* menu2();*/	printf("kelly"); clrscr ();       break; }
       case 3:{  clrscr();/* estructura();*/ printf ("angie");clrscr ();       break;}
       case 4:{  clrscr();/* nota();menu3();*/printf("hola");clrscr ();      break;}
       case 5:{ closegraph(); exit(0);}}}
  while(opc>=1 && opc<=5);}


main()
{
graficos();
cuadro(4);
getch();
cuadro1(3);
getch();
principal();
opciones();
getch();
closegraph();
}

