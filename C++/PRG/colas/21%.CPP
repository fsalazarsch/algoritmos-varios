#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <process.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>
#include "alloc.h"


#define TRUE 1
#define FALSE 0
#define MAXIMO 20

#define memoria (struct moreno*)malloc(sizeof(struct circulares))

#define ne 10
int cola[ne];
char op;
int fre,c,a,i,num;
char nom[45],aux[45];


//*****************************listas dobles***************************/
 struct cesar{
  char cod[10];
  char nom[40];
  char apel[40];

  struct cesar *ant;
  struct cesar *sig;

 }nodo,*nn,*p,*ptr;




//*******************lista dobles circulares****************************************************/

    struct NODO {
    long codigo;
    char *nombre;
    struct NODO *Izq;
    struct NODO *Der;
    }moreno; 
      
  struct NODO  *cabeza1,*cabeza2,*p1,*q1,*nn1;

//**********************************************************************/

    struct COLAS{
    struct NODO COLA[MAXIMO];
    int frente,final;
    }cola1;
   
//*********************************************************************/
 void menu();
 void menu1();
 void menu2();
 void menu3();
 void menu4();
   int sw=0;
   //char op;
   int z,r;
  long cod;
 char nombre[50];
 void adicionar_bcolas();
 void eliminar_bcolas();
 void visualizar_bcolas();
 void captura_doblecircular();
 void eliminar_doblecircular();
 void consultardoblecircular();
 void inscola();
 void insertarcola(struct COLAS *pq,long cod,char *nombre);
 void inscola();
 int colavacia(struct COLAS *pq);
 void eliminar_colas(struct COLAS *pq);

 void visualizar_colas();
 void adicionar_listas();
 void eliminar_listas();
 void visualizar_listas();
 void adicionar_circulares();
 void eliminar_circulares();
 void visualizar_circulares();

/************************************************************/
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

void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ß");
    gotoxy(i,y2); cprintf("Ü");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("Û");
    gotoxy(x2,i); cprintf("Û");
  }

}


/*************************************************************/
void main()
{
 menu();
 }


/*****************************MENU GENERAL************************/

void menu()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"COLAS        ");
 strcpy(opciones[12],"LISTA-DOBLES ");
 strcpy(opciones[13],"CIRCU-DOBLES ");
 strcpy(opciones[14],"BICOLAS      ");
 strcpy(opciones[15],"REGRESAR     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(14,4); textcolor(15); textbackground(1);
 cprintf(" E S T R U C T U R A  D E   D A T O S ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=15;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=15)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=15;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: menu1(); break;
 case 12: menu2();break;
 case 13: menu3();break;
 case 14: menu4();break;
 case 15: default: printf("FINAL");

}
}
 while(f!=15);
}


/*//////////////////menu archivo///////////////////////**/

void Insertar()
{
}
//////////////////////////////////////menu colas/////////////////////////////////////////////////

void menu1()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR    ");
 strcpy(opciones[12],"ELIMINAR     ");
 strcpy(opciones[13],"REGRESAR     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(14,4); textcolor(15); textbackground(1);
 cprintf(" E S T R U C T U R A  D E   D A T O S ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=13;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=13)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=13;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: inscola(); break;
 case 12: eliminar_colas(&cola1);break;
 case 13: default: printf("FINAL");

}
}
 while(f!=13);
}

//*********************************BCOLAS**************************************/  

void menu4()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR    ");
 strcpy(opciones[12],"ELIMINAR     ");
 strcpy(opciones[13],"VISUALIZAR   ");
 strcpy(opciones[14],"REGRESAR     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(14,4); textcolor(15); textbackground(1);
 cprintf(" E S T R U C T U R A  D E   D A T O S ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=14;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=14)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: adicionar_bcolas(); break;
 case 12: eliminar_bcolas();break;
 case 13: visualizar_bcolas();break;
 case 14: default: printf("FINAL");

}
}
 while(f!=14);
}


/////////////////////////////////////menu listas///////////////////////////////////////////



void menu2()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR    ");
 strcpy(opciones[12],"ELIMINAR     ");
 strcpy(opciones[13],"VISUALIZAR   ");
 strcpy(opciones[14],"REGRESAR     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(14,4); textcolor(15); textbackground(1);cprintf(" M E N U   L I S  T A  S     D  O B  L  E  S ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=14;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=14)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {


 case 11: adicionar_listas(); break;
 case 12: eliminar_listas();break;
 case 13: visualizar_listas();break;
 case 14: default: printf("FINAL");

}
}
 while(f!=14);
}




