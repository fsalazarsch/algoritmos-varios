#include<stdio.h>
#include<io.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<time.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<iostream.h>
/******************************************************************/
 void marco();
 void cuadros();
 void letras();

class pacho
{

  struct arbol
  { char codigo[10];
    char nombre[15];
    char apellido[15];
    int elemento;
    float n1,n2,n3,n4;
    struct arbol *izquierdo;
    struct arbol *derecho;
  };struct arbol *raiz,*nn,*p;

  public:
	pacho(struct arbol *a){raiz=a;}
	void opcion_2();
	void menu();
        void adicionar();
        void consultar();
        void presentacion();
        float val_not(int z, int w );
        int val(int x, int y);
        void cons_inorden(struct arbol *p);
	void reloj();
        void cons_ap();
        void cons_arb(); 
	void cons_postorden(struct arbol *p); 
	void opcion_1();
        void teoria();
        void clave();
        void cons_preorden(struct arbol *p);
        void sacar_pila (struct LIFO *p,struct arbol **s);
        void ins_pila (struct LIFO *p, struct arbol *s);
        void ins_izquierdo (struct arbol *p,int n);
        void init_pila (struct LIFO *p);
        val_ent();
        void ins_derecho (struct arbol *p,int n);
        int pila_vacia (struct LIFO *p);

     struct 
 {
  unsigned char  ti_min;
  unsigned char  ti_hour;
  unsigned char  ti_hund;
  unsigned char  ti_sec;
 }t;

 };

/***********************************************************/
void tiempo(int x,int y)
{
 time_t t;
 time(&t);gotoxy(x,y);
 cprintf("%s",ctime(&t));
}

/*********************************************************/
int lee_clave()
{
 char tecla,cad[10];
 int  k=0,sw=0;  
 do
 {  
  k++;  
  tecla=tolower(getch());putchar('*');
  if(k==1 && tecla=='a')sw++;
  if(k==2 && tecla=='d')sw++;
  if(k==3 && tecla=='r')sw++;
  if(k==4 && tecla=='i')sw++;
  if(k==5 && tecla=='a')sw++;
  if(k==6 && tecla=='n')sw++;
  if(k==7 && tecla=='a')sw++;
 }while(k<=7 && sw<=6);
 return(sw);
}

/************************************************************/
void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("п");
    gotoxy(i,y2); cprintf("м");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("л");
    gotoxy(x2,i); cprintf("л");
  }

}

/***************************cortina*****************************/

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

/**********************************marco*****************************/
void marco(ci,cf,fi,ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Э");
  delay(4); gotoxy(i,ff); printf("Э");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("К");
  delay(4); gotoxy(cf,i); printf("К");
  }
 gotoxy(ci,fi); printf("Щ");
 gotoxy(ci,ff); printf("Ш");
 gotoxy(cf,fi); printf("Л");
 gotoxy(cf,ff);
 printf("М");
 textcolor(14); textbackground(0);
 }


/*************************teoria**********************************/
void pacho::teoria()
{
clrscr();
textmode(BW40);textcolor(4);
textcolor(14);textbackground(0); 

gotoxy(3,3);cprintf("APLICACION DE LA TEORIA DE ARBOLES   ");
textcolor(4);
gotoxy(2,8); cprintf(" LAS ESTRUCTURAS DE TIPO ARBOL        ");
gotoxy(2,9); cprintf(" SE USAN PARA REPRESENTAR DATOS       ");
gotoxy(2,10);cprintf(" CON UNA RELACION JERARQUICA ENTRE    ");                  
gotoxy(2,11);cprintf(" SUS ELEMENTOS .                      ");
gotoxy(2,13);cprintf(" LA DEFINICION DE  ARBOL IMPLICA UNA  ");
gotoxy(2,14);cprintf(" NATURALEZA RECURSIVA,YA QUE UN ARBOL ");
gotoxy(2,15);cprintf(" O ES VACIO O SE CONSIDERA FORMADO POR");
gotoxy(2,16);cprintf(" UN NODO RAIZ Y UN CONJUNTO DISYUNTO  ");
gotoxy(2,17);cprintf(" DE ARBOLES QUE SE LLAMAN SUBARBOLES  ");
gotoxy(2,18);cprintf(" DE RAIZ .                            ");
gotoxy(8,22);textcolor(252);cprintf(" PRESIONE CUALQUIER TECLA...");
getch();
textmode(BW80);
}

