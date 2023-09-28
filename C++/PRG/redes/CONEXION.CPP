#include <bios.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <ctype.h>
#include <graphics.h>
#include <string.h>

#define COM1       0
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
#define SETTINGS (_COM_9600 | _COM_CHR8 | _COM_STOP1 | _COM_NOPARITY)

void acceso(void);
void presentacion(void);
int  trans_archivo(void);
void trans_texto(void);
void inigra(void);
void mover(int);
void mova(void);
void movb(void);
void menu(void);
void cuadro(void);
void cuadro1(int, int, int, int);
int  recep_arch(void);

int t=1,y=200;
char *op[3]={"TRANSMISION DE TEXTO","TRANSMISION DE ARCHIVO","SALIR"};

void main(void)
{
 int c,e=0;
 unsigned a=0;
 char ai;
 inigra();
 acceso();
 presentacion();
 bioscom(0,SETTINGS,COM1);
 _bios_serialcom(_COM_INIT, COM1, SETTINGS);
 menu();
 int i;
 while(1)
   {
    c = getch();
    if(!c)
      {
       e = getch();
       mover(e);
      }
    if(a==1)
      {
       closegraph();
       a=0;
       recep_arch();
       inigra();
       menu();
      }
    if(c==13)
      switch(t)
       {
	case 1: closegraph();cuadro();trans_texto();inigra(); menu();
		break;
	case 2: closegraph();trans_archivo(); inigra();menu();
		break;
	case 3: //closegraph();
		exit(1);
       }
   }
}

void acceso()
{
 char clav[7],clav1[8];
 int j,i,wt,wt2,wt3;
 setbkcolor(BLUE);
 clav1[0]='g';
 clav1[1]='r';
 clav1[2]='u';
 clav1[3]='p';
 clav1[4]='o';
 clav1[5]=' ';
 clav1[6]='4';
 clav1[7]='6';
 j=4;
 wt3=0;
 setcolor(YELLOW);
 rectangle(0,0,639,479);
 rectangle(4,4,635,475);
 setcolor(8);
 settextstyle(4,0,5);
 outtextxy(230,30," U.A.N ");
 settextstyle(4,0,4);
 outtextxy(150,80,"  TRANSMISION  ");
 setcolor(15);
 settextstyle(4,0,5);
 outtextxy(232,32," U.A.N ");
 settextstyle(4,0,4);
 outtextxy(152,82,"  TRANSMISION  ");
 settextstyle(1,0,4);
 do{
   j++;
   setcolor(j);
   wt=1;
   wt2=1;
   outtextxy(110,150,"Teclee su clave de acceso.");
   rectangle(240,200,370,230);
   setcolor(j+1);
   for(i=0;i<=7;i++)
     {
      clav[i]=getch();
      sound(300);
      delay(50);
      nosound();
      outtextxy(260+i*12,202,"*");
     }
   for(i=0;i<=7;i++)
     {
      if(tolower(clav[i])!=clav1[i])
	wt=0;
     }
   if(wt==0)
     {
      setcolor(j+2);
      wt2=0;
      wt3++;
      outtextxy(160,310,"!!! CLAVE ERRADA !!!");
      outtextxy(160,360,"INTENTE DE NUEVO");
     }
   if(wt3==3)
     {
      cleardevice();
      setcolor(4);
      outtextxy(175,360,"!! INTRUSO !!");
      for(j=0;j<6;j++)
       for(i=200;i<=900;i+=20)
	{
	 sound(i);
	 delay(20);
	 nosound();
	}
      closegraph();
      exit(1);
     }
 }while(wt2==0);
 setcolor(1);
 setfillstyle(1,1);
 bar(150,300,600,400);
 floodfill(151,301,1);
 setcolor(j);
 outtextxy(170,380,"ACCESO PERMITIDO");
 delay(2700);
 clearviewport();
}

