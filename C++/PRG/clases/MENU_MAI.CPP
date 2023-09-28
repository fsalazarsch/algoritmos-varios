# include <iostream.h>
# include <conio.h>
# include <dos.h>
# include <string.h>
# include <iomanip.h>
# include  <ctype.h>

class  salir
{
 float sal;
 long tle_f;
 char nom[20];
 public:
 salir(void);//constructor
 void captura();
// void menu();
 void imprimir();
 ~salir(void);//destructor
};

salir::salir(void)
{
/* char *noname="noma";
 strcpy(nom,noname);*/
 char nom[30];
 tle_f=000;
 sal=000;
}

void salir::captura()
{
 clrscr();
 gotoxy(14,2);cout<<"  FUNCION QUE ME PERMITE CAPTURAR UN DATO  ";
 gotoxy(14,6);cout<<"     DIGITE SU NOMBRE POR FAVOR : ";cin>>nom;
 gotoxy(14,8);cout<<"     AHORA SU NUMERO TELEFONICO : ";cin>>tle_f;
 gotoxy(14,10);cout<<"    DISCULPE POR FAVOR DIGITE SU SALARIO : ";cin>>sal;
}

void salir::imprimir()
{
 clrscr();
 gotoxy(14,2);cout<<" RESULTADO DE LA CAPTURA DE DATOS ";
 gotoxy(14,4);cout<<"             IMPRESION            ";
 gotoxy(14,6);cout<<"    ESTE ES SU NOMBRE: ";cout<<nom;
 gotoxy(14,8);cout<<"    ESTE ES SU TELEFONO: ";cout<<tle_f;
 gotoxy(14,10);cout<<"   ESTE ES SU SALARIO: ";cout<<sal;
 getch();
}

salir::~salir(void)
{
 tle_f=000;
 sal=000;
}

/*void menu()
{
 char op;
 clrscr();
 gotoxy(10,10);cout<<"================================";
 gotoxy(10,12);cout<<"        MENU PRINCIPAL          ";
 gotoxy(10,14);cout<<"                                ";
 gotoxy(10,16);cout<<"        1. Captura              ";
 gotoxy(10,18);cout<<"        2. Imprimir             ";
 gotoxy(10,20);cout<<"================================";
 gotoxy(10,21);cout<<"          Opcion  [ ]           ";
 gotoxy(10,22);cout<<"================================";
 gotoxy(10,42);op=toupper(op);
} */
main()
{
 clrscr();
 salir  empleado;
// menu();
 empleado.captura();
 empleado.imprimir();
}