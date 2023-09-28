  #include "ctype.h"
  #include "iostream.h"
  #include "alloc.h"
  #include "stdio.h"
  #include "conio.h"
  #include "dos.h"
  #define memo (struct nodo*)malloc(sizeof (struct nodo))

struct nodo{   
 int info;
 struct nodo *sig;
 };
 int n,c;
 int codigo[8];
 char nombre[15];
 struct nodo *p,*q,*cab,*sig;

 /*****************************************************************/

void crea_lista();
//void adicionar();
//void eliminar();
 void main()
{
 char op;
 textbackground(4);
 textcolor(15);
 clrscr();
 while(op!='4')
 {
 clrscr();

 gotoxy(30,5);cout<<"M E N U  P R I N C I P A L";
 gotoxy(32,7);cout<< "1) CREAR LISTA ";
 gotoxy(32,8);cout<< "2) ADICIONAR";
 gotoxy(32,9);cout<< "3) ELIMINAR";
 gotoxy(32,10);cout<<"4) SALIR ";
 gotoxy(32,11);cout<<" DIGITE UNA OPCION : ";
 op=getchar();
 switch(op)
 {
	  case '1': crea_lista();break;
	 /* case '2': adicionar();break;
	  case '3': eliminar();break;*/
	  case '4':  break;


    }
   }
 }


 /*****************************************************************/
  void crea_lista()
  {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
	printf("DIGITE CODIGO: ");
	scanf("%d",&n);
	printf("DIGITE NOMBRE: ");
	scanf("%d",&n);
	q=memo;
	q->info=n;
	if(cab==NULL){
	  cab=q;
	  cab->sig=NULL;
	  p=q;
    }
    else{
	p->sig=q;
	q->sig=NULL;
	p=p->sig;
	}

	printf("DESEA ADICIONAR OTRO(s/n):");
	 op=toupper(getche());
    }while(op!='n'&& op!='N');
	p=cab;
	printf("\n");
  while(p!=NULL){
  printf("%d\t",p->info);
  p=p->sig;
  }
    getche();
 }
 /********************************************************************/
 /*void adicionar()
   {
    struct nodo *ins(p,n)
    struct nodo *p;
	 int n;
	 {
	 struct nodo *nuevo;
	 nuevo=memo;
	 nuevo->info=n;
	  if(p==NULL)
	  nuevo->sig=nuevo;
	 else
	 {
	  nuevo->sig=p->sig;
	  p->sig=nuevo;
	 }
	  p=nuevo;
	  return(p);
   }*/
  /*******************************************************************/
  /* void eliminar()
	{
	struct (cab,p,dato);
	  struct nodo **cab,p;
	  int *dato;
	  {
	  struct nodo *q;
	if(*cab=NULL)
	 printf("no se puede retirar");
	  else
	if(p==NULL)
	 printf("no se pude retirar");
	  else
	if(*cab==(*cab)->sig)
	 printf("un solo nodo no se puede retirar");
	  else
	   q=p->sig;
	   *dato=q->info;
	   p->sig=q->sig;
	    if(q==*cab);
	    *cab=p;
	    free(q);
	 }
	dato=p->info;
	cab->sig=p->sig;
	free(p);
	}*/
