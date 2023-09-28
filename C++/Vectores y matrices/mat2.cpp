//************MATRIZ***************************


#include<iostream.h>
#include<conio.h>
#include<stdio.h> 
void TITULOS();
void MENU();
char CAPTURA(char NOMB[3][30]);
void MOSTRAR(char NOMB[3][30]);
void main(void)
  {
  int I,TIPO,F;
  char OP='S';
  char NOMBRE[3][30];  
  while(OP=='S')
    {
    TITULOS();

    TIPO = MENU();
    switch (TIPO)
	  {
       case 1:
	  CAPTURA( NOMBRES );
	  break;
       case 2:
	  MOSTRAR( NOMBRES ) ;
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
     gotoxy(28,7);cout<<"UNIDIMENSIONAL - VECTOR";
     }
     void MENU()
     {
     int TIPO;
     gotoxy(26,10);cout<<"1 - ASIGNAR VALORES AL VECTOR";
     gotoxy(26,11);cout<<"2 - CONSULTAR VALORES AL VECTOR";
     gotoxy(26,12);cout<<"3 - SALIR DEL PROGRAMA";
     do{
       gotoxy(21,16);cout<<"Seleccione una alternativa y presione <ENTER> [  ]";
       gotoxy(64,16);cin>>TIPO;
       }while((TIPO<1)||(TIPO>3));
     return TIPO;
     }
     char CAPTURA( char NOMB[3][30])
     {
     int I;
     TITULOS();
     gotoxy(27,9);cout<<"ASIGNAR VALORES AL VECTOR";
     for(I=0;I<3;I++)
       {
       gotoxy(20,15);cout<<"NOMBRE :[                                ]";
       gotoxy(30,15);gets( NOMB[I]);
         }
       return NOMB[I][J];
     }
       void MOSTRAR( char NOMB[3][30] )
	  {
	  int I,F;
	  TITULOS();
	  gotoxy(26,9);cout<<"CONSULTAR VALORES AL VECTOR";
	  F=13;
	  for(I=0;I<3;I++)
	  {
	  gotoxy(20,F);cout<<NOMB[I];
	  F++;
	    }
	    getch();
	    }

