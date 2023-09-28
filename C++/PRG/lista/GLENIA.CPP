#include <stdio.h>
#include <iostream.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>
#define MAXIMO 50
#define escape    27

int i,ii,iii,j,k,l,m,n,kn,ki,npuntos,ncod,ai,cont_total,cont_gan,xcod;
time_t t1,t2;
float d;
void pos(int y,int x)
	 {gotoxy(y,x);}

void devolver()
	  {
	  ki--;
	  gotoxy(wherex()-1,wherey());
	  cout<< " ";
	  gotoxy(wherex()-1,wherey());
	  }

void v_alfnum(char caracter)
	{
	 if(isalnum(caracter)==0)
			devolver();
	}


void v_digito(char caracter)
	{
	 if(isdigit(caracter)==0)
		devolver();
	}

int validar(char caracter,int tipo)

{
switch(tipo)
	    {

		 case 1: v_alfnum(caracter);break;
		 case 2: v_digito(caracter);break;

		 default:  break;
	    }
		 return(17);
 }




void capturar(char linea[],int n,char tipo)
{
   ki=-1;
   npuntos=0;
   while(1)
   {
   if(n<=0) break;
   ki++;
   if(ki>=n-1){linea[ki]='\0';break;}
   linea[ki]=getche();
   if(linea[ki]==27)  exit(0);   //ESC
	 if(linea[ki] == 13 )       //enter
	  {
	  linea[ki]='\0';
	  break;
	  }
	 else

	  if(validar(linea[ki],tipo)==7)
		 {
		 linea[1]='\0';
		 ki=50; break;
		 }
   }
 }

	  struct info
	    {
	    long codigo;
	    char nombre[30];
	    }item;

	  struct nodo
	    {
	    struct info vinfo;
	    struct nodo *izq;
	    struct nodo *der;
	    };

	  struct nodo *pnuevo,*raiz,*fin,*p,*q;

	  char temporal[10];
	  int sw;
class classtotal
	 {

	  public:
		 classtotal(){ sw=0;}
		 void leer();
		 int buscar();
		 void adicionar();
		 void eliminar();
		 void recorrer();
		 void ins_izq ();
		 void ins_der ();
	  }objeto;

int retira_arbol (int n);
void borrar_nodo (struct nodo *q,struct nodo *p);
struct nodo *buscar(int n,struct nodo **p,struct nodo *q);
struct nodo *buscar(int n,struct nodo **p,struct nodo *q) {
	if (*p == NULL)
		return NULL;
	if (n < (*p)->vinfo.codigo) {
		q = *p;
		*p = (*p)->izq;
		q = buscar(n,p,q);
		return q;
	}
	else if (n > (*p)->vinfo.codigo) {
		q = *p;
		*p = (*p)->der;
		q = buscar(n,p,q);
		return q;
	}
	else return q;
}

struct nodo *buscar_arbol(int n,struct nodo *p,struct nodo *q);
struct nodo *buscar_arbol(int n,struct nodo *p,struct nodo *q) {
	if (p == NULL)
		return q;
	if (n < p->vinfo.codigo) {
		q = p;
		q = buscar_arbol (n,p->izq,q);
		return q;
	}
	else if (n > p->vinfo.codigo) {
		q = p;
		q = buscar_arbol (n,p->der,q);
		return q;
	}
	else return NULL;
}

void classtotal::eliminar(){
int sw=0,info;
char inform[8],op;

	do{
	clrscr();
		pos(4,8);printf("De Codigo A Eliminar::>");
		pos(4*kn,8);capturar(temporal,9,2);
		info=atoi(temporal);
		if (retira_arbol (info) == -1){
			gotoxy(42,12);
			cprintf("No existe...");
			getch();
			}
			else{
			gotoxy(42,12);
			cprintf("Eliminado......\n");
			getch();
			}

			do{
		   sw=0;
		   gotoxy(35,12);
		   printf("Desea seguir eliminando datos S/N::> ");
		   op=toupper(getch());
		   if(op=='N'||op=='S'){
			  sw=1;
			  putchar(op);
			  delay(450);
			  }
		    }
		    while(sw!=1);
		} while(op!='N');


}
void borrar_nodo (struct nodo *q,struct nodo *p) {
	struct nodo *r,*s,*t;
	if (p->izq == NULL)
		r = p->der;
	else if (p->der == NULL)
		r = p->izq;
	else {
		s = p;
		r = p->der;
		t = r->izq;
		while (t != NULL) {
			s = r;  r = t; t = t->izq;
		}
		if (p != s) {
			s->izq = r->der;
			r->der = p->der;
		}
		r->izq = p->izq;
	}
	if (q == NULL)
		raiz = r;
	else if (p == q->izq)
		q->izq = r;
	else q->der = r;
	free(p);
}

