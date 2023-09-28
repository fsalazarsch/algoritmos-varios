#include"conio.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"ctype.h"
#define MAXCOLS 100
#define STACKSIZE MAXCOLS
#define TRUE 1
#define FALSE 0
struct stack {
  int top;
  char items[STACKSIZE];
  };
struct COLAS{
   char a[MAXCOLS];
    int frente,final;
    };
struct Lista {
   char infijo[MAXCOLS];
   char posfijo[MAXCOLS];
   struct Lista *sig;
	     };

static int m[6][7]= {
{ TRUE,TRUE,FALSE,FALSE,FALSE,FALSE,TRUE },
{ TRUE,TRUE,FALSE,FALSE,FALSE,FALSE,TRUE },
{ TRUE,TRUE,TRUE,TRUE,FALSE,FALSE,TRUE },
{ TRUE,TRUE,TRUE,TRUE,FALSE,FALSE,TRUE },
{ TRUE,TRUE,TRUE,TRUE,TRUE,FALSE,TRUE },
{ FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE },
		    };

struct Lista *Cab,*nn,*p;
class Expresion {
struct stack opstk;
struct stack operador;
struct COLAS cola;

public:
Expresion(){   printf("Construyendo");
	      opstk.top=-1;
	      operador.top=-1;
	      cola.frente=0;
	      cola.final=0;

	  };
~Expresion(){   printf("destruyendo");
	  };
void PilaRecorrido();
void postfix(char infix[],char postr[]);
void push(struct stack *ps,char x);
char popandtest(struct stack *ps,int *pund);
int empty(struct stack *ps);
int prcd(char op1, char op2);
int isoperand(char c);
int pop(struct stack *ps);
void eliminarcola(struct COLAS *pq);
void insertarcola(struct COLAS *pq,char elemento);
int colavacia(struct COLAS *pq);
void ColaRecorrido();
void InsertarLista(char infijo[], char posfijo[]);
};
void Expresion::PilaRecorrido(){
			 while(!empty(&operador))
			       printf("%c",pop(&operador));

			       }
void Expresion::postfix(char infix[],char postr[])
 {
  int position,und;
  int outpos=0;
  char topsymb='+';
  char symb;


  for(position=0;(symb=infix[position])!='\0';position++)
	{
	  if(isoperand(symb)){
			 postr[outpos++]=symb;
			 insertarcola(&cola,symb);

			 }
			 else{
			if(symb!=')' && symb!='(')
			      push(&operador,symb);

			topsymb=popandtest(&opstk,&und);
				 while(!und && prcd(topsymb,symb))
				 {
				  postr[outpos++]=topsymb;
				  topsymb=popandtest(&opstk,&und);
				 }
				if(!und)
					 push(&opstk,topsymb);
				  if(und || (symb !=')'))
				push(&opstk,symb);
					else
				 topsymb=pop(&opstk);
			  }
		}
		 while(!empty(&opstk))
		  postr[outpos++]=pop(&opstk);

		  postr[outpos]='\0';

 }
/*************************************************************************/
void Expresion::push(struct stack *ps,char x)
	 {
	if(ps->top==STACKSIZE-1) {
		printf("%s","desborde de la pila");
		 exit(1);
				 }
				 else
					 ps->items[++(ps->top)]=x;

	  }

/*************************************************************************/
char Expresion::popandtest(struct stack *ps,int *pund)
	  {
		if(empty(ps)) {
		 *pund=TRUE;
		 return NULL;
	  }
	 *pund=FALSE;
	 return(ps->items[ps->top--]);
		 }

/************************************************************************/
int Expresion::empty(struct stack *ps)
	  {
	  if(ps->top==-1)
	 return(TRUE);
	  else
	 return(FALSE);
	  }

/************************************************************************/
int Expresion::prcd(char op1, char op2)
					 {
					 int i,j;

					 switch(op1) {
					case '+': i=0; break;
					case '-': i=1; break;
					case '*': i=2; break;
					case '/': i=3; break;
					case '^': i=4; break;
					case '(': i=5; break;
									  }
										 switch(op2) {
					case '+': j=0; break;
					case '-': j=1; break;
					case '*': j=2; break;
					case '/': j=3; break;
					case '^': j=4; break;
					case '(': j=5; break;
					case ')': j=6; break;
									  }
				  return (m[i][j]);

				  }
