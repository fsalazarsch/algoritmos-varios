#include "stdio.h"
#include "io.h"
#include "conio.h"
#include "fcntl.h"
#include "dos.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include "alloc.h"
#define MAXIMO 20


struct ARBOL
 {
  long int cod;
  char nom[15],apell[30],edad[3],sex,sueldo[15],bono[15];
  struct ARBOL *izq,*der;
 }tARBOL;

struct MOLE
 {
  long int senal;
  struct ARBOL *apunt;
 };

struct LIFO
 {
  long int t;
  struct ARBOL *a[MAXIMO];
  struct MOLE b[MAXIMO];
 };
	 
void eliminar();
void visualizar();
void men_modificar();
int retira_arbol (long int n);
void recorrido_1(); 
void recorrido_2();
void recorrido_3();
void in_orden(struct ARBOL *aux);
void post_orden(struct ARBOL *aux);
void pre_orden(struct ARBOL *aux);
void imprimir(struct ARBOL *a);
void lee_cod(int x,int y,char *cod);
void lee_nom(int x,int y,char *nom);
char lee_sex(int x,int y,char F,char M);
void lee_sueldo(int x,int y,char *sueldo);
void lee_edad(int x,int y,char *edad);
void adic();
void cuadro_2(int x, int x2,int y,int y2,int m);
void cuadro(int, int, int, int);
void cuadroff();
void cuadro_del(int,int,int,int);
void cuadro_ver();
struct ARBOL *nn,*p,*raiz,*cab,*q,*aux,*apunt1;
long int x;
char vec[5];
float noa(int s,int s2);
void imprimir();
void borrar_ARBOL (struct ARBOL *q,struct ARBOL *p);
struct ARBOL *buscar(long int n,struct ARBOL  **p,struct ARBOL *q);
void men_prin();
void inorden (struct ARBOL *p);
void preorden(struct ARBOL *p);
void posorden(struct ARBOL *p);
int pila_vacia(struct LIFO *p);
void init_pila(struct LIFO *p);
void ins_pila(struct LIFO *p, struct ARBOL *s);
void ins_pila2(struct LIFO *p, struct ARBOL *s);
void cuadro_3(int,int,int,int);
void ver();
void mirar(struct LIFO *p,struct ARBOL **s,int *i);
void retira_pila(struct LIFO *p, struct ARBOL **s);
int evaluar(long int cod);
int existe(long int cod);
void ver2();
void modifica_nom();

int val;
long int m[50];

void main()
 {
  raiz=NULL;
  textmode(3);
  men_prin();
 }


void portada()
 {
  int i;
  textbackground(7);
  textcolor(0);
  clrscr();
  cuadro(1,79,1,3);
  gotoxy(27,2);cprintf(" TRABAJO DE ARBOLES BINARIOS");
  textcolor(14);
  window(27,6,57,17); 
  textbackground(7);
  clrscr();
  cuadro(1,30,1,12);
  gotoxy(5 ,2);
  cprintf( "   MENU   PRINCIPAL  ");
  textcolor(0);
  gotoxy(5,4);
  cprintf("1.CAPTURA EMPLEADO");
  gotoxy(5,5);
  textcolor(0);
  cprintf("2.CAPTURA ");
  gotoxy(5,6);
  textcolor(0);
  cprintf("3.MODIFICAR   ");
  gotoxy(5,7);
  textcolor(0);
  cprintf("4.R. INORDEN");
  gotoxy(5,8);
  textcolor(0);
  cprintf("5.R. POSORDEN");
  gotoxy(5,9);
  textcolor(0);
  cprintf("6.R. PREORDEN");
  gotoxy(5,10);
  textcolor(0);
  cprintf("7.ELIMINAR HOJAS");
  gotoxy(5,11);
  textcolor(0);
  cprintf("8.FINALIZAR");
 }


