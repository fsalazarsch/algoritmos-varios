#include<dos.h>
#include<io.h>
#include<stdio.h>
#include<process.h>
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<c:\bb\prg\sis_op~1\direcv~1\cuadro.h>
union REGS r;
int posx,posy,boton;
pixel(int,int,int,int,int,int,int);
cirwin();
void creditos();
void nombres();
void titulo();
void presentacion();
void iniciar();
void mostrar();
void esconde();
void posicion();
void simulacion();
void ayuda();
void programa();
int compara();
int click();
void menu();
void men1();
int gd=DETECT,gm=0;
main()
{
initgraph(&gd,&gm,"c:\\borlandc\\bgi");
iniciar();
presentacion();
closegraph();
men1();
getch();
return 0;
}

void men1()
{
 initgraph(&gd,&gm,"");
 menu();
 while(!kbhit())
 {
  mostrar();
  posicion();
  if(click()==1)
  {
   compara();
  }
 }
}

void iniciar()
{
 r.x.ax=0x00;int86(51,&r,&r);
}
void mostrar()
{
 r.x.ax=0x01;int86(51,&r,&r);
}
int click()
{
 int j=0;r.x.ax=0x05;r.x.bx=0;int86(51,&r,&r);j=r.x.bx;return (j);
}
void posicion()
{
 r.x.ax=0x03;int86(51,&r,&r);posx=r.x.cx;posy=r.x.dx;
}
void esconde()
{
 r.x.ax=0x02;int86 (51,&r,&r);
}
void menu()
{
 cleardevice();
 //setbkcolor(4);
 pixel(0,0,640,480,15,800,1);
 setcolor(7);
 rectangle(150,100,450,450);
 setfillstyle(1,7);floodfill(250,150,7);
 setcolor(8);
 line(160,110,440,110);line(160,110,160,440);
 setcolor(15);
 line(160,440,440,440);line(440,110,440,440);
 /*******botones********/
 rectangle(240,120,360,150);
 rectangle(200,170,400,200);
 rectangle(200,220,400,250);
 rectangle(200,270,400,300);
 rectangle(200,320,400,350);
 rectangle(200,370,400,400);
 setcolor(8);
 /****lineas de efecto **/
 line(360,120,360,150);
 line(240,150,360,150);
 line(400,170,400,200);
 line(200,200,400,200);
 line(400,220,400,250);
 line(200,250,400,250);
 line(400,270,400,300);
 line(200,300,400,300);
 line(400,320,400,350);
 line(200,350,400,350);
 line(400,370,400,400);
 line(200,400,400,400);
 setcolor(1);
 settextstyle(1,0,1);
 setcolor(672);outtextxy(263,124,"M E N U");
 setcolor(670);outtextxy(256,174,"SIMULACION");
 outtextxy(270,224,"AYUDA");
 outtextxy(260,274,"CREDITOS");
 outtextxy(260,324,"PROGRAMA");
 outtextxy(270,370,"SALIR");
}
int compara()
{
 setcolor(15);
 if (posx>=200&&posx<=400&&posy>=170&&posy<=200)
 {
 esconde();
 rectangle(200,170,400,200);
 setcolor(8);
 line(200,170,400,170);
 line(200,170,200,200);
 delay(200);
 simulacion();//llamado a funcion  simulacion
 }
 if (posx>=200&&posx<=400&&posy>=220&&posy<=250)
 {
 esconde();
 rectangle(200,220,400,250);
 setcolor(8);
 line(200,220,400,220);
 line(200,220,200,250);
 delay(200);
 ayuda();//llamado a funcion ayuda
 }
 if (posx>=200&&posx<=400&&posy>=270&&posy<=300)
 {
 esconde();
 rectangle(200,270,400,300);
 setcolor(8);
 line(200,270,400,270);
 line(200,270,200,300);
 delay(200);
 creditos();
 closegraph();
 men1();
 //llamado a funcion creditos
 }
 if (posx>=200&&posx<=400&&posy>=320&&posy<=350)
 {
 esconde();
 rectangle(200,320,400,350);
 setcolor(8);
 line(200,320,400,320);
 line(200,320,200,350);
 delay(200);
 programa();//llamado a funcion PROGRAMA
 }
 if (posx>=200&&posx<=400&&posy>=370&&posy<=400)
 {
 esconde();
 rectangle(200,370,400,400);
 setcolor(8);
 line(200,370,400,370);
 line(200,370,200,400);
 delay(200);
 //llamado a salir
 cirwin();
 closegraph();
 clrscr();
 exit(0);
 }
 return 0;
}
void presentacion()
 {
  int i,j,m;
 cleardevice();setbkcolor(1);setcolor(11);
 for(i=0;i<=320;i++)
 {
  line(320,240,640-i*2,0);
  line(320,240,640-i*2,480);
  delay(3);
 }
 for(j=0;j<=140;j++)
 {
  line(320,240,640,240-j*2);
  line(320,240,640,240+j*2);
  line(320,240,0,240-j*2);
  line(320,240,0,240+j*2);
  delay(3);
 }
 setcolor(1);
 settextstyle(2,0,4);
 outtextxy(290,350,"PULSE UNA TECLA PARA CONTINUAR");
 titulo();
 getch();
 r;
}

