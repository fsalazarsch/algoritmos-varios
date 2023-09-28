#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include <io.h>
struct notas
{ float nota;
  struct notas *sig_not;
}notas;

struct nodo
 {
   char codigo[9];
   char nombre[20];
   char apellido[20];
   char sexo ;
   struct nodo *sig;
   struct notas *enla_not;
}uba;

char cadena[1000][20];
int swi;
char res,opcion;
char codi[9],nom[20],ape[20],sex;
float not[6];
int n,swic,i,cont;
struct nodo *ptr,*p,*nn,*pe,*pl,*q;
struct notas *nn2,*pn;
void cuadro(int x1,int x2,int y1,int y2);
void pantalla();
void menu_principal();
void intro_not();
void meter();
void eliminar();
void modificar();
void modinom();
void modiape();
void modisex();
void modinota();
void leer();
void visualizar();
void listado_general();
void panta();
void marco(int x1,int y1,int x2,int y2);
void escribir(int x1, int n, int p, int op);
/*************************************************************/
void main()
	   {
	   clrscr();
	  // panta();
	  menu_principal();
	   }
/************************************************************/
void cuadro(int x1,int x2,int y1,int y2)
{    int j,i,k;
      textbackground(4);
     for(j=x1;j<=x2;j++)
       { delay(10);
       gotoxy(j,y1);cprintf("Ä");
       gotoxy(j,y2);cprintf("Ä");
       }
     for(i=y1;i<=y2-1;i++)
       {  delay(10);
       gotoxy(x1,i);cprintf("³");
       gotoxy(x2,i);cprintf("³");
       }
     gotoxy(x1,y1);cprintf("Ú");
     gotoxy(x2,y1);cprintf("¿");
     gotoxy(x1,y2);cprintf("À");
     gotoxy(x2,y2);cprintf("Ù");
    
} 

/***********************************************************************/
void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);} 
  }

/**********************************************************************/
void cuad_visual(int x1, int y1, int x2, int y2, int op)
{int i;
 marco(x1,y1,x2,y2);
 textcolor(15);
 for(i=x1;i<=x2;i++)
 { gotoxy(i,y1+2);
   if(i==x1)cprintf("Ã");else
   if(i==x2)cprintf("´");else
   cprintf("Ä");
 }
 for(i=y1;i<=y2;i++){
  if(i==y1)escribir(x1,194,i,op);else  
  if(i==y2)escribir(x1,193,i,op);else
  if(i==y1+2)escribir(x1,197,i,op);else
  escribir(x1,179,i,op);}
 textcolor(14);
 gotoxy(x1+2,y1+1);cprintf("CODIGO");
 gotoxy(x1+10,y1+1);cprintf("SEXO");
 gotoxy(x1+19,y1+1);cprintf("NOMBRE");
 gotoxy(x1+34,y1+1);cprintf("APELLIDO");
 if(op==2)
 {  gotoxy(x1+47,y1+1);cprintf("NOTA.1");
    gotoxy(x1+54,y1+1);cprintf("NOTA.2");
    gotoxy(x1+61,y1+1);cprintf("NOTA.3");
    gotoxy(x1+68,y1+1);cprintf("NOTA.4");
    gotoxy(x1+75,y1+1);cprintf("DEF.");}
  }
