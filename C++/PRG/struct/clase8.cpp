#include "iostream.h"
#include "conio.h"

#define limpiar clrscr();
#define pos gotoxy
                           //clase8.cpp sumatoria de una matriz
class matriz
{
  private:
         int m[10][10];
         int i,j,c,f;
         int sum;
	 int vec1[10],vec2[10];

  public:
        void captura();

 };

 void matriz::captura()
 {
      limpiar
      pos(35,8);cout<<"Captura matriz ";
      f=10;
      for (i=1; i<=3; i++)
      {
       c=33;
        for (j=1; j<=3; j++)
        {
	 pos(c,f);cin >>m[i][j];
         c+=8;
         }
    f+=2;
   }


      sum=0;
      for (i=1; i<=3; i++)
      {

        for (j=1; j<=3; j++)
        {
	  sum=sum+m[i][j];
        
         }
    
   }

    gotoxy(33,17);cout <<"Sumatoria:...";
    gotoxy(50,17);cout <<sum;

   }



 void main()
 {
      matriz mat;
      mat.captura();
   };