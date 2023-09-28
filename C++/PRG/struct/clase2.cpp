#include <iostream.h>
#include <conio.h>


class tiempo{      //este programa genera error no puede accesar los miembros de la clase
        private:
	int hora;
	int minuto;
	int segundo;
	};

     main()
	 {
	 clrscr();
	 tiempo x;
	 x.hora=2;
	 x.minuto=20;
	 x.segundo=30;

	 cout<<x.hora<<x.minuto<<x.segundo;
	 return 0;
         }




