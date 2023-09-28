#include <iostream.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include "fcntl.h"
#include "io.h"
#define memo (struct nodo_alumnos*)malloc(sizeof (struct nodo_alumnos))
/**********************************************************************/
   //estruct nodo_alumnos *ptr,*nn,*pad,*p,*pila[20],*e,*q,*s,*u;
  struct nodo_alumnos {
  struct nodo_alumnos *izq;
   long codigo;
   int costo;
   int tiempo;
   char nombre[20];
   struct nodo_alumnos *der;
  }*ptr,*nn,*pad,*p,*pila[20],*e,*q,*s,*u;

/**********************************************************************/
 void eliminar_estudiante();
 void recorrido_postorden();
void recorrido_inorden();
void recorrido_preorden();
void lista();
  void modificar_estudiante();
  void mensaje(char men[45]);
  char cod[8],nombre[15],tecla;  
 
 void comv(int x,char a[2]);
  long valcod(int x);
  void valdatos(int x,int y,int x1,int y1,int x2,int y2,char a[15],int a1,int k);
 int i,x,f2,x2,f,f1,c,n,sw,cos,tim;
 long cod_alumno,cod1;
 xy(int x, int y);
 void eliminar();
 void menu();

 void piscol (int piso,int color);
 void introducir();
 void cuadro(int C1,int F1,int C2,int F2);
//*****************************CUADROS************************************//

void cuadro(int C1,int F1,int C2,int F2)
{
 for(i=C1+1;i<C2;i++){
 gotoxy(i,F1);cprintf("Í");delay(1.8);gotoxy(i,F2);cprintf("Í");delay(1.8);}
 for(i=F1+1;i<F2;i++){
 gotoxy(C1,i);cprintf("º");delay(1.8); gotoxy(C2,i);cprintf("º");delay(1.8);}
 gotoxy(C1,F1);cprintf("É");
 gotoxy(C1,F2);cprintf("È");
 gotoxy(C2,F1);cprintf("»");
 gotoxy(C2,F2);cprintf("¼");
}

/**********************************************************************/

void piscol (int piso,int color)
      {
	textbackground (piso);	/* Color del piso */
	textcolor (color);	/* Color de la letra */
      }

/**********************************************************************/
void menu()
{ char op;
do{
// piscol(1,15);
 window(1,1,80,25);
 clrscr();
 gotoxy(15,9);printf("1> INTRODUCIR ");
 gotoxy(15,10);printf("2> VISUALIZAR PREORDEN");
 gotoxy(15,11);printf("3> VISUALIZAR INORDEN");
 gotoxy(15,12);printf("4> VISUALIZAR POSTORDEN");
 gotoxy(15,13);printf("5> ELIMINAR");
 gotoxy(15,14);printf("6> MODIFICAR");
 gotoxy(15,15);printf("7> SALIR");
 gotoxy(18,19);printf(" DIGITE SU OPCION => ");
  do
  {
   gotoxy(39,19);clreol(); op=getch();
  }while((op>'7') ||(op<'1'));
   switch(op){
   case'1':introducir();break;

  case'2':clrscr(); recorrido_preorden(); getche(); break;
   case'3':clrscr(); recorrido_inorden(); getche(); break;
   case'4':clrscr(); recorrido_postorden(); getche(); break;
  case'5':clrscr();eliminar_estudiante() ; break;
  case'6': modificar_estudiante();break;
	case'7':exit(0);
  }
}while(op!='7');
}

/**********************************************************************/

void main()
{ menu();
}
//*************************************************************************

void mensaje(char men[45])
{
 textbackground(0);window(1,1,80,25);
 gotoxy(5,22);cprintf("ESTADO :");
  gotoxy(15,22);  clreol();
 window(15,22,65,22);textbackground(1);clrscr();
 gotoxy(15,22);  clreol();
printf("%s",men);
 textbackground(0);window(1,1,80,25);
}
//*********************************************************
void valdatos(int x,int y,int x1,int y1,int x2,int y2,char a[15],int a1,int k)
{
 do
 {
 textbackground(1);window(x1,y1,x2,y1);
  if (a1==0) clreol();
  textbackground(4);window(y2,y1,x1-1,y1);
  if (a1==0) clrscr();
  gotoxy(x,y);;gets(a);
  for (i=0; i<strlen(a); i++)
  {
   a[i] = toupper(a[i]);
  }
  n=strlen(a);
  if((n=strlen(a))>20)
  {
   mensaje("ERROR! NMOMBRE FUERA DE RANGO");
   getch();
  }
  if ((n=strlen(a))==0)
  {
   if (a1==0)
   {
	mensaje("ERROR! INGRESE LA INFORMACION SOLICITADA");
	getch();
	n=25;
   }
   else break;
  }
 }while(n>15);
 if (k==0)
 {
  if ((a1==1)&&(n==0)) strcpy(nombre,p->nombre);
 }
}
//**************************VERIFICACION DEL CODIGO********************************
long valcod(int x)
{
 n=0;i=0;
 do
 {
  do
  {
  textbackground(1);window(26,x,29,x);clreol();
  textbackground(4);window(44,x,21,x);clrscr();
   clreol();gets(cod);n=strlen(cod);
   if ((n=strlen(cod))!=3)
   {
	mensaje("ERROR! CODIGO FURA DE RANGO MAX 3");
	getch();
   }
  }while(n!=3);sw=0;
  for(i=0;i<n;i++) if(isdigit(cod[i])==0) sw=1;
  if(sw==1)
  {
	mensaje("ERROR! CODIGO DEBE SER NUMERICO");
   getch();
  }
  else
  {
   cod_alumno=atol(cod);
   if (cod_alumno==0)
   {
    sw=1;
  mensaje("ERROR! INGRESE LA INFORMACION SOLICITADA");
	getch();
   }
  }
 }while(sw==1);
 return(cod_alumno);
}

