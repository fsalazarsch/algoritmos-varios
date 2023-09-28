#include <ctype.h>
#include<iostream.h>
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

void menu();
void crea_lista();
void inser_antes();
void inser_despues();
void inser_entre();
void elim_nodo();
void elim_despues();


void main()
{
 char op;
clrscr();
 while(op!='7')
 {
 clrscr();
 gotoxy(30,5);cout<<"*****MENU  LISTAS  PRINCIPAL********";
 gotoxy(32,7);cout<< "1** CREAR EL NODO ";
 gotoxy(32,8);cout<<  "2** INSERTAR EL NODO ANTES";
 gotoxy(32,9);cout<< "3** INSERTAR EL NODO DESPUES";
 gotoxy(32,10);cout<<"4** INSERTAR ENTRE DOS NODOS ";
 gotoxy(32,11);cout<<"5** ELIMINAR EL NODO ";
 gotoxy(32,12);cout<<"6** ELIMINAR DESPUES ";
 gotoxy(32,13);cout<<"7** SALIR ";
 gotoxy(32,14);cout<<"** DIGITE  UNA OPCION==>>  ";
 op=getchar();
 switch(op)
 {
	  case '1': crea_lista();break;
	  case '2': inser_antes();break;
	  case '3': inser_despues ();break;
	  case '4': inser_entre (); break;
	  case '5': elim_nodo();break;
	  case '6': elim_despues ();break;
	  case '7': break;

    }
   }
 }


/*********************************/
void crea_lista()
 {

  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
	gotoxy(10,5);printf("DIGITE CONTENIDO DEL NODO.....   ");
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

	  gotoxy(10,8);printf("DESEA ADICIONAR OTRO(s/n).....     ");
	  op=toupper(getche());
       }
       while(op!='n'&& op!='N');
       p=cab;
       printf("\n");
  while(p!=NULL){
  printf("%d\t",p->info);
  p=p->sig;
  }

   getche();
 }




/************************************/
void inser_antes(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    gotoxy(10,5);printf("DIGITE EL NODO GUIA.....   ");
    scanf("%d",&num);
    if (p==NULL)
	 {
	 printf("NO  PUEDE INSERTAR EL NODO:");
	 }
	 else{
	 while(p!=NULL){
	 if(p->info==num&&sw==0)
	  {
	  sw=1;
	  gotoxy(10,8);printf("DIGITE NODO A INSERTAR.....   ");
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
	  { gotoxy(10,10);printf("NODO GUIA NO EXISTE :");}
	  getche();
	 }

/***********************************/


 void inser_despues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;
    clrscr();
    gotoxy(10,5);printf("DIGITE NODO GUIA.....   ");
    scanf("%d",&num);

    if (p==NULL)
    {
	gotoxy(10,10);printf(" NO SE PUEDE INSERTAR :");
	}
	else{
	while(p!=NULL){
	 if(p->info== num)
	{sw=1;
	 gotoxy(10,8);printf(" DIGITE  NODO A INSERTAR.....   ");
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
  gotoxy(10,10);printf("  EL NODO DADO NO EXISTE :");}
  getche();
}
 void inser_entre(){

    int sw=0;
    struct nodo *nuevo;
    p=cab;
    q=p->sig;
    clrscr();
    gotoxy(10,5);printf("DIGITE NODO GUIA....  ");
    scanf("%d",&num);
	if (p==NULL)
	  {
	  gotoxy(10,10);printf("NO SE PUEDE INSERTAR  NODO:");
	  }
	 else{
	 while(p!=NULL){
	 if(p->info==num&&sw==0)
	 {
	 sw=1;
	 gotoxy(10,8);printf("DIGITE NODO A INSERTAR..... ");
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
	}else { gotoxy(10,10);printf("EL NODO GUIA NO SE ENCONTRO");}
	getche();
   }
/********************************/
void elim_nodo(){
int sw=0;
   struct nodo *nuevo;
   p=cab;q=cab;
   clrscr();
   gotoxy(10,5);printf("DIGITE NODO A ELIMINAR....   ");
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
	 gotoxy(10,10);printf("EL NODO HA SIDO ELIMINADO....  ");
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
	 }else { gotoxy(10,8);printf("EL NODO GUIA NO SE ENCONTRO");}
	 getche();
	 }
/**************************************/
void elim_despues(){
    int sw=0;
    struct nodo *nuevo;
    p=cab;
    q=p->sig;
    clrscr();
    gotoxy(10,5);printf("DIGITE NODO GUIA...   ");
    scanf("%d",&num);
	if (p->sig==NULL)
	{
	gotoxy(10,10);printf("NO SE PUEDE ELIMINAR ");
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
	 } gotoxy(10,10);printf("EL NODO HA SIDO ELIMINADO....   ");
	 }
   if(sw==1){
    p=cab;
    while(p!=NULL){
    printf("%d\t",p->info);
    p=p->sig;
    }
    }
    else {
	gotoxy(10,8);printf("NODO GUIA NO SE ENCONTRO");
	}
	getche();
    }