int retira_arbol (int n) {
	struct nodo *q,*p = raiz;
	q = buscar (n,&p,NULL);
	if (p == NULL)
		return -1;
	borrar_nodo (q,p);
	return 0;
}


void menu();
//char cadena[10];
int jj;

void classtotal::ins_izq ()

{
	struct nodo *nuevo;
	if(p->vinfo.codigo==0)
	  p->vinfo=item;
  else     {
	  nuevo=new nodo;
	  nuevo->vinfo.codigo=0;
	  strcpy(nuevo->vinfo.nombre,"0");
	  nuevo->izq=NULL;
	  nuevo->der=NULL;
	  p->der=nuevo;
	nuevo = new nodo;
	nuevo->vinfo =item;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo; }
}


void classtotal::ins_der ()

{
	struct nodo *nuevo;
	if(p->vinfo.codigo==0)
	  p->vinfo=item;
  else     {
	  nuevo=new nodo;
	  nuevo->vinfo.codigo=0;
	  strcpy(nuevo->vinfo.nombre,"0");
	  nuevo->izq=NULL;
	  nuevo->der=NULL;
	  p->izq=nuevo;
	nuevo = new nodo;
	nuevo->vinfo = item;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo; }
}


int classtotal::buscar()
{

p=q=raiz;


		while (p->vinfo.codigo != n &&  q  != NULL )
		{
			p = q;
			if (n < p->vinfo.codigo)
				q = q->izq;
			else q = q->der;
		}
		if (p->vinfo.codigo == n)
		   {printf ("CODIGO REPETIDO/n"); return(1);}
		else
		return(0);
	}


void classtotal::leer()
{
clrscr();

pos(iii,j);cout<<" DIGITE DATOS DEL  ESTUDIANTE ";
pos(2*kn,8);cout<<"CODIGO                       ";
pos(2*kn,10);cout<<"NOMBRE                      ";
pos(4*kn,8);capturar(temporal,9,2);
if(temporal[0]=='0') menu();
n=atoi(temporal);
if(objeto.buscar()==0)


	{
	item.codigo=n;
	pos(4*kn,10);capturar(item.nombre,10,1);
	pos(4*kn,8);

	if (n < p->vinfo.codigo)
		  ins_izq ();

	 else  ins_der ();
	}
else        getch();

}

void modificar(struct nodo *p)
{
clrscr();

pos(iii,j);cout<<" DIGITE DATOS DEL  ESTUDIANTE ";
pos(2*kn,8);cout<<"CODIGO                       ";
pos(2*kn,10);cout<<"NOMBRE                      ";
pos(4*kn,8);cout<<xcod;


	{
	pos(4*kn,10);capturar(item.nombre,10,1);
	strcpy(p->vinfo.nombre,item.nombre);
	pos(4*kn,8);


	}


	getch();

}
struct LIFO {
	int t;
	struct nodo *a[MAXIMO];
};
//*****************************PREORDEN********************************


void init_pila (struct LIFO *p)

{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)

{
	return (!p->t);
}

void ins_pila (struct LIFO *p,struct nodo *s)


{
	if (p->t == MAXIMO)
	   printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
		 }
}



void retira_pila (struct LIFO *p,struct nodo **s)

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
////*******************************
void imprimir(struct nodo *p)
{ai++;           cont_total=0;cont_gan=0;
		 gotoxy(4,ai+1);cout<<p->vinfo.codigo;
		 gotoxy(14,ai+1);cout<<p->vinfo.nombre;
		 cont_total++;

}

void inorden (struct nodo *p,int sw)
{

	struct LIFO pila;
	time(&t1);
	delay(1000);
	clrscr();
	cont_total=0; cont_gan=0;
	pos(2,4);cout<<("   CODIGO    NOMBRE    ");
	if(sw==1) {gotoxy(2,2);cout<<"DIGITE CODIGO A MODIFICAR";cin>>xcod;}
	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		if(p->vinfo.codigo!=0) cont_total++;
   if(sw==1)
	  {

	  if(xcod==p->vinfo.codigo)
		{
		 imprimir(p);
		 modificar(p);

		}
	  }
   else
	  {
		 imprimir(p);
	  }
		p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
			  }
	}
	getch();


}
//**********************************
void preorden (struct nodo *p)