void cuadro_2(int x1,int x2,int y1,int y2,int m)
 {
  int j,i;
  for(j=x1;j<=x2;j++)
	{
	 textbackground(0);
	 gotoxy(j,y1-1);cprintf(" ");
	 textbackground(1);
	 gotoxy(j,y1);printf("Í");
	 gotoxy(j,y2);printf("Í");
	 gotoxy(j,y2-m);printf("Í");
	}
  for(i=y1;i<=y2-1;i++)
	{
	 gotoxy(x1,i);printf("º");
	 textbackground(0);
	 gotoxy(x2,i);cprintf("º ");
	}
  gotoxy(x1,y1);printf("É");
  gotoxy(x2,y1); printf("»");
  gotoxy(x1,y1+2);printf("Ì");
  gotoxy(x2,y1+2); printf("¹");
  gotoxy(x1,y2);printf("È");
  gotoxy(x2,y2); printf("¼");
 } 


void men_prin()
{
 int op;
 char tecla,SALIR;
 do
  {
   clrscr();  
   portada();
   textbackground(7);
   SALIR='N';
   gotoxy(3,4);cprintf("");gotoxy(3,4);
   do
    {
     tecla=getch();
     if(tecla==72)
      {
       cprintf(" ");
       if(wherey()==4)
	{
	 gotoxy(3,wherey()+7);
	 cprintf("");
	 gotoxy(3,wherey());
	}
       else
	{
	 gotoxy(3,wherey()-1);
	 cprintf("");
	 gotoxy(3,wherey());
	}
      }
     if(tecla==80)
      {
       printf(" ");
       if(wherey()==11)
	{
	 gotoxy(3,wherey()-7);
	 cprintf("");
	 gotoxy(3,wherey());
	}
       else
	{
	 gotoxy(3,wherey()+1);
	 cprintf("");
	 gotoxy(3,wherey());
	}
     }
    }while(tecla!=13);
   op=wherey();
   if(op==11)
    {
     SALIR='S';
    }
   else
    {
     switch(op)
      {
       case 4: 
	{
	 adic();
	 break;
	}
       case 5:break;//parcial
	  /***********/
       case 6:modifica_nom();break;
       case 7: 
	{ 
	 recorrido_1();
	 break;
	}
       case 8:
	{
	 recorrido_2();
	 break; 
	}
       case 9:recorrido_3();break;
       case 10:eliminar(); break;
      }
    }
  }while(SALIR!='S');
}


