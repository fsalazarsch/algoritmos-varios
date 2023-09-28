#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include<stdlib.h>
#include<fcntl.h>
#include<process.h>
#include<time.h>
#define color(x,y)textcolor(x);textbackground(y);

/*****************   C U A D R O    D E L     M E N U   *****************/

void cuadro(ci,cf,fi,ff)
{
 int i;
 for(i=ci;i<=cf;i++)
 {
  delay(5); gotoxy(i,fi); cprintf("Í");
  delay(5); gotoxy(i,ff); cprintf("Í");
 }
 for(i=fi;i<=ff;i++)
 {
  delay(5); gotoxy(ci,i); cprintf("º");
  delay(5); gotoxy(cf,i); cprintf("º");
 }
 gotoxy(ci,fi); cprintf("É");
 gotoxy(ci,ff); cprintf("È");
 gotoxy(cf,fi); cprintf("»");
 gotoxy(cf,ff);
 cprintf("¼");
}

/****************   P I N T A R     C U A D R O     **********************/

void pintar(int c1,int f1,int c2,int f2,int fondo)
{
 int i1,i2;
 switch(fondo)
 {
  case 1: fondo= 176;break;
  case 2: fondo=177 ;break;
  case 3: fondo= 178;break;
  case 4: fondo= 32;break;
  default  :fondo= 32;
 }
 for(i1=f1;i1<=f2;i1++)
 for(i2=c1;i2<=c2;i2++)
 {
  gotoxy(i2,i1); cprintf("%c",fondo);
 }
}
/***********************    P R O G R A M A    *****************************/

/** Definicion y declaracion del nodo **/

 struct nodo
 {
   long datos;
   struct nodo *enlace;
 };
 struct nodo  *nn,*ptr=NULL,*auxptr,*aux1,*aux11,*aux111;

 long auxdat,datos;
 int i,con=0,j,lon,sw,st;

  void adicionar();
  void menu_principal();

 void main()
 {
  clrscr();
  menu_principal();getche();  
 }
