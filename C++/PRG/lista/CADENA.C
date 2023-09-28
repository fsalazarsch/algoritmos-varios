
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>
#include <string.h>
#include <alloc.h>
#include <iostream.h>
#include <iomanip.h>
#include <time.h>
#define memo (struct nodo *) malloc (sizeof (struct nodo))
void leer_datos();
void captura(char cod_para[],int t,int x,int y,int opcion);
void cap();
void insercion1();
void cap1();
void insercion();
void menu_prin();
void menu_prin1();
void f_l(int f,int l);
void eliminacion1();
void menu_prin2();
void cuadros1(int x1,int x2,int y1,int y2);
void f_l(int ,int );
void eliminacion();
struct nodo *nuevo;
int   h=6;
char cod[40];
char nom[40];

struct nodo
{
	char codigo[40];
	char nombre[40];

	struct nodo *sig;
	struct nodo *ant;
};


 struct nodo *p,*mov,*cab,*v,*q,*r;
 int n; int num;int sw=0;
  char op;

void cap()
{
 do{
     clrscr();
     gotoxy(10,2);
     printf("DIGITE EL CODIGO :");
     captura(cod,38,40,2,1);
     gotoxy(10,4);
     printf("DIGITE EL NOMBRE :");
     captura(nom,38,40,4,2);


    v->ant=NULL;
    v->sig=NULL;



      v=memo;


   strcpy(v->codigo,cod);
   strcpy(v->nombre,nom);
   if (cab==NULL){
     cab=v;
     p=cab;

     }
     else{
	 p->sig=v;
	 v->ant=p;
	 p=v;
	 }
     gotoxy(10,6);
     printf("nodo insertado:");
     gotoxy(10,8);
     printf("DESEA ADICIONAR NODO(s/n):");
      op=toupper(getche());
    }while(op!='n'&& op!='N');
  clrscr();



     printf("\n");
     clrscr();
    mov=cab;
  h=6;
	 gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");

  while(mov!=p->sig){
	 gotoxy(29,h);cprintf("%s",mov->nombre);
	 gotoxy(49,h);cprintf("%s",mov->codigo);
	 h=h+1;
	 mov=mov->sig;



  }
    getche();
 }

	void insercion1(){
	 int sw=0;

	 char nom2[30],codnu[45];




	 clrscr();
	 gotoxy(10,2);
	 cprintf("DIGITE EL NODO GUIA  :");
	 captura(cod,39,40,2,1);
	mov=cab;

	  while(mov!=p){

	  if(strcmp(mov->codigo, cod)==0)
	  { sw=1;

	 clrscr();
	 v=memo;
	 cprintf("DIGITE EL CODIGO A INSERTAR:");
	 captura(codnu,38,40,2,1);
	 gotoxy(10,4);
	 cprintf("DIGITE EL NOMBRE A INSERTAR:");
	 captura(nom2,38,40,4,2);
	 strcpy(v->nombre,nom2);
	 strcpy(v->codigo,codnu);
	 if(cab==NULL){
	 cprintf("NO SE PUEDE INSERTAR:");}


	 if(cab->sig==cab)
	 {
	  textcolor(4);
	  gotoxy(20,20);
	  v=memo;
	  cab->sig=v;

	  cab->ant=v;
	  v->sig=cab;
	  v->ant=cab;
	  p=v;
	  break;
	  }else {



       if(p->sig==cab)
	{r=cab;

	p->sig=v;
	v->ant=p;
	v->sig=r;
	r->ant=v;
	p=p->sig;
	 break;
	}
	else{
		 v->ant=mov;
		 mov->sig=r;
		 mov->sig=v;

		 r->ant=v;
		 v->sig=r;
		 break;
		}

	       }//el si
	   }

		  mov=mov->sig;

	  }//mientras que











	if (sw==0){
	gotoxy(10,10);
cprintf("El nodo guia no existe");
    }else{

	 clrscr();
	 cprintf("\n");
	 gotoxy(5,3);
	cprintf("el se¤or %s con codigo %s ha sido registrado",v->nombre,v->codigo);

	 mov=cab;
	 h=6;

   gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");
       //		 gotoxy(29,h);cprintf("%s",mov->nombre);
	 //gotoxy(49,h);cprintf("%s",mov->codigo);


  while(mov!=p){
	 gotoxy(29,h);cprintf("%s",mov->nombre);
	 gotoxy(49,h);cprintf("%s",mov->codigo);
	 h=h+1;
	 mov=mov->sig;











	 }
	 }





  getche();

}

   void insercion(){
	 int sw=0;

	 char nom2[30],codnu[45];




	 clrscr();
	 gotoxy(10,2);
	 printf("DIGITE EL NODO GUIA  :");
	 captura(cod,39,40,2,1);
	mov=cab;
	  while(mov!=p->sig){

	  if(strcmp(mov->codigo, cod)==0)
	  { sw=1;

	 clrscr();
	 v=memo;
	 printf("DIGITE EL CODIGO A INSERTAR:");
	 captura(codnu,38,40,2,1);
	 gotoxy(10,4);
	 printf("DIGITE EL NOMBRE A INSERTAR:");
	 captura(nom2,38,40,4,2);
	 strcpy(v->nombre,nom2);
	 strcpy(v->codigo,codnu);

	 if(cab->sig==NULL)
	 {
	  textcolor(4);
	  gotoxy(20,20);
	  v=memo;
	  cab->sig=v;
	  p=v;
	  v->sig=NULL;
	  v->ant=cab;
	  break;
	  }else {



       if(mov->sig==p->sig)
	{
	p->sig=v;
	v->ant=p;
	v->sig=NULL;
	p=p->sig;
	 break;
	}
	else{
		 v->ant=mov;
		 v->sig=mov->sig;
		 mov->sig=v;
		 mov=v->sig;
		 mov->ant=v;
		 break;
		}

	       }//el si

	      }
		  mov=mov->sig;
 }//mientras que


	if (sw==0){
	gotoxy(10,10);
printf("El nodo guia no existe");
    }else{

	 clrscr();
	 printf("\n");
	 gotoxy(5,3);
	 printf("el se¤or %s con codigo %s ha sido registrado",v->nombre,v->codigo);

	 q=cab;
	 h=6;

	 gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");

  while(q!=p->sig){
	 gotoxy(29,h);cprintf("%s",q->nombre);
	 gotoxy(49,h);cprintf("%s",q->codigo);
	 h=h+1;
	 q=q->sig;
	 }



	}

  getche();

}
	void eliminacion1()
   {
	 int sw=0;

	 char nom2[30],codnu[45];




	 clrscr();
	 gotoxy(10,2);
	 cprintf("DIGITE EL NODO GUIA  :");
	 captura(cod,39,40,2,1);
	mov=cab;
	  while(mov!=p->sig){

	  if(strcmp(mov->codigo, cod)==0)
	  { sw=1;

	 clrscr();

	 if(cab->sig==cab)
	 {
	   cprintf("NO SE PUEDE ELIMINAR EL NODO:");
	  break;
	  }else {



       if(mov->sig==p->sig)
	{   q=p;
	p=p->ant;
	p->sig=cab;cab->ant=p;
	free(q);

	 break;
	}
	else{
	      q=mov->ant;
	      q->sig=mov->sig;
	      q=mov->sig;
	      q->ant=mov->ant;


	      free(mov);

		 break;
		}

	       }//el si

	      }
		  mov=mov->sig;
 }//mientras que


	if (sw==0){
	gotoxy(10,10);
cprintf("El nodo guia no existe");
    }else{

	 clrscr();
	 cprintf("\n");
	 gotoxy(5,3);
	 r=cab;
	 //printf("el se¤or %s con codigo %s ",v->nombre, v->codigo);
	 if(r->sig==cab)
	 {
	 gotoxy(10,20);delay(100);cprintf ( "NO SE PUEDE ELIMINAR:");}


	 h=6;//     gotoxy(29,h);cprintf("%s",r->nombre);
	// gotoxy(49,h);cprintf("%s",r->codigo);
	// h++;

	 gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");

	p=p->sig;
  while(r!=p){
	 gotoxy(29,h);cprintf("%s",r->nombre);
	 gotoxy(49,h);cprintf("%s",r->codigo);
	 h=h+1;
	r=r->sig;
	 }



	}

  getche();

}





  void eliminacion(){                 
  	 int sw=0;

	 char nom2[30],codnu[45];




	 clrscr();
	 gotoxy(10,2);
	 printf("DIGITE EL NODO GUIA  :");
	 captura(cod,39,40,2,1);
	mov=cab;
	  while(mov!=p->sig){

	  if(strcmp(mov->codigo, cod)==0)
	  { sw=1;

	 clrscr();
	 
	 if(cab->sig==NULL)
	 { 
           printf("NO SE PUEDE ELIMINAR EL NODO:");
	  break;
	  }else {



       if(mov->sig==p->sig)
	{   q=p;
        p=p->ant;
        free(q);
         
	 break;
	}
	else{
	      q=mov->ant;
              q->sig=mov->sig;
              q=mov->sig;
              q->ant=mov->ant;

              free(mov);	

		 break;
		}

	       }//el si

	      }
		  mov=mov->sig;
 }//mientras que


	if (sw==0){
	gotoxy(10,10);
printf("El nodo guia no existe");
    }else{

	 clrscr();
	 printf("\n");
	 gotoxy(5,3);
	 printf("el se¤or %s con codigo %s ",v->nombre, v->codigo);
         if(cab->sig==NULL)
         {
         gotoxy(10,20);delay(100);printf ( "NO SE PUEDE ELIMINAR:");}

	 r=cab;
	 h=6;

	 gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");

  while(r!=p->sig){
	 gotoxy(29,h);cprintf("%s",r->nombre);
	 gotoxy(49,h);cprintf("%s",r->codigo);
	 h=h+1;
	r=r->sig;
	 }



	}

  getche();

}







