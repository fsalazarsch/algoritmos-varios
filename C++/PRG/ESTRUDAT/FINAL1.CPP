#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream.h>
#define MAXIMO 100
void menu_principal();
void menu_recorridos();
class arboles{
struct arbol{
char codigo[15];
char nombre[45];
char apellido[45];
float nota1;
float nota2;
float nota3;
float nota4;
struct arbol *izq,*der;
};
struct elemento {
struct arbol *apunt;
	int senal;
};


struct LIFO {
int t;
struct elemento A[MAXIMO];
struct arbol *a[MAXIMO];
};

public:
struct arbol *pad,*pos,*raiz,*nn;
void busqueda(char codigo[15]);
void introducir();

char *val_cod(int x, int y);

int sw;
struct arbol *raiz_arbol() { return raiz; }
	void inorden(struct arbol *);
	void preorden(struct arbol *);
	void posorden(struct arbol *);
      void capnom(char nom[], int x,int y,int ancho,int *tec);
      void capnot(char not[],int ancho,int x,int y);
      void capcod(char codigo[],int x,int y ,int ancho);
	void mirar (LIFO *p,struct arbol **s,int *i);
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila ( struct LIFO *p, struct arbol *s);
	void retira_pila (struct LIFO *p,struct arbol **s);
arboles() { raiz=NULL;}

};
arboles obj;
/*********validaciones*******/
char  *arboles::val_cod(int x, int y)
{ int i,sw,st, lenght,swc;
  char cad[20];
     sw=1;
    do
      {
	    do{
      gotoxy(x,y);clreol();
      gets(cad); swc=0;
	 st=1;
	 lenght = strlen(cad);
     for( i=0;i<=lenght-1; i++)
	{ 
	if(!(isdigit(cad[i])))
	   { gotoxy(10,10);printf("REINTENTE");
	    getche();
	    gotoxy(10,10);
	    clreol();
	     st=2;
	     swc=1;
	     break;

	      }
	   }
	   if(st==2)
	   {
	   sw=1;
	   }
	   else
	   {
	   sw=2;
	   }
	   }while(swc==1);
  cad[i] =  toupper(cad[i]);
	 return(cad);
	   }while(sw==1);
}
void arboles::capnot(char not[],int ancho,int x,int y)
{
char c=' ';
int n_car=0,a=x-1;
gotoxy(x,y);
 while(c!='\r' && n_car<ancho)
 {
  c=getche();
  a++;
  if(!isdigit(c) && c!='\r'&& !ispunct(c))
  {
   gotoxy(a,y);
   clreol();
   a--;
  }
  else
  {
   not[n_car]=c;
   n_car++;
  }
 }
 not[n_car]='\0';
}
/****************************************************************************/
void arboles::capnom(char nom[],int x,int y,int ancho,int *tec)
{
  int c,nu,i=0;
  char car1;
  c=x;
  gotoxy(c,y);
  do
  {
   do
    car1=toupper(getch());
    while ((car1 < 'A') && (car1 > 'Z') && (car1 != 32) &&
     (car1 != 13) && (car1 != 27));
     if ((((car1 >= 'A') && (car1 <= 'Z')) || (car1 == 32)) && (i < ancho))
      {
       gotoxy(c,y);
       c++;
       nom[i]=car1;
       i++;
       putch(car1);
      }
      else
       if ((car1 == 8) && (c != x))
       {
	i--;c--;
	gotoxy(c,y);
	putchar(32);
	gotoxy(c,y);
       }
      if ((car1 == 13) || (i == ancho))
	 nom[i]='\0';
   }while ((car1 != 13) && (car1 != 27));
   *tec=car1;
}

