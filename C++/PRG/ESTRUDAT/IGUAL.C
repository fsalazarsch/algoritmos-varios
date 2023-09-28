#include <stdio.h>     
#include <conio.h>
#include <dos.h>
void main()
{
int i,j,aux,n,a[50],b[50],d[50][50]
clrscr();
void igual()
{

printf("DIGITE RANGO DEL VECTOR :  ");
scanf("%d",&n);
for(i=0;i<n;i++)
   {
     printf("DIGITE NUMERO DEL VECTOR A  :);
     scanf("%d",&a[i]);
   }
    for(i=0;i<n;i++)
       {
	printf("DIGITE UN NUMERO DEL VECTOR B  :);
	scanf("%d",&b[i]);
       }
	aux = 1;
	i = 0;
	while(i<n && aux == 1){
	  if(a[i]!=b[i])
	    {
	      aux = 0;
	    }
	      i++;
			      }