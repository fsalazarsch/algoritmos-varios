#include "iostream.h"
#include "conio.h"
#include "stdlib.h"


#define pos gotoxy


class potencia{
       private:
       int i;
       int a,n;
       int res;

       public:
         void multiplica();
       };

       void potencia::multiplica()
       {
	pos(35,12);cout <<"Captura A";
	pos(45,12);cin  >>a;
	pos(35,13);cout <<"Captura N";
	pos(45,13);cin  >>n;

        res=1;
	for (i=1; i<=n; i++)
	{

         res*=a;
	}
	gotoxy(32,15);cout <<"Resultado...";
	gotoxy(50,15);cout <<res;

      }

       void main()
       {
       potencia poten;
       poten.multiplica();
       getch();
       }
