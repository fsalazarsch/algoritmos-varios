#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>
#include "alloc.h"
#define TRUE 1
#define FALSE 0
#define MAXIMO 20


#define memoria (struct sanchez*)malloc(sizeof(struct circulares))
#define memoria (struct nodo3*)malloc(sizeof(struct regi))

#define ne 10

int cola[ne];
char op;
int fre,c,a,i,num;
char nom[45],aux[45];


//*****************************listas dobles***************************/

struct regi{
       int cod3;
       char nom3[45];
       struct regi *sig3;
       }nodo3;
	 struct regi *ptr3,*nn3,*p3,*q3;



 struct edwar{
  char cod[10];
  char nom[40];
  char apel[40];
  struct edwar *ant;
  struct edwar *sig;

 }nodo,*nn,*p,*ptr;




//*******************lista dobles circulares****************************************************/

    struct NODO {
    long codigo;
    char *nombre;
    struct NODO *Izq;
    struct NODO *Der;
    }sanchez;

  struct NODO  *cabeza1,*cabeza2,*p1,*q1,*nn1;

//**********************************************************************/

    struct COLAS{
    struct NODO COLA[MAXIMO];
    int frente,final;
    }cola1;

//*********************************************************************/
 void colas();
 void menu();
 int sw=0;
 char op;
 int z,r;
 long cod;
 char nombre[50];
 void adicionar_bcolas();
 void  lis_circular();
 void  listas_circular();

 void bicolas();
 void l_dobles();
int valida(int x,int y);

 void eliminar_bcolas();
 void visualizar_bcolas();
 void captura_doblecircular();
 void eliminar_doblecircular();
 void consultardoblecircular();
 void inscola();
 void insertarcola(struct COLAS *pq,long cod,char *nombre);
 void inscola();
 int colavacia(struct COLAS *pq);
 void eliminar_colas(struct COLAS *pq);
 void apagar_c();
    void  crear_circ();

    void modificar();

    void visualisar();

    void eliminar();



 void visualizar_colas();
 void adicionar_listas();
 void eliminar_listas();
 void visualizar_listas();
 void adicionar_circulares();
 void eliminar_circulares();
 void visualizar_circulares();

//************************************************************/

int valida(int x,int y)
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
   if(!isdigit(cad[i])||(cad[i]=='§'||cad[i]=='•'))
   {
      gotoxy(x,y);
   clreol();
   gotoxy(x,y);
   swi=1;break;}}
   }while(swi==1);
   return(atoi(cad));}

/*-----------------------------------------------------------------------*/
int lee_clave()
{
 char tecla,cad[10];
 int  k=0,sw=0;
 do
 {
  k++;
  tecla=tolower(getch());putchar('*');
  if(k==1 && tecla=='e')sw++;
  if(k==2 && tecla=='d')sw++;
  if(k==3 && tecla=='w')sw++;
  if(k==4 && tecla=='a')sw++;
  if(k==5 && tecla=='r')sw++;
  if(k==6 && tecla=='s')sw++;
  if(k==7 && tecla=='m')sw++;
 }while(k<=7 && sw<=6);
 return(sw);
}


/*******************************************************/
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

/********************************************************/
void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ﬂ");
    gotoxy(i,y2); cprintf("‹");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("€");
    gotoxy(x2,i); cprintf("€");
  }

}

/**************************PINTURA******************************/
void marco2(ci,cf,fi,ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Õ");
  delay(4); gotoxy(i,ff); printf("Õ");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("∫");
  delay(4); gotoxy(cf,i); printf("∫");
  }
 gotoxy(ci,fi); printf("…");
 gotoxy(ci,ff); printf("»");
 gotoxy(cf,fi); printf("ª");
 gotoxy(cf,ff);
 printf("º");
 textcolor(14); textbackground(0);
 }

/*********************************************************************/
void marco(ci,cf,fi,ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Õ");
  delay(4); gotoxy(i,ff); printf("Õ");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("∫");
  delay(4); gotoxy(cf,i); printf("∫");
  }
 gotoxy(ci,fi); printf("…");
 gotoxy(ci,ff); printf("»");
 gotoxy(cf,fi); printf("ª");
 gotoxy(cf,ff);
 printf("º");
 textcolor(14); textbackground(0);
 }

