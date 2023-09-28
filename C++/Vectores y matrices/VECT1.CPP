#include<iostream.h>
#include<conio.h>
void TITULOS();
void MENU();
int CREAR(int VECT[10]);
void MOSTRAR(int VECT[10]);
void main(void)
  {
  int I,TIPO;
  char OP='S';
  int VECTOR[10];
  while(OP=='S')
    {
    TITULOS();
    MENU();
    do{
       gotoxy(15,16);cout<<"Seleccione una alternativa y presione <ENTER> [  ]";
       gotoxy(62,16);cin>>TIPO;
       }while((TIPO<1)||(TIPO>3));
       switch (TIPO)
	  {
       case 1:
	  CREAR(VECTOR);
	  break;
       case 2:
	  MOSTRAR(VECTOR);
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
     gotoxy(28,7);cout<<"UNIDIMENSIONAL VECTOR";
     }
     void MENU()
     {
     gotoxy(26,10);cout<<"1 - ASIGNAR VALORES AL VECTOR";
     gotoxy(26,11);cout<<"2 - CONSULTAR VALORES AL VECTOR";
     gotoxy(26,12);cout<<"3 - SALIR DEL PROGRAMA";
     }
     int CREAR(int VECT[10])
     {
     int I;
     TITULOS();
     gotoxy(27,9);cout<<"ASIGNAR VALORES AL VECTOR";
     for(I=0;I<10;I++)
       {
       gotoxy(15,15);cout<<"INTRODUCIR UN VALOR ENTERO DE PRESICION SENCILLA [  ]";
       gotoxy(64,15);cin>>VECT[I];
       }
       return VECT[I];
     }
       void MOSTRAR(int VECT[10])
	  {
	  int I;
	  TITULOS();
	  gotoxy(26,9);cout<<"CONSULTAR VALORES AL VECTOR";
	  gotoxy(20,18);
	  for(I=0;I<10;I++)
	    cout<<VECT[I]<< "  ";
	    gotoxy(20,22);cout<<"PRESIONE CUALQUIER TECLA PARA CONTINUAR: ";
	    getch();
	    }

