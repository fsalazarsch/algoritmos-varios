#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

 

class abc{
         private:  //si usted quiere la escribe
	 char a;
	 int b;
	 float c;

	 public:
	 void inicializa(void){
	      a=(rand()%27)+65; //tabla ascii
	      b=rand()%100;
	      c=float(rand()*.25);
	      }

	      void escribir(void){
		   gotoxy(24,7);cout <<"UNIVERSIDAD ANTONIO NARIÑO"<<"\n";
		   gotoxy(30,8);cout <<"OSCAR PEREZ"<<"\n";
                   gotoxy(30,10);cout <<"a es... " <<a <<"\n";
	           gotoxy(30,11);cout <<"b es... " <<b <<"\n";
		   gotoxy(30,12);cout <<"c es... " <<c <<"\n";
                   getch();
		    //cout <<"a es... " <<a <<"\n";
	            //cout <<"b es... " <<b <<"\n";
		    //cout <<"c es... " <<c <<"\n";
	      }
	    };
	  main()
	       {
		clrscr();
		abc var1,var2;
		var1.inicializa();
		var1.escribir();
		var2.inicializa();
		var2.escribir();

		return (0);
		}