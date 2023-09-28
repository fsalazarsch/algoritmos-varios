#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

class comparar{
       private:
       char cad1[10];
       char cad2[10];

       public:
         void vector();
       };

       void comparar::vector()
       {

	clrscr();
  
	gotoxy(25,10);cout <<"CADENA1.....[                      ]";
	gotoxy(42,10);cin >>cad1;
 
	gotoxy(25,12);cout <<"CADENA2..... [                     ]";
	gotoxy(42.,12);cin >>cad2;
  
 	 if (strcmp(cad1,cad2)==0)
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
