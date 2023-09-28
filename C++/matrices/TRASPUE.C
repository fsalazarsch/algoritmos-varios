#include <stdio.h>
#include <conio.h>
int j,n,i;
int a[50][50];
void main()
{
   clrscr();
   printf("digite el orden de la matriz n*n:");
   scanf("%d",&n);
   clrscr();
   printf("digite los valores de la matriz\n");
   printf("\n");
   for (i=0; i<n;i++)
   {
       for(j=0; j<n; j++)
       {
	   gotoxy(j*6,wherey()-1);
	   scanf("%d",&a[i][j]);
       }
       printf("\n");
   }
   clrscr();
   printf("matriz transpuesta\n");
   printf("\n");
   printf("\n");
   for (j=0; j<n;j++)
   {
       for(i=0; i<n; i++)
       {

	   printf("%d\t",a[i][j]);
       }
       printf("\n");
   }
   getche();
}








