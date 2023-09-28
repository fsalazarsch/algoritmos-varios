#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<ctype.h>
#define memo (struct nodo *) malloc (sizeof (struct nodo))
#define limp clrscr() 
#define colp textbackground  
#define col  textcolor 
#define imp  cprintf 
#define pos  gotoxy 
struct nodo
 {
   
   char codigo[10];
   char nombre[45];
   int info,j;
   struct nodo *sig;
 };
   struct nodo *p,*q,*cab;
   int n,m,*dato,*nuevo;
   int num,i,j;
   char op;
   char codigo[8];
   char nombre[30];

void crealista();
void imprime();
void inserta();
void elimina();
void musica();
void  cuadro();
void musica()
{
sound(480);
delay(1000);
nosound();
}
 
/********************  PRIMERO   ******************************************/
  void crealista()
   {
 
  struct nodo *nuevo;
  do
  {
   nuevo=memo;
   clrscr();
   colp(1);
   pos(15,2);
   imp("   CREAR LA  LISTA  ");
   pos(10,4);imp(" Digite  el codigo a crear          ");
   pos(10,5);imp(" Digite  el nombre a crear          ");
   pos(39,4);scanf("\n"); gets(nuevo->codigo);
   pos(39,5);scanf("\n"); gets(nuevo->nombre);
   if(cab==NULL)
   {
    cab=nuevo;
    nuevo->sig=cab;
   }
    else{
     p=cab;
     while(p->sig!=cab && strcmp(p->codigo,nuevo->codigo)!=0)
      p=p->sig;
      if(strcmp(p->codigo,nuevo->codigo)==0)
      {
	clrscr();
	pos(20,15);
	imp("  Codigo exixtente");
	musica();
      
	free(nuevo);
      }
       else
       {
	p->sig=nuevo;
	nuevo->sig=cab;
       }
   }
	pos(30,23); 
	imp("  DESEA CONTINUAR [s/n] ");
      do
      {
	op=toupper(getche());
      }while ((op != 'S') && (op != 'N'));
    }while (op != 'N');
   
     getche();
 }

   
/*********************   SEGUNDO  ************************************/
  void imprime()
  {
    struct nodo *nuevo;
    colp(1);
    clrscr();
    colp(1);
     if(cab!=NULL)
     {
     p=cab;
     pos(10,4);
     imp("  Impresion de lista  ");
     pos(12,10);
    imp("  COD ==>                        NAME ==>");
     j=10;
    while(p->sig!=cab)

    {
    pos(24,j);printf("%s\n",p->codigo);
    pos(58,j);printf("%s\t",p->nombre);
    p=p->sig;
  
  j++;
     }
     pos(24,j);printf("%s\n",p->codigo);
     pos(58,j);printf("%s\t",p->nombre);
 

  
   
   
    }
      else{
       clrscr();
       pos(20,15);imp("   Lista vacia ok.");
       }
         musica();
	col(10+128);pos(40,24);imp(" << P R E E S S   ENTER >>"); 
      
       getche();
  
 }   
/*******************   TERCERO  ***********************************/
 void inserta()
 {

  char op;
  struct nodo *nuevo;
  do
  {
   nuevo=memo;
   limp;
   colp(1);
   pos(10,4);
   imp(" Estamos en insertar ");
   pos(10,10);imp("  Digite el codigo        ");
   pos(10,11);imp("  Digite el nombre        ");
   pos(30,10);scanf("\n"); gets(nuevo->codigo);
   pos(30,11);scanf("\n"); gets(nuevo->nombre);
   if(cab==NULL)
   {
    cab=nuevo;
    nuevo->sig=cab;
   }
    else{
     p=cab;
     while(p->sig!=cab && strcmp(p->codigo,nuevo->codigo)!=0)
      p=p->sig;
      if(strcmp(p->codigo,nuevo->codigo)==0)
      {
	clrscr();
	limp;
	pos(20,15);
	imp(" Codigo existente ");
	getch();
	free(nuevo);
      }
       else
       {
	p->sig=nuevo;
	nuevo->sig=cab;
       }
   }
	pos(30,23); 
	imp("DESEA CONTINUAR [s/n]: ");
      do
      {
	op=toupper(getche());
      }while ((op != 'S') && (op != 'N'));
    }while (op != 'N');
     getche();
 }


