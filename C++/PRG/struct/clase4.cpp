#include <iostream.h>
#include <conio.h>

     //carga char int float

class abc{
         private:  //si usted quiere la escribe
	 char a;
	 int b;
	 float c;

	 public:
	 void inicializa(void){
	      a='X';
	      b=200;
	      c=12,5;
	      }

	      void escribir(void){
	      cout <<"a es" <<a <<"\n";
	      cout <<"b es" <<b <<"\n";
	      cout <<"c es" <<c <<"\n";

	      }
	    };
	  main()
	       {
		clrscr();
		abc var;
		var.inicializa();
		var.escribir();
		return (0);
		}