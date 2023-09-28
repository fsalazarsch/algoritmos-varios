#include<stdio.h>
#include<alloc.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#define memoria (struct Tnodo*) malloc(sizeof(struct Tnodo))
/**************************************/
struct Tnodo
  {
	 char nombre[20];
	 int codigo;
	 struct Tnodo *sig;
	 };
	struct Tnodo *nuevo,*cab,*q,*p;
	char nombre[20];
	int codigo;
/***********F U N C I O N E S********************/
void crear();
void insertar();
void eliminar();
void marco();
void ventana(int X1,int Y1,int X2,int Y2);
void visualizar();
 int validar_codi(int x,int y);
void menu();
/***************************/
void main()
{
 menu();
 clrscr();
 }
 /*********V A L I D A R********************************/
 int validar_codi(int x,int y)
{
int j,numero,swich;
char cadena[30];
do{
do{
	gets(cadena);swich=1;
	numero=strlen(cadena);
	}while(numero<=0);
	for(j=0;j<numero;j++)
	{
	if(!isdigit(cadena[j])||(cadena[j]=='¤'||cadena[j]=='¥'))
	{
		gotoxy(x,y);
	clreol();
	gotoxy(x,y);
	swich=0;break;}}
	}while(swich==0);
	return(atoi(cadena));}



 /**********C R E A R********************/
void crear()
 {
	struct Tnodo *tq;
	char op;
	int codi;
	clrscr();
	do
	{
	textcolor(14);
	clrscr();
	gotoxy(4,4);cprintf("DIGITE EL NOMBRE: ");
	gets(nombre);
	gotoxy(4,6);cprintf("DIGITE EL CODIGO: ");
	gotoxy(25,6);
  codigo=validar_codi(25,6);
{flushall();}

		 nuevo=memoria;
		nuevo->codigo=codigo;
		strcpy(nuevo->nombre,nombre);

	if(cab==NULL)
	  {
		 p=memoria;
		  cab=p;
		  p->sig=nuevo;
		  nuevo->sig=cab;

	  }
		else
		{
		 p=cab->sig;
		 nuevo->sig=p;
		 cab->sig=nuevo;
		}
		gotoxy(10,20);
		printf("DESEA SEGUIR CREAR OTRO (S/N) :");
		op=toupper(getche());
	 }while(op!='N');

  getch();
 }
 /**************V E R******************/
 void visualizar()
 {
	 char nombre[15];
	 int codigo;
	struct Tnodo *nuevo;
	int cont=7;
	textcolor(8);textbackground(7);
  clrscr();


     if(cab!=NULL)
     {
	  gotoxy(26,2);printf(" L I S T A  D I G I T A D A \n   ");
	 p=cab->sig;
	 while(p!=cab)
	 {gotoxy(35,cont);
	  printf(" %d \n",p->codigo);
	  gotoxy(10,cont);
	  printf(" %s \t",p->nombre);
	  p=p->sig;
	  cont=cont+1;
	 }
	 }
	    if(cab==NULL)
      { gotoxy(25,10);
      printf("NO HAY DATOS");
      gotoxy(25,11);textcolor(4);
      cprintf("------------");
      gotoxy(15,15);
      printf("OPRIMA <<ENTER>> PARA REGRESAR AL MENU ");
      }

	  getche();
}
/**********I N S E R T A R************************/
void insertar()
{   int n;
	 struct Tnodo *nuevo,*p;
	 textcolor(14);
      char op;
int i,x,swich,codigo;

    if(cab!=NULL){
clrscr(); swich=0;
gotoxy(20,10);printf("DIGITE CODIGO A MODIFICAR[*********]");
gotoxy(47,10);
codigo=validar_codi(47,10);

p=cab->sig;
while(p!=cab){
if(p->codigo==codigo){
clrscr();
gotoxy(10,10);printf("DIGITE CODIGO: ");
gotoxy(30,10);
codigo=validar_codi(30,10);
gotoxy(10,13);printf("DIGITE NOMBRE: ");
gotoxy(30,13);gets(nombre);
p->codigo=codigo;
strcpy(p->nombre,nombre);
swich=1;
	}
p=p->sig;
}
}
if(swich==0){
gotoxy(25,16);printf("El codigo %d", codigo);
gotoxy(25,17);printf("No existe");
   }
  if (cab==NULL)
  {   clrscr();
      gotoxy(25,10);
      printf("NO HAY DATOS");
      gotoxy(25,11);textcolor(4);
      cprintf("------------");
      gotoxy(15,15);
      printf("OPRIMA <<ENTER>> PARA REGRESAR AL MENU ");
    }
     getche();

}



