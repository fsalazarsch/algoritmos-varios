#include<dos.h>
#include<alloc.h>
#include<iostream.h>
#include<ctype.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define MAXIMO 30
#define memo (struct nodo *) malloc (sizeof (struct nodo))
#define limp clrscr() 
#define colp textbackground  
#define col  textcolor 
#define imp  cprintf 
#define pos  gotoxy 

    struct NODO {
					long codigo;
					char *nombre;
					struct NODO *Izq;
					struct NODO *Der;
    };


	 struct NODO *cabeza1,*cabeza2,*p,*q,*nn;
	  int sw=0;
	  char op;
	  char a[20];
	  int z,r;
 long cod;
 char nombre[50];
 void musica();
 void cuadro();
 void captura();
 void elimina();
 void imprime();
 int  evaluar(long cod);
 void valida(int posx,int posy,int tipo_captura,struct NODO *aux);


//*****************************************

void  imprime() 
 {
	 if(cabeza1!=NULL)
	 {
	  p=cabeza1;
	  while(p->Der!=cabeza1)
	  {
		 clrscr();
		 printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
		 getch();
		 p=p->Der;
		}
		if(p!=NULL){
		clrscr();
		printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
		getch();
	}
}
	else
	{
	clrscr();
	pos(10,10);printf("LISTA VACIA  ");
	}
	getch();
	
}
//***************
int evaluar(long cod){
	  int sw=0;
	if(cabeza1==NULL)
	return 0;
	else{
	  p=cabeza1;
	  while(p->Der!=cabeza1 && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->Der;
					   }
	  if(sw==1)
	  return 1; 
			if(sw==0)
		   if(p->codigo==cod)
			return 1;
			    }
		return 0;
	}


//**********************************************************/

void valida(int posx,int posy,int tipo_captura,struct NODO *aux)
		{
		int sw=0,i,control;
		char *auxiliar;
		switch(tipo_captura){
			  case 1:{do{
			  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				 if(isdigit(auxiliar[i])==0){
				    sw=1;
				    break;
				    }

				 }while(sw!=1);
				if(sw==1){
				control=sw;
				sw=0;
				}

				}while(control!=1);
				strcpy(aux->nombre,auxiliar);
				break;
				}
			  case 2:{
				  do{
				  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				    if(isdigit(auxiliar[i])==0){
					sw=1;
					break;
					}
				 }while(sw!=0);
				if(sw==1){
				control=sw;
				sw=0;
				}
				}while(control!=0);
				aux->codigo=atol(auxiliar);
				break;
				}
			    }
			 }

//**********************************************************
void elimina(){

			 int sw=0;
				clrscr();
				gotoxy(10,15);
				printf("ELIMINE CODIGO ?..  ");
			  do{
			  z=0;r=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);

		p=cabeza1;
			q=NULL;
			while(p->Der!=cabeza1 && sw==0)
			  if(p->codigo==cod)
				sw=1;
				else{
					 q=p;
					 p=p->Der;
					 }
			if(q==NULL){
				if(p->Der==cabeza1 && p->codigo==cod && sw==0)
					 cabeza1=NULL;
				 else
				  if(p->Der!=cabeza1 && p->codigo==cod && sw==1){
						 q=p->Izq;
						 q->Der=p->Der;
						 q=q->Der;
						 q->Izq=p->Izq;
						 cabeza1=p->Der;
						  delete(p);
						  }
				  }else
					if(p->Der==cabeza1 && p->codigo==cod && sw==0){
						 q->Der=p->Der;
						 q=q->Der;
						 q->Izq=p->Izq;
						 delete(p);
						 }
						 else{
						 if(sw==1){
						 q->Der=p->Der;
						 q=q->Der;
						 q->Izq=p->Izq;
						 delete(p);
						 }
						 }

	do{
	sw=0;
	gotoxy(10,15);
	printf(" Desea Continuar S/N ");
	op=toupper(getch());
	if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
	if(op=='S')
	elimina();
}
//***************
void captura(){ 
	 int sw=0;
	 limp;
	 nn= new NODO;
	 do{
	 gotoxy(5,10);
	 printf("DIGITE CODIGO  ");

	if(sw==1){
	gotoxy(15,15);
	musica();
	col(10+128);printf(" REPETIDO");
	getch();
	limp;
	clreol();
	}
	 valida(25,10,2,nn);
	}while((sw=evaluar(nn->codigo))==1);
	 gotoxy(5,12);
	 printf("DIGITE NOMBRE  ");
	valida(25,12,1,nn);
	  nn->Izq=nn->Der=NULL;
	  if(cabeza1==NULL)
	   {
		cabeza1=nn;
		nn->Izq=cabeza1;
		nn->Der=cabeza1;
	   }
		else{
			p=cabeza1;
			while(p->Der!=cabeza1){
			    p=p->Der;
						  }
			p->Der=nn;
			nn->Der=cabeza1;
			nn->Izq=p;
		    }


   do{
   sw=0;
	gotoxy(35,23);
	printf(" CONTINUAR [s/n)");
	op=toupper(getch());	
		if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	captura();
 }
void musica()
{
sound(480);
delay(1000);
nosound();
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
   pos(20,20);imp("          ROBERTO GIMENEZ                ");
   pos(20,21);imp("                                         ");
   col(10);
	pos(20,22);imp("       VALLEDUPAR NOV 10 1998            ");
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
	pos(20,11);imp("       LISTA CIRCULAR  DOBLES               ");
	pos(20,12);imp("                                            ");
	pos(20,13);imp("                                            ");
	pos(20,14);imp("        1.Captura                           ");
	pos(20,15);imp("        2.Elimina                           ");
	pos(20,16);imp("        3.Consulta                          ");
	pos(20,17);imp("        4.Salir                             ");
	pos(20,18);imp("                                            ");
	pos(20,19);imp("                                            ");
   pos(20,20);imp("          ELIJA OPCION  [ ]                 ");
   pos(20,21);imp("                                            ");
   pos(20,22);imp(" Elaborado por: JAIME RINCON B.  S 3 A      ");
   col(15);pos(45,20);op=getchar();op=toupper(op);
   switch(op)
   {
	  case '1' :colp(1);col(15);captura();break;
	  case '2' :colp(1);col(15);elimina();break;
	  case '3' :colp(1);col(15);imprime();break;
	  case '4' :return;
	}
  }
}
void main()
{
  menu();
}
