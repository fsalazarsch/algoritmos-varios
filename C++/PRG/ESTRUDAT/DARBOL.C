
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include "fcntl.h"
#include<process.h>
#include "io.h"
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
/**********************************************************************/

  struct tree
  {
    int COD;
    struct tree *izquierdo,*derecho;
  }nuevo, *raiz,*nn,*p;

  void cuadros(int x1,int x2,int y1,int y2);
  void preorden(struct tree *auxiliar);
  void posorden(struct tree *auxiliar);
  void inorden(struct tree *auxiliar);
  void adicionar_nodo();
  void eliminar();
  void menu();
  char ve[3];
  

/**********************************************************************/


/**********************************************************************/
void adicionar_nodo()
  {
  char op,CODIGO[3];
  int COD,i;
  

   do{
   i=0;
      clrscr();
   textbackground(0);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 textbackground(15);  
 textcolor(4);  
  
  gotoxy(22,7);cprintf("DIGITE EL NODO A INGRESAR: ");
  
  do{
    
   gotoxy(35,7);
     gotoxy(50,7);cprintf("                     ");
     //clreol();
     
    CODIGO[i]=getche();
    if(CODIGO[i]=='\b'&&i>0) i-=2;
    else
     {
     if(CODIGO[i]=='\r'&&i>0) break;
     if(!isdigit(CODIGO[i])) i--;
     }
    i++;
  }while(i<2);
  CODIGO[i]='\0';
  COD=atoi(CODIGO);
  p=nn=raiz;i=1;
  while((COD!=p->COD)&&(nn!=NULL)&&(i<=6))
  {
    p=nn;
    if(COD<p->COD)
      nn=p->izquierdo;
    else
      nn=p->derecho;
    i++;
  }
  if(COD==p->COD)
    {
    gotoxy(20,12);printf("<< ESTE NODO YA EXISTE >>");
    }
  else
   if(i==6)
     {
     gotoxy(14,12);printf("EL NODO QUE A DIGITADO NO SE PUEDE INGRESAR");}
   else
   {
   nn=malloc(sizeof(nuevo));
     nn->COD=COD;
     nn->izquierdo=nn->derecho=NULL;
     if(raiz==NULL)
       raiz=nn;
     else
     { if(COD<p->COD)
	p->izquierdo=nn;
       else
	p->derecho=nn;
     }
     gotoxy(20,12);printf("<< NODO INGRESADO >>");
   }
 gotoxy(15,15);printf("DESEA INGRESAR OTRO NODO  [S/N]: ");
 gotoxy(1,1);op=toupper(getche());
 }while(op!='N');
/* do
 {
     gotoxy(1,1);op=toupper(getche());
 adicionar_nodo();}
 //else{void menu();}
 }while(op!='N');

 if(op=='S') {
 clrscr();
 textcolor(4);
 adicionar_nodo();}
 else{void menu();}*/
}

  
/**********************************************************************/

void inorden(struct tree *auxiliar)
{
  if(auxiliar!=NULL)
  {
    inorden(auxiliar->izquierdo);
printf("%d\t  ",auxiliar->COD);
 inorden(auxiliar->derecho);
  }
 
}

/**********************************************************************/

void preorden(struct tree *auxiliar)
{
 if(auxiliar!=NULL)
  { 
    printf("%d\t  ",auxiliar->COD);
    preorden(auxiliar->izquierdo);
    preorden(auxiliar->derecho);
  }

}

/**********************************************************************/

void posorden(struct tree *auxiliar)
{
  if(auxiliar!=NULL)
  { 
  posorden(auxiliar->izquierdo);
    posorden(auxiliar->derecho);

  printf("%d\t  ",auxiliar->COD);
    
  }

}

/**********************************************************************/

