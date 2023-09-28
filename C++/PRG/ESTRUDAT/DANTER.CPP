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
void marco();
void menu();

main()
{
textmode (2);
textcolor(1);
textbackground(3);
menu();
getche();
}

/*****************************************************************/
void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);} 
  }
/******************************************************************/
void menu()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(128);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  gotoxy(15,25);textcolor(9);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(9);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("MENU PRINCIPAL");

  textbackground(9);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,2);
  cprintf("1.ADICIONAR NODOS");
  gotoxy(4,3);
  cprintf("2.VISUALIZAR NODOS");
  gotoxy(4,4);
  cprintf("3.ELIMINAR NODOS");
  gotoxy(4,5);
  cprintf("4.BUSCAR NODOS");
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

/*********************************************************/
void adicionar()
{
 char sw;
 char x[6];
 char car;
 int i=-1;
 do
 {
 window(1,1,80,25);
 textbackground(0);
 clrscr();
 window(1,1,80,25);
 clrscr();
 i=0;
 car='';

  textbackground(9);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("  ADICIONAR");

  textbackground(9);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);

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
	gotoxy(46,1);
	clreol();
      }
    }
 }
 x[i]='\0';
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

  textbackground(9);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf(" VISUALIZAR");

  textbackground(9);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);

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
if (ptr==NULL)

   {gotoxy(20,20);printf("<<< NO EXISTE LISTA >>>");}
else
{
    q=ptr;
    ptr=ptr->enlace;
    free(q);
}
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

  textbackground(9);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("   BUSCAR");

  textbackground(9);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);

  q=ptr;
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
      gotoxy(5,7);printf(" ENTER PARA REGRESAR ");
  getche();
}



 

