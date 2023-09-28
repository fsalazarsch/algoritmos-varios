
#include<alloc.h>
#include<ctype.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************/
 class alfo{

   struct arbol
   {    int dato;
	char nom[45],ape[45];
	float  n1,n2,n3,n4;
	struct arbol *izquierdo,*derecho;
      }tarbol;
    
   struct arbol *raiz,*nn,*p,*temp;


 public:

alfo(struct arbol *a){raiz=a;}

void insertar();
void posorden();
void inorden();
void suprimir();
float val_not(int z, int w );
void cierre(int ci,int fi,int cf,int ff);
char val(int x, int y);
void marco(x1,y1,x2,y2);
void preorden (struct arbol *p);
void sacar_pila (struct LIFO *p,struct arbol **s);
void ins_pila (struct LIFO *p, struct arbol *s);
void ins_izquierdo (struct arbol *p,int n);
void init_pila (struct LIFO *p);
val_ent();
void ins_derecho (struct arbol *p,int n);
int pila_vacia (struct LIFO *p);
void menu();

};






/*****************************************************************/

 void alfo::insertar()
{ char op,vecto[5],info[3],nom[45],ape[45],valido;
  float n1,n2,n3,n4;
  int i,n,j,dato;
  textcolor(14); textbackground(3);
  textcolor(14);textbackground(3);

   window(1,1,80,25);clrscr();
   cierre(1,1,80,24);
 do{
  clrscr();
  textcolor(14);textbackground(3);

   i=0;
  gotoxy(20,3);cout<<"INTRODUCCION DE DATOS";
  gotoxy(20,5); cout<<"CODIGO......: ";
  
 do
 {  
    
    gotoxy(i+33,5);
    clreol();
    info[i]=getche();
    if(info[i]=='\b'&&i>0) i-=2;
    else
     {
     if(info[i]=='\r'&&i>0) break;
     if(!isdigit(info[i])) i--;
     }
    i++;
  }while(i<5);
  
  info[i]='\0';
  dato=atoi(info);
  p=nn=raiz;i=1;     
  while((dato!=p->dato)&&(nn!=NULL)&&(i<=6))
  {
    p=nn;
    if(dato<p->dato)
      nn=p->izquierdo;
    else

      nn=p->derecho;
    i++;
  }
  if(dato==p->dato)
    {
	 gotoxy(20,12);cout<<"CODIGO  EXISTE";
	 }
  else
   if(i==6)
     {
	  gotoxy(14,12);cout<<"EL NUMERO  NO SE PUEDE INTRODUCIR";
	  }
	
	else
	{  



	do
       {
	valido='n';
	gotoxy(33,6);
	cout<<"             ";
	gotoxy(20,6);cout<<"NOMBRE......:";
	gotoxy(33,6);gets(nom);
	n = strlen(nom);
	for(j=0;j<=n-1; j++)
	  {if(!(isalpha(nom[j])))
	    {
	     gotoxy(29,8);
	     cout<<"ERROR!!";
	     valido='m';
	     getch();
	     gotoxy(29,8);
	     cout<<"              ";
	     break;
	    }
	  }
       }while(valido=='m');

  

	do
       {
	valido='n';
	gotoxy(33,7);
	cout<<"                 ";
	gotoxy(20,7); cout<<"APELLIDO....: ";
	gotoxy(33,7);gets(ape);
	n = strlen(ape);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(ape[j])))
	    {
	     gotoxy(29,8);
	     cout<<"ERROR!!";
	     valido='m';
	     getch();
	     gotoxy(29,8);
	     cout<<"                ";
	     break;
	    }
	  }
       }while(valido=='m');

  


      gotoxy(10,11); cout<<" NOTA #1 ";n1=val_not(13,12);      
      gotoxy(25,11);cout<<" NOTA #2 "; n2=val_not(28,12);
      gotoxy(40,11);cout<<" NOTA #3 ";n3=val_not(43,12); 
      gotoxy(55,11);cout<<" NOTA #4 ";n4=val_not(58,12); 
 
  

     nn=new arbol;
     nn->dato= dato;
     strcpy(nn->nom,nom);
     strcpy(nn->ape,ape);

     nn->n1=n1;
     nn->n2=n2;
     nn->n3=n3;
     nn->n4=n4;
     nn->izquierdo=nn->derecho=NULL;
  


  
     if(raiz==NULL)
       raiz=nn;
     else
     { if(dato<p->dato)
	p->izquierdo=nn;
       else
	p->derecho=nn;
     }
     gotoxy(29,20);printf(" NODO INSERTADO..! ");

   }

   gotoxy(18,22);printf(" DESEA ADICIONAR OTRO NODO <<S/N>>");
    op=toupper(getche());

   }while(op!='N');

}
/****************************ELMINAR***************************************/
void alfo::suprimir()
{ }




 /**********************************************************************/
