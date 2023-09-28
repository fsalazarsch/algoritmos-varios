#include <stdio.h>
#include <conio.h>
#include <string.h>
# include "iostream.h"
#define MAXIMO 100

struct LIFO {
	int t;
	char a[100];
};

void main ()
{
	clrscr();
	char prefijo [100],posfijo[100];
	int i;
	void pre_a_pos (char *posfijo,char *prefijo);
	gotoxy(20,9);textcolor(2);cprintf("ESCRIBE LA EXPRESION EN PREFIJO: ");
	gets (prefijo);
	i = strlen (prefijo);
	prefijo [i] = '#';
	prefijo [i+1] = '\0';
	pre_a_pos (prefijo,posfijo);
	gotoxy(25,12);printf("EXPRESION EN PREFIJO: ");
	textcolor(2);cprintf("%s ",prefijo);
	gotoxy(25,15);printf("TRANSFORMADA A POSFIJO: ");
	textcolor(2);cprintf("%s ",posfijo);
  getche();
}


void pre_a_pos (char *prefijo,char *posfijo)
{
	
	struct LIFO pila;
	int operando (char c);
	int prioridad (char op1,char op2);
	char tope (struct LIFO p);
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p,char s);
	void retira_pila (struct LIFO *p,char *s);
	int i,j;
	char elemento;

	i=0;
	j=-1;
	init_pila (&pila);
	while (prefijo [i] != '#') {
		if (operando(prefijo[i]) )
				posfijo [++j] = prefijo [i++];
		else {
				while (!pila_vacia (&pila)  &&
					 prioridad (tope (pila),prefijo [i] ) )  {
					retira_pila (&pila,&elemento);
					posfijo [++j] = elemento;
				}
				ins_pila (&pila,prefijo [i++]);
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
		case '+' :  j = 0; break;
		case '-' :  j = 1; break;
		case '*' :  j = 2; break;
		case '/' :  j = 3; break;
		case '^' :  j = 4; break;
	}
	switch (op2) {
		case '+' :  i = 0; break;
		case '-' :  i = 1; break;
		case '*' :  i = 2; break;
		case '/' :  i = 3; break;
		case '^' :  i = 4; break;
	}
	return (m [j][i]);

}
char tope (struct LIFO p)
{
	return ( p.a [p.t -1] );
}

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
		cout<<"la pila no soporta mas elementos\n";
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void retira_pila (struct LIFO *p,char *s)
{
	if (pila_vacia (p) )  {
		cout<<"la pila esta vacia\n";
		*s = '#';
	}
	else  {
		  *s = p->a [p->t - 1];
		  p->t--;
	}
}