/***********************************PRESENTACION************************/
void pacho::presentacion()
{int i;
clrscr();
 textcolor(14); textbackground(3);
 marcar(2,2,79,24,1);
 textcolor(14);textbackground(3);
 textcolor(14); textbackground(15);
 marcar(2,2,79,8,1);
 textcolor(14);textbackground(15);
 cuadros(2,2,79,24);
 marco(2,79,2,24);
 cuadros(2,2,79,8);
 marco(2,79,2,8);

textcolor(14);
delay(500);
textcolor(15);
gotoxy(16,3);cprintf("U N I V E R S I D A D    D E    S A N T A N D E R ");
delay(150);
gotoxy(32,4);cprintf("MODELOS DE PROGRAMACION");
delay(150);
gotoxy(26,5);cprintf("FRANCISCO JAVIER CARDENAS GARCIA");
delay(150);
gotoxy(32,6);cprintf("CODIGO 96132021");
delay(50);
gotoxy(26,23);textcolor(252);cprintf(" PRESIONE CUALQUIER TECLA...");
delay(150);
delay(50);
gotoxy(21,19);textcolor(252);cprintf(" PRESENTADO AL ING. ALFONSO QUINTERO...");
delay(150);


textcolor(1);textbackground(14);
letras();
textcolor(1);textbackground(14);
getch();
textcolor(14);textbackground(3);
clrscr();
}
/*******************************letras***************************/ 
void letras()
{
  int i;
  delay(10);
  gotoxy(64,16);cprintf("лл");
  for(i=10;i<=16;i++)
  {
  delay(150);
    gotoxy(20,i);cprintf("л");
    gotoxy(21,i);cprintf("л");
    gotoxy(30,i);cprintf("л");
    gotoxy(31,i);cprintf("л");
    gotoxy(37,i);cprintf("л");
    gotoxy(38,i);cprintf("л");
    gotoxy(40,i);cprintf("л");
    gotoxy(41,i);cprintf("л");
    gotoxy(48,i);cprintf("л");
    gotoxy(49,i);cprintf("л");
    gotoxy(53,i);cprintf("л");
    gotoxy(54,i);cprintf("л");



  }

/********************************************/
    for(i=67;i<=76;i++)
  {
   gotoxy(i,10); cprintf("м");
   gotoxy(i,16); cprintf("л");
   gotoxy(i,13); cprintf("л");
  
}

  for(i=10;i<=16;i++)
  {
  delay(150);

    gotoxy(67,i);cprintf("л");
    gotoxy(68,i);cprintf("л");
    gotoxy(75,i);cprintf("л");
    gotoxy(76,i);cprintf("л");

 }

/******************************************/
    for(i=7;i<=16;i++)
  {
   gotoxy(i,10); cprintf("м");
   gotoxy(i,13); cprintf("л");
  }

    for(i=40;i<=49;i++)
  {
   gotoxy(i,10); cprintf("м");
  
  }
     for(i=53;i<=54;i++)
  {
   gotoxy(i,10); cprintf("м");
  
  }


/*******************************************/
    for(i=10;i<=16;i++)
  {
  delay(150);
    gotoxy(7,i);cprintf("л");
    gotoxy(8,i);cprintf("л");

  }

     for(i=10;i<=16;i++)
  {
   gotoxy(15,i);cprintf("л");
   gotoxy(16,i);cprintf("л");

  }

   for(i=8;i<=15;i++)
  {
   gotoxy(i,13); cprintf("м");
   gotoxy(i,13); cprintf("л");
 }



/******************************************/
    for(i=13;i<=16;i++)
  {
  delay(150);
    gotoxy(26,i);cprintf("л");
    gotoxy(25,i);cprintf("л");

  }

     for(i=10;i<=13;i++)
  {
   gotoxy(28,i);cprintf("л");
   gotoxy(27,i);cprintf("л");
  }
 

    for(i=20;i<=28;i++)
  {
   gotoxy(i,10); cprintf("м");
   gotoxy(i,13); cprintf("л");
  }

  for(i=30;i<=38;i++)
  {
   gotoxy(i,10); cprintf("м");
   gotoxy(i,16); cprintf("л");
  }




/*************************************/
  for(i=40;i<=48;i++)
  {
   gotoxy(i,16); cprintf("м");
   gotoxy(i,16); cprintf("л");
 }
  for(i=53;i<=60;i++)
  {
   gotoxy(i,16); cprintf("л");

 }
  for(i=30;i<=38;i++)
  {
   gotoxy(i,13); cprintf("м");
   gotoxy(i,13); cprintf("л");
 }


 }