////////////////////////////////menu circulares///////////////////////////////
void menu3()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR    ");
 strcpy(opciones[12],"ELIMINAR     ");
 strcpy(opciones[13],"VISUALIZAR   ");
 strcpy(opciones[14],"REGRESAR     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
  marcar(2,6,79,24,1);
  textcolor(3); textbackground(3);
   marcar(2,3,79,5,3);
  gotoxy(8,4); textcolor(15); textbackground(1);cprintf(" M E N U   L I S  T A  S    C  I  R  C   U   L   A  R  E ");

 textcolor(0);textbackground(5);
  gotoxy(20,22); textcolor(15); textbackground(1);
 cprintf(" CESAR LEONARDO MORENO RIOS  ");


 for(f=11; f<=14;f++)
 {
   gotoxy(25,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(0); textbackground(15);
  gotoxy(25,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch();  }
  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));

  if (tecla==80)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=14)
   f=f+1;
    else

    f=11;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(25,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=14;
    textcolor(0);textbackground(15);
    gotoxy(25,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {

 case 11:captura_doblecircular();break;
 case 12:eliminar_doblecircular();break;
 case 13:consultardoblecircular();break;
 case 14: default: printf("FINAL");

}
}
 while(f!=14);
}




//********************************listas**************************************/

 void adicionar_circulares()
 {}
  void eliminar_circulares()
{}
  void visualizar_circulares()

 {}
//***************************************************************************/
 void adicionar_listas()
 { char cod[10];
  char nom[40];
  char apel[40],op;
  int i,j,sw,st;
  char valido;
  int n;


do{

do 
{ clrscr();
       cuadros(2,2,80,24);
       cuadros(3,3,78,5);
       gotoxy(20,4);printf(" A  D  I  C  I  O   N  A   R     :") ;
   
	 nn=(struct cesar *)malloc(sizeof(nodo));
	 valido='n';
	 gotoxy(20,8);printf("DIGITE EL CODIGO     :") ;gets(cod);

	 //valido el codigo
	 n = strlen(cod);
	  for(j=0;j<=n-1;j++)
	{
	 if(n>8)
	  {   textcolor(4);textbackground(3);
              cuadros(19,16,40,18);
              gotoxy(20,17);
	      printf("FUERA DE RANGO");
	      valido='m';
	      getch();
	      break;
	  }

	 else
	  {
	   if((!(isdigit(cod[j]))))
	    { textcolor(8);textbackground(3);
              cuadros(14,16,50,18);
              gotoxy(15,17);
	     textcolor(1);printf("INGRESE SOLO NUMEROS  ");
	     valido='m';
	     getch();
	     break;   
            }
	   else
	    {
	     p=ptr;
			   //recorremos la lista
	     while(p!=NULL)
	     {
	      if(strcmp(p->cod,cod)==0)
	       { textcolor(5);textbackground(15);
                cuadros(19,16,40,18);
		gotoxy(20,17);
		printf(" CODIGO EXISTENTE");
		valido='m';
		getch();
		break;
	       }
	      p=p->sig;
	     }    
     	    }
	   }
	 }
    }while(valido=='m');

   strcpy(nn->cod,cod);

	       //capturo el nombre y lo valido
  do
      {
	valido='n';
	gotoxy(42,9);
	printf("             ");
	gotoxy(20,9);printf("DIGITE EL NOMBRE     :") ;
	gotoxy(42,9);gets(nom);
	n=strlen(nom);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nom[j])))
	    {textcolor(4);textbackground(3);
             gotoxy(20,17);
	     textcolor(128);printf("PULSE SOLO LETRAS");
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     printf("                                 ");
	     break;
	    }
	  }
       }while(valido=='m');

       //capturo y valido el apellido  
    do
      {
	valido='n';
	gotoxy(42,10);
	printf("             ");
	gotoxy(20,10);printf("DIGITE EL APELLIDO  :") ;
	gotoxy(42,10);gets(apel);
	n=strlen(apel);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(apel[j])))
	    {textcolor(4);textbackground(3);
	     gotoxy(20,17);
	     textcolor(128);printf("PULSE SOLO LETRAS");
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     printf("                                 ");
	     break;
	    }
	  }
       }while(valido=='m');



	 
  strcpy(nn->nom,nom);
  strcpy(nn->apel,apel);
  nn->sig=nn->ant=NULL;
 
  if(ptr==NULL)
   ptr=nn;
   else
  
  {p=ptr;
   while(p->sig!=NULL)
   p=p->sig;
   p->sig=nn;
   nn->ant=p;
  }
  gotoxy(29,20);printf(" OPERACION EXITOSA ");


  gotoxy(18,22);printf(" DESEA ADICIONAR OTRO ARTICULO [S/N]");
  op=toupper(getche());
  }while(op!='N');

}
//****************************************eliminar en lista dobles**********/

 void eliminar_listas()
{
  char cod[10];
  char nom[40];
  char apel[40];

  char op,sw1=0;

 
 clrscr();
    textcolor(4);textbackground(15);
   cuadros(2,2,80,24);

  do{
  cuadros(17,14,60,16);
  gotoxy(18,15); printf(" DESEA ELIMINAR EL PRIMER REGISTRO  [S/N]");
  op=toupper(getche());
  }while((op!='N')&&(op!='S'));
 if(op=='S')
  { sw1=1;

  if(ptr==NULL)
   {gotoxy(20,6);printf(" LISTA VACIA:") ;
    
     }
   else
     { p=ptr;
       ptr=p->sig;
       ptr->ant=p->sig=NULL;
        free(p);
      }
  
  
 }

}
//********************************visualizar listas***************************/
 void visualizar_listas()
{
int fill=6;
  
clrscr();
 
   cuadros(2,2,80,24);

 if(ptr==NULL)
	{

	gotoxy(25,8); printf("LISTA VACIA   ");
	  }
  else{
    cuadros(3,3,78,5);
    gotoxy(20,4); cprintf("V I S U A L I Z A R   L I S T A S   ");
    gotoxy(13,7);printf("CODIGO              NOMBRE       APELLIDO ");
    textcolor(4);textbackground(15);    

    p=ptr;
      while(p!=NULL)
      {
       gotoxy(13,2+fill);printf(p->cod);
       gotoxy(33,2+fill);printf(p->nom);
       gotoxy(50,2+fill);printf(p->apel);
	
	fill++;
	p=p->sig;
	
       }
     } 
gotoxy(20,22);printf("PULSE ENTER PARA REGRESAR");
getche();
 
}