void escribir(int x1, int n, int p, int op)
{ textcolor(15);
  gotoxy(x1+9,p);cprintf("%c",n);
  gotoxy(x1+14,p);cprintf("%c",n);
  gotoxy(x1+30,p);cprintf("%c",n);
 if(op==2)
 { gotoxy(x1+46,p);cprintf("%c",n);
   gotoxy(x1+53,p);cprintf("%c",n);
   gotoxy(x1+60,p);cprintf("%c",n);
   gotoxy(x1+67,p);cprintf("%c",n);
   gotoxy(x1+74,p);cprintf("%c",n);
 }
}
/************************************************************/
void menu_principal()
{
  do{
     do{
       clrscr();
       textbackground(12);
       textcolor(15);
       cuadro(20,60,6,20);
       gotoxy(38,7);
       cprintf("MENU");
       gotoxy(28,9);
       cprintf("1.DATOS DEL ESTUDIANTE\n");
       gotoxy(28,10);
       cprintf("2.VISUALIZAR\n");
       gotoxy(28,11);
       cprintf("3.LISTADO GENERAL\n");
       gotoxy(28,12);
       cprintf("4.ELIMINAR\n");
       gotoxy(28,13);
       cprintf("5.MODIFICAR \n");
       gotoxy(28,14);
       textcolor(14);
       cprintf("6.NOTAS DEL ESTUDIANTE\n");
       gotoxy(28,15);
       textcolor(15);
       gotoxy(28,16);
       cprintf("7.SALIR\n");
       cprintf("DIGITE LA OPCION   [ ]");
       gotoxy(48,15);
       res=getche();
       }while(res< '1' || res > '7');
	switch(res)
		{
	       case '1':
			meter();
			break;
	       case '2':
			visualizar();
			break;
	       case '3':
			listado_general();
			break;
	       case '4':
			eliminar();
			break;
	       case '5':
			modificar();
			break;
	       case '6':
			intro_not();
			break;

		 }
	  }while(res != '7');
      }	     
/*********************************************************************/
 void meter() {

	   
		clrscr();do{clrscr();
		textbackground(12);
		leer();
		nn=malloc(sizeof(uba));
		strcpy(nn->codigo,codi);
		strcpy(nn->nombre,nom);
		strcpy(nn->apellido,ape);
		nn->sexo=sex;
		nn->sig=NULL;
		if(ptr==NULL){
		  ptr=nn;
		  p=ptr;
		}
		else
		  {
		    p=ptr;
		    while(p->sig!=NULL)
			 p=p->sig;
			 p->sig=nn;
		    
		   }
		   
			gotoxy(3,11);
		       printf("desea ingresar un nueva lista (S/N):");
			     opcion=getche();
			     opcion=toupper(opcion);
			  }
		      while(opcion=='S');
		   
	       
	  }
/*************************************************************************/
void leer(){

	do
	 {
	  swi=0;
	  clrscr();
	  cuadro(2,70,2,20);
	  gotoxy(3,4);
	  cprintf("-------------------------------------------------------------------");
	  gotoxy(20,3);
	  printf("INTRODUZCA DATOS DEL ALUMNO");
	  gotoxy(3,6);
	  textbackground(12);
	  textcolor(15);
	  cprintf("CODIGO...:");
	  scanf("\n");
	  textbackground(0);
	  gets(codi);
	  strcpy(cadena[n],codi);
	  if(n!=0)
	     for(i=0;i<n;i++)
		 if(strcmp(codi,cadena[i])==0)
		 {
		   gotoxy(20,15);
		   printf("el codigo existe\a");
		   delay(1000);
		   swi=1;
		   break;
		   }
		   else
		    swi=0;
		}
		while(swi!=0);
		gotoxy(3,7);
		printf("NOMBRE...:");
		gets(nom);
		gotoxy(3,8);
		printf("APELLIDO...:");
		gets(ape);
		gotoxy(3,9);
		printf("SEXO.[F/M]..:");
		scanf("%c",&sex);
		sex=toupper(sex);
		n++;
	  }
/*************************************************************************/
void intro_not()
       {
	 clrscr();

       printf("digite codigo...:");
	       scanf("\n");
	  textbackground(0);
	  gets(codi);
	  strcpy(cadena[n],codi);
	  if(n!=0)
	     for(i=0;i<n;i++)
		 if(!strcmp(codi,cadena[i])==0)
		 {
		   
		   printf("el codigo existe\a");

		   printf("nombre:");
		   printf("%s\n",p->nombre);
		   printf("apellido:");
		   printf("%s\n",p->apellido);
		   printf("sexo:");
		   scanf("%c",&sex);
		   if(p->enla_not != NULL)
		      printf("ya tiene notas");

		   else 
		      {
		       printf("1.parcial..:");
		       not[1];
		       printf("2.parcial..:");
		       not[2];
		       printf("3.parcial..:");
		       not[3];
		       printf("4.parcial..:");
		       not[4];
		       not[5]=not[1]*0.25+not[2]*0.25+not[3]*0.20+not[4]*0.30;
		       printf("definitiva:");
		       printf("%.2f\n",not[5]);
		       nn2=malloc(sizeof(notas));
			  nn2->nota=not[1];
			  nn2->sig_not=NULL;
			  p->enla_not=nn2;
			  pn=nn2;
			  for(i=2;i<=5;i++)
			     { nn2=malloc(sizeof(notas));
			       nn2->nota=not[i];
			       nn2->sig_not=NULL;
			       pn->sig_not=nn2;
			       pn=nn2;
			       }
			     }}	   

			 }
