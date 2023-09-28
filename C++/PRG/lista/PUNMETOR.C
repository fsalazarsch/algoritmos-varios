#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include<string.h>
#include<process.h>
#include<io.h>
#include<alloc.h>
#include<ctype.h>

int her[20];
void menu();
int val_num(int cont);

void burbuja();
void insercion();
void quicksort();
void seleccion();
void shell();
int vec[100];

void pintar();
void rallado();


/*-------------------------- MENU GENERAL -----------------------------*/
void rallado(ci,cf,fi,ff)
{
 int i;
 textcolor(2);textbackground(5);
 for(i=ci;i<=cf;i++)
 {
  delay(5); gotoxy(i,fi); printf("Í");
  delay(5); gotoxy(i,ff); printf("Í");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(10); gotoxy(ci,i); printf("º");
  delay(10); gotoxy(cf,i); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff);
 printf("¼");
 textcolor(14); textbackground(1);
 }
void pintar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {

   case 1: fondo= 176;break;
   case 2: fondo=177 ;break;
   case 3: fondo= 178;break;
   case 4: fondo= 32;break;
   default  :fondo= 176;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }
/*------------------------------------------------------------------------*/
void menu()

   { int op;
   do{
    clrscr();

     textbackground(1);
	textcolor(14); textbackground(1);
	pintar(2,1,78,25,2);
	rallado(2,78,22,25);
	textcolor(0); textbackground(15);
	pintar(13,6,66,20,0);
	gotoxy(20,7);printf(" M  E  N  U   -   P  R  I  N  C  I  P  A  L");
	gotoxy(25,9);printf("[1] METODO DE BURBUJA         ");
	gotoxy(25,10);printf("[2] METODO DE SELECCION       ");
	gotoxy(25,11);printf("[3] METODO DE QUICKSORT       ");
	gotoxy(25,12);printf("[4] METODO DE INSERCION       ");
	gotoxy(25,13);printf("[5] METODO DE SHELL           ");
	gotoxy(25,14);printf("[0] SALIR                     ");
	gotoxy(23,24);printf(" DIGITE LA OPCION Y PULCE ENTER ");
	gotoxy(25,16);printf("SU OPCION ES=> [ ]");
	gotoxy(41,16);printf("");
	scanf("%d",&op);

	switch(op)


  {

  case 1:burbuja();break;
  case 2:seleccion(); break;
  case 3:quicksort(); break;
  case 4:insercion();break;
  case 5:shell();break;
  case 0 :exit(0);

   }
       }while(op!=0);
   }





/*----------------------------------------------------------------------*/
void burbuja()
{
  int i,j,n,aux,*v;
  int op;
  clrscr();

    gotoxy(3,10);
    printf("%s","ESCRIBA LA LONGITUD DEL VECTOR:>");
    n=val_num(1);
    scanf("%d",&aux);
    v=(int *)malloc(aux);
      for(i=0;i<n;i++)
      {
       clrscr();
       _setcursortype(_NOCURSOR);
       gotoxy(3,19);cprintf("%s %d %s ", "ESCRIBA EN LA POSICION [",i+1,"]:");
       vec[i]=val_num(1);
	  }

     clrscr();
     gotoxy(2,10);
     printf("%s\n","VECTOR NORMAL");
     for(i=0;i<n;i++)
     {
      printf("%d\t",vec[i]);
     }
      printf("\n\n");
       for(i=0;i<(n-1);i++)
       {
	for(j=(i+1);j<n;j++)
	 if (vec[i]>vec[j])
	 {
	  aux=vec[i];
	  vec[i]=vec[j];
	  vec[j]=aux;
	     }
	  }
	  gotoxy(2,13);
	  printf("VECTOR ORDENADO ");
	  printf("\n\n");
	  for(i=0;i<n;i++)
	  {
	   printf("%d\t",vec[i]);
	   }

	getch();
}
/*-------------------------------------------------------------*/
int val_num(int cont)
  {
   int i,lon,op;
   char valido,valorn[9];
	  _setcursortype(_SOLIDCURSOR);
	  do
	  {
	  valido='n';
	  if(cont==2)
	  {
	     clreol();
	     scanf("\n"); gets(valorn);
	    }
	     if(cont==1)
	     {
	       gotoxy(34,10);
	       clreol();
	       scanf("\n");
	       gets(valorn);
	      }
	       lon = strlen(valorn);
	       for(i=0;i<=lon-1; i++)
	       {

		if(!(isdigit(valorn[i])) && valorn[i]!='-')
		 {
		  valido='m';
		  break;
		 }

	   }
	 }
	 while(valido=='m');
	 op=atoi(valorn);
	 return(op);
}
/*--------------------------------------------------------------------------*/
void seleccion()
{
  int i,j,aux,n,*ve;
  clrscr();
   gotoxy(3,10);
   printf("%s","ESCRIBA LA LONGITUD DEL VECTOR:>");
   n=val_num(1);
   scanf("%d",&aux);
   ve=(int *)malloc(aux);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(3,19);cprintf("%s %d %s ", "ESCRIBA EN LA POSICION [",i+1,"]:");
      vec[i]=val_num(1);
	  }

      clrscr();
      gotoxy(2,10);
      printf("%s\n","VECTOR NORMAL");
      for(i=0;i<n;i++)
      {
      printf("%d\t",vec[i]);
      }
      printf("\n\n");

	  for(i=0;i<=n-1;i++)
	   for(j=i+1;j<=(n-1);j++)
		   if(vec[i]>vec[j])
		   {
		     aux=vec[i];
		     vec[i]=vec[j];
		     vec[j]=aux;
		     }


	   gotoxy(2,13);
	   printf("VECTOR ORDENADO ");
	   printf("\n\n");
	   for(i=0;i<n;i++)
	   {
	    printf("%d\t",vec[i]);
	   }

	getch();

     }

