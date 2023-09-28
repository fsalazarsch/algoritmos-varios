# include <iostream.h>
# include <conio.h>
#include<ctype.h>
#include<stdio.h>

class empleado
     {
     char nombre[50];
     long ced;
     int edad;
     public:
     void leer_datos();
     void escribir_datos();

};
      void empleado::leer_datos()
       {
       gotoxy(20,10);cout<<"Digite el nombre : ";gets(nombre);
       gotoxy(20,11);cout<<"Digite la cedula : ";cin>>ced;
       gotoxy(20,12);cout<<"Digite la edad   : ";cin>>edad;
	}

       void empleado::escribir_datos()
	{
	gotoxy(20,10);cout<<"El nombre es : "<<nombre;
	gotoxy(20,11);cout<<"La cedula es : "<<ced;
	gotoxy(20,12);cout<<"La edad es   : "<<edad;
	}

class administrativo : public empleado
     {
     char categoria[50];
     char destino[50];
     public:
     void leer_datos();void escribir_datos();
};
      void administrativo::leer_datos()
       {
       empleado::leer_datos(); //encapsulamiento
       gotoxy(20,13);cout<<"Digite la categoria : ";gets(categoria);
       gotoxy(20,14);cout<<"Digite el destino   : ";gets(destino);
       }

     void administrativo::escribir_datos()
       {
	 empleado::escribir_datos(); //encapsulamiento
	 gotoxy(20,13);cout<<"La categoria es : "<<categoria;
	 gotoxy(20,14);cout<<"El destino es   : "<<destino;
       }

main()
{
clrscr();
administrativo uno;
uno.leer_datos();
clrscr();
uno.escribir_datos();
getch();
}
