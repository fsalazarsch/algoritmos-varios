//ejercicio de constructores y destructores en clases derivadas de herencia no.10
#include<iostream.h>
#include<conio.h>
class base{
	   public:
		  base(){
			  cout<<"base est� creada\n";}
		  ~base(){
			   cout<<"base est� destruida\n";}
			  };
class clase_d1:
          public base{
 	              public:
		             clase_d1(){
			     cout<<"clase_d1 creada\n";}
		      }
class clase_d2:
         public clase_d1
	 {
	    public:
	           clase_d2(){cout<<"clase_d2 creada\n";}
		   ~clase_d2(){cout<<"clase_d2 destru�da\n";}
	 }
main()
{
  clrscr();
  clase_d1 d1;
  clase_d2 d2;
  cout<<"\n";
  getch();
  return(0);
}

