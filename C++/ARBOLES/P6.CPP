/**************************LIBRERIAS**********************************/
#include<time.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
#include<stdio.h>
#include <dos.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#define l(x) textcolor(x);
#define f(x) textbackground(x);
#include<graphics.h>

/*****************************DECLARACION DE CUADROS**********************/
 void cuadro2();
 void cuadros();
 void cuadro();

/**************************VARIABLES PARA EL MODO GRAFICO***************************/

 int unidad=DETECT,modo;
 char n[3];

/*************************DECLARACION DE LA CLASE********************************/

class arboles {


  struct arbol
  {
    int info;
    char codigo[10];
    char nombre[15];
    char apellido[15];
    int dato;
    float n1,n2,n3,n4,def;
    struct arbol *izq;
    struct arbol *der;
  };struct arbol *raiz,*nn,*p;


/***VARIABLES**TIPO*APUNTADOR* PARA EL*PROCEDIMIENTO**ELIMINAR***************/

  struct arbol *hijo,*pos,*pad,*ptr,*salva,*suc,*padsuc;
  struct arbol *padd;

/******************DEFINICION DE PROCEDIMIENTOD******************************/

  public:
	arboles(struct arbol *a){raiz=a;}
	void adicionar();
	float val_not(int z, int w );
	int val(int x, int y);
	void escribir(int x1, int n, int p, int op);
	void lee_nom(int x,int y,char *nom);
	float lee_not(int x1,int y1 );
	void grafico(arbol *t,int x,int y,int f);
	void visu(arbol *p,int cx,int cy,int g);
	void inicio();
	void menu();
	void inorden(struct arbol *p);
	void cuad_pres(int x1, int y1, int x2, int y2, int op);
	void cuad(int x1,int y1,int x2,int y2);
	void cons_ap();
	void cons_arb();
	void postorden(struct arbol *p);
	void consultas();
	void preorden(struct arbol *p);
	void sacar_pila (struct LIFO *p,struct arbol **s);
	void casoa();
	void casob();
	void  modificar();
	void eliminar();
	void ins_pila (struct LIFO *p, struct arbol *s);
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void colores();
/********************VARIABLES GLOBALES*********************************/
int i;

};
//int i;
/************************FUNCION CUADRO1***********************************************/
void arboles::cuad(int x1,int y1,int x2,int y2)
{
  int i; window(1,1,80,25);
  gotoxy(x1, y1); printf("%c",201); //É
  gotoxy(x2, y1); printf("%c",187); //»
  gotoxy(x1, y2); printf("%c",200); //È
  gotoxy(x2, y2); printf("%c",188); //¼
		 for(i=(x1+1);i<=(x2-1);i++)
		 { gotoxy(i, y1);printf("%c",205);//Í
	 gotoxy(i, y2);printf("%c",205);}
    for(i=(y1+1);i<=(y2-1);i++)
     { gotoxy(x1, i);printf("%c",186); //º
       gotoxy(x2, i);printf("%c",186);}
 }

/*********************FUNCION****CUADRO2*********************************/

void cuadro(int X1,int Y1,int X2,int Y2)
{ int i;
  for(i=X1+1;i<X2;i++)

     { gotoxy(i,Y1);cprintf("Í");   /* ALT 205 "Í" */
       gotoxy(i,Y2);cprintf("Í");
     }
  for(i=Y1+1;i<Y2;i++)
     { gotoxy(X1,i);cprintf("º");   /* ALT 186 "º "*/
       gotoxy(X2,i);cprintf("º");
     }
  gotoxy(X1,Y1);cprintf("É"); /*ALT 201 "É" */
  gotoxy(X1,Y2);cprintf("È"); /*ATL 200 "È" */
  gotoxy(X2,Y1);cprintf("»"); /*ALT 187 "»" */
  gotoxy(X2,Y2);cprintf("¼"); /*ALT 188 "¼" */
}
/**************************************************************************/

/*******************************************************/
void marcar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {
	  case 1: fondo=176; break;

	  case 2: fondo= 177;break;

	  case 3: fondo= 178;break;

	  case 4: fondo= 32;break;

	    default:
			fondo= 32;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }

