#include "iostream.h"
#include "conio.h"

 class X{
	 int a,b;
	 char c,d;
	 int f(int i){return i;}

      public:
		  
	  void leer ()
	    {
	      clrscr();
	      cout <<"Digite el valor de A : "; cin>>a;
	      cout <<"Digite el valor de B : "; cin>>b;
	      cout <<"Digite el valor de C : "; cin>>c;
	      cout <<"Digite el valor de D : "; cin>>d;
	     }

	    void escriba ()
	     {
		clrscr();
		cout <<"El Resultado Es :";
		cout <<f(a+b) << f(c+d);
	      }
	   };

 void main()
  {
    X A;
    A.leer();
    A.escriba();
    getch();
   }
	