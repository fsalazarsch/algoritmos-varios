#include<stdio.h>
#include<io.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#include <graphics.h>
#define col textcolor
#define colp textbackground
#define imp cprintf
#define pos gotoxy
#define limp clrscr()

/******************************************************************/

class RINCON
{

  struct arbol
  {
	 char codigo[10];
	 char nombre[15];
	 char apellido[15];
	 //int codigo;
	 struct arbol *izq;
	 struct arbol *der;
  };struct arbol *raiz,*memo,*p;

  public:
	RINCON(struct arbol *a){raiz=a;}
		  void menu();
	void adicionar();
	void consultar();
	void opcion_1();
	void cons_postorden(struct arbol *p);
	void cons_inorden(struct arbol *p);
	void cons_preorden(struct arbol *p);
	void ins_izq (struct arbol *p,int n);
	void ins_der (struct arbol *p,int n);
	int val(int x, int y);
	val_ent();
 };

//**************************m MENU  **********************/

void RINCON::menu()
	 {
	 char op;
	 int m,unidad=DETECT,cual;
	 limp;
	 raiz=NULL;
	 colp(0);
	 while(1)
	 {
		colp(1);
		limp;
		col(10);
		pos(30,5); imp("     MENU PRINCIPAL ");
		pos(30,12);imp("1. Adicionar            ");
		pos(30,13);imp("2. Consultar            ");
		pos(30,14);imp("3. Ver-Modo             ");
		pos(30,15);imp("4. Salir                ");
		pos(30,20);imp("Digite Opcion [ ]       ");
		col(4); pos(45,20); op=getchar();op=toupper(op);

	 switch(op)
	 {
	  case '1' :limp;adicionar();break;
	  case '2' :limp;consultar();break;
	/* case '3':
		//initgraph(&unidad,&cual,"c:\\tc\\bgi");
		//modo(raiz,320,20,320);
		//getch();
	  // closegraph();
		//break;
					*/
	  case '4' :exit(0);
	}
  }
}

//*****************************************
int RINCON::val_ent()
{
	char aux[20];
	gets (aux);
	return atoi(aux);
}

/****************************************************************/


void ins_izq (struct arbol *p,int n)
	{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->codigo = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
       }

/****************************************************************/

void ins_der (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->codigo = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
}
/****************************************************************/
#define MAXIMO 20

struct LIFO {
	int t;
	struct arbol *a[MAXIMO];
};



/***************  METODO PREORDEN ***************************/

