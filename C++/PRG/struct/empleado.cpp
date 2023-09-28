#include<iostream.h>
#include<conio.h>
#include<string.h>

class empleado
{
 public:
	char nombre[30];
	long numero_empleado;
	float salario;

 void muestra_empleado(void)
 {
  cout<<"nombre: "<<nombre<<endl;
  cout<<"numero: "<<numero_empleado<<endl;
  cout<<"salario:$ "<<salario<<endl;
  };
};

void main(void)
{
 empleado trabajador,jefe;
 strcpy(trabajador.nombre,"Juan Perez");
 trabajador.numero_empleado=12345;
 trabajador.salario=25000;

 strcpy(jefe.nombre,"Hugo Lopez");
 jefe.numero_empleado=101;
 jefe.salario=500000;

 trabajador.muestra_empleado();
 jefe.muestra_empleado();
}