#include<conio.h>
#include<stdio.h>
int i,j,intervalo,her[10],n,k,aux;
void main()
{
clrscr();
printf("dimencion:  ");
scanf("%d",&n);
for(i=0;i<=n;i++){
      printf("posicion[%d %s ",i,"]  ");
	    scanf("%d",&her[i]);
	    }
  intervalo=n/2;
     while(intervalo>0){
    for(i=intervalo;i<=n;i++){
    j=i-intervalo;
      while(j>=0){
      k=j+intervalo;
      if(her[j]<=her[k]){
      j=0;
      }
      else{
      aux=her[j];her[j]=her[k];
      her[k]=aux;
	     }
	     j=j-intervalo;
	 }      }
      intervalo/= 2;
      }
      printf(" vector ordenado: ");
      for(k=0;k<=n;k++){
	printf("%d\t",her[k]);
	}
	getch();

	}