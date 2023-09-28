#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

class NUEVA{
	    private:
	    int A,B,sum;
	    public:
	    NUEVA(){sum=A=B=0;cout<<"Constructor";}
	    ~NUEVA(){cout<<"destructor";}
	   };

NUEVA::NUEVA()
{
 sum=A+B;
 cout<<"LA SUMA ES:"<<sum;
 //return sum;
 }

 NUEVA::~NUEVA()
 {
  cout<<"DESTRUYE";
 }

 Void main()
 {
  NUEVA OBJ(10);
  //OBJ.NUEVA();
 }



	      