/************************************************************************/
void main()
{
 char op;
// fin=0;fre=0;
 int cont;
 int u;
 cont=0;

 clrscr();




do
 {
  textcolor(15);
  marcar(20,8,57,15,0);
  cont++;
  cuadros(20,9,57,15);
  marco(22,55,11,13);
  gotoxy(23,12);cprintf("ENTER CURRENT  PASSWORD[       ]");

   gotoxy(47,12);
  if(lee_clave()==7)
  {
   cont=7;
  }

   else
  {
   clrscr();

   textcolor(0);
   gotoxy(21,14);textcolor(13);cprintf("CLAVE EQUIVOCADA   ");
   gotoxy(21,15);textcolor(13);cprintf("INTENTELO DE NUEVO ");
   delay(1500);
  }
 }while(cont<3);


 clrscr();
 apagar_c();
 textcolor(15);
 gotoxy(22,7);textcolor(252);
 cprintf("  EDWAR  EMILIO  SANCHEZ  MAZZRI   ");
 gotoxy(32,19);
 cprintf("Copyright (c) 1998");
 for(i=70;i>15;i--)
{ textcolor(i+1);

gotoxy(i,9); cprintf("    ⁄ƒƒƒø  ⁄ƒƒƒø  ");
gotoxy(i,10);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,11);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,12);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,13);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,14);cprintf("    ≥€€€≥  ≥€€€≥  ");
gotoxy(i,15);cprintf("    ≥€€€¿ƒƒŸ€€€≥  ");
gotoxy(i,16);cprintf("    ≥€€€€€€€€€€≥  ");
gotoxy(i,17);cprintf("    ¿ƒƒƒƒƒƒƒƒƒƒŸ  ");
delay(10);
}

for(i=70;i>31;i--)
{ textcolor(i+5);
gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒƒø  ");
gotoxy(i,10); cprintf(" ≥€€€€€€‹‹≥  ");
gotoxy(i,11); cprintf(" ≥€€€  ﬂ€€≥  ");
gotoxy(i,12); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,13); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,14); cprintf(" ≥ €€   €€≥  ");
gotoxy(i,15); cprintf(" ≥€€€  ‹€€≥  ");
gotoxy(i,16); cprintf(" ≥€€€€€€ﬂﬂ≥  ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒƒŸ  ");
delay(10);
}
for(i=70;i>42;i--)
{ textcolor(i+3);


gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒø   ");
gotoxy(i,10); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,11); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,12); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,13); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,14); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,15); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,16); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒŸ   ");
delay(10);
}

for(i=70;i>52;i--)
{ textcolor(i);

gotoxy(i,9);  cprintf(" ⁄ƒƒƒƒƒƒƒø   ");
gotoxy(i,10); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,11); cprintf(" ≥€€€⁄ƒƒƒŸ   ");
gotoxy(i,12); cprintf(" ≥€€€¿ƒƒƒø   ");
gotoxy(i,13); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,14); cprintf(" ¿ƒƒƒø€€€≥   ");
gotoxy(i,15); cprintf(" ⁄ƒƒƒŸ€€€≥   ");
gotoxy(i,16); cprintf(" ≥€€€€€€€≥   ");
gotoxy(i,17); cprintf(" ¿ƒƒƒƒƒƒƒŸ   ");
delay(10);
 //marco(17,6,64,21);
 window(1,1,80,25);

}

delay(500);
 menu();
 getche();

}


void apagar_c()

{
	union REGS r,r1;
	r.h.ah=1;
	r.h.ch=32;
	int86(0x10,&r,&r1);
}


//*****************************MENU GENERAL************************/

void menu()

