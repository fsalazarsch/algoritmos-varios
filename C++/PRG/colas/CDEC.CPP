#include "iostream.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "ctype.h"
#include "stdio.h"
#include "io.h"
#include "fcntl.h"
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
    char nombre[50];
    int z,r;
    long cod;
    void captura_doblecircular();
    void eliminar_doblecircular();
    void consultardoblecircular();
    void captura_doble();
    void eliminar_doble();
    void consultardoble();
    void pantalla(int x1,int x2,int y1, int y2);
    int  buscar_nododoble(long cod);
    int  buscar_nododoblecircular(long cod);
    void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux);
    int colavacia(struct COLAS *pq);
    void eliminarcola(struct COLAS *pq);
    void insertarcola(struct COLAS *pq,long cod,char *nombre);
    void ventana(int X1,int Y1,int X2,int Y2);
    void inscola();
    void menu();
    void menu_LDE();
    void menu_LDC();
    void menu_COLAS();
////////////////////////////////////////////////////////////////////////////
void consultardoblecircular()
{
 if(cabeza1!=NULL){
 p=cabeza1;
 while(p->Der!=cabeza1){
 clrscr();
 gotoxy(10,10);printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
 getch();
 p=p->Der;
 }
  if(p!=NULL){
  clrscr();
  gotoxy(10,10);printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
  getch();
  }
}
  else{
  clrscr();gotoxy(15,15);printf("NO HAY INFORMACION EN LA LISTA");
  getch();
  }
  }
////////////////////////////////////////////////////////////////////////////
 void consultardoble(){
 p=cabeza2;
 while(p!=NULL){
 clrscr();
 gotoxy(10,10);printf("Codigo: %ld  Nombre: %s \n",p->codigo,p->nombre);
 getch();
 p=p->Der;
 }
  if(cabeza2==NULL){
 clrscr();gotoxy(15,15);printf("NO HAY INFORMACION EN LA LISTA");
 getch();  
 }
   }
////////////////////////////////////////////////////////////////////////////
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
    return 1; 
  if(sw==0)
   if(p->codigo==cod)
   return 1;
  }
    return 0; 
 }
