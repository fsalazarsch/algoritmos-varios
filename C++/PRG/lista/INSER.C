#include <ctype.h>
#include <stdio.h>
#include <io.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#define memo (struct nodo *) malloc (sizeof (struct nodo))
struct nodo{
 int info;
 struct nodo *sig;
 };
 struct nodo *p,*q,*cab;
 int n; int num;
  void captura();
  void menu1();
  void insedespues();
  void inseantes();
  void inserentre();
  void eliminodo();
  void elimidespues();
  void cuadro();  




   void main(){
   clrscr();
   menu1();
   }
/**********************************CUADRO*********************************/
 void cuadro(int x1,int x2,int y1,int  y2)
{   
    /* int j,i;
     textcolor(10);textbackground(1);
     for(j=x1;j<=x2;j++)
       {
       gotoxy(j,y1);cprintf("=");
       gotoxy(j,y2);cprintf("=");
       }
     for(i=y1;i<=y2-1;i++)
       {
       gotoxy(x1,i);cprintf("*");
       gotoxy(x2,i);cprintf("*");
       }
     gotoxy(x1,y1);cprintf("*");
     gotoxy(x2,y1);cprintf("*");
     gotoxy(x1,y2);cprintf("*");
     gotoxy(x2,y2);cprintf("*");*/


} 
 /***************************MENU PRINCIPAL*********************************/
void menu1()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(4); textbackground(2);

  do{
  clrscr();
  strcpy(opciones[10], " ADICIONAR LISTA             ");
  strcpy(opciones[11], " ADICIONAR DESPUES DE UN NODO");
  strcpy(opciones[12], " ADICIONAR ANTES             ");
  strcpy(opciones[13], " ADICIONAR ENTRE DOS NODO    ");
  strcpy(opciones[14], " ELIMINAR DESPUES DE UN NODO ");
  strcpy(opciones[15], " ELIMINAR EL NODO            ");
  strcpy(opciones[16], " SALIR                       ");
  textcolor(10);textbackground(0);
  gotoxy(31,20);printf(" Luis Amaya N.");
  gotoxy(31,21);printf("CODIGO 95132101");
  gotoxy(35,22);printf("S  3 A");
	textcolor(9);textbackground(2);
	cuadro(2,79,2,24);
	cuadro(22,52,9,17);
	textcolor(12);textbackground(3);
	for(f=10;f<=16;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(2);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();}
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    {
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=16)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{
		f=16;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       }
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:captura();break;
		      case    11:insedespues();break;
		      case    12:inseantes();break;
		      case    13:inserentre();break;
		      case    14:elimidespues();break;
		      case    15:eliminodo();break;
		     }
	   }while(f !=16);

  }
 /****************************ADICIONAR DATOS*****************************/
 void captura()
 {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
     printf("DIGITE EL NODO :");
     scanf("%d",&n);
     q=memo;
     q->info=n;
     if(cab==NULL){
       cab=q;
       cab->sig=NULL;
       p=q;
    }
    else{
     p->sig=q;
     q->sig=NULL;
     p=p->sig;
     }

     printf("DESEA ADICIONAR NODO(s/n):");
      op=toupper(getche());
    }while(op!='n'&& op!='N');
     p=cab;
     printf("\n");
  while(p!=NULL){
  printf("%d\t",p->info);
  p=p->sig;
  }
    getche();
 }
/***************************ADICIONAR DESPUES*****************************/
  void insedespues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    printf("DIGITE EL NODO GUIA  :");
    scanf("%d",&num);

    if (p==NULL)
    {
     printf(" NO SE PUEDE INSERTAR :");
     }
     else{
     while(p!=NULL){
      if(p->info== num)
     {sw=1;
      printf(" DIGITE EL NODO A INSERTAR:");
      scanf("%d",&n);
      nuevo=memo;
      nuevo->info=n;
      nuevo->sig=p->sig;
      p->sig=nuevo;
      }
      p=p->sig;
     }
  }
  if(sw==1){
  p=cab;
  while(p!=NULL){
  printf("%d\t",p->info);
  p=p->sig;
  }
  }else
  {
  printf("  EL NODO DIGITADO NO EXISTE :");}
  getche();
}
 /*****************************ADICIONAR ANTES******************************/
