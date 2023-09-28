# include "alloc.h"
# include "conio.h"
# include "stdio.h"
# include "stdlib.h"
# include "dos.h"
# include "string.h"
# include "ctype.h"

int nu,i=0,sw=1;

void ordenamiento();
void burbuja();
int val_num(int cont);
void seleccion();
void shell();
void quick();
//void cuadros();
//int x1, x2, y1, y2,j;

//void mar();
//int( x1, y1, x2, y2);
void cuadros(int x1,int y1,int x2,int y2);
void cuadros(int x1,int y1,int x2,int y2)
{
 int i;
 gotoxy(x1, y1); printf("%c",218);// Ú
 gotoxy(x2, y1); printf("%c",191);//¿
 gotoxy(x1, y2); printf("%c",192);//À
 gotoxy(x2, y2); printf("%c",217);//Ù
 for(i=(x1+1);i<=(x2-1);i++)
 {
  gotoxy(i, y1);printf("%c",196);//Ä
  gotoxy(i, y2);printf("%c",196);
  delay(15);
 }

 for(i=(y1+1);i<=(y2-1);i++)
 {
  gotoxy(x1, i);printf("%c",179);//³
  gotoxy(x2, i);printf("%c",179);
 }
}

void mar(int x1,int x2,int y1,int y2)
{
  int j,i,k;
  textcolor(14);textbackground(0);
  for(j=x1;j<=x2;j++)
  {
   gotoxy(j,y1);cprintf("Í");
   gotoxy(j,y2);cprintf("Í");
   delay(10);
  }
  for(i=y1;i<=y2-1;i++)
  {
   gotoxy(x1,i);cprintf("º");
   gotoxy(x2,i);cprintf("º");
   delay(10);
  }
  gotoxy(x1,y1);cprintf("É");
  gotoxy(x2,y1);cprintf("»");
  gotoxy(x1,y2);cprintf("È");
  gotoxy(x2,y2);cprintf("¼");
} 

void mensaje(int col,int fil,char letrero[])
{
  gotoxy(col,fil);
  cprintf("%s",letrero);
}

void menu()
{
 int sw,op;

  textbackground(1);
  clrscr();


  for(i=1;i<1761;i++)
  {
   textcolor(2);
   cprintf("%c",219);
  }

   for(i=1761;i<2000;i++)
   {
   textcolor(1);
   cprintf("%c",219);
   gotoxy(34,37); printf("Carmen Jacquin");
  }
 cuadros(2,79,2,23);textcolor(15);
 gotoxy(20,1);cprintf("                                               " ) ;
  gotoxy(20,2);cprintf("        M E N U   P R I N C I P A L           " ) ;
  gotoxy(20,3);cprintf("                                              " ) ;


 textcolor(0);
 mar(5,76,4,21);
 mar(8,73,6,19);
 do{
	mensaje(25,9,"[1] METODOS DE ORDENAMIENTO");
      //mensaje(25,10,"[2] ORDENAMIENTO DE BUSQUEDA");
	mensaje(25,11,"[3] SALIR");
	mensaje(15,14,"Introduzca una opci¢n y pulse <<ENTER>>");
	mensaje(25,16,"SU OPCION ?[ ]"); mensaje(37,16,"");
		  op=getchar();sound(300);delay(57);nosound();
	switch(op)

  {
   case '1' : sw=2;
	     clrscr();ordenamiento(); break;
//case '2' :
   case '3' :
	      clrscr();
	      mensaje(33,12," GOOD BYE !!!!!!!!!"); delay(2000);
	     exit(1);

  }
 } while(op!=3);
}



void ordenamiento()
{
 int sw;
 short op;
    do{
	short op;
	clrscr();
	mensaje(35,3," METODOS DE ORDENAMIENTO");
	mensaje(25,9,"[1] BURBUJA");
	mensaje(25,10,"[2] QUICKSORT");
	mensaje(25,11,"[3] SELECCION");
	mensaje(25,12,"[4] SHELL_SORT");
	mensaje(25,13,"[5] RETORNAR");
	mensaje(9,19,"Introduzca una opci¢n y pulse <<ENTER>>");
	mensaje(9,21,"SU OPCION ?[ ]"); mensaje(21,21,"");
		  op=getchar();sound(300);delay(57);nosound();
	switch(op)

  {
   case '1' : sw=2;
	     clrscr();burbuja(); break;

case '2' :  sw=3;
	     clrscr();quick();break;


case '3' :  sw=4;
	     clrscr();seleccion();break;


case '4' :  sw=5;
	     clrscr();shell();break;



case '5' :

menu();break;
  }

    }while(op!=5);
 }



