#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
//  #include "malloc.h"
#include "ctype.h"
#define memoria (nodo *)malloc(sizeof(nodo))
long lista();
void capturar(char cod_para[],int t,int x,int y,int opcion);
void insertar();
void buscar(int cod);
typedef struct lista nodo;
  struct lista
   {       int cod;
	    char nom[20];
	    char ape[20];
	    int no1;
	    int no2;
	    int no3;
	    nodo *izdo, *dcho;
   };
nodo *anterior,*actual,*raiz,*nuevo;
void main()
{
clrscr();
anterior=NULL;
raiz=NULL;
actual=NULL;
insertar();
}

/*t longitud del vector
/*x coordenada en x
/*y coordenada en y
/*opcion 1:si es numero
/*opcion 2:si es letras*/
void capturar(char cod_para[],int t,int x,int y,int opcion)
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

long lista()
{
  int Ncodigo;
  char Scodigo[9], car;
  int i;

  for (i=0; i<9;)
    {
      car=getch();
      if ((i<8) && (car>='0') && (car<='9'))
	{
		printf("car");
		Scodigo[i]=car;
		i++;
	}
      if (car=='\b' && i>0)
	{
	  printf("\b \b");
	  i--;
	  Scodigo[i]='\0';
	}
      if ((i>=1) && (car=='\r'))
	{
	  Scodigo[i]='\0';
	  i=9;
	}
    }
  Ncodigo=atol(Scodigo);
  return(Ncodigo);
} 


void buscar(int cod)
{ int sw=0;
  actual=raiz;
  while(sw==0 && actual !=NULL)
  {if(actual->cod==cod)
      sw=1;
     else
     { anterior=actual;
	if(actual->cod>cod)
	 actual=actual->izdo;
	else
	 actual=actual->dcho;
     }
 }
}


void insertar()
 {  int cod;
    char res;
  do
   {
	 printf("digite codigo:   ");
	 //scanf("%d",&cod);
	 capturar(1,10,1,1);
	 buscar(cod);
	 if(actual!=NULL)
	 { printf("elemento duplicado");
		getch();}
		else
	{ nuevo=memoria;
	  nuevo->cod=cod;
	  gotoxy(8,4);printf("digite el nombre:    ");
	  scanf("%s",nuevo->nom);
	  fflush(stdin);
	  gotoxy(8,5);printf("digite el apellido:   ");
	  scanf("%s",nuevo->ape);
	  fflush(stdin);
	  gotoxy(8,6);printf("nota#1:  ");
	  scanf("%d",nuevo->no1);
	  gotoxy(8,7);printf("nota#2:  ");
	  scanf("%d",nuevo->no2);
	  gotoxy(8,8);printf("nota#3:  ");
	  scanf("%d",nuevo->no3);
	  nuevo->izdo=NULL;
	  nuevo->dcho=NULL;
	     if(anterior==NULL)
	       raiz=nuevo;
	     else
	       if(anterior->cod>cod)
		  anterior->izdo=nuevo;
		else
		  anterior->dcho=nuevo;
	  }
       printf("Desea continuar s/n");
       res=getch();
     }while (toupper(res)=='S');

 }

