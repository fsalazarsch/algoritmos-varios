#include<conio.h>
#include<stdio.h>
void main()
{
int v[100],i,j,aux,n;
clrscr();
printf("DIGITE EL TAMA¥O DEL VECTOR  ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("DIGITE EL ELEMENTO i  ");
scanf("%d",&n);}
	   
   for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++)
	if(v[i]>v[j]){
	aux=v[i];
	v[i]=v[j];
	v[j]=aux;
      }
      
   }	
printf("\n\n");
printf("EL VECTOR ORDENADO ACENDENTEMENTE ES "); 
       for(j=0;j<n;j++){                         
     scanf("%d", &v[j]");}
getche();
}

 