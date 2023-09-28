#include "iostream.h"
#include "conio.h"
#include "stdlib.h"

#define pos gotoxy

class figura{
       private:
       int col,i;
       int vec[5];

       public:
         void triangulo();
       };

       void figura::triangulo()
       {

	gotoxy(30,6);cout<<"Figura  ==> Triangulo";
        col=40;
	for(i=1; i<=6; i++)
	{
	  pos(col,8+i);cout <<"";
          col--;
	 }

        col=40;
        for(i=1; i<=6; i++)
	{
	 pos(col,8+i);cout <<"";
         col++;
	}

        col=35;
	for(i=1; i<=10; i++)
	{
	  pos(col,14);cout <<"";
          col++;
        }

      }

       void main()
       {
       figura fig;
       fig.triangulo();
       } 
