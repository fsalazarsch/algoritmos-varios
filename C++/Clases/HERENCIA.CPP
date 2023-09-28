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
     void leer_emple();
     void escribir_emple();
};

void empleado::leer_emple()
{
gotoxy(20,10);cout<<"Digite el nombre : ";gets(nombre);
gotoxy(20,11);cout<<"Digite la cedula : ";cin>>ced;
gotoxy(20,12);cout<<"Digite la edad   : ";cin>>edad;
}

void empleado::escribir_emple()
{
gotoxy(20,8);cout<<"LOS DATOS LEIDOS SON ";
gotoxy(20,10);cout<<"El nombre es : "<<nombre;
gotoxy(20,11);cout<<"La cedula es : "<<ced;
gotoxy(20,12);cout<<"La edad es   : "<<edad;
}

class administrativo : public empleado
     {
     char categoria[50];
     char destino[50];
     public:
     void leer_admin();
     void escribir_admin();
};

void administrativo::leer_admin()
{
gotoxy(20,13);cout<<"Digite la categoria : ";gets(categoria);
gotoxy(20,14);cout<<"Digite el destino   : ";gets(destino);
}

void administrativo::escribir_admin()
{
gotoxy(20,13);cout<<"La categoria es : "<<categoria;
gotoxy(20,14);cout<<"El destino es   : "<<destino;
}


class vendedores : public empleado
     {
     char titulaciones[50];
     double ventas;
     public:
     void leer_vend();
     void escribir_vend();
};

void vendedores::leer_vend()
{
gotoxy(20,13);cout<<"Digite la titulacion : ";gets(titulaciones);
gotoxy(20,14);cout<<"Digite las ventas    : ";cin>>ventas;
}

void vendedores::escribir_vend()
{
gotoxy(20,13);cout<<"La titulacion es : "<<titulaciones;
gotoxy(20,14);cout<<"Las ventas son   : "<<ventas;
}


main()
{
clrscr();
administrativo uno;
vendedores dos;
int ele;
char op;
op='S';
while (op=='S'){
clrscr();
gotoxy(20,22);cout<<" 1 ->> ADMINISTRATIVO. 2 ->> VENDEDORES. ";
gotoxy(20,5);cout<<"Digite que clase de emleado : ";cin>>ele;
if(ele==1)
{
clrscr();
gotoxy(15,5);cout<<"EMPLEADO ADMINISTRATIVO ";
uno.leer_emple();
uno.leer_admin();
clrscr();
uno.escribir_emple();
uno.escribir_admin();
getch();
}
else
 if(ele==2)
 {
clrscr();
gotoxy(15,5);cout<<"EMPLEADO VENDEDOR ";
dos.leer_emple();
dos.leer_vend();
clrscr();
dos.escribir_emple();
dos.escribir_vend();

 }
do{
    gotoxy(20,22);cout<<"DESEA CONTINUAR -S/N- ";op=getch();
    op=toupper(op);
   }while((op!='S')&&(op!='N'));
  }
}
