#include <iostream.h>
#include <conio.h>
class abc{
	 private: //si usted quiere escribir
	 char a;
	 int  b;
	 float c;
	 public:
	 void inicializa (void){
	 a='x';
	 b=200;
	 c=12.5;
	 }
	 void escribir(void){
       cout<<"a es" <<a<<"\n";
       cout<<"b es" <<b<<"\n";
       cout<<"c es" <<c<<"\n";
}
};
       main()
       {
       clrscr();
       abc var;
       var.inicializa();
       var.escribir( );
       return (0);
       }













































































