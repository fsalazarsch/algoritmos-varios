/******************************************************************
 * ESTE PROGRAMA PERMITE CREAR UN ARCHIVO EN UN DISCO DE ALMACE-  *
 * NAMIENTO AUXILIAR, EL ARCHIVO SE LLAMARA "DATOS.DAT"  Y  SE    *
 * ALMACENARA EN LA RAIZ DE UN DISKETTE DE LA UNIDAD A.           *
 ******************************************************************/
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
   char OPCION='S';
   ofstream DATOS("A:\DATOS.DAT");
   while(OPCION=='S')
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
      gotoxy(38,10);cin>>EMPLEADO.CEDULA;
      gotoxy(38,11);gets(EMPLEADO.NOMBRES);
      gotoxy(38,12);cin>>EMPLEADO.TEL;
      gotoxy(38,13);gets(EMPLEADO.DIRECCION);
      DATOS.write((char *)&EMPLEADO,sizeof(ARCHIVO));    //ALMACENAR ARCHIVO
      gotoxy(26,22);cout<<"DESEA CONTINUAR S/N: [  ] ";
      do {
	 gotoxy(49,22); OPCION=getch();
	 OPCION=toupper(OPCION);
	 } while(( OPCION!='S')&&(OPCION!='N'));
      }
      DATOS.close();
    }