void trans_texto(void)
{
 int in, out, status, DONE = FALSE;
 int c=3,f=3,c1=3,f1=13;
 while (!DONE)
  {
   status = bioscom(3, 0, COM1);
   if(status & DATA_READY)
    if((out = bioscom(2, 0, COM1) & 0xFF) != 0)
       if(out!='\x9')
	 {
	  gotoxy(c,f);
	  printf("%c",out);
	  c++;
	 }
       if(c==78 || out == '\xD')
	 {
	  c=3;
	  f++;
	  gotoxy(c,f);
	  clreol();
	  gotoxy(80,f);
	  printf("º");
	  out = 0;
	 }
       if(f==11)
	 {
	  f=3;
	  c=3;
	  gotoxy(c,f);
	  clreol();
	  gotoxy(80,f);
	  printf("º");
	 }
       if(out=='\x8')
	 {
	  if(c>2 && c!=4)
	    {
	     printf(" ");
	     c-=2;
	    }
	  else
	   c--;
	  out = 0;
	 }
       if(out == '\x1B')
	 DONE = TRUE;
   gotoxy(c1,f1);
   if(kbhit())
     {
      gotoxy(c1,f1);
      if(c1>2)
       {
	if((in = getch()) == '\x1B')
	  {
	   DONE = TRUE;
	   bioscom(1,in,COM1);
	  }
	if(in!='\x9')
	  {
	   putch(in);
	   c1++;
	  }
	if(c1==78 || in == '\xD')
	  {
	   c1=3;
	   f1++;
	   gotoxy(c1,f1);
	   clreol();
	   gotoxy(80,f1);
	   printf("º");
	  }
	if(f1==23)
	  {
	   f1=13;
	   c1=3;
	   gotoxy(c1,f1);
	   clreol();
	   gotoxy(80,f1);
	   printf("º");
	  }
	if(in=='\x8')
	  {
	   if(c1>2 && c1!=4)
	     {
	      printf(" ");
	      c1-=2;
	     }
	   else
	    c1--;
	  }
	bioscom(1, in, COM1);
       }
     }
  }
}

/*FUNCION QUE TRANSMITE ARCHIVOS*/
int trans_archivo()
{
 FILE *fp;
 int i = 0;
 char noma[30],l;
 unsigned status;
 char in;
 clrscr();
 printf("(E)nvia o (R)ecibe datos ?  [ ]");
 do{
 gotoxy(30,1);
 l = tolower(getch());
 }while(l!='r' && l!='e');
 clrscr();
 if(l=='r')
   {
    recep_arch();
    return 1;
   }
 cuadro1(1,1,79,3);
 gotoxy(2,2);
 cprintf("DIGITE EL NOMBRE DEL ARCHIVO A TRANSMITIR: ");
 scanf("%s",noma);
 if((fp = fopen(noma, "r"))== NULL)
     return 1;
 while(i < strlen(noma))
  {
   bioscom(1,noma[i],COM1);
   i++;
  }
 bioscom(1,'@',COM1);
 cuadro1(1,11,80,13);
 gotoxy(5,12);
 printf("ENVIANDO ARCHIVO - %s -",noma);
 fread(&in,sizeof(in),1,fp);
 while(!feof(fp))
  {
   _bios_serialcom(_COM_SEND, COM1,in);
   fread(&in,sizeof(in),1,fp);
   delay(20);
  }
 fclose(fp);

 gotoxy(10,23);
 printf("ARCHIVO ENVIADO... <Presione cualquier tecla...>");
 getch();

 return 0;
}

int recep_arch(void)
{
 FILE *fp;
 unsigned out=0,status,i=0;
 char nombre[50];

 cuadro1(1,1,80,3);
 gotoxy(25,2);
 printf("MODULO DE RECEPCION DE ARCHIVO");

 while(out!='@')
  {
   status = bioscom(3,0,COM1);
   if(status & DATA_READY)
     if((out = bioscom(2,0,COM1) & 0xFF) != 0)
       {
	if(out!='@')
	  {
	   nombre[i] = out;
	   i++;
	  }
       }
  }
 nombre[i] = '\0';

 cuadro1(1,5,80,7);
 gotoxy(2,6);
 printf("NOMBRE DEL ARCHIVO : - %s -",nombre);

 remove(nombre);
 if((fp = fopen(nombre,"w"))== NULL)
    return 1;

 cuadro1(1,10,39,12);
 gotoxy(2,11);
 printf("RECIBIENDO EL CARACTER");
 cuadro1(41,10,50,12);

 cuadro1(1,15,39,17);
 gotoxy(2,16);
 printf("RECIBIENDO EL CARACTER NUMERO");
 cuadro1(41,15,50,17);

 out = 0;

 while(out!='@')
  {
   status = bioscom(3, 0, COM1);
   if(status & DATA_READY)
     if((out = bioscom(2, 0, COM1) & 0xFF) != 0)
       {
	if(out!='@')
	  {
	   gotoxy(45,11);
	   printf("%c",out);
	   gotoxy(45,16);
	   printf("%d",i);
	   i++;
	   fputc(out,fp);
	  }
       }
  }
 fclose(fp);
 gotoxy(10,23);
 printf("ARCHIVO RECIBIDO... <Presione cualquier tecla...>");
 getch();
 return 0;
}



void inigra()
{
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "");
 errorcode = graphresult();
 if(errorcode != grOk)
   {
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1);
   }
}

/*FUNCION QUE IDENTIFICA LAS TECLAS PULSADAS*/
void mover(int e)
{
 switch(e)
  {
   case 72: mova();break;
   case 80: movb();break;
  }
}

