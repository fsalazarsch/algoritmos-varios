#include"stdio.h"
#include"conio.h"
#include <ctype.h>
/*************************************************************************/
  void menu();
  void menu_2();
  void menu_3();
  void burbuja();
  int val_num(int cont);
  void insercion();
  void quick_sort();
  void partir(int *,int,int);
  void seleccion();
  void shell();
  void busqueda_binaria();
  void busqueda_secuencial();
int vec[100];
/************************************************************************/
void menu()
{
  char op1;

  do{
  textcolor(14);
  textbackground(7);
    clrscr();
    _setcursortype(_NOCURSOR);
    gotoxy (24,6); printf("<<M E N U     P R I N C I P A L>>");
    gotoxy (22,3); printf("CORPORACION UNIVERSITARIA DE SANTANDER");
    gotoxy (26,4); printf("EUCARDO FABIAN PE¥ALOZA PEREA");
    gotoxy (33,10); printf("1.METODOS PARA ORDENAR");
    gotoxy (33,12); printf("2.METODOS PARA BUSCAR");
    gotoxy(33,14); printf("3. SALIR");
    textcolor(128+1);
    gotoxy(24,21);cprintf(" DIGITE LA OPCION PREFERIDA ");
    gotoxy (29,24); printf("CODIGO:   96132053");
    gotoxy(33,19);printf("[ ] OPCION ");gotoxy(34,16);printf("");

    op1=getch();
    switch (op1)
    {

    case '1':menu_2();
	       break;
    case '2':
	    menu_3();
	       break;

    case '3':  exit(0);




    }
   } while (op1!='3');
 }
/*************************************************************************/
void main()
{ clrscr();
 menu ();
getche();
}
/*************************************************************************/
void menu_2()
{
char op;

  do{
  textcolor(5);
  textbackground(7);
    clrscr();
    gotoxy (24,6); cprintf("!!!!M E N U  P A R A   O R D E N A R!!!!");
    gotoxy (35,3); printf("----UDES----");
    gotoxy (33,8); cprintf("1.BURBUJA");
    gotoxy (33,10); cprintf("2.QUICK SORT");
    gotoxy (33,12); cprintf("3.INSERCION");
    gotoxy (33,14); cprintf("4.SELECCION");
    gotoxy (33,16); cprintf("5.SHELL_SORT");
    gotoxy (33,18); cprintf("6.VOLVEMOS AL MENU PRINCIPAL");
    textcolor(128+4);
    gotoxy (24,21); cprintf(" DIGITE LA OPCION QUE DESEE ");
    gotoxy (33,19); cprintf("[ ] OPCION ");gotoxy(34,19);printf("");
    op=getche();
    switch (op)
    {
     case '1':burbuja(); clrscr(); break;
     case '2':clrscr();quick_sort();getch();clrscr();break;
     case '3':insercion();clrscr();break;
    case '4': seleccion();clrscr();break;
    case '5': shell();clrscr();break;

    }
   } while (op!='6');


}

/************************************************************************/
void menu_3()
{
  int op3;

  do{
  textcolor(14);
  textbackground(5);
    clrscr();
    gotoxy (24,6); printf("----M E N U   P A R A   B U S C A R----");
    gotoxy (35,3); printf("----UDES----");
    gotoxy (33,10); printf("1.SECUENCIAL");
    gotoxy (33,12); printf("2.BINARIA");
    gotoxy (33,14); printf("3.VOLVEMOS AL MENU PRINCIPAL");
    textcolor(128+7);
    gotoxy(24,21);cprintf(" DIGITA LA OPCION QUE QUIERES ");
    gotoxy(33,17);printf("[ ] OPCION ");gotoxy(34,17);printf("");
    op3=getch();


    switch (op3)
    {
     case '1':
     case '2':busqueda_binaria();getch();break;
    }
   } while (op3!='3');

}
/*************************************************************************/
void burbuja()
{
int i,j,n,aux;
int op;
clrscr();

   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      _setcursortype(_NOCURSOR);
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }

  clrscr();
  gotoxy(2,10);
  printf("%s\n"," ES UN VECTOR NORMAL");
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
/********************seleccion*****************************/
void seleccion(){
int i,j,aux,n;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
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
  printf("%s\n","ES UN VECTOR NORMAL");
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
/********************shell_sort*********************************/
void shell()
  {
  int j,i,n,k=0,vect[100],intervalo,aux;
   clrscr();
   gotoxy(3,19);
   printf("%s","ESCRIBA LA LONGITUD DEL VECTOR");
   n=val_num(1);
    
    
  for(i=0;i<n;i++)
  {
    printf("ESCRIBA EN LA POSICION  : ");
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

/******************insercion*****************************/

void insercion(){
int i,n,aux,p,u,c,k;
int j;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
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
  printf("%s\n","ES UN VECTOR NORMAL");
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
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
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
  printf("%s\n"," ES UN VECTOR NORMAL");
  for(i=0;i<n;i++)
  {
   printf("%d\t",vect[i]);
  }
  printf("\n\n");
 partir(vect,0,n-1);

  printf("%s\n"," EL VECTOR ESTA ORDENADO");
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
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
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

   printf("%s","DIGITE EL VALOR QUE DESEAS BUSCAR:>");
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
     printf("ESTE ES EL NUMERO:  OK");
     else
     printf("NUMERO NO ENCONTRADO VIEJO");
     }
void busqueda_secuencial(){
 int i,n,k;
int j,encontrado=0,bajo,alto;
clrscr();
   gotoxy(10,7);
   printf("%s","DIGITE EL LIMITE DE SU VECTOR:>");
   n=val_num(1);
     for(i=0;i<n;i++)
     {
      clrscr();
      gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
      gotoxy(49,13);printf("::>");
      vec[i]=val_num(1);
	  }
  clrscr();

   printf("%s","DIGITE EL VALOR QUE DESEAS BUSCAR:>");
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