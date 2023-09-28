#include "ctype.h"
#include "iostream.h"
#include "alloc.h"
#include "stdio.h"
#include "conio.h"
#include "dos.h"
#define localizar (struct nodo*)malloc(sizeof (struct nodo))

struct nodo{
 int info;
 char nombre[15];
 struct nodo *sig;
 };
 int n;
 int codigo[8];
 char nombre[15];
 struct nodo *p,*q,*cab,*sig;
 /*****************************************************************/
  void cuadro();
  void crear_lista();
  void adicionar();
//  void eliminar();  
 /******************************************************************/
     void crea_lista()
  {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
	q=localizar;
	printf("DIGITE CODIGO :");
	scanf("%d",&q->info);
	fflush(stdin);
	printf("DIGITE EL NOMBRE :");
	gets(q->nombre);

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

	printf("DESEA ADICIONAR OTRO(s/n):");
	 op=toupper(getche());
    }while(op!='n'&& op!='N');
	p=cab;
	printf("\n");
  while(p!=NULL){
  printf("%d\t",p->info);
  puts(p->nombre);
  p=p->sig;
  }
    getche();
 }

 /****************************************************************/
    void adicionar()
   {
  struct nodo *ins(p);
    struct nodo *p;
      {	 int n;
 
	 struct nodo *nuevo;
	 nuevo=localizar;
	 scanf("%d",&q->info);
	 gets(q->nombre);
	 
	 if(p==NULL)
	  nuevo->sig=nuevo;
	 else
	 {
	  nuevo->sig=p->sig;
	  p->sig=nuevo;
	 }
	  p=nuevo;
	  getche();
 
 }
 
   
 /****************************************************************/
/*void eliminar() 
	{
	struct (cab,p,dato);
	  struct nodo **cab,p;
	  int *dato;
	  {
	  struct nodo *q;
	if(*cab=NULL)
	 printf("no se puede retirar");
	  else
	if(p==NULL)
	 printf("no se pude retirar");
	  else
	if(*cab==(*cab)->sig)
	 printf("un solo nodo no se puede retirar");
	  else
	   q=p->sig;
	   *dato=q->info;
	   p->sig=q->sig;
	    if(q==*cab);
	    *cab=p;
	    free(q);
	 }
	dato=p->info;
	cab->sig=p->sig;
	free(p);
	getche();
	}*/


   
   
 /******************************************************************/  
 void cuadro();
 { int c,f;

 textcolor(10);gotoxy(30,8);cout<<"M E N U   P R I N C I P A L";
					
 for(c=16;c<65;c++)
    {
     gotoxy(c,7);cout<<"Í";
     gotoxy(c,9);cout<<"Í";
     gotoxy(c,20);cout<<"Í";
    }

   for(f=8;f<20;f++)
    {gotoxy(15,f);cout<<"º";
     gotoxy(65,f);cout<<"º";
    }
					    /*ESQUINAS*/
    gotoxy(15,7);cout<<"É";
    gotoxy(65,7);cout<<"»";
    gotoxy(15,9);cout<<"Ì";
    gotoxy(65,9);cout<<"¹";
    gotoxy(15,20);cout<<"È";
    gotoxy(65,20);cout<<"¼";

}
/******************************************************************/
void menu();
{ int op;
 do
 {
 clrscr();
 cuadro();
 gotoxy(30,12);
 cout<<"1. CREAR LISTA ";
 gotoxy(30,13);
 cout<<"2. ADICIONAR ";
 gotoxy(30,14);
 cout<<"3. ELIMINAR ";
 gotoxy(30,15);
 cout<<"4. SALIR ";
 gotoxy(30,18);
 cout<<"ESCOJA UNA OPCION... ";
 cin>>op;

   
     switch(op)
     {

       case 1: 
	       crear_lista();
	       break;
       case 2:
	      adicionar();
	      break;
      /* case 3:
	      eliminar();
	      break;*/

       case 4:
	      break;

	default:clrscr();
		gotoxy(30,30);
		cout<<"Opcion Errada ";
		getch();
		break;

	}  
	
	  } while(op!=4);
   }  

 /****************************************************************/

void main();
{ clrscr();
 menu();
 } 
   
  
 /****************************************************************/
 