#include"a:menu.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include"iostream.h"
#include <stdlib.h>
#include<dos.h>
#include"io.h"
#define MAXIMO 100
#define localizar (struct LIFO *)malloc(sizeof(struct LIFO))
typedef struct LIFO LIFO;
 struct LIFO {
	int t;
	char a[100];

	 };

class cel
{
 public:
 void udes();
 void password();
 void menu_principal();
 void init_pila (struct LIFO *p);
 void ins_pila (struct LIFO *p,char s);
 void retira_pila (struct LIFO *p,char *s);
 void in_a_pre (char *infijo,char *prefijo);
 struct LIFO pila;
 int operando (char c);
 int prioridad (char op1,char op2);
 char tope (struct LIFO p);
 int pila_vacia (struct LIFO *p);
 void jhogus ();
/************************** CONSTRUCTOR Y DESTRUCTOR ***********************/
 cel(){
 cprintf ("CONSTRUCTOR");
		 };

 ~cel(){
cprintf ("DESTRUCTOR");
};
};
/****************************************************************************/
/***************************************UDES ******************************/
 void cel::udes()
 {
int m=10,k;//window(1,1,80,25);
textbackground(0);clrscr();
for(k=1;k<2;k++){
int i,a,b,c,d,e,f;
textcolor(m+3);
clrscr();
a=1;b=2;c=3;d=4;e=5;f=6;
for(i=10;i<18;i++)
{
gotoxy(i,a);sound(a*60);delay(50);cprintf("                        ");
gotoxy(i,b);sound(b*60);delay(50);cprintf(" ⁄ƒƒƒø  ⁄ƒƒƒø ⁄ƒƒƒƒƒƒƒƒø");
gotoxy(i,c);sound(c*60);delay(50);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€€€€‹‹≥");
gotoxy(i,d);sound(d*60);delay(50);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€  ﬂ€€≥");
gotoxy(i,e);sound(e*60);delay(50);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");
gotoxy(i,f);sound(f*60);delay(50);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");
a++;b++;c++;d++,e++;f++;
delay(20);
}
a=3;b=4;c=5;d=6;e=7;f=8;
for(i=47;i>=42;i--)
{
gotoxy(i,a);sound(a*40);delay(50);cprintf("                    ");
gotoxy(i,b);sound(b*40);delay(50);cprintf("⁄ƒƒƒƒƒƒƒø ⁄ƒƒƒƒƒƒƒø ");
gotoxy(i,c);sound(c*40);delay(50);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");
gotoxy(i,d);sound(d*40);delay(50);cprintf("≥€€€⁄ƒƒƒŸ ≥€€€⁄ƒƒƒŸ ");
gotoxy(i,e);sound(e*40);delay(50);cprintf("≥€€€¿ƒƒƒø ≥€€€¿ƒƒƒø ");
gotoxy(i,f);sound(f*40);delay(50);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");

a++;b++;c++;d++,e++;f++;
delay(20);
}
a=21;b=22;c=23;d=24;e=25;
for(i=10;i<18;i++)
{
gotoxy(i,a);sound(i*50);delay(50);cprintf(" ≥€€€≥  ≥€€€≥ ≥€€€   €€≥");
gotoxy(i,b);sound(i*50);delay(50);cprintf(" ≥€€€¿ƒƒŸ€€€≥ ≥€€€   €€≥");
gotoxy(i,c);sound(i*50);delay(50);cprintf(" ≥€€€€€€€€€€≥ ≥€€€€€€ﬂﬂ≥");
gotoxy(i,d);sound(i*50);delay(50);cprintf(" ¿ƒƒƒƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒƒŸ");
gotoxy(i,e);sound(i*50);delay(50);cprintf("                       ");
a--;b--;c--;d--;e--;delay(20);
}


a=19;b=20;c=21;d=22;e=23;f=24;
for(i=47;i>=42;i--)
{
gotoxy(i,a);sound(a*60);delay(50);cprintf("≥€€€⁄ƒƒƒŸ ¿ƒƒƒø€€€≥ ");
gotoxy(i,b);sound(b*60);delay(50);cprintf("≥€€€¿ƒƒƒø ⁄ƒƒƒŸ€€€≥ ");
gotoxy(i,c);sound(c*60);delay(50);cprintf("≥€€€€€€€≥ ≥€€€€€€€≥ ");
gotoxy(i,d);sound(d*60);delay(50);cprintf("¿ƒƒƒƒƒƒƒŸ ¿ƒƒƒƒƒƒƒŸ ");
gotoxy(i,e);sound(e*60);delay(50);cprintf("                    ");
a--;b--;c--;d--;e--;delay(20);
}
m++;
}
gotoxy(27,20);textcolor(15+127);cprintf("PRESS ANY KEY TO CONTINUE");
gotoxy(52,20);textcolor(15);nosound();getche();
}

