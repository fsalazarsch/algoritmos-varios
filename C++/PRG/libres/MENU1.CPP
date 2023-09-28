	     #include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "iomanip.h"
#include "conio.h"
#include "io.h"
#include "dos.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#define escribir(i){cprintf("%s",vec[i]);}
#define mensa(men){printf("%s",men);};
#define go {gotoxy(1,24);}
#define ENTER 13

inline void colores(int x, int y){textcolor(x);textbackground(y);}
inline void pos (int x,int y){gotoxy(y,x);}
static char vec[6][13]={"CAPTURA","ELIMINA","CONSULTA","VISUALIZAR","VENTAS","SALIR"};
/*********************************************************************************/
int rr;
struct comprart{
    char referencia[8];
    char articulo[45];
    int cantidad;
    float costo;
    comprart *sig;
   };
struct ventart{
    char referencia[8];
    int cantidad;
    float costoventa;
    ventart *sig;
    };

class compra
{
   struct comprart *cab,*q,*tm,*z,*p,*r;
   struct ventart *cab1,*q1,*tm1,*z1,*p1,*r1;
  public:
    compra(){cab=q=tm=z=p=r=NULL;}
    ~compra();
    void adicionar();
    void ordenar();
    void eliminar();
    void consultar();
    void visualizar();
    void cap_artic(char nom[],int x,int y,int ancho,int *tec);
    void capcod(char codigo[],int x,int y ,int ancho);
    void vender();
 };
int sw=0,sw1=0,canven=0,cancomp=0,elim=0,existe=0;
char c1[]="³",c2[]="Ä",c3[]="Ú",c4[]="Ù",c5[]="¿",c6[]="À";
char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È";
void boli(int fi,int ff,int ci,int cf)
{ int i,j;
  for(i=fi;i<=ff;i++)
  { for(j=ci;j<=cf;j++)
   { gotoxy(j,i);cprintf(" ");}}
}
void centraM(char men[],int f)
{ int lon,col;
  lon=strlen(men);
  col=(80-lon)/2;
  gotoxy(col,f);cprintf("%s",men);
}

void cuadro(int x1, int y1, int x2, int y2, char a1[],char a2[],char a3[],char a4[],char a5[],char a6[])
{  int i;
     for(i=x1;i<=x2;i++)
     { gotoxy(y1,i);cprintf(a1);
       gotoxy(y2,i);cprintf(a1);}
     for(i=y1;i<=y2;i++)
     { gotoxy(i,x1);cprintf(a2);
       gotoxy(i,x2);cprintf(a2);}
       gotoxy(y1,x1);cprintf(a3);
       gotoxy(y2,x2);cprintf(a4);
       gotoxy(y2,x1);cprintf(a5);
       gotoxy(y1,x2);cprintf(a6);
}

void piso()
{ int u;
  for (u=5;u<23;u++)
   { gotoxy(3,u);
     textcolor(1);
     cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   }
}

menuH(int f)
{ int i, r,j1=f;
  char tecla;
  do
  { r=2;
   textbackground(0);
 /* clrscr();*/
   for(i=0;i<6;i++)
     { if (i==j1)
      { textcolor(1);
	textbackground(7);
	gotoxy(2+r,4);escribir(i);
	}
      else
	{ textcolor(0);textbackground(11);
	  gotoxy(2+r,4);escribir(i);}
	r+=13;
	textcolor(3);
      }
       switch(j1)
	{ case 0:go;mensa("modulo para la adicion de clientes  ");
		 break;
	  case 1:go;mensa("Modulo para la eliminacion clientes");
		 break;
	  case 2:go;mensa("Modulo para la consulta de cliente  ");
		 break;
	  case 3:go;mensa("Modulo para  visualizar los clientes");
		 break;
	  case 4:go;mensa("modulo para la venta de articulo    ");
		 break;
	  case 5:go;mensa("Modulo para salir de la aplicacion  ");
		 break;
      }

      tecla=getch();

	if (tecla==77 )
	{  if (j1<5)
	    j1++;
	   else
	    j1=0;
	}

	 if (tecla==75)
	   { if (j1!=0)
	      j1--;
	     else
	      j1=5;
	   }
  }
  while (tecla!=ENTER);
  return(j1);
 }