/***************************************************************************/

int Expresion::isoperand(char c)
	{
	 return(c!='+' &&
				 c!='-' &&
				 c!='*' &&
				 c!='/' &&
				 c!='^' &&
				 c!=')' &&
				 c!='(' );
	}
/***************************************************************************/
int Expresion::pop(struct stack *ps)
	  {
	  if(empty(ps)) {
	  printf("subdesborde de la pila");
	  exit(1);
			 }
	 return(ps->items[ps->top--]);
		}
/***************************************************************************/

void Expresion::insertarcola(struct COLAS *pq,char elemento)
{
    if(pq->final==MAXCOLS-1)
     pq->final=0;

     pq->a[pq->final]=elemento;
     pq->final++;
}
/***************************************************************************/
int Expresion::colavacia(struct COLAS *pq)
{
    return((pq->frente==pq->final) ? TRUE : FALSE);
}
/**************************************************************************/
void Expresion::ColaRecorrido(){
    while(!colavacia(&cola))
	   eliminarcola(&cola);
	   cola.frente=-1;
	   cola.final=-1;
			      }
/*************************************************************************/
void Expresion::eliminarcola(struct COLAS *pq)
{

    if(colavacia(pq))
    {
       printf("subdesborde en la cola ");
       getch();
       return;
    }
    if( pq->frente==MAXCOLS-1)
    {
	pq->frente=0;
	printf("%c",pq->a[pq->frente]);


    }
    else{
	 printf("%c",pq->a[pq->frente]);
	 pq->frente++;
	 }
}

void Expresion::InsertarLista(char infijo[], char posfijo[]){
	  nn=new Lista;
	  nn->sig=NULL;
	  strcpy(nn->infijo,infijo);
	  strcpy(nn->posfijo,posfijo);
	  if(Cab==NULL)
	     Cab=nn;
	  else {
		p=Cab;
	 while(p->sig!=NULL)
		  p=p->sig;
	     p->sig=nn;
	       }
	   };
void main()
	  {
	Expresion Notacion;
	char infix[MAXCOLS],postr[MAXCOLS],op;
	int pos;
	pos=0;
	clrscr();
	while(TRUE){
	  clrscr();
	  textcolor(11);
	  gotoxy(12,2);
	  printf("  MODELOS DE PROGRAMACION Y ESTRUCTURA DE DATOS EN C++ ");
	  gotoxy(11,3);
	  printf("EVALUACION DE EXPRESIONES ARITMETICAS EN INFIJO A POSFIJO.");
	  gotoxy(26,8);
	  printf("*** MENU PRINCIPAL ***");
	  gotoxy(20,11);
	  printf("1.ADICIONAR EXPRESIONES EN INFIJO");
	  gotoxy(20,12);
	  printf("2.EVALUAR LAS EXPRESIONES A POSFIJO");
	  gotoxy(20,13);
	  printf("3.SALIR");
	  gotoxy(20,16);
	  printf("DIGITE SU OPCION::>");
	  op=getchar();
	  switch(op)
	    {
	    case '1': {
	    do {
		clrscr();
		pos=0;
		printf("Digite Expresion En Infijo::>");
		while((infix[pos++]=getchar())!='\n');
		infix[--pos]='\0';
		Notacion.postfix(infix,postr);
		Notacion.InsertarLista(infix,postr);
		printf("\nLos Operdores son: ");
		Notacion.PilaRecorrido();
		printf("\nLas Variables son ");
		Notacion.ColaRecorrido();
		printf("\nDesea Continua S o N::>");
	       }while(toupper(getch())!='N');

	      }
	      break;

	  case '2':{p=Cab;
		 clrscr();
		 while(p!=NULL){
		     printf("\nExpresion En Infijo %s\n",p->infijo);
		     printf("\nExpresion En Posfijo %s\n",p->posfijo);
		     p=p->sig;
		     }
		    getch();
		    }break;

	   case '3':exit(0);


	  }
	  }




	 }