{
	struct LIFO pila;
	clrscr();
	time(&t1);
	delay(1000);
	  pos(2,4);	cout<<("   CODIGO    NOMBRE    ");

	init_pila (&pila);
	while (p) {
   imprimir(p);
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		p = p->der;
		while (p) {

   imprimir(p);
			ins_pila (&pila,p);
			p = p->izq;
		}
	}

	getch();
}
//*********



struct elemento {
	struct nodo *apunt;
	int senal;
};

struct PILA {
	int t;
	struct elemento a[MAXIMO];
};


void inicia_pila (struct PILA *p)

{
	p->t = 0;
}

int pila_vacia1 (struct PILA *p)

{
	return (!p->t);
}

void inserte_pila (struct PILA *p,struct nodo *s)

{
	if (p->t == MAXIMO)
	   printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a[p->t - 1].apunt = s;
			p->a[p->t - 1].senal = 0;
		 }
}

void retire_pila (struct PILA *p,struct nodo **s)

{
	if (pila_vacia1 (p) )  {
	   printf ("la pila esta vacia\n");
	   *s = NULL;
	}
	else  {
			*s = p->a [p->t -1].apunt;
			p->t--;
		 }
}
void mirar (struct PILA *p,struct nodo **s,int *i)

{
	if (pila_vacia1 (p) )  {
	   printf ("la pila esta vacia\n");
	   *s = NULL;
	}
	else  {
			*s = p->a [p->t -1].apunt;
			*i = p->a [p->t -1].senal;
			p->a [p->t - 1].senal = 1;
		 }
}



void posorden (struct nodo *p)

{
	int i;
	struct PILA pila;
	clrscr();
	pos(2,4);	cout<<("   CODIGO    NOMBRE   ");

	inicia_pila (&pila);
	while (p) {
		inserte_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia1 (&pila)) {
		mirar (&pila,&p,&i);
		if (i == 0)
			p = p->der;
		else p = NULL;
		if (p)
			while (p) {
				inserte_pila (&pila,p);
				p = p->izq;
			}
		else {
				retire_pila (&pila,&p);
   imprimir(p);
			}
	}
	getch();

}
////////////////////////////////////////////////////////////

void menu();
void classtotal::recorrer()
{
clrscr();
ai=5;
p=raiz;
jj=0;

if(sw==0)
   {
   pos(20,20);cout<<"NO EXISTEN REGISTROS ";
   getche();
   }
else
   {

int c;
while(1)

	  {  clrscr();

	  pos(ii,j);cout<<" ELIJA    OPCION PARA RECORRER EL ARBOL BINARIO ";
	  pos(k,l);cout<<    "A.   PREORDEN";
	  pos(k,l+m);cout<<  "B.   INORDEN ";
	  pos(k,l+2*m);cout<<"C.   POSORDEN";

	  pos(k+2,ii);cout<<"ESC    PARA SALIR";

	  c=getch();
	  if(islower(c))
		c=c-32;
	  switch(c)

	    {

		 case 'A': ai=5;preorden(raiz);break;


		 case 'B': ai=5;inorden(raiz,0);break;


		case 'C': ai=5;posorden(raiz);getch();break;

		 default: menu();break;
	    }


	  }
 }

}


void classtotal::adicionar()
{

   int temp;
   while (1)
	{
		leer();
		{
		if(sw==0)
		    {
		    raiz=new nodo;
		    raiz->der=NULL;
		    raiz->izq=NULL;
		    //fin=raiz;
			sw=1;
		    raiz->vinfo=item;
		    }
		else
		    buscar();
		}

	}
}


void menu()
{
int c;
while(1)
	  {
	  clrscr();
	  gotoxy(21,4);cout<<" GLENIA MILENA MONTERO LUNA";
	  gotoxy(22,7);cout<<" ELIJA    OPCION               ";
	  pos(k,l);cout<<    "A.   ADICION REGISTRO";
	  pos(k,l+m);cout<<  "B.   LISTADO ";
	  pos(k,l+2*m);cout<<"C.   MODIFICAR";
	  pos(k,l+3*m);cout<<"D.   ELIMINAR";

	  pos(k+2,ii);cout<<"ESC    PARA SALIR";

	  c=getch();
	  if(islower(c))
		c=c-32;
	  switch(c)

	    {

		 case 'A': objeto.adicionar();break;

		 case 'B': objeto.recorrer();

		 case 'C': ai=5;inorden(raiz,1);break;

		 case 'D':objeto.eliminar();break;

		 case escape: exit(1);
	    }


	  }
 }


void main()
{
ii=20;j=4;k=25;l=10;m=2;kn=15;
clrscr();
menu();
}