/*********************   CUARTO   ************************************/
 void elimina()
  {
   char cod[10],op;
   clrscr();
    if(cab!=NULL)
    {
     do
     {
      limp;
      colp(1);
      pos(10,4);
      imp("   Elimina por codigo ");
      pos(10,8);imp("  Digite el codigo que desea eliminar       ");
      pos(51,8);scanf("\n");gets(cod);
      q=NULL;
      p=cab;
      while(p->sig!=cab && strcmp(p->codigo,cod)!=0)
      {

       q=p;
       p=p->sig;
      }
      if(q==NULL)
      {
       if(cab!=p->sig && strcmp(p->codigo,cod)==0)
      // 
       {
	q=cab;
	while(q->sig!=cab)    //cambio
	q=q->sig;
	q->sig=p->sig;
	cab=p->sig;
	p->sig=NULL;
       }
       else
	if(cab ==p->sig && strcmp(p->codigo,cod)==0)
	 cab=NULL;	 
     }
      else
       if(strcmp(p->codigo,cod)==0)
       q->sig=p->sig;
      else
      {
       clrscr();
       if(cab!=NULL&& strcmp(p->codigo,cod)!=0){
	pos(20,15);
	imp(" No insista el codigo no existe ");
	musica();
	getch();
       }
       else
       {
	pos(10,15);
	imp(" Lista vacia ok.");
	col(10+128);pos(40,24);imp(" << P R E E S S   ENTER >>"); 
	musica();
	getch();
	return;
       }
    }
	pos(35,22);imp("DESEA CONTINUAR [s/n] ");
       do
       {
	op=toupper(getche());
       }while ((op!='S')&&(op!='N'));
    }while(op!='N');
     getche();
    }
    else
    {

      pos(11,15);
      col(1+128);imp("  Lista vacia ");
      col(10+128);pos(40,24);imp(" << P R E E S S   ENTER >>"); 
      musica();
      getch();
     return;
    }
  }


//******************************* SECCION DE MENU ************

void  cuadro()
  { limp;

   colp(1);
   pos(20,8); imp("   E S T R U C T U R A   DE   D A T O S  ");
   colp(15);
   col(1);
   pos(20,10);imp(" CORPORACION UNIVERSITARIA DEL SANTANDER ");
   pos(20,11);imp("              U D E S                    ");
   pos(20,12);imp("                                         ");
   pos(20,13);imp("   PROGRAMA DE ESTRUCTURA DE DATOS PARA  ");
   pos(20,14);imp("      LA FORMACION DE BUENOS PROFE-      ");
   pos(20,15);imp("       SIONALES PARA EL DESARROLLO       ");
   pos(20,16);imp("           DEL DEPARTAMENTO              ");
   pos(20,17);imp("                                         ");
   pos(20,18);imp("                                         ");
   pos(20,19);imp("  DICTADA POR EL ING                    ");
   pos(20,20);imp("          ROBERTO FERNANDEZ              ");
   pos(20,21);imp("                                         ");
   col(10);
   pos(20,22);imp("       VALLEDUPAR OCT 23 1998            ");
   col(4+128);pos(35,24);imp(" << P R E E S S   ENTER >>"); 
   
   getch();
}

//************** MENU *******************
void menu();
void menu()
{
   cuadro();
   while(1)
   {
   colp(1);
   limp;
   colp(15);
   col(1);  
   pos(20,7); imp(" << E S T R U C T U R A   DE   D A T O S >> ");
   pos(20,10);imp("                                            ");
   pos(20,11);imp("       M E N U  P R I N C I P A L           ");
   pos(20,12);imp("                                            ");
   pos(20,13);imp("                                            ");
   pos(20,14);imp("        1.CREAR UNA LISATA                  ");
   pos(20,15);imp("        2.VISUALIZAR  LISTA                 ");
   pos(20,16);imp("        3.INSERTAR                          ");
   pos(20,17);imp("        4.ELIMINAR                          ");
   pos(20,18);imp("        5.SALIR                             ");
   pos(20,19);imp("                                            ");
   pos(20,20);imp("          ELIJA OPCION  [ ]                 ");
   pos(20,21);imp("                                            ");
   pos(20,22);imp(" Elaborado por: JAIME RINCON B.  S 3 A      ");
   col(15);pos(45,20);op=getchar();op=toupper(op);
   switch(op)
   {
     case '1' :crealista();break;
     case '2' :imprime();break;
     case '3' :inserta();break;
     case '4' :elimina();break;
     case '5' :return;
   }
  }
}
void main()
{
  menu();
}