void compra::cap_artic(char nom[],int x,int y,int ancho,int *tec)
{
  int c,nu,i=0;
  char car1;
  c=x;
  gotoxy(c,y);
  do
  {
   do
    car1=toupper(getch());
    while ((car1 < 'A') && (car1 > 'Z') && (car1 != 32) &&
     (car1 != 13) && (car1 != 27));
     if ((((car1 >= 'A') && (car1 <= 'Z')) || (car1 == 32)) && (i < ancho))
      {
       gotoxy(c,y);
       c++;
       nom[i]=car1;
       i++;
       putch(car1);
      }
      else
       if ((car1 == 8) && (c != x))
       {
	i--;c--;
	gotoxy(c,y);
	putchar(32);
	gotoxy(c,y);
       }
      if ((car1 == 13) || (i == ancho))
	 nom[i]='\0';
   }while ((car1 != 13) && (car1 != 27));
   *tec=car1;
}
void compra::capcod(char codigo[],int x,int y ,int ancho)
{     char c =' ';
      int n_car=0;
      gotoxy(x,y);
      clreol();
      while (c!='\r' && n_car<ancho)
      {
	 c=getche();
	 if (!isdigit(c) && c!='\r')
	 {
	  gotoxy(x,y);//clreol();
	  n_car=0;
	 }
	 else
	 {
	  codigo[n_car]=c;
	  n_car++;
	 }
       }
       codigo[n_car]='\0';
}
void validar_numero(char h[20]){

    int i,lon;
    sw1=0;
    lon = strlen(h);
    for(i=0;i<lon;i++){
      if(isdigit(h[i])==0){
	sw1=1;
      }
    }
    if(h[0]=='\0')
       sw1=1;
}
void validar_numero_f(char h[20]){
    int i,lon;
    sw1=0;
    lon = strlen(h);
    for(i=0;i<lon;i++){
      if(isalpha(h[i])!=0){
	sw1=1;
      }
    }
    if(h[0]=='\0')
       sw1=1;
}
void compra::adicionar()
{  cab=p;
  int *tec;
  char op,n,c[37], refe[9],art[21],tem[10],tem2[10];
  int sw=0,cant=0;
  float cost=0;
  do{//1
       window(11,7,60,15);
       textcolor(15);
       textbackground(0);
       clrscr();
	gotoxy(10,1);cout<<" DIGITANDO ESTRUCTURA ";
	gotoxy(2,3);cout<<"Referancia...:";
	gotoxy(2,4);cout<<"Articulo.....:";
	gotoxy(2,5);cout<<"Cantidad.....:";
	gotoxy(2,6);cout<<"Costo........:";

	do{ capcod(refe,17,3,8);
	 tm=cab;
	 while(tm!=NULL)
	 {//2.1
	  if(strcmp(tm->referencia,refe)==0)
	  {gotoxy(2,9);cout<<" Codigo existente";
	   getch();
	   sw=1;break;}
	  else
	  {sw=0;tm=tm->sig;}
	 }//2.1
     }while(sw==1);//2
       do{cap_artic(art,17,4,20,tec);
	 tm=cab;
	 while(tm!=NULL)
	 {
	  if(strcmp(tm->articulo,art)==0)
	  {gotoxy(2,9);cout<<" Articulo existente";
	   getch();
	   sw=1;break;}
	  else
	  {sw=0;tm=tm->sig;}
	 }
      }while(sw==1);//2
     do
	{
	 gotoxy(17,5);gets(tem);
	 validar_numero(tem);
	 if(sw1==1)
	   boli(5,5,17,30);
	}while(sw1 != 0);
	cant= atoi(tem);
     do
      { sw1=0;
	 gotoxy(17,6);gets(tem2);
	 validar_numero_f(tem2);
	 if(sw1==1)
	   boli(6,6,17,30);
       }while(sw1 != 0);
	cost= atof(tem2);
	cancomp=cancomp+cant;
     p=new comprart;
     strcpy(p->referencia,refe);
     strcpy(p->articulo,art);
     p->cantidad=cant;
     p->costo=cost;
       if(cab==NULL)//3
	{cab=p;p->sig=NULL;}
       else
	{q=cab;cab=p;cab->sig=q;}//3
    gotoxy(2,9);cout<<"Desea Continuar s/n ";
    do{op=toupper(getch());
      }while ((op != 'S') && (op != 'N'));
  }while (op != 'N');//1
  window(1,1,80,24);
  existe=1;ordenar();


}
void compra::eliminar()
{
  char n,c[35],refe[10],op;
  window(11,7,60,15);
      textcolor(15);
       textbackground(0);
       clrscr();
do{
  if(cab==NULL)
  {

   gotoxy(6,2);cout<<"NO EXISTEN INFORMACION PARA ELIMINAR";
   gotoxy(6,3);cout<<"        << PRESIONE ENTER >>        ";
   getch();
   gotoxy(6,2);cout<<"                                    ";
   gotoxy(6,3);cout<<"                                    ";
   break;
  }
  else
  {    q=cab;r=q;
	   clrscr();
	    gotoxy(2,2);cout<<"Digite referencia..:";
	    capcod(refe,24,2,8);
	    while(elim==0 && q!=NULL)
	    {//2.1
	     if(strcmp(q->referencia,refe)==0)
	     {elim=1;}
	     else
	     {
	      r=q;q=q->sig;
	     }//fin si
	    }//fin mq
	     if (elim==1)
	     {   if(r==q && q->sig==NULL)
		   {
		    free(q);free(r);free(cab);cab=NULL;
		    gotoxy(3,5);cout<<"<<      E L I M I N A N D O    D A T O      >>";
		    delay(50);sound(100);sleep(1);nosound();
		   }
		   else
		   {if(r==q && q->sig!=NULL)
		     {
			cab=q->sig;
			q->sig=NULL;
			free(q);
			gotoxy(3,5);cout<<"<<      E L I M I N A N D O    D A T O      >>";
			delay(50);sound(100);sleep(2);nosound();
		       }
		       else
		       { if(r!=q && q->sig==NULL)
			   {
			    r->sig=NULL;
			    free(q);
			    gotoxy(3,5);cout<<"<<      E L I M I N A N D O    D A T O      >>";
			    delay(50);sound(100);sleep(2);nosound();
			   }
			   else
			   {
				r->sig=q->sig;
				free(q);
				gotoxy(3,5);cout<<"<<      E L I M I N A N D O    D A T O      >>";
				delay(50);sound(100);sleep(2);nosound();
			   }
			}
		   }elim=0;
	     }
	     else
	     {
	       gotoxy(5,4);cout<<" REFERENCIA NO EXISTENTE";
	       gotoxy(5,5);cout<<"    << Press Enter >>   ";
	       getch();
	       gotoxy(5,4);cout<<"                         ";
	       gotoxy(5,5);cout<<"                         ";
	      }
	     clrscr();
	     gotoxy(5,9);cout<<"Desea Continuar s/n ";
	     do{op=toupper(getche());
	       }while ((op != 'S') && (op != 'N'));
	}
       }while (op != 'N');//1
    window(1,1,80,25);
}
void compra::ordenar()
{int cant,cost;
 char refe[40],art[23],op;
 q=cab;
 while(q->sig !=NULL)
 {
   q=q->sig;
 }
 tm=cab;
 while(tm !=q)
 {
  z=tm->sig;
  while(z!=NULL)
  {
   if(strcmp(z->referencia,tm->referencia)<0)
   {
    strcpy(refe,tm->referencia);
    strcpy(tm->referencia,z->referencia);
    strcpy(z->referencia,refe);
    strcpy(art,tm->articulo);
    strcpy(tm->articulo,z->articulo);
    strcpy(z->articulo,art);
    cant=tm->cantidad;
    tm->cantidad=z->cantidad;
    z->cantidad=cant;
    cost=tm->costo;
    tm->costo=z->costo;
    z->costo=cost;
   }
   z=z->sig;
  }
  tm=tm->sig;
 }
}