/*******************************************pantalla**********************/
void pacho::menu()
{
 int tecla,f,i;
 char opciones[25][45];
 
 
  strcpy(opciones[6]," ADICIONAR   ");
  strcpy(opciones[7]," OPCION 1    ");
  strcpy(opciones[8]," OPCION 2    ");
  strcpy(opciones[9]," CONSULTAR   ");
  strcpy(opciones[10]," SALIR       ");
  
do
 {
 
 clrscr();
 textcolor(14); textbackground(3);
 marcar(2,2,80,24,1);
 textcolor(14); textbackground(15);
 cuadros(2,2,40,12); 
 marco(2,40,2,12);
 textcolor(14); textbackground(15);
 marco(2,80,22,24);
 cuadros(2,2,40,4); 
 marco(2,40,2,4);
 textcolor(14); textbackground(15);
     delay(14);gotoxy(3,5);cprintf (" ммммммм                             ");
     delay(14);gotoxy(3,6);cprintf (" лл   лл                             ");
     delay(14);gotoxy(3,7);cprintf (" ллллллл                             ");    
     delay(14);gotoxy(3,8);cprintf (" лл   лл                             ");
     delay(14);gotoxy(3,9); cprintf(" лл   лл                             ");
     delay(14);gotoxy(3,9); cprintf("                                     ");
     delay(14);gotoxy(3,10); cprintf("                                     ");
     delay(14);gotoxy(3,11); cprintf("                                     ");

delay(50);
gotoxy(3,23);textcolor(15);cprintf(" START    TC ");
delay(150);
 
gotoxy(3,3);cprintf("     M E N U   P R I N C I P A L     ");
tiempo(56,23);
                                                           
 for(f=6; f<=10;f++)
 {
  gotoxy(15,f); cprintf(opciones[f]);
  }
  f=6;
  textcolor(1); textbackground(0);
  gotoxy(15,f); cprintf(opciones[f]);
  textcolor(14); textbackground(0);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(3);
     gotoxy(15,f);cprintf(opciones[f]);
     if(f!=10)
     f=f+1;
     else

    f=6;

    textcolor(14);textbackground(0);
    gotoxy(15,f);cprintf(opciones[f]);
    textcolor(14);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(15,f);cprintf(opciones[f]);
   if(f!=6)
   f=f-1;
   else

    f=10;
    textcolor(14);textbackground(3);
    gotoxy(15,f);cprintf(opciones[f]);
    textcolor(14);textbackground(3);

  }
  }
  
    
   while(tecla!=13);
 switch(f)
 {
  case 6:adicionar(); break;
  case 7:opcion_1(); break;
  case 8:opcion_2(); break;
  case 9:consultar(); break;
  case 10: default: printf("FINAL");
  

}

}
 while(f!=10);
}


/********************************************/
int pacho::val_ent() {
	char aux[20];
	gets (aux);
	return atoi(aux);
}

/****************************************************************/


void ins_izquierdo (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->elemento = n;
	nuevo->izquierdo = NULL;
	nuevo->derecho = NULL;
	p->izquierdo = nuevo;
}

/****************************************************************/

void ins_derecho (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->elemento = n;
	nuevo->izquierdo = NULL;
	nuevo->derecho = NULL;
	p->derecho = nuevo;
}
/****************************************************************/
#define MAXIMO 20

struct LIFO {
	int t;
	struct arbol *a[MAXIMO];
};



/*************************************PREORDEN***************************/