void titulo()
{
 int i=0,bandera=0;
 settextstyle(1,0,4);
 setcolor(1);outtextxy(160,220,"SISTEMA OPERATIVOS");
 do
 {
  if (bandera==1)
  {
   setrgbpalette(BLUE,0,i,0);
   i--;if (i==0)
   {
    bandera=0;
   }
  }
 if (bandera==0){setrgbpalette(BLUE,0,i,0);i++;}if (i==40){bandera=1;}}
 while(!kbhit());
 r;
}

void creditos()
{
 int i, j;
 cleardevice();//setbkcolor(0);setcolor(1);
 for(i=0;i<=480;i++)
 {
 for(j=0;j<=640;j++)
 putpixel(j,i,1);
 }
 setcolor(15);
 for(j=1;j<=70;j++)
 {
 for(i=1;i<=3;i++)
 rectangle(i*j,i*j,639-i*j,479-i*j);
 }
 for(i=210;i<=430;i++)
 {
 for(j=210;j<=270;j++)
 putpixel(i,j,0);
 }
 setcolor(11);rectangle(5,5,635,475); rectangle(7,7,633,473);
 setfillstyle(1,11);floodfill(40,20,1);
 setcolor(9);settextstyle(7,0,2);
 outtextxy(214,222,"PRESENTADO POR :");
 outtextxy(215,223,"PRESENTADO POR :");
 line(213,253,427,253);setcolor (670);
 outtextxy(217,224,"PRESENTADO POR :");
 outtextxy(218,225,"PRESENTADO POR :");
 outtextxy(219,226,"PRESENTADO POR :");
 settextstyle(2,0,5);line(214,254,428,254);line(214,254,429,254);
 setcolor(9);outtextxy(189,440,"PRESIONE UNA TECLA PARA CONTINUAR");
 setcolor(9);outtextxy(190,440,"PRESIONE UNA TECLA PARA CONTINUAR");
 getch(); nombres();r;
}

void nombres()
{
 int i, j;
 cleardevice();
 setbkcolor(1);setcolor(11);
 for(j=1;j<=10;j++)
 {
 for(i=1;i<=3;i++)
 rectangle(i*j,i*j,639-i*j,479-i*j);
 }
 settextstyle(GOTHIC_FONT,HORIZ_DIR,1);outtextxy(190,80,"SISTEMAS OPERATIVOS");
 outtextxy(120,150,"JAVIER ALEXANDER MEJIA CRUZ   COD. 492917");
 outtextxy(120,200,"CLAUDIA AGUILERA GUZMAN.      COD. 493373 ");
 outtextxy(120,250,"JUAN CARLOS PI¥EROS GARCIA.   COD. 494668 ");
 outtextxy(120,370,"21 DE OCTUBRE  DE 1997");
 settextstyle(SMALL_FONT,HORIZ_DIR,5);outtextxy(300,430,"PRESIONE UNA TECLA PARA CONTINUAR");
 getch();
}