void inseantes(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    printf("DIGITE EL NODO GUIA :");
    scanf("%d",&num);
    if (p==NULL)
      {
      printf("NO SE PUEDE INSERTAR EL NODO:");
      }
      else{
      while(p!=NULL){
      if(p->info==num&&sw==0)
       {
       sw=1;
       printf("DIGITE EL NODO A INSERTAR:");
       scanf("%d",&n);
      nuevo=memo;
      nuevo->info=p->info;
      nuevo->sig=p->sig;
      p->sig=nuevo;
      p->info=n;
      }
      p=p->sig;
      }
      }
       if(sw==1){
	p=cab;
	while(p!=NULL){
	printf("%d\t",p->info);
	p=p->sig;
	 }
	 }else
	  { printf("NODO GUIA NO EXISTE :");}
	  getche();
	 }

 /********************************ADICIONAR ENTRE DOS**********************/ 
 void inserentre(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    q=p->sig;
    clrscr();
    printf("DIGITE EL NODO GUIA :");
    scanf("%d",&num);
     if (p==NULL)
       {
       printf("NO SE PUEDE INSERTAR EL NODO:");
       }
      else{
      while(p!=NULL){
      if(p->info==num&&sw==0)
      {
      sw=1;
      printf("DIGITE EL NODO A INSERTAR:");
      scanf("%d",&n);
      nuevo=memo;
      nuevo->info=n;
      nuevo->sig=p->sig;
      p->sig=nuevo;
      }
       p=p->sig;
     }
      }
     if(sw==1){
     p=cab;
     while(p!=NULL){
     printf("%d\t",p->info);
     p=p->sig;
     }
     }else { printf("EL NODO GUIA NO EXISTE  :");}
     getche();
   }
/*******************************ELIMINAR DESPUES****************************/
void elimidespues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;q=p->sig;
    clrscr();
    printf("DIGITE EL NODO GUIA :");
    scanf("%d",&num);
     if (p->sig==NULL)
	{
	printf("NO SE PUEDE ELIMINAR EL NODO:");
        }
     else{
         while(p->sig!=NULL){
         if(p->info== num)
          {sw=1;
	  q=p->sig;
         if(q->sig==NULL)
          { p->sig=NULL;
          free(q);
          }else{
          p->sig=q->sig;
          free(q);
          }
      }
      p=p->sig;
      } printf("HA SIDO ELIMINADO EL NODO SIGUIENTE:");
      }
   if(sw==1){
    p=cab;
    while(p!=NULL){
    printf("%d\t",p->info);
    p=p->sig;
    }
    }else { printf("NODO GUIA NO EXISTE :");}
    getche();
    }
/**************************ELIMINAR NODO**********************************/
void eliminodo(){
int sw=0;
   struct nodo *nuevo;
   p=cab;q=cab;
   clrscr();
   printf("DIGITE EL NODO A ELIMINAR :");
   scanf("%d",&num);
   if (cab->info==num)
      {sw=1;
      cab=cab->sig;
      p=cab;
      }
      else
      {
      while(p!=NULL){
      if(p->info== num)
      {sw=1;
      if(p->sig==NULL)
      { q->sig=NULL;
      free(p);
      }else{
      q->sig=p->sig;
      free(p);
      printf("HA SIDO ELIMINADO EL NODO :");
      }
      }
      q=p;
      p=p->sig;
      }     
      }
      if(sw==1){
      p=cab;
      while(p!=NULL){
      printf("%d\t",p->info);
      p=p->sig;
      }
      }else { printf("EL NODO GUIA NO EXISTE :");}
      getche();
      }
