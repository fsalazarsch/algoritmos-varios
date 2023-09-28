#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#define memo (struct nodo *)malloc(sizeof(struct nodo))
/****************************************************************************/
struct nodos
{
  char nom[20],cod[10],apell[20];
  struct nodos *ant;
  struct nodos *sig;
};
/****************************************************************************/
  int sw;
  nodos *nn,*p,*ptr;
  char nom[20],cod[10],apell[20],opcion;
  void adicionar();
  void visualizar();
  void eliminar();
  void visualiza_gral();
  void pisos();
  void pantalla();
  void rango(char p[25]);
  void menu();
  void ventana(int X1,int Y1,int X2,int Y2);
  long int val_int(int x,int y);
  char *validar_cod(int x,int y);
  char *validar_nom(int y,int x);
  char *validar_apell(int y,int x);
/****************************************************************************/
void rango(char p[25])
{
  window(3,22,70,22);clrscr();textcolor(14+128);
  gotoxy(25,1);cprintf("%s",p);delay(1500);
  clrscr();window(1,1,80,25);textcolor(9);
}
/****************************************************************************/
long int val_int(int x,int y)
{
  
  int n,i;
   char cad[20];
    void menu();

   do
   {
     gotoxy(x,y);clreol();
     gets(cad);sw=0;
     n=strlen(cad);
     if(n>5)
     {
      sw=1;rango("!!!CODIGO FUERA DE RANGO!!!");
     }
      for(i=0;i<n;i++)
       if(!isdigit(cad[i]))
       {
	sw=1;break;
       }
    }while(sw==1);
     return(atoi(cad));
}
/****************************************************************************/
char *validar_cod(int x,int y)
{ 
  int n,i;
  char cad[20];
  do
  {
   gotoxy(x,y);clreol();
   gets(cad);sw=0;
   n=strlen(cad);
   if(n>7){sw=1;rango("!!!CODIGO FUERA DE RANGO!!!");}
   for(i=0;i<n;i++)
    if(!isalnum(cad[i]))
    {
     sw=1;break;
    }
   }while(sw==1);
    return(strupr(cad));
}
/****************************************************************************/
char *validar_nom(int y, int x)
{
  int i,n;
  char nombre[20];
  do
  {
    gotoxy(y,x);
    sw=0;window(45,6,78,6); 
    gets(nombre);window(1,1,80,25); 
    if((n=strlen(nombre))>20)
    {
     sw=1;rango("!!!NOMBRE FUERA DE RANGO!!!");}
     else{
     for(i=0;i<n;i++)
      if(!isalpha(nombre[i]))
      {
	sw=1;rango("!!!NOMBRE ERRADO!!!");
      }
	    
    }
  }while(sw==1);
   return(strupr(nombre));
}
/****************************************************************************/
char *validar_apell(int y,int x)
{
  int i,n;
  char apellido[20];
  do
  {
    gotoxy(y,x);sw=0;window(45,6,78,6); 
    clreol();
    gets(apellido);window(1,1,80,25); 
    if((n=strlen(apellido))>20)
    {
      sw=1;rango("!!!APELLIDO FUERA DE RANGO!!!");
    }
     else{
      for(i=0;i<n;i++)
       if(!isalpha(apellido[i]))
       {
	sw=1;rango("!!!APELLIDO ERRADO!!!");
       }
    }
  }while(sw==1);
   return(strupr(apellido));
}
/****************************************************************************/
void insertar()
{
 do
 {
   clrscr();ventana(2,2,79,24);
   gotoxy(23,4);printf(">>>>>>>>>> DATOS DEL CLIENTE <<<<<<<<<< ");
   gotoxy(15,6);printf("No. DE CODIGO: ");
   strcpy(cod,validar_cod(30,6));
   p=ptr;
   sw=0;
   while(p!=NULL)
   {
    if(strcmp(cod,p->cod)==0)
    {
     sw=1;break;
    }
     p=p->sig;
  }
    if(sw==1)
    {
      textcolor(14+128);gotoxy(30,12);cprintf("!!! YA EXIXTE !!!");
    } 
     else{
     gotoxy(15,8);printf("NOMBRE: ");scanf("\n"); 
     strcpy(nom,validar_nom(30,8));
     gotoxy(15,10);printf("APELLIDO: ");scanf("\n");
     strcpy(apell,validar_apell(30,10));
     nn=new nodos;
     strcpy(nn->cod,cod);
     strcpy(nn->nom,nom);
     strcpy(nn->apell,apell);
     nn->sig=nn->ant=NULL;
     if(ptr==NULL)
	ptr=nn;
	else
	{
	 p=ptr;
	 while(p->sig!=NULL)
	 p=p->sig;
	 p->sig=nn;
	 nn->ant=p;
	}
	    rango("!!!!!! REGISTRO ADICIONADO !!!!!!");
      }
      gotoxy(22,21);printf("DESEA ADICIONAR OTRO REGISTRO [S/N]: ");
      opcion=toupper(getche());
  }while(opcion=='S');
}
/****************************************************************************/
void visualizar()
{  
  int fil;
  if(ptr==NULL)
  {
   clrscr();ventana(2,2,79,24);
   gotoxy(18,10);cprintf("ญญญ NO SE PUEDE VISUALIZAR NO HAY REGISTROS !!!");
   gotoxy(12,13);cprintf(">>>> POR FAVOR DIGITE ### ENTER ### Y REGRESE AL MENU <<<<"); 
  }
   else
   {
     p=ptr;clrscr();fil=8;
     while(p!=NULL)
     {
       visualiza_gral();
       gotoxy(15,fil);printf(p->cod);
       gotoxy(38,fil);printf(p->nom);
       gotoxy(60,fil);printf(p->apell);
       p=p->sig;fil++;
       getch();
       
     }
   }
    getche();
} 
/****************************************************************************/
void eliminar()
{ 
  do
  {
   clrscr();ventana(2,2,79,24);
   if(ptr==NULL)
   {  
    gotoxy(16,10);printf("!!!!!! NO SE PUEDE ELIMINAR REGISTRO VACIO !!!!!!"); 
    gotoxy(12,13);cprintf(">>>> POR FAVOR DIGITE ### ENTER ### Y REGRESE AL MENU <<<<"); 
    opcion='N';getche();
   }
    else
    {
     ventana(2,2,79,24);
     p=ptr;
     ptr=p->sig;
     ptr->ant=p->sig=NULL;
     delete(p);

     textcolor(14+128);gotoxy(25,13);cprintf("!!!!!!!!!! REGISTRO ELIMINADO !!!!!!!!!!");
     gotoxy(30,22);printf("DESEA ELIMINAR OTRO[S/N]: ");
     opcion=toupper(getche());
   }
  }while(opcion=='S');
}
/****************************************************************************/
void ventana(int X1,int Y1,int X2,int Y2)
{
 int i;
 for(i=X1+1;i<X2;i++){
  gotoxy(i,Y1);printf("อ"); 
  gotoxy(i,Y2);printf("อ");} 
 for(i=Y1+1;i<Y2;i++){
  gotoxy(X1,i);printf("บ");   
  gotoxy(X2,i);printf("บ");}  
  gotoxy(X1,Y1);printf("ษ");
  gotoxy(X1,Y2);printf("ศ");
  gotoxy(X2,Y1);printf("ป");
  gotoxy(X2,Y2);printf("ผ");
}
/****************************************************************************/
void pantalla()
{
 textcolor(13);
 delay(40);
 ventana(1,3,80,22);
}
/****************************************************************************/
void visualiza_gral()
{ 
  ventana(4,2,76,24);
  gotoxy(18,4);printf(">>>>>>>>>> V I S U A L I Z A C I O N <<<<<<<<<<");
  gotoxy(15,6);printf("CODIGO");
  gotoxy(38,6);printf("NOMBRE ");
  gotoxy(60,6);printf("APELLIDO");
  textcolor(14+128);gotoxy(30,22);cprintf("###### ENTER ######");
  getche();
}
/****************************************************************************/
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
  char helpline[35][45];
  clrscr();
  textbackground(1); 
  strcpy(opciones[11],"  INSERTAR USUARIOS   ");
  strcpy(opciones[12],"  VISUALIZAR USUARIOS ");
  strcpy(opciones[13],"  ELIMINAR USUARIOS   ");
  strcpy(opciones[14],"  SALIR DEL SISTEMA  ");
  strcpy(helpline[11]," INSERTAR USUARIOS AL ARCHIVO             ");
  strcpy(helpline[12]," VISUALIZA INFORMACION DEL ARCHIVO        ");
  strcpy(helpline[13]," ELIMINA SALIDA DE UN USUARIO DEL ARCHIVO ");
  strcpy(helpline[14],"     >>>>> SALIR  DEL  SISTEMA  <<<<<     ");
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
    gotoxy(17,24);cprintf(helpline[f]);
   _setcursortype(_NOCURSOR);
   do
   { 
     tecla=getch(); 
   }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
     if(tecla==80)
     {
      gotoxy(17,24);
      cprintf(helpline[f]);
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
      gotoxy(17,24);
      cprintf(helpline[f]);
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
	      insertar();pisos();break;
       case 12:_setcursortype(_SOLIDCURSOR);
	       visualizar();pisos(); break;
       case 13:_setcursortype(_SOLIDCURSOR);
	       eliminar();pisos(); break;
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
/****************************************************************************/
void marcos(int ci,int cf,int fi,int ff)
{
 int i;
 int c,f;
 clrscr();
 textcolor(15);
 textbackground(1);
 for(i=ci;i<=cf;i++)
 {
   gotoxy(i,fi);cprintf("อ");
   gotoxy(i,ff);cprintf("อ");
 }
 for(i=fi;i<=ff;i++)
 {
   gotoxy(ci,i);cprintf("บ");
   gotoxy(cf,i);cprintf("บ");
 }
   gotoxy(ci,fi);cprintf("ษ");
   gotoxy(ci,ff);cprintf("ศ");
   gotoxy(cf,fi);cprintf("ป");
   gotoxy(cf,ff);cprintf("ผ");
 }
/***************************************************************************/
void pisos()
{
 int n,j;
 clrscr();
 textbackground(1);
 clrscr();
 for(n=2;n<=24;n++)
  gotoxy(8,4);textcolor(15);
  cprintf("E L E C T R O  C A R I B E  D E  L A  C O S T A  L I M I T A D A");
  gotoxy(28,9);textcolor(15);cprintf(">>>> MENU PRINCIPAL <<<<");
  textcolor(14+128);gotoxy(14,19);
  cprintf("UTILICE LAS TECLAS DEL CURSOR  Y  PRESIONE ฎ ENTER ฏ ");  
  marco(26,7,53,16);marco(5,2,75,22);marco(9,5,70,20);marco(13,23,65,25);
}
/****************************************************************************/
	  //CORPORACION UNIVERSITARIA  DE  SANTANDER << U D E S>>
		  //FACULTAD  INGENIERIA  DE  SISTEMAS
	     //DALILA MICHELA BRACHO ACOSTA  COD. 96132018
		   //VALLEDUPAR NOVIEMBRE 10 DE 1998
/****************************************************************************/