/********************************************************/
/**************************PINTURA******************************/
void marco2(int ci,int cf,int fi,int ff)
{
 int i3;
 textcolor(1);textbackground(14);
 for(i3=ci;i3<=cf;i3++)
 {
  delay(4); gotoxy(i3,fi); printf("Í");
  delay(4); gotoxy(i3,ff); printf("Í");
  }
 for(i3=fi;i3<=ff;i3++)
 {
  delay(4); gotoxy(ci,i3); printf("º");
  delay(4); gotoxy(cf,i3); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(0);
 }

/*********************************************************************/
void marco(int ci,int cf,int fi,int ff)
{
 int i4;
 textcolor(1);textbackground(14);
 for(i4=ci;i4<=cf;i4++)
 {
  delay(4); gotoxy(i4,fi); printf("Í");
  delay(4); gotoxy(i4,ff); printf("Í");
  }
 for(i4=fi;i4<=ff;i4++)
 {
  delay(4); gotoxy(ci,i4); printf("º");
  delay(4); gotoxy(cf,i4); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(0);
 }


/**************************** I N I  C I O *********************************/
void main()
{
  arboles objeto(NULL);
  objeto.menu();
  getche();

}

/**************************MENU3*************************************/
void arboles::menu()
{
 int tecla,f,i,j;
 char opciones[25][45];


 strcpy(opciones[7]," ADICIONAR  ");
 strcpy(opciones[8]," MODIFICAR  ");
 strcpy(opciones[9]," ELIMINAR   ");
 strcpy(opciones[10],"R.PREORDEN ");
 strcpy(opciones[11],"R.INORDEN  ");
 strcpy(opciones[12],"R.POSTORDEN");
 strcpy(opciones[13],"M.GRAFICO  ");
 strcpy(opciones[14],"SALIR      ");
   do
 {
 textcolor(15); textbackground(0);
 clrscr();
  marco(2,79,2,24);
  textcolor(14); textbackground(0);
  marcar(3,3,19,5,3);
  marcar(3,16,19,23,3);
  marco2(2,20,2,24);
  marco2(21,78,3,5);
 textbackground(1);
 marco(3,19,3,5);
  marco2(3,19,6,15);

 for (i=22;i<=78;i++)
  {
   for (j=6;j<=23;j++)
   {
    gotoxy(i,j);textbackground(3);cprintf(" ");
   }
  }


 for (i=23;i<=31;i++)
  {
   for (j=7;j<=14;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

 for (i=69;i<=77;i++)
  {
   for (j=7;j<=14;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

  gotoxy(42,4);textcolor(15);cprintf(" MENU PRINCIPAL ");

 for(f=7; f<=14;f++)
 {
  gotoxy(6,f); cprintf(opciones[f]);
  }
  f=7;
  textcolor(0); textbackground(15);
  gotoxy(6,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(6,f);cprintf(opciones[f]);
     if(f!=14)
     f=f+1;
     else

    f=7;

    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(6,f);cprintf(opciones[f]);
   if(f!=7)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(6,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {



  case 7:adicionar(); break;
  case 8:modificar(); break;
  case 9:eliminar(); break;
  case 10:preorden(raiz);getche(); break;
  case 11:inorden(raiz); getche();break;
  case 12:postorden(raiz);getche();break;
     case 13:
	 {   initgraph(&unidad,&modo,"..\\bgi");
	      setcolor(15);
	      cuad(2,3,79,24);

	      setcolor(1);

	      delay(500);
	      setcolor(14);
			grafico(raiz,320,60,320);
			getch();
			visu(raiz,320,60,320);
			setcolor(1);
			setcolor(4);
			settextstyle(1,0,1);
			outtextxy(200,380,"PULSE ENTER PARA REGRESAR");
			getch();
			closegraph();
			break; }


}

}
 while(f!=14);


 }

/*-------------------------------------------------------------------*/

/*************************FUNCION ADICIONAR*******************************************/

 void  arboles::adicionar()
  {
   char nombre[15];
   char apellido[15];
   float n1,n2,n3,n4,ef;
   char op,info[3],co[5];
   int dato,i,j;
   int sw,st;
   char valido;
   int n;

do{
  clrscr();


  cuad(3,3,40,5);
  cuad(3,6,13,14);
  cuad(14,6,26,14);
  cuad(27,6,38,14);

  gotoxy(32,2);textcolor(15);cprintf(" REGISTRO ADICIONAR...");
  delay(150);
  textbackground(0);
  i=0;
  textcolor(15);gotoxy(4,4);cout<<"CODIGO";
  textcolor(15);gotoxy(16,4);cout<<"NOMBRE";
  textcolor(15);gotoxy(29,4);cout<<"APELLIDO";

 do
 {

	 gotoxy(i+7,7);
	 info[i]=getche();
	 if(info[i]=='\d'&&i>0) i-=2;
	 else
	  {
	  if(info[i]=='\r'&&i>0) break;
	  if(!isdigit(info[i])) i--;
	  }
	 i++;
  }while(i<5);

  info[i]='\0';
  dato=atoi(info);
  p=nn=raiz;i=1;
  while((dato!=p->dato)&&(nn!=NULL)&&(i<=6))
  {
	 p=nn;
	 if(dato<p->dato)
		nn=p->izq;
	 else

		nn=p->der;
	 i++;
  }
  if(dato==p->dato)
	 {    delay(50);
	 gotoxy(5,16);textcolor(252);cprintf(" YA EXISTE...");
	  delay(150);

	 }
  else
	if(i==6)
	  {
	  gotoxy(14,12);cout<<"EL NUMERO  NO SE PUEDE INTRODUCIR";
	  }
	else
	{


	 lee_nom(16,7,nombre);
	 textcolor(15);textbackground(15);
	 cuad(3,6,13,14);
	 cuad(14,6,26,14);
	 cuad(27,6,38,14);
	 textcolor(15);textbackground(15);


	 lee_nom(29,7,apellido);
	 textcolor(15);textbackground(15);
	 cuad(3,6,13,14);
	 cuad(14,6,26,14);
	 cuad(27,6,38,14);
	 textcolor(15);textbackground(15);

	  nn=new arbol;
	  nn->dato=dato;
	  strcpy(nn->nombre,nombre);
	  strcpy(nn->apellido,apellido);

	  nn->izq=NULL;
	  nn->der=NULL;


     if(raiz==NULL)
       raiz=nn;

     else
     {
     if(dato<p->dato)
	p->izq=nn;
       else
	p->der=nn;


	}

		      }

  cuad(71,6,79,14);
  textcolor(15);textbackground(1);
  gotoxy(24,20);cprintf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');



}
/************************MAXIMO DE LA PILA***********************************************/
#define MAXIMO 20

struct LIFO {
	int t;
	struct arbol *a[MAXIMO];
};



/**********************RECORRIDO***PREORDEN**********************************/
void arboles::preorden (struct arbol *p)
{

struct LIFO pila;
void init_pila (struct LIFO *p);
int pila_vacia (struct LIFO *p);
void ins_pila (struct LIFO *p, struct arbol *s);
void sacar_pila (struct LIFO *p,struct arbol **s);
init_pila (&pila);

int f,i,j;
float def;

clrscr();

 f=8;

  textcolor(15);
  cuad(25,4,53,6);
  cuad(25,7,32,14);
  cuad(35,7,43,14);
  cuad(45,7,53,14);

  delay(50);
  gotoxy(20,2);textcolor(15);cprintf(" R E C O R R I D O - P R E O R D E N ");
  gotoxy(16,18);textcolor(252);cprintf(" P U L S E - E N T E R - P A R A - O P E R A R ");


 textcolor(15); gotoxy(26,5);cprintf("CODIGO   NOMBRE   APELLIDO");


while (p) {
  gotoxy(26,f);cout<<p->dato;
  gotoxy(36,f);cout<<p->nombre;
  gotoxy(46,f);cout<<p->apellido;
   f++;
	ins_pila (&pila,p);
	p = p->izq;
    }
	while (!pila_vacia (&pila)) {
	sacar_pila (&pila,&p);
	p = p->der;
	while (p) {
	gotoxy(4,f);cout<<p->dato;
	gotoxy(12,f);cout<<p->nombre;
	gotoxy(20,f);cout<<p->apellido;

    f++;
	ins_pila (&pila,p);
	p = p->izq;
     }
   }
}



/*******************************************************************/
void init_pila (struct LIFO *p)
{
	p->t = 0;
}
/*****************************************************************/
int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}


/***************************FUNCION INSERTAR PILA***************************************/
void ins_pila (struct LIFO *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas datos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

/*************************FUNCION VACIAR PILA*********************************************/
void sacar_pila (struct LIFO *p,struct arbol **s)
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

/**************************RECORRIDO INORDEN*********************************************/
void arboles::inorden (struct arbol *p)
{
	int f,i,j;
	float def;
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct arbol *s);
	void sacar_pila (struct LIFO *p,struct arbol **s);
	init_pila (&pila);


 f=8;
 clrscr();
  textcolor(15);
  cuad(25,4,53,6);
  cuad(25,7,32,14);
  cuad(35,7,43,14);
  cuad(45,7,53,14);

      delay(50);

  gotoxy(25,2);textcolor(15);cprintf(" R E C O R R I D O - I N O R D E N ");
  gotoxy(16,18);textcolor(252);cprintf("  P U L S E - E N T E R - P A R A - O P E R A R");

     gotoxy(26,5);cout<<"CODIGO    NOMBRE   APELLIDO";



	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		sacar_pila (&pila,&p);



  gotoxy(26,f);cout<<p->dato;
  gotoxy(36,f);cout<<p->nombre;
  gotoxy(46,f);cout<<p->apellido;


    f++;
		p = p->der;
		while (p) {
			ins_pila (&pila,p);
			p = p->izq;
		}
	}


}

/*************************FUNCION MODIFICAR**********************************/
 void  arboles::modificar()
 {
  int f,i,j;
  float def;
  char op;
  char nombre[15];
  char apellido[15];
  int dato;
  float n1,n2,n3,n4;
  struct LIFO pila;
  void init_pila (struct LIFO *p);
  int pila_vacia (struct LIFO *p);
  void ins_pila (struct LIFO *p, struct arbol *s);
  void sacar_pila (struct LIFO *p,struct arbol **s);
  init_pila (&pila);

 do{
  clrscr();

  gotoxy(20,2);textcolor(252);cprintf(" R E G I S T R O - M O D I F I C A R ");
  gotoxy(8,4);printf(" CODIGO A  MODIFICAR : ");gotoxy(31,4);scanf("%d",&dato);

  p=raiz;
  while(p!=NULL)
  {
   if(dato==p->dato)
    {

 for (i=8;i<=32;i++)
  {
   for (j=6;j<=20;j++)
   {
    gotoxy(i,j);textbackground(0);cprintf(" ");
   }
  }


	 cuad(8,6,32,20);
	 cuad(10,9,20,12);
	 cuad(21,9,30,12);
	 cuad(10,13,30,15);



    gotoxy(35,7);textcolor(15);cprintf("DATOS A MODIFICAR");
    gotoxy(10,7);textcolor(15);cprintf("DATOS PROCESADOS");
    textcolor(15);gotoxy(10,8);cprintf("CODIGO: ");
    textcolor(15);gotoxy(11,10);cprintf("NOMBRE");
    textcolor(15);gotoxy(35,9);cprintf("NOMBRE:");
    gotoxy(44,9);printf("         ");
    textcolor(15);gotoxy(22,10);cprintf("APELLIDO");
    textcolor(15);gotoxy(35,10);cprintf("APELLIDO:");
    gotoxy(44,10);printf("         ");

    //cuad(10,16,30,18);
    gotoxy(17,8);cout<<p->dato;
    gotoxy(11,11);cout<<p->nombre;
    gotoxy(22,11);cout<<p->apellido;
	  cuad(34,6,66,16);

    for (i=34;i<=66;i++)
   {
    for (j=17;j<=20;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }



 do{
    gotoxy(35,18);printf("MODIFICAR  NOMBRE [S/N]");
    op=toupper(getche());
    }while(op!='N'&& op!='S');
     if (op=='S'){gotoxy(44,9); scanf("\n");gets(p->nombre);}
       else {gotoxy(44,9);cout<<p->nombre;}


  do{gotoxy(35,18);printf("MODIFICAR  APELLIDO [S/N]");
    op=toupper(getche());
    }while(op!='N'&& op!='S');
     if (op=='S'){ gotoxy(44,10); scanf("\n");gets(p->apellido); }
       else { gotoxy(44,10); cout<<p->apellido; }

	break;
   }

  else if(p->dato>dato)
	 { p=p->izq; }

      else

	p=p->der;

  }

  if(p==NULL)
   { gotoxy(10,13);printf(" \EL CODIGO NO EXISTE \a");getch();}

     textcolor(15);textbackground(1);
     cuad(34,17,66,20);
     gotoxy(35,18);printf("DESEA SEGUIR MODIFICAR [S/N]");
     op=toupper(getche());
	 }while(op!='N');


 }


/**************************SUBFUNCION ELIMINAR*CASOA****************************************/
void arboles::casoa()
{

if (((pos->izq)==NULL) && ((pos->der)==NULL))
	hijo=NULL;
	else if ((pos->izq)!=NULL)
		  hijo=pos->izq;
	else
		  hijo=pos->der;

if (pad!=NULL)
	if ((pos==pad->izq))
		pad->izq=hijo;
	else
		pad->der=hijo;
else
	raiz=hijo;

}
/***************************SUBFUNCION ELIMINAR CASOB****************************************/
void arboles::casob()
{
ptr=pos->der;
salva=pos;
while (ptr->izq!=NULL)
{	salva=ptr;
	ptr=ptr->izq;
}
suc=ptr;
padsuc=salva;
padd=pad;
pos=suc;pad=padsuc;casoa();pos=p;
pad=padd;

if (pad!=NULL)
	if (pos==pad->izq)
		pad->izq=suc;
	else
		pad->der=suc;
else
	raiz=suc;
	suc->izq=pos->izq;
	suc->der=pos->der;
}



/***************************FUNCION ELIMINAR*******************************************/

 void arboles::eliminar()

{
   int i,j;
   float def;
	char op;
   char info[9];
   int dato;


 do{



  clrscr();

    gotoxy(30,4);textcolor(15);cprintf(" REGISTRO ELIMINAR ");
    gotoxy(11,7);cprintf(" CODIGO A  ELIMINAR : ");gotoxy(32,7);scanf("%d",&dato);


  i=0;
 cuad(9,8,30,17);

  textcolor(15);gotoxy(10,9);cout<<"CODIGO   : ";
  textcolor(15);gotoxy(10,10);cout<<"NOMBRE   : ";
  textcolor(15);gotoxy(10,11);cout<<"APELLIDO : ";

  pad=NULL;
  p=raiz;
  while(p!=NULL)
  {
   if(dato==p->dato)
    {
	 gotoxy(21,9);cout<<p->dato;
	 gotoxy(21,10);cout<<p->nombre;
	 gotoxy(21,11);cout<<p->apellido;

	  do{
	  cuad(7,19,40,21);
	  gotoxy(8,20);printf("DESEA ELIMINAR ESTE NODO [S/N]");
	  op=toupper(getche());
	 }while(op!='N'&& op!='S');
	 if (op=='S')
	 {
		ptr=NULL;salva=NULL;suc=NULL;padsuc=NULL;

		pos=p;dato=p->dato;hijo=NULL;
		if (((pos->der)!=NULL)&&((pos->izq)!=NULL))
		casob();
		else
		casoa();
//			 cuad(38,7,65,16);
			 delay(14);gotoxy(40,9);cout <<"ELEMENTO ELIMINADO\n";break;

	  }
	 if (op=='N')
	 { break;
	  }
     }

  else if(p->dato>dato)
	 { pad=p;p=p->izq; }

      else {
	pad=p;
	p=p->der;
	}
  }

if(p==NULL)
{ 	gotoxy(8,18);
	printf(" \EL CODIGO NO EXISTE \n");
}

  textcolor(15);textbackground(1);
  gotoxy(8,20);cprintf(" DESEA ELIMINAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');

}


/**************************MODO GRAFICO***************************************************/

void arboles::grafico(arbol *t,int x,int y,int f)
{
  if(t!=NULL)
 {

    itoa(t->dato,n,10);
    outtextxy(x-8,y-4,n);
    circle(x,y,15);
    if(t->izq!=NULL)
	line(x,y+15,x-f/2,(y+70)-15);
    if(t->der!=NULL)
	line(x,y+15,x+f/2,(y+70)-15);
    f=f/2;
    grafico(t->izq,x-f,y+70,f);
    grafico(t->der,x+f,y+70,f);
  }
}
void arboles::visu(arbol *p,int cx,int cy,int g)  // < Este procedimineto fue realizando tomando como base el recorrido inorden de forma recursiva >
{
   if(p!=NULL)
   {

     itoa(p->dato,n,10);
     setcolor(12); // LIGHTRED   < El modo grafico no acepta BLINK >
	 for (i=1;i<=20;i++)
	 {
    setcolor(1);
    circle(cx,cy,15);delay(100);
    setcolor(14);
    circle(cx,cy,15);
    delay(100);

    }

    setcolor(15);

     setcolor(15); // WHITE
     outtextxy(cx-8,cy-4,n);
     circle(cx,cy,15);

     if(p->izq!=NULL)       //	< Si hay nodos a la izquierda >
       line(cx,cy+15,cx-g/2,(cy+70)-15);
     if(p->der!=NULL)       //	< Si hay nodos a la derecha >
       line(cx,cy+15,cx+g/2,(cy+70)-15);
	  g=g/2;                 //	< Dividir por mitades sectores de pantalla >
     visu(p->izq,cx-g,cy+70,g); //	< Moverse a la izquierda >
     visu(p->der,cx+g,cy+70,g); //	< MOverse a la derecha >
	}
}


/**********************VALIDACION*DE*TIPO*FLOAT**************************************************/
float arboles::val_not(int z, int w )
 { int i,n,sw;
   char nota[10];
   float not;
 do
 {
  do
   {
    gotoxy(z,w);sw=0;
    clreol();
    scanf("\n");
    gets(nota);
	 if(isdigit(nota[0])==0) sw=1;
    else
      { if((nota[1]!='.')&&(( n=strlen(nota)-1) > 0 )) sw=1;
	else
	 { n=strlen(nota);
	   if(n>1)
	    { for(i=2;i<n;i++)
	       if(isdigit(nota[i])==0) sw=1;
	    }
	 }
      }
   }while(sw==1);
  not=atof(nota);
    if((not>5)||(not<0))
      sw=1;
   }while(sw==1);
return(not);
}


/*******************VALIDACION*DE*TIPO*CARACTER******************************/

void arboles::lee_nom(int x,int y,char *nom)
{ int i=0;
  textbackground(1);
  textcolor(15);
  window(x,y,x+13,y);clrscr();
  do
  { gotoxy(i+1,1);clreol();
    nom[i]=getche();
    if(nom[i]=='\b'&&i>0) i-=2;
    else
    {  if(nom[i]=='\r'&&i>0) break;
       if(nom[i]==' '&&i>0) i++;
       //if(!(isalpha(apellido[i])))
       if(!isalpha(nom[i])) i--;
    }
    i++;
  }while(i<14);
 nom[i]='\0';
}
/***********************************************************************/
#define MAXIMO 20

struct elem {
	struct arbol *apunt;
	int senal;
};

/*************************************************************************/
struct LIFO1 {
	int t;
	struct elem a[MAXIMO];
};

/************************************RECORRIDO PREORDEN**************************************/

void arboles::postorden (struct arbol *p)
{
	int i,j,x,f;
	float def;

	void mirar (struct LIFO1 *p,struct arbol **s,int *i);
	void init_pila1 (struct LIFO1 *p);
	int pila_vacia1 (struct LIFO1 *p);
	void ins_pila1 (struct LIFO1 *p,struct arbol *s);
	void retira_pila1 (struct LIFO1 *p,struct arbol **s);

	struct  LIFO1 pila;
	init_pila1 (&pila);

  clrscr();



 f=8;

  textcolor(15);
  cuad(25,4,53,6);
  cuad(25,7,32,14);
  cuad(35,7,43,14);
  cuad(45,7,53,14);


   gotoxy(22,2);textcolor(15);cprintf(" R E C O R R I D O - P O S T O R D E N ");
  gotoxy(16,18);textcolor(252);cprintf("  P U L S E - E N T E R - P A R A - O P E R A R");

     gotoxy(26,5);cout<<"CODIGO    NOMBRE   APELLIDO";


	while (p) {
		ins_pila1 (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia1 (&pila)) {

		mirar (&pila,&p,&i);

		if (i == 0)
			p = p->der;
		else p = NULL;
		if (p)
			while (p) {
				ins_pila1 (&pila,p);
				p = p->izq;
			}
		else {

				retira_pila1 (&pila,&p);
  gotoxy(26,f);cout<<p->dato;
  gotoxy(36,f);cout<<p->nombre;
  gotoxy(46,f);cout<<p->apellido;
  f++;
	}


  }

  getche();

}



//***************************************************************/
void init_pila1 (struct LIFO1 *p)
{
	p->t = 0;
}

/*********************************************************************/
int pila_vacia1 (struct LIFO1 *p)
{
	return (!p->t);
}

/********************************************************************/
void ins_pila1 (struct LIFO1 *p,struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a[p->t - 1].apunt = s;
			p->a[p->t - 1].senal = 0;
	}
}


/**********************************************************************/
void retira_pila1 (struct LIFO1 *p,struct arbol **s)
{
	if (pila_vacia1 (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1].apunt;
			p->t--;
	}
}

/*************************************************************************/
void mirar (struct LIFO1 *p,struct arbol **s,int *i)
{
	if (pila_vacia1 (p) )  {
		printf ("la pila esta vacia\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1].apunt;
			*i = p->a [p->t -1].senal;
			p->a [p->t - 1].senal = 1;
	}
}


/**********************************************************************/




