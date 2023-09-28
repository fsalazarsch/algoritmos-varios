//*********VECTORES*******************

#include <iostream.h>
#include <conio.h>
#include <dos.h>

void CUADROS();
void CUADROS2();	
void TITULOS();

void main(void)
{
int I,TIPO,Aux,J;
char OP = 'S';
int VECTOR[10];
while (OP == 'S')
   {
    TITULOS();
    CUADROS();
    CUADROS2();
    textcolor(YELLOW);
    textbackground(BLUE);
    gotoxy(17,10); cout << " 1 - ASIGNAR VALORES AL VECTOR";
    gotoxy(17,11); cout << " 2 - CONSULTAR VALORES AL VECTOR";
    gotoxy(17,12); cout << " 3 - ORDENAR Y MOSTRAR LOS ELEMENTOS DEL VECTOR ";
    gotoxy(17,14); cout << " 4 - SALIR DEL PROGRAMA";
    do{
      gotoxy(16,16); cout <<" Seleccione una alternativa y pulse <ENTER> [   ]" ;
      gotoxy(62,16); cin >>TIPO;
      } while ((TIPO < 1) || (TIPO > 4));
     switch (TIPO) {
       case 1:
       textcolor(WHITE);
       textbackground(RED);
       sound(2000);
       delay(1000);
       nosound();
       TITULOS();
       CUADROS();
       gotoxy(27,9); cout << "ASIGNAR VALORES AL VECTOR";
       for (I=0;I<10;I++)
	 {
	 gotoxy(15,15); cout << " Introducir un valor entero de persicion sencilla [   ]";
	 gotoxy(66,15); cin >> VECTOR[I];

	 }
	 textcolor(YELLOW);
	 textbackground(BLUE);
	 break;
      case 2:
       textcolor(WHITE);
       textbackground(RED); 
       TITULOS();
       CUADROS();
              gotoxy(26,9); cout << "CONSULTAR VALORES AL VECTOR";
       for (I=0;I<10;I++)
	 {
	 gotoxy(49,15); cout << "            ";
	 gotoxy(18,15); cout <<" valor del vestor en l posici¢n " << I << " = " << VECTOR[I];
	 getch();
	 }
	 textcolor(YELLOW);
	 textbackground(BLUE);
       break;
      case 3:
       textcolor(WHITE);
       textbackground(RED);
       TITULOS();
       CUADROS();
       for (I=0;I<10-1;I++)
	  for (J=I+1;J<10;J++)
	  {
	  if(VECTOR[I]>VECTOR[J])
	   {
	   Aux = VECTOR[I];
	   VECTOR[I] = VECTOR[J];
	   VECTOR[J] = Aux;
	   }
	  }
       gotoxy(25,10); cout << " ELEMENTOS DEL VECTOR ORDENADOS ";
       gotoxy(8,14); cout << " Presione cualquier tecla para observar los elementos uno a uno [   ]";
       gotoxy(74,14);getch();
       gotoxy(14,16);
       for (I=0;I<10;I++)
	 {
	 cout << VECTOR[I] <<" ";
	 getch();
	 }
	 gotoxy(28,20); cout <<"Presione cual quier tecla para continuar ";
	 getch();
	 textcolor(YELLOW);
	 textbackground(BLUE);
       break; 	    
      case 4:
      OP = 'N';
      break;
      }          
    }
}
void TITULOS()
  {
  clrscr();
  gotoxy(17,6); cout << " CAPTURA Y CONSULTA DE VALORES PARA UN ARREGLO ";
  gotoxy(28,7); cout << " UNIDIMENSIONAL - VECTOR ";
  }
void CUADROS()
{
int I,J;
for(I=3;I<=78;I++)
 {
 gotoxy(I,2); cout <<"Í";
 gotoxy(I,23); cout <<"Í";
 delay (20);
 }
for(J=2;J<=23;J++)
 {
 gotoxy(2,2); cout <<"É";
 gotoxy(2,J); cout <<"º";
 gotoxy(2,23); cout <<"È";
 gotoxy(78,2); cout <<"»";
 gotoxy(78,J); cout <<"º";
 gotoxy(78,23); cout <<"¼";
 delay(20);
 }
}

void CUADROS2()
{
int P,K;
for(K=4;K<=18;K++)
 {
 gotoxy(12,K); cout << "*";
 gotoxy(69,K); cout << "*";
 delay(30);
 }
for(P=12;P<=69;P++)
 {
 gotoxy(P,4); cout <<"*";
 gotoxy(P,18); cout <<"*";
 delay(30);
 }
}