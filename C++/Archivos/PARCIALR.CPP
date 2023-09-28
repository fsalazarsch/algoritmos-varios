#include"fstream.h"
#include"conio.h"
#include"ctype.h"
#include"stdio.h"
	
class alumno
	{
   char nombre[30];
   float nota1;
   float nota2;
   float nota3;
public:
   void leer();
   void escribir();
};

void alumno::leer()
{
  gotoxy(19,11);gets(nombre);
  gotoxy(19,12);cin>>nota1;
  gotoxy(19,13);cin>>nota2;
  gotoxy(19,14);cin>>nota3;
 }

void alumno::escribir()
{
  gotoxy(19,11);cout<<nombre;
  gotoxy(19,12);cout<<nota1;
  gotoxy(19,13);cout<<nota2;
  gotoxy(19,14);cout<<nota3;
  gotoxy(5,16); cout<<"Presione una tecla para continuar ...";
  getch();
 }


class estudiante:public alumno
{
};
void main()
{
 estudiante a1;
/*
  **************        LEER         *********************** 
*/

 char OPCION = 'S';
 ofstream DAT("A:\DATOS.DAT");
 while(OPCION=='S')
 {
  clrscr();
  gotoxy(5,6);cout<<"SISTEMA INTEGRADO DE INFORMACION";
  gotoxy(5,8);cout<<"    CAPTURA DATOS BASICOS";
  gotoxy(9,11);cout<<"NOMBRES [                              ]";
  gotoxy(9,12);cout<<"NOTA 1  [    ]";
  gotoxy(9,13);cout<<"NOTA 2  [    ]";
  gotoxy(9,14);cout<<"NOTA 3  [    ]";
  a1.leer();
  DAT.write((char *)&a1,sizeof(a1));    //ALMACENAR ARCHIVO
  gotoxy(8,16);cout<<"DESEA CONTINUAR S/N: [ ] ";
  do {
     gotoxy(30,16); OPCION=getch();
     OPCION=toupper(OPCION);
   } while(( OPCION!='S')&&(OPCION!='N'));
  }
 DAT.close();
/*
 //      ESCRIBIR
 //
 */

 ifstream DATOS("A:\DATOS.DAT");
 while(! DATOS.eof())
 {
  clrscr();
  gotoxy(5,6);cout<<"SISTEMA INTEGRADO DE INFORMACION";
  gotoxy(5,8);cout<<"            LEYENDO ...";
  gotoxy(9,11);cout<<"NOMBRES [                              ]";
  gotoxy(9,12);cout<<"NOTA 1  [    ]";
  gotoxy(9,13);cout<<"NOTA 2  [    ]";
  gotoxy(9,14);cout<<"NOTA 3  [    ]";
  DATOS.read((char *)&a1,sizeof(a1));    //ALMACENAR ARCHIVO
  a1.escribir();
  }
 DATOS.close();

}