/*************************************************************************/
void modificar()
{
  do{
     do{
       clrscr();
       textbackground(13);
       textcolor(15);
       cuadro(20,60,6,20);
       gotoxy(30,7);
       cprintf("MENU MODIFICAR");
       gotoxy(28,11);
       cprintf("1.MODIFICAR NOMBRE\n");
       gotoxy(28,12);
       cprintf("2.MODIFICAR APELLIDO\n");
       gotoxy(28,13);
       cprintf("3.MODIFICAR SEXO\n");
       gotoxy(28,14);
       cprintf("4.MODIFICAR NOTAS\n");
       gotoxy(28,15);
       textcolor(14);
       cprintf("5.REGRESAR A MENU PRINCINPAL");
       gotoxy(28,16);
       textcolor(15);
       printf("DIGITE LA OPCION   [ ]");
       gotoxy(48,16);
       res=getche();
       }while(res< '1' || res > '5');
	switch(res)
		{
	       case '1':
			modinom();
			break;
	       case '2':
			modiape();
			break;
	       case '3':
			modisex();
			break;
	       case '4':
		       //modinota();
			break;
		 }
	  }while(res != '5');
      }	     

/*************************************************************************/
void modinom()
 {
   char codm[9],op;
   int a;
      
	p=ptr;
	clrscr();do{clrscr();
	textbackground(12);
	window(9,17,23,50);
	printf("DIGITE EL CODIGO DEL NOMBRE MODIFICAR...:");
	scanf("\n");
	gets(codm);
	a=0;
	while(p!=NULL)
	 {
	  if(strcmp(codm,p->codigo)==0)
	    {
	     clrscr();
	     printf("DIGITE EL NUEVO NOMBRE...:");
	     gets(nom);
	     strcpy(p->nombre,nom);
	     a++;
	     break;
	    }
	    p=p->sig;
	  }
	  if(a==0)
	     {
	      gotoxy(1,2);
	      printf("EL CODIGO NO EXISTE ");
	      getch();
	    }

	    
	    
	 
	    printf("desea seguir modificar otro (S/N):");
		  opcion=getche();
		  opcion=toupper(opcion);
		  }
		  while(opcion=='S');
	    
	   
	 } 
/*************************************************************************/
void modiape()
{
  char codm[9],op;
   int a;
       
	p=ptr;
	clrscr();do{clrscr();
	textbackground(12);
	window(1,80,1,24);
	printf("DIGITE EL CODIGO DEL APELLIDO A  MODIFICAR...:");
	scanf("\n");
	gets(codm);
	a=0;
	while(p!=NULL)
	 {
	  if(strcmp(codm,p->codigo)==0)
	    {
	     clrscr();
	     printf("DIGITE EL NUEVO APELLIDO...:");
	     gets(ape);
	     strcpy(p->apellido,ape);
	     a++;
	     break;
	    }
	    p=p->sig;
	  }
	  if(a==0)
	     {
	      gotoxy(1,2);
	      printf("EL CODIGO NO EXISTE ");
	      getch();
	    }

	    printf("desea seguir modificar otro (S/N):");
		  opcion=getche();
		  opcion=toupper(opcion);
		  }
		  while(opcion=='S');
	    
	 } 
