# include<alloc.h>
#include<conio.h>
#include<stdio.h>;
# define localizar (struct nodo*)malloc(sizeof(struct nodo));
#define p1( x ) printf (" %d ", x )
struct nodo{
   int info;
   struct nodo*sig;
   };
   main()
   {
   clrscr();
   struct nodo*cab,*q,*p;
   int i=10;
   cab=NULL;
   while (i>0){
   q=localizar;
   q->info=i;
   q->sig=cab;
   cab=q;
   i=i-1;
   }
   p=cab;
   while(p!=NULL)
   {
   p1 (p->info);
   p=p->sig;
}
getch();
   }
