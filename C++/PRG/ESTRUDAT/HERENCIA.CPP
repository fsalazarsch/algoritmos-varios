#include "iostream.h"
#include "conio.h"

class A{
public:
A(){cout<<"CONSTRUCTOR DE A";}
~A(){cout<<"DESTRUCTOR DE A";}
};
class B: public A{
public:
B(){cout<<"CONSTRUCTOR DE B";}
~B(){cout<<"DESTRUCTOR DE B";}
};
void main()
{
//clrscr();
B a;
getch();
}




