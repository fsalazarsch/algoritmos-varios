#include<conio.h>
#include<alloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream.h>
#include<string.h>

#define nuevo (nodo*)malloc(sizeof(nodo))
typedef struct nodo nodo;
/**************************************************************************/
class lista{
 struct nodo{

	      char cdgo[10];

	      nodo *izq;
	      nodo *der;
	    };
  public:
	  void lista::fondo(int prin,int fin,int fl,int cl,int co);
	  void lista::marco(int prin,int fin,int fl,int cl,int co);
	  void lista::linea(int prin,int fl,int cl,int co);
	  void lista::captura_codigo();
	  void lista::eliminar();

	  void lista::visualizar();
	  void lista::menu();
  nodo *cab,*p,*q;
  int res,lon,sw1,pf;

};
/**************************************************************************/
void lista::fondo(int prin,int fin,int fl,int cl,int co)
{
 int i,tem;
 tem=fl;
 for(i=prin;i<=fin;i++)
  {
    textbackground(co); gotoxy(i,fl); cprintf(" ");
    if(i==fin)
     {
       i=prin-1;
       tem++;
       fl++;
     }
    if(tem==cl)
     {
       i=85;
     }
  }
}
/**************************************************************************/
void lista::marco(int prin,int fin,int fl,int cl,int co)
{
  int i;
  for(i=prin;i<=fin;i++)
  {
    textcolor(co);
    gotoxy(i,fl);cprintf("Ä");
    gotoxy(i,cl);cprintf("Ä");

  }
  for(i=fl;i<=cl;i++)
  {
    textcolor(co);
    gotoxy(prin,i);cprintf("³");
    gotoxy(fin,i);cprintf("³");
  }
    gotoxy(prin,fl);cprintf("Ú");
    gotoxy(fin,fl);cprintf("¿");
    gotoxy(prin,cl);cprintf("À");
    gotoxy(fin,cl);cprintf("Ù");
}
/*************************************************************************/
void lista::linea(int prin,int fl,int cl,int co)
{
 int i;
  for(i=fl;i<=cl;i++)
   {
     textcolor(co);
     gotoxy(prin,i);cprintf("³");
   }
  gotoxy(prin,cl);printf("Á");
  gotoxy(prin,fl);printf("Â");
}
/**************************************************************************/
numero(float dig,int pc,int pf)
{
  char continuar;
  int lon;
   do{
       continuar='n';
       gotoxy(pc,pf);clreol();scanf("%f",&dig);
	   if((dig<0)||(dig>5))
	    {
	      continuar='s';
	    }
   }while (continuar=='s');
  return(0);
}
/*************************************************************************/
dig(char dig[10],int c,int f)
{
  char continuar;
  int lon;
   do{
	continuar='n';
	gotoxy(c,f);clreol();scanf("\n");gets(dig);
	lon=strlen(dig);
	for(int i=0; i<=lon-1; i++)
	 {
	 if(!(isdigit(dig[i])))
	  {
	   continuar='s';
	  }
	 }
    }while (continuar=='s');
  return(0);
}
/*************************************************************************/
carac(char car[30],int c,int f)
{
  char continuar;
  int lon;
   do{
	continuar='n';
	gotoxy(c,f);clreol();scanf("\n");gets(car);
	lon=strlen(car);
	for(int i=0; i<=lon-1; i++)
	 {
	   if(car[i]==' ')
	    {
		i++;
	    }
	   if(!(isalpha(car[i])))
	    {
	      continuar='s';
	    }
	 }
    }while (continuar=='s');
  return(0);
}
/**********************************************************************/
void lista::captura_codigo()
{
  clrscr();
  char  codi[10],nomb[25];
  float n1,n2,n3,n4;
  int ban;
  nodo *c;
  ban=0;
  do
  {
  clrscr();
  fondo(1,80,1,25,7);
  fondo(26,51,3,5,3);
  marco(26,51,3,5,1);
  gotoxy(28,4);cprintf("CAPTURA  DE  CODIGOS  ");
  fondo(1,80,7,12,3);
  gotoxy(20,8);printf("DIGITE EL CODIGO   ");dig(codi,38,8);
  c=cab;
  if(c->der!=NULL)
   {
  while(c!=NULL)
   {
     if(strcmp(c->cdgo,codi)==0)
      {
	    gotoxy(20,12);printf(" ESTE CODIGO YA EXISTE ");getch();
	    ban=1;
      }
       c=c->der;
   }
  }
  if(ban==0)
  {

  if(sw1==1)
    {
       q=nuevo;
       strcpy(q->cdgo,codi);
       q->izq=p;
       q->der=NULL  ;
       p->der=q;
       p=p->der;
    }
  if(sw1==0)
   {
     p=nuevo;
     cab=p;
     strcpy(p->cdgo,codi);
     p->izq=NULL;
     p->der=NULL;
     sw1=1;
   }
  }
  ban=0;
  textcolor(4);
  gotoxy(1,24);cprintf(" Desea Continuar S/N  ");res=toupper(getch());
  }while(res=='S'||res=='s');
}
/*************************************************************************/
void lista::visualizar()
{
   nodo *p;
  int pf,i;
  clrscr();
  fondo(1,80,1,24,0);
  p=cab;
  i=0;
  pf=8;
  while(p->der!=NULL)
   {
    i++;
    p=p->der;
   }
  p=cab;
  if(i==0)
   {
     gotoxy(20,10);printf("NO EXISTEN CODIGOS PARA VISUALIZAR");
   }
  else
  {
  while(p!=NULL)
   {
     gotoxy(23,2);printf("LISTADO     DE     SUS CODIGOS");
     gotoxy(24,4);printf("CODIGO        ");
     marco(12,68,6,21,1);
     textcolor(4);
     gotoxy(24,pf);cprintf("%s",p->cdgo);
     pf++;
     p=p->der;
   }
  }
  getch();
}
/***********************************************************************/
void lista::eliminar()
{
  nodo *b,*d,*a,*c;
  int sw;
  char aux[10];
  clrscr();
  fondo(1,80,1,24,0);
  sw=0;
  fondo(1,80,3,6,3);textcolor(4);
  gotoxy(20,4);cprintf("DIGITE EL CODIGO A ELIMINAR  ");dig(aux,50,4);
  b=cab;
  while(b!=NULL)
   {
     d=b;
     a=d->izq;
     c=d->der;
     if(strcmp(d->cdgo,aux)==0)
      {
	sw=1;
	if(d->izq==NULL)
	 {
	   c->izq=NULL;
	   cab=c;
	 }
	else
	 {
	   a->der=c;
	 }
	c->izq=a;
	free(d);
	gotoxy(15,10);printf("EL CODIGO HA SIDO ELIMINADO");getch();
      }
    b=b->der;
    }
  if(sw==0)
   {
     gotoxy(20,10);printf("EL CODIGO A ELIMINAR NO EXISTE");getch();
   }
}

