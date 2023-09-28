#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

class comparar{
       private:
       int vec1[10];
       int vec2[10];

       public:
         void vector();
       };

       void comparar::vector()
       {

	clrscr();
  
	gotoxy(25,10);cout <<"VECTOR No.1 ===> [                      ]";
	gotoxy(42,10);cin >>vec1;
 
	gotoxy(25,12);cout <<"VECTOR No.2 ===> [                     ]";
	gotoxy(42,12);cin >>vec2;
  
 	 if (vec1==vec2)
 	 {
   
	   gotoxy(35,15);cout<<"SON IGUALES";
   	   }
  	else
        {
	  gotoxy(35,15);cout<<"NO SON IGUALES";
 	  }

     }

        main()
       {
       comparar compara;
       compara.vector();
       } 
