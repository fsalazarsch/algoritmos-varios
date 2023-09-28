#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define memoria (struct nombre *)malloc(sizeof(struct nombre))

struct nombre
{
	int info;
	char nom[15];
	int cod;
	struct nombre *enlace;
};

struct nombre *nn,*cabeza,*p;
char nom[15],op[2];
int cod;
int sw,i;
void intro();
void eliminar();
void insertar();
carlos(struct nombre *e);
void vis();
void vis_gen();
void menu();
int validar(int k,int q);
//*****************************
void menu()
{ char op;
  textcolor(13);
  clrscr();
 gotoxy(30,5);printf(" ® MENU  ¯");
 gotoxy(15,9);printf("1.INTRODUCIR EST");
 gotoxy(15,10);printf("2.VISUALIZAR ESTUD");
 gotoxy(15,11);printf("3.INSERTAR         ");
 gotoxy(15,12);printf("4.ELIMINAR");
 gotoxy(15,13);printf("5.SALIR");
 gotoxy(22,14);printf("digite su opcion: " );

  textcolor(9);
 gotoxy(15,16);printf("GLORYS MARTINEZ       ");
 gotoxy(15,17);printf("INGENIERIA DE SISTEMAS");

  do
  {
	gotoxy(39,14);clreol(); op=getch();
	switch(op){
	case'1':intro();break;
	case'2':vis();break;
	case'3':insertar();break;
	case'4':eliminar();
	case'5':exit(0);
  }
  }while((op>5) ||(op<1));
}


//*******************************************
int validar(int k,int q)
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
				  if(!isdigit(cad[i])||(cad[i]=='¤'||cad[i]=='¥'))
					{
						gotoxy(k,q);
						clreol();
						gotoxy(k,q);
						swi=1;break;
					}
				 }
	}while(swi==1);
	return(atoi(cad));
	}


/***************************/

void intro()
{

clrscr();
gotoxy(10,8);
  printf("Digite el codigo : ");
	gotoxy(30,8);
	  cod=validar(30,8);
	 {flushall();}

		gotoxy(15,9);cprintf("digite el nombre: ");
		gets(nom);
		 nn=memoria;
		nn->cod=cod;
		strcpy(nn->nom,nom);
	if(cabeza==NULL)
	  {
		 p=memoria;
		  cabeza=p;
		  p->enlace=nn;
		  nn->enlace=cabeza;

	  }
		else
		{
		 p=cabeza->enlace;
		 nn->enlace=p;
		 cabeza->enlace=nn;
		}


menu();
}
/*********************************/
void eliminar()
{
  struct nombre *cabeza,*p,*q;
  clrscr();
 if(cabeza==NULL)
	{ clrscr();
	  gotoxy(25,5);printf("NO SE ENCUENTRAN DATOS");


	  gotoxy(25,15);printf("PULSA <<ENTER>> ");
	 getche();
	 }
	 if(cabeza!=NULL)
	 {
		clrscr();
		gotoxy(5,8);printf("DOGITE CODIGO A ELIMINAR..      ");
			gotoxy(30,8);
	  cod=validar(30,8);
	 {flushall();}


			 p=cabeza->enlace;


	  while(p!=cabeza)
	  {
		 if(p->cod==cod)
		 {
		  q->enlace=p->enlace;
		  free(p);
		  sw=1;
			if(p->enlace==cabeza)
			{
			 cabeza=NULL;break;
			 }

		  }
		q=p;
		p=p->enlace;

	 }

 if(sw==0)
 {textcolor(15+BLINK);
  gotoxy(10,15);printf("EL CODIGO %d", cod);
  gotoxy(10,16);cprintf("NO EXISTE");
	 gotoxy(10,19);printf("PULSA <<ENTER>> ");

getch();
}
getch();
 menu();
 }
 }
//*********************************
void insertar()
{    char nombre[15];
	 int codigo;
  char op,n;
	 int i,x,sw;
	p=cabeza;
if(cabeza==NULL){
clrscr();
gotoxy(6,4);printf("NO HAY DATOS");
getche();
	 }
	 if(cabeza!=NULL){
clrscr(); sw=0;
gotoxy(5,6);printf("DIGITE CODIGO A INSERTAR[      ]");
	gotoxy(30,6);
	  codigo=validar(30,6);
	 {flushall();}


p=cabeza->enlace;
while(p!=cabeza){
if(p->cod!=cod){
clrscr();
gotoxy(10,6);printf("DIGITR CODIGO  ");
	gotoxy(30,6);
	  codigo=validar(30,6);
	 {flushall();}

gotoxy(20,13);printf("DIGITE NOMBRE  ");
gotoxy(40,13);gets(nombre);

p->cod=cod;
strcpy(p->nom,nom);
sw=1;
	}
p=p->enlace;
}
}
if(sw==0){
gotoxy(14,23);printf("El CODIGO %d", codigo);
gotoxy(18,24);printf("NO EXISTE");
getche();

}

getch();
menu();
}



/*************************************/

void vis()
{
	int g=4;
	textcolor(14);
	clrscr();
	p=cabeza->enlace;

	 while(p!=cabeza)
	 { gotoxy(25,g);
	  printf("\t      %d  \n",p->cod);
	  gotoxy(16,g);
	  printf("%s  \t ",p->nom);
	  p=p->enlace;
	  g++;
	 }

 getch();
 menu();
}


/****************************************************************/
		 void main()
		 {
	 menu();
		 }
//********************************************


