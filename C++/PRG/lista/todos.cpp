#include "stdio.h"
#include "io.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "ctype.h"
#define TRUE 1
#define FALSE 0
#define MAXIMO 20

    struct NODO {
    long codigo;
    char *nombre;
    struct NODO *Izq;
    struct NODO *Der;
    };


    struct NODO *cabeza1,*cabeza2,*p,*q,*nn;

    struct COLAS{
    struct NODO COLA[MAXIMO];
    int frente,final;
    }cola;
    int sw=0;
    char op;
    char a[20];
    int z,r;
    long cod;
    char nombre[50];
    void captura_doblecircular();
    void eliminar_doblecircular();
    void consultardoblecircular();
    void captura_doble();
    void eliminar_doble();
    void consultardoble();
    int  buscar_nododoble(long cod);
    int  buscar_nododoblecircular(long cod);
    void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux);
    int colavacia(struct COLAS *pq);
    void eliminarcola(struct COLAS *pq);
    void insertarcola(struct COLAS *pq,long cod,char *nombre);
    void inscola();
    void menu();
    void menu_LDE();
    void menu_LDC();
    void menu_COLAS();
    void marco(int x1,int y1,int x2,int y2);
    void color();
 void consultardoblecircular(){
 if(cabeza1!=NULL){
 p=cabeza1;
 while(p->Der!=cabeza1){
	clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	p=p->Der;
	}
   if(p!=NULL){
   clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	}
}
	else
	{
	clrscr();
	printf("Lista Vacia........");
	getch();
	}
   }
  /*******************************************************************/
 void consultardoble(){
 p=cabeza2;
 while(p!=NULL){
	clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
	getch();
	p=p->Der;
	}
   if(cabeza2==NULL){
	clrscr();
	printf("Lista Vacia........");
	getch();
	}
   }

	int buscar_nododoblecircular(long cod){
	  int sw=0;
	if(cabeza1==NULL)
	return 0;
	else{
	  p=cabeza1;
	  while(p->Der!=cabeza1 && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->Der;
					   }
	  if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}

 /*******************************************************************/
   /* valida los datos de entradas tales como los codigos y los nombres */
   void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux)
		{
		int sw=0,i,control;
		char *auxiliar;
		switch(tipo_captura){
			  case 1:{do{
			  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				 if(isdigit(auxiliar[i])==0){
				    sw=1;
				    break;
				    }

				 }while(sw!=1);
				if(sw==1){
				control=sw;
				sw=0;
				}

				}while(control!=1);
				strcpy(aux->nombre,auxiliar);
				break;
				}
			  case 2:{
				  do{
				  control=0;
				  do{
				gotoxy(posx,posy);
				clreol();
				scanf("\n");
				gets(auxiliar);

				for(i=0;i<=strlen(auxiliar)-1;i++)
				    if(isdigit(auxiliar[i])==0){
					sw=1;
					break;
					}
				 }while(sw!=0);
				if(sw==1){
				control=sw;
				sw=0;
				}
				}while(control!=0);
				aux->codigo=atol(auxiliar);
				break;
				}
			    }
			 }

 /*******************************************************************/
/* elimina un nodo de la lista doble circular */
void eliminar_doblecircular(){

			 int sw=0;
					clrscr();
   gotoxy(10,10);
   printf("Digite Codigo  A Eliminar::> ");
			  do{
			  z=0;r=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);

		p=cabeza1;
		   q=NULL;
		   while(p->Der!=cabeza1 && sw==0)
			  if(p->codigo==cod)
				sw=1;
				else{
				    q=p;
				    p=p->Der;
				    }
		   if(q==NULL){
			   if(p->Der==cabeza1 && p->codigo==cod && sw==0)
				    cabeza1=NULL;
			    else
				  if(p->Der!=cabeza1 && p->codigo==cod && sw==1){
					    q=p->Izq;
					    q->Der=p->Der;
					    q=q->Der;
					    q->Izq=p->Izq;
					    cabeza1=p->Der;
						  delete(p);
						  }
				  }else
					if(p->Der==cabeza1 && p->codigo==cod && sw==0){
						 q->Der=p->Der;
						 q=q->Der;
						 q->Izq=p->Izq;
						 delete(p);
						 }
						 else{
						 if(sw==1){
						 q->Der=p->Der;
						 q=q->Der;
						 q->Izq=p->Izq;
						 delete(p);
						 }
						 }

   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	eliminar_doblecircular();
			   }

 /*******************************************************************/
