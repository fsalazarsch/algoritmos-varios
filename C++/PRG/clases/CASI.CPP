#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#include <string.h>
#include <iomanip.h>
/*********************DEFINICION DE LA CLASE*********************/
class lista
{
    struct nodoc{
	    

	   int cedula[8];
	   char nombre[45];
	   char apellido[45];
	   char sexo[1];
	   struct nodou *ant_usuario; 
	   struct nodoc *sig_caj;
	   }nodo_caj;
	   struct nodoc *ptr,*p,*nn,*q;
	   
     struct nodou{
	   int cedula[8];
	   char nombre[40];
	   char apellido[30];
	   float op;
	   float valor;
	   struct nodou *sig;
	   struct nodou *ant;
	   }nodo_usuario;
	   struct nodou *nn1;


     public:
	    void inicializar();
	    void adicionar_caj();
	    void adicionar_usuario();
	    void operacion();
	    void consultas();
	    void captura(char ced_para[],int t,int x,int y);
	    void captura1(char ced_para[],int t,int x,int y);
	    void marco(int x1,int y1,int x2,int y2);
	    void cuadro(int a,int b,int c,int d);
	    void pintura();
	    //void presentacion();
            
};


void lista::inicializar()
{
  ptr=NULL;
}

void lista::operacion()
{
}
void lista::consultas()
{
}
void lista::adicionar_caj()
{
}
void lista::adicionar_usuario()

{
}
 

void lista::captura(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);
	   while(c!='\r' && n_caracteres<t)
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
	      cod_para[n_caracteres]=c;
	      n_caracteres++;
	      }
	    }
	    cod_para[n_caracteres]='\0';
	    
}

void lista::captura1(char cod_para[],int t,int x,int y)
{
char c=' ';
int n_caracteres=0,a=x-1;
gotoxy(x,y);
	   while(c!='\r' && n_caracteres<t)
	   {
	     c=getche();
	     a++;
	     if(!isalpha(c) && c!='\r')
	     {
	     gotoxy(a,y);
	     clreol();
	     a--;
	     }
	      else
	      {
	      cod_para[n_caracteres]=c;
	      n_caracteres++;
	      }
	    }
	    cod_para[n_caracteres]='\0';
	    
}


