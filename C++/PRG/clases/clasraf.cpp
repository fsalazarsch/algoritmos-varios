#include <iostream.h>
#include <conio.h>

class cuadrado{
private:
int i;
public:

void rayas();
void vertical();
void rayas1();
void vertical1();
void subegor();
};
	 void cuadrado::rayas ()
	 {
	    for(i=0;i<20;i++)
	      {
		 gotoxy(i+5,5);cout<<"*";
               }
	 }
	 void cuadrado::rayas1()
	 {
	  for (i=0;i<10;i++)
        	{
		  gotoxy(24,i+5);
		  cout<<"*";
		}
  	 }
	  void cuadrado::vertical()
	  {
	    for(i=0;i<10;i++)
	      {
		 gotoxy(5,i+5);
		 cout<<"*";
	      }
	  }
	 void cuadrado::vertical1()
        {
	  for(i=0;i<20;i++)
	  {
	     gotoxy(i+5,15);
	     cout<<"*";
	  }
	}
	 void cuadrado::subegor()
	{
	 gotoxy(8,9);cout<<"RAFAEL SEGUNDO";
	 gotoxy(12,10);cout<<"VILLERO";
	}

 main()
 {
	 cuadrado raf;
	 raf.vertical();
	 raf.rayas1();
	 raf.subegor();
	 raf.rayas();
	 raf.vertical1();
	 return(0);
}
