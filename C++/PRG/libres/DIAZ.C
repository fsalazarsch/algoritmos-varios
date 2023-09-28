#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
//#include<iostream.h>
#include<ctype.h>
#include<stdlib.h>

/********************************************************************/
#define salir '7'
/********************************************************************/
#define memo (struct nodo *) malloc (sizeof (struct nodo))

struct nodo{
 int info;
 struct nodo *sig;
 };
 struct nodo *p,*q,*cab;
 int n; int num;
  void cap_lista();
  void inser_despues();
  void inser_antes();
  void inser_entre();
  void eli_nodo();
  void eli_despues();

void Menu_principal();



/*********************************************************/
//void cuadro(int x1,int x2,int y1,int y2);
//int validar(int x,int y,int ancho);
/********************************************************************/
void cuadro(int x1,int x2,int y1,int y2)
{
  int j,i,k;
  textcolor(4);

  for(j=x1;j<=x2;j++)
 {
   textcolor(4);
   gotoxy(j,y1);delay(6);cprintf("Í");
   gotoxy(j,y2);delay(6);cprintf("Í");
 }
   for(i=y1;i<=y2-1;i++)
 {
   textcolor(4);
   gotoxy(x1,i);delay(6);cprintf("º");
   gotoxy(x2,i);delay(6);cprintf("º");
 }
   textcolor(4);
   gotoxy(x1,y1);delay(6);cprintf("É");
   gotoxy(x2,y1);delay(6);cprintf("»");
   gotoxy(x1,y2);delay(6);cprintf("È");
   gotoxy(x2,y2);delay(6);cprintf("¼");

}
/****************************INICIALIZACON DEL PROGRAMA****************/
//void Menu_principal();
/*********************************************************************/
void Menu_principal()
{
  char res,op;

  while(1)
 {
   clrscr();
   cuadro(2,78,2,24);
   cuadro(29,50,4,6);
   cuadro(7,72,7,21);
   cuadro(8,71,8,20);
   cuadro(9,70,9,19);
   gotoxy(33,5);textcolor(15+128);cprintf ("MENU PRINCIPAL\n");
   gotoxy(19,10);textcolor(3);cprintf ("1. CAPTURAR LISTA  ");
   gotoxy(19,11);textcolor(3);cprintf ("2. INSERTAR DESPUES \n  ");
   gotoxy(19,12);textcolor(3);cprintf ("3. INSERTAR ANTES\n   ");
   gotoxy(19,13);textcolor(3);cprintf ("4. INSERTAR ENTRE \n  ");
   gotoxy(19,14);textcolor(3);cprintf ("5. ELIMINAR UN NODO \n   ");
   gotoxy(19,15);textcolor(3);cprintf ("6. ELIMINAR DESPUES DE UN NODO\n   ");
   gotoxy(45,18);textcolor(15);cprintf ("DIGITE UNA OPCION:[ ]");
   gotoxy(19,16);textcolor(3);cprintf ("7. S A L I R\n");
   gotoxy (64,18);op=getchar();op=toupper(op);
   switch(op)
 {
   case '1':
	 cap_lista();
	 break;
   case '2':
	inser_despues();
	 break;
   case '3':
	  inser_antes();
	 break;
   case'4':
	  inser_entre();
	  break;
   case'5':
	    eli_nodo();
	    break;
   case'6':
	   eli_despues();
	   break;
    case  salir: exit(0);


 }

}
}


void main()
{
 clrscr();
 Menu_principal();
}
/***************************CAPTURA  DE DATOS******************************/
 void cap_lista()
 {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
     gotoxy(20,13);  printf("DIGITE EL NODO :");
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
      gotoxy(20,15);
     printf("DESEA ADICIONAR NODO(s/n):");
      op=toupper(getche());
    }while(op!='n'&& op!='N');
     p=cab;
     printf("\n");
  while(p!=NULL)
    {
     printf("%d\t",p->info);
  p=p->sig;
  }
    getche();
 }
 /*******************INSERTAR DESPUES DE UN NODO DADO*********************/
  void inser_despues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    printf("DIGITE EL NODO REFERENCIA  :");
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
/**********************INSERTAR ANTES DE UN NODO DADO**********************/
void inser_antes(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    printf("DIGITE EL NODO REFERENCIA :");
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
	  { printf("NODO REFERENCIA NO EXISTE :");}
	  getche();
	 }
/*****************INSERTAR ENTRE DOS NODOS DADOS**************************/

 void inser_entre(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    q=p->sig;
    clrscr();
    printf("DIGITE EL NODO REFERENCIA :");
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
     }else { printf("EL NODO REFERENCIA NO EXISTE  :");}
     getche();
   }
/*************************ELIMINA DESPUES DE UN NODO***********************/
void eli_despues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;q=p->sig;
    clrscr();
    printf("DIGITE EL NODO REFERENCIA :");
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
  }else { printf("NODO REFERENCIA NO EXISTE :");}


    getche();

}

/******************************ELIMINA NODO*****************************/
void eli_nodo(){


   int sw=0;
   struct nodo *nuevo;
   p=cab;q=cab;
clrscr();
    printf("DIGITE EL NODO A ELIMINAR :");
     scanf("%d",&num);



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



	if(sw==1){


   p=cab;
   while(p!=NULL){

    printf("%d\t",p->info);
   p=p->sig;

  }
  }else { printf("EL NODO REFERENCIA NO EXISTE :");}


    getche();

}



