#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#define MAXIMO 30
#define memo (struct nodo *)malloc(sizeof(struct nodo))
/***************************************************************************/
struct NODO {
	     long codigo;
	     char *nombre;
	     struct NODO *izq;
	     struct NODO *der;
	   };
 struct NODO *ptr,*p,*q,*nuevo;
/***************************************************************************/
 char opcion;
 char X[20];
 char nombre[50];
 int W,J;
 int  buscar_nododoblecircular(long cod);
 long cod;
 void menu();
 void pisos();
 void pantalla();
 void insertar_doblecircular();
 void visualiza_doblecircular();
 void eliminar_doblecircular();
 void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux);
 void ventana(int X1,int Y1,int X2,int Y2);
/***************************************************************************/    
 void inserta_doblecircular()
 {
  int sw=0;
  clrscr();
  nuevo=new NODO;
    ventana(2,3,79,24);
    do
     {
     gotoxy(22,4);printf(">>>>>> REGISTRO  DE  ESTUDIANTES <<<<<<");
      gotoxy(10,7);printf("No. DE CODIGO: ");
      if(sw==1)
      {
       textcolor(14+128);gotoxy(24,14);cprintf("!!! CODIGO YA EXISTE !!!!");
       getch();
       clreol();
       clrscr();
      }validar_datos(25,7,2,nuevo);
     }while((sw=buscar_nododoblecircular(nuevo->codigo))==1);
      gotoxy(10,9);printf("NOMBRE DEL ESTUDIEANTE: ");
      validar_datos(34,9,1,nuevo);
      nuevo->izq=nuevo->der=NULL;
      if(ptr==NULL)
      {
	ptr=nuevo;
	nuevo->izq=ptr;
	nuevo->der=ptr;
      }
       else{
	    p=ptr;
	    while(p->der!=ptr)
	    {
	      p=p->der;
	    }
	      p->der=nuevo;
	      nuevo->der=ptr;
	      nuevo->izq=p;
	  }
	  do{
	      sw=0;
	      gotoxy(25,22);printf("DESEA INGRESAR OTRO [S_N]: ");
	      opcion=toupper(getch());
	      if(opcion=='S'||opcion =='N')
	      sw=1;
	     }while(sw!=1);
	      if(opcion=='S')inserta_doblecircular();
}
/****************************************************************************/
 void visualiza_doblecircular()
 {
   int fil;
   clrscr();
   if(ptr!=NULL){
    p=ptr;
     gotoxy(16,4);
     printf(">>>>>>>>>> VISUALIZACION  DE  LA  LISTA <<<<<<<<<< ");
     gotoxy(23,8);
     printf("No. CODIGO                       NOMBRE");
     fil=10;
     getch();
     while(p->der!=ptr)
     {
		 gotoxy(25,fil);printf("%ld\n",p->codigo);
		 gotoxy(56,fil);printf("%s\t",p->nombre);
		 getch();
		 p=p->der;
		 fil++;
		 }
		 if(p!=NULL){
		 gotoxy(25,fil);printf("%ld\n",p->codigo);
		 gotoxy(56,fil);printf("%s\t",p->nombre);
      
		 textcolor(14+128);gotoxy(30,23);cprintf("###### ENTER ######");
	 }
     }
	 else{
		clrscr();
		ventana(2,3,79,24);
		textcolor(14);
		gotoxy(16,6);cprintf("<<<<< NO  HAY  INFORMACION  QUE  VISUALIZAR >>>>>");
		gotoxy(10,15);
		cprintf("POR FAVOR PRESIONE ## ENTER ## PARA REGRESE AL MENU PRINCIPAL");
		textcolor(14+128);gotoxy(23,23);cprintf(">>>>> Y  ELIJA  OTRA  OPCION <<<<<");
	      }
	getch();
 }