pixel(int xi,int yi,int xf,int yf,int cl,int tt,int rn)
//int xi,yi,xf,yf,cl,tt,rn;
{
 int q,w,i,clr;
 randomize();
 for(i=0;i<tt;i++)
 {
   do
   {
    q=random(xf);
    w=random(yf);
    }while(!((q>xi&&q<xf)&&(w>yi&&w<yf)));
  if(!rn)
  clr=random(cl);
  else
  clr=cl;
  putpixel(q,w,clr);

}
return 0;
}


cirwin()
{
 int ban=1,i;
 closegraph();
 initgraph(&gd,&gm,"");
 for(i=10;i<=100;i=i+3)
 {
 if(ban==1)
 {
 cleardevice();
 ban=0;
 circle(320,240,i);
 sector(320,240,45,135,i,i);
 sector(320,240,225,315,i,i);
 delay(200);
 }
 else{
 cleardevice();
 ban=1;
 circle(320,240,i);
 sector(320,240,135,225,i,i);
 sector(320,240,315,360,i,i);
 sector(320,240,0,45,i,i);
 delay(200);
 }
 }
 ban=1;
 randomize();
 while(!kbhit())
 {
 int p;
 if(ban==1)
 {
 cleardevice();
 ban=0;
 circle(320,240,i);
 p=random(15);
 setfillstyle(1,p);
 sector(320,240,45,135,i,i); //grande
 sector(320,240,225,315,i,i); //grande
 setfillstyle(1,15);
 circle(100,100,30);
 sector(100,100,45,135,30,30); //izq
 sector(100,100,225,315,30,30); //izq
 circle(540,100,30);
 sector(540,100,45,135,30,30); //der
 sector(540,100,225,315,30,30); //der
 delay(200);
 }
 else{
 }
 cleardevice();
 ban=1;
 settextstyle(1,0,3);
 setcolor(7882);
 outtextxy(180,60,"SISTEMAS OPERACIONALES");
 settextstyle(0,0,1);
 outtextxy(170,400,"Pulse cualquier tecla para terminar");
 circle(320,240,i);
 p=random(15);
 setfillstyle(1,p);
 sector(320,240,135,225,i,i);//g
 sector(320,240,315,360,i,i);//g
 sector(320,240,0,45,i,i);//g
 setcolor(p);
 line(320,240,420,240);
 setfillstyle(1,15);
 circle(100,100,30);
 sector(100,100,135,225,30,30);//izq
 sector(100,100,315,360,30,30);//izq
 sector(100,100,0,45,30,30); //izq
 setcolor(15);
 line(100,100,130,100);
 circle(540,100,30);
 sector(540,100,135,225,30,30);//der
 sector(540,100,315,360,30,30);//der
 sector(540,100,0,45,30,30); //der
 line(540,100,570,100);
 delay(200);
 }
 return 0;
}
void simulacion()
{
 int i,j;
 int dispgraf = DETECT, modograf,coderror;
 initgraph(&dispgraf,&modograf,"");
 coderror=graphresult();
 if(coderror!=grOk)
 {
  printf("error en la funcion grafica: %s", grapherrormsg(coderror));
  cout<<"pulsa una tecla para parar";
  getch();
  exit(1);
 }
 setbkcolor(7);
 setcolor(WHITE);
 rectangle(10,10,625,453);
 rectangle(8,8,630,455);
 setcolor(5);
 outtextxy(400,80,"DIRECCION VIRTUAL");
 outtextxy(100,320,"TABLA DE PAGINAS");
 outtextxy(400,150," Pag   des");
 setcolor(15);
 outtextxy(145,145,"2");
 outtextxy(140,210,"21,504");
 outtextxy(145,255,"3");
 outtextxy(410,110,"2      500");
 setcolor(5);
 outtextxy(500,260,"DIRECCION ");
 outtextxy(500,280," REAL");
 outtextxy(400,350,"MEMORIA REAL");
 outtextxy(100,50,"DIRECCIONAMIENTO VIRTUAL A UNO REAL UTILIZANDO PAGINACION");
 outtextxy(170,400,"Pulse cualquier tecla para terminar");
 rectangle(100,100,200,300);
 line(100,200,200,200);
 line(100,230,200,230);
 rectangle(400,100,500,140);
 line(450,100,450,140);
 rectangle(410,180,490,340);
 line(410,250,490,250);
 line(410,300,490,300);
 line(410,310,490,310);
 setcolor(WHITE);
 sound(200);
 for(i=1;i<=12;i++)
 {
  putpixel(405,100-i,4);
  delay(10);
 }
 for(i=1;i<=315;i++)
 {
  putpixel(405-i,88,4);
  delay(10);
 }
  for(i=1;i<=65;i++)
 {
  putpixel(90,87+i,4);
  delay(10);
 }
 for(i=1;i<=10;i++)
 {
  putpixel(90+i,153,4);
  delay(10);
 }
 nosound();
 setcolor(4);
 outtextxy(95,150,"");
 setcolor(WHITE);
 sound(400);
 for(i=1;i<=50;i++)
 {
  putpixel(200+i,220,4);
  delay(10);
 }
 nosound();
 setcolor(4);
 outtextxy(244,217,"");
 setcolor(WHITE);
 outtextxy(257,220,"21,504");
 sound(350);
 for(i=1;i<=20;i++)
 {
  putpixel(480,140+i,4);
  delay(10);
 }
 for(i=1;i<=150;i++)
 {
  putpixel(480-i,160,4);
  delay(10);
 }
 for(i=1;i<=70;i++)
  {
   putpixel(330,160+i,4);
   delay(10);
  }
 for(i=1;i<=30;i++)
  {
   putpixel(330-i,230,4);
   delay(10);
  }
 nosound();
 outtextxy(260,229,"  500");
 outtextxy(260,230,"______");
 outtextxy(260,239,"22,004");
 sound(500);
 for(i=1;i<=68;i++)
  {
   putpixel(310+i,245,4);
   delay(10);
  }
  for(i=1;i<=40;i++)
  {
   putpixel(379,245+i,4);
   delay(10);
  }
  for(i=1;i<=30;i++)
  {
   putpixel(379+i,285,4);
   delay(10);
  }
 nosound();
 setcolor(4);
 outtextxy(405,282,"");
 setcolor(WHITE);
 outtextxy(430,280,"22,004");
 getch();
 cleardevice();
 setbkcolor(9);
 setcolor(WHITE);
 rectangle(10,10,625,453);
 rectangle(8,8,630,455);
 setcolor(7);
 outtextxy(400,80,"DIRECCION VIRTUAL");
 outtextxy(100,320,"TABLA DE SEGMENTOS");
 outtextxy(400,150,"Seg   des");
 setcolor(15);
 outtextxy(145,145,"1");
 outtextxy(120,210,"8K  17,408");
 outtextxy(145,255,"2");
 outtextxy(410,110,"1      600");
 setcolor(7);
 outtextxy(500,260,"DIRECCION ");
 outtextxy(500,280," REAL");
 outtextxy(400,350,"MEMORIA REAL");
 outtextxy(100,50,"DIRECCIONAMIENTO VIRTUAL A UNO REAL UTILIZANDO SEGMENTACION");
 outtextxy(170,400,"Pulse cualquier tecla para terminar");
 setcolor(11);
 rectangle(100,100,200,300);
 line(100,200,200,200);
 line(100,230,200,230);
 line(150,200,150,230);
 rectangle(400,100,500,140);
 line(450,100,450,140);
 rectangle(410,180,490,340);
 line(410,250,490,250);
 line(410,300,490,300);
 line(410,310,490,310);
 setcolor(15);
 sound(200);
 for(i=1;i<=12;i++)
 {
  putpixel(405,100-i,4);
  delay(10);
 }
 for(i=1;i<=315;i++)
 {
  putpixel(405-i,88,4);
  delay(10);
 }
  for(i=1;i<=65;i++)
 {
  putpixel(90,87+i,4);
  delay(10);
 }
 for(i=1;i<=10;i++)
 {
  putpixel(90+i,153,4);
  delay(10);
 }
 nosound();
 setcolor(4);
 outtextxy(95,150,"");
 setcolor(WHITE);
 sound(400);
 for(i=1;i<=50;i++)
 {
  putpixel(200+i,220,4);
  delay(10);
 }
 nosound();
 setcolor(4);
 outtextxy(244,217,"");
 setcolor(WHITE);
 outtextxy(255,220,"17,408");
 outtextxy(250,230,"+");
 sound(350);
 for(i=1;i<=20;i++)
 {
  putpixel(480,140+i,4);
  delay(10);
 }
 for(i=1;i<=150;i++)
 {
  putpixel(480-i,160,4);
  delay(10);
 }
 for(i=1;i<=70;i++)
  {
   putpixel(330,160+i,4);
   delay(10);
  }
  for(i=1;i<=30;i++)
  {
   putpixel(330-i,230,4);
   delay(10);
  }
 nosound();
 outtextxy(260,229,"  600");
 outtextxy(260,230,"______");
 outtextxy(260,239,"18,008");
 sound(400);
 for(i=1;i<=68;i++)
  {
   putpixel(310+i,245,4);
   delay(10);
  }
  for(i=1;i<=40;i++)
  {
   putpixel(379,245+i,4);
   delay(10);
  }
  for(i=1;i<=30;i++)
  {
   putpixel(379+i,285,4);
   delay(10);
  }
 nosound();
  setcolor(4);
 outtextxy(405,282,"");
 setcolor(WHITE);
 outtextxy(430,280,"18,008");
 getch();
 cleardevice();
 setbkcolor(8);
 setcolor(WHITE);
 rectangle(10,10,625,453);
 rectangle(8,8,630,455);
 setcolor(14);
 outtextxy(250,70,"DIRECCION VIRTUAL");
 outtextxy(100,320,"TABLA DE SEG");
 outtextxy(250,145,"Seg  Pag  Des");
 setcolor(15);
 outtextxy(140,150,"1");
 outtextxy(130,210,"4K  X");
 outtextxy(290,200,"1");
 outtextxy(250,120," 1    2  400");
 outtextxy(290,300,"2");
 setcolor(14);
 outtextxy(500,260,"DIRECCION ");
 outtextxy(500,280," REAL");
 outtextxy(400,350,"MEMORIA REAL");
 outtextxy(250,360,"TABLA DE PAG");
 outtextxy(40,50,"DIRECCIONAMIENTO VIRTUAL A UNO REAL UTILIZANDO SEGMENTACION Y PAGINACION");
 outtextxy(170,400,"Pulse cualquier tecla para terminar");
 setcolor(3);
 rectangle(100,100,200,300);
 line(100,200,200,200);
 line(100,220,200,220);
 line(150,200,150,220);
 rectangle(250,100,350,140);
 line(280,100,280,140);
 line(320,100,320,140);
 rectangle(250,180,350,350);
 line(250,230,350,230);
 line(250,250,350,250);
 rectangle(410,180,490,340);
 line(410,250,490,250);
 line(410,300,490,300);
 line(410,310,490,310);
 sound(200);
 setcolor(15);
 for(i=1;i<=12;i++)
 {
  putpixel(270,100-i,4);
  delay(10);
 }
 for(i=1;i<=178;i++)
 {
  putpixel(270-i,88,4);
  delay(10);
 }
 for(i=1;i<=65;i++)
 {
  putpixel(90,87+i,4);
  delay(10);
 }
 for(i=1;i<=10;i++)
 {
  putpixel(90+i,153,4);
  delay(10);
 }
 nosound();
  setcolor(4);
 outtextxy(95,150,"");
 setcolor(WHITE);
 sound(340);
 for(i=1;i<=20;i++)
 {
  putpixel(300,140+i,4);
  delay(10);
 }
 for(i=1;i<=80;i++)
 {
  putpixel(300-i,160,4);
  delay(10);
 }
 for(i=1;i<=40;i++)
 {
  putpixel(220,160+i,4);
  delay(10);
 }
 for(i=1;i<=30;i++)
 {
  putpixel(220+i,200,4);
  delay(10);
 }
 nosound();
 setcolor(4);
 outtextxy(245,197,"");
 setcolor(WHITE);
 sound(400);
 for(i=1;i<=50;i++)
 {
  putpixel(200+i,220,4);
  delay(10);
 }
 nosound();
  setcolor(4);
 outtextxy(244,217,"");
 setcolor(WHITE);
 outtextxy(270,240,"21,504");
 sound(600);
 for(i=1;i<=19;i++)
 {
  putpixel(350,140+i,4);
  delay(10);
 }
 for(i=1;i<=170;i++)
 {
  putpixel(350+i,160,4);
  delay(10);
 }
 for(i=1;i<=120;i++)
 {
  putpixel(520,160+i,4);
  delay(10);
 }
 for(i=1;i<=30;i++)
 {
  putpixel(520-i,280,4);
  delay(10);
 }
 nosound();
 outtextxy(430,280,"12,488");
 sound(350);
 for(i=1;i<=30;i++)
  {
   putpixel(350+i,245,4);
   delay(10);
  }
  for(i=1;i<=40;i++)
  {
   putpixel(379,245-i,4);
   delay(10);
  }
  for(i=1;i<=30;i++)
  {
   putpixel(379+i,205,4);
   delay(10);
  }
 nosound();
 setcolor(4);
 outtextxy(405,202,"");
 setcolor(WHITE);
 outtextxy(430,230,"21,904");
 getch();men1();
 restorecrtmode();
}