/************E L I M I N A R***********************/
 void eliminar()
 {
	int codigo,swich;
    if(cab!=NULL)
    {
	clrscr(); swich=0;
	gotoxy(10,10);printf("DIGITE EL CODIGO A ELIMINAR..[********]");
	gotoxy(40,10);
	codigo=validar_codi(40,10);
	p=cab->sig;
	q=cab;
	while(p!=cab)
	{
	if(p->codigo==codigo)
	{
	q->sig=p->sig;
	free(p);swich=1;
	if(p->sig==cab)
	{
	cab=NULL;break;
	}

    }
     q=p;
     p=p->sig;

  }

	if(swich==0)
	{
	gotoxy(25,16);printf("El codigo %d", codigo);
	gotoxy(25,17);printf("No existe");

	getche();
	}
      }
	if(cab==NULL)
	{
	clrscr();
	gotoxy(25,10);
      printf("NO HAY DATOS");
      gotoxy(25,11);textcolor(4);
      cprintf("------------");
      gotoxy(15,15);
      printf("OPRIMA <<ENTER>> PARA REGRESAR AL MENU ");
       getch();
       }

  }




 //***********V E N T A N A   O  C U A D R O**********************

void ventana(int X1,int Y1,int X2,int Y2)
{    int i;
 for(i=X1+1;i<X2;i++){
 gotoxy(i,Y1);printf("Í");   // LINEA ARRIBA HORIZONTAL
 gotoxy(i,Y2);printf("Í");}  // LINEA ABAJO HORIZONTAL
 for(i=Y1+1;i<Y2;i++){
 gotoxy(X1,i);printf("º");    // LINEA IZQUIERDA VERTICAL
 gotoxy(X2,i);printf("º");}   // LINEA DERECHA VERTICAL
 gotoxy(X1,Y1);printf("É");
 gotoxy(X1,Y2); printf("È");
 gotoxy(X2,Y1);printf("»");
 gotoxy(X2,Y2); printf("¼");
}

/**************M E N U********************************/
void menu()
{
  char op;
  clrscr();
  while (1)
	{
	 textbackground(0);
       //	window(22,8,57,17);

	textbackground(3);clrscr();ventana(1,1,36,11);
	textcolor(44);
	gotoxy(15,2);delay(250);cprintf("M E N U ");
	gotoxy(14,3);delay(248); cprintf("T:CREACION");
	gotoxy(14,4);delay(246); cprintf("A:VISUALIZAR");
	gotoxy(14,5);delay(246); cprintf("P:INSERTAR");
	gotoxy(14,6);delay(244);cprintf("Q:ELIMINAR");
	gotoxy(14,7);delay(240);cprintf("G:SALIR     ");
	gotoxy(9,8);textcolor(14);
	delay(146);delay(238);cprintf("DIGITE UNA OPCION:[ ]");
	gotoxy(11,9);textcolor(0+BLINK);delay(100);cprintf("TATIANA QUINTERO");
	gotoxy(8,10);textcolor(0);delay(100);cprintf("PULSE LETRAS MAYUSCULAS");
	gotoxy(28,8);op=getche();



	  switch(op)
	  {
		case 'T':crear();clrscr();break;
		case 'A':visualizar();clrscr();break;
		case 'P':insertar();clrscr();break;
		case 'Q':eliminar();clrscr();break;
		case 'G':exit(0);
		}

	    }
	  }


/***************F I N A L***************/