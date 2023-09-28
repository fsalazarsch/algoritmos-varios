#include <stdio.h>
#include <conio.h>
#include <dos.h>
int i,j,aux,n,a[50],b[50],d[50][50];

void igual();
void sumavec();
void parimpar();
void matriz();
void main(){
void homogenea();
void diagonal();
void superior();
void invertir();
clrscr();
//igual();
//sumavec();
//parimpar(); 
//matriz();
//homogenia();
//diagonal();
//superior();
//invertir();
getch();
}
void igual(){

printf("digite rango del vector::>");
scanf("%d",&n);

 for(i=0;i<n;i++){
    printf("digite un # del vec A::>");
    scanf("%d",&a[i]);
		  }
    for(i=0;i<n;i++){
      printf("digite un # del vec B::>");
	 scanf("%d",&b[i]);
		  }
	  aux=1;
	  i=0;
	  while(i<n && aux==1){
	    if(a[i]!=b[i]){
	       aux=0;     }
	       i++;
			      }

	   if( aux==1){
		 printf("son iguales");  }
	      if( aux==0){
		 
		 printf("son diferentes");}
getch();
}
/***************programa6********************/
void sumavec(){		 
int sum;
printf("digite rango del vector::>");
scanf("%d",&n);

 for(i=0;i<n;i++){
    printf("digite un # del vec A::>");
    scanf("%d",&a[i]);
		  }
    for(i=0;i<n;i++){
      printf("digite un # del vec B::>");
	 scanf("%d",&b[i]);
		  }

	  for(i=0;i<n;i++){
	     aux=aux+a[i];
	     sum=sum+b[i];
		  }

		  
       printf("suma de los vectores es\n\n");	  
       printf("\n\n");
       printf("resultado suma vec A::>%d\n",aux);
       printf("resultado suma vec B::>%d\n",sum);
       }
 /********programa7****************/
 void parimpar(){
int par[30],impar[30];
  printf("digite rango del vector::>");
   scanf("%d",&n);

    for(i=0;i<n;i++){
      printf("digite un # del vec A::>");
     scanf("%d",&a[i]);
		    }
	  aux=0;
	  for(i=0;i<n;i++){
	     if( a[i]%2==0) {
		par[i]=i+1;     
		impar[i]=0;   }
		  else {
		    impar[i]=i+1;
		    par[i]=0;
			}
			   }

for(i=0;i<n;i++){
  if(par[i]!=0)
  printf("posicion par::%d\n",par[i]);
		  }
for(i=0;i<n;i++){
    if(impar[i]!=0)
  printf("posicion impar::%d\n",impar[i]);
		  }
		  }
/*****************PROGRAMA 8************************/
void matriz(){
char A[20][20],a;
int i,k,m;
clrscr();
printf (" DIGITE NUMEROS DE FILAS:");
scanf ("%d",&m);
//printf (" DIGITE NUMEROS DE COLUMNAS:");scanf("%d",&n);
//printf("\n");
clrscr();
printf("INTRODUZCA VALORES DE LA PRIMERA MATRIZ");
j=0;
for (i =0 ; i <= m ; ++i){

    for (k = 0 ;k <=m ; ++k){
       gotoxy( k*4+3,i+5);
	 scanf("%c",&a); 
	 gotoxy (k*3+4,i+5);
	 A[i][k]= a;
			   }
 
	 }


for (i=0 ; i <=m ; ++i){
    for (k = 0 ;k <=m ; ++k){
	    if(	 A[i][k]=='a'|| A[i][k]=='A'){
		aux++;
		 j=1;                        }
 
			     }
			  }


   printf("\n");
if(j==0)
 
   printf("NO HAY LETRAS AAAAAAA");
    else
      printf("EN LA MATRIZ EXISTEN  %d%s\n",aux,"  AAAs");


getch();
}



/****************PROGRAMA 9**********************/

