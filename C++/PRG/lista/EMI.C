#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>

#define memo (struct nodo*)malloc(sizeof(struct nodo))
struct nodo{ 
	     int info;
	     struct nodo *sig;
	     };
  
	      struct nodo *crearlis(int valor)
	      {
	      clrscr();
	       struct nodo *p,*q;
	       valor=5;
	      p = NULL;
	      while(valor>0){
		  q=memo;
		  q->info=valor;
		  p=q;
		  valor--;
		  printf("%4d", q->info);
		  }
		  return(p);

	        }

		void main()
		{
		   clrscr();
		   struct nodo *p;
		   p=crearlis(10);
		   //escribir_lista();
		   getch();
		   }

