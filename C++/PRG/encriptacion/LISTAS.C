#include <stdio.h>
#include <stdlib.h>
#define localizar (struct nodo*)  malloc(sizeof(struct nodo))
#define MAX 7
/*PROGRAMA DE ORDENAMIENTO DE UNA LISTA SIMPLE QUE IMPRIME SU DIRECCION Y
LA DEL PROXIMO ELEMENTO*/

struct nodo
   {
    int info;
    struct nodo* sig;
   };

struct nodo *cab, *p, *q, *nuevo;
void insertar(struct nodo**cab,struct nodo *p,struct nodo*q);
void mostrar(struct nodo*cab);

main()
  {
   cab=NULL;
   insertar(&cab,p,q);
   mostrar(cab);
   return(0);
  }

void insertar(struct nodo**cab, struct nodo*p,struct nodo*q)
  {
   int i;
   for (i=1; i<=MAX; i++)
       {
	nuevo=localizar;
	printf("Entre nuevo %d",i);
	scanf("%d",&nuevo->info);
	p=NULL;
	q=*cab;
	if (q!=NULL)
	   {
	    while (nuevo->info>=q->info)
		  {
		   p=q;
		   q=q->sig;
		   if (q==NULL) break;
		  }
	   }
	nuevo->sig=q;
	if (p!=NULL)
	   {
	    p->sig=nuevo;
	   }
	else
	    {
	     *cab=nuevo;
	     }
       }
  }

void mostrar(struct nodo*cab)
  {
   p=cab;
   while(p!=NULL)
	{
	 printf("\n n£mero %d direcci¢n %p siguiente %p",p->info,p,p->sig);
	 p=p->sig;
	}
  }

