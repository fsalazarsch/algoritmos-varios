#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAXIMO 100
#define TRUE 1
#define FALSE 0
struct LIFO1 {
	  int t;
	  char a[MAXIMO];
	  };

struct COLAS{
	  char a[MAXIMO];
	  int frente,final;
		};

struct Infijo {
	 char infijo[MAXIMO];
	 char posfijo[MAXIMO];
	 struct Infijo *sig;
		 };

	  static int m[6][7]= {
	  { 1,1,0,0,0,0,1 },
	  { 1,1,0,0,0,0,1 },
	  { 1,1,1,1,0,0,1 },
	  { 1,1,1,1,0,0,1 },
	  { 1,1,1,1,1,0,1 },
	  { 0,0,0,0,0,0,0 },
		 };
struct Infijo *Cab1,*p1,*q1,*nn1;
/***********************************************************************/
class Notacion {

  struct LIFO1 pila;
  struct LIFO1 operador;
  struct COLAS cola;
  public:
  Notacion(){ printf("Constructor......");
  clrscr();
  Cab1=p1=q1=NULL;
  cola.frente=0;
  cola.final=0;
  };
  ~Notacion(){ printf("Destructor......");clrscr();};
	char tope1(struct LIFO1 p);
	void init1_pila(struct LIFO1 *p);
	int pila1_vacia(struct LIFO1 *p);
	void ins1_pila(struct LIFO1 *p,char s);
	void retira1_pila(struct LIFO1 *p, char *s);
	void in_a_pos(char *infijo,char *posfijo);
	int operando(char c);
	int prioridad(char op1, char op2);
	void c_expresion(char linea[], char infijo[], double operan[]);
	void llenar(char infijo[],char posfijo[]);
	void Cola();
	void operadores();
	int colavacia(struct COLAS *pq){
	return((pq->frente==pq->final) ? TRUE : FALSE);
	};
	void eliminarcola(struct COLAS *pq)
	{
		if(colavacia(pq)){
		printf("subdesborde en la cola ");
		getch();
		return;}
		if( pq->frente==MAXIMO-1){
		 pq->frente=0;
		 printf("%c",pq->a[pq->frente]);}
		 else {
		 printf("%c",pq->a[pq->frente]);
		 pq->frente++;}
	};
	void insertarcola(struct COLAS *pq,char elemento)
	{
		if(pq->final==MAXIMO-1)
		pq->final=0;
		pq->a[pq->final]=elemento;
		pq->final++;
	};
};

void Notacion::Cola()
{
  while(!colavacia(&cola)){
	 eliminarcola(&cola);}
}

/************************LISTAS******************************************/
void Notacion::llenar(char infijo[], char posfijo[])
{
	  nn1=new Infijo;
	  nn1->sig=NULL;
	  strcpy(nn1->infijo,infijo);
	  strcpy(nn1->posfijo,posfijo);
	  if(Cab1==NULL)
	   Cab1=nn1;
	  else {
		p1=Cab1;
	  while(p1->sig!=NULL)
		  p1=p1->sig;
		  p1->sig=nn1;}
};