void main()
 {
  menu_prin();

 }
/*********************************************************************/

void cuadros1(int x1,int x2,int y1,int y2)
{

	  int j,i,k;
	  for (j=x1;j<=x2;j++)
		 {
		 gotoxy(j,y1);cprintf("Í");
		 gotoxy(j,y2);cprintf("Í");
		 }
	  for (i=y1;i<=y2-1;i++)
		 {
		 gotoxy(x1,i);cprintf("º");
		 gotoxy(x2,i);cprintf("º");
		 }
	  gotoxy(x1,y1);cprintf("É");
	  gotoxy(x2,y1);cprintf("»");
	  gotoxy(x1,y2);cprintf("È");
	  gotoxy(x2,y2);cprintf("¼");

}
/***************************************************/
//***************************************************************************
void menu_prin()
{
 int tecla,f;
 char opciones[27][70];
 do
 {

  strcpy(opciones[1], "DOBLE ENCADENADA    ");
  strcpy(opciones[2], "DOBLE ENCADENADA CIRCULAR ");
  strcpy(opciones[3], "SALIR ");


  clrscr();
  f_l(1,14);
  cuadros1(1,79,2,24);
  gotoxy(20,4);cprintf("<< M E N U   P R I N C I P A L >>");
  gotoxy(27,7);cprintf("<<O P C I O N E S>>");
  cuadros1(20,52,6,17);
	f_l(1,14);
  for(f=1;f<=3;f++) {gotoxy(25,f+8);cprintf("%s",opciones[f]);}
  f=1;
	f_l(3,0);
  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	f_l(1,14);
  do
  {
	do
	{
	 tecla=getch();
	}while((tecla==80)&&(tecla==72)&&(tecla==13));
	if(tecla==80)
	{
	  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=3)
	 {
	  f++;
	  f_l(3,0);
	  gotoxy(25,f+8);  cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=1;
	  f_l(3,0);
	  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
	if(tecla == 72)
	{  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=1)
	 {
	  f--;
	  f_l(3,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=3;
	  f_l(3,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
  }while(tecla!=13);
  switch(f)
  {
	case 1:{f_l(9,7); window(1,1,80,25);clrscr();
		 menu_prin1()  ; break;}

	  case 2:{f_l(9,7);window(1,1,80,25);clrscr();
		 menu_prin2();break;}


  }
 }while(f!=3);
}






void cap1()
 {

 do{
     clrscr();
     gotoxy(10,2);
     printf("DIGITE EL CODIGO :");
     captura(cod,38,40,2,1);
     gotoxy(10,4);
     printf("DIGITE EL NOMBRE :");
     captura(nom,38,40,4,2);
       v=memo;
    v->ant=v;
    v->sig=v;
   

   strcpy(v->codigo,cod);
   strcpy(v->nombre,nom);
    if(cab==NULL ){
      
     cab=v;
       cab->sig=cab;
       cab->ant=NULL;
       p=v;
     }
     else{
           p->sig=v;
           
	 v->ant=p;
        
        v->sig=cab;
	   p=v;	 
	 } 
     gotoxy(10,6);
     printf("nodo insertado:");
     gotoxy(10,8);
     printf("DESEA ADICIONAR NODO(s/n):");
     op=toupper(getche());
    }while(op!='n'&& op!='N');
    clrscr();



     printf("\n");
     clrscr();
    mov=cab;
  h=6;
	 gotoxy(29,5);cprintf( "Nombre");
	 gotoxy(49,5);cprintf( "Codigo");
         gotoxy(29,h);cprintf("%s",mov->nombre);
	 gotoxy(49,h);cprintf("%s",mov->codigo);
          h++;
       mov=mov->sig;
  while(mov!=p->sig){
	 gotoxy(29,h);cprintf("%s",mov->nombre);
	 gotoxy(49,h);cprintf("%s",mov->codigo);
	 h=h+1;
	 mov=mov->sig;



  }

    getche();
 }




void menu_prin1()
{
 int tecla,f;
 char opciones[27][70];
 do
 {

  strcpy(opciones[1], "CAPTURA   ");
  strcpy(opciones[2], "INSERCION  ");
  strcpy(opciones[3], "ELIMINACION   ");
  strcpy(opciones[4], "SALIR  ");


  clrscr();
  f_l(1,14);
  cuadros1(1,79,2,24);
  gotoxy(20,4);cprintf("<<  LISTAS DOBLEMENTE ENCADENADA  >>");
  gotoxy(27,7);cprintf("<<O P C I O N E S>>");
  cuadros1(20,52,6,17);
	f_l(1,14);
  for(f=1;f<=4;f++) {gotoxy(25,f+8);cprintf("%s",opciones[f]);}
  f=1;
	f_l(4,0);
  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	f_l(1,14);
  do
  {
	do
	{
	 tecla=getch();
	}while((tecla==80)&&(tecla==72)&&(tecla==13));
	if(tecla==80)
	{
	  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=4)
	 {
	  f++;
	  f_l(4,0);
	  gotoxy(25,f+8);  cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=1;
	  f_l(4,0);
	  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
	if(tecla == 72)
	{  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=1)
	 {
	  f--;
	  f_l(4,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=4;
	  f_l(4,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
  }while(tecla!=13);
  switch(f)
  {
	case 1:{f_l(9,7); window(1,1,80,25);clrscr();
		cap(); break;}

	  case 2:{f_l(9,7);window(1,1,80,25);clrscr();
	        insercion();break;}

	  case 3:{f_l(9,7);window(1,1,80,25);clrscr();
		eliminacion();break;}



  }
 }while(f!=4);
}

void menu_prin2()
{
 int tecla,f;
 char opciones[27][70];
 do
 {
  strcpy(opciones[1], "CAPTURA  ");
  strcpy(opciones[2], "INSERCION   ");
  strcpy(opciones[3], "ELIMINACION ");
  strcpy(opciones[4], "SALIR     ");





  clrscr();
  f_l(1,14);
  cuadros1(1,79,2,24);
  gotoxy(20,4);cprintf("<< LISTAS DOBLEMENTE ENCADENADA CIRCULAR >>");
  gotoxy(27,7);cprintf("<<O P C I O N E S>>");
  cuadros1(20,52,6,17);
	f_l(1,14);
  for(f=1;f<=4;f++) {gotoxy(25,f+8);cprintf("%s",opciones[f]);}
  f=1;
	f_l(4,0);
  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	f_l(1,14);
  do
  {
	do
	{
	 tecla=getch();
	}while((tecla==80)&&(tecla==72)&&(tecla==13));
	if(tecla==80)
	{
	  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=7)
	 {
	  f++;
	  f_l(4,0);
	  gotoxy(25,f+8);  cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=1;
	  f_l(4,0);
	  gotoxy(25,f+8);cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
	if(tecla == 72)
	{  f_l(1,14);
	 gotoxy(25,f+8);cprintf("%s",opciones[f]);
	 if (f!=1)
	 {
	  f--;
	  f_l(4,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	 else
	 {
	  f=4;
	  f_l(4,0);
	  gotoxy(25,f+8); cprintf("%s",opciones[f]);
	  f_l(1,14);
	 }
	}
  }while(tecla!=13);
  switch(f)
  {
	case 1:{f_l(9,7); window(1,1,80,25);clrscr();
		 cap1(); break;}

	  case 2:{f_l(9,7);window(1,1,80,25);clrscr();
	   insercion1();break;}

	  case 3:{f_l(9,7);window(1,1,80,25);clrscr();
		 eliminacion1();break;}



  }
 }while(f!=4);
}

void f_l(int f,int l)
  {  textbackground(f);
	textcolor(l);
  }

 void captura(char cod_para[],int t,int x,int y,int opcion)
{
char c=' ';
int n=0;
gotoxy(x,y);
switch(opcion)
{
   case 1:
	   while(c!='\r' && n<t)
	   {
	     c=getche();

	     if(!isdigit(c) && c!='\r')
	     {

	     gotoxy(x+n-1,y);
	     clreol();

	     }
	     else
	       if(c!='¤'||c!='¥')
	       {
	      cod_para[n]=c;
	      n++;
	      }

	    }
	      cod_para[n]='\0';

	    break;
	case 2:
	while(c!='\r' && n<t)
	{
	  c=getche();
	  if(isdigit(c)&&c!='\r'){
	  gotoxy(x+n-1,y);
	  clreol();
	  }
	  else
	   if(c!='¤'||c!='¥')
	   {
	  cod_para[n]=c;
	  n++;
	  }
	}
      cod_para[n]='\0';
	  break;
     }


   }



