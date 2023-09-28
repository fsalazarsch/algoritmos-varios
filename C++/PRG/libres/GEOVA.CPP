#include "stdio.h"
#include "conio.h"
void fx(int x);
void fy(int y);
void main()
{clrscr();
int a=10;
fx(a);
fy(a);
printf("Despues del procedimiento\n A=%d\n",a);
getch();
}
void fx(int x)
{ int a=5;
/*  a=a+x;*/
  a+=x;
  printf("En el 1er procedimiento\n a=%d\n",a);
}

void fy(int y)
{ int a=8;
/*  a=a+y;*/
    a+=y;
  printf("En el 2do procedimiento\n a=%d\n",a);
}

