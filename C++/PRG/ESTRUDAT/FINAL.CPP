#include "iostream.h"
#include "conio.h"

class gle {
	int *p;
public:
	gle(int i) { p = new int [i]; } //CONSTRUCTOR
	int P(int i) { return p [i]; }
	~gle() { delete p; }            //DESTRUCTOR
	void F(int i, int j) { p[i] = j; }
};

main() {  clrscr();
	
	gle x(5);
	{
	 gle y(10);
	 for (int i=0; i<2; i++)
	       y.F(i,1);
	 for (i=0; i < 2; i++)
	  gotoxy(10,10);cout << y.P(i) << endl;
	}
	      // Llamada a desctructor para el objeto y
	for (int i=0; i < 2; i++)
		x.F(i,2);
	for (i=0; i < 2; i++)
	  gotoxy(10,30);cout << x.P(i) << endl;
	     // Llamda al destructor para el objeto x
           getche();
}
