
/**************************ARBOL BINARIO****************************/
	#include "stdio.h"
	#include "conio.h"
	#include "stdlib.h"
	#include "time.h"
	#include "alloc.h"
	#include "ctype.h"
	#include "string.h"
	#include "graphics.h"
	#include "fcntl.h"
	#include "io.h"
	#include "dos.h"#
	#define bajar 80
	#define subir 72
	#define ESC 27
	#define ENTER 13

	class tree
		{
		 struct arbol *inic_palo()
		  {
		  return(NULL);
		}
public:
	void cuadro(int,int,int,int);
	void mostrar(int,int,int);
	void mostrar2(int,int,int);
	void menu2();
	void menu();
	void MOST_ARBOL(struct arbol *a);
	void MOSTRAR(struct arbol *a,int x1,int y1, int n, int j);
	void buscar();
	void inorden(struct arbol *temp);
	tree(struct arbol *inic_palo);
	void preorden(struct arbol *temp);
	void posorden(struct arbol *temp);
	void visualder(struct arbol *temp);
	void lee_palo();
	void lugar(int q, int w, int *e, int *r);
	void mostrarpre();
	void mostrarin();
	void mostrarpos();
	void vali();
	void eliminar();
	xy(int x, int y);
	char VECTOR[3];
	void CONVERTIR(int x,char a[3]);

};
struct
       {
	char cad[30];
}v[6];
       char o;
       int y;
struct
{
	char cad[30];
}b[5];

struct arbol{
       int inf,nivel;
       struct arbol *izq,*der;
}*raiz=NULL;
struct arbol *p,*nn;


struct arbol *inic_palo()
    {
     return(NULL);
    }

struct arbol *cons_palo(int x,struct arbol *aux1, struct arbol *aux2)
 { struct arbol *a,var;

   a=(struct arbol *) malloc(sizeof(struct arbol));
   a->inf=x;
   a->izq=aux1;
   a->der=aux2;
   return(a);
 }

struct arbol *ins_ordenado(struct arbol *a,int x)
{ struct arbol *temp;
	if(a==NULL){
		a=cons_palo(x,NULL,NULL);
		a->nivel = 0;
	}
	else{
	if(x==a->inf)
	 {
	 clrscr();
	 gotoxy(25,8);
	 printf("YA EL EXISTE EL NODO");
	}
	else {
	if (a->nivel < 4){
	 if(x>a->inf)
		{ temp=a->der;
			temp=ins_ordenado(temp,x);
			a->der=temp;
		}

		else
		{ temp=a->izq;
			temp=ins_ordenado(temp,x);
			a->izq=temp;
		}


			temp->nivel = a->nivel + 1;
	}
		else {
			clrscr();
			textbackground(0);textcolor(11);
			gotoxy(23,11);printf("Este Arbol no pude mostrar");
			gotoxy(23,12);printf("mas de 4 niveles");
			delay(1000);
			clrscr();
		}

	}

	}
	return(a);
}
/***********************************LECTURA*****************************/
void tree:: lee_palo()
{
  char op;
	int t;
	int c;
	time_t tt;

 do{
    textbackground(0);textcolor(11);clrscr();
    cuadro(6,20,16,55);
    gotoxy(25,9);
     srand((unsigned) time(&tt));
     c = rand() % 100;

    if (c>=100){
	 clrscr();
	 gotoxy(22,8);printf("VALOR DEL NODO FUERA DE RANGO");
	}

    else
    raiz=ins_ordenado(raiz,c);


    gotoxy(24,12);
    printf("DESEA INGRESAR OTRO [S/N]: ");
    op=toupper(getche());


	 } while(op=='S' || op == 's');
	 clrscr();

}
/****************************************************************************/
/**********************************************************************/

