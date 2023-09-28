#include"stdio.h"
#include"conio.h"
#include <ctype.h>

void menu();
void burbuja();
int validar(int num, int f,int c);
void insercion();
void sandra(int *vector,int p,int u);
void quick_sort();
void seleccion();
void cuadro();
int vector[100];


/*************************************************************************/
void main()
{ 
 menu ();
}

void cuadro(ci,cf,fi,ff)
{
 int i;
 textcolor(0);textbackground(15);
 for(i=ci;i<=cf;i++)
 {
  delay(5); gotoxy(i,fi); printf("Í");
  delay(5); gotoxy(i,ff); printf("Í");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(5); gotoxy(ci,i); printf("º");
  delay(5); gotoxy(cf,i); printf("º");
  }
 gotoxy(ci,fi); printf("É");
 gotoxy(ci,ff); printf("È");
 gotoxy(cf,fi); printf("»");
 gotoxy(cf,ff); printf("¼");
 textcolor(14); textbackground(1);
 }


void menu()
{
 int tecla,f,i;
 char opciones[25][45];

 strcpy(opciones[12],"BURBUJA                    ");
 strcpy(opciones[13],"QUICK SORT                 ");
 strcpy(opciones[14],"POR INSERCCION             ");
 strcpy(opciones[15],"SELECCION                  "); 
 strcpy(opciones[16],"TERMINAR                     ");
  do
 {
 textcolor(14); textbackground(1);
 clrscr();
 gotoxy(30,10); textcolor(11); textbackground(1);
 printf("MENU PRINCIPAL");
 textcolor(0);textbackground(5);
 cuadro(19,55,9,17);
 cuadro(17,57,8,18);
 textcolor(14); textbackground(1);
 for(f=12; f<=16; f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=12;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
	  while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
	 if (tecla==80)
	 {
	  textcolor(14);textbackground(1);
	  gotoxy(20,f);cprintf(opciones[f]);
	  if(f!=16)
	  f=f+1;
	  else

    f=12;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=12)
   f=f-1;
   else

	 f=16;
	 textcolor(0);textbackground(15);
	 gotoxy(20,f);cprintf(opciones[f]);
	 textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 12: burbuja(); 
	  break;
 case 13: quick_sort(); 
	  break;
 case 14: insercion(); 
	  break;
 case 15: seleccion(); 
	  break;
 case 16: default:  printf("usted ha terminado");
 }

}
 while(f!=16);
}










/*-----------------------------------------------------------------------*/

int validar(int num,int f, int c)
  {int i,lon,op;
   char valido,valorn[9];
	  do
	  {
	  valido='n';
	  if(num==2){
	  clreol();
	  scanf("\n"); gets(valorn);
	  }
	  if(num==1){
	  gotoxy(f,c);
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
	 }while(valido=='m');
	op=atoi(valorn);
 return(op);
}




/*----------------------------------------------*/

void seleccion()
{
int i,j,aux,n;
clrscr();
   gotoxy(10,7);
	printf("%s","DIGITE LA DIMENSION DEL VECTOR:");
	n=validar(1,68,7);
	  for(i=0;i<n;i++)
	  {
		clrscr();
		gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
		vector[i]=validar(1,65,13);
	  }

  clrscr();

	  for(i=0;i<=n-1;i++)
	   for(j=i+1;j<=(n-1);j++)
			if(vector[i]>vector[j]){
			  aux=vector[i];
			  vector[i]=vector[j];
			  vector[j]=aux;
			  }


       gotoxy(2,13);
		 printf("VECTOR ORDENADO POR METODO DE SELECCION : ");
		 printf("\n\n");
		 for(i=0;i<n;i++)
		 {
		 printf("%d\t",vector[i]);
		 }

	getch();

	  }




/*---------------------------------------------------------------------*/




void insercion()
{
int i,n,aux,p,u,c,k;
int j;
clrscr();
   gotoxy(10,7);
	printf("%s","DIGITE LA DIMENSION DEL VECTOR:");
	n=validar(1,68,7);
	  for(i=0;i<n;i++)
	  {
		clrscr();
		gotoxy(12,13);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
		vector[i]=validar(1,55,13);
	  }
  clrscr();


for(i=1;i<n;i++){
aux=vector[i];
p=0;
u=i-1;
  for(;p<=u;){
  c=(p+u)/2;
  if(aux<vector[c])
	u=c-1;
  else
  p=c+1;
  }
for(k=i-1;k>=p;k--){
  vector[k+1]=vector[k];
  }
  vector[p]=aux;
  }
       gotoxy(2,13);
		 printf("VECTOR ORDENADO POR METODO DE INSERCION : ");
		 printf("\n\n");
		 for(i=0;i<n;i++)
		 {
		 printf("%d\t",vector[i]);
		 }

	getch();
  }



/*-------------------------------------------------------------------*/


  void quick_sort()
  {
  int k,i,j,n,aux;
	  clrscr();
	  gotoxy(10,7);
	printf("%s","DIGITE LA DIMENSION DEL VECTOR :");
	n=validar(1,68,7);
	  for(i=0;i<n;i++)
	  {
		clrscr();
		gotoxy(12,7);cprintf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"] :");
		vector[i]=validar(1,55,7);
	  }
  clrscr();

 sandra(vector,0,n-1);

  printf("%s\n","VECTOR ORDENADO POR EL METODO DE QUICK SORT");
  for(i=0;i<n;i++)
  {
  printf("%d\t",vector[i]);
  }
  printf("\n\n");
  getch();
}


/*----------------------------------------------------------------*/



void sandra(int *vector,int p,int u)
{
	int j,i,mitad,sw=0,aux;
	mitad=vector[(p+u)/2];
	i=p;
	j=u;
	do{
	for(;vector[i]<mitad;i++)
		 ; 
	for(;vector[j]>mitad;j--)
		 ;

       if(i<=j){
	  aux=vector[i];
	  vector[i]=vector[j];
	  vector[j]=aux;
		  }
		  i++;j--;
		  if(i>j)
			 sw=1;
		  }while(sw==0);
		  if(p<j)
		  sandra(vector,p,j);
		  if(i<u)
		  sandra(vector,i,u);
	   }

/*--------------------------------------------------------*/


void burbuja()
{
int i,j,n,aux;
int op;
clrscr();

	gotoxy(10,7);

	printf("DIGITE LA DIMENSION DEL VECTOR  : ");

	n=validar(1,50,7);

     for(i=0;i<n;i++)
     {
      clrscr();
		gotoxy(10,10);printf("%s %d %s ", "DIGITE EL VALOR EN LA POSICION [",i+1,"]:");
		vector[i]=validar(1,75,10);
	  }

  clrscr();


		 gotoxy(2,5);
		 printf("VECTOR ORDENADO POR BURBUJA : ");
  

  for(i=0;i<(n-1);i++)
  {
   for(j=(i+1);j<n;j++)
	 if (vector[i]>vector[j])
	 {
		aux=vector[i];
		vector[i]=vector[j];
		 vector[j]=aux;
	  }
  }
	  printf("\n\n");
       for(i=0;i<n;i++)
       {
		 printf("%d\t",vector[i]);
		 }

	getch();
}

