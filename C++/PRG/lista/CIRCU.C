#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<ctype.h>
#define memo (struct nodo *) malloc (sizeof (struct nodo))
struct nodo{
 int info;
 struct nodo *sig;
 };
 struct nodo *p,*q,*r,*cab;
 int n,m,num;
#define imp  cprintf
#define limp  clrscr()
#define pos  gotoxy
#define col  textcolor
#define colp  textbackground
void crealista();
void imprimelista();
void inserantnodo();
void inserdnodo();
void inserdosnodos();
void elimina();
void cuadro();
void musica();
void musica()
 {
  sound(480);
   delay(400);
  nosound();
  }

//******** PRIMERO ****************************************

void crealista()
 {
  char op;
  cab=NULL;
   do {
     limp;
     pos(15,10);imp("DIGITE EL NODO A CREAR ==>");
     scanf("%d",&n);
     q=memo;
     q->info=n;
      if(cab==p)
       if(p!=q){
       //cab=q;
       q=q->sig;
       q->sig=p->sig;
       p=q;
    }
   else{
     p->sig=q;
     q->sig=NULL;
     p=p->sig;
     }  
     pos(15,20);imp(" DESEA ADICIONAR NODO[s/n] ");
     op=toupper(getche());
     }
     while(op!='n'&& op!='N');
     getche();
     }

//************* SEGUNDO ********************************************

void imprimelista()
    {
    struct nodo *nuevo;
    p=cab;q=cab;
    musica();
    limp;
    pos(4,4);col(10);imp(" << CONTENIDO DE LA LISTA >>");
    pos(10,10);
    while(p!=NULL){
     printf("%d\t",p->info);
     p=p->sig;  }
     pos(40,22);col(2+128);imp("<< PRESS  E N T E R  CONTINUE >> ");
     getche();

}

//******************************* SECCION DE MENU ************

void menu();
void menu()
{
   char op;
   while(1)
   {
   colp(1);
   limp;
   colp(15);
   col(1);
   pos(20,7); imp(" << E S T R U C T U R A   DE   D A T O S >> ");
   pos(20,10);imp("                                            ");
   pos(20,11);imp("       M E N U  P R I N C I P A L           ");
   pos(20,12);imp("                                            ");
   pos(20,13);imp("        1.CREAR UNA LISTA                   ");
   pos(20,14);imp("        2.VISUALIZAR  LISTA                 ");
   pos(20,15);imp("        3.INSERTAR                          ");
   pos(20,16);imp("        4.ELIMINAR                          ");
   pos(20,17);imp("        5.SALIR                             ");
   pos(20,18);imp("                                            ");
   pos(20,19);imp("                                            ");
   pos(20,20);imp("                                            ");
   pos(20,21);imp("          ELIJA OPCION  [ ]                 ");
   pos(20,22);imp("                                            ");
   pos(20,23);imp(" Elaborado por: JAIME RINCON B.  S_3_A      ");
   col(15);pos(45,21);op=getchar();op=toupper(op);
   switch(op)
   {
     case '1' :crealista();break;
     case '2' :imprimelista();break;
   /*  case '3' :inserdesnodo();break;
     case '4' :inserantesnodo();break;
     case '5' :elimina();break;
     case '6' :inserdosnodos();break;*/
     case '5' :return;
   }
  }
}
void main()
{
  menu();
}

 