void Notacion::c_expresion(char linea[], char infijo[], double operan[])
{
	 double cifra=0;
	 int i,j,k,m;
	 char auxiliar[10];
	 i=k=m=0;
	 while(linea[i]){
	  j=0;
	 while(linea[i]>='0' && linea[i]<='9' || linea[i]=='.')
	  auxiliar[j++]=linea[i++];
	  if(j!=0){
	  auxiliar[j]='\0';
	  cifra=atof(auxiliar);
	  //cifra=_atolg(auxiliar); cambiar la cuando este en Turbo C++ ide
	  infijo[k++]=cifra+'0';
	  operan[m++]=cifra;}
	  if(linea[i])
	  infijo[k++]=linea[i++];}
	  infijo[k++]='#';
	  infijo[k]='\0';
}
/***********************************************************************/
void Notacion::operadores()
{
	 char elemento;
	 while(!pila1_vacia(&operador)){
	 retira1_pila(&operador,&elemento);
	 printf("%c",elemento);}
}
/***********************************************************************/
void Notacion::init1_pila(struct LIFO1 *p)
{
  p->t=0;
}
/***********************************************************************/
int Notacion::pila1_vacia(struct LIFO1 *p)
{
  return(!p->t);
}
/***********************************************************************/
void Notacion::ins1_pila(struct LIFO1 *p,char s)
{
	if(p->t==MAXIMO)
	printf("La pila no soporta mas elementos\n");
	else{
	p->t++;
	p->a[p->t-1]=s;}
}
/***********************************************************************/
void Notacion::retira1_pila(struct LIFO1 *p, char *s)
{
  if(pila1_vacia(p)){
  printf("la Pila Esta Vacia\n");
  *s='#';}
  else {
  *s=p->a[p->t-1];
  p->t--;}
}
/***********************************************************************/
void Notacion::in_a_pos(char *infijo,char *posfijo)
{
	 int i,j;
	 char elemento;
	 i=0;
	 j=-1;
	 init1_pila(&pila);
	 init1_pila(&operador);
	 while(infijo[i]!='#') {
		if(operando(infijo[i])){
		  insertarcola(&cola,infijo[i]);
		  posfijo[++j]=infijo[i++];}
		  else {
			 if(infijo[i]!='(' && infijo[i]!=')')
			  ins1_pila(&operador,infijo[i]);
				while(!pila1_vacia(&pila) && prioridad(tope1(pila),infijo[i])){
				 retira1_pila(&pila,&elemento);
				 posfijo[++j]=elemento;}
				 if(infijo[i]==')')
				  retira1_pila(&pila,&elemento);
				  else
				  ins1_pila(&pila,infijo[i]);
				  i++;}
				  }
				  while(!pila1_vacia(&pila)){
					retira1_pila(&pila,&elemento);
					posfijo[++j]=elemento;}
					posfijo[++j]='\0';
}
/***********************************************************************/
int Notacion::operando(char c)
{
	return(c!='+' &&
	c!='-' &&
	c!='*' &&
	c!='/' &&
	c!='^' &&
	c!=')' &&
	c!='(' );
}
/***********************************************************************/
int Notacion::prioridad(char op1, char op2)
{
	 int i,j;
	 switch(op1)
	 {
		 case '+': i=0; break;
		 case '-': i=1; break;
		 case '*': i=2; break;
		 case '/': i=3; break;
		 case '^': i=4; break;
		 case '(': i=5; break;
	 }
	 switch(op2)
	 {
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
/***********************************************************************/
char Notacion::tope1(struct LIFO1 p)
{
  return (p.a[p.t-1]);
}
/***********************************************************************/
void main()
{
	Notacion Expre;
	int i, sw;
	char op;
	char infijo[MAXIMO],posfijo1[MAXIMO],linea[100];
	double operan[MAXIMO];
	do{
	     clrscr();
	     for(i=0; i<MAXIMO; i++){
	     infijo[i]=' ';
	     linea[i]=' ';
	     operan[i]=0;}
	     textcolor(8+5);
	     printf("\nEscriba la ecuacion\n");
	     scanf("\n");
	     gets(linea);
	     Expre.c_expresion(linea,infijo,operan);
	     Expre.in_a_pos(infijo,posfijo1);
	     Expre.llenar(infijo,posfijo1);
	     textcolor(15);
	     printf("\nLos Operadores Son\n");
	     Expre.operadores();
	     printf("\nLas Variables Son\n");
	     Expre.Cola();
	     printf("\nDesea Seguir Evaluando Expresiones S o N::>\n");
	     sw=0;
	     do{
		 op=toupper(getch());
		 if(op=='N'|| op=='S')
		 sw=1;
	      }while(sw!=1);
	  }while(op!='N');
	  p1=Cab1;
	  p1=Cab1;
	  while(p1!=NULL){
	    printf("\nExpresion En Infijo: %s\n",p1->infijo);
	    printf("\nConversion En Posfijo: %s\n",p1->posfijo);
	    p1=p1->sig;}
	    getch();
}
