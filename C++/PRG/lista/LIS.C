# include <stdio.h>
# include <conio.h>
# define memo (struct nodo*)malloc(sizeof(struct nodo))
# define cpr(x) printf("%d\t",x)
struct nodo{
	     int info;
	     struct nodo *sig;
	   };
struct nodo *p, *q,*cab;
int n;
void crear_lista();
void crear_lista()
{
	char op;
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
   getche();
   return (p);
}

void imprimir_lista(struct nodo *p);
void imprimir_lista(struct nodo *p)
{
	clrscr();
	p=cab;
		gotoxy(5,10);
		printf("\t");
		while (p!=NULL)
		{
		   cpr (p->info);
		   p=p->sig;
		}
		getche();
		return (p);
}
struct nodo *p,*nuevo;
void insertar_despues(struct nodo *p);
void insertar_despues(struct nodo *p)
{
	int n;
	clrscr();
	gotoxy(10,5);printf("DIGITE EL No. A INSERTAR: ");
	scanf("%d",&n);
	if (p==NULL)
	printf("!NO­ se pudo insertar");
	else
	{
	     nuevo=memo;
	     nuevo->info=n;
	     nuevo->sig=p->sig;
	     p->sig=nuevo;
	}
	    gotoxy(5,10);
	    printf("\t");
	    while(p!=NULL)
	    {
	       cpr(p->info);
	       p=p->sig;
	    }
	    getche();
	    return (p);
}

struct nodo *nuevo, *p;
void insertar_antes(struct nodo *p);
void insertar_antes(struct nodo *p)
{
	int n;
	clrscr();
	gotoxy(10,5);printf("DIGITE EL No. A INSERTAR: ");
	scanf("%d",&n);
	if (p==NULL)
	     printf("!NO­ se pudo insertar");
	else
	{
	   nuevo=memo;
	   nuevo->info=p->info;
	   nuevo->sig=p->sig;
	   p->info=n;
	   p->sig=nuevo;
	}
	gotoxy(5,10);
	printf("\t");
	while (p!=NULL)
	{
	   cpr(p->info);
	   p=p->sig;
	}
	getch();
	return (p);
}
struct nodo *nuevo, *p, *q, *cab;
void insertar_entre(struct nodo *p);
void insertar_entre(struct nodo *p)
{
	int n;
	clrscr();
	gotoxy(10,5);printf("DIGITE EL No. A INSERTAR: ");
	scanf("%d",&n);
	if (p==NULL)
		     printf("!NO­ se pudo insertar");
	else
	{
	  nuevo=memo;
	  nuevo->info=n;
	  nuevo->sig=p->sig;
	  p->sig=nuevo;
	}
	gotoxy(5,10);
	printf("\t");
       while (p!=NULL)
       {
	  cpr(p->info);
	  p=p->sig;
       }
       getche();
       return (p);
}

void eliminar_nodo(struct nodo *p);
void eliminar_nodo(struct nodo *p)
{
	struct nodo *q, *cab, *dato;
	clrscr();
	printf("\n");
	if(p->sig==NULL)
	     printf("!NO­ se pudo insertar");
	else
	{
	  q=p->sig;
	  dato=q->info;
	  p->sig=q->sig;
	  free(q);
	}
	gotoxy(5,10);
	printf("\t");
	 while (p!=NULL)
	 {
	   cpr(p->info);
	   p=p->sig;
	 }
	 getche();
	 return (p);
}

void menu()
{
  char op;
   do
   {

	textbackground(BLACK);
	textcolor(15);
	clrscr();
	gotoxy(30,5);printf("MENU DE LAS LISTA");
	gotoxy(30,7);printf("1. CREAT lista");
	gotoxy(30,8);printf("2. IMPRIMIR lista");
	gotoxy(30,9);printf("3. INSERT ANTES ");
	gotoxy(30,10);printf("4. INSERT DESPUES");
	gotoxy(30,11);printf("5. INSERT ENTRE TWO NODO");
	gotoxy(30,12);printf("6. ELIMINATOR THE NODO");
	gotoxy(30,13);printf("7. EXIT....");
	gotoxy(30,15);printf("[ ] No. A SELECCIONAR. ");gotoxy(31,15);printf("");
	op=getch();
	switch (op)
	{
	    case '1':crear_lista();break;
	    case '2':imprimir_lista(p);break;
	    case '3':insertar_antes(p);break;
	    case '4':insertar_despues(p);break;
	    case '5':insertar_entre(p);break;
	    case '6':eliminar_nodo(p);break;
   }
}
  while(op!='7');
}
void main()
{
   struct nodo *cab=NULL;
   clrscr();
   menu();
}