void ayuda()
{
 int dispgraf = DETECT, modograf,coderror;
 initgraph(&dispgraf,&modograf,"");
 coderror=graphresult();
 if(coderror!=grOk)
 {
  printf("error en la funcion grafica: %s", grapherrormsg(coderror));
  printf("pulsa una tecla para parar");
  getch();
  exit(1);
 }
 setbkcolor(7);
 setcolor(WHITE);
 rectangle(8,8,630,455);
 rectangle(10,10,625,453);
 setcolor(5);
 outtextxy(150,80,"BIENVENIDOS A AYUDA");
 outtextxy(100,150,"DIRECCIONAMIENTO VIRTUAL A UNO REAL POR SEGMENTACION");
 outtextxy(80,200,"En  el  direccionamiento  por SEGMENTACION,  la direcci¢n  virtual ");
 outtextxy(80,220,"se compone de dos partes  el  segmento  y desplazamiento.  La  1ra");
 outtextxy(80,240,"sirve para indizarse dentro de la llamada  tabla de segmentos,  en ");
 outtextxy(80,260,"donde se encuentra la direcci¢n del segmento   correspondiente.  A");
 outtextxy(80,280,"‚sta se le suma el desplazamiento para obtener la  direcci¢n en la");
 outtextxy(80,300,"memoria real.  Dentro de cada entrada de la  tabla  de segmento se");
 outtextxy(80,320,"encuentra tambi‚n un campo que indica la longitud del segmento, el");
 outtextxy(80,340,"cual permite verificar que no se hagan referencias  fuera del seg.");
 outtextxy(100,400,"DIGITE CUALQUIER TECLA PARA CONTINUAR CON LA SIGUIENTE AYUDA");
 getch();
 cleardevice();
 setbkcolor(7);
 setcolor(WHITE);
 rectangle(10,10,625,453);
 rectangle(8,8,630,455);
 setcolor(5);
 outtextxy(150,80,"BIENVENIDOS A AYUDA");
 outtextxy(100,150,"DIRECCIONAMIENTO VIRTUAL A UNO REAL POR PAGINACION");
 outtextxy(80,200,"En  el  direccionamiento  por   PAGINACION,  la direcci¢n   virtual ");
 outtextxy(80,220,"se compone de dos partes  el  segmento  y desplazamiento.  La   1ra ");
 outtextxy(80,240,"sirve para indizarse dentro de  la  llamada  tabla de paginas,   en ");
 outtextxy(80,260,"donde se encuentra la direcci¢n de la pagina   correspondiente.   A ");
 outtextxy(80,280,"‚sta se le suma el desplazamiento para obtener la  direcci¢n en  la ");
 outtextxy(80,300,"memoria real. Los bloques, denominados en este caso p ginas, tienen ");
 outtextxy(80,320,"una longitud fija, e igual a la del m ximo  desplazamiento  posible ");
 outtextxy(100,400,"DIGITE CUALQUIER TECLA PARA CONTINUAR CON LA SIGUIENTE AYUDA");
 getch();
 cleardevice();
 setbkcolor(7);
 setcolor(WHITE);
 rectangle(10,10,625,453);
 rectangle(8,8,630,455);
 setcolor(5);
 outtextxy(150,80,"BIENVENIDOS A AYUDA");
 outtextxy(100,150,"DIRECCIONAMIENTO VIRTUAL A UNO REAL  DE SEGMENTACION-PAGINACION");
 outtextxy(80,200,"Las direcciones virtuales se componen de tres partes:     segmento, ");
 outtextxy(80,220,"p gina y desplazamiento.  La 1ra sirve para indizarse en una tabla ");
 outtextxy(80,240,"de segmentos, en la cual se encuentran la longitud y direcci¢n, la ");
 outtextxy(80,260,"2da sirve para indizarse en la tabla de p ginas, si se saben ‚sta y ");
 outtextxy(80,280,"el desplazamiento, se puede llegar a la direcci¢n en memoria real. ");
 outtextxy(80,300,"Este m‚todo se utiliza en sistemas como Multics y PRIMOS. ");
 outtextxy(100,400,"DIGITE CUALQUIER TECLA PARA CONTINUAR CON LA SIGUIENTE AYUDA");
 getch();men1();
 restorecrtmode();
}
void programa()
{
 int i,j;
 int dispgraf = DETECT, modograf,coderror;
 initgraph(&dispgraf,&modograf,"");
 coderror=graphresult();
 if(coderror!=grOk)
 {
  printf("error en la funcion grafica: %s", grapherrormsg(coderror));
  printf("pulsa una tecla para parar");
  getch();
  exit(1);
 }
 setbkcolor(9);
 setcolor(11);
 rectangle(8,8,630,455);
 rectangle(10,10,625,453);
 setfillstyle(LINE_FILL,RED);
 setcolor(607);
 settextstyle(SMALL_FONT,HORIZ_DIR,6);outtextxy(80,100,"SIMULACION DE UN DIRECCIONAMIENTO VIRTUAL A UNO REAL");
 setcolor(GREEN); outtextxy(80,200,"Ü UTILIZANDO SEGMENTACION");
 setcolor(GREEN); outtextxy(80,250,"Ü UTILIZANDO PAGINACION");
 setcolor(GREEN); outtextxy(80,300,"Ü UTILIZANDO SEGMENTACION - PAGINACION");
 getch();men1();
 restorecrtmode();
}