#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream.h>
class lista
{
struct persona
{
   char cod[9],nom[15],ape[15];
   struct persona *enlace;
};
public:
struct persona *nn,*ptr,*p;
char cod[10],nom[20],ape[20],op[2];
int sw,i;

void insertar();
lista(struct persona *e);
void visualizar();
void menu();
};


/******************************************************/

void lista::menu()
{ char op;
  textbackground(15);
  textcolor(4);
  clrscr();
 gotoxy(30,5);printf("  MENU PRINCIPAL ");
gotoxy(25,6);printf(" CORPORACION UNIVERSUTARIA ");
gotoxy(36,7);printf(" DEL ");
gotoxy(33,8);printf(" SANTANDER" );
 gotoxy(20,10);printf("1.INTRODUCIR PERSONA :");
 gotoxy(20,12);printf("2.VISUALIZAR :");
 gotoxy(20,14);printf("3.SALIR  :");
 gotoxy(22,19);printf("DIGITE SU OPCION: " );
  do
  {
   gotoxy(39,19);clreol(); op=getch();
   switch(op){
   case'1':insertar();break;
   case'2':visualizar();break;
   case'3':exit(0);
  }
  }while((op>3) ||(op<1));
}

/******************************************************/

void lista::insertar()
{ clrscr();
  printf("Digite el codigo : ");
  gets(cod);
  p=ptr; sw=0;
  while(p!=NULL)
   { if(!strcmp(cod,p->cod)) { sw=1; break; }
     p=p->enlace;
   }
  if(sw==0){
      cprintf("DIGITE EL NOMBRE :");
      gets(nom);
      cprintf("DIGITE EL APELLIDO : ");
      gets(ape);
      nn=new persona;
      strcpy(nn->cod,cod);
      strcpy(nn->nom,nom);
      strcpy(nn->ape,ape);
      nn->enlace=NULL;
      if(ptr==NULL) ptr=nn;
      else
      { nn->enlace=ptr;
	ptr=nn;
      }
    }else printf(" EL CODIGO YA EXISTE ");
menu();
}

/******************************************************/

void lista::visualizar()
{  clrscr();
   p=ptr;
   cprintf("DIGITE EL CODIGO A VISUALIZAR :");  scanf("\n");
   gets(cod);
   while(p!=NULL)
     { if(!strcmp(cod,p->cod))
       { printf("codigo %s\n",p->cod);
	 printf("persona %s\n",p->nom);
	 printf("apellido %s\n",p->ape);
	 break;
       }
       p=p->enlace;
     }
    getche();
    menu();
}

/******************************************************/
getche();
lista::lista(struct persona *e)
{ptr=e;}

void main()
{
 lista obj(NULL);
 obj.menu();
}