void tree::eliminar()
{ char op,inform[3];
  int info,i,n;
  struct arbol *q,*s,*f;
  clrscr(); i=0;
  char c[57];
  int j;
 textbackground(0);textcolor(11);clrscr();
    cuadro(6,20,16,55);
 if(raiz!=NULL)
 {
  do
  {
    gotoxy(23,10);
   printf("INGRESAR NODO A BORRAR: ");
    gotoxy(48+i,10);
    inform[i]=getche();
    if(inform[i]=='\b'&&i>0) i-=2;
    else
     { if(inform[i]=='\r'&&i>0) break;
       if(!isdigit(inform[i])) i--;
     }
    i++;
  }while(i<2);
  inform[i]='\0';
  info=atoi(inform);
  f=NULL;
  p=nn=raiz;
  while((info!=p->inf)&&(nn!=NULL))
  { f=p;
    p=nn;
    if(info<p->inf)
      nn=p->izq;
    else
      nn=p->der;
  }
  if(info!=p->inf)
  {
    gotoxy(25,12);printf("EL NODO  NO EXIXTE");
  }
  else
  { if(p->izq==NULL)
      nn=p->der;
    else
      if(p->der==NULL)
	nn=p->izq;
      else
      { q=p;
	nn=q->der;
	s=nn->izq;
	while(s!=NULL)
	{ q=nn;
	  nn=s;
	  s=nn->izq;
	}
	if(q!=p)
	{ q->izq=nn->der;
	  nn->der=p->der;
	}
	nn->izq=p->izq;
      }
      if(f==NULL)
	raiz=nn;
      else
	{ if(p==f->izq) f->izq=nn;
	  else f->der=nn;
	}
    p->izq=p->der=NULL;
    free(p);
    gotoxy(25,12);printf("EL NODO FUE ELIMINADO");
  }
 gotoxy(22,14);printf("DESEA ELIMINAR OTRO NODO : [S/N]: ");
 do{
     gotoxy(54,14);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') eliminar(); clrscr();
}
else
{
 gotoxy(23,14);printf("ARBOL VACIO");getch();
}
clrscr();
}

/**********************************************************************/

/***********************************POSTORDEN******************************/

void tree:: posorden(struct arbol *temp)
{
  if(temp!=NULL)
  {
    posorden(temp->izq);
    posorden(temp->der);
    printf("%d\t",temp->inf);

  }
}

/*************************************PREORDEN***************************/

void tree:: preorden(struct arbol *temp)
{

   if(temp!=NULL)
  {
    printf("%d\t",temp->inf);
    preorden(temp->izq);
    preorden(temp->der);

  }
}
/******************************INORDEN*************************************/
void tree:: inorden(struct arbol *temp)
{
   if(temp!=NULL)
    {
    inorden(temp->izq);
		printf("%d\t",temp->inf);
		inorden(temp->der);

  }
}

/*****************************************************/
void tree::lugar(int q, int w, int *e, int *r)
{
    if (q==4)
  if (w%2!= 0)
*e=2+(w/2)*10;
    else
 *e=8+(w/2-1)*10;
     else
*e=80/xy(2,q+1)+(w-1)*2*(80/xy(2,q+1));
    *r=q*4+2;
  }
/*******************************/
tree::xy(int x, int y)
  {
    int k;
     if (y==0)
       return(1);
     else
       {
	 for (k=1; k<y; k++)

	   x=x*2;
	 return(x);
       }
  }

/************************MOSTRAR ARBOL**************************************/
void tree::MOSTRAR(struct arbol *a,int x1,int y1, int n, int j)
{
   int nn,jj,as;
    char ve[3];
    lugar(n, j, &nn, &jj);setbkcolor(3);setcolor(14);
     if (a!=NULL)
       { if((x1!=0)&&(y1!=0))
	 line((x1+.3)*7.9875,(y1+.75)*19.16,nn*7.9875,(jj-.75)*19.16);
	 circle((nn+.3)*7.9875,jj*19.16,14);
	 CONVERTIR(a->inf,VECTOR);
	 if(strlen(VECTOR)==1)
	  outtextxy((nn-.1)*7.9875,(jj-.15)*19.16,VECTOR);
	 else
	  outtextxy((nn-.47)*7.9875,(jj-.15)*19.16,VECTOR);
	 x1=nn;y1=jj;
	 MOSTRAR(a->izq,x1,y1,n+1,j*2-1);
	 MOSTRAR(a->der,x1,y1,n+1,j*2);
       }
   }
/***********************************ARBOL***************************/
void tree::MOST_ARBOL(struct arbol *a)
{

    int s,e;
    char c[57];
    int j,n;
   if(raiz!=NULL)
   {
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	setcolor(getmaxcolor());
	s=0;  e=1;cleardevice(); MOSTRAR(a,0,0,s,e);
	getche();closegraph();textbackground(3);textcolor(14);clrscr();
   }
   clrscr();
}

/**********************************************************/
void tree::CONVERTIR(int x,char a[3])
{ int as;
 if(x>9)
  { as= (x/10);
    a[0]=as+'0';
    as=(x%10);
    a[1]=as+'0';
    a[2]='\0';
  }
 else
  { a[0]=x+'0';
    a[1]='\0';
  }
}

/*********************************BUSCAR*********************************/
void tree::buscar(){
	int n;
	char  op;

      do{

		clrscr();
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);


	    if (raiz == 0){
		gotoxy(29,9);cprintf("ARBOL  VACIO");
		getch();clrscr();menu();
	     }

	       else {
			gotoxy(25,10);printf("ELEMENTO A BUSCAR ");
			scanf("%d",&n);
			 clrscr();
			 textbackground(0);textcolor(11);clrscr();
			 cuadro(6,20,16,55);
			p = raiz;
			while (p != 0 && p->inf != n) {
				if (n < p->inf)
					p = p->izq;
				else
					p = p->der;
			}
		if (p->inf == n){

				textcolor(11);
				gotoxy(30,9);cprintf("EXISTE ELEMENTO!");
				getch();clrscr();menu();
		}
		else{
				gotoxy(24,9);cprintf("NO EXISTE EL ELEMENTO ");
				getch();clrscr();menu();
			}

		   }

		       gotoxy(23,13);
		       printf("DESEA BUSCAR OTRO NODO [S/N]: ");
		       op=toupper(getche());
		       }while(op=='S');
		       clrscr();
	 }