//*************************************************************************
void introducir()
{
 char op;
do
{
 clrscr();window(1,1,80,24);textbackground(0);//mostrar();
 textcolor(15);cuadro(2,6,79,23);//cuadro(50,6,79,16);
 cuadro(2,2,79,6);
 gotoxy(2,6);printf("Ì");//gotoxy(50,6);printf("Ë");
 gotoxy(79,6);printf("¹");gotoxy(2,16);printf("Ì");
 gotoxy(50,16);printf("Ê");gotoxy(79,16);printf("¹");
 gotoxy(2,23);printf("È");gotoxy(79,23);printf("¼");

 cuadro(2,16,79,23);textcolor(15);gotoxy(21,4);
 cprintf(" ADICION DE LOS ESTUDIANTES");

 textbackground(1);gotoxy(5,8);cprintf("DISTANCIA MUNICIPIO ");
 cod1=valcod(8);
 //VALIDA EXISTENCIA DELCODIGO
 p=ptr;
 sw=0;
 pad=NULL;
 while ((p!=NULL) && (sw==0))
 {
  if (cod1<p->codigo)
  {
   pad=p;
   p=p->izq;
  }
  else
  {
   if (cod1>p->codigo)
   {
    pad=p;
    p=p->der;
   }
   else
   {
    sw=1;
   }
  }
 }
 //VERIFICACION BUSQUEDA
 if (sw==1)
 {
  mensaje("CODIGO INGRESADO YA EXISTE");
  getch();
 }
 else
 {
  textbackground(1);window(1,1,80,24);
  gotoxy(5,9);cprintf("MUNICIPIO: ");
  valdatos(1,1,26,9,38,42,nombre,0,0);
  textbackground(1);window(1,1,80,24); gotoxy(5,10);
   cprintf("COSTO : ");

   textbackground(1);window(26,10,35,10);clreol();
   textbackground(4);window(42,10,31,10);clrscr();
	 scanf("%d",&cos);

	  textbackground(1);window(1,1,80,24); gotoxy(5,11);
   cprintf("TIEMPO : ");

   textbackground(1);window(26,11,35,11);clreol();
   textbackground(4);window(42,11,31,11);clrscr();

	 scanf("%d",&tim);

  textbackground(1);window(1,1,80,24);
  //OBTIENE NODO Y SE ADICIONA LA INFORMACION
  nn=memo;
  nn->izq=NULL;
  nn->der=NULL;
  //INSERTA EN EL ARBOL
  if (pad==NULL)
  {
   ptr=nn;
  }
  else
  {
   if (cod1<pad->codigo)
   {
    pad->izq=nn;
   }
   else
   {
    pad->der=nn;
   }
  }
  nn->codigo=cod1;
  nn->costo= cos;
  nn->tiempo=tim;
  strcpy(nn->nombre,nombre);
 }
 mensaje("OPERACION EXITOSA! DESEA CONTINUAR S/N");
 op=toupper(getche());textbackground(0);window(1,1,80,25);clrscr();
}while(op=='S');
}
//***************************************************************************
//*************************CUADRO DE LOS RECORRIDOS*************************
void lista()
{
 cuadro(1,3,77,14);
 cuadro(1,1,77,14);
 cuadro(1,1,12,14);
 cuadro(34,3,56,14);  gotoxy(40,2);printf("COSTO ");
					  gotoxy(63,2);printf("TIEMPO ");
 gotoxy(2,2);printf("DISTANCIA  ");
 cuadro(12,1,77,14);
 gotoxy(15,2);printf(" MUNICIPIO");
}

