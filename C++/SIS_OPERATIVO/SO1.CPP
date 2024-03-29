#include <bios.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <ctype.h>
#include <graphics.h>
#include <string.h>
int acceso();
int fondo();
int presentacion();
void inigra();
void mover(int);
void mova();
void movb();
void menu();
int t=1,y=100;
void parte_grafi();
void simula();
void superusuario();
void usuario1();
void usuario2();
void usuario3();
void presenta ();
char *op[3]={"PRESENTACION GRAFICA UNIX","SIMULACION UNIX","SALIR"};
struct user{
	    char id[14],clave[8];
	    int pl,pe,pex,su;
	    };
void cambiarc(char *i,char *cl);

void main(void)
{

  int c,e=0;
  inigra();
   presenta();
   acceso();
   fondo();
   presentacion();

  menu();
      while(1)
	{
	    c = getch();
	    if (!c)
	       {e = getch();
		mover(e);
		}
	 if(c==13)
	 switch(t)
	 {case 1: closegraph();inigra();parte_grafi(); menu();
		  break;
	 case 2: closegraph();simula();inigra(); menu();
		  break;
	  case 3: closegraph(); exit(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                (errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
   }

}
/*************************************************/
/*FUNCION QUE IDENTIFICA LAS TECLAS PULSADAS*/
/*************************************************/

void mover(int e)
{
switch(e)
{
case 72: mova();break;
case 80: movb();break;
}
}
/***********************************************/
/*FUNCION QUE ACTIVA LA FUNCION A EJECUTARSE*/
/***********************************************/
void mova()
{
 if(t==1)
   {setcolor(14);
   outtextxy(130,100,op[0]);
   setcolor(13);
   outtextxy(130,250,op[2]);
   t=3;
   y=250;
      }
 else
   {setcolor(14);
    outtextxy(130,y,op[t-1]);
    t--;
    setcolor(13);
    y-=75;
    outtextxy(130,y,op[t-1]);
}
}

void movb()
{
 if(t==3)
   {setcolor(14);
    outtextxy(130,250,op[2]);
    setcolor(13);
    outtextxy(130,100,op[0]);
    t=1;
    y=100;
    }
  else
   {setcolor(14);
    outtextxy(130,y,op[t-1]);
    t++;
    setcolor(13);
    y+=75;
    outtextxy(130,y,op[t-1]);
    }
    }
/******************************************/
/*FUNCION QUE MUESTRA MENU PRINCIPAL*/
/*******************************************/
void menu()
{
   cleardevice();

   setbkcolor(BLACK);
   setcolor(3);
   bar3d(40,40,600,350,15,10);
   setfillstyle(1,3);
   floodfill(42,42,3);
   setcolor(13);
   settextstyle(3,0,4);
   outtextxy(130,100,"PRESENTACION GRAFICA UNIX");
   setcolor(14);
   outtextxy(130,175,"SIMULACION UNIX ");
   outtextxy(130,250,"SALIR");
   settextstyle(1,0,4);
   setcolor(10);
   outtextxy(40,400,"SEGURIDAD SISTEMA OPERATIVO UNIX");
   t=1;
    setcolor(3);
   settextstyle(3,0,4);
 }
/********************************************/
/*FUNCION QUE VALIDA LA CLAVE DEL PROGRAMA*/
/********************************************/
 acceso(){
   char clav[7],clav1[8];
   int j,i,wt,wt2,wt3;
   setbkcolor(DARKGRAY);
   clav1[0]='s';
   clav1[1]='e';
   clav1[2]='m';
   clav1[3]='e';
   clav1[4]='s';
   clav1[5]='t';
   clav1[6]='r';
   clav1[7]='e';
   j=4;wt3=0;
   setcolor(YELLOW);
   rectangle(20,10,600,400);
   setcolor(WHITE);
   settextstyle(1,0,5);
   outtextxy(220,30," U.A.N");
   outtextxy(123,90,"  SEGURIDAD UNIX");
   settextstyle(1,0,4);
   do{
    j++;
    setcolor(j);
    wt=1;
    wt2=1;
   outtextxy(120,150,"teclee su clave de acceso");
   rectangle(230,200,360,230);
   for (i=0;i<=7;i++){
     clav[i]=getch();
     sound(300);
     delay(50);
     nosound();
     outtextxy(250+i*12,202,"*");
     }
    for (i=0;i<=7;i++){
     if(tolower(clav[i])!=clav1[i])
     wt=0;
     }
     if(wt==0){
	wt2=0;
	wt3++;
	outtextxy(160,310,"acceso no permitido");
	outtextxy(175,360,"vuelva a intentar");
     }
     if(wt3==3){
      setcolor(DARKGRAY);
      outtextxy(175,360,"vuelva a intentar");
      for(i=200;;i=i+20){
      if(i>900)i=300;
      sound(i);
      delay(20);
      nosound();
      }
      }
     }while(wt2==0);
     outtextxy(180,250,"acceso permitido");
     delay(2700);
     clearviewport();
    return 0;
   }


 /*******************************************************************/
 /**********ESTA FUNCION HACE LA PRESENTACION DEL PROGRAMA***********/
 /******************************************************************/

int presentacion(){
void *bufp,*bufp1,*bufp2;
int l1,l2,l3,wp;
unsigned tamanop,tamanop1,tamanop2;
setbkcolor(DARKGRAY);
tamanop2=imagesize(0,0,60,60);

      bufp2=malloc(tamanop2);
      if (bufp2){
	getimage(0,0,60,60,bufp2);
      }

setcolor(GREEN);
setfillstyle(INTERLEAVE_FILL,BLUE);
bar3d(0,10,55,60,3,3);
floodfill(1,12,GREEN);
tamanop=imagesize(0,0,60,60);

      bufp=malloc(tamanop);
      if (bufp){
	getimage(0,0,60,60,bufp);
      }
setfillstyle(INTERLEAVE_FILL,RED);
bar3d(0,10,55,60,2,2);
floodfill(1,12,GREEN);
tamanop1=imagesize(0,0,60,60);

      bufp1=malloc(tamanop1);
      if (bufp1){
	getimage(0,0,60,60,bufp1);
      }
    clearviewport();
    putimage(0,10,bufp2,COPY_PUT);
  wp=0;
  for(l3=40;l3<=300;l3=l3+56){
  for(l2=400;l2>=0;l2=l2-54){
  if(wp==0)wp=1;
  else wp=0;
  for(l1=20;l1<=l2;l1=l1+54){
  if(wp==0){
  putimage(l3,l1,bufp1,COPY_PUT);
  putimage(580-l3,l1,bufp1,COPY_PUT);
  }
  else
  putimage(l3,l1,bufp,COPY_PUT);
  putimage(580-l3,l1,bufp,COPY_PUT);
  putimage(l3,l1,bufp2,COPY_PUT);
  putimage(580-l3,l1,bufp2,COPY_PUT);
  }
  if(wp==0){
  putimage(l3,l2,bufp1,COPY_PUT);
  putimage(580-l3,l2,bufp1,COPY_PUT);
  }
  else{
  putimage(l3,l2,bufp,COPY_PUT);
  putimage(580-l3,l2,bufp,COPY_PUT);
  }
  }
  }
  setcolor(14);
  settextstyle(3,0,8);
  outtextxy(50,80,"SEGURIDAD");
  outtextxy(51,80,"SEGURIDAD");
  outtextxy(52,80,"SEGURIDAD");
  outtextxy(53,80,"SEGURIDAD");
  outtextxy(54,80,"SEGURIDAD");
  outtextxy(55,80,"SEGURIDAD");
  outtextxy(120,250,"UNIX...");
  outtextxy(121,250,"UNIX...");
  outtextxy(122,250,"UNIX...");
  outtextxy(123,250,"UNIX...");
  outtextxy(124,250,"UNIX...");
  outtextxy(125,250,"UNIX...");
  free(bufp);
  free(bufp1);
  free(bufp2);
  setcolor(14);
  settextstyle(1,0,3);
  outtextxy(300,420,"presione alguna tecla");
  getch();
  clearviewport();

  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("                             INTRODUCCION           \n");
  printf("\n");
  printf("\n");
  printf("      LOS SISTEMAS UNIX,ESTAN DISEĽADOS PARA SER AMABLES Y AACESIBLES, \n");  printf("\n");
  printf("      Y PARA FOMENTAR LA INTERACCION ENTRE PERSONAS A TRAVEZ DEL SISTEMA\n" );
  printf("\n");
  printf("      DE COMPUTO. ESTO HACE MAS DIFICIL MANTENER LA SEGURIDAD DEL SISTEMA\n");
  printf("\n");
  printf("      LOS SISTEMAS UNIX ESTAN DISEĽADOS PARA SER SISTEMAS ABIERTOS; SUS  \n");
  printf("\n");
  printf("      ESPECIFICACIONES SE DAN A CONOCER AMPLIAMENTE. ES POSIBLE OBTENER EL  \n");
  printf("\n");
  printf("      CODIGO FUENTE. EL ARCHIVO DE CONTRASEĽA DEL SISTEMA UNIX SE ALMACENA  \n");
  printf("\n");
  printf("      EN FORMA CIFRADA. CUANDO UN USUARIO TECLEA UNA CONTRASEĽA, SE APLICA  \n");
  printf("\n");
  printf("      UNA TRANSFORMACION EN UN SOLO SENTIDO PARA FORMAR LA VERSION CIFRADA\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("     ESTE TRABAJO PRESENTA LA SIMULACION DE LA SEGURIDAD DE UNIX \n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("                                       presione alguna tecla....\n");
  setcolor(GREEN);
  rectangle(10,10,630,450);
  getch();
  clearviewport();
return 0;
}


fondo(){
int x,y;
setfillstyle(WIDE_DOT_FILL,WHITE);
setcolor(GREEN);
bar3d(70,80,550,455,10,1);
floodfill(81,90,GREEN);
for(x=130;x<=550;x=x+60)
line(x,80,x,455);
for(y=80;y<=455;y=y+63)
line(70,y,550,y);
return 0;
}

 void presenta (void)
  {
   setbkcolor(5);
   rectangle(55,30,580,460);
   setfillstyle(SOLID_FILL, 1);
   floodfill(57,445,3);
   setcolor(16);
   setbkcolor(2);
   settextstyle(3, 0,4);
   outtextxy(95,50, "UNIVERSIDAD ANTONIO NARINO");
   settextstyle(3, 0,3);
   outtextxy(180,100, "SISTEMAS OPERATIVOS");
   settextstyle(3, 0,3);
   outtextxy(150,140, "SEGURIDAD DEL SISTEMA OPERATIVO UNIX");
   settextstyle(3, 0,3);
   outtextxy(100,180, "PRESENTADO AL ing:");
   outtextxy(250,220,  "ROBERTO FERNANDEZ");
   settextstyle(3, 0,3);
   outtextxy(100,265, "PRESENTADO POR:");
   outtextxy(250,290,"MARLYN BAENA Cod. 494268");
   settextstyle(3, 0,3);
   outtextxy(100,325, "FACULDAD DE INGENIERIA DE SISTEMAS");
   settextstyle(3, 0,3);
   outtextxy(230,375, "OCTUBRE 21 DE 1997.");
   settextstyle(6, 0,5);
   outtextxy(190,430, "DIGITE ENTER !!! [  ]");
   getch();
   cleardevice();
   }

/************************************************************/
/*FUNCION QUE MUESTRA LA PARTE DE GRAFICA DE LA SIMULACION*/
/************************************************************/
 void parte_grafi(void)
 {
  int op;
  cleardevice();
  delay(200);
  setbkcolor(0);
  setcolor(12);
  rectangle(0,0,640,450);
  setfillstyle(INTERLEAVE_FILL,1);
  floodfill(360,310,12);
  setcolor(11);
  settextstyle(0,0,2);
  setcolor(4);
  outtextxy(20,14, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  outtextxy(20,15, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  outtextxy(20,16, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  outtextxy(20,17, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  setcolor(1);
  outtextxy(20,18, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  outtextxy(20,19, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  outtextxy(20,20, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  setcolor(15);
  outtextxy(20,21, " SEGURIDAD  DEL SISTEMA OPERATIVO UNIX");
  delay(100);
  setcolor(3);
  settextstyle(0,0,2);
  outtextxy(205,105, " SUPERUSUARIO");
  setcolor(14);
  rectangle(260,140,360,220);
  setcolor(3);
  rectangle(275,155,340,200);
  setfillstyle(INTERLEAVE_FILL,3);
  floodfill(280,170,3);
  setcolor(0);
  line(260,220,290,250);
  line(360,220,390,250);
  line(290,250,390,250);
 // setfillstyle(INTERLEAVE_FILL,0);
//  floodfill(250,236,5);
  delay(250);
  setcolor(6);
  rectangle(70,240,140,290);
  setcolor(2);
  rectangle(85,255,125,275);
  setfillstyle(INTERLEAVE_FILL,7);
  floodfill(90,260,2);
  setcolor(7);
  line(70,290,90,310);
  line(140,290,160,310);
  line(90,310,160,310);
  setcolor(4);
  settextstyle(0,0,1);
  outtextxy(70,320, " USUARIO No.1");
  delay(300);
  setcolor(9);
  rectangle(490,240,560,290);
  setcolor(10);
  rectangle(505,255,545,275);
  setfillstyle(INTERLEAVE_FILL,7);
  floodfill(520,260,10);
  setcolor(12);
  line(490,290,520,310);
  line(560,290,590,310);
  line(520,310,590,310);
  setcolor(6);
  settextstyle(0,0,1);
  outtextxy(490,320, " USUARIO No.2");
  delay(400);
  setcolor(4);
  rectangle(330,290,385,335);
  setcolor(3);
  rectangle(340,300,375,325);
  setfillstyle(INTERLEAVE_FILL,7);
  floodfill(360,310,3);
  setcolor(1);
  line(330,335,350,355);
  line(385,335,405,355);
  line(405,355,350,355);
  setcolor(15);
  settextstyle(0,0,1);
  outtextxy(320,365, " USUARIO No.3");
  settextstyle(6,0,1);
  setcolor(2);
  outtextxy (200,420, "OPRIMA CUALQUIER TECLA PARA IR  AL MENU USUARIOS");
  getch();
  cleardevice();
    do
     {
       cleardevice();
       setbkcolor(WHITE);
       rectangle(0,0,650,480);
       setcolor(4);
      // settextstyle(0,0,2);
      // outtextxy(45,20," SEGURIDAD SISTEMA OPERATIVO UNIX   ");
       setcolor(3);
       rectangle(100,90,530,460);
       setfillstyle(SOLID_FILL,CYAN);
       floodfill(102,440,3);
       setcolor(14);
       settextstyle(0,0,2);
       outtextxy(180,105," MENU  DE  USUARIOS  ");
       setcolor(1);
       settextstyle(6,0,2);
       outtextxy(180,190,"1.- SUPERUSUARIO ");
       settextstyle(6, 0,2);
       outtextxy(180,220,"2.- USUARIO1  ");
       outtextxy(180,260,"3.- USUARIO2  ");
       outtextxy(180,300,"4.- USUARIO3  ");
       outtextxy(180,340,"5.- SALIR menu principal");
       outtextxy(265,370, "   ESCOJA SU OPCION [  ] ");
       gotoxy(60,25);scanf("%d",&op);

  switch(op)
	{
	    case  1 :  superusuario();
		      break;
	    case  2 : usuario1();
		      break;
	    case  3:  usuario2();
		      break;
	    case 4:  usuario3();
		      break;
	    case 5 :  menu();
		      break;
	   }
    }while(op < 5 );

     }


  void superusuario()
  {
  cleardevice();
  setcolor(2);
  setfillstyle(INTERLEAVE_FILL,7);
  floodfill(2,12,2);
  delay(200);
  setcolor(2);
  settextstyle(0,0,2);
  outtextxy(10,30,"GENERACION DE LOS PROCESOS DEL SISTEMA ");
  setcolor(5);
  delay(60);
  circle(300,100,30);
  setcolor(6);
  settextstyle(6,0,1);
  outtextxy(285,80,"boot ");
  setcolor(2);
  line(300,130,300,160);
  delay(200);
  setcolor(9);
  rectangle(260,160,340,180);
  setcolor(6);
  settextstyle(6,0,1);
  outtextxy(270,150,"swapper ");
  setcolor(2);
  line(300,180,300,200);
  setcolor(9);
  delay(120);
  rectangle(260,200,340,220);
  setcolor(6);
  outtextxy(285,195,"init");
  setcolor(2);
  line(300,220,250,240);
  setcolor(9);
  delay(150);
  rectangle(200,240,260,260);
  setcolor(6);
  settextstyle(1,0,2);
  outtextxy(210,240,"getty");
  setcolor(2);
  line(230,260,230,280);
  setcolor(9);
  delay(170);
  rectangle(200,280,260,300);
  setcolor(6);
  outtextxy(210,280,"login");
  setcolor(2);
  line(230,300,230,320);
  setcolor(9);
  delay(200);
  rectangle(200,320,260,340);
  setcolor(6);
  outtextxy(220,310,"sh"); //linea derecha//
  setcolor(2);
  line(300,220,350,240);
  setcolor(9);
  rectangle(340,240,400,260);
  setcolor(6);
  outtextxy(350,240,"getty");
  setcolor(2);
  line(375,260,375,280);
  setcolor(9);
  rectangle(340,280,400,300);
  setcolor(6);
  outtextxy(350,280,"login");
  setcolor(2);
  line(375,300,375,320);
  setcolor(9);
  rectangle(340,320,400,340);
  setcolor(6);
  outtextxy(350,320,"sh");
  setcolor(9);
  outtextxy(240,200,"0");
  outtextxy(360,200,"1");

  outtextxy(170,240,"1");
  outtextxy(170,280,"1");
  outtextxy(170,330,"1");
  outtextxy(420,240,"101");
  outtextxy(420,280,"101");
  outtextxy(420,330,"101");
  outtextxy(265,240,"100");
  outtextxy(265,280,"100");
  outtextxy(265,330,"100");
  outtextxy(330,240,"1");
  outtextxy(330,280,"1");
  outtextxy(330,330,"1");
  delay(4000);
  cleardevice();
  setbkcolor(BLACK);
  setcolor(9);
  rectangle(0,0,640,470);
  setcolor(2);
  settextstyle(1,0,3);
  outtextxy(30,10,  "SUPERUSUARIO ENCARGADO DE LA SEGURIDAD TOTAL ");
  setcolor(9);
  rectangle(120,60,540,340);
  setfillstyle(INTERLEAVE_FILL,15);
  floodfill(150,136,9);
  setcolor(7);
  rectangle(140,80,520,300);
  setfillstyle(INTERLEAVE_FILL,1);
  floodfill(150,136,7);
  setcolor(7);
  line(120,340,200,420);
  line(540,340,620,420);
  line(200,420,620,420);
  settextstyle(6,0,1);
  setcolor(15);
  settextstyle(6,0,1);
  outtextxy(160,100, "login : ");
  settextstyle(6,0,1);
  outtextxy(160,120, "paswd : ");
  settextstyle(6,0,1);
  outtextxy(160,150, "$ :    ls  ");
  setcolor(3);
  rectangle(10,60,110,350);
  setfillstyle(1,3);
  floodfill(15,136,3);
  setcolor(0);
  outtextxy(12,70, "La clave de ");
  settextstyle(6,0,1);
  outtextxy(12,90,"acceso al");
  settextstyle(6,0,1);
  outtextxy(12,110,"programa es ");
  settextstyle(6,0,1);
  outtextxy(12,130, "programador ");
  settextstyle(6,0,1);
  outtextxy(12,150," ");
  delay (3000);
  cleardevice();
  setbkcolor(0);
  setcolor(2);
  rectangle(40,80,590,230);
  setfillstyle(INTERLEAVE_FILL,BLUE);
  floodfill(45,200,GREEN);
  setcolor(4);
  settextstyle(0,0,3);
  outtextxy (80,30, "CREACION DE PROCESOS");
  setcolor(8);
  settextstyle(1,0,1);
  outtextxy(60,100,"UID");
  setcolor(15);
  settextstyle(2,0,6);
  outtextxy(60,120,"root");
  outtextxy(60,140,"root");
  outtextxy(60,160,"root");
  outtextxy(60,180,"juan");
  outtextxy(60,200,"prico");
  settextstyle(2,0,6);
  setcolor(15);
  outtextxy(120,120,"  0");
  outtextxy(120,140,"  1");
  outtextxy(120,160,"285");
  outtextxy(120,180,"375");
  outtextxy(120,200,"394");
  delay(1200);
  setcolor(8);
  settextstyle(1,0,1);
  outtextxy(120,100,"PID");
  outtextxy(180,100,"PPID");
  outtextxy(240,100,"C");
  outtextxy(280,100,"STIME  TTY");
  outtextxy(390,100,"TIME COMMAND");
  delay(1400);
  setcolor(15);
  outtextxy(180,120," 0");
  outtextxy(180,140," 0 ");
  outtextxy(180,160," 1 ");
  outtextxy(180,180," 1 ");
  outtextxy(180,200," 1 ");
  delay(1700);
  settextstyle(2,0,6);
  setcolor(15);
  outtextxy(220,120,"  0");
  outtextxy(220,140,"  0");
  outtextxy(220,160,"  3");
  outtextxy(220,180,"  0");
  outtextxy(220,200,"  0");
  outtextxy(290,120,"Aug 24   ? ");
  outtextxy(290,140,"Aug 24   ?");
  outtextxy(290,160,"12:22:34 01");
  outtextxy(290,180,"12:43:57 02");
  outtextxy(290,200,"12:47:03 03 ");
  delay(1000);
  setcolor(2);
  settextstyle(2,0,6);
  setcolor(15);
  outtextxy(390,120," 0:00 swapper");
  outtextxy(390,140," 0:26 /etc/init");
  outtextxy(390,160," 0:04 -ksh");
  outtextxy(390,180," 0:09 /bin");
  outtextxy(390,200," 0;01 -sh");
  setcolor(13);
  settextstyle(6,0,1);
  outtextxy (100,440, "OPRIMA CUALQUIER TECLA PARA IR  AL MENU USUARIOS");
  getch();


   }
   void usuario1()
   {
  cleardevice();
  //setbkcolor(0);
  setcolor(1);
  rectangle(0,0,640,470);
  setfillstyle(INTERLEAVE_FILL,7);
  floodfill(50,200,1);
  setcolor(11);
  settextstyle(0,0,5);
  outtextxy(150,10,  "USUARIO1  ");
  setcolor(15);
  rectangle(120,60,540,340);
  setfillstyle(1,0);
  floodfill(135,90,15);
  setcolor(11);
  rectangle(140,80,520,300);
  setfillstyle(SOLID_FILL,1);
  floodfill(150,90,11);
  setcolor(4);
  line(120,340,200,420);
  line(540,340,620,420);
  line(200,420,620,420);
  setcolor(15);
  settextstyle(6,0,1);
  outtextxy(160,100, "login : usuario ");
  settextstyle(6,0,1);
  outtextxy(160,120, "paswd :  estad0 ");
  settextstyle(6,0,1);
  outtextxy(160,150, "$ : ls  ");
  setcolor(2);
  rectangle(10,60,110,350);
  setfillstyle(1,3);
  floodfill(15,90,2);
  setcolor(15);
  outtextxy(12,70, "La clave de ");
  settextstyle(6,0,1);
  outtextxy(12,90,"acceso del");
  settextstyle(6,0,1);
  outtextxy(12,110,"usuario1 es ");
  settextstyle(6,0,1);
  outtextxy(12,130, "est0d0 ");
  delay (2000);
  cleardevice();
  setcolor(4);
  settextstyle(0,0,4);
  outtextxy(50,20, "SISTEMA DE FICHERO ");
  setcolor(4);
  rectangle(0,0,690,470);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(350,200,4);
  delay(100);
  setcolor(2);
  line(20,200,230,200);
  line(20,200,120,120);
  line(230,200,120,120);
  delay(200);
  setcolor(4);
  line(70,200,30,260);
  line(70,200,110,260);
  line(30,260,110,260);
  line(170,200,130,260);
  line(170,200,210,260);
  line(130,260,210,260);
  delay(300);
  setcolor(8);
  line(55,260,20,290);
  line(55,260,85,290);
  line(20,290,85,290);
  line(170,260,120,290);
  line(170,260,210,290);
  line(120,290,210,290);
  delay(250);
  setcolor(4);
  settextstyle(6,0,1);
  outtextxy(30,100,"disco0 ");
  settextstyle(6,0,1);
  outtextxy(170,100, "root file system ");
  settextstyle(6,0,1);
  outtextxy(160,120, "sistema de fichero raiz ");
  settextstyle(6,0,1);
  outtextxy(20,230, "directorio3 ");
  settextstyle(6,0,1);
  outtextxy(170,230, "directorio4 ");
  delay(2500);
  setcolor(1);
  rectangle(340,100,650,320);
  setfillstyle(SOLID_FILL,CYAN);
  floodfill(350,200,1);
  setcolor(1);
  rectangle(0,0,690,470);
  setfillstyle(SOLID_FILL,CYAN);
  floodfill(350,200,1);

  setcolor(15);
  outtextxy(360,120, "/bin  comandos de usuario ");
  outtextxy(360,140, "/dev  dispositivo ");
  outtextxy(360,160, "/lib  bibliotecas parael compilador c");
  outtextxy(360,180, " tmp  ficheros temporales ");
  outtextxy(360,200, " usr  informacion relacionada con");
  outtextxy(360,220,"        aplicaciones temporales  ");
  outtextxy(360,240, " usr/bin mas comandos de ususario ");
  outtextxy(360,260, " usr/lib bibliotecas de comandos ");
  setcolor(0);
  settextstyle(6,0,1);
  outtextxy (250,430, "OPRIMA CUALQUIER TECLA PARA IR  AL MENU USUARIOS");
  getch();


   }
   void usuario2()
   {
   cleardevice();
   cleardevice();
  setbkcolor(BLACK);
  setcolor(14);
  rectangle(0,0,640,470);
  setcolor(3);
  settextstyle(0,0,5);
  outtextxy(160,15,  "USUARIO2 ");
  setcolor(0);
  rectangle(120,60,540,340);
  setcolor(1);
  rectangle(140,80,520,300);
  setcolor(4);
  line(120,340,200,420);
  line(540,340,620,420);
  line(200,420,620,420);
  settextstyle(6,0,1);
  setcolor(3);
  settextstyle(6,0,1);
  outtextxy(160,100, "login : ");
  settextstyle(6,0,1);
  outtextxy(160,120, "paswd : ");
  settextstyle(6,0,1);
  outtextxy(160,150, "$ : ");
  setcolor(14);
  rectangle(10,60,110,350);
  setcolor(12);
  outtextxy(12,70, "La clave de ");
  settextstyle(6,0,1);
  outtextxy(12,90,"acceso del");
  settextstyle(6,0,1);
  outtextxy(12,110,"usuario2 es ");
  settextstyle(6,0,1);
  outtextxy(12,130, "programar ");
  settextstyle(6,0,1);
  outtextxy(12,150," ");
  setcolor(5);
  settextstyle(6,0,1);
  outtextxy (130,440, "OPRIMA CUALQUIER TECLA PARA IR  AL MENU USUARIOS");
  getch();


   }
   void usuario3()
   {
  cleardevice();
  setbkcolor(BLACK);
  setcolor(12);
  rectangle(0,0,640,470);
  setcolor(13);
  settextstyle(0,0,5);
  outtextxy(150,10,  "USUARIO3 ");
  setcolor(9);
  rectangle(120,60,540,340);
  setcolor(11);
  rectangle(140,80,520,300);
  setcolor(2);
  line(120,340,200,420);
  line(540,340,620,420);
  line(200,420,620,420);
  settextstyle(6,0,1);
  setcolor(15);
  settextstyle(6,0,1);
  outtextxy(160,100, "login : ");
  settextstyle(6,0,1);
  outtextxy(160,120, "paswd : ");
  settextstyle(6,0,1);
  outtextxy(160,150, "$ : ");
  setcolor(3);
  rectangle(10,60,110,350);
  outtextxy(12,70, "La clave de ");
  settextstyle(6,0,1);
  outtextxy(12,90,"acceso del");
  settextstyle(6,0,1);
  outtextxy(12,110,"usuario es ");
  settextstyle(6,0,1);
  outtextxy(12,130, "salon ");
  settextstyle(6,0,1);
  outtextxy(12,150," ");
  setcolor(14);
  settextstyle(6,0,1);
  outtextxy (170,440, "OPRIMA CUALQUIER TECLA PARA IR  AL MENU USUARIOS");
  getch();

   }

 /*/****************************************************/
 /* FINCION QUE MUESTRA LA SIMULACION EN EL PROGRAMA   */
 /******************************************************/

  void simula (void)
  {
FILE *p;
struct user us;
char login[14],clav[10],orden[30];
int sw=0,or=0;
clrscr();
while(sw==0)
{if ((p = fopen("usuarios", "wd"))== NULL)
       exit(1);
gotoxy(5,6);printf("login:\n ");
scanf("%s",&login);
fread(&us,sizeof(us),1,p);
while(!feof(p)&&!strcmp(us.id,login))
fread(&us,sizeof(us),1,p);
if(!strcmp(us.id,login))
  {fclose(p);
  gotoxy(5,8); printf("passw:\n  ");
  fflush(stdin);
   scanf("%s",&clav);
  if(!strcmp(us.clave,clav))
    {clrscr();
    printf(" $");
     sw=1;
     getch();
     }
    }
else
{  printf("passw:\n");
   getch();
   printf("error ");
   }

   } //hasta aqui primera linea de seguridad
while(strcmp(orden,"logout"))
{
scanf("%s",&orden);
if(!strcmp(orden,"paswd")) ///esta parte cambiarla por una funcion que deternine el comando y deacuerdo a este le asigne un numero
  or=1;
switch(or)
{
case 1: cambiarc(us.id,us.clave);break;
}
}
}


void cambiarc(char *i,char *cl)
{
printf(".");
  clrscr ();
  gotoxy (30,20);
  printf ("<< salir de la simulacion >>");
  getch ();
}