void pacho::cons_preorden (struct arbol *p)
{
int f,i,j;
float def;
struct LIFO pila;
void init_pila (struct LIFO *p);
int pila_vacia (struct LIFO *p);
void ins_pila (struct LIFO *p, struct arbol *s);
void sacar_pila (struct LIFO *p,struct arbol **s);
init_pila (&pila);
clrscr();
  textcolor(14); textbackground(15);
  marcar(2,3,80,24,1);


 f=7;

 for (i=2;i<=62;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }
 
  marco(3,10,3,14);
  marco(11,18,3,14);
  marco(19,28,3,14);
  marco(29,35,3,14);
  marco(36,41,3,14);
  marco(42,48,3,14);
  marco(49,55,3,14);
  marco(56,61,3,14);
  marco(2,80,15,18);
  delay(50);
  gotoxy(32,2);textcolor(15);cprintf(" REGISTRO PREORDEN...");
  delay(150);
  tiempo(55,16);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");
 

  gotoxy(4,5);cout<<"CODIGO  NOMBRE  APELLIDO  NOT1   NOT2   NOT3   NOT4  DEF ";

 
while (p) {
  gotoxy(4,f);cout<<p->elemento;
  gotoxy(12,f);cout<<p->nombre;
  gotoxy(20,f);cout<<p->apellido;
  gotoxy(30,f);cout<<p->n1;
  gotoxy(37,f);cout<<p->n2;
  gotoxy(43,f);cout<<p->n3;
  gotoxy(50,f);cout<<p->n4;
  def=p->n1*0.25+p->n2*0.25+p->n3*0.2+p->n4*0.3;
  gotoxy(57,f);cout<<def;
   f++;	
	ins_pila (&pila,p);
	p = p->izquierdo;
    }
	while (!pila_vacia (&pila)) {
	sacar_pila (&pila,&p);
	p = p->derecho;
	while (p) {
	gotoxy(4,f);cout<<p->elemento;
	gotoxy(12,f);cout<<p->nombre;
	gotoxy(20,f);cout<<p->apellido;
	gotoxy(30,f);cout<<p->n1;
	gotoxy(37,f);cout<<p->n2;
	gotoxy(43,f);cout<<p->n3;
	gotoxy(50,f);cout<<p->n4;
	def=p->n1*0.25+p->n2*0.25+p->n3*0.2+p->n4*0.3;
	gotoxy(57,f);cout<<def;
 
    f++;		
	ins_pila (&pila,p);
	p = p->izquierdo;
     }
   }
reloj();
}

/*****************************************************************/

void init_pila (struct LIFO *p)
{
	p->t = 0;
}
/*****************************************************************/
int pila_vacia (struct LIFO *p)
{
	return (!p->t);
}


/******************************************************************/
void ins_pila (struct LIFO *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}

/**********************************************************************/
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

/*************************************************************************/
void pacho::opcion_1()
{
}