/*********************************************************************/

void main()
{
  clrscr();
  cel obj;
  obj.udes();
  obj.password();
  obj.menu_principal();
}
/**********************************MENU PRINCIPAL ***************************/
void cel::menu_principal()
{
	menu i;
	submenu j;
	int op,op1;
	clrscr();
	do
	{
		i.cls();
		i.inicializar(1,LIGHTGRAY);
		i.additem(1,"Infijo a Prefijo","presione ENTER para ver la opcion de Infijo a Prefijo ");
		i.additem(2,"Salir","presione ENTER para salir del menu");
		op=i.runmenu(LIGHTGRAY,GREEN);
		switch(op)
		{
			case 1:
			{


				j.inicializar();
				j.additem(1,"Infijo a Prefijo...","Infijo a Prefijo");
				op1=j.runsubmenu(LIGHTGRAY,GREEN);
				switch(op1)
				{
					case 1:
					{
						jhogus();
						break;
					}


				}
				break;
			}
			case 2:
			{
				exit(1);
			}
		}
	}while(1);
}

/************************************* PRESENTACION ***************************/

void cel::jhogus()
{
	ventana k;
	char prefijo [100],infijo[100];
	int i;
	k.dventana(2,3,79,10,BLUE,YELLOW,"INFIJO A PREFIJO");
	gotoxy(2,2);
	cprintf ("DIGITE LA EXPRESION CORRECTA EN INFIJO.\n");
	textcolor(WHITE);
	gotoxy(2,3);
	strcpy(infijo,cgets(infijo));
	i = strlen (infijo);
	infijo [i] = '#';
	infijo [i+1] = '\0';
	in_a_pre (infijo,prefijo);
	textcolor(YELLOW);
	gotoxy(3,5);
	cprintf("INFIJO               PREFIJO");
	textcolor(WHITE);
	gotoxy(3,6);
	cprintf("%s",infijo);
	gotoxy(24,6);
	cprintf("%s",prefijo);
	getch();
	window(1,1,80,25);
}

/********************************INFIJO A PREFIJO ****************************/
void cel::in_a_pre (char *infijo,char *prefijo)
{

	int i,j;
	char elemento;

	i=0;
	j=-1;
	init_pila (&pila);
	while (infijo [i] != '#') {
		if (!operando (infijo [i]) )
				prefijo [++j] = infijo [i++];
		else {
				while (!pila_vacia (&pila)  &&
					 prioridad (tope (pila),infijo [i] ) )  {
					retira_pila (&pila,&elemento);
					prefijo [++j] = elemento;
				}
				ins_pila (&pila,infijo [i++]);
			}
	}
	while (!pila_vacia (&pila) ) {
		retira_pila (&pila,&elemento);
		prefijo [++j] = elemento;
	}
	prefijo [++j] = '\0';
}


int cel::operando (char c)
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

int cel::prioridad (char op1,char op2)
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

char cel::tope (struct LIFO p)
{
	return ( p.a [p.t -1] );
}

void cel::init_pila (struct LIFO *p)
{
	p->t = 0;
}

int cel::pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void cel::ins_pila (struct LIFO *p,char s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
		  p->t++;
		  p->a [p->t - 1] = s;
	}
}

void cel::retira_pila (struct LIFO *p,char *s)
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
/********************************CLAVE DEL PROGRAMA ************************/
void cel::password()
{
	char pw[12];
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
	window(25,11,56,14);
	textbackground(BLUE);
	clrscr();
	window(24,10,55,13);
	textbackground(RED);
	clrscr();

   do
   {
		gotoxy(2,2);
   	printf("ENTER YOUR PASSWORD:");
   	strcpy(pw,passwd(8,WHITE,BLUE));
      if(strcmp(pw,"shakira")==0)
      {
			gotoxy(2,4);
			printf("CONGRATULATIONS PASSWORD IS OK");
			delay(1000);
			gotoxy(2,4);
			printf("                        ");

      }
      else
      {
			gotoxy(5,4);
			printf("SORRY INCORRECT PASSWORD");
			delay(1000);
			gotoxy(5,4);
         printf("                              ");
		}
	}while(strcmp(pw,"shakira")!=0);
	window(1,1,80,25);
}


