//********************ARCHIVOS****************************** *

/****************************************************************** *
 * ESTE PROGRAMA PERMITE CONSULTAR UN ARCHIVO EXISTENTE EN UN DISCO *
 * DE ALMACENAMIENTO AUXILIAR, EL ARCHIVO SE LLAMA "DATOS.DAT" Y SE * 
 * ALMACENARA EN LA RAIZ DE UN DISKETTE DE LA UNIDAD A.             *
 ********************************************************************/
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<fstream.h>
main()
   {
   struct ARCHIVO {
       long CEDULA;
       char NOMBRES[30];
       long TEL;
       char DIRECCION[30];
       } EMPLEADO; 
      ifstream DATOS("A:\DATOS.DAT");
      while(! DATOS.eof())
	{
	textcolor(YELLOW);
	textbackground(MAGENTA);
	clrscr();
	gotoxy(33,5);cout<<"CUEROLANDIA LTDA";
      gotoxy(25,6);cout<<"SISTEMA INTEGRADO DE INFORMACION";
      gotoxy(30,7);cout<<"CAPTURA DATOS BASICOS";
      gotoxy(13,10);cout<<"CEDULA.................[       ]";
      gotoxy(13,11);cout<<"NOMBRES Y APELLIDOS....[                              ]";
      gotoxy(13,12);cout<<"TELEFONO...............[        ]";
      gotoxy(13,13);cout<<"DIRECCION..............[                              ]";
      DATOS.read((char *) &EMPLEADO,sizeof(ARCHIVO));    //PERMITE LEER UN REGISTRO
      gotoxy(38,10);cout<<EMPLEADO.CEDULA;
      gotoxy(38,11);cout<<EMPLEADO.NOMBRES;
      gotoxy(38,12);cout<<EMPLEADO.TEL;
      gotoxy(38,13);cout<<EMPLEADO.DIRECCION;
      gotoxy(24,22);cout<<"PRESIONE CUAQUIER TECLA PARA SALIR";getch();
      }
      DATOS.close();
    }
 
