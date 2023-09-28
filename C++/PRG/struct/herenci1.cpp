#include "iostream.h"
#include "conio.h"

class base{

           public:
	   base(void){
		      cout << "base \n";
                      }
		    };

class derivada: public base{
	        public:
		derivada(void){
			      cout << "heredada \n";
                              }
		          };

main()
{
  clrscr();
  derivada x ;
  getch();
  return(0);
  }