/**************************************************************************/
void lista::menu()
{
  int f,c,tecla,l;
  char opcion[21][75];
  sw1=0;
  f=8;
  c=15;

   strcpy(opcion[8],">> ADICIONAR CODIGOS<<");


  strcpy(opcion[12],">>ELIMINAR  CODIGOS <<");

  strcpy(opcion[16],">>    VISUALIZAR    <<");

  strcpy(opcion[20],">>      SALIR       <<");
  do{
     textcolor(1);textbackground(0);
     clrscr();
     fondo(1,80,1,25,7);
     fondo(29,46,4,5,3);
     marco(28,47,3,5,1);
	 textcolor(1);
     for(l=8;l<=20;l=l+4)
      {
	gotoxy(15,l);cprintf("%s",opcion[l]);
      }
     textcolor(1);textbackground(7);
     gotoxy(c,f);cprintf("%s",opcion[f]);
     textcolor(3);textbackground(0);
     do{
	 do{
	     tecla=getch();
	   }while((tecla==80)&&(tecla==72)&&(tecla==13));
	   if(tecla==80)
	    {
	      textcolor(1);textbackground(3);
	      gotoxy(c,f);cprintf("%s",opcion[f]);
	      if(f!=20)
	       {
		 f=f+4;
		 textcolor(4);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(3);textbackground(2);
	       }
	       else
	       {
		 f=8;
		 textcolor(4);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(3);textbackground(2);
		}
	    }
	    if(tecla==72)
	    {
	      textcolor(1);textbackground(3);
	      gotoxy(c,f);cprintf("%s",opcion[f]);
	      if(f!=8)
	       {
		 f=f-4;
		 textcolor(4);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(3);textbackground(2);
	       }
	       else
	       {
		 f=20;
		 textcolor(4);textbackground(7);
		 gotoxy(c,f);cprintf("%s",opcion[f]);
		 textcolor(3);textbackground(2);
		}
	    }
       }while(tecla!=13);
      switch(f)
       {
	case 8:captura_codigo();break;
	case 12:eliminar();break;
	case 16:visualizar();break;
	case 20:exit(1);break;
       }
   }while(f!=20);
}
/***********************************************************************/
void main()
{
 clrscr();
 lista materias;
 materias.menu();
}