/*******************************/
void arboles::busqueda(char codigo[15]){
sw=0;
if(raiz==NULL){
 pos=NULL;
pad=NULL;}
else
if(strcmp(codigo,raiz->codigo)==0){
pos=raiz;
pad=NULL;}
else
if(strcmp(codigo,raiz->codigo)<0){
pad=raiz;
pos=raiz->izq;
}
else{
pad=raiz;
pos=raiz->der;
}
while(pos!=NULL){
if(strcmp(codigo,pos->codigo)==0){
sw=1;
break;

}
else{pad=pos;
if(strcmp(codigo,pos->codigo)<0)
pos=pos->izq;

else
pos=pos->der;
}
}
}
/*************************/
void arboles::introducir(){
 int *tec;
char op;
clrscr();
char codigo[10];
char nombre[20],n1[5],n2[5],n3[5],n4[5];
char apellido[30];
float cam1,cam2,cam3, cam4,df;
do{
gotoxy(4,4); cout<<"DIGITE EL CODIGO: ";
strcpy(codigo,val_cod(24,4));
busqueda(codigo);
 }while(sw==1);
gotoxy(4,5);cout<<"DIGITE EL NOMBRE: ";
capnom(nombre,24,5,20,tec);

gotoxy(4,6);cout<<"DIGITE EL APELLIDO: ";
   capnom(apellido,30,6,20,tec);
gotoxy(4,8);cout<<"DIGITE NOTA 1: ";
 do
   {
   gotoxy(24,8);
     clreol();
    capnot(n1,3,24,8);cam1=atof(n1);
    if(cam1>5)
    {
     
     gotoxy(24,8);
     cout<<"Nota fuera de rango";
    delay(500);
     gotoxy(24,8);
     clreol();
     capnot(n1,3,24,8);cam1=atof(n1);
    }
   }while(cam1>5);

gotoxy(4,9);cout<<"DIGITE NOTA 2: ";
   do
   {
     gotoxy(24,9);
     
     clreol();
    capnot(n2,3,24,9);cam2=atof(n2);
    if(cam2>5)
    {
    gotoxy(24,9);
     cout<<"Nota fuera de rango";
    delay(500);
    gotoxy(24,9);
     clreol();
     capnot(n2,3,24,9);cam2=atof(n2);
    }
   }while(cam2>5);
gotoxy(4,10);cout<<"DIGITE NOTA 3: ";
   do
   {
     gotoxy(24,10);
     clreol();
     capnot(n3,3,24,10);cam3=atof(n3);
     if(cam3>5)
     {
      gotoxy(24,10);
     cout<<"Nota fuera de rango";
    delay(500);
     gotoxy(24,10);
     clreol();
      capnot(n3,3,24,10);cam3=atof(n3);
    }
   }while(cam3>5);
gotoxy(4,11);cout<<"DIGITE NOTA 4: ";

   do
   { gotoxy(24,11);
     clreol();
    capnot(n4,3,24,11);cam4=atof(n4);
    if(cam4>5)
    {  

    gotoxy(24,11);
     cout<<"Nota fuera de rango";
    delay(500);
      gotoxy(24,11);
     clreol();
     capnot(n4,3,24,11);cam4=atof(n4);
    }
   }while(cam4 > 5);
    cam1=atof(n1);
    cam2=atof(n2);
    cam3=atof(n3);
    cam4=atof(n4);
df=cam1*0.25+cam2*0.25+cam3*0.20+cam4*0.30;
gotoxy(4,12);
printf("Nota Df: %.f ",df);
if(pos!=NULL){
cout<<"NO SE PUEDE INSERTAR";getche();
}
else
nn = new arbol;
strcpy(nn -> codigo,codigo);
strcpy(nn -> nombre, nombre);
strcpy(nn -> apellido,apellido);
nn->nota1=cam1;
nn->nota2=cam2;
nn->nota3=cam3;
nn->nota4=cam4;
nn->izq=nn->der=NULL;
if(raiz==NULL)
   raiz=nn;
else{
if(strcmp(codigo,pad->codigo)<0){
pad->izq=nn;}
else
pad->der=nn;
}

  
 gotoxy(4,13);cprintf("INTRODUCES OTRO NUMERO [ S/N ] ? :");
 do{
     gotoxy(37,13);clreol();op=toupper(getche());
   }while(op!='S'&&op!='N');
 if(op=='S') introducir();



}
void menu_recorridos(){
char op;
do{
		
	clrscr();
	textcolor(15);textbackground(1);

	gotoxy(17,6);cout<<"CORPORACION UNIVERSITARIA DE SANTANDER";
	gotoxy(23,7);cout<<" ALUMNO JUAN C. VERDECIA";
	gotoxy(28,8);cout<<" A¤o de 1997";
       
	gotoxy(25,10);cout<<" 1. INORDEN";
	gotoxy(25,11);cout<<" 2. PREORDEN";
	gotoxy(25,12);cout<<" 3. POSORDEN";
	gotoxy(25,13);cout<<" 4. VOLVER MENU";
       
	gotoxy(23,15);cout<<" DIGITE UNA OPCION ";

	 op=getch();
	 switch(op){
	  case '1':{clrscr(); obj.inorden(obj.raiz_arbol());getch();break;}
	  case '2':{clrscr(); obj.preorden(obj.raiz_arbol());getch();break;}
	  case '3':{clrscr(); obj.posorden(obj.raiz_arbol());getch();break;}
	      }
 } while (op!='4');
 }
void menu_principal(){ 
 char op;
  do{
	
	clrscr();
	textcolor(15);textbackground(1);

	gotoxy(17,6);cout<<"CORPORACION UNIVERSITARIA DE SANTANDER";
	gotoxy(23,7);cout<<" ALUMNO JUAN C. VERDECIA";
	gotoxy(28,8);cout<<" A¤o de 1997";
       
	gotoxy(25,10);cout<<" 1. CAPTURA";
	gotoxy(25,11);cout<<" 2. RECORRIDOS";
	gotoxy(25,12);cout<<" 3. ELIMINAR";
	gotoxy(25,13);cout<<" 4. CONSULTA";
	gotoxy(25,14);cout<<" 5. VISUALIAR";
	gotoxy(25,15);cout<<" 6. OTRAS CONSULTAS";
	gotoxy(25,16);cout<<" 7. SALIR";
       
	gotoxy(23,18);cout<<" DIGITE UNA OPCION ";
	 op=getche();
	 switch(op){
	  case'1':obj.introducir();break;
	  case'2':menu_recorridos();break;	    
	  case'3':;break;
	  case'4':;break;
	  case'5':;break;
	  case'6':;break;
	  case'7':;break;
    }
 } while (op!='7');
}
void main(){
menu_principal();
}



