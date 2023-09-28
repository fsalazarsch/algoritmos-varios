   #include "ctype.h"
  #include "alloc.h"
  #include "stdio.h"
  #include "conio.h"
  #include "string.h"
  #include "dos.h"
  #define memo (struct nodo*)malloc(sizeof (struct nodo))

struct nodo{
 char codigo[50];
 char nombre[50];
 struct nodo *sig;
 };
 int n;
 char codigo[50];
 char nombre[50];
 struct nodo *p,*q,*cab,*sig;

 /*****************************************************************/

void crea_lista_circular();
void adicionar();
void eliminar();
void imprimir();
 /*****************************************************************/
  void adicionar()
  {
  char op;
  clrscr();
  p=NULL;
  q=NULL;

   do {
    clrscr();
	q=memo;
	printf("DIGITE CODIGO :");
	gets(q->codigo);
	fflush(stdin);
	printf("DIGITE EL NOMBRE :");
	gets(q->nombre);


	if(cab==NULL){
	  cab=q;
	  q->sig=cab;
    }
    else{
	p=cab;
	while(p->sig!=cab && strcmp(p->codigo,q->codigo)!=0)
	    p=p->sig;
	if(p->sig==cab && strcmp(p->codigo,q->codigo)==0)
	{
	printf("Codigo Repetido..................");
	getch();
	free(q);
	return;
	}else
	if(p->sig!=cab && strcmp(p->codigo,q->codigo)==0)
	{
	printf("Codigo Repetido..................");
	getch();
	free(q);
	return;
	}else{
	   p=cab;
	while(p->sig!=cab)
	   p=p->sig;
	p->sig=q;
	q->sig=cab;
	}
       }
	printf("DESEA ADICIONAR OTRO(s/n):");
	 op=toupper(getche());
    }while(op!='n'&& op!='N');
    getche();
 }
 /********************************************************************/
  void crea_lista_circular(){
  clrscr();
  if(cab==NULL){
  cab=NULL;
  printf("Inicializacion De La Lista..........................");
  }
  else
   printf("La Inicializacion De La Lista Ya Se Realizo ......");
   getch();
   }
  /*******************************************************************/
  void eliminar()
     {
  char op;
  int sw=0;
  clrscr();
  p=NULL;
  q=NULL;

   do {
    clrscr();
	printf("DIGITE CODIGO A ELIMINAR :");
	gets(codigo);
	fflush(stdin);
	q=NULL;
	p=cab;
	sw=0;
	while(p->sig!=cab && sw==0){
	    if(strcmp(p->codigo,codigo)==0)
	    sw=1;
	    else{
	    q=p;
	    p=p->sig;
	    }
	    }
	if(sw==0)
	{
	if(p->sig==cab &&strcmp(p->codigo,codigo)==0 && q==NULL)
	{
	cab=NULL;
	printf("Codigo Eliminado.................");
	p->sig=NULL;
	 free(p);
	getch();
	}else{
	q->sig=p->sig;
	printf("Codigo Eliminado.................");
	p->sig=NULL;
	 free(p);
	getch();
       }	

       
      
      }
	if(sw==1 && strcmp(p->codigo,codigo)==0){

	if(p->sig!=cab && strcmp(p->codigo,codigo)==0 &&q==NULL )
	{
	  printf("Codigo Eliminado.................");
	 q=cab;
	 while(q->sig!=cab)
	 q=q->sig;
	 q->sig=p->sig;
	 cab=q;
	 p->sig=NULL;
	 free(p);
	getch();
	}else{
	printf("Codigo Eliminado......................");
	q->sig=p->sig;
	p->sig=NULL;
	free(p);
	getch();
	}
	}

	

       
	printf("\nDESEA ELIMINAR  OTRO(s/n):");
	 op=toupper(getche());
    }while(op!='n'&& op!='N');
    getche();

	}

 /*******************************************************************/
  void menu()
 { int op;
 do
 {
 clrscr();
 gotoxy(20,10);
 printf("1. CREA LISTA CIRCULAR ");
 gotoxy(20,11);
 printf("2. ADICIONAR ");
 gotoxy(20,12);
 printf("3. ELIMINAR ");
 gotoxy(20,14);
 printf("4. VISUALIZAR ");
 gotoxy(20,15);
 printf("5. SALIR ");
 gotoxy(20,16);
 printf(" ESCOJA UNA OPCION... ");
  op= getch();

     switch(op)
     {
      case '1':
	       crea_lista_circular();
		  break;
       case '2':
	       adicionar();
	       break;
       case '3':
	       eliminar();
	       break;
       case '4':imprimir();
	       break;

	/*default:clrscr();
		gotoxy(30,30);
		printf("Opcion Errada ");
		getch();
		break; */

	}

	  } while(op!='5');
     }

 void imprimir(){
 clrscr();
 if(cab==NULL)
 printf("Lista Circular Vacia.........................");
 else
 {
 p=cab;
 printf("Codigo                      Nombre\n\n\n");
 printf("%s                          %s        \n",p->codigo,p->nombre);
 while(p->sig!=cab){
 p=p->sig;
 printf("%s                          %s        \n",p->codigo,p->nombre);

 }
}
getch();
}
 /*******************************************************************/
 void main()
 { clrscr();
   cab=NULL;
   menu();

 }
 /*******************************************************************/
