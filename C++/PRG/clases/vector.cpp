#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

class vector{
    private:
    int vect[10],i;
    public:                    	     
    void cargar();
    };
    void vector::cargar()
    { 
       for(i=0;i<10;i++)
       {
          gotoxy(20,10);cout<<"DIGITE EL VECTOR :";
	  gotoxy(38,i+10);
	  cin>>vect[i];
	}
    }
main()
{
vector sol;
sol.cargar();
}


					  