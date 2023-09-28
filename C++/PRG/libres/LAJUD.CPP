#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
void lis(void);
void crea(void);
void inser(void);
void elimi();
void hechopor();
void cuadro(int x1, int y1, int x2, int y2);
#define memoria (nodo *)malloc(sizeof(nodo))
typedef struct lista nodo;
  struct lista
   { int info;
     nodo *sig,*ant;
   };
   char rr='S';
   int dat,sw,opc,op1,op2,aux,o4,con;
   nodo *cab,*p,*q,*r;
void main ()
{/*cuerpo programa*/
 hechopor();
 cab=NULL;
 do
 {clrscr();
 printf("\n");
 printf("1: CREAR    \n");
 printf("2: INSERTAR  \n");
 printf("3: ELIMINA   \n");
 printf("4:  SALIR    \n");
 printf("seleccione opcion ");
 scanf("%d",&opc);
  switch(opc)
   {
   case 1:
    {crea();
     break;}
   case 2:
    {inser();
     break;}
   case 3:
    { elimi();
     break;}
   }
  }
 while (opc!=4);
 }
 /*final programa*/
void inser(void)
{
 do
  {clrscr();
    printf("1: DESPUES ");
    printf("2: ANTES  ");
    printf("3: COMIENZO ");
    printf("4:  FINAL  ");
    printf("5: SALIR  \n");
    printf("Digite opcion\t");
    scanf("%d",&op1);
     switch(op1)
     {
      case 1:{  if (cab==NULL)
		{printf("No existe lista creada presione <enter> ");
		 rr=getch();}
		 else
		 {
	   do
	    {
	     clrscr();
	     lis();
	     printf("\n\ndespues de cual elemento\t");
	     scanf("%d",&dat);
	     /*busqueda*/
	     r=cab;
	     sw=0;
	      while ((sw==0) && (r!=NULL))
		{ if (dat==r->info)
		   sw=1;
		  else
		   r=r->sig;
		}
		 if (sw==0)
		    printf("no existe el elemento !!!");
		  else
		   {
		   if ((r==cab) && (r->sig==NULL))
		    { printf("\nimposible insertar otro elemento ");
		      rr='N';
		     }
		     else
		      {
			if (r->sig==NULL)
			printf("\nno existe un elemento despues para poder insertar el nuevo nodo\n");
		       else
			{
			 p=memoria;
			 printf("\n\ndigite el elemento a insertar\t");
			 scanf("%d",&dat);
			 q=r->sig;
			 r->sig=p;
			 q->ant=p;
			 p->sig=q;
			 p->ant=r;
			 p->info=dat;
			 lis();
			}
		      }
		    }
		       printf("\ndesea insertar otro elemento despues s/n\t");
		       scanf("%s",&rr);
		  }
		 while ((rr=='S') || (rr=='s'));
		}
		break;
	       }
	       case 2:
		    {  if (cab==NULL)
			{printf("No existe lista creada presione <enter> ");
			 rr=getch();}
			 else
		       {
do
{ lis();
  printf("\n\nantes de cual elemento a insertar\t");
  scanf("%d",&dat);
    r=cab;
    sw=0;
     while ((sw==0) && (r != NULL))
      { if (dat==r->info)
	 sw=1;
	else
	 r=r->sig;
       }
	if (sw==0)
	 printf("no existe el elemento !!!");
	  else
	   {
	   if (r==cab)
	     printf("no existe un elemento antes para poder insertar el nuevo nodo\n");
	       else
		  {
		    p=memoria;
                    printf("\n\ndigite el elemento a insertar\t");
		    scanf("%d",&dat);
		    q=r->ant;
		    q->sig=p;
		    r->ant=p;
		    p->sig=r;
		    p->ant=q;
		    p->info=dat;
		    lis();
		 }
	      }
     printf("\ndesea seguir insertando otro elemento antes s/n\t");
     scanf("%s",&rr);
  }
  while ((rr=='S') || (rr=='s'));
   }
   break;
   }
case 3:
{int dat,sw;
 do
 {  /*insertar al comienzo*/
    clrscr();
    p=memoria;
    printf("digite un numero\t");
    scanf("%d",&dat);
     if (cab==NULL)
      { p->sig=NULL;
	p->ant=NULL;
	p->info=dat;
	cab=p;
       }
       else
	{
	     p->info=dat;
	     p->ant=NULL;
	     p->sig=cab;
	     cab->ant=p;
	     cab=p;
	 }
     clrscr();
     printf("\nla lista de elemento es\n\n");
     q=cab;
     while (q!=NULL)
      { printf("%d\t",q->info);
	q=q->sig;
       }
     printf("\ndesea seguir adicionando otro nodo s/n\t");
     scanf("%s",&rr);
     }
     while ((rr=='S') || (rr=='s'));
     break;
     }
 case 4:
  { /*inserta al final*/
    crea();}
     }
  }
  while (op1!=5);
 }
void lis(void)
 {
   clrscr();
     printf("\nla lista de elemento es\n\n");
     q=cab;
     while (q!=NULL)
      { printf("%d\t",q->info);
	q=q->sig;
       }
 }
 void crea(void)
  {
  do
   {clrscr();
    p=memoria;
    printf("digite un numero\t");
    scanf("%d",&dat);
     if (cab==NULL)
      { p->sig=NULL;
	p->ant=NULL;
	p->info=dat;
	cab=p;
       }
       else
	{
	 q=cab;
	  while (q->sig != NULL)
	   q=q->sig;
	     p->info=dat;
	     q->sig=p;
	     p->ant=q;
	     p->sig=NULL;
	 }
     lis();
     printf("\ndesea seguir adicionando otro nodo s/n\t");
     scanf("%s",&rr);
     }
     while ((rr=='S') || (rr=='s'));
   }
