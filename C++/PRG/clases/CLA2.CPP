//#include<stdio.h"
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
# include"stdio.h"
#include<dos.h>

class empleado
{
public:
char nombre[40];
long tel_emp;
float salario;
//void marco();
void sal_emp(void);//funcion definida de la clase
};

void empleado::sal_emp(void){
cout<<"NOMBRE:"<<nombre<<endl;
cout<<"TELEFONO:"<<tel_emp<<endl;
cout<<"SALARIO:"<<salario<<endl;
};

void main(void)
{
//clrscr();
textcolor(0);
textbackground(3);
clrscr();
//marco(2,79,2,24);
empleado operario,jefe,admo;//nombre de la clase//variable de la clase objecto
strcpy(operario.nombre,"pedro perez");
operario.tel_emp=703040;
operario.salario=45703040;
strcpy(operario.nombre,"jose perez");
jefe.tel_emp=709876;
jefe.salario=455676;
strcpy(admo.nombre,"jose pullon");
admo.tel_emp=3709876;
admo.salario=3455676;
operario.sal_emp();//llamada de la funcion
jefe.sal_emp();
admo.sal_emp();
getch();
}