//*********************************************************************/

 void adicionar_bcolas()
{
}

void eliminar_bcolas()
{}
 void visualizar_bcolas()
{}



//****************************************************/
 void consultardoblecircular(){
 if(cabeza1!=NULL){
 p1=cabeza1;
 while(p1->Der!=cabeza1){
	clrscr();
	printf("Codigo: %ld  Nombre: %s \n",p1->codigo,p1->nombre);
	getch();
	p1=p1->Der;
	}
   if(p1!=NULL){
   clrscr();
	printf("CODIGO: %ld  NOMBRE: %s \n",p1->codigo,p1->nombre);
	getch();
	}
}
	else
	{
	clrscr();
	 textcolor(1+BLINK);textbackground(15);
gotoxy(22,3);cprintf("LISTA VACIA");
	getch();
	}
   }
//*******************************************************************/
 void consultardoble(){
 p1=cabeza2;
 while(p1!=NULL){
	clrscr();
	gotoxy(15,15);printf("CODIGO : %ld  NOMBRE: %s \n",p1->codigo,p1->nombre);
	getch();
	p1=p1->Der;
	}
   if(cabeza2==NULL){
	clrscr();
	 textcolor(1+BLINK);textbackground(15);
	gotoxy(15,20);cprintf("LISTA VACIA");
	getch();
	}
   }

	int buscar_nododoblecircular(long cod){
	int sw=0;
	if(cabeza1==NULL)
	return 0;
	else{
	p1=cabeza1;
	while(p1->Der!=cabeza1 && sw==0){
	if(p1->codigo==cod)
	  sw=1;
	  else
		  p1=p1->Der;
	   }
	  if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p1->codigo==cod)
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

//*******************************************************************/
/* elimina un nodo de la lista doble circular */
void eliminar_doblecircular(){

  char a[20];

 int sw=0;
 clrscr();
  gotoxy(10,10);printf("INGRESE CODIGO A ELIMINAR: ");
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

		p1=cabeza1;
		   q1=NULL;
		   while(p1->Der!=cabeza1 && sw==0)
			  if(p1->codigo==cod)
				sw=1;
				else{
				    q1=p1;
				    p1=p1->Der;
				    }
		   if(q1==NULL){
			   if(p1->Der==cabeza1 && p1->codigo==cod && sw==0)
				    cabeza1=NULL;
			    else
				  if(p1->Der!=cabeza1 && p1->codigo==cod && sw==1){
					    q1=p1->Izq;
					    q1->Der=p1->Der;
					    q1=q1->Der;
					    q1->Izq=p1->Izq;
					    cabeza1=p1->Der;
						   free(p1);
						  }
				  }else
					if(p1->Der==cabeza1 && p1->codigo==cod && sw==0){
						 q1->Der=p1->Der;
						 q1=q1->Der;
				 q1->Izq=p1->Izq;
						  free(p1);
						 }
						 else{
						 if(sw==1){
						 q1->Der=p1->Der;
						 q1=q1->Der;
						 q1->Izq=p1->Izq;
						 free(p1);
						 }
						 }

   do{
   sw=0;
   gotoxy(10,15);
   printf(" PARA CONTINUAR S/N ");
   op=toupper(getch());
   if(op=='S'||op =='N')
	 sw=1;
  }while(sw!=1);
  if(op=='S')
	eliminar_doblecircular();
		   }

//*****************************************/

/* captura la informacion para crear en la lista doble */
void captura_doblecircular(){
    int sw=0;
    clrscr();
	 nn1=(struct NODO *)malloc(sizeof(moreno));


    do{
    gotoxy(10,10);
    printf("CODIGO: ");
	if(sw==1){
	gotoxy(10,10);
	printf("El CODIGO YA EXISTE");
	getch();
	clreol();
	}
    validar_datos(23,10,2,nn1);
   }while((sw=buscar_nododoblecircular(nn1->codigo))==1);
    gotoxy(10,12);
    printf("NOMBRE: ");
    validar_datos(23,12,1,nn1);

   nn1->Izq=nn1->Der=NULL;
	  if(cabeza1==NULL)
	   {
		cabeza1=nn1;
		nn1->Izq=cabeza1;
		nn1->Der=cabeza1;
	   }
		else{
			p1=cabeza1;
			while(p1->Der!=cabeza1){
			    p1=p1->Der;
						  }
			p1->Der=nn1;
			nn1->Der=cabeza1;
			nn1->Izq=p1;
	    }

   do{
  sw=0;
   gotoxy(10,15);
   printf(" PARA CONTINUAR S/N ");
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
	  p1=cabeza2;
	  while(p1->Der!=NULL && sw==0){
		if(p1->codigo==cod)
		  sw=1;
		  else
		  p1=p1->Der;
	   }

 if(sw==1)
	  return 1; //existe
		if(sw==0)
		   if(p1->codigo==cod)
			return 1; // existe
			    }
	   return 0; //no existe
	}


//*******************************************************************/
 void inscola()
{

 int sw2=0;
  char a[20];
  clrscr();
   gotoxy(15,5);
   printf("INGRESE EL CODIGO: ");
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
 gotoxy(15,6);printf("INGRESE EL NOMBRE: ");
 scanf("\n");
 gets(nombre);
 insertarcola(&cola1,cod,nombre);

   do{
   sw2=0;
   gotoxy(10,15);
   printf(" PARA SEGUIR S/N ");
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

 void eliminar_colas(struct COLAS *pq)

{
    clrscr();

    if(colavacia(pq)){
 textcolor(1+BLINK);textbackground(15);
gotoxy(10,7);cprintf("NO HAY ELEMENTOS A ATENDER ");
    getch();
    return;
    }
    if( pq->frente==MAXIMO-1){
	pq->frente=0;
	printf("CODIGO:%ld",pq->COLA[pq->frente].codigo);
	printf("\tNOMBRE: %s\n",pq->COLA[pq->frente].nombre);
	getch();

	  }
   else {
	    gotoxy(22,3);printf("F U N C I O N   A T E N D E R");
gotoxy(10,7);printf("\tCODIGO: %ld\n",pq->COLA[pq->frente].codigo);
 gotoxy(10,8);printf("\tNOMBRE: %s\n",pq->COLA[pq->frente].nombre);
 gotoxy(22,14);printf("PULSE ENTER PARA CULMINAR");

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













