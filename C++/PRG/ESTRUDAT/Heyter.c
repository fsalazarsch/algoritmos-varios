#include<stdio.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>


struct  lis
{
  long codigo;
  struct lis *sig;
};
struct lis  *nn,*ptr=NULL,*auxptr,*aux1,*aux2,*aux3;

  long auxcod,codigo;
  int i,con=0,j,lon,sw,st;

  void listado_general();
  void menu2();

void cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(1);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     textcolor(14);textbackground(1);
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

void agregar()
 {
  char op,suel[10],sex[2];
  char valido,ced[20];
   do
    {
     clrscr();
    cuadros(1,79,1,24);
  do
     {
      clrscr();
      cuadros(1,79,1,24);
      valido='n';
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(j=0;j<=lon-1; j++)
	{
	 if(!(isdigit(ced[j])))
	  {
	    valido='m';
	    break;
	  }
	}
    auxcod=atol(ced);
    aux2=ptr;

   while(aux2!=NULL)
     {
     if(aux2->codigo==auxcod)
       {
	gotoxy(15,10);
	printf("ESTE CODIGO YA EXISTE");
	valido='m';
	sw=2;
	getch();
       }
       aux2=aux2->sig;
     }
     if(sw==1)
     {
      valido='m';
     }
    }while(valido=='m');
   nn=malloc(sizeof (struct lis) );
   nn->codigo=auxcod;
   nn->sig=NULL;


   if(ptr==NULL)
   {
     ptr=nn;
     auxptr=ptr;
     con=1;
   }
   else
    {
    auxptr->sig=nn;
    auxptr=nn;
    con++;
    }

   gotoxy(25,12);printf("DESEA AGREGAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
 }while(op!='N');
}



void consultar()
 {
  char op,ced[20],valido;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("             ");
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	  {
	    valido='m';
	    break;
	  }
	}
     }while(valido=='m');
    auxcod=atol(ced);
    aux2=ptr;
    while(aux2!=NULL)
     {
     if(aux2->codigo==auxcod)
       {
	gotoxy(25,12);printf("LA CODIGO DEL USUARIO ES  :%ld",aux2->codigo);
	sw=2;
       }
       aux2=aux2->sig;
     }
    if(sw==1)
     {
      gotoxy(20,12);printf("< NO EXISTE ESTE CODIGO  >");
     }
    gotoxy(25,20);printf("DESEA CONSULTAR OTRO REGISTRO (S/N):");
    op=toupper(getch());
  }while(op!='N');
}



void ordenar_codigo()
  {
  for(i=con-1;i>=1;i--)
     {
      aux2=ptr;
      aux3=aux2->sig;
      for(j=1;j<=i;j++)
      {
       aux2=aux2;
       aux3=aux3;
	if(aux2->codigo>aux3->codigo)
	 {
	  codigo=aux2->codigo;

	  aux2->codigo=aux3->codigo;

	  aux3->codigo=codigo;

	}
	aux2=aux2->sig;
	aux3=aux2->sig;
       } 
     }
   listado_general();
 }


void modificar()
 {
  char ced[20],op,op1,valido;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(34,4);
      printf("             ");
      gotoxy(20,4);printf("DIGITE CODIGO:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	   {
	     valido='m';
	     break;
	   }
	}
     }while(valido=='m');
     auxcod=atol(ced);
    aux2=ptr;
    while(aux2!=NULL)
    {
    if(aux2->codigo==auxcod)
      {
   do
      {
       valido='n';
       gotoxy(39,11);
       printf("             ");
       gotoxy(25,11);printf("DIGITE CODIGO:");
       scanf("\n"); gets(ced);
       lon = strlen(ced);
       for(j=0;j<=lon-1; j++)
	{
	 if(!(isdigit(ced[j])))
	  {
	    valido='m';
	     break;
	   }
	}
       }while(valido=='m');
      sw=2;
     }
     aux2=aux2->sig;
   }
   if (sw==1)
    {
    gotoxy(20,13);printf("< NO EXISTE ESTE CODIGO >");
    getch();
    }
   gotoxy(25,20);printf("DESEA MODIFICAR OTRO REGISTRO (S/N):");
   op=toupper(getch());
  }while(op!='N');
}


void eliminar()
 {
  int k;
  char ced[20],valido,op;
  long aux;
  do
   {
    clrscr();
    cuadros(1,79,1,24);
    sw=1;
    do
     {
      valido='n';
      gotoxy(39,5);
      printf("               ");
      gotoxy(25,5);printf("DIGITE CODIGO:");
      scanf("\n"); gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	   {
	     valido='m';
	     break;
	   }
	 }
      }while(valido=='m');
      auxcod=atol(ced);
      if(ptr==NULL)
      {
      clrscr();
      printf("NO EXISTE INFORMACION EN LA LISTA..!");
      getch();
      }
      aux2=ptr;
      aux3=ptr->sig;
       if(ptr->codigo==auxcod)
	 {
	  sw=2;
	  ptr=aux3;                                      
	  free(aux2);
	  clrscr();
	  printf("EMPLEADO ELIMINADO...");
	  con--;
	  getch();
	 }
	else
	  {
	  while(aux3!=NULL)
	  {
	  if(auxcod==aux3->codigo)
	      {
	      sw=2;
	      aux1=ptr;
	      while(aux1!=NULL)
	      {
	       if(aux1->sig==aux3)
		 {
		   if(aux1->sig==auxptr)
		    {
		    auxptr=aux1;
		    }
		   aux1->sig=aux3->sig;
		   free(aux3);
		   clrscr();
		   printf("EMPLEADO ELIMINADO...\n");
		   con--;
		 }
		aux1=aux1->sig;
	      }
	     }
	     aux3=aux3->sig;
	     }
	     }

      if(sw==1)
       {
	gotoxy(20,13); printf("< ESTE CODIGO NO EXISTE >");
	getch();
       }
      gotoxy(25,20);printf("DESEA ELIMINAR OTRO REGISTRO (S/N):");
      op=toupper(getch());
     }while(op!='N');
   }

void listado_general()
{
  int c;

      c=4; sw=1;
    if(ptr==NULL)
    {
    clrscr();
    printf("NO EXISTE INFORMACION EN LA LISTA..!");
   }
   else
    {
    clrscr();
    gotoxy(2,2);
    aux2=ptr;
    printf("           CODIGO       ");
    while(aux2!=NULL)
    {
     gotoxy(15,c);printf("%ld",aux2->codigo);
     c++;
     aux2=aux2->sig;
     }
   }
   getch();
}


void menu()
{
 int tecla;
  int f;
  char opciones[35][75];
  textcolor(10);textbackground(1);

  do{ 
  clrscr();                                        
  strcpy(opciones[10], " ADICCIONAR DATOS  ");
  strcpy(opciones[11], " CONSULTAR  DATOS  ");
  strcpy(opciones[12], " IMPRIMIR INFORME  ");
  strcpy(opciones[13], " MODIFICAR DATOS   ");
  strcpy(opciones[14], " ELIMINAR DATOS    ");
  strcpy(opciones[15], " ORDENAR  DATOS    ");
  strcpy(opciones[16], " TERMINAR O SALIR  ");

  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");								
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	textcolor(10);textbackground(1);
	for(f=10;f<=16;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=16)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=16;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   10:agregar() ;break;
		      case   11:consultar() ;break;
		      case   12:listado_general() ;break;
		      case   13:modificar() ;break;
		      case   14:eliminar() ;break;
		      case   15:ordenar_codigo() ;break;
		     }
	   }while(f !=16);
  }

void main()
{
clrscr();
menu();
}