/******************************MENU****************************************/
/*************************************************************************/
/*************************************************************************/


void tree::menu()

	{
	while(1)
	   {
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		strcpy(v[0].cad,"A. CREACION DE ARBOL.......");
		strcpy(v[1].cad,"B. RECORIDOS DEL ARBOL.....");
		strcpy(v[2].cad,"C. MOSTRAR ARBOL...........");
		strcpy(v[3].cad,"D. BUSCAR UN ELEMENTO......");
		strcpy(v[4].cad,"E. ELIMINAR................");
		strcpy(v[5].cad,"F. TERMINAR................");
		mostrar(9,24,5);
		textbackground(10);textcolor(BLUE);
		gotoxy(24,9+y);cprintf("%s",v[y].cad);
		o=getch();o=toupper(o);
		textcolor(11);
		switch(o)
		{
			case subir:(y=(y>0)?--y:y);break;
			case bajar:(y=(y<5)?++y:y);break;
			case ESC:exit(1);
			case ENTER:switch(y)
			{
			 case 0:clrscr(); lee_palo();break;
			 case 1:clrscr(); menu2();clrscr();break;
			 case 2:clrscr(); vali()/*/MOST_ARBOL(raiz);*/; break;
			 case 5:clrscr(); exit (1);
			 case 3:clrscr(); buscar();
			 case 4:clrscr(); eliminar();
			}
		}
	}
}