{
 int tecla,f,i,j;
 char opciones[25][45];


 strcpy(opciones[7]," COLAS        ");
 strcpy(opciones[8]," BICOLAS      ");
 strcpy(opciones[9],"LIS DOBLE CIRC");
 strcpy(opciones[10],"LIS.DOBLES    ");
 strcpy(opciones[11]," LIS.CIRCULARES");
 strcpy(opciones[12]," SALIR      ");
  do
 {
 textcolor(15); textbackground(0);
 clrscr();
  marco(2,79,2,24);
  textcolor(14); textbackground(0);
  marcar(3,3,19,5,3);
  marcar(3,16,19,23,3);
  marco2(2,20,2,24);
  marco2(21,78,3,5);
 textbackground(1);
 marco(3,19,3,5);
  marco2(3,19,6,15);

 for (i=22;i<=78;i++)
  {
   for (j=6;j<=23;j++)
   {
    gotoxy(i,j);textbackground(3);cprintf(" ");
   }
  }


 for (i=23;i<=31;i++)
  {
   for (j=7;j<=9;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

 for (i=69;i<=77;i++)
  {
   for (j=7;j<=9;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }


  gotoxy(42,4);textcolor(15);cprintf(" MENU PRINCIPAL ");

 for(f=7; f<=12;f++)
 {
  gotoxy(6,f); cprintf(opciones[f]);
  }
  f=7;
  textcolor(0); textbackground(15);
  gotoxy(6,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(6,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=7;

    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(6,f);cprintf(opciones[f]);
   if(f!=7)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


    case  7:colas();break;
    case  8:bicolas();break;
    case  9:listas_circular();break;
    case  10:l_dobles();break;
    case  11:  lis_circular();break;
 }

}
 while(f!=12);
}



//////////////////////////////////////menu colas/////////////////////////////////////////////////



void colas( )
{
 int tecla,f,i;
 char opciones[25][45];

 strcpy(opciones[12],"ADICIONAR    ");
 strcpy(opciones[13],"ELIMINAR     ");
 strcpy(opciones[14],"REGRESAR     ");

do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU COLAS ");


 marco2(39,58,10,16);
 for(f=12; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {

 case 12: inscola(); break;
 case 13: eliminar_colas(&cola1);break;

 }

  }while(f!=14);

}



//*********************************BCOLAS**************************************/

void bicolas()

{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11],"CREAR-INSERTAR    ");
 strcpy(opciones[12],"DATOS GENERALES   ");
 strcpy(opciones[13],"VISUALIZAR ULT    ");
 strcpy(opciones[14],"MENU PRINCIPAL    ");
do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU COLAS ");


 marco2(39,58,10,16);
 for(f=11; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: adicionar_bcolas(); break;
 case 12: eliminar_bcolas();break;
 case 13: visualizar_bcolas();break;



 }

}
 while(f!=14);

}


/////////////////////////////////////menu listas///////////////////////////////////////////
void l_dobles()

{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11]," ADICIONAR  ");
 strcpy(opciones[12]," ELIMINAR   ");
 strcpy(opciones[13]," VISUALISAR ");
 strcpy(opciones[14]," SALIR      ");

do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU LISTAS DOBLES ");


 marco2(39,58,10,16);
 for(f=11; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {

 case 11: adicionar_listas(); break;
 case 12: eliminar_listas();break;
 case 13: visualizar_listas();break;

   }

}
 while(f!=14);
}


//****************************************************************/

void listas_circular()

{

 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11]," ADICIONAR  ");
 strcpy(opciones[12]," ELIMINAR   ");
 strcpy(opciones[13]," VISUALISAR ");
 strcpy(opciones[14]," SALIR      ");

do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU LISTAS DOBLES ");


 marco2(39,58,10,16);
 for(f=11; f<=14;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11:captura_doblecircular();break;
 case 12:eliminar_doblecircular();break;
 case 13:consultardoblecircular();break;



   }

}
 while(f!=14);
}



//********************************listas**************************************/

 void adicionar_circulares()
 {}
  void eliminar_circulares()
{}
  void visualizar_circulares()

 {}