void RINCON::cons_preorden (struct arbol *p)
{
int f,i,j;
float def;
struct LIFO pila;
void init_pila (struct LIFO *p);
int pila_vacia (struct LIFO *p);
void ins_pila (struct LIFO *p, struct arbol *s);
void sacar_pila (struct LIFO *p,struct arbol **s);
init_pila (&pila);
clrscr();
  textcolor(14); colp(15);


 f=7;

 for (i=2;i<=62;i++)
  {
   for (j=6;j<=14;j++)
   {
	 pos(i,j);colp(1);imp(" ");
   }
  }
  pos(32,2);textcolor(15);imp(" MODO EN  PREORDEN   ");
  delay(150);
  pos(32,22);textcolor(10);imp(" PRESS ENTER   ");
  pos(4,5);cout<<"CODIGO  NOMBRE    ";

  while (p) {
	pos(4,f);cout<<p->codigo;
	pos(12,f);cout<<p->nombre;
	f++;
	ins_pila (&pila,p);
	p = p->izq;
    }
	while (!pila_vacia (&pila)) {
	sacar_pila (&pila,&p);
	p = p->der;
	while (p) {
	pos(4,f);cout<<p->codigo;
	pos(12,f);cout<<p->nombre;
	 f++;
		ins_pila (&pila,p);
		p=p->izq;
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
	 imp ("La pila se encuentra llena..? \n");
	  else  {
	  p->t++;
	  p->a [p->t -1] = s;
	}
}

/**********************************************************************/
void sacar_pila(struct LIFO *p,struct arbol **s)
{
	if (pila_vacia(p)) 
	 {
		imp ("La pila se encuentra vacia..?\n");
		*s=NULL;
		}
		else 
		 {
		  *s=p->a[p->t-1];
		  p->t--;
	 }
}

/*************************************************************************/
void RINCON::adicionar()

  {
  char nombre[15];
  char op,info[3],co[5];
  int codigo,i,j;
  int sw,st;
  char valido;
  int n;

  do{
  clrscr();
  for (i=3;i<=79;i++)
  {
   for (j=6;j<=14;j++)
   {
	 pos(i,j);colp(1);imp(" ");
	 }
	}
	 pos(32,2);textcolor(252);imp(" ESTAMOS ADICIONANDO ");
	 delay(150);
	 i=0;
	 textcolor(19);pos(4,5);cout<<"CODIGO";
	 textcolor(19);pos(16,5);cout<<"NOMBRE";

	do
	{
	 pos(7,i+6);
    info[i]=getche();
    if(info[i]=='\d'&&i>0) i-=2;
    else
	  {
     if(info[i]=='\r'&&i>0) break;
     if(!isdigit(info[i])) i--;
     }
	  i++;
		}while(i<5);

	  info[i]='\0';
	  codigo=atoi(info);
	  p=memo=raiz;i=1;
	  while((codigo!=p->codigo)&&(memo!=NULL)&&(i<=6))
	  {
		p=memo;
		if(codigo<p->codigo)
		memo=p->izq;
		else
		memo=p->der;
	  i++;
	 }
	 if(codigo==p->codigo)
	  {
		delay(50);
		pos(5,16);textcolor(4);imp(" EXISTENTE ");
		delay(150);
		}
		else
		if(i==6)
		{
		pos(14,12);cout<<"EL NUMERO  NO SE PUEDE INTRODUCIR";
		}
		else
		{
		do
			{
			valido='n';
			pos(16,i+5);
			cout<<"             ";
			pos(16,i+5);gets(nombre);
			n=strlen(nombre);
			for(j=0;j<=n-1; j++)
		  {
		 if(!(isalpha(nombre[j])))
		 {
		 delay(50);
		 pos(15,16);textcolor(4);imp(" SOLO LETRAS");
		 delay(150);
		 valido='m';
		 getch();
		 pos(15,16);
		 cout<<"                                 ";
		 break;
		 }
	  }
	  }while(valido=='m');
	  memo=new arbol;
	  memo->codigo=codigo;
	  strcpy(memo->nombre,nombre);
	  memo->izq=NULL;
	  memo->der=NULL;

     if(raiz==NULL)
		 raiz=memo;
		 else
		 {
		if(codigo<p->codigo)
		p->izq=memo;
		else
		p->der=memo;
		}
		pos(29,21);imp(" NODO INSERTADO ");
		}
	  textcolor(15); colp(0);
	  textcolor(15);colp(0);
	  pos(24,22);imp(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
	  op=toupper(getche());
	  }while(op!='N');
}


/**  MENU DOS  DE CONSULTAS  ***************************************/

void RINCON::consultar()
	{
	 char op;
	 limp;
	 colp(0);
	 while(1)
	 {
		 limp;
		 colp(1);
		 col(10);pos(30,5); imp(" MENU DE CONSULTA ");
		 col(15);
		 pos(30,12); imp("1. Pre-Orden                 ");
		 pos(30,13); imp("2. In-Orden                  ");
		 pos(30,14); imp("3. Pos-Orden                 ");
		 pos(30,15); imp("4. Regresar al Menu Proncipal");
		 pos(30,20); imp("Digite opcion[  ]     ");
		 pos(45,20); op=getchar();op=toupper(op);

	switch(op)
	{
	  case '1' :limp;cons_inorden(raiz);getch();break;
	  case '2' :limp;cons_preorden(raiz);getch();break;
	  case '3' :limp;cons_postorden(raiz);getch();break;
	  case '4' :limp;menu();
	}
  }
}
//************ IMPRESION EN INORDEN ************************************/

void RINCON::cons_inorden (struct arbol *p)
{
	int f,i,j;
	float def;
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct arbol *s);
	void sacar_pila (struct LIFO *p,struct arbol **s);
	init_pila (&pila);

	clrscr();
	f=7;
	for (i=2;i<=62;i++)
	 {
	 for (j=6;j<=14;j++)
	  {
	  pos(i,j);colp(4);imp(" ");
	  }
	 }
	 pos(32,2);textcolor(15);imp(" METODO DE INORDEN   ");
	 delay(150);
	 pos(32,22);textcolor(15);imp(" PULSE ENTER...");
	 pos(4,5);cout<<"CODIGO  NOMBRE    ";
	 init_pila(&pila);
	 while(p)
	 {
		ins_pila(&pila,p);
		p=p->izq;
		}
	  while(!pila_vacia(&pila))
	  {
		sacar_pila (&pila,&p);
		  {
		  pos(4,f);cout<<p->codigo;
		  pos(12,f);cout<<p->nombre;
		 }
		f++;
		p=p->der;
		while(p)
		 {
		 ins_pila(&pila,p);
		 p=p->izq;
		}
	}
}

//**********************************************************************
#define MAXIMO 20

struct elem {
	struct arbol *apunt;
	int senal;
};
//*******************************************

struct LIFO1 {
	int t;
	struct elem a[MAXIMO];
};

//***************  IMPRESION EN POSTORDEN  *****************************************

void RINCON::cons_postorden (struct arbol *p)
{
	int i,j,x,f;
	void mirar (struct LIFO1 *p,struct arbol **s,int *i);
	void init_pila1 (struct LIFO1 *p);
	void ins_pila1 (struct LIFO1 *p,struct arbol *s);
	void retira_pila1 (struct LIFO1 *p,struct arbol **s);
	int pila_vacia1 (struct LIFO1 *p);

	struct  LIFO1 pila;
	init_pila1 (&pila);
	clrscr();
	f=7;

	for (i=2;i<=62;i++)
	{
	 for (j=6;j<=14;j++)
	 {
	 pos(i,j);colp(15);imp(" ");
	 }
	 }
	pos(32,2);textcolor(15);imp(" POSTORDEN...");
	delay(150);
	pos(32,22);textcolor(15);imp(" PULSE ENTER...");
	pos(4,5);cout<<"CODIGO  NOMBRE    ";
	while(p)
	{
		ins_pila1(&pila,p);
		p=p->izq;
		}
	  while (!pila_vacia1 (&pila)) {
		mirar(&pila,&p,&i);
		 if(i==0)
			p=p->der;
			else
			p=NULL;
			if (p)
			while(p)
			 {
				ins_pila1(&pila,p);
				p=p->izq;
			  }
			 else {
			 retira_pila1 (&pila,&p);
			 pos(4,f);cout<<p->codigo;
			 pos(12,f);cout<<p->nombre;
		  f++;
			}
		}
  getche();
}

//******* inicializa la pila ******************************************/

void init_pila1 (struct LIFO1 *p)

 {
	p->t=0;
  }

//****contenido de la pila *******************************************/

int pila_vacia1(struct LIFO1 *p)
{
	return(!p->t);
}

//*************** estado de la pila   ***********************************/

void ins_pila1 (struct LIFO1 *p,struct arbol *s)
{
	if (p->t==MAXIMO)
		imp("La pila se encuentra llena..? \n");
	else  {
		p->t++;
		p->a[p->t - 1].apunt=s;
		p->a[p->t - 1].senal=0;
	      }
 }
//********************************** estado de la pila

void retira_pila1 (struct LIFO1 *p,struct arbol **s)
{
		if(pila_vacia1 (p) )  {
		imp ("La pila se encuentra vacia..?\n");
		*s=NULL;
		}
	  else  {
			*s=p->a[p->t-1].apunt;
			p->t--;
			}
 }

/*************************************************************************/
void mirar (struct LIFO1 *p,struct arbol **s,int *i)
{
	if (pila_vacia1 (p) )  {
	    imp("La pila se encuentra vacia..?\n");
	    *s=NULL;
	   }
	   else  {
		*s=p->a[p->t-1].apunt;
		*i=p->a[p->t-1].senal;
		p->a [p->t-1].senal=1;
	      }
}

/*******************************************************************/
void main()
{
  char op;
  int cont;
  int u;
  clrscr();
  RINCON objeto(NULL);
  objeto.menu();
  getche();
}

//  F i N....