main(){
int i;
clrscr();
alfo obj(NULL);
obj. menu();
}


 /***********************************POSTORDEN******************************/

void alfo::posorden()
{  }


/******************************INORDEN*************************************/
void alfo::inorden()
{
}


/*************************************************************************/
void alfo::menu()
{ char op,tecla,SALIR;
  int u,i;
 do
 { window(1,1,80,24);
   textbackground(128);

   textcolor(9);

   clrscr();
   SALIR='N';
  cierre(1,1,80,25);
  gotoxy(2,24);textcolor(3);
  gotoxy(1,24);cprintf("ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
  gotoxy(2,24);textcolor(15);textbackground(3);
  cprintf("[UTILICE EL CURSOR(%c%c) Y PRESIONE <ENTER>]",24,25);
  
  textbackground(0);
  gotoxy(1,80);textcolor(3);
    for(i=1;i<=80;i++)
   {gotoxy(1,24);textcolor(3);
    gotoxy(i,1);cprintf("л");}


  //gotoxy(1,1);cprintf("ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
  gotoxy(1,80);textcolor(15);textbackground(3);
  gotoxy(14,1);cprintf("  M   E   N   U       P   R   I   N   C   I   P   A   L");
		
  textbackground(0);
  window(25,11,57,18);clrscr();//marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,2);
  cprintf(" ADICIONAR ");
  gotoxy(4,3);
  cprintf(" PREORDEN");
  gotoxy(4,4);
  cprintf(" POSTORDEN ");
  gotoxy(4,5);
  cprintf(" INORDEN");
  gotoxy(4,6);
  cprintf(" ELIMINAR");
  gotoxy(4,7);
  cprintf(" SALIR");

  textcolor(12);
  gotoxy(3,2);cprintf("");gotoxy(3,2);

 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(3,wherey()+5);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==7)
	  {
	     gotoxy(3,wherey()-5);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==7)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:insertar();break;
       case 3:preorden(raiz);getch();break;
       //case 4:mostrar_tres();break;
       //case 5:mostrar_uno();break;
       //case 6:suprimir();break;

      }

  }
    } while(SALIR!='S');
}

/*************************************************************************/
float alfo::val_not(int z, int w )
 { int i,n,sw;
   char nota[10];
   float not;
 do
 {
  do
   {
    gotoxy(z,w);sw=0;
    clreol();
    scanf("\n");
    gets(nota);
    if(isdigit(nota[0])==0) sw=1;
    else 
      { if((nota[1]!='.')&&(( n=strlen(nota)-1) > 0 )) sw=1;
	else                                    
	 { n=strlen(nota);
	   if(n>1)
	    { for(i=2;i<n;i++)
	       if(isdigit(nota[i])==0) sw=1;
	    }
	 }
      }
   }while(sw==1);
  not=atof(nota);
    if((not>5)||(not<0))
      sw=1; 
   }while(sw==1);
return(not);
}

/************************************************************************/

