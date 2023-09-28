#include "iostream.h"
#include "conio.h"

#define limpiar clrscr();
#define pos gotoxy

class factorial
{
  private:
         int lim;
         int i;
         int long fac;

  public:
        void captura();

 };

 void factorial::captura()
 {
      limpiar
      pos(10,10);cout <<"Captura numero a hallar factorial  " <<" ";
      cin >>lim;

      fac=1;
      for (i=1; i<=lim; i++)
      {
           fac*=i;
	   pos(20,12);cout << "Factorial ==> " <<fac;
           
        }
   }


 void main()
 {
      factorial factor;
      factor.captura();
   };      