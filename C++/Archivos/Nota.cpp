//*****************ARCHIVOS**************************


#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<dos.h>
#include<iomanip.h>
#include<time.h>
#include<stdio.h>
#include<math.h>

void titulo(), inicio(), contexto(), detalle(), cierre();
void menu(), cuadro(int c1, int f1, int c2, int f2), captura(), consulta();
struct registro1
{
long codigo;
char nombre[30];
char asignatura[15];
float nota1, nota2, nota3;
}r1;

main()

{
textcolor(15); textbackground(4);
inicio();
textcolor(15); textbackground(2);
menu();
clrscr();
}

void inicio()

{
int m,n;
clrscr();
for(m=0; m<=25; m++)
{
for(n=0; n<=81; n++)
{
gotoxy(n,m); cout<<"°"; delay(1);
}
}
gotoxy(22,9); cout<<"PROGRAMA PRESENTADO POR EL INGENIERO";
gotoxy(30,14); cout<<"ALVARO O¥ATE BOWEN ";
  
getch();
}

void cuadro(int c1, int f1, int c2, int f2)

{
int i;
for(i=c1+1; i<c2; i++)
{
gotoxy(i,f1); cout<<"Í"; delay(1);
gotoxy(i,f2); cout<<"Í"; delay(1);
}
for(i=f1+1; i<f2; i++)
{
gotoxy(c1,i); cout<<"º"; delay(1);
gotoxy(c2,i); cout<<"º"; delay(1);
}
gotoxy(c1,f1); cout<<"É"; delay(1);
gotoxy(c1,f2); cout<<"È"; delay(1);
gotoxy(c2,f1); cout<<"»"; delay(1);
 gotoxy(c2,f2); cout<<"¼"; delay(1);
}

void menu()

{
int opcion;
do{
titulo();
cuadro(1,1,80,24);
cuadro(24,2,61,6);
cuadro(16,7,65,17);
gotoxy(19,9); cout<<"**************MENU PRINCIPAL**************";
gotoxy(22,11); cout<<"1. CAPTURA DE DATOS"; 
gotoxy(22,12); cout<<"2. CONSULTA DE DATOS";
gotoxy(22,13); cout<<"3. SALIR DEL PROGRAMA";
gotoxy(22,14); cout<<"ELIJA UNA OPCION Y PRESIONE <ENTER> [ ]";
gotoxy(59,14); cin >>opcion;
switch(opcion)
{
case 1: captura() ; break;
case 2: consulta(); break;
}

}while( opcion != 3);
}

void titulo()

{
clrscr();
time_t fecha;
fecha = time(NULL);
gotoxy(26,3); cout<<"UNIVERSIDAD POPULAR DEL CESAR";
gotoxy(32,4); cout<<"REGISTRO DE NOTAS";
gotoxy(28,5); cout<<ctime(&fecha);
}

void captura()

{

char CAP = 'S';
fstream archivo("registro1.dat", ios::app);
while(CAP == 'S')
{
titulo();
cuadro(1,1,80,24);
cuadro(24,2,61,7);
gotoxy(34,6); cout<<"CAPTURA DE DATOS";
contexto();
gotoxy(44, 9); cin >>r1.codigo;
gotoxy(44,10); gets(r1.nombre);
gotoxy(44,11); gets(r1.asignatura);
gotoxy(44,12); cin >>r1.nota1;
gotoxy(44,13); cin >>r1.nota2;
gotoxy(44,14); cin >>r1.nota3;

archivo.write((char *) &r1, sizeof(registro1));

do{
gotoxy(20,20); cout <<"DESEA CONTINUAR PROCESANDO DATOS S/N";
gotoxy(59,20); CAP = getch();
CAP = toupper(CAP);
}while((CAP != 'S') && (CAP != 'N'));
}
cierre();
archivo.close();
}

void contexto()

{
gotoxy(15,9);  cout<<"CODIGO                   :";
gotoxy(15,10); cout<<"NOMBRES Y APELLIDOS      :";
gotoxy(15,11); cout<<"ASIGNATURAS              :";
gotoxy(15,12); cout<<"PRIMERA NOTA             :";
gotoxy(15,13); cout<<"SEGUNDA NOTA             :";
gotoxy(15,14); cout<<"TERCERA NOTA             :";
}
 
void consulta()

{
fstream archivo("registro1.dat", ios::in);
titulo();
cuadro(1,1,80,24);
cuadro(24,2,61,7);

gotoxy(26,6); cout<<"CONSULTA TODOS LOS ESTUDIANTES";
detalle();
int f = 11;
while( ! archivo.eof())
{
archivo.read((char *) &r1, sizeof(registro1));
if(archivo.eof()) break;
gotoxy(2,f);  cout<< setw(8) << r1.codigo;
gotoxy(13,f); cout<< r1.nombre;
gotoxy(42,f); cout<< r1.asignatura;
gotoxy(57,f); cout<< setw(4) << r1.nota1;
gotoxy(65,f); cout<< setw(4) << r1.nota2;
gotoxy(73,f); cout<< setw(4) << r1.nota3;

if(f<=20)
{
f++;
}
else
{
gotoxy(21,22); cout<<"pulse cualquier tecla para continuar"; getch();
titulo();
detalle();
f=10;
}
delay(1000);
}
cierre();
archivo.close();
}


void detalle()

{
gotoxy(4,10); cout<<"CODIGO   NOMBRES Y APELLIDOS          ASIGNATURA     NOTA 1  NOTA 2  NOTA 3 ";
}

void cierre()

{
clrscr();
cuadro(10,10,50,14);
gotoxy(12,12); cout<<"CERRANDO ARCHIVO................";
delay(2000);
} 




