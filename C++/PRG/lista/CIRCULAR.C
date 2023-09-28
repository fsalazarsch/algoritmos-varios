
#include <string.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <process.h>
#define memoria (struct regi*)malloc(sizeof(struct regi))

struct regi{
       int cod;
       char nom[45];
       char ape[45];
       struct regi *sig;
       }nodo;
      struct regi *ptr,*nn,*fin,*p,*q;

int colador(int x,int y);

    void adicionar();
    void eliminar();
    void menu();
    void visualisar();
    void crear();
    void eliminar();
    void modificar();
    void marco();

void cuadro(int x1,int x2,int y1,int y2)
{     int j,i,k;//clrscr();
     textcolor(14);

     for(j=x1;j<=x2;j++)
       {

       gotoxy(j,y1);cprintf("Í");

       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       {
       gotoxy(x1,i);cprintf("º");

       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
}
void marco()
{
    int i, j, op, fil, col, fila;

    textcolor(15);textbackground(9);
    for (fil=1;fil<=6;fil++)
    {
	 gotoxy(1,fil);cprintf("³");
	 gotoxy(80,fil);cprintf("³");
    }
    for (col=1;col<=80;col++)
    {
	 gotoxy(col,1);cprintf("Ä");
	 gotoxy(col,6);cprintf("Ä");
    }
    for (i=2;i<=5;i++)
	 for (j=2;j<=79;j++)
	 {
	      textbackground(29);
	      gotoxy(j,i);cprintf(" ");
	 }
    for (i=7;i<=24;i++)
	 for (j=1;j<=80;j++)
	 {
	      textbackground(8);
	      gotoxy(j,i);cprintf("²");
	 }
    gotoxy(1,1);printf("Ú");gotoxy(80,1);printf("¿");
    gotoxy(1,6);printf("À");gotoxy(80,6);printf("Ù");
    gotoxy(21,3);printf("CORPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy(21,4);printf("FACULTAD DE INGENIERIA DE SISTEMAS S3A");
    window(1,1,80,25);textbackground(5);gotoxy(75,25);printf("MARLA");
}



void menu()
{
int op;
    clrscr();
    while (op!=5)
    {
	 window(1,1,80,25);textbackground(5);clrscr();marco();/*marcomenu();*/
	 gotoxy(34,9);printf("MENU PRINCIPAL");
	 gotoxy(16,12);printf(" 1.Adicinar un nuevo Estudiante     ");
	 gotoxy(16,14);printf(" 2.Modificar Estudiante	           ");
	 gotoxy(16,16);printf(" 3.Eliminar un Estudiante           ");
	 gotoxy(16,18);printf(" 4.Visualisar Estudiate             ");
	 gotoxy(16,20);printf(" 5.Fin Menu Ppal	               ");
	 gotoxy(48,22);printf("Su Elecci¢n ---->  ");scanf("%d",&op);
	 if (op>5)
	 {
	      gotoxy(1,25);printf(" Opci¢n Fuera del Rango");
	      getch();
	 }
	 switch(op)
	 {
	      case 1:{
		     clrscr();	crear();clrscr();break;
		     }
	      case 2:{
		       clrscr();modificar();clrscr();break;
		     }
	      case 3:{
			eliminar();break;
		     }
	      case 4:{
		     clrscr();visualisar();clrscr();	break;
		     }
	 }
    }
}

int colador(int x,int y)
{
int i,a,b,num,swi;
char cad[30];
do{
do{
   gets(cad);swi=0;
   num=strlen(cad);
   }while(num<=0);
   for(i=0;i<num;i++)
   {
   if(!isdigit(cad[i])||(cad[i]=='¤'||cad[i]=='¥'))
   {
      gotoxy(x,y);
//   printf("debe ser un numero");
   clreol();
   gotoxy(x,y);
   swi=1;break;}}
   }while(swi==1);
   return(atoi(cad));}


void crear(){
int cod;
char nom[45];
char ape[45];
char op,n;
int i,x;
do{ op='s';
clrscr();marco();
gotoxy(20,10);printf("digite codigo del usuaario  ");
gotoxy(50,10);
cod=colador(50,10);
{flushall();}
gotoxy(20,13);printf("digite nombre del usuario   ");
gotoxy(50,13);
gets(nom);
gotoxy(20,16);printf("digite apellido del usuario ");
gotoxy(50,16);gets(ape);
nn=memoria;//malloc(sizeof(nodo));
nn->cod=cod;
strcpy(nn->nom,nom);
strcpy(nn->ape,ape);
 if(ptr==NULL){
  p=memoria;//malloc(sizeof(nodo));
 ptr=p;
 p->sig=nn;
 nn->sig=ptr;
     }
  else {
  p=ptr->sig;
  nn->sig=p;
  ptr->sig=nn;
	}

gotoxy(4,22);printf("Desea seguir ingresando  n/s");
gotoxy(40,22);scanf("%c",&op);

}while(op=='s'); }
void modificar(){
int cod;
char nom[45];
char ape[45];
char op,n;
int i,x,swi;
if(ptr==NULL){
clrscr();
cuadro(1,79,1,25);
gotoxy(6,4);printf("NO HAY DATOS");
getche();
    }
    if(ptr!=NULL){
clrscr(); swi=0; marco();
gotoxy(20,10);printf("digite codigo a modificar[*********]");
gotoxy(47,10);
cod=colador(47,10);

p=ptr->sig;
while(p!=ptr){
if(p->cod==cod){
clrscr();marco();
gotoxy(20,10);printf("digite codigo  ");
gotoxy(40,10);
cod=colador(40,10);
gotoxy(20,13);printf("digite nombre  ");
gotoxy(40,13);gets(nom);
gotoxy(20,16);printf("digite apellido  ");
gotoxy(40,16);gets(ape);

p->cod=cod;
strcpy(p->nom,nom);
strcpy(p->ape,ape);
swi=1;
	}
p=p->sig;
}
}
if(swi==0){
gotoxy(4,23);printf("El codigo %d", cod);
gotoxy(8,24);printf("No existe");
getche();

}


}

void visualisar()
{
int x;
cuadro(1,79,1,25);
if(ptr==NULL){
gotoxy(6,4);printf("NO HAY DATOS");
	    }
if(ptr!=NULL){
cuadro(1,79,1,3);

cuadro(1,15,4,25);
cuadro(16,45,4,25);
cuadro(46,79,4,25);

gotoxy(4,2);printf("CODIGO");
gotoxy(18,2);printf("NOMBRE");
gotoxy(48,2);printf("APELLIDO");
x=5;
p=ptr->sig;
while(p!=ptr){
gotoxy(4,x);
printf("%d",p->cod);
gotoxy(18,x);
printf(p->nom);
gotoxy(48,x);
printf(p->ape);
x=x+1;
p=p->sig;

}
 }
getche();}
void eliminar()
{
int cod,swi;
if(ptr==NULL){
clrscr(); cuadro(1,79,1,25);

gotoxy(6,4);printf("NO HAY DATOS");
getche();
    }
    if(ptr!=NULL){
clrscr();marco(); swi=0;
gotoxy(20,10);printf("digite codigo a eliminar....[********]");
gotoxy(50,10);
cod=colador(50,10);
p=ptr->sig;
q=ptr;
while(p!=ptr){
if(p->cod==cod){
q->sig=p->sig;
free(p);swi=1;
if(p->sig==ptr){
ptr=NULL;break;
}

}
q=p;
p=p->sig;

}

if(swi==0){
gotoxy(4,23);printf("El codigo %d", cod);
gotoxy(8,24);printf("No existe");

getche();
}
}
}

main()
{
menu();
}

