//ejercicio de constructores y herencia  no. 7
#include<iostream.h>
#include<conio.h>
class A{
	 public:
		 A(){cout<<"constructor A\n";}
	}
class B{
	 public:
		 B(){cout<<"constructor B\n";}
	}
class C{
	 public:
		 C(){cout<<"constructor C\n";}
       }
class D:A{//clase derivada
	  public:
		 B c;//es un objeto miembro
		 C c1;//es un objeto miembro
		 D(){cout<<"constructor D\n";}
	  }
void main()
{
  clrscr();
  D d;
}