/**************************************************************************/
 int buscar_nododoblecircular(long cod)
 {
  int sw=0;
  if(ptr==NULL)
   return 0;
   else
   {
    p=ptr;
    while(p->der!=ptr && sw==0){
    if(p->codigo==cod)
     sw=1;
     else
      p=p->der;
   }
     if(sw==1)
     return 1; 
     if(sw==0)
     if(p->codigo==cod)
     return 1;
 }
     return 0; 
}
/***************************************************************************/
void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux)
 {
   char *auxiliar;
   int sw=0,i,control;
   switch(tipo_captura)
   {
     case 1:
	   {
	    do{control=0;
			do{
			   gotoxy(posx,posy);
			   clreol();scanf("\n");gets(auxiliar);
			   for(i=0;i<=strlen(auxiliar)-1;i++)
			   if(isdigit(auxiliar[i])==0){
			   sw=1;break;}
			  }while(sw!=1);
			  if(sw==1){
			  control=sw;sw=0;
	  }

	     }while(control!=1);
			  strcpy(aux->nombre,auxiliar);
			  break;
  }
   case 2:
	 {
	  do{control=0;
		      do{
			gotoxy(posx,posy);clreol();scanf("\n");gets(auxiliar);
			for(i=0;i<=strlen(auxiliar)-1;i++)
			if(isdigit(auxiliar[i])==0){
			sw=1;break;}
		       }while(sw!=0);
			if(sw==1){
			control=sw;sw=0;
	 }
	    }while(control!=0);
			aux->codigo=atol(auxiliar);
			break;}
     }
 }
/**************************************************************************/
 void eliminar_doblecircular()
 {
  int sw=0;
  clrscr();
   ventana(2,3,79,24);
   gotoxy(22,5);printf(">>>>>>>>>> ELIMINAR  REGISTROS <<<<<<<<<<");
   gotoxy(10,8);printf("CODIGO A ELIMINAR: ");
   do
   {
    W=0;J=0;
    gotoxy(29,8);clreol();gets(X);
    while(X[W]!='\0')
    {
     if(X[W]<'0'||X[W]>'9')
     J=-1;
     W++;
    }
   }while(J==-1);
    cod=atol(X);
      p=ptr;
      q=NULL;
     while(p->der!=ptr && sw==0)
	if(p->codigo==cod)
	 sw=1;
     else
     {
       q=p;
       p=p->der;
     }
      if(q==NULL){
      if(p->der==ptr&&p->codigo==cod&&sw==0)
      ptr=NULL;
    else
     if(p->der!=ptr&&p->codigo==cod&&sw==1)
     {
       q=p->izq;
       q->der=p->der;
       q=q->der;
       q->izq=p->izq;
       ptr=p->der;
       delete(p);
     }
   }else
       if(p->der==ptr&&p->codigo==cod&&sw==0)
       {
	q->der=p->der;
	q=q->der;
	q->izq=p->izq;
	delete(p);
      }   
     else{
	 if(sw==1){
		   q->der=p->der;
		   q=q->der;
		   q->izq=p->izq;
		   delete(p);
		 }
	}
	do{
	   sw=0;
	   gotoxy(25,22);printf("DESEA ELIMINAR OTRO [S_N]: ");
	   opcion=toupper(getch());
	   if(opcion=='S'||opcion =='N')
	   sw=1;
	  }while(sw!=1);
	   if(opcion=='S')
	  eliminar_doblecircular();
       }
/***************************************************************************/
 void ventana(int X1,int Y1,int X2,int Y2)
 {
  int i;
 for(i=X1+1;i<X2;i++){
  gotoxy(i,Y1);printf("Í"); 
  gotoxy(i,Y2);printf("Í");} 
 for(i=Y1+1;i<Y2;i++){
  gotoxy(X1,i);printf("º");   
  gotoxy(X2,i);printf("º");}  
  gotoxy(X1,Y1);printf("É");
  gotoxy(X1,Y2);printf("È");
  gotoxy(X2,Y1);printf("»");
  gotoxy(X2,Y2);printf("¼");
}
/***************************************************************************/
 void pantalla()
 {
  textcolor(13);
  delay(40);
  ventana(1,3,80,22);
 }