/**************************************************************************/
/******************  A D I C I O N A R    D A T O S  **********************/
/**************************************************************************/
void adicionar()
{
  char op;
  char val,cedu[20];
  do
  {
   clrscr();
   textcolor(14);textbackground(1);
   pintar(15,8,64,18,0);
   textbackground(3);
   do
   {
    clrscr();
    textbackground(1);
    pintar(15,8,64,18,0);
    textbackground(3);
    gotoxy(45,11);printf("               ");
    val='n';
    gotoxy(23,11);printf("DIGITE DATOS A ADICIONAR : ");
    scanf("\n"); gets(cedu);
    lon = strlen(cedu);
    for(j=0;j<=lon-1; j++)
    {
     if(!(isdigit(cedu[j])))
     {
      val='m';
      break;
     }
    }
    }while(val=='m');
    auxdat=atol(cedu);
    aux11=ptr;
    while(aux11!=NULL)
    {
     if(aux11->datos==auxdat)
     {
      clrscr();
      textbackground(1);
      pintar(15,8,64,18,0);
      textbackground(3);
      textcolor(128+14);
      gotoxy(18,12);cprintf("** E S T E   D A T O   Y A   E X I S T E **");
      val='m';
      sw=2;
      getch();
     }
     aux11=aux11->enlace;
    }
    if(val!='m')
    {
   nn=malloc(sizeof (struct nodo) );
   nn->datos=auxdat;
   nn->enlace=NULL;
   if(ptr==NULL)
   {
    ptr=nn;
    auxptr=ptr;
    con=1;
   }
   else
   {
    auxptr->enlace=nn;
    auxptr=nn;
    con++;
   }
   }
   gotoxy(22,14);printf("DESEA ADICIONAR OTRO DATO (S/N): ");
   op=toupper(getch());
 }while(op!='N');
}
/***************************************************************************/
/******************************  C O N S U L T A R  ************************/
/***************************************************************************/
void consultar()
{
 char op,cedu[20],val;
 do
 {
  clrscr();
  textcolor(14);textbackground(1);
  pintar(15,8,64,18,0);
  textbackground(3);
  sw=1;
  do
  {
   clrscr();
   textbackground(1);
   pintar(15,8,64,18,0);
   textbackground(3);
   val='n';
   gotoxy(47,10);printf("             ");
   gotoxy(22,10);printf("DIGITE DATO A CONSULTAR : ");
   scanf("\n"); gets(cedu);
   lon = strlen(cedu);
   for(i=0;i<=lon-1; i++)
   {
    if(!(isdigit(cedu[i])))
    {
     val='m';
     break;
    }
   }
  }while(val=='m');
  auxdat=atol(cedu);
  aux11=ptr;
  while(aux11!=NULL)
  {
   if(aux11->datos==auxdat)
   {
    gotoxy(22,12);printf("EL DATO DEL USUARIO ES :%ld",aux11->datos);
    sw=2;
   }
   aux11=aux11->enlace;
  }
  if(sw==1)
  {
   clrscr();
   textbackground(1);
   pintar(15,8,64,18,0);
   textbackground(3);
   textcolor(128+14);
   gotoxy(19,11);cprintf("** D A T O   N O   E X I S T E N T E **");
  }
  gotoxy(22,14);printf("DESEA CONSULTAR OTROS DATOS (S/N):");
  op=toupper(getch());
 }while(op!='N');
}
/**************************************************************************/
/*************************** E L I M I N A R   ***************************/
/*************************************************************************/
void eliminar()
{
 int k;
 char cedu[20],val,op;
 long aux;
  do
   {
    clrscr();
    textcolor(14);textbackground(1);
    pintar(15,8,64,18,0);
    textbackground(3);
    sw=1;
    do
     {
      clrscr();
      textbackground(1);
      pintar(15,8,64,18,0);
      textbackground(3);
      val='n';
      gotoxy(39,5);
      printf("               ");
      gotoxy(22,11);printf("DIGITE DATOS A ELIMINAR:");
      scanf("\n"); gets(cedu);
      lon = strlen(cedu);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(cedu[i])))
	   {
	     val='m';
	     break;
	   }
	 }
      }while(val=='m');
      auxdat=atol(cedu);
      if(ptr==NULL)
      {
       clrscr();
       textbackground(3);
       pintar(15,8,64,18,0);
       textbackground(3);textcolor(128+14);
       gotoxy(20,13);cprintf(" ** NO EXISTE INFORMACION EN LA LISTA **");
       getch();
      }
      aux11=ptr;
      aux111=ptr->enlace;
      if(ptr->datos==auxdat)
      {
       sw=2;
       ptr=aux111;
       free(aux11);
       clrscr();
       textbackground(1);
       pintar(15,8,64,18,0);
       textbackground(3);
       textcolor(128+14);
       gotoxy(21,12);cprintf(" ** D A T O    E L I M I N A D O **");
       con--;
       getch();
      }
      else
      {
       while(aux111!=NULL)
       {
	if(auxdat==aux111->datos)
	{
	 sw=2;
	 aux1=ptr;
	 while(aux1!=NULL)
	 {
	  if(aux1->enlace==aux111)
	  {
	   if(aux1->enlace==auxptr)
	   {
	     auxptr=aux1;
	   }
	   aux1->enlace=aux111->enlace;
	   free(aux111);
	   clrscr();
	   textbackground(3);
	   pintar(15,8,64,18,0);
	   textbackground(1);textcolor(128+14);
	   gotoxy(21,12);cprintf("**  D A T O     E L I M I N A D O **");
	   con--;
	  }
	  aux1=aux1->enlace;
	 }
	}
	aux111=aux111->enlace;
       }
      }
      if(sw==1)
      {
       clrscr();
       textbackground(1);
       pintar(15,8,64,18,0);
       textbackground(3);
       textcolor(128+14);
       gotoxy(20,12);cprintf("** D A T O    N O    E X I S T E  **");
       getch();
      }
      gotoxy(23,14);printf("DESEA ELIMINAR OTRO DATO (S/N):");
      op=toupper(getch());
     }while(op!='N');
   }
