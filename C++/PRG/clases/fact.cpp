#include <iostream.h>
#include <conio.h>

class factorial{

	     
	      int a;
	      int i;
              int long fac,fac1;
   public:

   void captura();
   };

   void factorial::captura()
  {
    gotoxy(5,5);cout<<" DIGITE  LIMITE: \t"<<" ";
    cin>>a;

    fac=1;
    for (i=1;i<=a;i++)
    {
      
      //fac1=fac;
      gotoxy(5,12);cout << "FACTORIAL =====>:"<<fac<<"*"<<i <<"="<<fac*i;
      getch();                     
      fac=fac*i;
      gotoxy(5,14);cout << "PULSE CUALQUIER TECLA PARA MOSTRAR SECUENCIALMENTE EL FACTORIAL !! ";
      
     } 
      
   }   
  void main()
  {
    clrscr();
    factorial fact;
    fact.captura();

  }