/*void homogenia(){
int A[20][20],c[20][20],a;
int i,k,m;
clrscr();
printf (" DIGITE NUMEROS DE FILAS:");
scanf ("%d",&m);
clrscr();
printf("INTRODUZCA VALORES DE LA PRIMERA MATRIZ");

for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k<  m ; ++k){printf("%d\n");
       gotoxy( k*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (k*3+4,i+5);
	 A[i][k]= a;
			   }
			  }

clrscr();
printf("INTRODUZCA VALORES DE LA SEGUNDA MATRIZ");

for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k < m ; ++k){
	 gotoxy( k*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (k*3+4,i+5);
	 d[i][k]= a;
			   }
			  }

/**---------------------------*/
/*for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k < m ; ++k){
       c[i][k]=  A[i][k]+ d[i][k];
			   }
			  }
  */
/**---------------------------*/
/*printf("\n");
for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k < m ; ++k){
printf("%d\n",c[i][k]);
			   }
			  }

} */

/*************PROGRAMA 10***************/

void diagonal(){
int A[4][4];
int i,k,m,sum;
clrscr();
printf("INTRODUZCA VALORES DE LA  MATRIZ");

for (i =0 ; i <  4 ; ++i){
    for (k = 0 ;k<  4 ; ++k){
       gotoxy( k*4+3,i+5);
	 scanf("%d",&n); 
	   gotoxy (k*3+4,i+5);
	 A[i][k]= n;
			   
	 }
       }
 sum=0;      	 		  
for (i =0 ; i <  4 ; ++i){
    for (k = 0 ;k<  4 ; ++k){
	 if (i==k)
	    sum=sum+A[i][k];

	  }
     }
     gotoxy(20,20);printf(" LA SUMA DE LA DIAGONAL ES:%d",sum);
 }       


 /**************11**************/
 void superior(){
 int A[4][4];
int i,k,m,sum,a;
clrscr();
printf("INTRODUZCA VALORES DE LA  MATRIZ");

for (i =1 ; i <=  4 ; ++i){
    for (k = 1 ;k<=  4 ; ++k){
       gotoxy( k*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (k*3+4,i+5);
	 A[i][k]= a;
			   
	 }
       }
	sum=0;
       for(i=1;i<=1;++i){	
	for(k=1;k<=4;++k) {
	  sum=sum+A[i][k];
	 }
       }
	gotoxy(20,20);printf("la suma de diag.superior:%d",sum);
      }
/***********************************************************/
 void inferior(){
 int A[40][40];
int i,k,m,sum,a;
clrscr();
printf("INTRODUZCA VALORES DE LA  MATRIZ");

for (i =1 ; i <=  4 ; ++i){
    for (k = 1 ;k<=  4 ; ++k){
       gotoxy( k*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (k*3+4,i+5);
	 A[i][k]= a;
			   
	 }
       }
	sum=0;
       for(i=1;i<=4;++i){	
	for(k=1;k<=1;++k) {
	  sum=sum+A[i][k];
	 }
       }
	gotoxy(20,20);printf("la suma de diag.inferior:%d",sum);
      }
/*************************************************************/
void invertir(){

char A[20][20],a;
int i,k,m,n;
clrscr();
printf (" DIGITE NUMEROS DE FILAS:");
scanf ("%d",&m);
printf (" DIGITE NUMEROS DE COLUMNAS:");
scanf("%d",&n);
printf("INTRODUZCA VALORES DE LA  MATRIZ");

for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k<  n ; ++k){
       gotoxy( k*4+3,i+5);
	 scanf("%d",&a); 
	   gotoxy (k*3+4,i+5);
	 A[i][k]= a;
			   
	 }
       }
      for (i =0 ; i <  m ; ++i){
    for (k = 0 ;k<  n ; ++k){
	aux=A[i][k];
       A[i][k]= A[k][i];
       A[i][k]=aux;
      }
   }
  printf("%d\n",A[i][k]);

}