/************************************************************************/
void pacho::adicionar()

  {
  char nombre[15];
  char apellido[15];
  float n1,n2,n3,n4;  
  char op,info[3],co[5];
  int elemento,i,j;
  int sw,st;
  char valido;
  int n;

do{
  clrscr(); 
   textcolor(14);
  textcolor(14); textbackground(15);
  marcar(2,3,80,24,1);
  marco(3,79,3,5);
  marco(2,80,1,15);
  
 for (i=3;i<=79;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(1);cprintf(" ");
   }
  }

  marco(3,13,3,14);
  marco(14,26,3,14);
  marco(27,38,3,14);
  marco(39,49,3,14);
  marco(50,60,3,14);
  marco(61,70,3,14);
  marco(71,79,3,14);
  marco(2,80,15,18);
  delay(50);
  gotoxy(32,2);textcolor(252);cprintf(" REGISTRO ADICIONAR...");
  delay(150);
  tiempo(55,16);

  textbackground(14);
  i=0;
  textcolor(19);gotoxy(4,4);cout<<"CODIGO";
  textcolor(19);gotoxy(16,4);cout<<"NOMBRE";
  textcolor(19);gotoxy(29,4);cout<<"APELLIDO";
  textcolor(19);gotoxy(40,4);cout<<"NOTA 1";
  textcolor(19);gotoxy(52,4);cout<<"NOTA 2";
  textcolor(19);gotoxy(63,4);cout<<"NOTA 3";
  textcolor(19);gotoxy(72,4);cout<<"NOTA 4";

 do
 {  
   
    
    gotoxy(7,i+6);
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
  elemento=atoi(info);
  p=nn=raiz;i=1;     
  while((elemento!=p->elemento)&&(nn!=NULL)&&(i<=6))
  {
    p=nn;
    if(elemento<p->elemento)
      nn=p->izquierdo;
    else

      nn=p->derecho;
    i++;
  }
  if(elemento==p->elemento)
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


   
 do
      {
	valido='n';
	gotoxy(16,i+5);
	cout<<"             ";
	 textcolor(1);textbackground(15);
         marco(3,13,3,14);
         marco(14,26,3,14);
         marco(27,38,3,14);
         textcolor(1);textbackground(15);
  
        gotoxy(16,i+5);gets(nombre);
        n=strlen(nombre);
        for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nombre[j])))
	    {
             
            delay(50);
	    gotoxy(15,16);textcolor(252);cprintf(" SOLO LETRAS...");
            delay(150);
	     valido='m';
	     getch();
	     gotoxy(15,16);
	     cout<<"                                 ";
	     break;
	    }
	  }
      
 }while(valido=='m');
     
  
 
 do
      {
	valido='n';
	gotoxy(29,i+5);cout<<"             ";
	 textcolor(1);textbackground(15);
         marco(3,13,3,14);
         marco(14,26,3,14);
         marco(27,38,3,14);
         textcolor(1);textbackground(15);
  
         gotoxy(29,i+5);gets(apellido);
        n=strlen(apellido);
        for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(apellido[j])))
	    {
             
             delay(50);
	    gotoxy(29,16);textcolor(252);cprintf(" SOLO LETRAS...");
            delay(150);
	 
	     valido='m';
	     getch();
	     gotoxy(29,16);
	     cout<<"                                 ";
	     break;
	    }
	  }
  
     }while(valido=='m');
     

	  


 do{
   
   gotoxy(42,i+5);cout<<"   ";
    textcolor(14);textbackground(1);
  marco(3,13,3,14);
  marco(14,26,3,14);
  marco(27,38,3,14);
  marco(39,49,3,14);
  marco(50,60,3,14);
  marco(61,70,3,14);
  marco(71,79,3,14);
  marco(2,80,15,18);
  textcolor(14);textbackground(1);
 
   n1=val_not(42,i+5);     
   gotoxy(42,i+5);
   if(n1>5.0)
   {  
    gotoxy(22,20);cout<<"LA NOTA ESTA FUERA DE RANGO\n";
    getche();
    gotoxy(22,20);cout<<"                             ";
    
   }
  }while(n1>5.0);  

  do{
   gotoxy(54,i+5);cout<<"    ";
  textcolor(14);textbackground(1);
  marco(39,49,3,14);
  textcolor(14);textbackground(1);

   n2=val_not(54,i+5);     
  
 gotoxy(54,i+5);
   if(n1>5.0)
   {  
    gotoxy(22,20);cout<<"LA NOTA ESTA FUERA DE RANGO\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    
   }
  }while(n2>5.0);  

  do{
   gotoxy(65,i+5);cout<<"   ";
  textcolor(14);textbackground(1);
   marco(50,60,3,14);
  textcolor(14);textbackground(1);
  
  
   n3=val_not(65,i+5);     
   gotoxy(65,i+5);
   if(n3>5.0)
   {  
    gotoxy(22,20);cout<<"LA NOTA ESTA FUERA DE RANGO\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    
   }
  }while(n3>5.0);  

 do{
   gotoxy(42,13);cout<<"    ";
   textcolor(14);textbackground(1);
  marco(61,70,3,14);
  marco(71,79,3,14);

   textcolor(14);textbackground(1);

  
   n4=val_not(74,i+5);     
   gotoxy(74,i+5);
   if(n4>5.0)
   {  
    gotoxy(22,20);cout<<"LA NOTA ESTA FUERA DE RANGO\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    
   }
  }while(n1>5.0);  
  

     nn=new arbol;
     nn->elemento=elemento;
     strcpy(nn->nombre,nombre);  
     strcpy(nn->apellido,apellido);       
     nn->n1=n1;
     nn->n2=n2;
     nn->n3=n3;
     nn->n4=n4;

     nn->izquierdo=NULL;
     nn->derecho=NULL;

     if(raiz==NULL)
       raiz=nn;
     else
     { 
     if(elemento<p->elemento)
	p->izquierdo=nn;
       else
	p->derecho=nn;
        }
    

          gotoxy(29,21);printf(" NODO INSERTADO..! ");

   }
       
  textcolor(15); textbackground(0);
  textcolor(15);textbackground(0);
  cuadros(2,21,78,23);
  marco(2,78,21,23);
  gotoxy(24,22);printf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');


}


