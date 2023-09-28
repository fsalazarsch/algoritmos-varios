#include <iostream.h>
#include <conio.h>
class A{
public:
A(){cout<<"CONSTRUCTOR BASE"<<endl;}
~A(){cout<<"DESTRUCTOR BASE"<<endl;}
};
class B:public A{
public:
B(){cout<<"CONSTRUCTOR DE B"<<endl;}
~B(){cout<<"DESTRUCTOR DE B"<<endl;}
};
class C:public A{
public:
C(){cout<<"CONSTRUCTOR DE C"<<endl;}
~C(){cout<<"DESTRUCTOR DE C"<<endl;}
};
void main()
{
B a;
C b;
getch();
}

