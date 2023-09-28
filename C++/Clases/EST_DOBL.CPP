# include <iostream.h>
# include <conio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
void agregar();
void mostrar();
void mostrar_1();

struct  nodo {
 int info;
 nodo *sig;
 nodo *ant;
 };

struct nodo *cab,*q,*p;

main()
{
clrscr();
cab=new struct nodo;
if (cab==NULL)
 {cout<<"no hay memoria disponible";getch();exit(0);}
cout<<"digite informacion : ";
cin>>cab->info;
cab->sig= NULL;
cab->ant=NULL;
agregar();
mostrar();
mostrar_1();
return(0);
}

void agregar()
{
char op;
do{
cout<<"desea continuar -S/N- "<<endl;op=toupper(getch());
}while((op != 'S')&&(op != 'N'));
while(op=='S')
{
clrscr();
p=new struct nodo;
if (p==NULL)
 {cout<<"no hay memoria disponible";getch();exit(0);}
cout<<"digite informacion : ";
cin>>p->info;
q=cab;
while (q->sig != NULL)
{ q=q->sig;}
q->sig=p;
p->ant=q;
p->sig=NULL;
do{
cout<<"desea continuar -S/N- "<<endl;op=toupper(getch());
}while((op != 'S')&&(op != 'N'));
}
}
void mostrar()
{
int i;
q=cab;
clrscr();
i=4;
cout<<"los datos leidos son :"<<endl;
while (q != NULL)
{gotoxy(20,i);cout<<q->info<<endl;
 q=q->sig;i=i+2;getch();}
}

void mostrar_1()
{
int i;
q=cab;
i=4;
while (q->sig != NULL)
{
 q=q->sig;}
 while (q != NULL)
{gotoxy(40,i);cout<<q->info<<endl;
 q=q->ant;i=i+2;getch();}
}