void compra::consultar()
{
 int sw=0;
 char refe[8];
 int * tec;
 tm=cab;
       window(11,7,60,15);
       textcolor(15);
       textbackground(0);
       clrscr();
 gotoxy(5,1);cout<<" OBSERVANDO ESRTRUCTURA";
 tm=cab;
 if(tm==NULL)
 {
  gotoxy(5,5);cout<<"NO EXISTE  LISTA ";
  gotoxy(5,6);cout<<"ENTER PARA SEGUIR";
  getch();
 }
 else
 {
  gotoxy(2,3);cout<<"Escriba referencia..:";
  capcod(refe,24,3,8);
  tm=cab;
  clrscr();
  while(tm!=NULL)
  {
   if(strcmp(tm->referencia,refe)==0)
   {
    sw=1;
    clrscr();
    gotoxy(11,1);cout<<" OBSERVANDO ESTRUCTURA ";
    gotoxy(2,3);cout<<"C¢digo Articulo.....: "<<tm->referencia;
    gotoxy(2,4);cout<<"Articulo............: "<<tm->articulo;
    gotoxy(2,5);cout<<"Cantidad............: "<<tm->cantidad;
    gotoxy(2,6);cout<<"Costo...............: "<<tm->costo;
    gotoxy(2,9);cout<<" <ENTER> para continuar";
    getch();
   }
   tm=tm->sig;
  }
  if(sw==0)
  {
   clrscr();
   gotoxy(5,5);cout<<"   Codigo inexistente  ";
   gotoxy(5,6);cout<<" <ENTER> para continuar";
   getche();
  }
 }
 window(1,1,80,25);
}