////////////////////////////////////////////////////////////////////////////
void validar_datos(int posx,int posy,int tipo_captura,struct NODO *aux)
{
 int sw=0,i,control;
 char *auxiliar;
 switch(tipo_captura){
   case 1:
	  {
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
////////////////////////////////////////////////////////////////////////////
void eliminar_doblecircular(){
int sw=0;
 clrscr();
 gotoxy(10,7);printf("Digite Codigo  A Eliminar::> ");
 do{
  z=0;r=0;
  gotoxy(45,7);clreol();gets(a);
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
   gotoxy(25,22);
   printf(" Desea Continuar (S/N): ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
   if(op=='S')
	eliminar_doblecircular();
  }
////////////////////////////////////////////////////////////////////////////
void captura_doble(){
    int sw=0;
    clrscr();
    nn=new NODO;

    do{
    gotoxy(10,7);
    printf("Codigo::> ");
	if(sw==1){
	gotoxy(15,15);
	printf("!!! Codigo ya Existe !!!");
	getch();
	clreol();
	}
    validar_datos(23,7,2,nn);
   }while((sw=buscar_nododoble(nn->codigo))==1);
    gotoxy(10,9);
    printf("Nombre::> ");
    validar_datos(23,9,1,nn);
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
     gotoxy(25,22);printf("Desea Continuar (S/N): ");
   op=toupper(getch());
   if(op=='S'||op =='N')
   sw=1;
  }while(sw!=1);
   if(op=='S')
   captura_doble();
   }
/////////////////////////////////////////////////////////////////////////////
void captura_doblecircular(){
 int sw=0;
 clrscr();
 nn=new NODO;
  do{
   gotoxy(10,7);printf("Codigo::> ");
   if(sw==1){
   gotoxy(15,15);printf("!!! Codigo ya Existe !!!!");
   getch();clreol();
}
   validar_datos(23,7,2,nn);
   }while((sw=buscar_nododoblecircular(nn->codigo))==1);
    gotoxy(10,9);printf("Nombre::> ");
    validar_datos(23,9,1,nn);
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
     gotoxy(25,22);printf(" Desea Continuar (S/N): ");
     op=toupper(getch());
     if(op=='S'||op =='N')
      sw=1;
   }while(sw!=1);
   if(op=='S')
   captura_doblecircular();
   }
////////////////////////////////////////////////////////////////////////////
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
   return 1;
   if(sw==0)
    if(p->codigo==cod)
   return 1;
   }
    return 0; 
}
/////////////////////////////////////////////////////////////////////////////
 void eliminar_doble(){
 int sw=0;
  clrscr();
   gotoxy(10,7);printf("Digite Codigo  A Eliminar::> ");
      do{
       z=0;r=0;
       gotoxy(45,7);clreol();
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
     gotoxy(15,15);printf(" ญญญ  Codigo No Existe ญญญญ");
      getch();
  }
   do{
   sw=0;
   gotoxy(25,22);printf(" Desea Continuar (S/N): ");
   op=toupper(getch());
   if(op=='S'||op =='N')
    sw=1;
  }while(sw!=1);
   if(op=='S')
     eliminar_doble();
  }
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void inscola(){
 int sw2=0;
 clrscr();
 gotoxy(15,5);printf("Digite Codigo ::> ");
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
/******/
void main ()
{
 clrscr();
 menu();

}	

void menu()
{
 int i;
 char op,SALIR;
 int n,j;
 int tecla,f;
 do
 {
  textbackground(12);
   textcolor(15);
  clrscr();                     
  ventana(28,6,53,19);

  gotoxy(33,9);cout<<"   MEMU  GENERAL   ";
  gotoxy(33,11);cout<<"LISTAS DOBLES     ";
  gotoxy(33,12);cout<<"LISTAS CIRCULARES ";
  gotoxy(33,13);cout<<"COLAS             ";
  gotoxy(33,15);cout<<"SALIR             ";
  textcolor(15);
  char c=127;
  gotoxy(30,11);cout<<c;
  gotoxy(30,11);
  do
  {
   char c=127; 
   tecla=getch();
   if(tecla==72) 
   {
    cout<<"  ";
    if(wherey()==11)
    {
     gotoxy(30,wherey()+5);
     cout<<c;
     gotoxy(30,wherey());
    }
    else
    {
     gotoxy(30,wherey()-1);printf("%c",127);
     gotoxy(30,wherey());
    }
   }
   if(tecla==80) 
   {
    cout<<"  ";
    if(wherey()==8)
    {
     gotoxy(30,wherey()-5);printf("%c",127);
     gotoxy(30,wherey());
    }
    else
    {
     gotoxy(30,wherey()+1);
     cout<<c;
     gotoxy(30,wherey());
    }
   }
  } while(tecla!=13);
  op=wherey();
  if(op==8)
  {
   SALIR='S';
  }
  else
  {
   switch(op)
   {
   
    case 11:clrscr();menu_LDC();clrscr();break;
    case 12:menu_LDE();clrscr();clrscr(); break;
    case 13:menu_COLAS();clrscr();clrscr(); break;
    case 15:exit(0);break;
   }
  }
 } while(SALIR!='S');
}
/******/
void menu_COLAS()
{
   int n,j;
   int tecla,f;
 char opciones[25][25];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"SALIR                   ");
   do{

   for(f=9; f<=11;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11); 
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=11)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=11;
    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);inscola();clrscr();break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminarcola(&cola);clrscr();break;
 }

}
 while(f!=11);
}
void menu_LDC()
{
 int n,j;
 int tecla,f;
 char opciones[25][45];
 window(1,1,80,25);
 clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"VISUALIZAR              ");
 strcpy(opciones[12],"SALIR                   ");

   do{

   for(f=9; f<=12;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11); 
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
gotoxy(10,22);
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(11); 
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);captura_doblecircular();clrscr(); break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminar_doblecircular();clrscr();break;
 case 11:_setcursortype(_SOLIDCURSOR);consultardoblecircular();clrscr(); break;
 }

}
 while(f!=12);
}
void menu_LDE()
{
   int n,j;
   int tecla,f;
 char opciones[25][45];
  window(1,1,80,25);
  clrscr();
 strcpy(opciones[9],"ADICIONAR               ");
 strcpy(opciones[10],"ELIMINAR                ");
 strcpy(opciones[11],"VISUALIZAR              ");
 strcpy(opciones[12],"SALIR                   ");

   do{

   for(f=9; f<=12;f++)
 {
  textcolor(0);
  gotoxy(28,f); cprintf(opciones[f]);
  }
  f=9;
  textcolor(0); textbackground(11); 
  gotoxy(28,f); cprintf(opciones[f]);
  textcolor(0); textbackground(15);
 do
 {
_setcursortype(_NOCURSOR);
gotoxy(1,1);
  do
  {
    _setcursortype(_NOCURSOR);
    tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     _setcursortype(_NOCURSOR);
     gotoxy(1,1);
     cprintf(" ");
     textcolor(0);textbackground(15);
     gotoxy(28,f);cprintf(opciones[f]);
     if(f!=12)
     f=f+1;
     else

    f=9;

    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(0);textbackground(15);
   gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);
    _setcursortype(_NOCURSOR);
    gotoxy(1,1);
    cprintf(" ");
   if(f!=9)
   f=f-1;
   else

    f=12;
    textcolor(0);textbackground(11);
    gotoxy(28,f);cprintf(opciones[f]);
    textcolor(0);textbackground(15);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 9 : _setcursortype(_SOLIDCURSOR);captura_doble();clrscr();break;
 case 10:_setcursortype(_SOLIDCURSOR);eliminar_doble();clrscr(); break;
 case 11:_setcursortype(_SOLIDCURSOR);consultardoble();clrscr(); break;
 }

}
 while(f!=12);
}
void ventana(int X1,int Y1,int X2,int Y2)
{    int i;
 for(i=X1+1;i<X2;i++){
 gotoxy(i,Y1);cprintf("อ");   // LINEA ARRIBA HORIZONTAL
 gotoxy(i,Y2);cprintf("อ");}  // LINEA ABAJO HORIZONTAL
 for(i=Y1+1;i<Y2;i++){
 gotoxy(X1,i);cprintf("บ");    // LINEA IZQUIERDA VERTICAL
 gotoxy(X2,i);cprintf("บ");}   // LINEA DERECHA VERTICAL
 gotoxy(X1,Y1);cprintf("ษ");
 gotoxy(X1,Y2); cprintf("ศ");
 gotoxy(X2,Y1);cprintf("ป");
 gotoxy(X2,Y2); cprintf("ผ");
}

