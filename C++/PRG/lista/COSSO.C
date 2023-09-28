# include<alloc.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
# define localizar (struct nodo*)malloc(sizeof(struct nodo));
#define p1( x ) printf (" %d ", x )
      char opc;
		void insdes();
			void eliminar();
	void cuadro();
	void captura();
	void insantes();
struct nodo{
   int info;
   struct nodo*sig;
   };
   struct nodo*cab,*q,*p,*nuevo;
   int nu,num;
   char op;
   void captura()
   {
   char op;
  clrscr();
   cab=NULL;
   do{
   clrscr();
   printf("digite un numero de lista: ");
   scanf("%d",&nu);

   q=localizar;
   q->info=nu;
   q->sig=cab;
   cab=q;
   p=cab;

	printf("seguir (s/n) ?:  " );
   op=toupper(getche());

   }while(op!='N');
   p=cab;
   printf("\n\n");
   while(p!=NULL)
   {

   p1 (p->info);
   p=p->sig;
}
getch();
   }

     void cuadro()
{ int c,f;

textcolor(15);gotoxy(31,8);cprintf("***MENU PRINCIPAL***");

for(c=16;c<65;c++)
    {
     gotoxy(c,6);cprintf("Í");
     gotoxy(c,12);cprintf("Í");
     gotoxy(c,25);cprintf("Í");
    }

   for(f=6;f<25;f++)
    {gotoxy(15,f);cprintf("º");
     gotoxy(65,f);cprintf("º");
    }
					    /*ESQUINAS*/
    gotoxy(15,6);cprintf("É");
    gotoxy(65,6);cprintf("»");
    gotoxy(15,12);cprintf("Ì");
    gotoxy(65,12);cprintf("¹");
    gotoxy(15,25);cprintf("È");
    gotoxy(65,25);cprintf("¼");

}

void main()

{
 while(1)
  {
  clrscr();
  cuadro();
  textbackground(12);
 // textcolor(10);

  gotoxy(16,7);cprintf("      CORPORACION UNIVERCITARIA DE SANCANDER");
  gotoxy(16,8);cprintf("        FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(16,9);cprintf("             EMILIANO ALFONSO SANCHEZ");
  gotoxy(16,10);cprintf("                   CURSO S3A	");

  gotoxy(20,14);cprintf("            1.CAPTURAR");
  gotoxy(20,15);cprintf("            2.INSERTAR DESPUE");
  gotoxy(20,16);cprintf("            3.INSETAR ANTES");
  gotoxy(20,17);cprintf("            4.ELIMINAR NODO");
  gotoxy(20,18);cprintf("            5.SALIR");
  gotoxy(24,23);cprintf("DIGITE LA OPCION [ ]");

  gotoxy(42,23);opc=getchar();
  switch(opc)
   {
   case'1':clrscr();captura();break;
   case'2':clrscr();insdes();break;
	case'3':clrscr();insantes();break;
	case'4':clrscr();eliminar();break;
	case'5':return;
	}
  }
}
void insdes()
{
int sw=0;
do{
clrscr();
printf("digite el numero de referencia");
scanf("%d",&nu);
printf("digite el numero a insertar ");
scanf("%d",&num);

p=cab;

while(p!=NULL){


if(p->info==nu){
nuevo=localizar;
nuevo->info=num;
nuevo->sig=p->sig;
p->sig=nuevo;
sw=1;
break;
}
p=p->sig;
}

if (sw==0){printf(" numero de referencia  no existente");}

else{
 p=cab;
   printf("\n\n");
   while(p!=NULL)
   {

   p1 (p->info);
   p=p->sig;
}

}
printf("\n\n");
   sw=0;
	printf("continuar(s/n) ?:  " );
   op=toupper(getche());

  }while(op!='N');
 getche();

}
	void insantes()
 
 {
int sw=0;
do{
clrscr();
printf("digite el numero de referencia");
scanf("%d",&nu);
printf("digite el numero a insertar ");
scanf("%d",&num);

p=cab;

while(p!=NULL){


if(p->info==nu){
nuevo=localizar;
nuevo->info=p->info;
nuevo->sig=p->sig;
p->sig=nuevo;
p->info=num;
sw=1;
break;
}
p=p->sig;
}

if (sw==0){printf(" numero de referencia  no existente");}

else{   
 p=cab;                    
	 printf("\n\n");
   while(p!=NULL)
   {

   p1 (p->info);
   p=p->sig;
}

}
printf("\n\n");
   sw=0;
	printf("continuar(s/n) ?:  " );
   op=toupper(getche());

  }while(op!='N');
 getche();
}
	void eliminar()
	{
int sw=0;
do{
clrscr();
printf("digite el numero de referencia");
scanf("%d",&nu);
//printf("digite el numero a insertar ");
//scanf("%d",&num);

p=cab;

while(p!=NULL){


//if(p->info==nu){
q=p->sig;
nu=q->info;
p->sig=q->sig;
free(q);  
sw=1;
break;

p=p->sig;
}

if (sw==0){printf(" numero de referencia  no existente");}

else{
 p=cab;
   printf("\n\n");
   while(p!=NULL)
   {

   p1 (p->info);



	p=p->sig;
}

}
printf("\n\n");
   sw=0;
   printf("seguir (s/n) ?:  " );
   op=toupper(getche());

  }while(op!='N');

 getche();
}