void burbuja()
{
   int x[99];
    int i,j,aux,aux1,n,lon;
    char valido,ced[20];
    long auxced; int sw;
    clrscr();
     do
     {
      valido='n';
      gotoxy(38,4);
      printf("                               ");
      gotoxy(5,4);printf("DIGITE CUANTOS NUMEROS A ORDENAR: ");
      scanf("\n");gets(ced);
      lon = strlen(ced);
      for(i=0;i<=lon-1; i++)
	{
	 if(!(isdigit(ced[i])))
	  {
	    valido='m';
	    break;
	  }
	}
    }while(valido=='m');
     aux1=atoi(ced);
     for(i=0;i<aux1;i++){
     printf("DIGITE EL NUMERO: ");
       scanf("%d",&x[i]);
       }
	for(i=0;i<aux1;i++)
	  for(j=0;j<aux1-1;j++)
	    if(x[j] > x[j+1]){
	     aux=x[j];
	     x[j]=x[j+1];
	     x[j+1]=aux;
	   }
	   for(j=0;j<aux1;j++){
	   printf("%d\t",x[j]);
	 }
	 getche();

}
void quick(){
int indice=1;
int n, izq[20],der[20],i,j;
int v[20],sw,aux,x;
int tempi,tempj;

 clrscr();
  printf("dimencion del vector");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {

    printf("Digite la posici¢n [ %d %s",i," ] ...");
    scanf("%d",&v[i]);
   }
   izq[indice]=0;
   der[indice]=n-1;
   do{
     i=izq[indice];
     j=der[indice];
     indice--;
     tempi=i;
     tempj=j;
     x=v[(i+j)/2];

       sw=0;
       do{
	 for(;x>v[i];i++)
	  {
	     ;
	  }
	   for(;x < v[j];j--)
	  {
	     ;
	  }
       if(i<j)
       {
	  aux=v[i]; //esto es lo que hacemos cuando aparece cambio
	  v[i]=v[j];
	  v[j]=aux;
	  i++;
	  j--;
       }
       if(i>=j)
	 sw=1;
       }while(sw!=1);
       if(i==j)
       {
	 if(x < v[i])
	 {
	   j--;
	  }
	   else
	   {
	     i++;
	   }
	 }
       if((tempj -i+1)>1)
       {
	   indice++;
	   izq[indice]=i;
	   der[indice]=tempj;
	}
	else
	{
	  if(v[i] > v[tempj])
	  {
	  aux=v[i]; 
	  v[i]=v[tempj];
	  v[tempj]=aux;
	  }
	}
	if((j-tempi+1) > 1)
	{
	    indice++;
	    izq[indice]=tempi;
	    der[indice]=j;
	}
	else
	{
	  if(v[tempi] > v[j])
	  {
	    aux=v[tempi]; 
	    v[tempi]=v[j];
	    v[j]=aux;
	   }
	}
   }while(indice != 0);
   for(i=0;i<n;i++)
		   {
		   printf("%d\t",v[i]);
		     }
		      getch();
		    

	  }




      void main ()
      {
       clrscr();
       menu();
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
void seleccion(){
int i,j,aux,n,vec[100];
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


 void shell(){
  int j,i,n,k=0,*vect,intervalo,aux;
gotoxy(2,3);  printf("DIMENCION DEL VECTOR...:  ");
  scanf("%d",&n);
    vect=(int *) malloc(n);
  for(i=0;i<n;i++)
  {
    printf("DIGITE LA POSICION [ %d %s",i," ] ...");
    scanf("%d",&vect[i]);
   }

    printf("\n\nVECTOR NORMAL\n\n");
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
	       printf("\n\nVECTOR ORDENADO\n\n");
	 for(k=0;k<n;k++)
		   {
		   printf("%d\t",vect[k]);
		     }
	      getche();
	   }




