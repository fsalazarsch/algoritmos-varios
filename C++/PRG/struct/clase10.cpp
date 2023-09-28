#include "iostream.h"
#include "conio.h"
#include "stdlib.h"


class califica{

       private:
       int i,f;
       float nota[5];
       float acum;
       float prom;

       public:
         void notas();
       };

       void califica::notas()
       {
          
	  gotoxy(30,7);cout << "CAPTURA 3 NOTAS";
	  
	  f=10; 
	  for(i=1;i<=3;i++)
	  {
	   gotoxy(30,10);cout << "NOTA [1]...";
	   gotoxy(30,11);cout << "NOTA [2]...";
	   gotoxy(30,12);cout << "NOTA [3]...";
           gotoxy(42,f);cin >>nota[i];
	  f++;
	 }

	for(i=1;i<=3;i++)
	  {
	   acum=acum+nota[i];
	   prom=acum/3;

	 }
	 gotoxy(30,15);cout<<"Promedio:...";
         gotoxy(43,15);cout << prom;
      }

        main()
       {
       califica cali;
       cali.notas();
       } 
