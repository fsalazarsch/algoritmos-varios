//*******************ARCHIVOS**************************

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<fstream.h>

void CAPTURA();
void MOSTRAR();
int MENU();
void BORRAR();

struct ARCHIVO{
   long cedula;
   char nombre [30];
   long tel;
   char direccion [30];
   }EMPLEADO;

void main(void)
{
  char op='S';
  int men;
 while(op=='S')
 {
 BORRAR();
 men = MENU();
 switch(men){
  case 1:
   CAPTURA();
   break;
  case 2:
   MOSTRAR();
   break;
  case 3:
   op='N';
  break;
 }
}
}

void CAPTURA()
 {
  char OPCION='S'; 
  ofstream datos("c:\datos.dat",ios::app);
  while (OPCION=='S')
  {
   BORRAR();
   gotoxy(30,7);cout<<"CAPTURA DE DATOS BASICOS";
   gotoxy(13,10);cout<<"Cedula            :[           ]";
   gotoxy(13,11);cout<<"Nombre y apellido :[                             ]";
   gotoxy(13,12);cout<<"Telefono          :[          ]";
   gotoxy(13,13);cout<<"Direccion         :[                             ]";
   gotoxy(33,10);cin>>EMPLEADO.cedula;
   gotoxy(33,11);gets(EMPLEADO.nombre);
   gotoxy(33,12);cin>>EMPLEADO.tel;
   gotoxy(33,13);gets(EMPLEADO.direccion);
   datos.write((char *)&EMPLEADO,sizeof(ARCHIVO));
   gotoxy(26,16);cout<<"DESEA CONTINUAR -S/N- ";
   do{
      OPCION = getch ();
      OPCION = toupper(OPCION);
      }while((OPCION != 'S') && (OPCION != 'N'));
   }
 datos.close();
}
void MOSTRAR()
{
 ifstream datos("c:\datos.dat");
 while(! datos.eof())
  {
   BORRAR();
   gotoxy(33,5);cout<<"CUEROLANDIA LTDA";
   gotoxy(25,6);cout<<"SISTEMA INTEGRADO DE INFORMACION";
   gotoxy(30,7);cout<<"CAPTURA DE DATOS BASICOS";
   gotoxy(13,10);cout<<"Cedula            :[           ]";
   gotoxy(13,11);cout<<"Nombre y apellido :[                             ]";
   gotoxy(13,12);cout<<"Telefono          :[          ]";
   gotoxy(13,13);cout<<"Direccion         :[                             ]";
   datos.read((char *) &EMPLEADO,sizeof(ARCHIVO));
   gotoxy(33,10);cout<<EMPLEADO.cedula;
   gotoxy(33,11);cout<<EMPLEADO.nombre;
   gotoxy(33,12);cout<<EMPLEADO.tel;
   gotoxy(33,13);cout<<EMPLEADO.direccion;
   gotoxy(26,16);cout<<"Pulse cualquier tecla para continuar... ";
   getch();
   }
 datos.close();
}
 
int MENU()
{
 int men;
 gotoxy(28,8);cout<<"1_ CAPTURA DE DATOS";
 gotoxy(28,9);cout<<"2_ MOSTRAR DATOS";
 gotoxy(28,10);cout<<"3_ SALIR DEL PROGRAMA";
 do{
    gotoxy(20,22);cout<<"Seleccione alguna alternativa y presione <ENTER>:[ ]";
    gotoxy(70,22);cin>>men;
   } while  (( men < 1) || (men > 3));
 return men;
}

void BORRAR()
{
   clrscr();
   gotoxy(33,5);cout<<"CUEROLANDIA LTDA";
   gotoxy(25,6);cout<<"SISTEMA INTEGRADO DE INFORMACION";
}