char alfo::val(int x, int y)
{ char *cad;
  
  int n,sw,j;

  do
  { gotoxy(x,y);sw=0;clreol();
    scanf("\n");gets(cad);
    n=strlen(cad);
    for(j=0;j<n;j++)
     if(isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
  return(atoi(cad));
} 

/***************************************************************************/
void alfo::cierre(int ci,int fi,int cf,int ff)
{int i,j;

 for(i=fi;i<=ff;i++)      
  { for(j=ci;j<=cf;j++)
      {gotoxy(j,i);printf("А");}
      }
  gotoxy(cf,ff);printf("А");
}
/***************************************************************************/
void alfo::marco(x1,y1,x2,y2)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=x1;i<=x2;i++)
 {
  delay(4); gotoxy(i,y1); printf("Э");
  delay(4); gotoxy(i,y2); printf("Э");
  }
 for(i=y1;i<=y2;i++)
 {
  delay(4); gotoxy(x1,i); printf("К");
  delay(4); gotoxy(x2,i); printf("К");
  }
 gotoxy(x1,y1); printf("Щ");
 gotoxy(x1,y2); printf("Ш");
 gotoxy(x2,y1); printf("Л");
 gotoxy(x2,y2); printf("М");
 textcolor(14); textbackground(0);
 }


/**************************************************************************/
int alfo::val_ent() {
	char aux[20];
	gets (aux);
	return atoi(aux);
}

/****************************************************************/


void ins_izquierdo (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izquierdo = NULL;
	nuevo->derecho = NULL;
	p->izquierdo = nuevo;
}

/****************************************************************/

void ins_derecho (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izquierdo = NULL;
	nuevo->derecho = NULL;
	p->derecho = nuevo;
}
/****************************************************************/


#define MAXIMO 20

struct LIFO {
	int t;
	struct arbol *a[MAXIMO];
};



/*************************************PREORDEN***************************/

void alfo::preorden (struct arbol *p)
{
int l;
struct LIFO pila;
void init_pila (struct LIFO *p);
int pila_vacia (struct LIFO *p);
void ins_pila (struct LIFO *p, struct arbol *s);
void sacar_pila (struct LIFO *p,struct arbol **s);
init_pila (&pila);
window(1,1,80,24);
 textbackground(128);	
clrscr();
 l=7;
 
  gotoxy(13,3);cprintf("R  E  C  O  R  R  I  D O    P  R  E  O  R  D  E  N  ");
  gotoxy(2,5);cout<<"CODIGO         NOMBRE        APELLIDO      NOTA#1     NOTA#2   NOTA#3  NOTA#4 ";

 
while (p) {
  gotoxy(2,l);cout<<p->dato;
  gotoxy(17,l);cout<<p->nom;
  gotoxy(31,l);cout<<p->ape;
  gotoxy(45,l);cout<<p->n1;
  gotoxy(56,l);cout<<p->n2;
  gotoxy(64,l);cout<<p->n3;
  gotoxy(72,l);cout<<p->n4;
    l++;	
	ins_pila (&pila,p);
	p = p->izquierdo;
    }
	while (!pila_vacia (&pila)) {
	sacar_pila (&pila,&p);
	p = p->derecho;
	while (p) {
        gotoxy(2,l);cout<<p->dato;
        gotoxy(17,l);cout<<p->nom;
        gotoxy(31,l);cout<<p->ape;
        gotoxy(45,l);cout<<p->n1;
        gotoxy(56,l);cout<<p->n2;
        gotoxy(64,l);cout<<p->n3;
        gotoxy(72,l);cout<<p->n4;
    l++;		
	ins_pila (&pila,p);
	p = p->izquierdo;
     }
   }
}
/*****************************************************************/
void init_pila (struct LIFO *p)
{
	p->t = 0;
}
/*****************************************************************/
int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}


/******************************************************************/
void ins_pila (struct LIFO *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

/**********************************************************************/
void sacar_pila (struct LIFO *p,struct arbol **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}

/*************************************************************************/
