#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#define  localizar  (struct nodo *) malloc (sizeof (struct nodo))
#define p1(x) printf ("%d",x)
struct nodo {
	int info;
	struct nodo *sig;
};

main()
{
	struct nodo  *cabeza,*cabeza1,*insertar1();
	int numero;

	printf ("utilizando la funcion insertar2 ()\n");
  	cabeza = NULL;
	printf ("de numero a insertar en la lista\n");
	scanf ("%d",&numero);
	while (numero != 9999) {
		insertar2 (&cabeza,numero);
		printf ("de numero a insertar en la lista\n");
		scanf ("%d",&numero);
	}
	printf ("\n utilizando la funcion insertar1 ()\n");
  	cabeza1 = NULL;
	printf ("de numero a insertar en la lista\n");
	scanf ("%d",&numero);
	while (numero != 9999) {
		cabeza1 = insertar1 (cabeza1,numero);
		printf ("de numero a insertar en la lista\n");
		scanf ("%d",&numero);
	}
	concatenar (&cabeza,cabeza1);
	escribir_lista (cabeza);
}

struct nodo *insertar1 (p,n)
struct nodo *p;
int n;
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	if (p == NULL)
	   nuevo->sig = nuevo;
	else {
		   nuevo->sig = p->sig;
		   p->sig = nuevo;
	     }
	p = nuevo;
	return (p);
}
insertar2 (p,n)
struct nodo **p;
int n;
{
	struct nodo *nuevo;

	nuevo = localizar;
	nuevo->info = n;
	if (*p == NULL)
	   nuevo->sig = nuevo;
	else {
		   nuevo->sig =(*p)->sig;
		   (*p)->sig = nuevo;
	     }
	*p = nuevo;
}

escribir_lista (p)
struct nodo *p;
{
	struct nodo *q;

	if (p==NULL)
	   printf ("vacia\n");
	else {
			q = p;
			do {
				q=q->sig;
				printf ("%d ",q->info);
			} while (p != q);
	    	}
}
concatenar (p,q)   /*  concatena  dos listas */
struct nodo **p,*q;
{
	struct nodo *r;

	if (q != NULL)
	    if (*p != NULL) {
			r = q->sig;
			q->sig = (*p)->sig;
			(*p)->sig = r;
			*p = q;
		}
		else  *p = q;
getch();
}

