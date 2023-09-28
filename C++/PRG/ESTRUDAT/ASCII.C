#include <stdio.h>

int i=0,k=1;

void main()
{
  clrscr();
  for(i=1; i<=255; i++)   
  {
    printf("%d  %c \n",i,i);
   k++;
   if (k==20)
   {
     getch();
     clrscr();
     k=1;
   }
  }
  getch();
}
