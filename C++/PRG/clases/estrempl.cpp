#include "stdio.h"
#include "conio.h"
#include "varios.h"
#include "string.h"

#define T 5

//Este programa captura una estructura 5 veces y reporta a los
//empleados con un sueldo mayor de 500.000.  estrempl.cpp

struct datos
{
 char cod[6];
 char nom[15];
 char ape[15];
 char dir[30];
 float salario;
}ejemplo[T];

int i;

void main();
void capturar();
void consultar();
void terminar();

void menu()
{
 clrscr;
 pos(4,1);rayas(74,'=');
 centrar("UNIVERSIDAD ANTONIO NARIÑO",5);
 centrar("FACULTAD DE INGENIERIA DE SISTEMAS",6);
 centrar("CICLO 5",7);
 pos(8,1);rayas(79,1);
 pos(8,33);printf("MENU PRINCIPAL");
 pos(11,14);printf(" 1. capturar ");
 pos(12,14);printf(" 2. consultar ");
 pos(14,14);printf(" 3. terminar ");
 pos(17,20);printf("Digite opcion --> ");

}


void capturar()
 {
  clrscr();
  pos(4,55);printf("CAPTURA DE REGISTROS");

  for (i=0;i<T;i++)
  {
  pos(10,10);printf(" Código...:");
  pos(12,10);printf(" Nombre...:");
  pos(14,10);printf(" Apellido..:");
  pos(16,10);printf(" Dirección..:");
  pos(18,10);printf(" Salario..:");
  pos(10,28);scanf("\n");
  gets(ejemplo[i].cod);
  pos(12,28);gets(ejemplo[i].nom);
  pos(14,28);gets(ejemplo[i].ape);
  pos(16,28);gets(ejemplo[i].dir);
  pos(18,28);scanf("%f",&ejemplo[i].salario);
  getchar();
 }
 clrscr();
 }

 void consultar()
 {
  clrscr();
  pos(4,1);rayas(74,'=');
  centrar("UNIVERSIDAD ANTONIO NARIÑO",4);
  centrar("CONSULTA TOTAL DE REGISTROS",5);
  pos(6,1);rayas(79,1);
  clrscr();
  pos(12,5); printf("CODIGO");
  pos(12,12); printf("NOMBRE");
  pos(12,35); printf("APELLIDO");
  pos(12,50); printf("DIRECCION");
  pos(12,65); printf("SUELDO");
  getch();
 for (i=0;i<T;i++)
   {
    pos(14+i,5); puts(ejemplo[i].cod);
    pos(14+i,12); puts(ejemplo[i].nom);
    pos(14+i,35); puts(ejemplo[i].ape);
    pos(14+i,50); puts(ejemplo[i].dir);
    pos(14+i,65); printf("%7.2f",ejemplo[i].salario);
  }
 getch();
 clrscr();
 pos(2,2); printf("** Digite <Enter> para seguir visualizando **");
 pos(10,10);printf("EMPLEADOS CON SUELDOS SUPERIORES A 500000 ");
 pos(12,5); printf("CODIGO");
 pos(12,12); printf("NOMBRE");
 pos(12,35); printf("APELLIDO");
 pos(12,50); printf("DIRECCION");
 pos(12,65); printf("SUELDO");
 getch();
 for (i=0;i<T;i++)
   {
     if(ejemplo[i].salario>500000)
       {
	pos(14+i,5); puts(ejemplo[i].cod);
        pos(14+i,12); puts(ejemplo[i].nom);
        pos(14+i,35); puts(ejemplo[i].ape);
        pos(14+i,50); puts(ejemplo[i].dir);
        pos(14+i,65); printf("%7.2f",ejemplo[i].salario);
        getch();
       }
}
clrscr();
}


void main()
{
  int op=0;
  while (1)
  {
    menu();
    pos(17,37);scanf("%d",&op);
    if (op!=3)
    {
    clrscr();
    pos(20,20);printf("Opción fuera de rango ");
    }
    switch(op)
	 {
          case 1:{
		capturar();break;
	          }
	  case 2:{
	      	consultar();break;
		 }
          case 3:{
                clrscr();
		centrar("Este programa ha terminado, cierre la ventana por favor!",10);return;
	         }
	 

	  }
   }

}



