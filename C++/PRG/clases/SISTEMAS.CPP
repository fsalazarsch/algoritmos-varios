#include <iostream.h>
#include <conio.h>
class a{
int y;
public:
a(){};
void f(int i)
     {y=i;}
int g()
    {return y;}

};

main()
{
clrscr();
a x;
x.f(3);
cout<< x.g()<<endl;
getch();
}