/*************************************************************************/
void pacho::opcion_2()
{}


void pacho::consultar()
{

{
 int tecla,f,i;
 char opciones[25][45];
 
 
  strcpy(opciones[7]," PREORDEN ");
  strcpy(opciones[8]," INORDEN  ");
  strcpy(opciones[9]," POSTORDEN");
  strcpy(opciones[10]," REGRESAR ");
  
do
 {
 
 textcolor(14); textbackground(0);
 cuadros(62,6,73,11); 
 marco(62,73,6,11);
 gotoxy(63,5);cprintf("CONSULTAR");
                                                           
 for(f=7; f<=10;f++)
 {
  gotoxy(63,f); cprintf(opciones[f]);
  }
  f=7;
  textcolor(1); textbackground(0);
  gotoxy(63,f); cprintf(opciones[f]);
  textcolor(14); textbackground(0);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(3);
     gotoxy(63,f);cprintf(opciones[f]);
     if(f!=10)
     f=f+1;
     else

    f=7;

    textcolor(14);textbackground(0);
    gotoxy(63,f);cprintf(opciones[f]);
    textcolor(14);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(63,f);cprintf(opciones[f]);
   if(f!=7)
   f=f-1;
   else

    f=10;
    textcolor(14);textbackground(3);
    gotoxy(63,f);cprintf(opciones[f]);
    textcolor(14);textbackground(3);

  }
  }
  
    
   while(tecla!=13);
 switch(f)
 {
  case 7:cons_preorden(raiz);getche(); break;
  case 8:cons_inorden(raiz); getche();break;
  case 9:cons_postorden(raiz);getche();break;
  case 10:menu();
 

}

}
 while(f!=10);
}
}
/*****************************************/
void pacho::cons_inorden (struct arbol *p)
{
	int f,i,j;
	float def;
	struct LIFO pila;
	void init_pila (struct LIFO *p);
	int pila_vacia (struct LIFO *p);
	void ins_pila (struct LIFO *p, struct arbol *s);
	void sacar_pila (struct LIFO *p,struct arbol **s);
	init_pila (&pila);
		

 f=7;
 clrscr();
  textcolor(14); textbackground(15);
  marcar(2,3,80,24,1);


 f=7;

 for (i=2;i<=62;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(4);cprintf(" ");
   }
  }



  marco(3,10,3,14);
  marco(11,18,3,14);
  marco(19,28,3,14);
  marco(29,35,3,14);
  marco(36,41,3,14);
  marco(42,48,3,14);
  marco(49,55,3,14);
  marco(56,61,3,14);
  marco(2,80,15,18);
  delay(50);
  gotoxy(32,2);textcolor(15);cprintf(" REGISTRO INORDEN...");
  delay(150);
  tiempo(55,16);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

     gotoxy(4,5);cout<<"CODIGO  NOMBRE  APELLIDO  NOT1   NOT2   NOT3   NOT4  DEF ";

 

	init_pila (&pila);
	while (p) {
		ins_pila (&pila,p);
		p = p->izquierdo;
	}
	while (!pila_vacia (&pila)) {
		sacar_pila (&pila,&p);

       if(p->n1<3.0)
      {
  gotoxy(4,f);cout<<p->elemento;
  gotoxy(12,f);cout<<p->nombre;
  gotoxy(20,f);cout<<p->apellido;
  gotoxy(30,f);cout<<p->n1;
  gotoxy(37,f);cout<<p->n2;
  gotoxy(43,f);cout<<p->n3;
  gotoxy(50,f);cout<<p->n4;
  def=p->n1*0.25+p->n2*0.25+p->n3*0.2+p->n4*0.3;
  gotoxy(57,f);cout<<def;
		}

    f++;
		p = p->derecho;
		while (p) {
			ins_pila (&pila,p);
			p = p->izquierdo;
		}
	}
