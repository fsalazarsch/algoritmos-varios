#include<iostream.h>
#include <conio.h>

class B;
class A{
int x,y;
public:
A (int j,int k){x=j;y=k;}
friend int igual(A obj,B obj1);
};
class B{
int m,n;
public:
B(){m=5;n=10;}
friend int igual (A obj,B obj1);
};
int igual(A obj,B obj1){
if(obj.x*obj.y == obj1.m || obj.x*obj.y == obj1.n)
return 1;
else return 0;
}
void main()
{
clrscr();
A uno(50,15); B dos;
if(igual(uno,dos))
cout<<"SON IGUALES";
else
cout<<"SON  DIFERENTES";
getch();
}
