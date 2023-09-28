#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<alloc.h>
#define memoria (struct nan *) malloc(sizeof(struct nan))
//*******************************************
  struct nan{
  char cod[10];
  char nom[40];
 long int valor;
  struct nan *ant;
  struct nan *sig;

 }hernanacuna;
 struct nan *nn,*p,*ptr;
/****************************/
  char cod[10],op;
  char nom[40];
  int sw;
  long int valor;
  void marcar();
  void marco();
  void cuadros();
  void adicionar();
  void visualizar();
  void menu();
  void eliminar();
  void consultar_cod();
  void consultar_rech();
  void consultar();
  char valido;
  void insertar();
  int lon;
  int entero(int x,int y);
  int largo(int x,int y);


///////////////////////////////////////////////////////////////////
void marcar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {
	  case 1: fondo=176; break;

	  case 2: fondo= 177;break;

	  case 3: fondo= 178;break;

	  case 4: fondo= 32;break;

	    default:
			fondo= 32;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }

/////////////////////////////////////////////////////////////////////////////
void  marco(int ci,int cf,int fi,int ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Í");
  delay(4); gotoxy(i,ff); printf("Í");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("º");
  delay(4); gotoxy(cf,i); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(0);
 }
/////////////////////////////////////////////////////////////////
void cuadros(int x1, int y1, int x2, int y2)
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


