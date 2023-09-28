#include <iostream.h>
#include <string.h>
#include <conio.h>
                                                          
class personal{
      char nombre [40];  
      char direccion[25];
      char ciudad[30];
      char estado[1];
      char telefono[10];
public:
      void store (char *n, char *s, char *c, char *t, char *z);
      void display();
                     };
      void personal:: store(char *n, char *s, char *c, char *t, char *z)
      {
        cout <<strcpy(nombre,n);
	cout <<strcpy(direccion,s);
        cout <<strcpy(ciudad,c);
        cout <<strcpy(estado,t);
        cout <<strcpy(telefono,z);
       }
     void personal::display()
     {
       gotoxy(15,4);cout <<"     CAPTURA DE DATOS \n";
       gotoxy(10,8);cout << "NOMBRE   : ";
       cin>>   nombre;
       gotoxy(10,10);cout <<"DIRECCION: ";
       cin>>   direccion;                                     
       gotoxy(10,12);cout <<"CIUDAD   : ";
       cin>>   ciudad;
       gotoxy(10,14);cout <<"ESTADO   : ";
       cin>>   estado;
       gotoxy(10,16);cout <<"TELEFONO : ";
       cin>>   telefono;
      }
     main()
     {
       personal a;
       a.display();
       return 0;
     }



