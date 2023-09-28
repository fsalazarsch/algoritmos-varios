#include<stdio.h>
#include<string.h>
#include<alloc.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream.h>
class carlos
{struct notas
{ float not;
  struct notas *sig_not;
};

struct nombre
{
   char cod[9],nom[15],ape[15],sex[2];
   struct nombre *enlace;
   struct notas *enla_not;
};
public:
struct nombre *nn,*cabeza,*p;
struct notas *nn1,*p1;
char cod[9],nom[15],ape[15],sex[2],op[2];
int sw,i;
void intro();
carlos(struct nombre *e);
void vis();
void int_not();
void vis_gen();
void menu();
void mod_not();
void mod_nom();
};
void carlos::menu()
{ char op;
  textcolor(15);
  clrscr();
 gotoxy(30,5);printf(" ® MENU  ¯");
 gotoxy(15,9);printf("1.INTRODUCIR EST");
 gotoxy(15,10);printf("2.INTRODUCIR NOTAS");
 gotoxy(15,11);printf("3.VISUALIZAR ESTUD");
// gotoxy(15,12);printf("4.LISTADO GENERAL");
// gotoxy(15,13);printf("5.MODIFICAR NOMBRES");
// gotoxy(15,14);printf("6.MODIFICAR NOTAS");
 gotoxy(15,12);printf("4.ELIMINAR");
 gotoxy(15,13);printf("5.SALIR");
 gotoxy(22,14);printf("digite su opcion: " );
  do
  {
   gotoxy(39,14);clreol(); op=getch();
   switch(op){
   case'1':intro();break;
   case'2':int_not();break;
   case'3':vis();break;
  // case'4':vis_gen();break;
   //case'5':/*mod_nom();*/break;
  // case'6':/*mod_not();*/break;
   case'4':/*eliminar();   */
   case'5':exit(0);
  }
  }while((op>5) ||(op<1));
}


/**********************************************************************/

void carlos::intro()
{ clrscr();
  printf("Digite el codigo : ");
  gets(cod);
  p=cabeza; sw=0;
  while(p!=NULL)
   { if(!strcmp(cod,p->cod)) { sw=1; break; }
     p=p->enlace;
   }
  if(sw==0){
      cprintf("digite el nombre :");
      gets(nom);
      cprintf("digite el apellido : ");
      gets(ape);
      cprintf("digite su sexo : ");
      gets(sex);
      nn=new nombre;
      strcpy(nn->cod,cod);
      strcpy(nn->nom,nom);
      strcpy(nn->ape,ape);
      strcpy(nn->sex,sex);
      nn->enlace=NULL;
      nn->enla_not=NULL;
      if(cabeza==NULL) cabeza=nn;
      else
      { nn->enlace=cabeza;
	cabeza=nn;
      }
    }else printf(" el codigo ya existe ");
menu();
}



void carlos::vis_gen()
{  clrscr();
   p=cabeza;
   while(p!=NULL)
     { printf("codigo %s\n",p->cod);
       printf("nombre %s\n",p->nom);
       printf("apellido %s\n",p->ape);
       printf("sexo %s\n",p->sex);
       p1=p->enla_not;
       if(p1==NULL) printf(" no hay notas");
       else
       while(p1!=NULL)
       { printf("\pnota:  %.2f\n",p1->not);
	 p1=p1->sig_not;
       }
       printf("\n");
       p=p->enlace;
       getche();
     }
   menu();
}


void carlos::vis()
{  clrscr();
   p=cabeza;
   cprintf("Digite el codigo a visualizar :");  scanf("\n");
   gets(cod);
   while(p!=NULL)
     { if(!strcmp(cod,p->cod))
       { printf("codigo %s\n",p->cod);
	 printf("nombre %s\n",p->nom);
	 printf("apellido %s\n",p->ape);
	 printf("sexo %s\n",p->sex);
	 p1=p->enla_not;
	 if(p1==NULL) { printf("no hay notas "); break; }
	 else
	 while(p1!=NULL)
	  { printf("\nnota:  %.2f\n",p1->not);
	    p1=p1->sig_not;
  }
         break;
       }
       p=p->enlace;
     }
    getche();
    menu();
}

/****************************************************************/

void carlos::int_not()
{ float not[5],not1,not2,not3,not4,c,def;
clrscr();
  printf("digite el codigo: ");scanf("\n");
  gets(cod);
  p=cabeza; sw=0;
  while(p!=NULL)
   { if(!strcmp(cod,p->cod)) { sw=1; break; }
     p=p->enlace;
   }
 if(sw==0) printf("no existe");
  else{ printf("codigo %s\n",p->cod);
       printf("nombre %s\n",p->nom);
       printf("apellido %s\n",p->ape);
       printf("sexo %s\n\n",p->sex);

/***********************************************************************/   

       printf("digite la primera nota: ");

       scanf("%f",&not[1]);
       if(not1>=0||not1<=5);
       
       printf("%f",&not[1]);


	  do{

       printf("digite la segunda nota: ");
       scanf("%f",&not[2]);	
	if ((not2>=0)||(not2<=5))
	c=1;

	else
	c=0;
	}while(c!=1);
	do{

       printf("digite la tercera nota: ");
       scanf("%f",&not[3]);
       if((not3>=0)||(not3<=5))
       c=1;

       else
       c=0;

       }while(c!=1);
       do{

       printf("digite la cuarta nota: ");
       scanf("%f",&not[4]);
       if((not4>=0)||(not4<=5))
       c=1;

       else
       c=0;
       }
       while(c!=1);

       def=(not1*0.25+not2*0.25+not3*0.20+not4*0.30);
       printf("DEFINITIVA ES=======>%.2f/n ",def);


       nn1=new notas;
       nn1->not=not[0];
       nn1->sig_not=NULL;
       p->enla_not=nn1;
       p1=nn1;
       for(i=1;i<4;i++)
       { nn1=new notas;
	 nn1->not=not[i];
	 nn1->sig_not=NULL;
	 p1->sig_not=nn1;
	 p1=nn1;
       }

       }
       getche(); menu();
       }
       carlos::carlos(struct nombre *e)
       {cabeza=e;}

       void main()
       {carlos objeto(NULL);
       objeto.menu();
       }



