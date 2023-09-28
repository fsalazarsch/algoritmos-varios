  #include "ctype.h"
  #include "alloc.h"
  #include "stdio.h"
  #include "conio.h"
  #include "dos.h"
  #define memo (struct nodo*)malloc(sizeof (struct nodo))

struct nodo{
 int info;
 char nombre[15];
 struct nodo *sig;
 };
 int n;
 int codigo[8];
 char nombre[15];
 struct nodo *p,*q,*cab,*sig;

 /*****************************************************************/

void crea_lista_circular();
void adicionar();
//void eliminar();

 /*****************************************************************/
  void crea_lista_circular()
  {
  char op;
  clrscr();
  p=NULL;
  q=NULL;
  cab=NULL;
   do {
    clrscr();
	q=memo;
	printf("DIGITE CODIGO :");
	scanf("%d",&q->info);
	fflush(stdin);
	printf("DIGITE EL NOMBRE :");
	gets(q->nombre);



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
  puts(p->nombre);
  p=p->sig;
  puts(p->codigo);
  p=p->sig;
  }
    getche();
 }
 /********************************************************************/
 void adicionar()
   {
    //struct nodo *ins(p,n)
    struct nodo *p;
	 int n;
	 {
      struct nodo *nuevo;
	 nuevo=memo;
	 scanf("%d",&q->info);
	 gets(q->nombre);

	 if(p==NULL)
	  nuevo->sig=nuevo;
	 else
	 {
	  nuevo->sig=p->sig;
	  p->sig=nuevo;
	 }
	  p=nuevo;
	  getch();
   }
 }
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
 gotoxy(20,13);
 printf("4. SALIR ");
 gotoxy(20,14);
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
      /* case 3:
	       eliminar();
	       break;*/
	  case '4':
	       break;

	/*default:clrscr();
		gotoxy(30,30);
		printf("Opcion Errada ");
		getch();
		break; */

	}

	  } while(op!='4');
     }

 /*******************************************************************/
 void main()
 { clrscr();
   menu();
//   cab=NULL;
 }
 /*******************************************************************/
