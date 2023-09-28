#include"stdio.h"
#include"conio.h"
#include <ctype.h>
/*************************************************************************/
  void main();
  void burbuja();
  int val_num(int cont);
  void quick_sort();
  void insercion();
  void shell_sort();
  void partir(int *,int,int);
int vec[100];

/*************************************************************************/
void main()
{
char op;

  do{
  textcolor(15);
  textbackground(1);
    clrscr();
    gotoxy (30,5); cprintf("MENU ORDENAMIENTO");
    gotoxy (33,8); cprintf("1.BURBUJA");
    gotoxy (33,10); cprintf("2.QUICK_SORT");
    gotoxy (33,12); cprintf("3.POR INSERCION");
    gotoxy (33,14); cprintf("4.SHELL_SORT");
    gotoxy (33,16); cprintf("5.SALIR");
    gotoxy (24,21); cprintf(" DIGITE LA OPCION Y PULSE ENTER ");
    gotoxy (33,19); cprintf("[ ] OPCION ");gotoxy(34,19);printf("");
    op=getche();
    switch (op)
    {
     case '1':clrscr();burbuja();break;
     case '2':clrscr();quick_sort();break;
     case '3':clrscr();insercion();break;
    case '4': clrscr();shell_sort();break;

    }
   } while (op!='5');


}

/*************************************************************************/
void burbuja()
{
int i,j,n,aux;
int op;
clrscr();

   gotoxy(10,7);
   printf("%s","DIGITE EL RANGO DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      gotoxy(10,8);
      clrscr();
      _setcursortype(_NOCURSOR);
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL NUMERO DE LA POSICION [",i+2,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }

  clrscr();
  gotoxy(2,10);
   printf("%s\n"," VECTOR NORMAL");
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
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();
}
int val_num(int cont)
  {int i,lon,op;
   char valido,valorn[9];
	  _setcursortype(_SOLIDCURSOR);
	  do
	  {
	  valido='n';
	  if(cont==2){
	  //printf("%s",op);
	  clreol();
	  scanf("\n"); gets(valorn);//strupr(valorn);
	  }
	  if(cont==1){
	  gotoxy(34,19);
	  clreol();
	  scanf("\n");
	  gets(valorn);//strupr(valorn);
	  }
	  lon = strlen(valorn);
	  for(i=0;i<=lon-1; i++)
	   {

	     if(!(isdigit(valorn[i])) && valorn[i]!='-')
	     //|| valorn[i]=='¤' )
	     {
	      valido='m';
	      break;
	    }

	   }
	 }while(valido=='m');
	op=atoi(valorn);
 return(op);
}
/******************shell_sort*********************/
void shell_sort(){
int i,j,aux,n;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
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
		   if(vec[i]>vec[j]){
		     aux=vec[i];
		     vec[i]=vec[j];
		     vec[j]=aux;
		     }


       gotoxy(2,13);
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();

     }

/******************insercion*********************/

void insercion(){
int i,n,aux,p,u,c,k;
int j;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
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
       printf("VECTOR ORDENADO DE MENOR A MAYOR");
       printf("\n\n");
       for(i=0;i<n;i++)
       {
       printf("%d\t",vec[i]);
       }

	getch();
  }
/********************Quick Sort****************************/
  void quick_sort(){
  int k,i,j,n,vect[100],aux;
     gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
      vect[i]=val_num(1);
	  }
  clrscr();
  gotoxy(2,10);
  printf("%s\n","VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
   printf("%d\t",vect[i]);
  }
  printf("\n\n");
 partir(vect,0,n-1);

  printf("%s\n","VECTOR ORDENADO");
  for(i=0;i<n;i++)
  {
  printf("%d\t",vect[i]);
  }
  printf("\n\n");
}
void partir(int *vect,int primero,int ultimo){
   int j,i,central,sw=0,aux;
   central=vect[(primero+ultimo)/2];
   i=primero;
   j=ultimo;
   do{
   for(;vect[i]<central;i++)
       ; 
   for(;vect[j]>central;j--)
       ;

       if(i<=j){
	  aux=vect[i];
	  vect[i]=vect[j];
	  vect[j]=aux;
	     }
	     i++;j--;
	     if(i>j)
	       sw=1;
	     }while(sw==0);
	     if(primero<j)
	     partir(vect,primero,j);
	     if(i<ultimo)
	     partir(vect,i,ultimo);
	   }


 void busqueda_binaria(){
 int i,n,k;
int j,encontrado=0,bajo,alto;
int central;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }
  clrscr();
   partir(vec,0,n-1);
   bajo=0;
   alto=n-1;

   printf("%s","DIGITE EL VALOR A BUSCAR:>");
   k=val_num(1);
   while(!encontrado &&bajo<=alto){
   central=(bajo+alto)/2;
   if(vec[central]==k)
      encontrado=1;
   else
     if(vec[central]>k)
      alto=central-1;
     else
      bajo=central+1;
     }
     if(encontrado)
     printf("Numero Encontrado");
     else
     printf("Numero No Encontrado");
     }
void busqueda_secuencial(){
 int i,n,k;
int j,encontrado=0,bajo,alto;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }
  clrscr();

   printf("%s","DIGITE EL VALOR A BUSCAR:>");
   k=val_num(1);
   while(!encontrado &&i<=n-1){
   
   if(vec[i]==k)
      encontrado=1;
   else
     i++;
     }
     if(encontrado)
     printf("Numero Encontrado");
     else
     printf("Numero No Encontrado");
     }