void modifica_nom()
 {
  char op,help[8];
  int sw=0,i;
  window(1,1,80,25);
  clrscr();
  window(1,1,80,25);
  if(raiz==NULL)
   {
    clrscr();
    textbackground(1);
    window(25,10,55,14); 
    clrscr();
    cuadro(1,30,1,5);
    textbackground(0);
    gotoxy(8,3);
    printf("NO HAY INFORMACION");
    window(1,1,80,25);
    gotoxy(3,25);
    printf("Presione una tecla");
    getche();
   }
  else
   {
    do
     {  
      window(1,1,80,25);
      textbackground(7);
      textcolor(0);
      clrscr();
      window(1,1,80,25);
      gotoxy(24,1);printf("MODIFICACION  DEL EMPLEADO ");
      gotoxy(3,25);printf("                                        "); 
      gotoxy(3,25);printf("Digite codigo del empleado a Modificar  ");
      _setcursortype(_NORMALCURSOR);
      p=raiz;
      clrscr();
      textbackground(1);
      window(25,10,58,14); 
      clrscr();
      cuadro(1,30,1,5);
      textbackground(0);gotoxy(3,3);printf("Digite codigo");
      i=0;
      window(41,12,46,12);
      clrscr();
      lee_cod(41,12,help);
      x=atol(help);
      while(p!=NULL)
       {
	    sw=0;
	    if(p->cod==x){ 
		sw=1;
		delay(1000); break;
		}
	    if(p->cod>x){
		    i++;
		    p=p->izq;
		 }
		if(p->cod<x){
		    i++;
		    p=p->der;
		  }
	 }
    if(sw==1){
	ver2();
	  gotoxy(5,9);printf("%ld",p->cod);
	  gotoxy(14,9); printf("%s",p->nom);
	  gotoxy(29,9); printf("%s",p->apell);
	  gotoxy(45,9); printf("%s",p->edad);
	  gotoxy(53,9); printf("%c",p->sex);
	  gotoxy(58,9); printf("%s",p->sueldo);
	  gotoxy(69,9); printf("%s",p->bono);
   do{
    window(1,1,80,25);
    gotoxy(3,25);printf("Desea modificar s/n? ..");
    op=toupper(getch());
   }while((op!='S')&&(op!='N'));
  if(op=='S'){  
	gotoxy(20,20); printf("Digite el nombre : ");
	lee_nom(40,20,p->nom);
	gotoxy(14,9); printf("          ");
	gotoxy(14,9); printf("%s",p->nom);
	gotoxy(20,20); printf("Digite el apellido : ");
	lee_nom(40,20,p->apell);
	gotoxy(29,9); printf("          ");
	gotoxy(29,9); printf("%s",p->apell);
	gotoxy(20,20); printf("Digite el edad : ");
	lee_edad(40,20,p->edad);
	gotoxy(45,9); printf("          ");
	gotoxy(45,9); printf("%s",p->edad);
	gotoxy(20,20); printf("Digite el sexo : ");
	gotoxy(53,9); printf("          ");
	gotoxy(53,9); printf("%c",p->sex);
	gotoxy(20,20); printf("Digite el sueldo : ");
	lee_sueldo(40,20,p->sueldo);
	gotoxy(58,9); printf("          ");
	gotoxy(58,9); printf("%s",p->sueldo);
	gotoxy(20,20); printf("Digite el bono : ");
	lee_sueldo(40,20,p->bono);
	gotoxy(69,9); printf("          ");
	gotoxy(69,9); printf("%s",p->bono);
	gotoxy(3,25);printf("Dato modificado           ");
	delay(800);
	}
   }
   if(sw==0){ window(1,1,80,25);gotoxy(3,25);printf("Codigo no existe...                          \a");
	  delay(1000);
	  }
   window(1,1,80,25);
   do{
   gotoxy(3,25);printf("Desea modificar otro empleado s/n?::>       ");
   op=toupper(getch());
   }while((op!='S')&&(op!='N'));  
  }while(op=='S');  
 } 
 
portada();
}
void ver2()
{
int j;
window(1,1,80,25);
textcolor(0);
textbackground(7);
clrscr();
cuadro(1,79,1,24);     
cuadro_3(3,77,2,5);
cuadro_3(3,77,6,11);
 gotoxy(20,3);printf("");
 gotoxy(20,4);printf("              MODIFICAR EMPLEADOS");
 for(j=3;j<=77;j++)
		 {
		 gotoxy(j,8);printf("Ä");
		 }
 for(j=7;j<=10;j++)
		 {
		 gotoxy(12,j);printf("³");
		 gotoxy(27,j);printf("³");
		 gotoxy(42,j);printf("³");
		 gotoxy(49,j);printf("³");
		 gotoxy(56,j);printf("³");
		 gotoxy(67,j);printf("³");
		 }
		 gotoxy(12,6);printf("Â");
		 gotoxy(27,6);printf("Â");
		 gotoxy(42,6);printf("Â");
		 gotoxy(49,6);printf("Â");
		 gotoxy(56,6);printf("Â");
		 gotoxy(67,6);printf("Â");
		 /***/
		 gotoxy(12,11);printf("Á");
		 gotoxy(27,11);printf("Á");
		 gotoxy(42,11);printf("Á");
		 gotoxy(49,11);printf("Á");
		 gotoxy(56,11);printf("Á");
		 gotoxy(67,11);printf("Á");
		 /*****/
		 gotoxy(3,8);printf("Ã");
		 gotoxy(77,8);printf("´");
		 /*******/
		 gotoxy(12,8);printf("Å");
		 gotoxy(27,8);printf("Å");
		 gotoxy(42,8);printf("Å");
		 gotoxy(49,8);printf("Å");
		 gotoxy(56,8);printf("Å");
		 gotoxy(67,8);printf("Å");
		 /*******/
		 gotoxy(5,7);printf("CODIGO");
		 gotoxy(16,7);printf("NOMBRE");
		 gotoxy(31,7);printf("APELLIDO");
		 gotoxy(44,7);printf("EDAD");
		 gotoxy(51,7);printf("SEXO");
		 gotoxy(59,7);printf("SUELDO");
		 gotoxy(70,7);printf("BONO");

		           
gotoxy(3,25);printf("Una tecla para volver al Menu...");
}