/*-------------------------------------------------------------------*/
void quicksort()
{
 int i,n,aux,lim_izq,lim_der,izq,der,a,*vec;
 int pivote,j;
 clrscr();
   gotoxy(3,10);
   printf("%s","ESCRIBA LA LONGITUD DEL VECTOR:>");
   n=val_num(1);
    scanf("%d",&aux);
    vec=(int *)malloc(aux);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(3,19);cprintf("%s %d %s ", "ESCRIBA EN LA POSICION  [",i+1,"]:");
      vec[i]=val_num(1);
	  }
   clrscr();
   lim_izq=0;
   lim_der=n-1;
     gotoxy(2,10);
     printf("%s\n","VECTOR NORMAL");
    for(i=0;i<n;i++)
    {
     printf("%d\t",vec[i]);
    }
     printf("\n\n");


    izq=lim_der;
    der=lim_izq;

    a=vec[0];
    while(izq<=der)
    {
      while(vec[izq]<a && izq<lim_der)
	  izq++;
       while(vec[der]>a)
	 der--;
	  if(izq<=der)
	  {
	   aux=vec[izq];
	   vec[izq]=vec[der];
	   vec[der]=aux;
	   izq++;
	   der--;
	   }
	 }
	if(izq<lim_der+1)
	{
	   aux=vec[der];
	   vec[der]=vec[0];
	   vec[0]=aux;
	   }
	   else
	   {
	   aux=vec[lim_der];
	   vec[lim_der]=vec[0];
	   vec[0]=aux;
	     }
      for(i=0;i<n;i++)
       {
	 printf("%d\t",vec[i]);
	}
	 printf("\n\n");

	   gotoxy(2,13);
	    printf("VECTOR ORDENADO ");
	    printf("\n\n");
	    for(i=0;i<n;i++)
	    {
	     printf("%d\t",vec[i]);
	     }

	getch();
}

/*--------------------------------------------------------------------------*/
void insercion(){
int i,n,aux,p,u,c,k,*vect;
int j;
clrscr();
   gotoxy(3,10);
   printf("%s","ESCRIBA LA LONGITUD DEL VECTOR:>");
   n=val_num(1);
    scanf("%d",&aux);
    vect=(int *)malloc(aux);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(3,19);cprintf("%s %d %s ", "ESCRIBA  EN LA POSICION [",i+1,"]:");

      vec[i]=val_num(1);
	  }
  clrscr();
  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
  printf("%d\t",vec[i]);
  }
  printf("\n\n");

for(i=1;i<n;i++){
aux=vec[i];
p=0;
u=i-1;
  for(;p<=u;){
  c=(p+u)/2;
  if(aux<vec[c])
   u=c-1;
  else
  p=c+1;
  }
for(k=i-1;k>=p;k--){
  vec[k+1]=vec[k];
  }
  vec[p]=aux;
  }
       gotoxy(2,13);
       printf("VECTOR ORDENADO ");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();
  }
/*-----------------------------------------------------------------*/
 void shell()
  {
  int j,i,n,k=0,*vect,intervalo,aux;
   textcolor(12);
   clrscr();
   gotoxy(3,10);
   printf("%s","ESCRIBA LA LONGITUD DEL VECTOR:>");
   n=val_num(1);
   scanf("%d",&n);
   vect=(int *)malloc(n);
 
    
  for(i=0;i<n;i++)
  {
    printf("ESCRIBA EN LA POSICION   => ");
    scanf("%d",&vect[i]);
   }

    printf("\n NUMEROS DIGITADOS \n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vect[k]);

		     }
	intervalo=n/2;
	while(intervalo>0){
	    for(i=intervalo;i<n;i++){
	      j=i-intervalo;
	      while(j>=0){
	      k=j+intervalo;
		 if(vect[j]<=vect[k]){
		    j=0;
		      }
		   else
		   {
		   aux=vect[j];
		   vect[j]=vect[k];
		   vect[k]=aux;
		   }
		  j=j-intervalo;
		  }
		}
	      intervalo/=2;
	     }
	       printf("\n  ORDENAMIENTO  \n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vect[k]);
		     }
	      getch();
	   }


/*-----------------------------------------------------------------------*/
void main()
{
 clrscr();
 menu();
}



