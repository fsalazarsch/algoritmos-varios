#include <stdio.h>
#include <conio.h>


void main()
{
   int x,n; x = 0; con = 0;
   clrscr();
   printf("Digite un numero");
   scanf("%d",&n);
   x=n;
   while(x!=0)
    {
     //n=x;con=0;
     while(n!=0)
      {
	if (x%n==0)
       con=con+1;
	n--;
      }
	if((con==2)||(con==1))
	printf("%d Es primo :\n:",x);
       else
	printf("%d No primo :\n:",x);
	x--;
	delay(500);


      printf("%d\n",x);
      x--;
    }
    getch();
}