/**************************************************************************/
/*****************  L I S T A D O     G E N E R A L   *********************/
/**************************************************************************/
void listado_general()
{
 int c;
 c=12; sw=1;
 if(ptr==NULL)
  {
    clrscr();
    textcolor(14);textbackground(1);
    pintar(15,8,64,18,0);
    textbackground(3);
    textcolor(128+14);
    gotoxy(20,13);cprintf("** NO EXISTE INFORMACION EN LA LISTA **");
  }
  else
  {
   clrscr();
   textcolor(14);textbackground(1);
   pintar(15,8,64,18,0);
   textbackground(3);
   gotoxy(26,10);
   aux11=ptr;
   printf(" LISTADO DE DATOS ");
   while(aux11!=NULL)
    {
     gotoxy(35,c);printf("%ld",aux11->datos);
     c++;
     aux11=aux11->enlace;
    }
  }
   getch();
}
/**************************************************************************/
/************************* ELEMENTO MAYOR *********************************/
/**************************************************************************/
void elemento_mayor()
{
 clrscr();
 textcolor(14);textbackground(1);
 pintar(15,8,64,18,0);
 textbackground(3);
 for(i=con-1;i>=1;i--)
 {
  aux11=ptr;
  aux111=aux11->enlace;
  for(j=1;j<=i;j++)
  {
   aux11=aux11;
   aux111=aux111;
   if(aux11->datos<aux111->datos)
   {
    datos=aux11->datos;
    aux11->datos=aux111->datos;
    aux111->datos=datos;
   }
   aux11=aux11->enlace;
   aux111=aux11->enlace;
  } 
}
   gotoxy(22,12);printf("EL ELEMENTO MAYOR ES :%ld",ptr->datos);
   getche();
 }
/**************************************************************************/
/*************************  MENU  PRINCIPAL  ******************************/
/**************************************************************************/
 void menu_principal()
 {
    char opciones[20][55];
    int f;
    char tecla;
    clrscr();
    textbackground(3);textcolor(14);
    strcpy(opciones[0],"    MENU    PRINCIPAL     \n");
    strcpy(opciones[1],"  ADICIONAR ..            \n");
    strcpy(opciones[2],"  CONSULTAR ..            \n");
    strcpy(opciones[3],"  ELIMINAR ..             \n");
    strcpy(opciones[4],"  LISTADO GENERAL ..      \n");
    strcpy(opciones[5],"  ELEMENTO MAYOR  ..      \n");
    strcpy(opciones[6],"  SALIR DEL SISTEMA ..    \n");
    textcolor(14);
    do
    {
     clrscr();
     cuadro(2,78,1,25);
     cuadro(2,78,3,3);
     cuadro(2,78,22,25);
     pintar(23,9,50,19,0);
     textbackground(3);textcolor(14);
     gotoxy(23,10);cprintf("Ì"); /** alt 204 **/
     gotoxy(48,10);cprintf("¹"); /** alt 185 **/
     textbackground(1);textcolor(14);
     gotoxy(23,10);cprintf(opciones[0]);
     gotoxy(15,2);printf("LUIS FERNANDO ARDILA ROMERO   COD. 96132074 ");
     gotoxy(6,24);printf("UTILICE LAS TECLAS DEL CURSOR () Y PRESIONE");
     gotoxy(53,24);printf("ENTER PARA CONTINUAR");
     textcolor(14);textbackground(1);
     for(f=1;f<=6;f++)
	 { gotoxy(23,f+11);
	   cprintf(opciones[f]);
	 }
      f=1;
      textcolor(14);textbackground(8);
      gotoxy(23,f+11);cprintf(opciones[f]);
      do
      { tecla=getch();
	if(tecla==72)
	{
	  textcolor(14);textbackground(1);
	  gotoxy(23,f+11);cprintf(opciones[f]);
	  if(f==1)
	    f=6;
	  else
	     f=f-1;
	  textcolor(14);textbackground(8);
	  gotoxy(23,f+11);cprintf(opciones[f]);
	 }
	if(tecla==80)
	  { textcolor(14);textbackground(1);
	    gotoxy(23,f+11);cprintf(opciones[f]);
	    if(f==6)
	      f=1;
	    else
	      f=f+1;
	      textcolor(14);textbackground(8);
	    gotoxy(23,f+11);cprintf(opciones[f]);
	  }
      }while(tecla!=13);
      switch(f)
      { case 1:adicionar();break;
	case 2:consultar();break;
	case 3:eliminar();break;
	case 4:listado_general();break;
	case 5:elemento_mayor();break;
	case 6:exit(0);
      }
    }while(f!=6);
}


