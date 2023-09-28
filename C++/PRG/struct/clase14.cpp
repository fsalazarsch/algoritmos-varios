#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"


#define pos gotoxy

class figura{
       private:
       int col,i;
       int vec[5];

       public:
	 void hor();
	 void ver();

       };

       void figura::hor()
       {
         gotoxy(30,6);cout<<"Figura  ==> Triangulo";
	 

       for(i=1; i<=10; i++)
       {
	  pos(30,8+i);cout <<"";
	  
	 }
        

       for(i=1; i<=10; i++)
       {
	 pos(50,8+i);cout <<"";
        
	}

	
	for(i=1; i<=10; i++)
	{
	  pos(40+i,8);cout <<"";
	  
	}

	for(i=1; i<=10; i++)
	{
	  pos(50+i,8);cout <<"";
	  
	}
      }

       void main()
       {
        figura fig;
        fig.hor();
       } 
