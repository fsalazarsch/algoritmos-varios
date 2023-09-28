#include <stdio.h>
#include <conio.h>
#include <dos.h>
void burbuja();
void main(){
clrscr();
burbuja();
getch();
}
void burbuja(){
int i,j,aux,n,a[50];
printf("DIGITE CANTIDAD DEL VECTOR::>");
scanf("%d",&n);

 for(i=1;i<=n;i++){
    printf("DIGITE UN NUMERO#::>");
    scanf("%d",&a[i]);
		  }
	    i=1;
	   while(i<n){
	       j=i+1;
	     while(j<=n){
	       if (a[i] > a[j]){
		 aux=a[i];
		 a[i]=a[j];
		 a[j]=aux;
				}
		 j++;    }
		 i++; }
	 printf("VECTOR ORDENADO\n\n");
 for(i=1;i<=n;i++){
    printf("%d \n",a[i]);
		  }
}