#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<dos.h>
 int i,j,o,p,m[50][50];
  long aux;
  
  void main()
  {
  textcolor(14);
  textbackground(3);
  clrscr();
  
  cout<<"DIGITE NUMERO DE COLUMNAS::>  ";
  cin>>o;
   cout<<"DIGITE NUMERO DE FILAS::>";
   cin>>p;
   for(i=1;i<=p;i++){
   for(j=1;j<=o;j++){
   gotoxy(j*4+3,i+5); 
   cin>>m[i][j];
  
      }
      }

 for(i=1;i<=p;i++){
   for(j=1;j<=o;j++){
   aux=m[i][j];
   m[i][j]=m[j][i];
   m[j][i]=aux;
   }
   }
   for(i=1;i<=p;i++){
   for(j=1;j<=o;j++){
   gotoxy(j*4+3,i+15);
   cout<<m[j][i];
	   cout<<"\n";
	   }
	   }
	    for(i=1;i<=p;i++){
	    sound((i*652)/2);
	    delay(300);
		     }
	     nosound();
	   getch();
	   }
