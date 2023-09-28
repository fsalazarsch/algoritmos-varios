#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#define MAXIMO 100

struct LIFO {
	int t;
	char a[100];
};

class inapre{
      struct LIFO pila;
      int i,j;
      char elemento;
      public:
      inapre(){
		clrscr();printf("CONSTRUYENDO");
	      }
      void in_a_pre(char *infijo,char *prefijo);
      void init_pila(struct LIFO *p);
      void ins_pila(struct LIFO *p,char s);
      void retira_pila (struct LIFO *p,char *s);
      int operando(char c);
      int prioridad(char op1,char op2);
      int pila_vacia(struct LIFO *p);
      char tope(struct LIFO p);
      ~inapre(){
		 clrscr();printf("DESTRUIDO");
	       }
};



void inapre::in_a_pre(char *infijo,char *prefijo)
{
  struct LIFO pila;

  i=0;
  j=-1;
  init_pila (&pila);
  while (infijo [i] != '#')
       {
	 if (!operando (infijo [i]) )
	   prefijo [++j] = infijo [i++];
	 else
	   {
	     while (!pila_vacia (&pila) && prioridad (tope (pila),infijo [i] ) )
		  {
		    retira_pila (&pila,&elemento);
		    prefijo [++j] = elemento;
		  }
	     ins_pila (&pila,infijo [i++]);
	   }
       }
  while (!pila_vacia (&pila) )
       {
	 retira_pila (&pila,&elemento);
	 prefijo [++j] = elemento;
       }
  prefijo [++j] = '\0';
}

int inapre::operando (char c)
{
  return ( c != '+' && c != '-' && c != '*' && c != '/' && c != '^' );
}

static int m[5][5] = {
	{ 1,1,0,0,0 },
	{ 1,1,0,0,0 },
	{ 1,1,1,1,0 },
	{ 1,1,1,1,0 },
	{ 1,1,1,1,1 }
};

int inapre::prioridad (char op1,char op2)
{
  int i,j;

  switch (op1)
	{
	  case '+' :  i = 0; break;
	  case '-' :  i = 1; break;
	  case '*' :  i = 2; break;
	  case '/' :  i = 3; break;
	  case '^' :  i = 4; break;
	}
  switch (op2)
	{
	  case '+' :  j = 0; break;
	  case '-' :  j = 1; break;
	  case '*' :  j = 2; break;
	  case '/' :  j = 3; break;
	  case '^' :  j = 4; break;
	}
  return (m [i][j]);
}

char inapre::tope (struct LIFO p)
{
  return (p.a[p.t-1]);
}

void inapre::init_pila (struct LIFO *p)
{
  p->t = 0;
}

int inapre::pila_vacia (struct LIFO *p)
{
  return (!p->t);
}

void inapre::ins_pila(struct LIFO *p,char s)
{
  if (p->t == MAXIMO)
     printf ("la pila no soporta mas elementos\n");
  else
    {
      p->t++;
      p->a [p->t - 1] = s;
    }
}

void inapre::retira_pila (struct LIFO *p,char *s)
{
  if (pila_vacia (p) )
    {
      printf ("la pila esta vacia\n");
      *s = '#';
    }
  else
    {
      *s = p->a [p->t - 1];
      p->t--;
    }
}


void mascara();
void final();
void cuadro(int prin,int fin,int fl,int cl,int co);

void main ()
{
  char prefijo [100],infijo[100];
  int i;
  inapre j;
  void mascara();
  textbackground(1);
  textcolor(11);
  clrscr();
  gotoxy(5,5);printf ("INTRODUZCA SU EXPRESION EN INFIJO... ");
//	printf ("Este programa no trabaja expresiones con Parentesis\n");
  gotoxy(5,7);gets (infijo);
  i = strlen (infijo);
  infijo [i] = '#';
  infijo [i+1] = '\0';
  j.in_a_pre(infijo,prefijo);
  gotoxy(5,9);printf ("Su Expresion En <<<INFIJO>>>... %s ",infijo);
  gotoxy(5,11);printf("Su Expresion En <<<PREFIJO>>>... %s ",prefijo);
  getche();
  final();
}

void cuadro(int prin,int fin,int fl,int cl,int co)
{
int i;
  for(i=prin;i<=fin;i++)
  {
    delay(10);
//    sound(i*60);
    textcolor(co);
    gotoxy(i,fl);cprintf("Í");
    gotoxy(i,cl);cprintf("Í");
  }
  for(i=fl;i<=cl;i++)
  {
    delay(10);
//    sound(i*70);
    textcolor(co);
    gotoxy(prin,i);cprintf("º");
    gotoxy(fin,i);cprintf("º");
  }
    gotoxy(prin,fl);cprintf("É");
    gotoxy(fin,fl);cprintf("»");
    gotoxy(prin,cl);cprintf("È");
    gotoxy(fin,cl);cprintf("¼");
    nosound();
}
void mascara()
  {
   textmode(BW80);
   cuadro(5,75,2,24,11);
   textbackground(8);
   cuadro(26,57,4,6,3+200);
   textcolor(15);gotoxy(29,5);cprintf("JESUS JAIR SOLANO CANTILLO");
   textcolor(11);
   gotoxy(32,11);cprintf("MODELOS DE PROGRAMACION II");
   gotoxy(40,12);cprintf("S3A");
   gotoxy(22,19);cprintf("CORPORACION UNIVERSITARIA DE SANTANDER ");
   gotoxy(35,20);cprintf("U   D   E   S");
   gotoxy(36,21);cprintf("VALLEDUPAR");
   gotoxy(39,22);cprintf("1999");
   textcolor(7+200);gotoxy(5,25);cprintf("Presione una tecla para continuar");
   getche();
   clrscr();
  }

void final()
   {
     textmode(BW40);textcolor(11);
     cuadro(3,40,1,24,7+200);
     textcolor(11);gotoxy(5,12);cprintf("Gracias Por Este Servicio Les Dice");
     getch();clrscr();
     cuadro(3,40,1,24,7+200);
     textcolor(3+200); gotoxy(10,12);cprintf("\"J E S U S  S O L A N O\"");
     getch();
   }
