#include<process.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<alloc.h>
#include<dos.h>
#define memoria (struct regi *)malloc(sizeof(struct regi))
struct regi{
       int cod;
       char nom[45];
       char ape[45];
       struct regi *sig;
       }nodo;
      struct regi *ptr,*nn,*fin,*p,*q;

int colador(int x,int y);



void crearlistacircular();
void imprimir();
void modificar();
void eliminar();
char opc;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

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

void crearlistacircular(){
clrscr();
int cod;
char nom[45];
char ape[45];
char op,n;
int i,x;
do{ op='s';
clrscr();
gotoxy(20,10);printf("DIGITAR CODIGO ");
gotoxy(50,10);
cod=colador(50,10);
{flushall();}
gotoxy(20,13);printf("NOMBRE");
gotoxy(50,13);
gets(nom);
gotoxy(20,16);printf("APELLIDO");
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

gotoxy(20,22);printf("OTRO DATO  n/s");
gotoxy(40,22);scanf("%c",&op);

}while(op=='s'); }

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++================================================================

void modificar(){
clrscr();
int cod;
char nom[45];
char ape[45];
char op,n;
int i,x,swi;
if(ptr==NULL){
clrscr();
gotoxy(6,4);printf("LISTA VACIA");
getche();
    }
    if(ptr!=NULL){
clrscr(); swi=0; 
gotoxy(20,10);printf("DIGITAR CODIGO          Nø[       ]");
gotoxy(47,10);
cod=colador(47,10);

p=ptr->sig;
while(p!=ptr){
if(p->cod==cod){
clrscr();
gotoxy(20,10);printf("NUEVO CODIGO  ");
gotoxy(40,10);
cod=colador(40,10);
gotoxy(20,13);printf("NOMBRE  ");
gotoxy(40,13);gets(nom);
gotoxy(20,16);printf("APELLIDO  ");
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
gotoxy(20,24);printf("ESTE CODIGO NO SE ENCUENTRA");
getche();

}

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void imprimir(){
clrscr();
	int x;
if(ptr==NULL){
gotoxy(6,4);printf("NO HAY DATOS");
		 }
if(ptr!=NULL){
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



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void eliminar(){
clrscr();
int cod,swi;
if(ptr==NULL){
clrscr(); 

gotoxy(6,4);printf("LISTA VACIA");
getche();
	 }
	 if(ptr!=NULL){
clrscr(); swi=0;
gotoxy(20,10);printf("ELIMINAR CODIGO            Nø[     ]");
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
gotoxy(20,24);printf("ESTE CODIGO NO SE ENCUENTRA");

getche();
}
}
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void main()
{
while(1) //mientras sea verdadero//
{
clrscr();
textbackground(1);
textcolor(22);
gotoxy(15,5);  cout<<"============================================";
textcolor(22);
gotoxy(22,6);  cout<<"TRABAJO DE ESTRUCTURA";
gotoxy(18,7);  cout<<"MILTON HABIB-COD:96131141-ING.DE SISTEMAS";
gotoxy(32,8);  cout<<"CURSO S3A";
textcolor(22);
gotoxy(15,9);   cout<<"============================================";
textcolor(22);
gotoxy(18,10);  cout<<" 1-CREAR LISTA CIRCULAR";
gotoxy(18,11);  cout<<" 2-IMPRIMIR";
gotoxy(18,12);  cout<<" 3-MODIFICAR";
gotoxy(18,13);  cout<<" 4-ELIMINAR";
gotoxy(18,14);  cout<<" 5-REGRESAR";
textcolor(5);
gotoxy(15,15);  cout<<"=============================================";
textcolor(10);
gotoxy(13,16);  cout<<"DIGITE LA OPCION Nø[ ]";
gotoxy(33,16); opc=getchar();
switch(opc)
{
case'1':crearlistacircular();break;
case'2':imprimir();break;
case'3':modificar();break;
case'4':eliminar();break;
case'5':return;
}
}
}
getch();





