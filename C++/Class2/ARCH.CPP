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
inline void colores(int x, int y){textcolor(x);textbackground(y);}
inline void pos (int x,int y){gotoxy(y,x);}
/*********************************************************************************/
struct comprart{
    char referencia[8];
    char articulo[45];
    int cantidad;
    float costo;
    comprart *sig;};


struct ventart{
    char referencia[8];
    char articulo[45];
    int cantidad;
    float costoventa;
    ventart *sig;};

class compra{
    struct comprart *cab,*q,*tm,*z,*p,*r;
    public:
    void costructor();
    //void ~destructor();
    void adicionar();
    void ordenar();
    void eliminar();
    void consultar();
    void visualizar();
    void cap_artic(char nom[],int x,int y,int ancho,int *tec);
    void capcod(char codigo[],int x,int y ,int ancho);
   };
class ventas{
     struct ventart *cab,*q,*tm,*z,*p,*r;
     compra obj;
     public:
       ventas(){cab=q=tm=z=p=NULL;}
       //~destruventa(){}
       void vender();
       };

int sw=0,sw1=0,canven=0,cancomp=0,elim=0;
void compra::costructor()
{
 cab=q=tm=z=p=r=NULL;
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
{
      char c =' ';
      int n_car=0;
      gotoxy(x,y);
      clreol();
      while (c!='\r' && n_car<ancho)
      {
	 c=getche();
	 if (!isdigit(c) && c!='\r')
	 {
	  gotoxy(x,y);clreol();
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
	clrscr();
	gotoxy(20,5);cout<<" DIGITANDO ESTRUCTURA ";
	gotoxy(11,8);cout<<"Referancia        " ;
	gotoxy(11,9);cout<<"Articulo         " ;
	gotoxy(11,10);cout<<"Cantidad          ";
	gotoxy(11,11);cout<<"Costo             ";

	do{ capcod(refe,45,8,8);
	 tm=cab;
	 while(tm!=NULL)
	 {//2.1
	  if(strcmp(tm->referencia,refe)==0)
	  {gotoxy(23,13);cout<<" CODIGO EXISTENTE";
	   gotoxy(23,14);cout<<"<< Press Enter >>";
	   getch();gotoxy(23,13);cout<<"                 ";
	   gotoxy(23,14);cout<<"                 ";gotoxy(45,8);cout<<"                           ";
	   sw=1;break;}
	  else
	  {sw=0;tm=tm->sig;}
	 }//2.1
     }while(sw==1);//2

     do{cap_artic(art,45,9,20,tec);
	 tm=cab;
	 while(tm!=NULL)
	 {
	  if(strcmp(tm->articulo,art)==0)
	  {gotoxy(23,13);cout<<" ARTICULO EXISTENTE";
	   gotoxy(23,14);cout<<" << Press Enter >>";
	   getch();gotoxy(23,13);cout<<"                   ";
	   gotoxy(23,14);cout<<"                  ";gotoxy(44,9);cout<<"                             ";
	   sw=1;break;}
	  else
	  {sw=0;tm=tm->sig;}
	 }
      }while(sw==1);//2
     do
	{
	 gotoxy(45,10);gets(tem);
	 validar_numero(tem);
	 if(sw1==1){
	   textcolor(14);
	   gotoxy(30,11);cout<<"No se Aceptan Letras. ";
	   gotoxy(30,12);cout<<"    Pressione Enter.  ";
	   textbackground(7);
	   getch();
	   gotoxy(30,11);cout<<"                      ";
	   gotoxy(30,12);cout<<"                      ";
	   gotoxy(45,10);cout<<"                      ";
	 }
	}while(sw1 != 0);
	cant= atoi(tem);
     do
	{
	 sw1=0;
	 gotoxy(45,11);gets(tem2);
	 validar_numero_f(tem2);
	 if(sw1==1){textcolor(5);
	   gotoxy(25,10);cout<<"No se Aceptan Letras. ";
	   gotoxy(25,11);cout<<"    Pressione Enter.  ";
	   textbackground(7);
	   getch();
	   gotoxy(25,10);cout<<"                      ";
	   gotoxy(25,11);cout<<"                      ";
	   gotoxy(45,11);cout<<"      ";
	 }
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
    gotoxy(15,23);cout<<"Desea Continuar Insertando Datos a la Lista s/n ";
    do{op=toupper(getche());
      }while ((op != 'S') && (op != 'N'));
  }while (op != 'N');//1
  ordenar();
getch();
}

void compra::eliminar()
{
  char n,c[35],refe[10],op;
  clrscr();
  if(cab==NULL)
  {
   gotoxy(20,10);cout<<"NO EXISTEN INFORMACION PARA ELIMINAR";
   gotoxy(20,11);cout<<"        << PRESS ENTER >>         ";
   getch();
   gotoxy(20,10);cout<<"                                  ";
   gotoxy(20,11);cout<<"                                  ";
  }
  else
  {  do{  q=cab;r=q;
	   clrscr();
	    gotoxy(20,8);cout<<"Digite referencia de articulo a eliminar ";
	    capcod(refe,65,8,8);
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
		    gotoxy(15,13);cout<<"<<      E L I M I N A N D O    D A T O      >>";
		    delay(50);sound(100);sleep(1);nosound();
		   }
		   else
		   {if(r==q && q->sig!=NULL)
		     {
			cab=q->sig;
			q->sig=NULL;
			free(q);
			gotoxy(15,13);cout<<"<<      E L I M I N A N D O    D A T O      >>";
			delay(50);sound(100);sleep(2);nosound();
		       }
		       else
		       { if(r!=q && q->sig==NULL)
			   {
			    r->sig=NULL;
			    free(q);
			    gotoxy(15,13);cout<<"<<      E L I M I N A N D O    D A T O      >>";
			    delay(50);sound(100);sleep(2);nosound();
			   }
			   else
			   {
				r->sig=q->sig;
				free(q);
				gotoxy(15,13);cout<<"<<      E L I M I N A N D O    D A T O      >>";
				delay(50);sound(100);sleep(2);nosound();
			   }
			}
		   }elim=0;
	     }
	     else
	     {
	       gotoxy(23,13);cout<<" REFERENCIA NO EXISTENTE";
	       gotoxy(23,14);cout<<"<< Press Enter >>";
	       getch();
	       gotoxy(23,13);cout<<"                         ";
	       gotoxy(23,14);cout<<"                         ";
	       gotoxy(45,8);cout<<"                          ";
	     }
	     clrscr();
	     gotoxy(15,23);cout<<"Desea Continuar Eliminando Datos en la Lista s/n ";
	     do{op=toupper(getche());
	       }while ((op != 'S') && (op != 'N'));
       }while (op != 'N');//1
  }
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
 clrscr();
 gotoxy(30,5);cout<<" OBSERVANDO ESRTRUCTURA";
 tm=cab;
 if(tm==NULL)
 {
  gotoxy(30,12);cout<<"NO EXISTE  LISTA ";
  gotoxy(35,20);cout<<"ENTER PARA SEGUIR";
  getch();
 }
 else
 {
  gotoxy(12,8);cout<<"Escriba referencia del articulo a consultar  ";
  capcod(refe,8,45,8);
  tm=cab;
  clrscr();
  while(tm!=NULL)
  {
   if(strcmp(tm->referencia,refe)==0)
   {
    sw=1;
    clrscr();
    gotoxy(20,5);cout<<" OBSERVANDO ESTRUCTURA ";
    gotoxy(11,8);cout<<"C¢digo Articulo..... "<<tm->referencia;
    gotoxy(11,10);cout<<"Articulo.....       "<<tm->articulo;
    gotoxy(11,11);cout<<"Cantidad.....       "<<tm->cantidad;
    gotoxy(11,12);cout<<"Costo.....          "<<tm->costo;
    gotoxy(30,24);cout<<" ENTER PARA CONTINUAR";
    getch();
   }
   tm=tm->sig;
  }
  if(sw==0)
  {
   clrscr();
   gotoxy(25,12);cout<<" CODIGO NO EXISTE ";
   gotoxy(30,24);cout<<" ENTER PARA CONTINUAR";
   getche();
  }
 }
}

void compra::visualizar()
{
 int x=0;
 q=cab;
 if (cab==NULL)
 { clrscr();
   gotoxy(20,10);cout<<"NO EXISTEN INFORMACION EN LA LISTA";
   gotoxy(20,11);cout<<"        << PRESS ENTER >>         ";
   getch();
   gotoxy(20,10);cout<<"                                  ";
   gotoxy(20,11);cout<<"                                  ";
   delay(50);
   }
 else
 {
      do
      {
      clrscr();
      x=7;
      clrscr();
      gotoxy(2,5);cout<<"REORTE DE COMPRA DE ARTICULO";
      gotoxy(2,5);cout<<"REFERENCIA         ARTICULO          CANTIDAD             COSTO     ";

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
	gotoxy(30,22);cout<<" PRECIONE CUALQUIER TECLA";
	getch();
	break;
       }
      }
      }while((x==20)||(q!=NULL));
      gotoxy(30,22);cout<<" PRECIONE CUALQUIER TECLA";
      getch();
 }
}
void ventas:: vender(){
 //int sw=0;
 char refe[8];
 int costven,canve;
 tm=cab;
 clrscr();
 gotoxy(30,5);cout<<" OBSERVANDO ESRTRUCTURA";
 tm=cab;
 if(tm==NULL)
 {
  gotoxy(30,12);cout<<"NO EXISTE  LISTA ";
  gotoxy(35,20);cout<<"ENTER PARA SEGUIR";
  getch();
 }
 else
 {
  gotoxy(12,8);cout<<"Digite referencia del articulo a Vender  ";
  obj.capcod(refe,8,45,8);
  tm=cab;
  clrscr();
  while(tm!=NULL)
  {
   if(strcmp(tm->referencia,refe)==0)
   {
    sw=1;
    clrscr();
    gotoxy(11,8);cout<<"C¢digo Articulo..... "<<tm->referencia;
    gotoxy(11,10);cout<<"Articulo.....       "<<tm->articulo;
    gotoxy(11,11);cout<<"Cantidad.....       ";
    gotoxy(11,12);cout<<"Costo.....          ";
    gotoxy(30,11);cin>>canve;
    gotoxy(30,12);cin>>costven;
   }
   tm=tm->sig;
  }
  if(sw==0)
  {
   clrscr();
   gotoxy(25,12);cout<<" CODIGO NO EXISTE ";
   gotoxy(30,24);cout<<" ENTER PARA CONTINUAR";
   getche();
  }
 }
getch();
}
/*void compra:: ~destructor()
{q=cab;r=q;
   while(q!=NULL)
   { q->sig=r;
     free(q);
     //q=r;
     q=q->sig;
   }
} */
void main()
{
  compra obj; ventas objet;
  obj.costructor();
  char op;
  do{
   clrscr();colores(15,7);
   gotoxy(17,6);cout<<"MENU PRINCIPAL";
   colores(0,7);
   gotoxy(25,10);cout<<" 1. CAPTURA";
   gotoxy(25,11);cout<<" 2. ELIMINAR";
   gotoxy(25,12);cout<<" 3. CONSULTA";
   gotoxy(25,13);cout<<" 4. VISUALIAR";
   gotoxy(25,14);cout<<" 5. VENTAS";
   gotoxy(25,15);cout<<" 6. SALIR";
   gotoxy(23,18);cout<<" ESCOJA LA OPCION: ";
   gotoxy(45,18);cin>>op;
    switch(op){
     case'1':obj.adicionar();break;
     case'2':obj.eliminar();break;
     case'3':obj.consultar();break;
     case'4':obj.visualizar();break;
     case'5':objet.vender();break;
     case'6':break;
    }
 } while (op!='6');
}