/*FUNCION QUE ACTIVA LA FUNCION A EJECUTARSE*/
void mova()
{
 if(t==1)
   {
    setcolor(8);
    outtextxy(130,200,op[0]);
    setcolor(5);
    outtextxy(130,300,op[2]);
    t=3;
    y=300;
   }
 else
   {
    setcolor(8);
    outtextxy(130,y,op[t-1]);
    t--;
    setcolor(5);
    y-=50;
    outtextxy(130,y,op[t-1]);
   }
}

void movb()
{
 if(t==3)
   {
    setcolor(8);
    outtextxy(130,300,op[2]);
    setcolor(5);
    outtextxy(130,200,op[0]);
    t=1;
    y=200;
   }
  else
   {
    setcolor(8);
    outtextxy(130,y,op[t-1]);
    t++;
    setcolor(5);
    y+=50;
    outtextxy(130,y,op[t-1]);
   }
}

/*FUNCION QUE MUESTRA MENU PRINCIPAL*/
void menu()
{
 cleardevice();
 setbkcolor(0);
 setfillstyle(1,7);
 floodfill(2,5,7);
 setcolor(1);
 rectangle(1,1,638,478);
 rectangle(5,5,633,473);
 setcolor(8);
 settextstyle(4,0,6);
 outtextxy(110,50,"MENU PRICIPAL");
 setcolor(1);
 outtextxy(112,52,"MENU PRICIPAL");
 setcolor(2);
 rectangle(100,160,540,360);
 rectangle(101,161,541,361);
 setcolor(5);
 settextstyle(0,0,2);
 outtextxy(130,200,"TRANSMISION DE TEXTO");
 setcolor(8);
 outtextxy(130,250,"TRANSMISION DE ARCHIVO");
 outtextxy(130,300,"SALIR");
 settextstyle(1,0,5);
 t=1;
 y=200;
 setcolor(5);
 settextstyle(0,0,2);
}

void presentacion()
{
 cleardevice();
 setbkcolor(1);
 setcolor(14);
 rectangle(0,0,639,479);
 rectangle(2,2,637,477);
 rectangle(4,4,635,475);
 setcolor(7);
 settextstyle(11,0,2);
 outtextxy(310,465,"PULSE CUALQUIER TECLA PARA CONTINUAR...");
 setcolor(11);
 settextstyle(4,0,5);
 outtextxy(30,10,"REDES DE COMUNICACION");
 setcolor(15);
 settextstyle(7,0,5);
 outtextxy(60,100,"COMUNICACION SERIAL");
 setcolor(4);
 settextstyle(1,0,3);
 outtextxy(110,250,"CESAR FONSECA B.     COD: 493368");
 outtextxy(110,280,"ANDREA CELIS C.       COD: 493360");
 outtextxy(110,310,"SILVANO URREGO R.    COD: 493386");
 outtextxy(110,340,"SONIA RODRIGUEZ M.   COD: 493370");
 outtextxy(110,370,"GUSTAVO FERRUCHO S. COD: 493234");
 getch();
}

void cuadro(void)
{
 int i,aux;
 for(i=2;i<=23;i++)
  {
   gotoxy(1,i);
   printf("º");
   gotoxy(80,i);
   printf("º");
  }
 for(i=2;i<=79;i++)
  {
   gotoxy(i,1);
   printf("Í");
   gotoxy(i,24);
   printf("Í");
   gotoxy(i,12);
   printf("Í");
  }
 aux=strlen(" SERVIDOR ");
 aux = (80 - aux) / 2;
 gotoxy(aux,12);
 printf(" SERVIDOR ");
 aux=strlen(" TERMINAL ");
 aux = (80 - aux) / 2;
 gotoxy(aux,1);
 printf(" TERMINAL ");

 gotoxy(1,1);
 printf("É");
 gotoxy(1,24);
 printf("È");
 gotoxy(80,1);
 printf("»");
 gotoxy(80,24);
 printf("¼");
 gotoxy(1,12);
 printf("Ì");
 gotoxy(80,12);
 printf("¹");
}

void cuadro1(int x,int y, int xf, int yf)
{
 int i;
 for(i=y;i<=yf;i++)
  {
   gotoxy(x,i);
   printf("º");
   gotoxy(xf,i);
   printf("º");
  }
 for(i=x;i<=xf;i++)
  {
   gotoxy(i,y);
   printf("Í");
   gotoxy(i,yf);
   printf("Í");
  }
 gotoxy(x,y);
 printf("É");
 gotoxy(x,yf);
 printf("È");
 gotoxy(xf,y);
 printf("»");
 gotoxy(xf,yf);
 printf("¼");
}


