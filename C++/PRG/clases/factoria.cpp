#include<stdio.h>
main ()
{
/*Este programa calcula el factorial de 5*/

int i=1,x=1;

while(i<=5)
  {
  
   x=x*i;
   i=i+1;
  }
printf("     El factorial de 5 es --> ");
printf("%d",x);
printf(" \n Porque 1*2*3*4*5 da este valor");

}