/***************************************************************************/
void main()
{
  menu();
}	
/****************************************************************************/
void menu()
{
  pantalla();
  clrscr();
  ventana(28,6,50,15);
  pisos();
  int n,j;
  int tecla,f;
  char opciones[35][45];
  clrscr();
  textbackground(1); 
  strcpy(opciones[11],"  INSERTAR ESTUDIANTES  ");
  strcpy(opciones[12]," VISUALIZAR ESTUDIANTES ");
  strcpy(opciones[13],"  ELIMINAR ESTUDIANTES  ");
  strcpy(opciones[14],"  SALIR DEL SISTEMA    ");
 do
  {
   pisos();
   for(f=11;f<=14;f++)
   {
    textcolor(15);
    gotoxy(28,f);cprintf(opciones[f]);
   }
    f=11;
    textcolor(15);
    textbackground(1); 
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(15); textbackground(1);
   do
   {
   _setcursortype(_NOCURSOR);
   do
   { 
     tecla=getch(); 
   }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
     if(tecla==80)
     {
      _setcursortype(_NOCURSOR);
      textcolor(15);
      textbackground(1);
      gotoxy(28,f);cprintf(opciones[f]);
      if(f!=14)
       f=f+1;
       else
	f=11;
	textcolor(0);
	textbackground(11);
	gotoxy(28,f);cprintf(opciones[f]);
	textcolor(15);textbackground(1);
  }
    if(tecla==72)
    {
      textcolor(15);textbackground(1);
      gotoxy(28,f);cprintf(opciones[f]);
      textcolor(15);
      _setcursortype(_NOCURSOR);
      if(f!=11)
       f=f-1;
       else
	f=14;
	textcolor(15);
	textbackground(1); 
	gotoxy(28,f);cprintf(opciones[f]);
	textcolor(15);textbackground(1);
     }
  } 
     while(tecla!=13);
     switch(f)
     {
       case 11:_setcursortype(_SOLIDCURSOR);
	      inserta_doblecircular();pisos();break;
       case 12:_setcursortype(_SOLIDCURSOR);
	       visualiza_doblecircular();pisos(); break;
       case 13:_setcursortype(_SOLIDCURSOR);
	       eliminar_doblecircular();pisos(); break;
       case 14:_setcursortype(_SOLIDCURSOR);break;
   }
 }
  while(f!=14);
} 
/****************************************************************************/
void marco(int x1,int y1,int x2,int y2)
{
  int n;
  textcolor(15);
  gotoxy(x1, y1); cprintf("%c",201); 
  gotoxy(x2, y1); cprintf("%c",187);   
  gotoxy(x1, y2); cprintf("%c",200);  
  gotoxy(x2, y2); cprintf("%c",188); 
  for(n=(x1+1);n<=(x2-1);n++)
  {
    gotoxy(n,y1);cprintf("%c",205);
    gotoxy(n,y2);cprintf("%c",205);
  } 
  for(n=(y1+1);n<=(y2-1);n++)
  {
    gotoxy(x1,n);cprintf("%c",186);
    gotoxy(x2, n);cprintf("%c",186);
  } 
}
/***************************************************************************/
void pisos()
{
 int n,j;
 clrscr();
 textbackground(4);
 clrscr();
 gotoxy(14,4);textcolor(15);
 cprintf("CORPORACION  UNIVERSITARIA  DE  SANTANDER <<< UDES >>>");
 gotoxy(30,6);textcolor(15);cprintf("ESTRUCTURA  DE   DATOS");
 gotoxy(24,5);textcolor(15);cprintf("ING. DALILA MICHELA BRACHO ACOSTA");
  for(n=2;n<=24;n++)
  gotoxy(28,9);textcolor(15);cprintf(">>>> MENU PRINCIPAL <<<<");
  textcolor(14+128);gotoxy(14,19);
  cprintf("UTILICE LAS TECLAS DEL CURSOR  Y  PRESIONE ® ENTER ¯ ");  
  marco(13,18,65,20);
  marco(26,7,53,16);
  marco(5,2,75,22);
}
/****************************************************************************/
	  //CORPORACION UNIVERSITARIA  DE  SANTANDER << U D E S>>
		  //FACULTAD  INGENIERIA  DE  SISTEMAS
	     //DALILA MICHELA BRACHO ACOSTA  COD. 96132018
		   //VALLEDUPAR NOVIEMBRE 10 DE 1998
/****************************************************************************/