/************************************************************************/
void modisex()
{
 char codm[9],op;
   int a;
      
	p=ptr;
	clrscr();do{clrscr();
	textbackground(12);
	window(1,80,1,24);
	printf("DIGITE EL CODIGO DEL SEXO A MODIFICAR...:");
	scanf("\n");
	gets(codm);
	a=0;
	while(p!=NULL)
	 {
	  if(strcmp(codm,p->codigo)==0)
	    {
	     clrscr();
	     printf("DIGITE EL NUEVO SEXO...:");
	     scanf("%c",&sex);
	     sex=toupper(sex);
	     nn->sexo=sex;
	     a++;
	     break;
	    }
	    p=p->sig;
	  }
	  if(a==0)
	     {
	      gotoxy(1,2);
	      printf("EL CODIGO NO EXISTE ");
	      getch();
	    }

	    
	    printf("desea seguir modificar otro (S/N):");
		  opcion=getche();
		  opcion=toupper(opcion);
		  }
		  while(opcion=='S');
	    
	 } 

/*************************************************************************/
void visualizar() {
	   char codi[9],op;
	   int a;

	     p=ptr;
	     clrscr();do{clrscr();
	     printf("ESCRIBA EL CODIGO A CONSULTAR...:");
	     gets(codi);
	     while(p!=NULL){
		  if(strcmp(codi,p->codigo)==0){
		    cuad_visual(1,1,80,6,2);
		    gotoxy(2,4);
		    printf("%s",p->codigo);
		    gotoxy(16,4);
		    printf("%s",p->nombre);
		    gotoxy(32,4);
		    printf("%s",p->apellido);
		    gotoxy(12,4);
		    printf("%c",p->sexo);
		    a++;
		    getch();
		    break;
		}
		p=p->sig;
	       }
	       if(a==0){
		  gotoxy(20,20);
		  printf("verifique bien su codigo \n");
		  getch();
		  }
		       
		       gotoxy(20,21);
		       printf("desea seguir consultando (S/N):");
			     opcion=getche();
			     opcion=toupper(opcion);
			  }
		      while(opcion=='S');
		   
	      
	  }
/********************************************************************/
void listado_general()
  {
  int a;
  p=ptr;
   clrscr();
   cuad_visual(1,1,80,21,2);
   a=4;
   while(p!=NULL)
    {
     gotoxy(2,a);
     printf("%s\n",p->codigo);
     gotoxy(16,a);
     printf("%s\n",p->nombre);
     gotoxy(32,a);
     printf("%s\n",p->apellido);
     gotoxy(12,a);
     printf("%c\n",p->sexo);
     p=p->sig;
     a++;
   
    }
    getch();
    clrscr();
    
 }
/**************************************************************************/
void eliminar()
{int i;
char code[9],opc;
	   
	    clrscr();do{clrscr();
	    printf("DIGITE EL CODIGO A ELIMINAR...:");
	    scanf("\n");
	    printf("\n");
	    gets(code);
	    for(i=0;i<n;i++)
	       if(strcmp(cadena[i],code)==0)
		 strcpy(cadena[i]," ");
		 pe=ptr;
		 pl=pe->sig;
		 for(i=1;i<=n;i++)
		     {
		     if((pe==ptr) && (strcmp(code,pe->codigo)==0))
		       {
			ptr=pl;
			clrscr();
		
			printf("estudiante a eliminar");
		      }
		      else
			  if((strcmp(code,pe->codigo)==0)&&(pe!=ptr))
			    {
			     p=ptr;
			     while(p!=NULL)
			     {
			       if(p->sig==pe)
			      {
				p->sig=pe->sig;
				clrscr();
				gotoxy(20,10);
				printf("el estudiante a eliminar");
				delay(200);
				}
				p=p->sig;
			       }
			       }
			       pe=pl;
			       pl=pe->sig;
			       clrscr();
			       gotoxy(25,15);
			       delay(2000);
			       printf("ALUMNO ELIMINADO\a");
			       getche();
			      }
				  gotoxy(20,20);
				  printf("desea seguir consultando (S/N):");
				      opcion=getche();
				      opcion=toupper(opcion);
				 }
			while(opcion=='S');
		     
	   }
/**************************************************************************/
