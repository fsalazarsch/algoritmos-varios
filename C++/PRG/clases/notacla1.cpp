//Calcula el promedio de tres notas
//notacla1.cpp
#include<iostream.h>
#include<conio.h>

class colegio{
	      private: 
	      char nom [25];
	      float nota1;
	      float nota2;
	      float nota3;
	      float prome;
              float suma;
              public:
	      void captura();
             };

 void colegio::captura ()
              {
               clrscr();
               gotoxy(10,5);cout<<"** ESTE PROGRAMA TE CALCULA EL PROMEDIO DE TRES NOTAS **"<<endl;
               gotoxy(10,10);cout<<" Digite el Nombre del Alumno -> "<<endl;
               gotoxy(42,10);cin>>nom;
	       gotoxy(10,12);cout<<" Digite la Primera Nota ------> "<<endl;
               gotoxy(42,12);cin>>nota1;
	       gotoxy(10,14);cout<<" Digite la Segunda Nota ------> "<<endl;
               gotoxy(42,14);cin>>nota2;
	       gotoxy(10,16);cout<<" Digite la Tercer Nota -------> "<<endl;
	       gotoxy(42,16);cin>>nota3;
	       suma=nota1+nota2+nota3;
	       prome=suma/3;
               cout.precision(2);
	       gotoxy(10,18);cout<<"EL PROMEDIO DE ESTE ALUMNO ES--> "<<prome<<"\n";
	      }

 void main()
           {
            clrscr();
            colegio col;
            col.captura();
           }