//*************************RECORRIDO EN PREORDEN****************************
void recorrido_preorden()
{
 int tope,k;
 window(1,1,80,25);textbackground(0);clrscr();
 cuadro(2,2,79,6);
 gotoxy(17,4);printf("MODULO RECORRIDO DEL ARBOL EN PREORDEN");
 if (ptr==NULL)
 {
  mensaje("NO HAY INFORMACION PARA MOSTRAR");
  getch();
 }
 else
 {
  window(2,8,79,21);textbackground(1);clrscr();
  lista();
  tope=1;
  p=ptr;
  k=4;
  while (tope!=0)
  {
   if (p!=NULL)
   {
	gotoxy(3,k);printf("%d",p->codigo);
	gotoxy(14,k);printf("%s",p->nombre);
	 gotoxy(39,k);printf("%d",p->costo);
	gotoxy(62,k);printf("%d",p->tiempo);
	k++;
	pila[tope]=p;
	tope++;
	p=p->izq;
	if (k==14)
	{
	 clrscr();
	 k=3;
	 lista();
	}
   }
   else
   {
    tope=tope-1;
    if (tope!=0)
    {
     p=pila[tope];
     p=p->der;
    }
   }
  }
  mensaje("ENTER PARA SALIR");
  getchar();
 // clrscr();
 }
}
//**************************RECORRIDO INORDEN******************************
void recorrido_inorden()
{
 int tope,k;
 window(1,1,80,25);textbackground(0);clrscr();
 cuadro(2,2,79,6);
 gotoxy(17,4);printf("MODULO RECORRIDO DEL ARBOL EN INORDEN");
 if (ptr==NULL)
 {
  mensaje("NO HAY INFORMACION PARA MOSTRAR");
  getch();
 }
 else
 {
  window(2,8,79,21);textbackground(1);clrscr();lista();
  tope=1;p=ptr;k=4;
  while (tope!=0)
  {
   if (p!=NULL)
   {
    pila[tope]=p;
    tope++;
    p=p->izq;
   }
   else
   {
    tope=tope-1;
    if (tope!=0)
    {
     p=pila[tope];
	 gotoxy(3,k);printf("%d",p->codigo);
	 gotoxy(14,k);printf("%s",p->nombre);
		 gotoxy(39,k);printf("%d",p->costo);
	gotoxy(62,k);printf("%d",p->tiempo);

	 k++;
	 if (k==14)
	 {
	  clrscr();
	  k=3;
	  lista();
	 }
	}
	p=p->der;
   }
  }
  mensaje("ENTER PARA SALIR");
  getchar();
  //clrscr();
 }
}
//***************************RECORRIDO POSTORDEN***************************
void recorrido_postorden()
{
 int tope,k;
 window(1,1,80,25);textbackground(0);clrscr();
 cuadro(2,2,79,6);
 gotoxy(17,4);printf("MODULO RECORRIDO DEL ARBOL EN POSTORDEN");
 if (ptr==NULL)
 {
  mensaje("NO HAY INFORMACION PARA MOSTRAR");
  getch();
 }
 else
 {
  window(2,8,79,21);textbackground(1);clrscr();
  lista();
  tope=1;
  p=ptr;
  pad=NULL;
  k=4;
  while ((tope!=0) && (pad!=ptr))
  {
   if (p==NULL)
   {
    tope=tope-1;
    p=pila[tope];
    e=p;
    p=p->der;
    if ((p==NULL) || (p==pad))
    {
     p=pila[tope];
	 gotoxy(3,k);printf("%d",p->codigo);
	 gotoxy(14,k);printf("%s",p->nombre);
	  gotoxy(39,k);printf("%d",p->costo);
	  gotoxy(62,k);printf("%d",p->tiempo);

	 k++;
     pad=p;
     p=NULL;
     if (k==14)
     {
      clrscr();
      k=3;
      lista();
     }
    }
    else
    {
     tope++;
    }
   }
   else
   {
    pila[tope]=p;
    tope++;
    p=p->izq;
   }
  }
  mensaje("ENTER PARA SALIR");
  getchar();
  //clrscr();
 }
}

