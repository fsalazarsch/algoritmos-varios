#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream.h>

class lista_circular
{
 struct nodo
 {
  char codigo[10];
  char nombre[45];
  char apellido[45];
  struct nodo *enlace;
 };

struct nodo *ptr,*p,*nn;
public:
lista_circular(struct nodo *a){ptr=a;}; //constructor
void crear_lista();
void recorrer_lista();
void visualizar_lista();
};

void lista_circular::crear_lista()
{
 char codigo[10];
 char nombre[45];
 char apellido[45];
 char op;
 do
 {
  clrscr();
  textbackground(1);
  window(13,7,60,18);
  clrscr();
  textbackground(3);textcolor(14);
  gotoxy(2,2);printf("DIGITE CODIGO:");
  scanf("%s",codigo);
  gotoxy(2,4);printf("DIGITE NOMBRE:");
  scanf("\n");
  gets(nombre);
  gotoxy(2,6);printf("DIGITE APELLIDO:");
  gets(apellido);
  nn=new nodo;
  strcpy(nn->codigo,codigo);
  strcpy(nn->nombre,nombre);
  strcpy(nn->apellido,apellido);
  nn->enlace=NULL;
  if(ptr==NULL)
  {
   ptr=nn;
   ptr->enlace=ptr;
  }
  else
  {
   p=ptr;
   while(p->enlace!=ptr)
       p=p->enlace;
    p->enlace=nn;
    nn->enlace=ptr;   //lista circular
   }
  gotoxy(2,8);printf("DESEA CREAR OTRO NODO S/N: ");
  op=toupper(getche());
 }while(op!='N');
}

/***************************************************************************/

void lista_circular::visualizar_lista()
{
 clrscr();
 p=ptr;
 do
 {
  gotoxy(7,3);printf("CODIGO: %s\n",p->codigo);
  gotoxy(7,4);printf("NOMBRE: %s\n",p->nombre);
  gotoxy(7,5);  printf("APELLIDO: %s\n",p->apellido);
  p=p->enlace;
  getche();
 }while(p!=ptr);

}

main()
{
clrscr();
lista_circular obj(NULL);
obj.crear_lista();
obj.visualizar_lista();
}