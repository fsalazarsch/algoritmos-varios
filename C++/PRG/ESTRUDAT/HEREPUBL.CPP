#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class base{
int x,y;
public:
base(int i=0,int j=0):x(i),y(j){}
int f() {return x+y;}
void g() {x++,y++;}
};
class derivada:public base
{ int z;
public:
derivada(int j,int k):base(j,k){}
};
void main()
{
clrscr();
derivada a (5,5);
a.g();
cout<< a.f()<<endl;
getch();
}