//***************************************************************************/
 void adicionar_listas()
 { char cod[10];
  char nom[40];
  char apel[40],op;
  int i,j,sw,st;
  char valido;
  int n;


do{

do
{ clrscr();
       marco(2,79,2,24);
       marco(2,79,2,5);

       gotoxy(20,3);printf(" A  D  I  C  I  O   N  A   R     :") ;

	 nn=(struct edwar *)malloc(sizeof(nodo));
	 valido='n';
	 gotoxy(20,8);printf("DIGITE EL CODIGO     :") ;gets(cod);

	 //valido el codigo
	 n = strlen(cod);
	  for(j=0;j<=n-1;j++)
	{
	 if(n>8)
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
	   if((!(isdigit(cod[j]))))
	    { textcolor(8);textbackground(3);
	      cuadros(14,16,50,18);
	      gotoxy(15,17);
	     textcolor(1);printf("INGRESE SOLO NUMEROS  ");
	     valido='m';
	     getch();
	     break;
	    }
	   else
	    {
	     p=ptr;
			   //recorremos la lista
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

	       //capturo el nombre y lo valido
  do
      {
	valido='n';
	gotoxy(42,9);
	printf("             ");
	gotoxy(20,9);printf("DIGITE EL NOMBRE     :") ;
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

       //capturo y valido el apellido
    do
      {
	valido='n';
	gotoxy(42,10);
	printf("             ");
	gotoxy(20,10);printf("DIGITE EL APELLIDO  :") ;
	gotoxy(42,10);gets(apel);
	n=strlen(apel);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(apel[j])))
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
  strcpy(nn->apel,apel);
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
  gotoxy(29,20);textcolor(252);cprintf(" REGISTRO INTRODUCIDO ");


  gotoxy(18,22);printf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');

}
//****************************************eliminar en lista dobles**********/

 void eliminar_listas()
{
  char cod[10];
  char nom[40];
  char apel[40];

  char op,sw1=0;


 clrscr();
   marco(2,79,2,24);
    marco(2,79,2,5);

       gotoxy(20,3);printf("E   L   I   M  I  N  A   R   	") ;


  do{
  cuadros(17,14,60,16);
  gotoxy(18,15); printf(" DESEA ELIMINAR EL PRIMER REGISTRO  [S/N]");
  op=toupper(getche());
  }while((op!='N')&&(op!='S'));
 if(op=='S')
  { sw1=1;

  if(ptr==NULL)
   {gotoxy(20,6);printf(" LISTA VACIA:") ;
    
     }
   else
     { p=ptr;
       ptr=p->sig;
       ptr->ant=p->sig=NULL;
        free(p);
      }


 }

}

//********************************visualizar listas***************************/
 void visualizar_listas()
{
int fill=6;

clrscr();

   marco(2,79,2,24);
    marco(2,79,2,5);

       gotoxy(20,3);printf("VISUALIZAR	") ;


 if(ptr==NULL)
	{

	gotoxy(25,8); printf("LISTA VACIA   ");
	  }
  else{
    marco(2,79,2,4);
    gotoxy(20,3); cprintf("V I S U A L I Z A R   L I S T A S   ");
    gotoxy(13,7);printf("CODIGO              NOMBRE       APELLIDO ");
    textcolor(4);textbackground(15);

    p=ptr;
      while(p!=NULL)
      {
       gotoxy(13,2+fill);printf(p->cod);
       gotoxy(33,2+fill);printf(p->nom);
       gotoxy(50,2+fill);printf(p->apel);

	fill++;
	p=p->sig;
	
       }
     }
gotoxy(20,22);printf("PULSE ENTER PARA REGRESAR");
getche();

}


//*********************************************************************/

 void adicionar_bcolas()
{
}

void eliminar_bcolas()
{}
 void visualizar_bcolas()
{}



//****************************************************/
 void consultardoblecircular(){


 if(cabeza1!=NULL){
 p1=cabeza1;
 while(p1->Der!=cabeza1){
	clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(20,3);printf("CONSULTA DOBLEMENTE CIRCULARES  	") ;

	gotoxy(20,10); printf("CODIGO: %ld  Nombre: %s \n",p1->codigo,p1->nombre);
	getch();
	p1=p1->Der;
	}
   if(p1!=NULL){
   clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

	gotoxy(15,15);printf("CODIGO %ld  Nombre: %s \n",p1->codigo,p1->nombre);
	getch();
	}
}
	else
	{
	clrscr();
       marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(15,15);textcolor(252);printf("Lista Vacia........");
	getch();
	}
   }
//*******************************************************************/
 void consultardoble(){
 p1=cabeza2;
 while(p1!=NULL){
	clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(20,3);printf("CONSULTA DOBLEMENTE CIRCULARES  	") ;

	gotoxy(15,15);printf("Codigo: %ld  Nombre: %s \n",p1->codigo,p1->nombre);
	getch();
	p1=p1->Der;
	}
   if(cabeza2==NULL){
	clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

	gotoxy(15,20);printf("Lista Vacia........");
	getch();
	}
   }

	int buscar_nododoblecircular(long cod){
	int sw=0;
	if(cabeza1==NULL)
	return 0;
	else{
	p1=cabeza1;
	while(p1->Der!=cabeza1 && sw==0){
	if(p1->codigo==cod)
	  sw=1;
	  else
		  p1=p1->Der;
	   }
	  if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p1->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}

 /*******************************************************************/
   /* valida los datos de entradas tales como los codigos y los nombres */
   void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux)
		{
		int sw=0,i,control;
		char *auxiliar;
		switch(tipo_captura){
			  case 1:{do{
			  control=0;

			  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				 if(isdigit(auxiliar[i])==0){
				    sw=1;
				    break;
				    }

				 }while(sw!=1);
				if(sw==1){
				control=sw;
				sw=0;
				}

				}while(control!=1);
				strcpy(aux->nombre,auxiliar);
				break;
				}
			  case 2:{
				  do{
				  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				    if(isdigit(auxiliar[i])==0){
					sw=1;
					break;
					}
				 }while(sw!=0);
				if(sw==1){
				control=sw;
				sw=0;
				}
				}while(control!=0);
				aux->codigo=atol(auxiliar);
				break;
				}
			    }
			 }

//*******************************************************************/
/* elimina un nodo de la lista doble circular */
void eliminar_doblecircular(){

  char a[20];

 int sw=0;
 clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(20,3);printf("ELIMINAR DOBLEMENTE CIRCULARES  	") ;

  gotoxy(10,10);printf("CODIGO A ELIMINAR: ");
			  do{
			  z=0;r=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);

		p1=cabeza1;
		   q1=NULL;
		   while(p1->Der!=cabeza1 && sw==0)
			  if(p1->codigo==cod)
				sw=1;
				else{
				    q1=p1;
				    p1=p1->Der;
				    }
		   if(q1==NULL){
			   if(p1->Der==cabeza1 && p1->codigo==cod && sw==0)
				    cabeza1=NULL;
			    else
				  if(p1->Der!=cabeza1 && p1->codigo==cod && sw==1){
					    q1=p1->Izq;
					    q1->Der=p1->Der;
					    q1=q1->Der;
					    q1->Izq=p1->Izq;
					    cabeza1=p1->Der;
						   free(p1);
						  }
				  }else
					if(p1->Der==cabeza1 && p1->codigo==cod && sw==0){
						 q1->Der=p1->Der;
						 q1=q1->Der;
				 q1->Izq=p1->Izq;
						  free(p1);
						 }
						 else{
						 if(sw==1){
						 q1->Der=p1->Der;
						 q1=q1->Der;
						 q1->Izq=p1->Izq;
						 free(p1);
						 }
						 }

   do{
   sw=0;
   gotoxy(10,20);printf(" DESEA CONTINUAR S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
  if(op=='S')
	eliminar_doblecircular();
		   }


//*****************************************/

/* captura la informacion para crear en la lista doble circular */
void captura_doblecircular(){
    int sw=0;
    clrscr();
	 nn1=(struct NODO *)malloc(sizeof(sanchez));

//nn1=new NODO;

    do{
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(20,3);printf("   REGISTRO  	") ;


    gotoxy(10,10);printf("CODIGO : ");
	if(sw==1){
	gotoxy(10,10);printf("ESTE CODIGO YA EXISTE");
	getch();
	clreol();
	}
    validar_datos(23,10,2,nn1);
   }while((sw=buscar_nododoblecircular(nn1->codigo))==1);
    gotoxy(10,12);
    printf("Nombre::> ");
    validar_datos(23,12,1,nn1);

   nn1->Izq=nn1->Der=NULL;
	  if(cabeza1==NULL)
	   {
		cabeza1=nn1;
		nn1->Izq=cabeza1;
		nn1->Der=cabeza1;
	   }
		else{
			p1=cabeza1;
			while(p1->Der!=cabeza1){
			    p1=p1->Der;
						  }
			p1->Der=nn1;
			nn1->Der=cabeza1;
			nn1->Izq=p1;
	    }

   do{
  sw=0;
   gotoxy(10,20);
   printf(" DESEA CONTINUAR S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	captura_doblecircular();
   }
/* busca si existe un nodo dentro una lista doble */


	  int buscar_nododoble(long cod){
	  int sw=0;
	if(cabeza2==NULL)
	return 0;
	else{
	  p1=cabeza2;
	  while(p1->Der!=NULL && sw==0){
		if(p1->codigo==cod)
		  sw=1;
		  else
		  p1=p1->Der;
	   }

 if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p1->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}


//*******************************************************************/
 void inscola()
{

 int sw2=0;
  char a[20];
  clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(30,3);printf(" CREAR COLAS ") ;


   gotoxy(15,15);printf("DIGITE EL CODIGO: ");
			  do{
			  z=0;r=0;
			  gotoxy(32,15);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);
 gotoxy(15,16);printf("DIGITE EL NOMBRE : ");
 scanf("\n");
 gotoxy(34,16); gets(nombre);
 insertarcola(&cola1,cod,nombre);

   do{
   sw2=0;
   gotoxy(30,20);
   printf(" DESEA CONTINUAR S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw2=1;
  }while(sw2!=1);
   if(op=='S')
	inscola();
    }

 /*******************************************************************/
    int colavacia(struct COLAS *pq){
    return((pq->frente==pq->final) ? TRUE : FALSE);
    }
 /*******************************************************************/

 void eliminar_colas(struct COLAS *pq)

{
    clrscr();
	marco(2,79,2,24);
	marco(2,79,2,5);

       gotoxy(30,3);printf(" ELIMINAR COLAS ") ;

    if(colavacia(pq)){
     gotoxy(30,15);printf("DESBORDE ");
    getch();
    return;
    }
    if( pq->frente==MAXIMO-1){
	pq->frente=0;
	 gotoxy(30,14);printf("Codigo :%ld Nombre :%s",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	getch();

	  }
   else {
	gotoxy(30,15);	printf("Codigo :%ld  Nombre:%s",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	getch();
	 pq->frente++;
       }

  }

 /*******************************************************************/
void insertarcola(struct COLAS *pq,long cod,char nombre[]){
	  if(pq->final==MAXIMO-1)
	   pq->final=0;

	pq->COLA[pq->final].codigo=cod;
	pq->COLA[pq->final].nombre=nombre;
	pq->final++;
	}


////////////////////////////////menu circulares///////////////////////////////

void lis_circular()

{
 int tecla,f,i;
 char opciones[25][45];


 strcpy(opciones[11],"CREAR LIS_CIRCULAR");
 strcpy(opciones[12],"     MODIFICAR    ");
 strcpy(opciones[13],"    VISUALISAR    ");
 strcpy(opciones[14],"     ELIMINAR     ");
 strcpy(opciones[15],"  MENU PRINCIPAL  ");
do
 {
 textcolor(14); textbackground(15);

 marco2(32,68,7,9);
 gotoxy(42,8);textcolor(252);cprintf(" MENU LIS_CIRCULAR ");


 marco2(39,58,10,16);
 for(f=11; f<=15;f++)
 {
  gotoxy(40,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(40,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
    while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(40,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=11;

    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(40,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(40,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


    case 11:crear_circ();break;
    case 12:modificar();break;
    case 13:visualisar();break;
    case 14:eliminar();break;

   }

}
 while(f!=15);
}


void crear_circ()
{
int cod3;
char nom3[45];

char op,n;
int i,x;
do{ op='s';
clrscr();
marco(2,78,2,24);
marco2(3,77,3,5);
marco2(3,77,6,23);
gotoxy(20,4);printf(" R  E  G  I  S  T  R  O       C   R   E   A   R     ");
gotoxy(20,10);printf("DIGITE EL CODIGO DEL ESTUDIANTE :  ");
gotoxy(55,10);
cod3=valida(55,10);
{flushall();}
gotoxy(20,13);printf("DIGITE EL NOMBRE DEL ESTUDIANTE :   ");
gotoxy(55,13);
gets(nom3);

nn3=memoria;

nn3->cod3=cod3;
strcpy(nn3->nom3,nom3);

 if(ptr3==NULL){

  p3=memoria;

 ptr3=p3;
 p3->sig3=nn3;
 nn3->sig3=ptr3;
     }
  else {
  p3=ptr3->sig3;
  nn3->sig3=p3;
  ptr3->sig3=nn3;
	}

gotoxy(20,22);printf("DESEA SEGUIR INSERTANDO ESTUDIANTES  n/s");
gotoxy(62,22);scanf("%c",&op);

}while(op=='s'); }

//*--------------------------------------------------------------------*/
void modificar(){
int cod3;
char nom3[45];

char op,n;


int i,x,swi;
clrscr();
 marco(2,78,2,24);
 marco2(3,77,3,5);
 marco2(3,77,6,23);
gotoxy(20,4);printf(" R  E  G  I  S  T  R  O       M  O  D  I  F   I  C   A  R   ");

if(ptr3==NULL){



gotoxy(10,10);printf("NO HAY DATOS");
getche();
    }
    if(ptr3!=NULL){
clrscr(); swi=0;
gotoxy(20,10);printf("ESCRIBA EL CODIGO A MODIFICAR  [         ]");
gotoxy(52,10);
cod3=valida(52,10);

p3=ptr3->sig3;
while(p3!=ptr3){
if(p3->cod3==cod3){
clrscr();
marco(3,77,3,5);
marco(2,78,2,24);
gotoxy(20,10);printf("DIGITE EL NUEVO CODIGO DEL ESTUDIANTE =>  ");
gotoxy(60,10);
cod3=valida(60,10);
gotoxy(20,13);printf("DIGITE EL NUEVO NOMBRE => ");
gotoxy(46,13);gets(nom3);

p3->cod3=cod3;
strcpy(p3->nom3,nom3);

swi=1;
	}
p3=p3->sig3;
}
}
if(swi==0){
gotoxy(4,23);printf("El codigo %d", cod3);
gotoxy(15,15);textcolor(252);cprintf(" N O   E X I S T E ");
getche();

}


}



//*-----------------------------------------------------------------------*/
void visualisar()
{
int x;
clrscr();
 marco(2,78,2,24);
 marco2(3,77,3,5);
 marco2(3,77,6,23);
 gotoxy(14,4);printf(" R  E  G  I  S  T  R  O      V  I  S  U  A  L  I   Z   A  R ");


if(ptr3==NULL)
{
gotoxy(6,5);textcolor(252);cprintf("LOS DATOS FUERON ELIMINADOS");
	    }
if(ptr3!=NULL){



gotoxy(6,13);printf("CODIGO");
gotoxy(20,13);printf("NOMBRE");
x=16;
p3=ptr3->sig3;
while(p3!=ptr3){
gotoxy(5,x);
printf("%d",p3->cod3);
gotoxy(18,x);
printf(p3->nom3);
x=x+1;
p3=p3->sig3;

}
 }
getche();}
//*--------------------------------------------------------------------*/
void eliminar()
{
int cod3,swi;

clrscr();

 marco(2,78,2,24);
 marco2(3,77,3,5);
 marco2(3,77,6,23);

 gotoxy(20,4);printf(" R  E  G  I  S  T  R  O       E   L  I  M  I  N  A  R    ");


if(ptr3==NULL){

gotoxy(10,10);textcolor(252);cprintf("NO HAY DATOS");
getche();
    }
    if(ptr3!=NULL){
clrscr(); swi=0;
gotoxy(20,10);printf("ESCRIBA EL CODIGO A ELIMINAR => [          ]");
gotoxy(53,10);
cod3=valida(53,10);
p3=ptr3->sig3;
q3=ptr3;
while(p3!=ptr3){
if(p3->cod3==cod3){
q3->sig3=p3->sig3;
free(p3);swi=1;
if(p3->sig3==ptr3){
ptr3=NULL;break;
}

}
q3=p3;
p3=p3->sig3;

}

if(swi==0){
gotoxy(4,23);printf("El codigo %d", cod3);
gotoxy(8,24);textcolor(252);cprintf(" N O   E X I S T E ");

getche();
}
}
}