void elimi()
{ int dat,sw;
  char rr;
  clrscr();
  if (cab==NULL)
    { printf("\nno existen elementos en la lista !!!! presione <ENTER>");
      rr=getch();
     }
    else
    {
 do
 {  clrscr();
    printf("1: INFORMACION X ");
    printf("2: DESPUES   ");
    printf("3: ANTES   ");
    printf("4: SALIR  \n");
    printf("Digite opcion\t");
    scanf("%d",&op2);
    switch(op2)
     {
     case 1:{/*informacion X*/
    do
    {clrscr();
    lis();
  printf("\n\ndigite el elemento a eliminar\t");
  scanf("%d",&dat);
    r=cab;
    sw=0;
     while ((sw==0) && (r != NULL))
      { if (dat==r->info)
	 sw=1;
	else
	 r=r->sig;
       }
	if (sw==0)
	 printf("no existe el elemento !!!");
	  else
	   {
	     if ((r==cab) && (r->sig==NULL))
	       cab=NULL;
	      else
	       { if (r==cab)
		  { p=r->sig;
		   p->ant=NULL;
		   free(cab);
		   cab=p;
		   }
		    else
		     { if (r->sig==NULL)
			{ p=r->ant;
			  p->sig=NULL;
			  free(r);
			 }
			  else
			   { q=r->ant;
			     p=r->sig;
			     q->sig=p;
			     p->ant=q;
			     free(r);
			    }
		       }
		   }
	      }
    if (cab!=NULL)
     {
      printf("\nla lista de elemento es\n\n");
      q=cab;
       while (q!=NULL)
	{ printf("%d\t",q->info);
	  q=q->sig;
	}
       printf("\ndesea seguir eliminando otro elemento s/n\t");
	scanf("%s",&rr);
       }
	else
	{ printf("\nno existen elementos en la lista !!!! presione <ENTER>");
	  rr=getch();
	  rr='N';
	 }
    }
    while ((rr=='S') || (rr=='s'));
    break;
  }
case 2:
{
do
{
  clrscr();
  lis();
  printf("\n\ndigite el elemento a eliminar\t");
  scanf("%d",&dat);
    r=cab;
    sw=0;
     while ((sw==0) && (r != NULL))
      { if (dat==r->info)
	 sw=1;
	else
	 r=r->sig;
       }
	if (sw==0)
	 printf("no existe el elemento !!!");
	  else
	   {
	   if (r->sig==NULL)
	     printf("no existe un elemento despues a eliminar\n");
	       else
		{
		 p=r->sig;
		 if (p->sig==NULL)
		  { r->sig=NULL;
		     }
		   else
		   {
		    q=p->sig;
		    r->sig=q;
		    q->ant=r;
		    }
		    free(p);
		 }
	      }
      printf("\nla lista de elemento es\n\n");
      q=cab;
       while (q!=NULL)
	{ printf("%d\t",q->info);
	  q=q->sig;
	}
     printf("\ndesea seguir eliminando otro elemento s/n\t");
     scanf("%s",&rr);
  }
  while ((rr=='S') || (rr=='s'));
  break;
 }
 case 3:
  {
  /********************/
do
{
  clrscr();
  lis();
   printf("\ndigite un numero\t");
   scanf("%d",&dat);
   if (cab==NULL)
    { printf("no existen elementos en la lista !!! presione <ENTER>");
     rr=getch();}
   else
   { r=cab;
     sw=0;
     while ((sw==0) && (r != NULL))
      {
	if (dat==r->info)
	 sw=1;
	else
	 r=r->sig;
       }
	if (sw==0)
	 { printf("elemento inexistente presione <ENTER>\n");
	  rr=getch();}
	 else
	  {
	   if (r==cab)
	    { printf("no existe un elemento antes a eliminar presione <ENTER>\n");
	      rr=getch();}
	      else
	      { q=r->ant;
	       if (q==cab)
		{ q->sig=NULL;
		  r->ant=NULL;
		  free(q);
		  cab=r;
		 }
		 else
		  { p=q->ant;
		    p->sig=r;
		    r->ant=p;
		    free(q);
		    }
		 }
	      }
	   }
     /*******************/
       lis();
       if (cab!=NULL)
       {
       printf("\ndesea seguir eliminando otro elemento s/n\t");
	scanf("%s",&rr);
	}
	else
	{ printf("\nno existen elementos en la lista !!!! presione <ENTER>");
	  rr='N';
	 }
 }
  while ((rr=='S') || (rr=='s'));
  break;
  }
 }
 }
   while (op2!=4);
  }
 }
 /**************************************/
void hechopor()
{
  textmode(C80);
  clrscr();
  textcolor(3);
  cuadro(1,1,79,25);
  cuadro(17,9,64,21);
  gotoxy(50,3);  cprintf("6  de OCT de 1998");
  gotoxy(26,10); cprintf(" Estructura de Datos ");
  gotoxy(19,11); cprintf("Presentado Por: NILSON LAJUD IRIARTE");

  textcolor(3+BLINK);
  gotoxy(27,24); cprintf("Oprima Una Tecla Para Continuar");
  textcolor(3);
  getch();
 }

void cuadro(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ß");
    gotoxy(i,y2); cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("Û");
    gotoxy(x2,i); cprintf("Û");
  }
}





