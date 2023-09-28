#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <alloc.h>
#include <ctype.h>
#include <dos.h>

struct nodo{
      int numero;
      struct nodo *enlace;
}tnodo;
struct nodo *ptr=NULL,*nn,*p,*l;

void crear();
void menu();
void busqueda();
void visualizar();
void eliminar();

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



void marco(ci,cf,fi,ff)
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

void main()
{
clrscr();
menu();
getche();
}
///////////////////////////////////////////////////////////////////
void menu()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[12],"CREAR                      ");
 strcpy(opciones[13],"BUSQUEDA                   ");
 strcpy(opciones[14],"ELIMINAR                   ");
 strcpy(opciones[15],"VISUALIZAR                 ");
 strcpy(opciones[16],"SALIR                      ");
   do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(14,4); textcolor(11); textbackground(1);
 printf("M   E   N   U       P   R   I   N   C   I   P   A  L");
 textcolor(14);textbackground(1);
 gotoxy(30,7); textcolor(12); textbackground(3);
 printf("LISTAS ENLAZADAS");
 marcar(8,8,70,20,0);
 marco(18,52,11,20);
 marco(2,78,2,24);
 textcolor(12); textbackground(8);
 for(f=12; f<=16;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=16)
     f=f+1;
     else

    f=12;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

    f=16;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 12: crear(); break;
 case 13: busqueda(); break;
 case 14: eliminar(); break;
 case 15: visualizar(); break;
 case 16: default: printf("FINAL");
 }

}
 while(f!=16);
}


/**************************************************************************/
void crear()
{
 char op,k;
 int numero;
 do
 {
  clrscr();
  textcolor(14); textbackground(1);
  marcar(2,2,78,24,1);
  textcolor(12); textbackground(8);
  marco(2,78,2,24);
  textcolor(12); textbackground(8);
  marco(10,68,8,15);
  marcar(10,8,68,15,2);
  gotoxy(25,4);printf("C    R     E    A     R :");
  gotoxy(15,18);printf(" <<<<<<DIGITE ENTER PARA CONTINUAR>>>>>> ");
  gotoxy(14,10);printf("PULSE UN NUMERO POSITIVO : ");scanf("%d",&numero);
   do
 {            
  gotoxy(40,10);
  clreol();
  k=getchar();
}while(!isdigit(k));
  nn=malloc(sizeof(tnodo));
  nn->numero=numero;
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
	textcolor(12); textbackground(3);
	marco(20,60,21,23);
	textcolor(12); textbackground(3);
	marcar(20,21,60,23,2);
	gotoxy(25,22);printf("DESEA CREAR OTRO NODO SI/NO ");
	sound(200);delay(500);nosound();
	op=toupper(getche());
 }while(op!='N');

}
/*********************************************************************/
void busqueda()
{
int x,sw=0;
 clrscr();
  p=ptr;
  textcolor(14);textbackground(1);
  marcar(2,2,78,24,1);
  textcolor(12);textbackground(8);
  marco(2,78,2,24);
  textcolor(18);textbackground(7);
  marco(10,68,8,15);
  marcar(10,8,68,15,0);
  gotoxy(23,4);printf("B    U    S    Q    U    E    D    A :");
  marco(2,78,2,5);
  gotoxy(14,10);printf("DIGITE EL NUMERO A BUSCAR: ");scanf("%d",&x);

   while (p!=NULL)
    {
	if (p->numero==x)
	  {
	  gotoxy(30,12);
	  printf("%d",p->numero);gotoxy(14,12);printf(" EL NUMERO ES: ");
	  sw=1;
	  }
	  p=p->enlace;

    }
    if (sw==0)
    { gotoxy(24,14);printf("  <<<< NO EXISTE HIJO >>>>   "); }
      sound(200);delay(500);nosound();
      gotoxy(22,23);printf(" <<<<< ENTER PARA REGRESAR >>>>> ");
  getche();
 }

/***************************************************************************/

void visualizar()
{
int fill=10;
clrscr();
 l=ptr;
  textcolor(14);textbackground(1);
  marcar(2,2,78,24,1);
  textcolor(12);textbackground(8);
  marco(2,78,2,24);
  textcolor(8);textbackground(7);
  marco(2,78,2,4);
  gotoxy(15,3);printf(" V I S U A L I Z A C I O N    D E    L I S T A S\n ");
  marco(3,77,5,20);
  marcar(3,5,77,20,0);
 while (l!=NULL)
 {
      gotoxy(15,fill);printf("%d",l->numero);
      l=l->enlace;
      fill++;
  }
 marco(2,78,21,24);
 gotoxy(18,22);printf("   <<<<<PULSE  ENTER PARA VOLVER AL MENU>>>>>  ");

 getche();
}
/*************************************************************/

void eliminar()
{
  char op;
   clrscr();
   marco(2,78,1,23);
  p=ptr;

do{
    gotoxy(5,20);printf("ESTA SEGURO DE ELIMINAR S/N ");
    gotoxy(35,20);op=toupper(getch());
    gotoxy(35,20);clreol();
 }
    while((op!='N')&&(op!='S'));
    if (op=='S')
    {
      ptr=ptr->enlace;
      free(p);
     }

}