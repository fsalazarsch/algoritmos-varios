#include<iostream.h>
#include<conio.h>
#include<iomanip.h>  //NECESARIO PARA QUE FUNCIONE setw
void TITULOS();
void MENU();
int CREAR(int MAT[5][4]);
void MOSTRAR(int MAT[5][4]);
void main(void)
  {
  int I,TIPO;
  char OP='S';
  int MAT[5][4];
  while(OP=='S')
    {
    TITULOS();
    MENU();
    do{
       gotoxy(21,16);cout<<"Seleccione una alternativa y presione <ENTER> [  ]";
       gotoxy(64,16);cin>>TIPO;
       }while((TIPO<1)||(TIPO>3));
       switch (TIPO)
	  {
       case 1:
	  CREAR(MATRIZ);
	  break;
       case 2:
	  MOSTRAR(MATRIZ) ;
	  break;
       case 3:
	  OP='N';
	  break;
	  }
     }
   }
    void TITULOS()
     {
     clrscr();
     gotoxy(17,6);cout<<"CAPTURA Y CONSULTA DE VALORES PARA UN ARREGLO";
     gotoxy(28,7);cout<<"BIDIMENSIONAL MATRIZ";
     }
     void MENU()
     {
     gotoxy(26,10);cout<<"1 - ASIGNAR VALORES A LA MATRIZ ";
     gotoxy(26,11);cout<<"2 - CONSULTAR VALORES A LA MATRIZ";
     gotoxy(26,12);cout<<"3 - SALIR DEL PROGRAMA";
     }
     int CREAR(int MAT[5][4])
     {
     int I,J;
     TITULOS();
     gotoxy(27,9);cout<<"ASIGNAR VALORES A LA MATRIZ";
     for(I=0;I<5;I++)
       {
       for(J=0;J<4;J++)
       gotoxy(15,15);cout<<"INTRODUCIR UN VALOR ENTERO DE PRESICION SENCILLA  [  ]"<< " FILA "<<I;
       gotoxy(67,15);cin>>MAT[I][J];
       }
       return MAT[I][J];
     }
       void MOSTRAR(int MAT[5][4])
	  {
	  int I,J,F;
	  TITULOS();
	  gotoxy(26,9);cout<<"CONSULTAR VALORES DE LA MATRIZ";
	  F=13;
	  for(I=0;I<5;I++)
	  {
	  gotoxy(25,F);
	  for(I=0;I<4;I++)
	    cout<<setw(5)<<MAT[I][J]<< "  ";
	    F++;
	    }
	    getch();
	    }