void eliminar()
{
  char op,CODIGO[3];
  int COD,i;
  struct tree *q,*s,*f;
  do
  {
  clrscr();
   textbackground(0);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
 textbackground(15);  
  textcolor(4);
  gotoxy(30,5);printf("<< ELIMINAR NODOS >>");
  gotoxy(22,7);printf("DIGITE NODO A ELIMINAR : ");
  do
  {
    CODIGO[i]=getche();
    if(CODIGO[i]=='\b'&&i>0) i-=2;
    else
     { if(CODIGO[i]=='\r'&&i>0) break;
       if(!isdigit(CODIGO[i])) i--;
     }
    i++;
  }while(i<2);
  CODIGO[i]='\0';
  COD=atoi(CODIGO);
  f=NULL;
  p=nn=raiz;
  while((COD!=p->COD)&&(nn!=NULL))
  { f=p;
    p=nn;
    if(COD<p->COD)
      nn=p->izquierdo;
    else
      nn=p->derecho;
  }
  if(COD!=p->COD){
    gotoxy(22,18);printf("<< EL NODO DIGITADO NO EXISTE >>");
  sound(2000);
    delay(1000);
    nosound();
  }
  else {
  
      if(p->izquierdo==NULL)
      nn=p->derecho;
    
    else
      if(p->derecho==NULL)
	nn=p->izquierdo; 
      else
      { q=p;
	nn=q->derecho;
	s=nn->izquierdo;
	while(s!=NULL)
	{
	  q=nn;
	  nn=s;
	  s=nn->izquierdo;
	}
	if(q!=p)
	{
	  q->izquierdo=nn->derecho;
	  nn->derecho=p->derecho;
	}
	nn->izquierdo=p->izquierdo;
      }
      if(f==NULL)
	raiz=nn;
      else
	{ if(p==f->izquierdo) f->izquierdo=nn;
	  else f->derecho=nn;
	}
    p->izquierdo=p->derecho=NULL;
    free(p);
    gotoxy(22,18);printf("<< N0DO ELIMINADO >>");
    sound(2000);
    delay(1000);
    nosound();
  }
gotoxy(22,20); printf("DESEA ELIMINAR OTRO NODO: [S/N]: ");
   op=toupper(getche());

   }while(op!='N');
}

  
  

/**********************************************************************/
/**********************************************************************/

void menu()
{
   char op;
 do{
 clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 cuadros(2,79,2,23);
 cuadros(5,76,4,21);
 cuadros(8,73,6,19);
  
    textcolor(4);
    //normvideo;
    gotoxy (30,8); printf("<< MENU PRINCIPAL >>");
    
  gotoxy(22,3);printf("CORPORACION UNIVERSITARIA DEL SANTANDER");  
  gotoxy(29,5);printf("DARWIN HELMUTHS LEON PEREZ");
  gotoxy(32,22);printf("CODIGO: 96132068");
  gotoxy(28,10);printf("[1]. ADICIONAR UN NODO");
  gotoxy(28,11);printf("[2]. REC.PREORDEN");
  gotoxy(28,12);printf("[3]. REC.INORDEN");
  gotoxy(28,13);printf("[4]. REC. POSORDEN");
  gotoxy(28,14);printf("[5]. ELIMINAR UN NODO");
  gotoxy(28,15);printf("[6]. SALIR DEL PROGRAMA..");
  
    
    gotoxy (28,18); printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case'1':adicionar_nodo();break;
   case'2':{
   clrscr();
 gotoxy (30,7);printf("<< RECORRIDO PREORDEN >> \n");
   preorden(raiz); getch(); break;}
   case'3':{
      clrscr();
 gotoxy (30,7);printf("<< RECORRIDO INORDEN >> \n");

   inorden(raiz); getch(); break;}
   case'4':{
      clrscr();
 gotoxy (30,7);printf("<< RECORRIDO POSORDEN >> \n");

   posorden(raiz); getch(); break;}
   case'5':eliminar();break;
   case'6':exit(0);
    getche();  
     }
     }while(op!='8');
   
     }

   
/**********************************************************************/

/**********************************************************************/

void main()
{
  menu();
}
/**********************************************************************/
 void cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(15);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
}