void cuadro(int x1,int x2,int y1,int y2)
{
  int j,i;
     for(j=x1;j<=x2;j++)
	  {textcolor(0);
	  gotoxy(j,y1);cprintf("Í");
	  gotoxy(j,y2);cprintf("Í");

       }
     for(i=y1;i<=y2-1;i++)
       {
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
}
void cuadro_3(int x1,int x2,int y1,int y2)
{
  int j,i;
     for(j=x1;j<=x2;j++)
       {
		 textbackground(1);
		 gotoxy(j,y1);printf("Ä");
		 gotoxy(j,y2);printf("Ä");
		 }
	  for(i=y1;i<=y2-1;i++)
		 {
		 gotoxy(x1,i);printf("³");
		 textbackground(0);
		 gotoxy(x2,i);printf("³");
		 }
	  gotoxy(x1,y1);printf("Ú");
	  gotoxy(x2,y1); printf("¿");
	  gotoxy(x1,y2);printf("À");
	  gotoxy(x2,y2); printf("Ù");
	  

}



void adic(){
{  char op,help[8];int sw=0,i;
	window(1,1,80,25);
	clrscr();
	window(1,2,80,25);
for(i=0;i<1920;i++){
cprintf("±");
}
window(1,1,80,25);
 clrscr();
 cuadroff();
do{ 
	  gotoxy(24,9);cprintf("                   ");
	  gotoxy(24,11);cprintf("                   ");
	  gotoxy(24,13);cprintf("   ");
	  gotoxy(24,15);cprintf(" ");
	  gotoxy(24,17);cprintf("                  ");
	  gotoxy(24,19);cprintf("               ");
    gotoxy(3,25);printf("DIGITE CODIGO DE EL EMPLEADO...   ");
    _setcursortype(_NORMALCURSOR);
    p=raiz;
    sw=0;
    i=0;
  lee_cod(24,7,help);
  gotoxy(1,1);printf("%s",help);
  x=atol(help);
  window(1,1,80,25);
  i=1;
    while(p!=NULL){
	    sw=0;
	    if(p->cod==x){ window(1,1,80,25);
		gotoxy(3,25);printf("CODIGO EXISTE..                  \a ");
		sw=1;
		delay(1000); break;
		}
	    if(p->cod>x){
		    i++;
		    p=p->izq;
		 }
		if(p->cod<x){
		    i++;
		    p=p->der;
		  }
		if(i==5){
		   gotoxy(28,20);printf(" NO SE PUEDE INTRODUCIR ");
		   break;
		   }
	 }
    if(sw==0){
	   gotoxy(3,25);printf("Apellido(s) del empleado....      ");
	   lee_nom(24,9,tARBOL.apell);
	   gotoxy(24,9);printf("%s",tARBOL.apell);
	   gotoxy(3,25);printf("Ingrese el Nombre del empleado... ");
	   lee_nom(25,11,tARBOL.nom);
	   gotoxy(25,11);printf("%s",tARBOL.nom);
	   gotoxy(3,25);printf("Digite la Edad del empleado...     ");
	   lee_edad(24,13,tARBOL.edad);
	   gotoxy(24,13);printf("%s",tARBOL.edad);
	   gotoxy(3,25);printf("Digite Sexo del empleado...      ");
	   tARBOL.sex=lee_sex(24,15,'F','M');
	   gotoxy(24,15);printf("%c",tARBOL.sex);
	   gotoxy(3,25);printf("Digite Sueldo del empleado..      ");
	   lee_sueldo(24,17,tARBOL.sueldo);
	   gotoxy(3,25);printf("Digite Deduccion del empleado...      ");
	   lee_sueldo(24,19,tARBOL.bono);

	 if(p==NULL) {p->der=NULL;p->izq=NULL;}
	   nn=malloc(sizeof(tARBOL));
	   nn->cod=x;
	   m[val]=x;
	   val++;
	   strcpy(nn->apell,tARBOL.apell);
	   strcpy(nn->nom,tARBOL.nom);
	   strcpy(nn->edad,tARBOL.edad);
	   nn->sex=tARBOL.sex;
	   strcpy(nn->sueldo,tARBOL.sueldo);
	   strcpy(nn->bono,tARBOL.bono);
	   //demas datos
	   nn->izq=NULL;
	   nn->der=NULL;
	  if(raiz==NULL)
	   {
	    raiz=nn;
	    p=nn;
	 }
    else {
	 p=raiz;
	 i=1;
	 while(p!=NULL){
	    if(p->cod==x){ window(1,1,80,25);
		gotoxy(3,25);printf("CODIGO EXISTE..                  \a ");
		delay(1000); break;
		}
	    if((p->cod>x)&&(p->izq==NULL)){
		 p->izq=nn;break;
	       }
	    if((p->cod>x)&&(p->izq!=NULL)){
		    i++;
		    p=p->izq;
		 }
	    if((p->cod<x)&&(p->der==NULL)){
		 p->der=nn;break;
		  }
		if((p->cod<x)&&(p->der!=NULL)){
		    i++;
		    p=p->der;
	       }
	 
	   /*  if(i==5){
		   gotoxy(28,20);printf(" NO SE PUEDE INTRODUCIR ");
		   break;} */
	 }
	}
	}

window(1,1,80,25);
gotoxy(3,25);printf("Desea adicionar otro ARBOL s/n?::>");
   op=toupper(getche());
 gotoxy(28,20);printf("                              ");
  }while(op=='S');  
 }
}
void cuadroff()
{
int c;
clrscr();
gotoxy(24,4);printf(" Ingreso de datos al Arbol Binario");
gotoxy(13,7);printf("Codigo :");
gotoxy(13,9);printf("Apellido(s) :");textbackground(0);gotoxy(24,9);cprintf("                   ");
gotoxy(13,11);printf("Nombre(s) :");textbackground(0);gotoxy(24,11);cprintf("                   ");
gotoxy(13,13);printf("Edad :");textbackground(0);gotoxy(24,13);cprintf("   ");
gotoxy(13,15);printf("Sexo :");textbackground(0);gotoxy(24,15);cprintf(" ");
gotoxy(13,17);printf("Sueldo :");textbackground(0);gotoxy(24,17);cprintf("                  ");
gotoxy(13,19);printf("Deduccion:");textbackground(0);gotoxy(24,19);cprintf("               ");

}
void inorden(struct ARBOL *p){
  int a=9;
  struct LIFO pila;
  init_pila(&pila);
   while(p){
	   ins_pila(&pila,p);
	   p=p->izq;
    }
   while(!pila_vacia(&pila)){
	   retira_pila(&pila,&p);
	  
	  gotoxy(5,a);printf("%ld",p->cod);
	  gotoxy(29,a); printf("%s",p->apell);
	  gotoxy(14,a); printf("%s",p->nom);
	  gotoxy(45,a); printf("%s",p->edad);
	  gotoxy(53,a); printf("%c",p->sex);
	  gotoxy(58,a); printf("%s",p->sueldo);
	  gotoxy(69,a); printf("%s",p->bono);
	  a++;
	   p=p->der;
	   while(p){
		ins_pila(&pila,p);
		p=p->izq;
		}
	  }
	}
void init_pila(struct LIFO *p)
   {
    p->t=0;
   }
int pila_vacia(struct LIFO *p)
 {
  return(!p->t);
 }
void ins_pila(struct LIFO *p, struct ARBOL *s)
 {
   if(p->t==MAXIMO)
	 printf("LA PILA NO SOPORTA MAS ELEMENTOS");
   else {
	    p->t++;
	    p->a[p->t-1]=s;
	    p->b[p->t-1].apunt=s;
	    p->b[p->t-1].senal=0;
	   }
   }
void retira_pila(struct LIFO *p, struct ARBOL **s)
 {
  if(pila_vacia(p)){
	  printf("La pila esta vacia");
	  *s=NULL;
	 }
    else {
	   *s=p->a[p->t-1];
	    p->t--;
	 }
   }	    	   			 
void pre_orden(struct ARBOL *aux){
	if(aux!=NULL){
	  printf("%d\t",aux->cod);
	  pre_orden(aux->izq);
	  pre_orden(aux->der);
	}
}
void preorden(struct ARBOL *p){
  int a=9;
  struct LIFO pila;
  init_pila(&pila);
   a=9;
   while(p){
	  gotoxy(5,a);printf("%ld",p->cod);
	  gotoxy(29,a); printf("%s",p->apell);
	  gotoxy(14,a); printf("%s",p->nom);
	  gotoxy(45,a); printf("%s",p->edad);
	  gotoxy(53,a); printf("%c",p->sex);
	  gotoxy(58,a); printf("%s",p->sueldo);
	  gotoxy(69,a); printf("%s",p->bono);
	  a++;
	   ins_pila(&pila,p);
	   p=p->izq;
    }
   while(!pila_vacia(&pila)){
	   retira_pila(&pila,&p);
	   p=p->der;
	   while(p){
	  gotoxy(5,a);printf("%ld",p->cod);
	  gotoxy(29,a); printf("%s",p->apell);
	  gotoxy(14,a); printf("%s",p->nom);
	  gotoxy(45,a); printf("%s",p->edad);
	  gotoxy(53,a); printf("%c",p->sex);
	  gotoxy(58,a); printf("%s",p->sueldo);
	  gotoxy(69,a); printf("%s",p->bono);
	  a++;
		ins_pila(&pila,p);
		p=p->izq;
		}
	  }
	}
void post_orden(struct ARBOL *aux){
	if(aux!=NULL){
	  post_orden(aux->izq);
	  post_orden(aux->der);
	  printf("%d\t",aux->cod);
	}
}
void posorden(struct ARBOL *p){
  int i,a=9;
  struct LIFO pila;
  init_pila(&pila);
   while(p){
	   ins_pila(&pila,p);
	   p=p->izq;
    }
   while(!pila_vacia(&pila)){
	   mirar(&pila,&p,&i);
	   if(i==0)
		p=p->der;
		else p=NULL;
		if(p)
			while(p){
				ins_pila(&pila,p);
				p=p->izq;
			   }
		else {
			  retira_pila(&pila,&p);
			  gotoxy(5,a);printf("%ld",p->cod);
			  gotoxy(29,a); printf("%s",p->apell);
			  gotoxy(14,a); printf("%s",p->nom);
			  gotoxy(45,a); printf("%s",p->edad);
			  gotoxy(53,a); printf("%c",p->sex);
			  gotoxy(58,a); printf("%s",p->sueldo);
			  gotoxy(69,a); printf("%s",p->bono);
			  a++;
		    }
	  }
	}
void mirar(struct LIFO *p,struct ARBOL **s,int *i)
{
 if(pila_vacia(p)){
    printf("la pila esta vacia");
    *s=NULL;
    }
    else {
	  *s=p->b[p->t-1].apunt;
	  *i=p->b[p->t-1].senal;
	  p->b[p->t-1].senal=1;
	}
   }
void recorrido_1(){
   window(1,1,80,25);
   clrscr();
   if(raiz==NULL){
   gotoxy(30,10);
    cprintf("NO HAY DATOS...");
   }
   else{
    ver();
    inorden(raiz);
   //	  in_orden(raiz);
  }
  gotoxy(3,25);printf("Presione Una Tecla Para Volver Al Menu..");
  getche();
portada();
}   
void recorrido_2(){
   window(1,1,80,25);
   clrscr();
   if(raiz==NULL){
   gotoxy(30,10);
    cprintf("NO HAY DATOS...");
   }
   else{
    ver();
    preorden(raiz);
 //   pre_orden(raiz);

  }
  gotoxy(3,25);printf("Presione Una Tecla Para Volver Al Menu..");
  getche();
portada();
}   
void recorrido_3(){
   window(1,1,80,25);
   clrscr();
   if(raiz==NULL){
   gotoxy(30,10);
    cprintf("NO HAY DATOS...");
   }
   else{
    ver();
    posorden(raiz);
   // post_orden(raiz);

  }
  gotoxy(3,25);printf("Presione Una Tecla Para Volver Al Menu..");
  getche();
portada();
}   
void ver()
{
int c,j;
textcolor(0);
textbackground(7);
clrscr();
cuadro(1,79,1,24);     //FORMA...
//cuadro_3(3,77,2,5);
cuadro_3(3,77,6,23);
 gotoxy(20,3);printf("        LISTADO GENERAL DE EMPLEADOS");
 for(j=3;j<=77;j++)
		 {
		 gotoxy(j,8);printf("Ä");
		 }
 for(j=7;j<=22;j++)
		 {
		 gotoxy(12,j);printf("³");
		 gotoxy(27,j);printf("³");
		 gotoxy(42,j);printf("³");
		 gotoxy(49,j);printf("³");
		 gotoxy(56,j);printf("³");
		 gotoxy(67,j);printf("³");
		 }
		 gotoxy(12,6);printf("Â");
		 gotoxy(27,6);printf("Â");
		 gotoxy(42,6);printf("Â");
		 gotoxy(49,6);printf("Â");
		 gotoxy(56,6);printf("Â");
		 gotoxy(67,6);printf("Â");
		 /***/
		 gotoxy(12,23);printf("Á");
		 gotoxy(27,23);printf("Á");
		 gotoxy(42,23);printf("Á");
		 gotoxy(49,23);printf("Á");
		 gotoxy(56,23);printf("Á");
		 gotoxy(67,23);printf("Á");
		 /*****/
		 gotoxy(12,23);printf("Á");
		 gotoxy(42,23);printf("Á");
		 gotoxy(49,23);printf("Á");
		 gotoxy(56,23);printf("Á");
		 gotoxy(67,23);printf("Á");
		 
		 gotoxy(3,8);printf("Ã");
		 gotoxy(77,8);printf("´");
		 /*******/
		 gotoxy(12,8);printf("Å");
		 gotoxy(27,8);printf("Å");
		 gotoxy(42,8);printf("Å");
		 gotoxy(49,8);printf("Å");
		 gotoxy(56,8);printf("Å");
		 gotoxy(67,8);printf("Å");
		 /*******/
		 gotoxy(5,7);printf("CODIGO");
		 gotoxy(16,7);printf("NOMBRE");
		 gotoxy(31,7);printf("APELLIDO");
		 gotoxy(44,7);printf("EDAD");
		 gotoxy(51,7);printf("SEXO");
		 gotoxy(59,7);printf("SUELDO");
		 gotoxy(70,7);printf("BONO");

		           
gotoxy(3,25);printf("Presione una tecla");
}
void eliminar()
{
 int i,b=0;
 for(i=0;i<=val;i++)
   {
	p=raiz;q=p;
	while(p!=NULL)
	{
	   if(m[i]==p->cod)
		{ 
		  break;
		}
	   if(m[i]<p->cod)
		{
		  q=p;b=1;
		  p=p->izq;
		}
	   if(m[i]>p->cod)
		{
		   q=p;b=2;
		   p=p->der;
		}
	 }
	if ((p->izq==NULL) && (p->der==NULL))	 
	 {
	  if (b==1) 
	     { free(p);q->izq=NULL;}
	  else
	     { free(p);q->der=NULL;} 
	}
   }

}

int retira_arbol (long int n) {
	struct ARBOL *q,*p = raiz;
	q = buscar(n,&p,NULL);
	if (p == NULL)
		return -1;
	borrar_ARBOL (q,p);
	return 0;
}
struct ARBOL *buscar(long int n,struct ARBOL  **p,struct ARBOL *q) {
	if (*p == NULL)
		return NULL;
	if (n < (*p)->cod) {
		q = *p;
		*p = (*p)->izq;
		q = buscar(n,p,q);
		return q;
	}
	else if (n > (*p)->cod) {
		q = *p;
		*p = (*p)->der;
		q = buscar(n,p,q);
		return q;
	}
	else return q;
}
void borrar_ARBOL (struct ARBOL *q,struct ARBOL *p) {
	struct ARBOL *r,*s,*t;
	if (p->izq == NULL)
		r = p->der;
	else if (p->der == NULL)
		r = p->izq;
	else {
		s = p;
		r = p->der;
		t = r->izq;
		while (t != NULL) {
			s = r;  r = t; t = t->izq;
		}
		if (p != s) {
			s->izq = r->der;
			r->der = p->der;
		}
		r->izq = p->izq;
	}
	if (q == NULL)
		raiz = r;
	else if (p == q->izq)
		q->izq = r;
	else q->der = r;
	free(p);
}
xy(int x, int y)
  {
    int k;
     if (y==0)
       return(1);
     else
       {
	 for (k=1; k<y; k++)
	   x=x*2;
	 return(x);
       }
  }
void calcula_pos(long int q,long int w,long int *e,long int *r)
  {
    if (q==4)
       if (w % 2 != 0)
	  *e=2 + (w / 2 ) * 10;
       else
	  *e=8 + (w / 2 - 1) * 10;
    else
       *e=80 / xy(2,q+1)+(w-1)*2*(80 / xy(2,q+1));
    *r=q*4+2;
  }
void lee_cod(int x,int y,char *cod)
{ int i=0;
  window(x,y,x+4,y);
  textbackground(0);
  textcolor(15);
  clrscr();
  do
  { gotoxy(i+1,1);clreol();
    cod[i]=getche();
    if(cod[i]=='\b'&&i>0) i-=2;
    else if(!isdigit(cod[i])) i--;
    i++;
  }while(i<5);
 cod[i]='\0';
}
void lee_nom(int x,int y,char *nom)
{ int i=0;
  textbackground(0);
  textcolor(15);
  window(x,y,x+13,y);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    nom[i]=getche();
    if(nom[i]=='\b'&&i>0) i-=2;
    else
    {  if(nom[i]=='\r'&&i>0) break;
	  if(nom[i]==' '&&i>0) i++;
	  if(!isalnum(nom[i])) i--;
    }
    i++;
  }while(i<15);
 nom[i]='\0';
 window(1,1,80,25);
}
char lee_sex(int x,int y,char F,char M)
{  char a;
   textbackground(0);
   textcolor(15);
   window(x,y,x,y);clrscr();
   do{
	  gotoxy(x,y);clreol();a=toupper(getche());
	}while(a!=F&&a!=M);
   textbackground(3);
   textcolor(1);
   window(1,1,80,25);
   return(a);
}
void lee_sueldo(int x,int y,char *sueldo)
{ int i=0;
  textbackground(0);
  textcolor(15);
  window(x,y,x+9,y);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    sueldo[i]=getche();
    if(sueldo[i]=='\b'&&i>0) i-=2;
    else
    {
	  if(sueldo[i]=='\r'&&i>0) break;
	 // if(sueldo[i]==' '&&i>0) i++;
	  if(!isdigit(sueldo[i])) i--;
    }
    i++;
  }while(i<10);
 sueldo[i]='\0';
window(1,1,80,25);
}
void lee_edad(int x,int y,char *edad)
{ int i=0;
  window(x,y,x+1,y);
  textbackground(0);
  textcolor(15);
  clrscr();
  do
  { gotoxy(i+1,1);clreol();
    edad[i]=getche();
    if(edad[i]=='\b'&&i>0) i-=2;
    else if(!isdigit(edad[i])) i--;
    i++;
  }while(i<2);
 edad[i]='\0';
 window(1,1,80,25);
}

