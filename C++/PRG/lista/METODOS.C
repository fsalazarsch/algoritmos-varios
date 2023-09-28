#include"conio.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*************************************************************************/
  void cuadro();
  //void piso();
  void menu();
  void menu_2();
  void burbuja();
  int val_num(int cont);
  void insercion();
  void quick_sort();
  void partir(int *,int,int);
  void seleccion();
  void shell_sort();
  void cuadro1();
  int vec[100],u;

/************************************************************************/
/*void piso()
{   for (u=3;u<22;u++)
   { //gotoxy(1,u);
     textcolor(1);
     cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   }
 }              */

void cuadro1()
{
 int x;
for(x=2;x<=79;x++)
{
  delay(2);sound(x*295);printf("Ä");
}
for(x=2;x<=79;x++)
{
  delay(2);sound(x*295);printf("Ä");
   gotoxy(x,25);
}
for(x=2;x<=25;x++)
{
    delay(2);sound(x*295);printf("³");
    gotoxy(1,x);
}
for(x=2;x<=25;x++)
{
    delay(2);sound(x*295);printf("³");
    gotoxy(79,x);
}

delay(2);sound(x*295);gotoxy(1,1);printf("Ú");
delay(2);sound(x*295);gotoxy(79,1);printf("¿");
delay(2);sound(x*295);gotoxy(1,25);printf("À");
delay(2);sound(x*295);gotoxy(79,25);printf("Ù");
nosound();
}
void cuadro(int ci,int fi,int cf,int ff)
 {  int i;
   i=ci;
   textcolor(0);
   for (i=ci;i<=cf;i++)
   {
    gotoxy(i,fi);cprintf("Í");
    gotoxy(i,ff);cprintf("Í");
   }
   i=fi;
   for (fi=i;i<=ff;i++)
   {
     gotoxy(ci,i);cprintf("º");
     gotoxy(cf,i);cprintf("º");
   }
    gotoxy(ci,fi);cprintf("É");
    gotoxy(cf,fi);cprintf("»");
    gotoxy(ci,ff);cprintf("È");
    gotoxy(cf,ff);cprintf("¼");
 }



/*************************************************************************/

void main()
{
char op;

  do{

    clrscr();

    cuadro1();
    textcolor(15);
    textbackground(3);
    cuadro(28,6,62,8);
    gotoxy (30,7); cprintf("M E N U  O R D E N A M I E N T O");
    cuadro(28,6,62,18);
    gotoxy (33,10); cprintf("1. BURBUJA");
    gotoxy (33,11); cprintf("2. QUICK SORT");
    gotoxy (33,12); cprintf("3. POR INSERCION");
    gotoxy (33,13); cprintf("4. SELECCION");
    gotoxy (33,14); cprintf("5. SHELL SORT");
    gotoxy (33,15); cprintf("6. SALDRAS DEL PROGRAMA");
    gotoxy (33,17); cprintf("[ ] OPCION ");gotoxy(34,17);printf("");

    op=getch();

    switch (op)
    {
      case '1':burbuja(); clrscr(); break;
      case '2':clrscr();quick_sort();getch();clrscr();break;
      case '3':insercion();clrscr();break;
      case '4':seleccion();clrscr();break;
      case '5':shell_sort();clrscr();break;

    }

   } while (op!='6');

}




/****************************burbuja************************************/
void burbuja()

{

int i,j,n,aux;

int op;

clrscr();
   //cuadro();
       cuadro(1,3,80,22);
   gotoxy(6,19);

   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");

   n=val_num(1);

     for(i=0;i<n;i++)

     {

      clrscr();

      gotoxy(5,19);cprintf("%s %d %s ", "DIGITE LA POSICION [",i+1,"]:");

      vec[i]=val_num(1);

	  }



  clrscr();

  gotoxy(4,10);

  printf("%s\t","VECTOR NORMAL");

  for(i=0;i<n;i++)

  {

  printf("%d\t",vec[i]);

  }

  printf("\t\t");

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

       gotoxy(4,13);

       printf("VECTOR ORDENADO DE MENOR A MAYOR: \t");

       for(i=0;i<n;i++)

       {

	       printf("%d\t",vec[i]);

       }


     gotoxy(15,25);
     printf("<<ENTER>> y !REGRESARAS­ ");

	getch();

}

int val_num(int cont)
{
int i,lon,op;

   char valido,valorn[9];

	  _setcursortype(_SOLIDCURSOR);

	  do

	  {

		  valido='n';

		  if(cont==2){

		  clreol();

		  scanf("\n"); gets(valorn);//strupr(valorn);

	  }

	  if(cont==1)
	  {

	      gotoxy(34,19);

	      clreol();

	      scanf("\n");

	      gets(valorn);//strupr(valorn);

	  }

	  lon = strlen(valorn);

	  for(i=0;i<=lon-1; i++)

	   {

	     if(!(isdigit(valorn[i])) && valorn[i]!='-')


	      {

		 valido='m';break;

	      }



	    }

	 }
	 while(valido=='m');

	 op=atoi(valorn);

 return(op);

}