void arboles::inorden (struct arbol *p)
{
       struct	LIFO pila;int x;float df;

	 x=7;
 clrscr();
 textcolor(15);textbackground(1);
 gotoxy(1,2);cout<<"------------------------------------------------------------------------------";
 gotoxy(14,3);cout<<"***** CORPORACION UNIVERSITARIA DE SANTANDER *****";
 gotoxy(1,4);cout<<"------------------------------------------------------------------------------";
 gotoxy(2,5);cout<<"CODIGO         NOMBRE        APELLIDO      1ra     2da   3ra  4ta  Df ";
 gotoxy(1,6);cout<<"------------------------------------------------------------------------------";

 

	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
 gotoxy(2,x);cout<<p->codigo;
  gotoxy(17,x);cout<<p->nombre;
  gotoxy(31,x);cout<<p->apellido;
  gotoxy(48,x);cout<<p->nota1;
  gotoxy(54,x);cout<<p->nota2;
  gotoxy(60,x);cout<<p->nota3;
  gotoxy(66,x);cout<<p->nota4;
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(70,x);cout<<df;
    x++;
		p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
		}
	}
}

void arboles::init_pila (struct LIFO *p)
{
	p->t = 0;
}

int arboles::pila_vacia (struct LIFO *p)
{
	return (!p->t);
}

void arboles::ins_pila (struct LIFO *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

void arboles::retira_pila (struct LIFO *p,struct arbol **s)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;
	}
}

void arboles::preorden (struct arbol *p)
{
	struct LIFO pila;
	init_pila (&pila);
	int x;float df;

	 x=7;
 clrscr();
 textcolor(15);textbackground(1);
 gotoxy(1,2);cout<<"------------------------------------------------------------------------------";
 gotoxy(14,3);cout<<"***** CORPORACION UNIVERSITARIA DE SANTANDER *****";
 gotoxy(1,4);cout<<"------------------------------------------------------------------------------";
 gotoxy(2,5);cout<<"CODIGO         NOMBRE        APELLIDO      1ra     2da   3ra  4ta  Df ";
 gotoxy(1,6);cout<<"------------------------------------------------------------------------------";

 
	while (p) {
 gotoxy(2,x);cout<<p->codigo;
  gotoxy(17,x);cout<<p->nombre;
  gotoxy(31,x);cout<<p->apellido;
  gotoxy(48,x);cout<<p->nota1;
  gotoxy(54,x);cout<<p->nota2;
  gotoxy(60,x);cout<<p->nota3;
  gotoxy(66,x);cout<<p->nota4;
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(70,x);cout<<df;
    x++;		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		retira_pila (&pila,&p);
		p = p->der;
		while (p) {
 gotoxy(2,x);cout<<p->codigo;
  gotoxy(17,x);cout<<p->nombre;
  gotoxy(31,x);cout<<p->apellido;
  gotoxy(48,x);cout<<p->nota1;
  gotoxy(54,x);cout<<p->nota2;
  gotoxy(60,x);cout<<p->nota3;
  gotoxy(66,x);cout<<p->nota4;
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(70,x);cout<<df;
    x++;			ins_pila (&pila,p);
			p = p->izq;
		}
	}
}



void arboles::posorden (struct arbol *p)
{
	int i;
	struct LIFO pila;
	int x;float df;

	 x=7;
 clrscr();
 textcolor(15);textbackground(1);
 gotoxy(1,2);cout<<"------------------------------------------------------------------------------";
 gotoxy(14,3);cout<<"***** CORPORACION UNIVERSITARIA DE SANTANDER *****";
 gotoxy(1,4);cout<<"------------------------------------------------------------------------------";
 gotoxy(2,5);cout<<"CODIGO         NOMBRE        APELLIDO      1ra     2da   3ra  4ta  Df ";
 gotoxy(1,6);cout<<"------------------------------------------------------------------------------";

	
	while (p) {
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		mirar (&pila,&p,&i);
		if (i == 0)
			p = p->der;
		else p = NULL;
		if (p)
			while (p) {
				ins_pila (&pila,p);
				p = p->izq;
			}
		else {
				retira_pila (&pila,&p);
gotoxy(2,x);cout<<p->codigo;
  gotoxy(17,x);cout<<p->nombre;
  gotoxy(31,x);cout<<p->apellido;
  gotoxy(48,x);cout<<p->nota1;
  gotoxy(54,x);cout<<p->nota2;
  gotoxy(60,x);cout<<p->nota3;
  gotoxy(66,x);cout<<p->nota4;
  df=p->nota1*0.25+p->nota2*0.25+p->nota3*0.2+p->nota4*0.3;
  gotoxy(70,x);cout<<df;
    x++;			
			}
	}
}
void arboles::mirar (struct LIFO *p,struct arbol **s,int *i)
{
	if (pila_vacia (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->A [p->t -1].apunt;
			*i = p->A [p->t -1].senal;
			p->A [p->t - 1].senal = 1;
	}
}