/* captura la informacion para crear en la lista doble circular */
void captura_doblecircular(){
    int sw=0;
    clrscr();
    nn=new NODO;

    do{
    gotoxy(10,10);
    printf("Codigo::> ");
	if(sw==1){
	gotoxy(10,10);
	printf("El Codigo Digitado ya Existe");
	getch();
	clreol();
	}
    validar_datos(23,10,2,nn);
   }while((sw=buscar_nododoblecircular(nn->codigo))==1);
    gotoxy(10,12);
    printf("Nombre::> ");
    validar_datos(23,12,1,nn);

   nn->Izq=nn->Der=NULL;
	  if(cabeza1==NULL)
	   {
		cabeza1=nn;
		nn->Izq=cabeza1;
		nn->Der=cabeza1;
	   }
		else{
			p=cabeza1;
			while(p->Der!=cabeza1){
			    p=p->Der;
						  }
			p->Der=nn;
			nn->Der=cabeza1;
			nn->Izq=p;
		    }


   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	captura_doblecircular();
   }
/* busca si existe un nodo dentro una lista doble */


	  int buscar_nododoble(long cod){
	  int sw=0;
	if(cabeza2==NULL)
	return 0;
	else{
	  p=cabeza2;
	  while(p->Der!=NULL && sw==0){
		if(p->codigo==cod)
		  sw=1;
		  else
		  p=p->Der;
					   }
	  if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}

   /*******************************************************************/
  /* elimina dentro de una lista doble */
  void eliminar_doble(){
			 int sw=0;
					clrscr();
   gotoxy(10,10);
   printf("Digite Codigo  A Eliminar::> ");
			  do{
			  z=0;r=0;
			  gotoxy(45,10);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);

		p=cabeza2;
		   q=NULL;
		   while(p!=NULL && sw==0)
			  if(p->codigo==cod)
				sw=1;
				else{
				    q=p;
				    p=p->Der;
				    }

				   if(q==NULL && sw==1){
					   if(p->Der!=NULL){
					   q=p->Der;
					   q->Izq=NULL;
					   p->Der=NULL;
					   cabeza2=q;
					   delete(p);
					   }else
						cabeza2=NULL;
					}else
				  if(sw==1){
				  if(p->Der!=NULL){
				   q->Der=p->Der;
				   q=p->Der;
				   q->Izq=p->Izq;
				   delete(p);
				   }else{

				   q->Der=NULL;
				   delete(p);
				   }
				   }else
				   {
				   printf("Este Codigo No Existe ");
				   getch();
				   }
   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	eliminar_doble();
			   }

 /*******************************************************************/
/* captura dentro de una lista doble */
void captura_doble(){
    int sw=0;
    clrscr();
    nn=new NODO;

    do{
    gotoxy(10,10);
    printf("Codigo::> ");
	if(sw==1){
	gotoxy(10,10);
	printf("El Codigo Digitado ya Existe");
	getch();
	clreol();
	}
    validar_datos(23,10,2,nn);
   }while((sw=buscar_nododoble(nn->codigo))==1);
    gotoxy(10,12);
    printf("Nombre::> ");
    validar_datos(23,12,1,nn);

   nn->Izq=nn->Der=NULL;
	  if(cabeza2==NULL)
	   {
		cabeza2=nn;
		nn->Izq=NULL;
		nn->Der=NULL;
	   }
		else{
			p=cabeza2;
			while(p->Der!=NULL){
			    p=p->Der;
						  }
			p->Der=nn;
			nn->Der=NULL;
			nn->Izq=p;
		    }


   do{
   sw=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	captura_doble();
   }
 /*******************************************************************/
     void inscola(){
	 int sw2=0;
	 clrscr();
   gotoxy(15,5);
   printf("Digite Codigo ::> ");
			  do{
			  z=0;r=0;
			  gotoxy(45,5);
			  clreol();
			  gets(a);
			 while(a[z]!='\0'){
			 if(a[z]<'0'|| a[z] > '9' ) r=-1;
			 z++;
			 }
			}while(r==-1);
			cod=atol(a);
 gotoxy(15,6);printf("Digite Nombre::> ");
 scanf("\n");
 gets(nombre);
 insertarcola(&cola,cod,nombre);

   do{
   sw2=0;
   gotoxy(10,15);
   printf(" Desea Continuar S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw2=1;
  }while(sw2!=1);
   if(op=='S')
	inscola();
    }

 /*******************************************************************/
    int colavacia(struct COLAS *pq){
    return((pq->frente==pq->final) ? TRUE : FALSE);
    }
 /*******************************************************************/

void eliminarcola(struct COLAS *pq){
    clrscr();

    if(colavacia(pq)){
    printf("subdesborde en la cola ");
    getch();
    return;
    }
    if( pq->frente==MAXIMO-1){
	pq->frente=0;
	printf("Codigo :%ld Nombre :%s",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	getch();

	  }
   else {
	printf("Codigo :%ld  Nombre:%s",pq->COLA[pq->frente].codigo,pq->COLA[pq->frente].nombre);
	getch();
	 pq->frente++;
       }

	  }

 /*******************************************************************/
void insertarcola(struct COLAS *pq,long cod,char nombre[]){
	  if(pq->final==MAXIMO-1)
	   pq->final=0;

	pq->COLA[pq->final].codigo=cod;
	pq->COLA[pq->final].nombre=nombre;
	pq->final++;
	}

void menu()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
 char helpline[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9], "LISTAS DOBLES CIRCULARES");
 strcpy(opciones[10],"LISTAS DOBLES ENCADENADA");
 strcpy(opciones[11],"COLAS                   ");
 strcpy(opciones[12],"SALIR                   ");
 strcpy(helpline[9], "LLAMA EL MENU DE LISTAS DOBLES CIRCULARES ");
 strcpy(helpline[10], "LLAMA EL MENU DE LISTAS DOBLES ENCADENADA ");
 strcpy(helpline[11], "LLAMA EL MENU COLAS                       ");
 strcpy(helpline[12],"SALIR DE LA APLICACION                    ");

   do{
   color();
    marco(26,7,53,15);
   for(f=9; f<=12;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,25);
cprintf(helpline[f]);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(11);  //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);menu_LDC();color(); break;
 case 10:_setcursortype(_SOLIDCURSOR);menu_LDE();color(); break;
 case 11:_setcursortype(_SOLIDCURSOR);menu_COLAS();color(); break;
 }

}
 while(f!=12);
}
void marco(int x1,int y1,int x2,int y2)
{ int n;
  textcolor(0);
  gotoxy(x1, y1); cprintf("%c",201); //É
  gotoxy(x2, y1); cprintf("%c",187); //»  
  gotoxy(x1, y2); cprintf("%c",200); //È 
  gotoxy(x2, y2); cprintf("%c",188); //¼
       for(n=(x1+1);n<=(x2-1);n++){
       gotoxy(n, y1);cprintf("%c",205);//Í
       gotoxy(n, y2);cprintf("%c",205);} 
    for(n=(y1+1);n<=(y2-1);n++){
       gotoxy(x1, n);cprintf("%c",186); //º
       gotoxy(x2, n);cprintf("%c",186);}
  }
void color()
{
int n,j;
window(1,1,80,25);
clrscr();
textbackground(15);
  window(1,1,80,25);
  clrscr();

 for(n=2;n<=24;n++)
     for(j=1;j<=80;j++)
	{
	textcolor(RED);
	gotoxy(j,n);
	cprintf("Û");
	}
 gotoxy(10,1);
 cprintf(" M A N E J O  D E  E S T R U C T U R A S  E N  C P P");

 }


void menu_COLAS()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
 char helpline[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"SALIR                   ");
 strcpy(helpline[9], "ADICIONA INFORMACION EN LA COLA           ");
 strcpy(helpline[10], "ELIMINA Y RECUPERA INFORMACION EN LA COLA");
 strcpy(helpline[12],"SALIR DEL MENU                            ");

   do{

   color();
    marco(26,7,53,13);
   for(f=9; f<=11;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,25);
cprintf(helpline[f]);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=11)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=11;
    textcolor(0);textbackground(11);  //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);inscola();color(); break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminarcola(&cola);color(); break;
 }

}
 while(f!=11);
}
void menu_LDC()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
 char helpline[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"VISUALIZAR              ");
 strcpy(opciones[12],"SALIR                   ");
 strcpy(helpline[9],"ADICIONA INFORMACION EN LA LISTA DOBLE C   ");
 strcpy(helpline[10],"ELIMINA  INFORMACION EN LA LISTA DOBLE C  ");
 strcpy(helpline[11],"VISUALIZAR INFORMACION DE LA LISTA DOBLE C");
 strcpy(helpline[12],"SALIR DE EL MENU                           ");

   do{

   color();
       marco(26,7,53,15);
   for(f=9; f<=12;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,25);
cprintf(helpline[f]);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(11);  //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);captura_doblecircular();color(); break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminar_doblecircular();color(); break;
 case 11:_setcursortype(_SOLIDCURSOR);consultardoblecircular();color(); break;
 }

}
 while(f!=12);
}
void menu_LDE()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
 char helpline[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"VISUALIZAR              ");
 strcpy(opciones[12],"SALIR                   ");
 strcpy(helpline[9],"ADICIONA INFORMACION EN LA LISTA DOBLE E   ");
 strcpy(helpline[10],"ELIMINA  INFORMACION EN LA LISTA DOBLE E  ");
 strcpy(helpline[11],"VISUALIZAR INFORMACION DE LA LISTA DOBLE E");
 strcpy(helpline[12],"SALIR DE EL MENU                           ");

   do{

   color();
    marco(26,7,53,15);
   for(f=9; f<=12;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11);  /*prueba*/
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,25);
cprintf(helpline[f]);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     gotoxy(10,25);
     cprintf(helpline[f]);
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11); //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
   gotoxy(10,25);
     cprintf(helpline[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(11);  //prueba
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);captura_doble();color(); break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminar_doble();color(); break;
 case 11:_setcursortype(_SOLIDCURSOR);consultardoble();color(); break;
 }

}
 while(f!=12);
}
void main(){
menu();
}