void compra::visualizar()
{
 int x=0;
   window(4,5,77,22);
   textcolor(15);
   textbackground(0);
   clrscr();
 q=cab;
 if (cab==NULL)
 { clrscr();
   gotoxy(20,10);cout<<"NO EXISTEN INFORMACION EN LA LISTA";
   gotoxy(20,11);cout<<"        << PRESIONE  ENTER >>         ";
   getch();
   gotoxy(20,10);cout<<"                                  ";
   gotoxy(20,11);cout<<"                                  ";
   delay(50);
   }
 else
 { do
      {
      clrscr();
      x=5;
      clrscr();
      gotoxy(22,2);cout<<"REPORTE DE COMPRA DE ARTICULO";
      gotoxy(2,3);cout<<"REFERENCIA         ARTICULO          CANTIDAD             COSTO     ";

      while(q!=NULL)
      {
       gotoxy(5,x);cout<<q->referencia;
       gotoxy(18,x);cout<<q->articulo;
       gotoxy(40,x);cout<<q->cantidad;
       gotoxy(58,x);cout<<"$  "<<q->costo;
       q=q->sig;
       x=x+1;
       if (x==20)
       {
	gotoxy(2,18);cout<<" Presione cualquier tecla";
	getch();
	break;
       }
      }
      }while((x==20)||(q!=NULL));
      gotoxy(2,16);cout<<" Presione cualquier tecla";
      getch();
 }
 window(1,1,80,25);
}
// porcedimiento para la venta de articulo
void compra::vender(){
 char refe[8];
 int costven,canve;
    window(11,7,60,15);
    textcolor(15);
    textbackground(0);
    clrscr();

 tm=cab;
 if(existe==0)
 {clrscr();
  gotoxy(13,5);cout<<"   NO EXISTE  LISTA   ";
  gotoxy(13,6);cout<<"<ENTER> para continuar";
  getch();
 }
 else
 {
  gotoxy(2,3);cout<<"Digite referencia..:";
  capcod(refe,3,22,8);
  tm=cab;
  clrscr();
  sw=0;
   while ((tm!=NULL) && (sw==0))
    {
     if(strcmp(tm->referencia,refe)==0)
       sw=1;
     else
      tm=tm->sig;
     }

   if(sw==0)
     {
      clrscr();
      gotoxy(5,5);cout<<"      CODIGO NO EXISTE     ";
      gotoxy(5,6);cout<<"    <ENTER> Para continuar  ";
      getche();
     }
     else
     {
       clrscr();
       gotoxy(3,3);cout<<"C¢digo Articulo.....:"<<tm->referencia;
       gotoxy(3,4);cout<<"Articulo............:"<<tm->articulo;
       gotoxy(3,5);cout<<"Costo...............:"<<tm->costo;
       gotoxy(3,6);cout<<"Cantidad a Vender...:";
       gotoxy(24,6);cin>>canve;
	 if (tm->cantidad<canve)
	  { gotoxy(3,8);cout<<"     No se puede realizar la vender      :";
	    gotoxy(3,9);cout<<"No existe esa cantidad en el inventario..:";
	   getch();
	  }
	  else
	   tm->cantidad=tm->cantidad-canve;


     }
 }
window(1,1,80,25);
}

void compra:: ~compra()
{q=cab;r=q;
   while(r!=NULL)
   { if(q==r && q->sig==NULL)
     {free(cab);free(r);free(q);r=NULL;}
     else
     {
     r->sig=q;
     free(q);
     q=r;
     }
   }
}
void main()
{ compra obj;
do
{ clrscr();
  textcolor(5);
  cuadro(3,1,23,80,a1,a2,a3,a4,a5,a6);
  textbackground(11);
  textcolor(9);
  boli(1,1,1,80);
  centraM("CENTROSISTEMAS",1);
  textbackground(4);
  boli(2,2,1,80);
  centraM("CENTRO CERAMICO EL BUEN AMIGO",2);
  textbackground(4);
  boli(24,24,1,80);
  textbackground(11);
  boli(4,4,2,79);
  piso();
 rr=menuH(0);
   switch(rr){
     case 0:obj.adicionar();;break;
     case 1:obj.eliminar();break;
     case 2:obj.consultar();break;
     case 3:obj.visualizar();break;
     case 4:obj.vender();break;
     case 5:exit;break;
    }
 } while (rr!=5);
}