reloj();
}

//********************************POSTORDEN*****************************************
#define MAXIMO 20

struct elem {
	struct arbol *apunt;
	int senal;
};

struct LIFO1 {
	int t;
	struct elem a[MAXIMO];
};

//**************************************************************************
void pacho::cons_postorden (struct arbol *p)
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
	
 f=7;
 clrscr();
  textcolor(14); textbackground(15);
  marcar(2,3,80,24,1);


 f=7;

 for (i=2;i<=62;i++)
  {
   for (j=6;j<=14;j++)
   {
    gotoxy(i,j);textbackground(15);cprintf(" ");
   }
  }
  marco(3,10,3,14);
  marco(11,18,3,14);
  marco(19,28,3,14);
  marco(29,35,3,14);
  marco(36,41,3,14);
  marco(42,48,3,14);
  marco(49,55,3,14);
  marco(56,61,3,14);
  marco(2,80,15,18);
  delay(50);
  gotoxy(32,2);textcolor(15);cprintf(" POSTORDEN...");
  delay(150);
  tiempo(55,16);
  gotoxy(32,22);textcolor(15);cprintf(" PULSE ENTER...");

     gotoxy(4,5);cout<<"CODIGO  NOMBRE  APELLIDO  NOT1   NOT2   NOT3   NOT4  DEF ";

 
	while (p) {
		ins_pila1 (&pila,p);
		p = p->izquierdo;
	}
	while (!pila_vacia1 (&pila)) {
		
		mirar (&pila,&p,&i);
		
		if (i == 0)
			p = p->derecho;
		else p = NULL;
		if (p)
			while (p) {
				ins_pila1 (&pila,p);
				p = p->izquierdo;
			}
		else {
            
				retira_pila1 (&pila,&p);
  gotoxy(4,f);cout<<p->elemento;
  gotoxy(12,f);cout<<p->nombre;
  gotoxy(20,f);cout<<p->apellido;
  gotoxy(30,f);cout<<p->n1;
  gotoxy(37,f);cout<<p->n2;
  gotoxy(43,f);cout<<p->n3;
  gotoxy(50,f);cout<<p->n4;
  def=p->n1*0.25+p->n2*0.25+p->n3*0.2+p->n4*0.3;
  gotoxy(57,f);cout<<def;
  
    f++;
	}


  }
  reloj();
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

/*************************************************************/
void pacho::cons_arb() 
{
}
/*******************************************************************/
 main()
{
 char op;
 int cont;
 int u;
 cont=0;
 clrscr();
do
 { 
  textcolor(14); textbackground(15);
  marcar(2,3,80,24,1);
  cont++;
  textcolor(14);textbackground(1);
  cuadros(2,2,79,24);
  marco(22,55,11,13);
  gotoxy(23,12);cout<<"ENTER CURRENT  PASSWORD[       ]";
  gotoxy(47,12);
  if(lee_clave()==7)
  {
   cont=7;
  }
   
   else
  {
   clrscr();
  textcolor(14); textbackground(3);
  marcar(2,3,80,24,1);
  textcolor(14);textbackground(1);
  cuadros(2,2,80,24);
  marco(20,42,13,16);

   textcolor(1);
   gotoxy(21,14);textcolor(13);cprintf("CLAVE EQUIVOCADA   ");
   gotoxy(21,15);textcolor(13);cprintf("INTENTELO DE NUEVO ");
   delay(1500);
  }
 }while(cont<3);  




pacho objeto(NULL);
objeto.presentacion();
objeto.teoria();
objeto.menu();
getche();
}

float pacho::val_not(int z, int w )
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


int pacho::val(int x, int y)
{ char *cad;
  
  int n,sw,j;
  do
  { gotoxy(x,y);sw=0;clreol();
    scanf("\n");gets(cad);
    n=strlen(cad);
    for(j=0;j<n;j++)
     if(!isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
  return(atol(cad));
} 

//************************************************
void pacho::reloj()

{
   clock_t start, end;
   start = clock();

  delay(2000);
   end = clock();
   gotoxy(5,16);printf("EL TIEMPO ES: %f\n", (end - start) / CLK_TCK);

  
}
