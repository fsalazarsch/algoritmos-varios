#include <iostream.h>
#include<conio.h>
class base{
public:
base(void){
	   cout<<"base creada\n";}
	   };
    class d_base: public base{
	      public:
		     d_base(void){
				  cout<<"se ha creado la clase d_base\n";}
				  };
				  main()
				  { clrscr();
				      d_base x;
				      getch();
				      return(0);
				      } 