///////////////////////////////////////////
int entero(int x,int y)
{ char *cad;
  int n,sw,j;


do
  {

    gotoxy(x,y);sw=0;
textcolor(14);textbackground(0);
	 textcolor(14);textbackground(0);
	 clreol();
	 scanf("\n");gets(cad);
	 n=strlen(cad);
	 for(j=0;j<n;j++)
	 if(!isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
  return(atoi(cad));
}
//////////////////////////////////////////////
 int largo(int x,int y)
{ char *cad;
  int n,sw,j;


do
  { gotoxy(x,y);sw=0;

/*(35,11);*/textcolor(14);textbackground(0);
    textcolor(14);textbackground(0);
   clreol();
   scanf("\n");gets(cad);
   n=strlen(cad);
   for(j=0;j<n;j++)
    if(!isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
   return(atol(cad));
}




//////////////////////////////////////////////////////////////////
void menu()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR     ");
 strcpy(opciones[12],"INSERTAR      ");
 strcpy(opciones[13],"ELIMINAR      ");
 strcpy(opciones[14],"VISUALIZAR    ");
 strcpy(opciones[15],"SALIR         ");

do
 {

 clrscr();

 textbackground(3);
 gotoxy(9,8);textcolor(128+14);
 delay(14);gotoxy(9,8);cprintf("Û ");
 textbackground(5);
 gotoxy(11,8);textcolor(128+4);
 delay(14);gotoxy(11,8);cprintf("Û ");
 textbackground(4);
 gotoxy(13,8);textcolor(15+BLINK);
 delay(14);gotoxy(13,8);cprintf("Û ");
 gotoxy(19,9);cprintf("MENU PRINCIPAL ");
 textbackground(15);
 gotoxy(13,17);textcolor(128+12);
 delay(14);gotoxy(13,17);cprintf("Û ");
 textbackground(5);
 gotoxy(11,17);textcolor(128+2);
 delay(14);gotoxy(11,17);cprintf("Û ");
 textbackground(7);
 gotoxy(9,17);textcolor(128+5);
 delay(14);gotoxy(9,17);cprintf("Û ");
 textbackground(7);
 gotoxy(8,18);textcolor(128+7);
 delay(14);gotoxy(8,18);cprintf("Û ");
 textbackground(3);
 gotoxy(7,19);textcolor(128+9);
 textbackground(3);
 gotoxy(6,20);textcolor(128+14);
 textbackground(5);
  textcolor(14);
 textcolor(7); textbackground(0);
 cuadros(39,5,62,14);
 marco(39,62,5,14);
 textcolor(14);
     delay(14);gotoxy(40,6);cprintf ("   ÜÜÜÜÜÜÜÜÜÜÜÜÛÛ   ");
     delay(14);gotoxy(40,7);cprintf ("   Û H E R N A NÛ   ");
     delay(14);gotoxy(40,8);cprintf ("   ÛÛ A C U ¥ AÛÛ   ");
     delay(14);gotoxy(40,9);cprintf ("   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛ ");
     delay(14);gotoxy(40,10);cprintf("   ÛÛR O M E R OÛ   ");
     delay(14);gotoxy(40,11);cprintf("   ÛÛÛÛÛÛÛÛÛÛÛÛÛÛ   ");
     delay(14);gotoxy(40,12);cprintf("   ÛÛÛÛÛÛÛÜÜÜÜÜÜÛ   ");
     delay(14);gotoxy(40,13);cprintf("                    ");


 textcolor(14); textbackground(0);
 cuadros(18,10,35,16);
 marco(18,35,10,16);
 textcolor(14); textbackground(0);
 cuadros(2,2,78,24);
 marco(2,78,2,24);
 textcolor(14); textbackground(0);
 for(f=11; f<=15;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(1); textbackground(0);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(0);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(3);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=11;

    textcolor(14);textbackground(0);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=15;
    textcolor(14);textbackground(3);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(3);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11: adicionar();break;
 case 12: insertar();break;
 case 13: eliminar(); break;
 case 14: visualizar(); break;
 case 15: default:printf("FINAL");
 }

}
 while(f!=15);
}

////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
void adicionar()
{ char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
  int i,j,sw,st;
  char valido;
  int n;


do{

do
{ clrscr();
   textcolor(14);textbackground(3);
   cuadros(2,2,80,24);
   textcolor(4);textbackground(3);
   cuadros(18,7,70,13);
  // textcolor(6+128); textcolor(6+128);

	 nn=memoria;
	 valido='n';
	 gotoxy(20,8);printf("DIGITE EL CODIGO     :");gets(cod);
	 n = strlen(cod);
	 for(j=0;j<=n-1;j++)
	{
	 if(n>4)
	  {   textcolor(4);textbackground(3);
	      cuadros(19,16,40,18);
	      gotoxy(20,17);
	      printf("FUERA DE RANGO");
	      valido='m';
	      getch();
	      break;
	  }

	 else
	  {
	   if((!(isdigit(cod[j])))&&(!(isalpha(cod[j]))))
	    { textcolor(8);textbackground(3);
	      cuadros(14,16,50,18);
	      gotoxy(15,17);
	     textcolor(1);printf("LO SIENTO VIEJO ACCESO DENEGADO ");
	     valido='m';
	     getch();
	     break;
	    }
	   else
	    {
	     p=ptr;

	     while(p!=NULL)
	     {
	      if(strcmp(p->cod,cod)==0)
	       { textcolor(5);textbackground(15);
		cuadros(19,16,40,18);
		gotoxy(20,17);
		printf(" CODIGO EXISTENTE");
		valido='m';
		getch();
		break;
	       }
	      p=p->sig;
	     }
	    }
	   }
	 }
    }while(valido=='m');

   strcpy(nn->cod,cod);

  do
      {
	valido='n';
	gotoxy(42,9);
	printf("             ");
	gotoxy(20,9);printf("DIGITE EL NOMBRE     :" );
	gotoxy(42,9);gets(nom);
	n=strlen(nom);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nom[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);printf("PULSE SOLO LETRAS");
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     printf("                                 ");
	     break;
	    }
	  }
       }while(valido=='m');


  strcpy(nn->nom,nom);
  nn->valor=valor;
  nn->sig=nn->ant=NULL;

  if(ptr==NULL)
   ptr=nn;
   else

  {p=ptr;
   while(p->sig!=NULL)
   p=p->sig;
   p->sig=nn;
   nn->ant=p;
  }
  gotoxy(29,20);printf("..EXITOS VIEJO ");


  gotoxy(18,22);printf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');

}
////////////////////////////////////////////////////////////////////
void visualizar()
{
int fill=6;

clrscr();
   textcolor(4);textbackground(14);
   cuadros(2,2,80,24);

 if(ptr==NULL)
	{gotoxy(25,8); printf("LISTA SIN PROCESAR   ");
	  }
  else{
    gotoxy(3,7);printf("CODIGO       NOMBRE                     ");
    textcolor(8);textbackground(15);
    delay(14);gotoxy(15,3);cprintf("  Ü     Ü  ÜÜÜ  ÜÜÜ  ÜÜÜ  ÜÜÜÜ  ÜÜÜ  ÜÜÜ           ");
    delay(14);gotoxy(15,4);cprintf("  Û     Û  ÛÜÜ   Û   ÛÜÛ  Û  Û  Û Û  ÛÜÜ           ");
    delay(14);gotoxy(15,5);cprintf("  ÛÜÜ   Û  ÜÜÛ   Û   Û Û  ÛÜÜÛ  ÛÜÛ  ÜÜÛ           ");

     textcolor(4);textbackground(15);
     cuadros(2,2,80,6);
  p=ptr;
	 textcolor(1);
	  while(p!=NULL)
      {
       gotoxy(3,2+fill);cprintf("%d",p->cod);
       gotoxy(16,2+fill);cprintf("%s",p->nom);
	fill++;
	p=p->sig;

       }
     }
gotoxy(20,22);printf("PULSE            PARA REGRESAR");clreol();
textcolor(4+BLINK);
gotoxy(26,22);cprintf("<<ENTER>>");
getche();
}


///////////////////////////////////////////////////////////////
void eliminar()
{ char cod[10];
  char nom[40];
  char op,sw1=0;


 clrscr();
    textcolor(4);textbackground(15);
   cuadros(2,2,80,24);
    textcolor(14);textbackground(3);
    delay(14);gotoxy(15,3);cprintf("  ÜÜÜ   Ü     Ü   ÜÜÜÜÜÜÜ   Ü   ÜÜÜÜÜ   ÜÜÜÜ   ÜÜÜÜ        ");
    delay(14);gotoxy(15,4);cprintf("  ÛÜ    Û     Û   Û  Û  Û   Û   Û   Û   ÛÜÜÛ   ÛÜÜÛ        ");
    delay(14);gotoxy(15,5);cprintf("  ÛÜÜ   ÛÜÜ   Û   Û     Û   Û   Û   Û   Û  Û   Û Û         ");

  do{
  cuadros(17,14,60,16);
   gotoxy(18,15); printf(" DESEA ELIMINAR EL PRIMER ARTICULO [S/N]");
  op=toupper(getche());
  }while((op!='N')&&(op!='S'));
 if(op=='S')
  { sw1=1;

  if(ptr==NULL)
   {gotoxy(20,6);printf(" LISTA VACIA:" );

     }
   else
     { p=ptr;
       ptr=p->sig;
       ptr->ant=p->sig=NULL;
	free(p);
      }


 }



}
//*****//////////////////////////////////////////////////
void insertar()
{ char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
  int i,j,sw,st;
  char valido;
  int n;


do{

do
{ clrscr();
   textcolor(14);textbackground(3);
   cuadros(2,2,80,24);
   textcolor(4);textbackground(3);
   cuadros(18,7,70,13);
  // textcolor(6+128); textcolor(6+128);

	 nn=memoria;
	 valido='n';
	 gotoxy(20,8);printf("DIGITE EL CODIGO     :");gets(cod);
	 n = strlen(cod);
	 for(j=0;j<=n-1;j++)
	{
	 if(n>4)
	  {   textcolor(4);textbackground(3);
	      cuadros(19,16,40,18);
	      gotoxy(20,17);
	      printf("FUERA DE RANGO");
	      valido='m';
	      getch();
	      break;
	  }

	 else
	  {
	   if((!(isdigit(cod[j])))&&(!(isalpha(cod[j]))))
	    { textcolor(8);textbackground(3);
	      cuadros(14,16,50,18);
	      gotoxy(15,17);
	     textcolor(1);printf("LO SIENTO VIEJO ACCESO DENEGADO ");
	     valido='m';
	     getch();
	     break;
	    }
	   else
	    {
	     p=ptr;

	     while(p!=NULL)
	     {
	      if(strcmp(p->cod,cod)==0)
	       { textcolor(5);textbackground(15);
		cuadros(19,16,40,18);
		gotoxy(20,17);
		printf(" CODIGO EXISTENTE");
		valido='m';
		getch();
		break;
	       }
	      p=p->sig;
	     }
	    }
	   }
	 }
    }while(valido=='m');

   strcpy(nn->cod,cod);

  do
      {
	valido='n';
	gotoxy(42,9);
	printf("             ");
	gotoxy(20,9);printf("DIGITE EL NOMBRE     :" );
	gotoxy(42,9);gets(nom);
	n=strlen(nom);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nom[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);printf("PULSE SOLO LETRAS");
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     printf("                                 ");
	     break;
	    }
	  }
       }while(valido=='m');


  strcpy(nn->nom,nom);
  nn->valor=valor;
  nn->sig=nn->ant=NULL;

  if(ptr==NULL)
   ptr=nn;
   else

  {p=ptr;
   while(p->sig!=NULL)
   p=p->sig;
   p->sig=nn;
   nn->ant=p;
  }
  gotoxy(29,20);printf("..EXITOS VIEJO ");


  gotoxy(18,22);printf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');

}
 
//////////////////////////////////////////////////////////////////////

void main()
{ clrscr();
 menu();
}