void lista::marco(int x1,int y1,int x2,int y2)
{
  int i;
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


void lista::cuadro(int a,int b,int c,int d)
{
	      int f;
	     //textcolor(10);
	    // window(1,1,80,25);
	     gotoxy(a-1,b-1);
	    cprintf("É");
	    for(f=a;f<=c;f++)
	      cprintf("Í");
	       cprintf("»");
	       for(f=b;f<=d;f++){
	       gotoxy(c+1,f);
	       cprintf("º");}
	       gotoxy(a-1,d+1);
	       cprintf("È");
	     for(f=a;f<=c;f++)
	       cprintf("Í");
	       cprintf("¼");
	      for(f=b;f<=d;f++){
	      gotoxy(a-1,f);
	      cprintf("º");}
}


void lista::pintura()
{
  int u;
  //textcolor(1);
  for (u=2;u<26;u++)
  {
  /* delay (2000);*/
  gotoxy(2,u);
  cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");

  }
}


void main()
{
lista obj;
obj.inicializar();
char op;
do
{
textbackground (16);
clrscr();
 do
 {
    textbackground (3);
    clrscr();
    obj.pintura();
    obj.marco(1,6,80,24);
   /* obj.marco(3,7,78,23);*/
   /* obj.marco(28,11,57,19);*/
   /* obj.cuadro(2,2,79,4);*/
    textcolor (15);
    gotoxy(23,5);
    textcolor (203);
    cprintf("COPORACION  UNIVERSITARIA  DE  SANTANDER           ");
   /* gotoxy(16,6);*/
  /*  cprintf("PROF: ALFONSO QUINTERO          ");*/
   /* gotoxy(16,7);*/
/*    cprintf("ALUN: ADRIANA SARMIENTO GAMEZ  ");*/
/*    gotoxy(2,3);*/
/*    cprintf("PROGRAMA CON LISTAS  DOBLEMENTE ENLAZADAS     ");*/
/*    gotoxy(2,4);*/
/*    cprintf("           VALLEDUPAR 1998                   ");*/
/*    gotoxy(13,5);*/
/*    gotoxy(47,4);*/
/*    cprintf(" COD : 96132521                  ");*/
    gotoxy(28,10);
    textcolor (15);
    cprintf("       õõ====MENU====õõ       ");
    gotoxy (29,12);
    cprintf(" 1.ADICION DE CAJAS      \n");
    gotoxy (29,13);
    cprintf(" 2.ADICION DE USUARIO    \n");
    gotoxy (29,14);
    cprintf(" 3.OPERACION DE CAJA     \n");
    gotoxy (29,15);
    cprintf(" 4.CONSULTAS             \n");
    gotoxy (29,16);
    cprintf(" 5.SALIR                 \n");
    gotoxy (28,20);
    cprintf(" SELECCIONE OPCION====>  \n");
    textcolor (1);
    obj.cuadro(28,10,57,20);
    gotoxy (51,20);
    printf ("[");
    gotoxy (53,20);
    printf ("]");
    gotoxy (52,20);
    op=getch();sound(300);delay(100);nosound();
 }while ((op>'7')||(op<'1'));
 switch (op)
 {
 case'1':
	 obj.adicionar_caj();
	 break;
     
 case'2':
	 obj.adicionar_usuario();
	 break;
 case'3':
	 obj.operacion();
	 break;
 case'4':
	 obj.consultas();
	 break;
 case '5':
	 
	 break;

 }
}while (op!='5');
clrscr();
}


/*void lista::adicionar_caj()
{   char op;
    clrscr();
  
     do{
	clrscr();
	pintura();
	cuadro(2,2,79,23);
	cuadro(20,6,62,18);
	marco(4,3,77,22);
	marco(3,2,78,23);
	marco(20,15,62,18);
	marco(20,6,62,14);
	textcolor(15);
	gotoxy(21,7);cprintf("           õõ====MENU====õõ              ");
	gotoxy(21,8);cprintf("                                         ");
	gotoxy(21,9);cprintf("  1. ADICIONAR CAJA   ");
	gotoxy(21,10);cprintf(" 2. MODIFICAR        ");
	gotoxy(21,11);cprintf(" 3. ELIMINAR         "); 
	gotoxy(21,12);cprintf(" 4. SALIR                               ");
	gotoxy(21,17);cprintf("                                         ");
	gotoxy(21,14);cprintf("          ELIJA UNA OPCION               ");
	textcolor (1);
	gotoxy (48,16);
	printf ("[");
	gotoxy (50,16);
	printf ("]");
	gotoxy (49,16);
	op=getch();sound(300);delay(100);nosound();
	switch(op){
	  case '1':
		 agregar();
		   break; 
		  
	  case '2':
		modificar();
		  break;
		   
	  case '3':
		 eliminar();
		   break; 
		    
	  case '4':break;
	    }
  }while(op!='4');
 }*/

void modificar()
{
}
void eliminar()
{
}


    /*  void agregar()
       {
		     char op;

		    int ced[10],edad[],sex,ncaj;
		    char nom[45],ape[45];
		    int sw;
		    clrscr();
		    do
		    {
		    do
		      {
		       clrscr();
		       sw=0;
			gotoxy(25,9);cout<<"CEDULA......: ";captura(cod_para,8,39,9);    //cin>>ced;
			q=ptr;                      
			while(q!=NULL)
			{
			 if(strcmp(q->cedula,ced)==0){
			  marco(24,12,60,16);
			  marco(25,13,59,15);
			  gotoxy(31,14);
			  printf("EL ELEMENTO YA EXISTE");delay(1500);
			  sw=1;
			   }
			  q=q->sig;
			  }
    
		       }while(sw==1);
		       gotoxy(25,10);cout<<"NOMBRE......: ";captura1(nom,45,39,10);
		       gotoxy(25,11);cout<<"APELLIDO....: ";captura1(ape,45,39,11);
		       gotoxy(25,12);cout<<"SEXO........: ";captura1(sex,1,39,12)

		       gotoxy(25,13);cout<<"EDAD......: ";captura(edad,1,3,39,12);
		       edad=atof(edad);
		       nn=new nodo;       

		       strcpy(nn->cedula,ced);   
		       strcpy(nn->nombre,nom);
		       strcpy(nn->apellido,ape);
		       strcpy(nn->sexo,sex)
		       nn->edad=edad;
		       nn->ant=NULL;
		       nn->sig=NULL;
		      if (ptr==NULL){
		       ptr=nn;
		       }
		     else{
			  p=ptr;
			  ptr=nn;
			  ptr->sig=p;
			}
			gotoxy(30,17);cout<<"DESEA INGRESAR OTRO NODO S/N ";
		     do{
		      op=toupper(getche());sound(300);delay(100);nosound();
		      if((op != 'S') && (op != 'N')){
			  gotoxy(59,16);
			  clreol();
			}
		      }while ((op != 'S') && (op != 'N'));
	      }while (op!='N');
	   }*/