void tree::cuadro(int a,int b,int c,int d)
{
	int i,z;
	gotoxy(b,a);printf("Ú");
	gotoxy(d,a);printf("¿");
	gotoxy(b,c);printf("À");
	gotoxy(d,c);printf("Ù");
	for (i=1;i<(d-b);i++)
	{
		gotoxy(b+i,a);printf("Ä");
		gotoxy(b+i,c);printf("Ä");
	}
	for (i=1;i<(c-a);i++)
	{
		gotoxy(b,a+i);printf("³");
		gotoxy(d,a+i);printf("³");
	}
	gotoxy(5,3);printf("C O R P O R A C I O N   T E C N O L O G I C A   D E L   S A N T A N D E R");
	gotoxy(29,20);printf("V A L L E D U P A R ");
	gotoxy(32,22);printf("  C E S A R ");
	}
void tree::mostrar(int x,int y,int z)
{

	int i;
	for (i=0;i<=z;i++)
	{
		gotoxy(y,x+i);
		cprintf(v[i].cad);
	}

}
void tree::mostrar2(int x,int y,int z)
{

	int i;
	for (i=0;i<=z;i++)
	{
		gotoxy(y,x+i);
		printf(b[i].cad);
	}

}

void tree::menu2()
	{
	while(1)
	   {
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		strcpy(b[0].cad,"A. RECORIDO PREORDEN.......");
		strcpy(b[1].cad,"B. RECORIDO INORDEN........");
		strcpy(b[2].cad,"C. RECORIDO POSTORDEN......");
		strcpy(b[3].cad,"D. VOLVER AL MENU..........");
		mostrar2(9,24,3);
		textbackground(10);textcolor(BLUE);
		gotoxy(24,9+y);cprintf("%s",b[y].cad);
		o=getch();o=toupper(o);
		//textcolor(11);
		switch(o)
		{
			case subir:(y=(y>0)?--y:y);break;
			case bajar:(y=(y<3)?++y:y);break;
			case ESC:exit(1);
			case ENTER:switch(y)
			{
			case 0:clrscr();mostrarpre(); getche();clrscr(); break;
			case 2:clrscr();mostrarpos(); getche();clrscr(); break;
			case 1:clrscr();mostrarin();;getche();clrscr(); break;
			case 3:clrscr();menu();getche();clrscr(); break;
		 }
		}

	   }
	}
/**********************************************************************/
void tree::mostrarpre(){
	clrscr();
	    if (raiz == 0){
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		gotoxy(29,12);cprintf("ARBOL  VACIO");
		getch();menu2();
	     }

	MOST_ARBOL(raiz);
	textbackground(0);textcolor(11);clrscr();
	cuadro(6,10,16,66);
	gotoxy(27,9);
	preorden(raiz);
	gotoxy(12,9);printf("PREORDEN-->");
	getch();
			 }

/*********************************************************************/
void tree::mostrarpos(){
	clrscr();
	if (raiz == 0){
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		gotoxy(29,12);cprintf("ARBOL  VACIO");
		getch();menu2();
	     }
	MOST_ARBOL(raiz);
	textbackground(0);textcolor(11);clrscr();
	cuadro(6,10,16,66);
	gotoxy(27,9);
	posorden(raiz);
	gotoxy(12,9);printf("POSTORDEN--> ");
	getch();
			 }
/*******************************************************************/
void tree::mostrarin(){
	clrscr();
	if (raiz == 0){
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		gotoxy(29,12);cprintf("ARBOL  VACIO");
		getch();menu2();
	     }
	MOST_ARBOL(raiz);
	textbackground(0);textcolor(11);clrscr();
	cuadro(6,10,16,66);
	gotoxy(27,9);
	inorden(raiz);
	gotoxy(12,9);printf("INORDEN--> ");
	getch();
		 }
/******************************vali***************/
void tree::vali()
	{
	if (raiz == 0){
		textbackground(0);textcolor(11);clrscr();
		cuadro(6,20,16,55);
		gotoxy(28,9);cprintf("ARBOL  VACIO");
		getch();menu();
	     }
	 MOST_ARBOL(raiz);
     }





tree::tree(struct arbol *inic_palo)
{ raiz=inic_palo; }
void main()
{ //raiz=inic_palo();
	tree obj(NULL);
  obj.menu();

};
