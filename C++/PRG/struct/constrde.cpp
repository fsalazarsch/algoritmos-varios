// ejercicio de constructores no. 6
#include<iostream.h>
#include<conio.h>
class A{
	 public:
		A(){cout<<"constructor A\n";}
		};
		class B{
	 public:
		B(){cout<<"constructor B\n";}
		}
		class C{
	 public:
		C(){cout<<"constructor C\n";}
		};
		class D{
	 public:
		A a;//es un objeto miembro
		B b;//es un objeto miembro
		C c;//es un objeto miembro
		D(){cout<<"constructor D\n";}
		}
		void main()
		{
		  clscr();
		  D d;
         }
                