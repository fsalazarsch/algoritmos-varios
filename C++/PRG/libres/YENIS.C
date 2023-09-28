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
  void visualizar();
  void inseantes();
  void insedespues();
  void inserentre();
  void eliminodo();
  void elimidespues();
   void main(){
      char op;

 do{
   clrscr();     // textmode(C40);
   gotoxy(30,9);printf ("1.CREAR LISTA");
   gotoxy(30,10);printf("2.VISUALIZAR");
   gotoxy(30,11);printf("3.INSERTAR ANTES DE UN NODO");
   gotoxy(30,12);printf("4.INSERTAR DESPUES DE UN NODO");
   gotoxy(30,13);printf("5.INSERTAR ENTRE DOS  NODOS");
   gotoxy(30,14);printf("6.ELIMINAR DESPUES DEL NODO");
   gotoxy(30,15);printf("7.ELIMINAR EL NODO");
   gotoxy(30,16);printf("8.SALIR DEL PROGRAMA");

   gotoxy(26,21);printf("DIGITE LA OPCION QUE DESEE==>:");op=getche();
      switch(op)
   {
     case '1':  {clrscr();captura();break;}
     case '2':  {clrscr();visualizar();break; }
     case '3':  {clrscr();insedespues();break;}
     case '4':  {clrscr();inseantes();break;}
     case '5':  {clrscr();inserentre();break;}
     case '6':  {clrscr();elimidespues();break;}
     case '7':  {clrscr();eliminodo();break;}
     case '8':  return;
     }
}while(op!='7');
}
 //*******************************CUADRO*********************************//
 void cuadro(int x1,int x2,int y1,int y2)
{    int j,i,k;
      textbackground(4);
      textcolor(0);
     for(j=x1;j<=x2;j++)
       { //delay(2);
       gotoxy(j,y1);cprintf("Ä");
       gotoxy(j,y2);cprintf("Ä");
       }
	for(i=y1;i<=y2-1;i++)
       {  //delay(2);
	 gotoxy(x1,i);cprintf("³");
	 gotoxy(x2,i);cprintf("³");
       }
	gotoxy(x1,y1);cprintf("Ú");
	gotoxy(x2,y1);cprintf("¿");
	gotoxy(x1,y2);cprintf("À");
	gotoxy(x2,y2);cprintf("Ù");
	getche();
    }
 //*******************************VISUALIZAR*****************************//
void visualizar()
	   {
	    struct nodo *nuevo;
	    p=cab;q=cab;
	    clrscr();
	    while(p!=NULL){
	    printf("%d\t",p->info);
	    p=p->sig;  }
	    getche();
	  }
 //******************************CAPTURA*********************************//
 void captura()
 {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
     clrscr();
     printf("ESCRIBA EL NODO A CREAR ==>");
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
      op=toupper(getch());
      getche();
    }while(op!='n'&& op!='N');
    getche();
 }
//*******************************INSERTA ANTES**************************//
void inseantes(){
int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    printf("DIGITE EL NODO DE GUIA ==> :");
    scanf("%d",&num);

    if (p==NULL)
    {
     printf(" <<IMPOSIBLE INSERTAR  NODO >>:");
     }
     else{
     while(p!=NULL){
      if(p->info== num)
     {sw=1;
      printf(" ESCRIBA LA INFORMACION DEL NODO ==> ");
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
  printf(" << LA INFORMACION  DEL NODO CONSULTADO NO EXISTE >>");}
  getche();
}
//*****************************INSERTA DESPUES****************************//
void insedespues(){
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
       printf("ESCRIBA EL DATO DEL NODO :");
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
	  { printf("NODO SE¥AL NO EXISTE :");}
	  getche();
	 }
//******************************INSERTA ENTRE DOS NODOS*******************//
 void inserentre(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    q=p->sig;
    clrscr();
    printf("ESCRIBA EL NODO GUIA :");
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
      printf("ESCRIBA LA INFORMACION DEL NODO :");
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

//**************************ELIMINA NODO SIGUIENTE*************************//
void elimidespues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;q=p->sig;
    clrscr();
    printf("ESCRIBA EL NODO SE¥AL :");
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
//******************************ELIMINAR NODO*****************************//
void eliminodo(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;q=cab;
    clrscr();
    printf("ESCRIBA EL NODO A ELIMINAR :");
     scanf("%d",&num);
     while(p!=NULL){
     if(p->info== num)
     {sw=1;
     if(p->sig==NULL)
     { q->sig=NULL;
       free(p);
       }else{
    // dato=q->info;
     q->sig=p->sig;
     free(p);
     printf("HA SIDO ELIMINADO EL NODO :");
   }
   }
    q=p;
    p=p->sig;
   }

 //  }
	if(sw==1){
   p=cab;
   while(p!=NULL){
   printf("%d\t",p->info);
   p=p->sig;

  }
  }else { printf("NODO GUIA NO EXISTE :");}
   getche();
 }
