#include <iostream.h>
#include <conio.h>
#include <stdio.h>   
#include <string.h>

class familia{        
	       char padre[30];
	       char madre[30];
	       char hijo[30];
	       char hija[30];

            public:
	       void captura ();
	       };

	       void familia::captura()
	       {
               gotoxy(20,7);cout<<"ESTE PROGRAMA CAPTURA LA FAMILIA MOSQUITO";

	       gotoxy(25,10);cout<<"Nombre del padre  :";
	       gotoxy(25,11);cout<<"Nombre de la Madre:";
	       gotoxy(25,12);cout<<"Nombre del Hijo   :";  
	       gotoxy(25,13);cout<<"Nombre de la Hija :";
               gotoxy(45,10);cin>>padre;
	       gotoxy(45,11);cin>>madre;
               gotoxy(45,12);cin>>hijo;
	       gotoxy(45,13);cin>>hija;
               
               gotoxy(45,16);cout<<"pulse Alt f4 para terminar";
               getch();
	       }

main()
{
  familia adalgiza;
  adalgiza.captura();
  return(0);
}                	       