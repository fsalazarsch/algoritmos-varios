#include<iostream.h>
#include<conio.h>

//constructores y destructores en clases derivadas
//construc

class base{
	   public:
	   base(){
		  cout<<"base está creada\n";}
	  };


class clase_d1:public base{
		           public:
			   clase_d1(){
			   cout<<"deriva creada\n";}
			   };

main()
{
 clrscr();
 clase_d1 d1;
 getch();
 return(0);
}


