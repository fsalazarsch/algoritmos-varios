#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAXIMO 100

struct LIFO {
	int t;
	char a[100];
};

void main ()
{
	textbackground(12);
	textcolor(2);
	clrscr();
	char posfijo [100],infijo[100];
	int i;
	void in_a_pos (char *infijo,char *posfijo);
	gotoxy(50,20);printf("INGRI MEZA RESTREPO\n");
	gotoxy(47,21);printf("ANDREA PIRAQUIVE SANCHEZ\n");
	gotoxy(52,22);printf("PARCIAL FINAL\n");
	gotoxy(25,5);printf(" I N F I J O  A  P O S F I J O\n ");
	gotoxy(22,7);printf("DE LA EXPRESION CORRECTAMENTE EN INFIJO\n");
	gotoxy(18,9);printf("ESTE PROGRAMA NO TRABAJA EXPRESIONES CON PARENTESIS \n");
	gets (infijo);
	i = strlen (infijo);
	infijo [i] = '#';
	infijo [i+1] = '\0';
	in_a_pos (infijo,posfijo);
	gotoxy(35,15);printf ("%s  %s  ",infijo,posfijo);
  getche();
}

void in_a_pos (char *infijo,char *posfijo)
{
	struct LIFO pila;
	int operando (char c);
	int prioridad (char op1,char op2);
	char tope (struct LIFO p);
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,char s);
	void retira_pila (struct LIFO *p,char *s);
	//
	int i,j;
	char elemento;
	i=0;
	j=-1;
	init_pila (&pila);
	while (infijo [i] != '#') {
		if (operando (infijo [i]) )
				posfijo [++j] = infijo [i++];
		else {
				while (!pila_vacia (&pila)  &&
					prioridad (tope (pila),infijo [i] ) )  {
					retira_pila (&pila,&elemento);
					posfijo [++j] = elemento;
				}
				ins_pila (&pila,infijo [i++]);
			}
	}
	while (!pila_vacia (&pila) ) {
		retira_pila (&pila,&elemento);
		posfijo [++j] = elemento;
	}
	posfijo [++j] = '\0';
}


int operando (char c)
{
	return ( c != '+' &&
		 c != '-' &&
		 c != '*' &&
		 c != '/' &&
		 c != '^'   );
}

static int m[5][5] = {
	{ 1,1,0,0,0 },
	{ 1,1,0,0,0 },
	{ 1,1,1,1,0 },
	{ 1,1,1,1,0 },
	{ 1,1,1,1,1 }
};

int prioridad (char op1,char op2)
{
	int i,j;

	switch (op1) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '/' :  i = 3; break;
		case '^' :  i = 4; break;
	}
	switch (op2) {
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '/' :  j = 3; break;
		case '^' :  j = 4; break;
	}
	return (m [i][j]);
}

char tope (struct LIFO p)
{
	return ( p.a [p.t -1] );
}
//evalua una expresion en posfijo
void init_pila (struct LIFO *p)
{
	p->t = 0;
}

int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void ins_pila (struct LIFO *p,char s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,char *s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}




