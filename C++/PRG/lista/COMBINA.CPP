 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#define memo (struct nodo *) malloc (sizeof (struct nodo))
#include <iostream.h>
#define  col textcolor
#define  colp textbackground
#define  imp  cprintf
#define  limp  clrscr()
#define  pos  gotoxy

  struct nodos
  { char nom[20],cod[10];
	 struct nodos *ante;
	 struct nodos *sigui;
  };
    nodos *nn,*p,*ptr;
   int sw;
   char nom[20],cod[10],op;
   void adicionar();
   void eliminar();
   void imprime();
   void ventana(int X1,int Y1,int X2,int Y2);
   void menu();
   void panta();


void menu()
{
   int n,j;
   int tecla,f;
   colp(1);
   limp;
   char opciones[25][45];
   char helpline[25][45];
    //window(1,1,80,25);
   clrscr();
   colp(14);
   strcpy(opciones[10],"	ADICIONAR    ");
   strcpy(opciones[11]," ELIMINAR     ");
   strcpy(opciones[12],"	VIZUALIZAR   ");
   strcpy(opciones[13]," SALIR  	     ");
   strcpy(helpline[10]," ADICIONA ELEMENTOS EN LA LISTA 	           ");
   strcpy(helpline[11]," ESTAMOS ELIMINANDO EN LA LISTA	           ");
   strcpy(helpline[12]," ESTAMOS VISUALIZANDO CONTENIDO DE LA LISTA ");
   strcpy(helpline[13]," SALE DEL PROGRAMA                          ");

   do{
   for(f=10; f<=14;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=10;
  textcolor(1); textbackground(15);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(15); textbackground(1);
 do
 {
  gotoxy(10,25);
  cprintf(helpline[f]);
  gotoxy(1,1);
  do
  {
  tecla=getch(); }
   while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
   if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 10: adicionar();limp; break;
 case 11: eliminar();limp;break;
 case 12: imprime();limp;break;
 case 13: exit(0);limp;break;

 }

}
 while(f!=14);
}
//*************************************************************/
void adicionar()
 {
  do
      {
	 limp;
	 colp(1);
	 clrscr();
	 ventana(2,2,79,24);
	 pos(15,4);
	 printf("DIGITE EL CODIGO A INGRESAR ==>");
	 scanf(" \n");gets(cod);
	 p=ptr; sw=0;
	 while(p!=NULL)
	 { if(strcmp(cod,p->cod)==0)
		{ sw=1; break; }
		p=p->sigui;
	 }
	 if(sw==1){  ventana(22,12,50,14);
	 pos(28,13);printf("    YA EXIXTE    ");}
	 else
	 {
	   pos(15,6);
	   printf("DIGITE EL NOMBRE ==> ");
	    scanf("\n");gets(nom);

		nn=new nodos;
		strcpy(nn->cod,cod);
		strcpy(nn->nom,nom);
		nn->sigui=nn->ante=NULL;
		if(ptr==NULL)
		 ptr=nn;
		 else
		 {
		  p=ptr;
		  while(p->sigui!=NULL)
			p=p->sigui;
			p->sigui=nn;
			nn->ante=p;
		 }

	  ventana(18,12,50,14);
	  pos(20,13);	imp("    CODIGO   ADICIONADO    ");
	  }

	 pos(20,22);printf("DESEA SEGUIR ADICIONANDO       [s/n]   ");
	 op=toupper(getche());
  }while(op=='S');
}
/*****************************************************************/
void imprime()
{
  int fila;
  limp;
  colp(1);
  col(15);
  if(ptr==NULL){clrscr();  ventana(2,2,79,24);
  pos(26,10);cout<<"NO SE PUEDE VISUALIZAR   ";
  pos(29,11);cout<<"   LISTA VACIA   ";
   ventana(24,8,52,13);}


	  else
	{
	  p=ptr; clrscr(); fila=7;
	  pos(4,3); cout<<" LISTADO  GENERAL   ";
	  pos(4,5); cout<<"COD          NOMBRE ";
	  ventana(9,4,31,24);
	  ventana(1,4,9,24);
	  ventana(1,2,31,24);
	  while(p!=NULL){
	  pos(4,fila);cout<<p->cod;
	  pos(15,fila);cout<<p->nom;
	  p=p->sigui;fila++;
	  }
	 }
	 getche();

}

/***** ELIMINAR ***************************************************************/
void eliminar()
{
 limp;
   colp(1);
   col(15);
    do
    { clrscr();  ventana(2,2,79,24);

    if(ptr==NULL)
    {
       ventana(18,12,55,14);
       pos(21,13);
       printf("    NO SE PUEDE ELIMINAR    "); op='N'; getche(); }
      else
      { ventana(2,2,79,24);
	p=ptr;
	ptr=p->sigui;
	ptr->ante=p->sigui=NULL;
	delete(p);
	ventana(18,12,55,14);
	pos(23,13);
	printf("  ELEMENTO  ELIMINADO    ");
	pos(20,19);
	printf("DESEA ELIMINAR OTRO  [s/n] : ");
	op=toupper(getche());
      }
  }while(op=='S');
}
/**************************************************************/
void ventana(int X1,int Y1,int X2,int Y2)
{    int i;
  for(i=X1+1;i<X2;i++){
    pos(i,Y1);imp("Í");   // LINEA ARRIBA HORIZONTAL
    pos(i,Y2);imp("Í");}  // LINEA ABAJO HORIZONTAL
    for(i=Y1+1;i<Y2;i++){
       pos(X1,i);imp("º");    // LINEA IZQUIERDA VERTICAL
       pos(X2,i);imp("º");}   // LINEA DERECHA VERTICAL
       pos(X1,Y1);imp("É");
       pos(X1,Y2); imp("È");
       pos(X2,Y1);imp("»");
       pos(X2,Y2); imp("¼");
}
/**************************************************************************/
void  panta()
{
 delay(150);
 ventana(5,1,76,24);
 textcolor(9);
}
/*****************************************************************/
main()
{
 menu();
}