//*****************************************************************************
void eliminar_estudiante()
{
 clrscr();window(1,1,80,24);textbackground(0);//mostrar();
 textcolor(15);cuadro(2,6,79,23);cuadro(50,6,79,16);cuadro(2,2,79,6);
 gotoxy(2,6);cout<<"Ì";gotoxy(50,6);cout<<"Ë";
 gotoxy(79,6);cout<<"¹";gotoxy(2,16);cout<<"Ì";
 gotoxy(50,16);cout<<"Ê";gotoxy(79,16);cout<<"¹";
 gotoxy(2,23);cout<<"È";gotoxy(79,23);cout<<"¼";
 cuadro(2,16,79,23);textcolor(15);gotoxy(21,4);
 cprintf(" ELIMINAR DATOS DE LOS ESTUDIANTES");
 if (ptr==NULL)
 {
  mensaje("NO EXISTE INFORMACION PARA ELIMINAR");
  getch();
 }
 else
 {
  textbackground(1);gotoxy(5,8);cprintf("DISTANCIA MUNICIPIO ");
  cod1=valcod(8);
  //valida existencia del codigo
  u=NULL;
  p=ptr;
  sw=0;
  pad=ptr;
  while ((cod1!=p->codigo) && (pad!=NULL))
  {
   u=p;
   p=pad;
   if (cod1<p->codigo)  pad=p->izq;
   else pad=p->der;
  }
  if (cod1!=p->codigo)
  {
   mensaje("CODIGO INGRESADO NO EXISTE");
   getch();
  }
  else
  {
   textbackground(1);window(1,1,80,24);
   gotoxy(5,9);cprintf("MUNICIPIO: ");gotoxy(24,9);puts(p->nombre);
   textbackground(0);window(1,1,80,24);window(3,18,78,22);textcolor(10);
   mensaje("ESTA SEGURO QUE DESEA ELIMINAR S/N");
   tecla=toupper(getche());
   if (tecla=='S')
   {
    //eliminar principio
    if (p->izq==NULL) pad=p->der;
    else
     if (p->der==NULL) pad=p->izq;
     else
     {
      q=p;
      pad=q->der;
      s=pad->izq;
      //eliminar en el medio
      while (s!=NULL)
      {
       q=pad;
       pad=s;
       s=pad->izq;
      }
      if (q!=p)
      {
       q->izq=pad->der;
       pad->der=p->der;
      }
      pad->izq=p->izq;
     }
     if (u==NULL) ptr=pad;
     else
     {
      if (p==u->izq) u->izq=pad;
      else u->der=pad;
     }
     p->izq=NULL;
     p->der=NULL;
     delete (p);
     mensaje("OPERACION EXITOSA! ENTER PARA CONTINUAR");
     getch();
    }
    else
    {
     mensaje("OPERACION CANCELADA! ENTER CONTINUAR");
	 //getch();
	}
   }
  }
  clrscr();
}
//***************************************************************************
//****************************************************************************
void modificar_estudiante()
{
 char op;
 do
 {
  clrscr();window(1,1,80,24);textbackground(0);//mostrar();
  textcolor(15);cuadro(2,6,79,23);//cuadro(50,6,79,16);
  cuadro(2,2,79,6);
  gotoxy(2,6);cout<<"Ì";gotoxy(50,6);cout<<"Ë";
  gotoxy(79,6);cout<<"¹";gotoxy(2,16);cout<<"Ì";
  gotoxy(50,16);cout<<"Ê";gotoxy(79,16);cout<<"¹";
  gotoxy(2,23);cout<<"È";gotoxy(79,23);cout<<"¼";
  cuadro(2,16,79,23);textcolor(15);gotoxy(21,4);
  cprintf(" MODIFICAR DATOS DE LOS ESTUDIANTES");
  textbackground(1);gotoxy(5,8);cprintf("DISTANCIA MUNICIPIO ");
  cod1=valcod(8);
  //valida existencia codigo
  p=ptr;
  sw=0;
  pad=NULL;
  while ((p!=NULL) && (sw==0))
  {
   if (cod1<p->codigo)
   {
    pad=p;
    p=p->izq;
   }
   else
   {
    if (cod1>p->codigo)
    {
     pad=p;
     p=p->der;
    }
    else
    {
     sw=1;
    }
   }
  }
  if (sw==0)
  {
   mensaje("CODIGO INGRESADO NO EXISTE");
   getch();
  }
  else
  {
   textbackground(1);window(1,1,80,24);
   gotoxy(5,9);cprintf("MUNICIPIO: ");
   window(24,9,40,9);textbackground(4);clrscr();cout<<p->nombre;
   mensaje("MODIFIQUE Y OPRIMA ENTER");
   textbackground(1);window(1,1,80,24);
   gotoxy(5,9);cprintf("MUNICIPIO: ");valdatos(1,1,24,9,38,42,nombre,1,0);
   textbackground(0);window(1,1,80,24);window(3,18,78,22);textcolor(10);
   mensaje("DESEA MODIFICAR EL REGISTRO S/N");
   tecla=toupper(getche());
   if (tecla=='S')
   {
    strcpy(p->nombre,nombre);
    mensaje("OPERACION EXITOSA! REGISTRO MDIFICADO");
    getch();
   }
   else
   {
    mensaje("OPERACION CANCELADA! REGISTRO NO MODIFICADO");
    getch();
   }
  }
  mensaje("DESEA MODIFICAR OTRO REGISTRO S/N");
  op=toupper(getche());textbackground(0);window(1,1,80,25);clrscr();
 }while(op=='S');
}
