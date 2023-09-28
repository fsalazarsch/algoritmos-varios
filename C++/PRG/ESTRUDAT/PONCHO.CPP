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
#define color(x,y)textcolor(x);textbackground(y)



class arboles
{

  struct arbol
  {
    char nombre[15];
    char apellido[15];
    char codigo[10];
    int dato;
    float prom,nota1,nota2,nota3,nota4;
    struct arbol *izq;
    struct arbol *der;
  };struct arbol *ptr,*nn,*p;

  public:
	arboles(struct arbol *a){ptr=a;}
	void introducir();
	void opcion1(); 
	void opcion2();
	void opcion3();
	void opcion4();
	void sacar_pila ();
	void insertar_pila ();
	void iniciar_pila ();
	void preorden (struct arbol *p);
	void inorden (struct arbol *p);
	void postorden (struct arbol *p);
	int pila_vacia ();
	void presentacion();
	void cuadro();
	void menu();
	void menu1();
	void marco(int x1,int y1,int x2,int y2);
	int val(int x, int y);
	float val_not(int z, int w );
	};



/*****************************************************/
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



/*****************************************************/
void arboles::introducir()
  {
  char nombre[40],apellido[40];
  float nota1,not,nota2,nota3,nota4;  
  char op,info[3];
  int dato,i;
  i=0;
  char codigo[10];
  char nom[40];
  int j,sw,st;
  char valido;
  int n;
clrscr();
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);
  window(1,1,80,35);
 textcolor(1);

  do
     {
	gotoxy(30,5);printf("ADICIONAR NODO");
	textcolor(4);
	textbackground(15);

  textbackground(1);textcolor(15);  
  
  gotoxy(20,7);cout<<"DIGITE EL CODIGO :"; 
    
    gotoxy(i+38,7);
    clreol();
    info[i]=getche();
    
      gotoxy(80,7);cout<<"³";
   gotoxy(78,7);cout<<"³";
   gotoxy(76,7);cout<<"³";

    if(info[i]=='\b'&&i>0) i-=2;
    else
     {
     if(info[i]=='\r'&&i>0) break;
     if(!isdigit(info[i])) i--;
     }
    i++;
  }while(i<5);
  
  info[i]='\0';
  dato=atoi(info);
  p=nn=ptr;i=1;     
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
    {
	 gotoxy(25,12);cout<<"...YA EXISTE ESTE CODIGO...";
	 }
  else
   if(i==6)
     {
	  gotoxy(14,12);cout<<"...EL NUMERO  NO SE PUEDE INTRODUCIR...";
	  }
	
	else
	{  

    do
      {
	valido='n';
	gotoxy(38,8);
	cout<<"             ";
	gotoxy(20,8);cout<<"DIGITE EL NOMBRE :" ;
	gotoxy(38,8);gets(nombre);
	n=strlen(nombre);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nombre[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);cout<<"...PULSE SOLO LETRAS...";
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
	
       }while(valido=='m');
  
  do
      {
	valido='n';
	gotoxy(38,9);
	cout<<"             ";
	gotoxy(20,9);cout<<"DIGITE EL APELLIDO :" ;
	gotoxy(40,9);gets(apellido);
	n=strlen(apellido);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(apellido[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);cout<<"...PULSE SOLO LETRAS...";
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
       }while(valido=='m');

   do{valido='n'; 
	
   gotoxy(30,10);cout<<"             ";
   gotoxy(37,10);textbackground(1);textcolor(15);  
   gotoxy(20,10);cout<<"DIGITE LA NOTA1:\n";    
   gotoxy(37,10);
   gotoxy(37,10);cout<<"                   ";
   nota1=val_not(37,10);     
   gotoxy(37,10);
   gotoxy(80,10);cout<<"³";
   gotoxy(78,10);cout<<"³";
   gotoxy(76,10);cout<<"³";
   if(nota1>5.0)
   {  
    gotoxy(22,20);cout<<"...LA NOTA ESTA FUERA DE RANGO...\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
   
  }while(nota1>5.0);  

  do{
   gotoxy(42,10);cout<<"             ";
  
   gotoxy(20,11);cout<<"DIGITE LA NOTA2:";//nota1=val(17,4);     
   gotoxy(37,11);
   nota2=val_not(37,11);     
   gotoxy(32,11);
   gotoxy(80,11);cout<<"³";
   gotoxy(78,11);cout<<"³";
   gotoxy(76,11);cout<<"³";

   if(nota1>5.0)
   {  
    gotoxy(22,20);cout<<"...LA NOTA ESTA FUERA DE RANGO...\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota2>5.0);  

  do{
   gotoxy(42,12);cout<<"             ";
  
   gotoxy(20,12);cout<<"DIGITE LA NOTA3:";//nota1=val(17,4);     
   gotoxy(37,12);
   nota3=val_not(37,12);     
   gotoxy(32,12);
   gotoxy(80,12);cout<<"³";
   gotoxy(78,12);cout<<"³";
   gotoxy(76,12);cout<<"³";

   if(nota3>5.0)
   {  
    gotoxy(22,20);cout<<"...LA NOTA ESTA FUERA DE RANGO...\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota3>5.0);  

 do{
   gotoxy(42,13);cout<<"             ";
  
   gotoxy(20,13);cout<<"DIGITE LA NOTA4:";//nota1=val(17,4);     
   gotoxy(37,13);
   nota4=val_not(37,13);     
   gotoxy(32,13);
   gotoxy(80,13);cout<<"³";
   gotoxy(78,13);cout<<"³";
   gotoxy(76,13);cout<<"³";

   if(nota4>5.0)
   {  
    gotoxy(22,20);cout<<"...LA NOTA ESTA FUERA DE RANGO...\n";
    getche();
    gotoxy(22,20);cout<<"                            ";
    break;
   }
  }while(nota4>5.0);  
  

     nn=new arbol;
     nn->dato=dato;
     strcpy(nn->nombre,nombre);  
     strcpy(nn->apellido,apellido);  
     nn->nota1=nota1;
     nn->nota2=nota2;
     nn->nota3=nota3;
     nn->nota4=nota4;

     nn->izq=NULL;
     nn->der=NULL;

     if(ptr==NULL)
       ptr=nn;
     else
     { 
     if(dato<p->dato)
	p->izq=nn;
       else
	p->der=nn;
     }
	  gotoxy(25,17);cout<<"NODO INSERTADO";
      }
    
 gotoxy(21,20);cout<<"DESEA INSERTAR OTRO NODO  [S/N]: ";
 do
 {
     gotoxy(54,20);op=toupper(getche());
 }while(op!='S'&&op!='N');

 if(op=='S')
 introducir();


}
/*****************************************************/
void arboles::opcion1(){}

void arboles::opcion2(){}

void arboles::opcion3(){}

void arboles::opcion4()
{}
/*****************************************************/

#define MAXIMO 100

struct PILA {
   int t;
   struct arbol *a[MAXIMO];
};


/****************************************************/
void arboles::preorden (struct arbol *p)
{
  int x,u;
  float prom;
  struct PILA pila;
  void iniciar_pila (struct PILA *p);
  int pila_vacia (struct PILA *p);
  void insertar_pila (struct PILA *p, struct arbol *s);
  void sacar_pila (struct PILA *p,struct arbol **s);
  iniciar_pila (&pila);
  clrscr();
   x=7;
marco(8,3,76,24);
cuadro();

 gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(36,4);cprintf("APELLIDO");
 gotoxy(48,4);cprintf("NOT1");
 gotoxy(54,4);cprintf("NOT2");
 gotoxy(60,4);cprintf("NOT3");
 gotoxy(66,4);cprintf("NOT4");
 gotoxy(72,4);cprintf("DEF.");

	while (p) {
 textbackground(15);
 gotoxy(10,x);cout<<p->dato;
  gotoxy(22,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(47,x);cout<<p->nota1;
  gotoxy(53,x);cout<<p->nota2;
  gotoxy(59,x);cout<<p->nota3;
  gotoxy(65,x);cout<<p->nota4;
  prom=p->nota1*0.25+p->nota2*0.25+p->nota3*0.20+p->nota4*0.30;
  gotoxy(71,x);cout<<prom;
    x++;		insertar_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		sacar_pila (&pila,&p);
		p = p->der;
		while (p) {
 gotoxy(10,x);cout<<p->dato;
  gotoxy(22,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(47,x);cout<<p->nota1;
  gotoxy(53,x);cout<<p->nota2;
  gotoxy(59,x);cout<<p->nota3;
  gotoxy(65,x);cout<<p->nota4;
  prom=p->nota1*0.25+p->nota2*0.25+p->nota3*0.20+p->nota4*0.30;
  gotoxy(71,x);cout<<prom;   
    x++;			insertar_pila (&pila,p);
			p = p->izq;
		}
	}
}


/********************************************************/
void iniciar_pila (struct PILA *p)
{
	p->t = 0;
}


/********************************************************/
int pila_vacia (struct PILA *p)
{
	return (!p->t);
}


/********************************************************/
void insertar_pila (struct PILA *p, struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("...LA PILA NO SOPORTA MAS ELEMENTOS...\n");
	else  {
			p->t++;
			p->a [p->t -1] = s;
	}
}


/********************************************************/
void sacar_pila (struct PILA *p,struct arbol **s)
{
	if (pila_vacia (p) )  {
		printf ("...LA PILA ESTA VACIA...\n");
		*s = NULL;
	  }
	else  {
			*s = p->a [p->t -1];
			p->t--;


	}
}



/*******************************************/
void arboles::inorden (struct arbol *p)
{
	int x,u;
	float prom;
	struct PILA pila;
  void iniciar_pila (struct PILA *p);
  int pila_vacia (struct PILA *p);
  void insertar_pila (struct PILA *p, struct arbol *s);
  void sacar_pila (struct PILA *p,struct arbol **s);
  iniciar_pila (&pila);
  clrscr();
   x=7;
marco(8,3,76,24);
cuadro();

  gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(36,4);cprintf("APELLIDO");
 gotoxy(48,4);cprintf("NOT1");
 gotoxy(54,4);cprintf("NOT2");
 gotoxy(60,4);cprintf("NOT3");
 gotoxy(66,4);cprintf("NOT4");
 gotoxy(72,4);cprintf("DEF.");
		
	iniciar_pila (&pila);
	while (p) {
	       insertar_pila (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia (&pila)) {
		sacar_pila (&pila,&p);
  textbackground(15);
 gotoxy(10,x);cout<<p->dato;
  gotoxy(22,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(47,x);cout<<p->nota1;
  gotoxy(53,x);cout<<p->nota2;
  gotoxy(59,x);cout<<p->nota3;
  gotoxy(65,x);cout<<p->nota4;
  prom=p->nota1*0.25+p->nota2*0.25+p->nota3*0.20+p->nota4*0.30;
  gotoxy(71,x);cout<<prom;
    x++;

		p = p->der;
		while (p) {
			insertar_pila (&pila,p);
			p = p->izq;
		}
	}
}


/*************************************************/
#define MAXIMO 20

struct elemento {
	struct arbol *apunt;
	int senal;
};

struct PILA1 {
	int t;
	struct elemento a[MAXIMO];
};


/*************************************************/
void arboles::postorden (struct arbol *p)
{
	int i,x,u;
	float prom;
	void mirar (struct PILA1 *p,struct arbol **s,int *i);
	void init_pila1 (struct PILA1 *p);
	int pila_vacia1 (struct PILA1 *p);
	void ins_pila1 (struct PILA1 *p,struct arbol *s);
	void retira_pila1 (struct PILA1 *p,struct arbol **s);

	struct  PILA1 pila;
	init_pila1 (&pila);

   x=7;
marco(8,3,76,24);
cuadro();

  gotoxy(10,4);cprintf("CODIGO");
 gotoxy(24,4);cprintf("NOMBRE");
 gotoxy(36,4);cprintf("APELLIDO");
 gotoxy(48,4);cprintf("NOT1");
 gotoxy(54,4);cprintf("NOT2");
 gotoxy(60,4);cprintf("NOT3");
 gotoxy(66,4);cprintf("NOT4");
 gotoxy(72,4);cprintf("DEF.");

	while (p) {
		ins_pila1 (&pila,p);
		p = p->izq;
	}
	while (!pila_vacia1 (&pila)) {
		mirar (&pila,&p,&i);
  textbackground(15);
  gotoxy(10,x);cout<<p->dato;
  gotoxy(22,x);cout<<p->nombre;
  gotoxy(35,x);cout<<p->apellido;
  gotoxy(47,x);cout<<p->nota1;
  gotoxy(53,x);cout<<p->nota2;
  gotoxy(59,x);cout<<p->nota3;
  gotoxy(65,x);cout<<p->nota4;
  prom=p->nota1*0.25+p->nota2*0.25+p->nota3*0.20+p->nota4*0.30;
  gotoxy(71,x);cout<<prom;
    x++;

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
			      //printf ("%d  ",p->dato);
			}
	}
}


/*************************************************/
void init_pila1 (struct PILA1 *p)
{
	p->t = 0;
}


/*************************************************/
int pila_vacia1 (struct PILA1 *p)
{
	return (!p->t);
}


/*************************************************/
void ins_pila1 (struct PILA1 *p,struct arbol *s)
{
	if (p->t == MAXIMO)
		printf ("la pila no soporta mas elementos\n");
	else  {
			p->t++;
			p->a[p->t - 1].apunt = s;
			p->a[p->t - 1].senal = 0;
	}
}


/*************************************************/
void retira_pila1 (struct PILA1 *p,struct arbol **s)
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

/*************************************************/
void mirar (struct PILA1 *p,struct arbol **s,int *i)
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


/*****************************************************************/
void arboles::marco(int x1,int y1,int x2,int y2)
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

/*****************************************************/
void arboles::menu()
{char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);
   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(0);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(1);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("MENU PRINCIPAL");

  textbackground(0);
  window(27,12,59,19);clrscr();
  
  textbackground(1);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(6,2);
  cprintf("1.ADICIONAR NODOS");
  gotoxy(6,3);
  cprintf("2.RECORRIDOS");
  gotoxy(6,4);
  cprintf("3.TIEMPO DE EJECUCION");
  gotoxy(6,5);
  cprintf("4.ARBOLES COMPLETOS");
  gotoxy(6,6);
  cprintf("5.PROCEDIMIENTO");
  gotoxy(6,7);
  cprintf("6. SALIR");


 textcolor(15);
 gotoxy(5,2);cprintf("");gotoxy(5,2);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(5,wherey()+5);
	     cprintf("");
	     gotoxy(5,wherey());
	   }
	    else
	    {

	      gotoxy(5,wherey()-1);
	      cprintf("");
	      gotoxy(5,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==7)
	  {
	     gotoxy(5,wherey()-5);
	     cprintf("");
	     gotoxy(5,wherey());
	  }
	 else
	 {
	     gotoxy(5,wherey()+1);
	     cprintf("");
	     gotoxy(5,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==7)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
	   { case 2:window(1,1,80,25);clrscr();introducir();break;
	     case 3:menu1();break;
	     case 4:opcion2();break; //tiempo de ejecucion
	     case 5:opcion3();break; //arboles completos
	     case 6:opcion4();break; //procedimiento
	     case 7:break;
     }

  }
    } while(SALIR!='S');
}



/*****************************************************/
void arboles::menu1()
{char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);
   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(0);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(1);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("RECORRIDOS");

  textbackground(0);
  window(27,12,59,19);clrscr();
  
  textbackground(1);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(6,2);
  cprintf("1.RECORRIDO PRE-ORDEN");
  gotoxy(6,3);
  cprintf("2.RECORRIDO IN-ORDEN");
  gotoxy(6,4);
  cprintf("3.RECORRIDO POST-ORDEN");
  gotoxy(6,5);
  cprintf("4.SALIR");
  gotoxy(6,6);

 textcolor(15);
 gotoxy(5,2);cprintf("");gotoxy(5,2);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(5,wherey()+3);
	     cprintf("");
	     gotoxy(5,wherey());
	   }
	    else
	    {

	      gotoxy(5,wherey()-1);
	      cprintf("");
	      gotoxy(5,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==7)
	  {
	     gotoxy(5,wherey()-3);
	     cprintf("");
	     gotoxy(5,wherey());
	  }
	 else
	 {
	     gotoxy(5,wherey()+1);
	     cprintf("");
	     gotoxy(5,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
	   { 
	     case 2:

	     {if(ptr==NULL){
	     window(1,1,80,25);clrscr();
	     marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);
	     gotoxy(20,10);cout<<"... NO EXISTEN NODOS EN LA LISTA ...";
	     getche();break;}
	     else{
	     window(1,1,80,25);clrscr();preorden(ptr);getche();break;}}

	     case 3:

	     {if(ptr==NULL){
	     window(1,1,80,25);clrscr();
	     marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);
	     gotoxy(20,10);cout<<"... NO EXISTEN NODOS EN LA LISTA ...";
	     getche();break;}
	     else{
	     window(1,1,80,25);clrscr();inorden(ptr);getche();break;}}

	     case 4:

             {if(ptr==NULL){
	     window(1,1,80,25);clrscr();
	     marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);
	     gotoxy(20,10);cout<<"... NO EXISTEN NODOS EN LA LISTA ...";
	     getche();break;}
	     else{
	     window(1,1,80,25);clrscr();postorden(ptr);getche();break;}}

	     case 5:break;menu();
     }

  }
    } while(SALIR!='S');
}




/*************************************************/
void arboles::presentacion()
{
  int u;

  for (u=1;u<26;u++)
 {
 delay(50);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
  
 window(1,1,80,25);
  
 }

textcolor(4); textbackground(15);
			 //177
gotoxy(17,6); printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»");
gotoxy(17,7); printf("º                                              º");
gotoxy(17,8); printf("º  ±±±±±± ±±±±   ±±±±±  ±±±±± ±	 ±±±± ±±±±   º");
gotoxy(17,9); printf("º  ±    ± ±   ±  ±    ± ±	  ± ±	 ±    ±	     º");
gotoxy(17,10);printf("º  ±±±±±± ±±±±   ±±±±±  ±   ± ±  	 ±±±  ±±±±   º");
gotoxy(17,11);printf("º  ±    ± ±   ±  ±    ± ±	  ± ±	 ±       ±   º");
gotoxy(17,12);printf("º  ±    ± ±   ±  ±±±±±  ±±±±± ±±±± ±±±± ±±±±   º");
gotoxy(17,13);printf("º                                              º");
gotoxy(17,14);printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
textcolor(0);
marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);
gotoxy(18,18);cout<<"DANGELA MAESTRE O¥ATE ,INGENIERA DE SISTEMAS ";
gotoxy(17,20);cout<<"...PRESIONE ENTER PARA VER EL MENU PRINCIPAL...";
}


/*******************************************************/
void arboles::cuadro()
{
int u;
  for (u=4;u<24;u++)
 {
 delay(15);
 gotoxy(20,u);cprintf("³"); gotoxy(33,u);cprintf("³");
 gotoxy(46,u);cprintf("³"); gotoxy(52,u);cprintf("³");
 gotoxy(58,u);cprintf("³"); gotoxy(64,u);cprintf("³");
 gotoxy(70,u);cprintf("³");
 }
   for (u=9;u<76;u++)
 {
   gotoxy(u,5);
   printf("%c",196);
 }
gotoxy(8,5);cprintf("Ã");gotoxy(20,5);cprintf("Å");
gotoxy(33,5);cprintf("Å");gotoxy(46,5);cprintf("Å");
gotoxy(52,5);cprintf("Å");gotoxy(58,5);cprintf("Å");
gotoxy(64,5);cprintf("Å");gotoxy(70,5);cprintf("Å");
gotoxy(20,3);cprintf("Â");gotoxy(33,3);cprintf("Â");
gotoxy(46,3);cprintf("Â");gotoxy(52,3);cprintf("Â");
gotoxy(58,3);cprintf("Â");gotoxy(64,3);cprintf("Â");
gotoxy(70,3);cprintf("Â");gotoxy(76,5);cprintf("´");
gotoxy(20,24);cprintf("Á");gotoxy(33,24);cprintf("Á");
gotoxy(46,24);cprintf("Á");gotoxy(52,24);cprintf("Á");
gotoxy(58,24);cprintf("Á");gotoxy(64,24);cprintf("Á");
gotoxy(70,24);cprintf("Á");

}

/*****************************************************/
main(){
clrscr();
arboles obj(NULL);
obj.presentacion();
getche();
obj.menu();
}













/******************************************
int arboles::lea_entero() {
	char aux[20];
	gets (aux);
	return atoi(aux);
}

void ins_izq (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->izq = nuevo;
}

void ins_der (struct arbol *p,int n)
{
	struct arbol *nuevo;
	struct arbol *arbol_arbol;
	nuevo = arbol_arbol;
	nuevo->dato = n;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	p->der = nuevo;
}

************/





