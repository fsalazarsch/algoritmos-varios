#include <stdio.h>
#include <conio.h>
#include <process.h>   
#include <stdlib.h>
#include <ctype.h>
struct nodo
{
 char x[6];
 struct nodo *enlace;
}tnodo;
struct nodo *ptr=NULL,*p,*nn,*q;
void adicionar();
void visualizar();
void eliminar();
void buscar();
void menu();
void main()
{
textmode (2);
textcolor(1);
textbackground(3);
menu();
}


/*********************************************************/
void adicionar()
{
 char sw;
 char x[6];
 char car;
 int w=0,i=-1;
 do
 {
 window(1,1,80,25);
 textbackground(0);
 clrscr();           
 window(1,1,80,25);
 clrscr();
 i=0;
 car='';

  textbackground(11);
  window(33,6,48,8);clrscr();
  gotoxy(2,2);textcolor(0);
  cprintf("  ADICIONAR");

  textbackground(11);
  window(25,11,57,18);clrscr();
  textcolor(0);

 gotoxy(3,2);
 printf("DIGITE UN NUMERO POSITIVO: ");
 while(car!='\r'&&i<6)
 { 
   car=getche();
   if (isdigit(car))
   {
      x[i]=car; 
      i++;
    }
    else
    {
      if (car!='\r')
      {
	gotoxy(30,2);
	clreol();printf("   Г");gotoxy(30,2);
      }
    }
 }
 x[i]='\0';
q=ptr;
while(q!=NULL)
{if (!strcmp(q->x,x))
 w=1;
q=q->enlace;
}
if(w==0)
{
nn=malloc(sizeof(tnodo));
strcpy(nn->x,x);
nn->enlace=NULL;
if(ptr==NULL)
{
 ptr=nn;
 p=nn;
}
else
{
p->enlace=nn;
p=nn;
}
}
 else
 {gotoxy(3,4);printf("EL NUMERO YA EXISTE");}
 gotoxy(3,6);printf("DESEA CREAR OTRO NODO S/N ");
 sw=toupper(getche());
 }while(sw!='N');
	}

/************************************************************/
void visualizar()
{
int x,c;

  window(1,1,80,25);
  textbackground(0);
  clrscr();

  textbackground(11);
  window(33,6,48,8);clrscr();
  gotoxy(2,2);textcolor(0);
  cprintf(" VISUALIZAR");

  textbackground(11);
  window(25,11,57,18);clrscr();
  textcolor(0);

c=2;
if(ptr==NULL)

{gotoxy(5,5);printf("<<< NO EXISTE LISTA >>>");}
else
{
    q=ptr;
    while(q!=NULL)
    {
       gotoxy(5,c);printf("%s",q->x);
       c++;
       q=q->enlace;
}

}
getche();
} 


/*************************************************************/
void eliminar()
{
  window(1,1,80,25);
  textbackground(0);
  clrscr();
  
  textbackground(11);
  window(33,6,48,8);clrscr();
  gotoxy(2,2);textcolor(0);
  cprintf("   ELIMINAR");

  textbackground(11);
  window(25,11,57,18);clrscr();
  textcolor(0);

if (ptr==NULL)

   {gotoxy(5,5);printf("<<< NO EXISTE LISTA >>>");}
else
{
    q=ptr;
    ptr=ptr->enlace;
    free(q);
    gotoxy(8,5);printf("NUMERO ELIMINADO");
}
getche();
}
/******************************************************************/
void menu()
{ char op,tecla,SALIR;
  int u,i;
 do
 { window(1,1,80,25);
   textbackground(128);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  for(i=1;i<=25;i++)
    {  textcolor(15);
      gotoxy(1,i);
      cprintf("лллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
      } 
  gotoxy(15,25);textcolor(15);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  window(1,1,80,25);
  textbackground(0);
  window(35,7,53,9);clrscr();
  textbackground(11);
  window(34,6,51,8);clrscr();
  gotoxy(2,2);textcolor(0);
  cprintf("MENU PRINCIPAL");
  textbackground(0);
  window(26,12,59,19);clrscr();
  textcolor(0);
  textbackground(11);
  window(25,11,57,18);clrscr();
  textcolor(0);
  gotoxy(4,2);
  cprintf("1.ADICIONAR LISTA");
  gotoxy(4,3);
  cprintf("2.VISUALIZAR LISTA");
  gotoxy(4,4);
  cprintf("3.ELIMINAR LISTA");
  gotoxy(4,5);
  cprintf("4.BUSCAR LISTA");
  gotoxy(4,6);
  cprintf("5.SALIR");

  textcolor(15);
  gotoxy(3,2);cprintf("");gotoxy(3,2);

 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(3,wherey()+4);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==6)
	  {
	     gotoxy(3,wherey()-4);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==6)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:adicionar();break;
       case 3:visualizar();break;
       case 4:eliminar();break;
       case 5:buscar();break;
      }

  }
    } while(SALIR!='S');
}
/***********************************************************/
void buscar()
{
char car,x[6];
int i=0,sw=0;
sw=0;
  window(1,1,80,25);
  textbackground(0);
  clrscr();

  textbackground(11);
  window(33,6,48,8);clrscr();
  gotoxy(2,2);textcolor(0);
  cprintf("   BUSCAR");

  textbackground(11);
  window(25,11,57,18);clrscr();
  textcolor(0);

  if(ptr==NULL)
  {gotoxy(5,5);printf("<<< NO EXISTE LISTA >>>");}

  else
  {q=ptr;
  gotoxy(3,2);printf("DIGITE EL NUMERO A BUSCAR: ");

  while(car!='\r'&&i<6)
 { 
   car=getche();
   if (isdigit(car))
   {
      x[i]=car; 
      i++;
    }
    else
    {
      if (car!='\r')
      {
	gotoxy(46,1);
	clreol();
      }
    }
}
 x[i]='\0';
   while (q!=NULL)
    {
	if (strcmp(q->x,x)==0)
	  {
	  gotoxy(5,5);printf(" EL NUMERO ES: %s",&x );
	  sw=1;
	  }
	  q=q->enlace;

    }
    if (sw==0)
    { gotoxy(5,5);printf(" EL NUMERO NO EXISTE "); }
      gotoxy(5,7);printf(" ENTER PARA REGRESAR ");  }
  getche();
}