/******************seleccion*********************/

void seleccion()
{

int i,j,aux,n;

clrscr();
   //cuadro();
       cuadro(1,3,80,22);
   gotoxy(6,19);

   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");

   n=val_num(1);

     for(i=0;i<n;i++)

     {

      clrscr();

      gotoxy(5,19);cprintf("%s %d %s ", "DIGITE LA POSICION [",i+1,"]:");

      vec[i]=val_num(1);

	  }



  clrscr();
  gotoxy(4,10);

  printf("%s\t","VECTOR NORMAL");

  for(i=0;i<n;i++)

  {

  printf("%d\t",vec[i]);

  }

  printf("\t\t");



	  for(i=0;i<=n-1;i++)

	   for(j=i+1;j<=(n-1);j++)

		   if(vec[i]>vec[j]){

		     aux=vec[i];

		     vec[i]=vec[j];

		     vec[j]=aux;

		     }





       gotoxy(4,13);

       printf("VECTOR ORDENADO DE MENOR A MAYOR: \t");

       for(i=0;i<n;i++)

       {

       printf("%d\t",vec[i]);

       }

     gotoxy(15,25);
     printf("<<ENTER>> y !REGRESARAS­ ");


	getch();



     }



/******************insercion*********************/



void insercion()
{

int i,n,aux,p,u,c,k;

int j;

clrscr();
   //cuadro();
       cuadro(1,3,80,22);
   gotoxy(6,19);

   printf("%s","DIGITE EL LIMITE DEL VECTOR:>");

   n=val_num(1);

     for(i=0;i<n;i++)

     {

      clrscr();

      gotoxy(5,19);cprintf("%s %d %s ", "DIGITE LA POSICION [",i+1,"]:");

      vec[i]=val_num(1);

	  }

  clrscr();

  gotoxy(4,10);

  printf("%s\t","VECTOR NORMAL");

  for(i=0;i<n;i++)

  {

  printf("%d\t",vec[i]);

  }

  printf("\t\t");



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

       gotoxy(4,13);

       printf("VECTOR ORDENADO DE MENOR A MAYOR:\t");

       for(i=0;i<n;i++)

       {

       printf("%d\t",vec[i]);

       }


     gotoxy(15,25);
     printf("<<ENTER>> y !REGRESARAS­ ");

	getch();

  }
 /********************************shel sort***************************************/
 void shell_sort(){
  int j,i,n,k=0,intervalo,aux,vec[20];
  clrscr();
  //cuadro();
      cuadro(1,3,80,22);
  gotoxy(6,9);  printf("DIGITE EL LIMITE DEL VECTOR:  ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vec[i]);
  }
    clrscr();
    gotoxy(4,13);printf("VECTOR NORMAL\t");
	 for(k=0;k<n;k++)
		   {
			   printf("%d\t",vec[k]);
		    }
	intervalo=n/2;
	while(intervalo>0){
	    for(i=intervalo;i<n;i++){
	      j=i-intervalo;
	      while(j>=0){
	      k=j+intervalo;
		 if(vec[j]<=vec[k]){
		    j=0;
		      }
		   else
		   {
		   aux=vec[j];
		   vec[j]=vec[k];
		   vec[k]=aux;
		   }
		  j=j-intervalo;
		  }
		}
	      intervalo/=2;
	     }
	       gotoxy(4,18);printf("VECTOR ORDENADO\t\t");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vec[k]);
		     }

     gotoxy(15,25);
     printf("<<ENTER>> y !REGRESARAS­ ");
	   getch();
  }
/********************Quick Sort****************************/

  void quick_sort(){

  int k,i,j,n,vect[100],aux;
//     cuadro();
	 cuadro(1,3,80,22);
     gotoxy(6,19);
     printf("%s","DIGITE EL LIMITE DEL VECTOR:>");

   n=val_num(1);

     for(i=0;i<n;i++)

     {

      clrscr();

      gotoxy(5,19);cprintf("%s %d %s ", "DIGITE LA POSICION [",i+1,"]:");

      vect[i]=val_num(1);

	  }

  clrscr();

  gotoxy(4,10);

  printf("%s\t","VECTOR NORMAL");

  for(i=0;i<n;i++)

  {

   printf("%d\t",vect[i]);

  }

       partir(vect,0,n-1);

       gotoxy(4,13);

       printf("VECTOR ORDENADO DE MENOR A MAYOR: \t");

  for(i=0;i<n;i++)

  {

     printf("%d\t",vect[i]);

  }
	gotoxy(15,25);
     printf("<<ENTER>> y !REGRESARAS­ ");

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





