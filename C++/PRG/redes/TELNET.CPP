/* ESTE PROGRAMA FUE REALIZADO POR:
   ZORAIDA BEJARANO AGUILAR   Cod. 493246
   SOL MILENA CONTENTO A.     Cod. 493258
   LUVIER YESID FORERO	      Cod. 492998
*/
#include <bios.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <ctype.h>
#include <graphics.h>
#define COM1       1
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
#define SETTINGS (_COM_9600 | _COM_CHR8 | _COM_STOP1 | _COM_NOPARITY)
int acceso();
int fondo();
int presentacion();
int trans_archivo();
void trans_texto();
void inigra();
void mover(int);
void mova();
void movb();
void menu();
int t=1,y=100;
char *op[3]={"TRANSMISION DE TEXTO","TRANSMISION DE ARCHIVO","SALIR"};

void main(void)
{
  int c,e=0;
  inigra();
  fondo();
  presentacion();

  _bios_serialcom(_COM_INIT, COM1, SETTINGS);
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
	 {
	  case 1: closegraph();trans_texto();inigra(); menu();
		  break;
	  case 2: closegraph();trans_archivo();inigra(); menu();
		  break;
	  case 3: closegraph(); exit(1);
	 }
	}
}
/*FUNCION QUE TRANSMITE TEXTO*/

void trans_texto()
{
   unsigned in, out, status;
   int x=1,y=1,a=1,b=12,i;
   for (;;)
   {
    status = _bios_serialcom(_COM_STATUS, COM1, 0);
    if (status & DATA_READY)
      if ((out = _bios_serialcom(_COM_RECEIVE, COM1, 0) & 0x7F) != 0)
	{
	 _bios_serialcom(_COM_SEND, COM1, '@');
	 if(out=='\x1B')
	   {printf("comunicacion terminada");
	    getch();
	    break;
	    }
	 if(out!='@')
	   {gotoxy(x,y);
	    putch(out);
	    x++;
	   }
	 if(x==80)
	   {y++;
	    x=1;
	    }
	  if(y==11)
	    {
	      for(i=1;i<=11;i++)
		{
		 gotoxy(1,i);
		 clreol();
		}
	     x=1;
	     y=1;
	    }
	    }
      if (kbhit())
      {
	if ((in = getch()) == '\x1B')
	{
	 _bios_serialcom(_COM_SEND, COM1,in);
	 break;
	}
       gotoxy(a,b);
       printf("%c",in);
       a++;
       if(a==80)
	{
	 a=1;
	 b++;
	}
       if(b==24)
	{
	 for(i=12;i<=24;i++)
	    {
	     gotoxy(1,i);clreol();
	    }
	  a=1;
	  b=12;
	}
      _bios_serialcom(_COM_SEND, COM1, in);
    }
  }
}

/*FUNCION QUE TRANSMITE ARCHIVOS*/
int trans_archivo()
{
  FILE *fp;
  char noma[30],l;
  unsigned out,status;
  char in;
  printf("digite nombre de archivo a transmitir");
  scanf("%s",noma);
  if ((fp = fopen(noma, "r"))== NULL)
   {
     fprintf(stderr, "Cannot open input file.\n");
     return 1;
   }
  fread(&in,sizeof(in),1,fp);
  while(!feof(fp))
  {
   _bios_serialcom(_COM_SEND, COM1,in);
   status = _bios_serialcom(_COM_STATUS, COM1, 0);
   if (status & DATA_READY)
   if ((out = _bios_serialcom(_COM_RECEIVE, COM1, 0) & 0x7F) != 0)
   _bios_serialcom(_COM_SEND, COM1, '@');
	 fread(&in,sizeof(in),1,fp);
  }
  fclose(fp);
}


/*FUNCION QUE INICIALIZA EL MODO GRAFICO*/
void inigra()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics mode */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();

   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);             /* return with error code */
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
     setcolor(14);
     outtextxy(130,100,op[0]);
     setcolor(13);
     outtextxy(130,250,op[2]);
     t=3;
     y=250;
   }
 else
   {
    setcolor(14);
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

/*FUNCION QUE MUESTRA MENU PRINCIPAL*/
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
   outtextxy(130,100,"TRANSMISION DE TEXTO");
   setcolor(14);
   outtextxy(130,175,"TRANSMISION DE ARCHIVO");
   outtextxy(130,250,"SALIR");
   settextstyle(1,0,5);
   setcolor(10);
   outtextxy(100,400,"TRANSMISION SERIAL");
   t=1;
    setcolor(3);
   settextstyle(3,0,4);
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
 }
 }
 }