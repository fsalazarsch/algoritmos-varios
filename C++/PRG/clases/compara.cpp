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
  
	gotoxy(25,10);cout <<"DIGITE CADENA1.....[                      ]";
	gotoxy(45,10);cin >>cad1;
 
	gotoxy(25,12);cout <<"DIGITE CADENA2..... [                     ]";
	gotoxy(47,12);cin >>cad2;
  
 	 if (strcmp(cad1,cad2)==0)
 	 {
   
	   gotoxy(35,15);cout<<"LOS VECTORES SON IGUALES";
   	   }
	else
        {
	  gotoxy(35,15);cout<<"LOS VECTORES NO SON IGUALES";
 	  }

     }

        main()
       {
       comparar compara;
       compara.vector();
       } 
