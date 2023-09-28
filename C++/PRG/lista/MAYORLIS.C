# include <stdio.h>
# include <conio.h>
# include <dos.h>
# define memo (struct nodo*)malloc(sizeof(struct nodo))
# define escribir(x) printf("%d\t",x)
struct nodo{
int info;
struct nodo *sig;
};
struct nodo *p, *cab, *q;
char op;
void crear(int n);
void crear(int n){
		cab=NULL;
	clrscr();
	cab=NULL;
	do {
		clrscr();
		gotoxy(12,10);printf("DIGITE LOS # DE LA LISTA: ");
		scanf("%d",&n);
		q=memo;
		q->info=n;
		if (cab==NULL)
		{
		     cab=q;
		     cab->sig=NULL;
		     p=q;
		}
	      else
	      {
		p->sig=q;
		q->sig=NULL;
		p=p->sig;
	      }

		gotoxy(12,17);printf("QUIERE CONTINUAR ¨S/N?: ");
		op=toupper(getche());
	}
	while (op!='N'&&op!='n');
		p=cab;

	return(p);
	getch();
  }

void imp(struct nodo *p);
void imp(struct nodo *p)
{
	int may=0;
	clrscr();
	gotoxy(35,12);printf("LISTA");
	printf("\n\n");
	p=cab;
	while (p!=NULL)
	{
		escribir (p->info);
		p=p->sig;
	}

       getch();
       return(p);
}

 void mayor(struct nodo *p);
 void mayor(struct nodo *p)
{
       int may=0;
       clrscr();

       while(p!=NULL)
       {
	 if(may<p->info)
	 {
	   may=p->info;
	 }
       p=p->sig;
      }
      gotoxy(12,10);printf("EL NUMERO MAYOR ES: %d",may);
       getch();
       return (p);
}
void menu(){
char op;
do {
clrscr();
	gotoxy(27,11);printf("1. CREAR, IMPRIME ");
	gotoxy(27,12);printf("2. IMPRIMIR");
	gotoxy(27,13);printf("3. MAYOR");

	gotoxy(27,14);printf("4. SALIR");
	gotoxy(27,15);printf("[ ] No. A SELECCIONAR. ");gotoxy(28,15);printf("");
	op=getch();
switch (op){
	case '1':crear(1);
	case '2':imp(p);break;
	case'3':mayor(p);break;
  }
}while(op!='4');
}
void main(){
	struct nodo *cab=NULL;
	struct nodo *cab1=NULL;
	clrscr();
	menu();

 }