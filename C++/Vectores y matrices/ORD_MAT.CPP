//**************MATRIZ**************************


#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <iomanip.h>

void CUADROS();
void CUADROS2();	
void TITULOS();
void CUADROS3();
void CUADROS4();

void main(void)
{
 int I,TIPO,Aux,X,J,F,C,K;
 char OP = 'S';
 int MATRIZ1[5][5];
 int MATRIZ2[5][5];
 int MATRIZ3[5][5];
 while (OP == 'S')
 {
  TITULOS();
  CUADROS();
  CUADROS2();
  textcolor(YELLOW);
  textbackground(BLUE);
  gotoxy(17,10); cout << " 1 - ASIGNAR VALORES A LAS MATRICES";
  gotoxy(17,11); cout << " 2 - SUMAR LOS ELEMENTOS DE LAS MATRICES";
  gotoxy(17,12); cout << " 3 - MOSTRAR LA MATRIZ RESULTANTE";
  gotoxy(17,14); cout << " 4 - SALIR DEL PROGRAMA";
  do{
      gotoxy(16,16); cout <<" Seleccione una alternativa y pulse <ENTER> [   ]" ;
      gotoxy(62,16); cin >>TIPO;
      } while ((TIPO < 1) || (TIPO > 4));
  switch (TIPO) {
   case 1:
    textcolor(WHITE);
    textbackground(RED);
    TITULOS();
    CUADROS();
    CUADROS3();
    X = 25;
    gotoxy(25,9); cout << "ASIGNAR VALORES A LAS MATRICES";
    for (I=0;I<5;I++)
     for (J=0;J<5;J++)
      {
	gotoxy(15,10); cout << " Introducir un valor entero de presici¢n sencilla. ";
	gotoxy(30,13); cout <<"     ";
	gotoxy(15,13); cout <<" MATRIZ 1   : ";
	gotoxy(30,15); cout <<"      ";
	gotoxy(15,15); cout <<" MATRIZ 2   :" ;
	gotoxy(40,20); cout << "Faltan " <<X <<" elementos";
	gotoxy(30,13); cin >> MATRIZ1[I][J];
	gotoxy(30,15); cin >> MATRIZ2[I][J];
	X=X-1;
	}
    textcolor(YELLOW);
    textbackground(BLUE);
    break;
   case 2:
    textcolor(WHITE);
    textbackground(RED); 
    TITULOS();
    CUADROS();
    CUADROS4();
    F = 15;
    gotoxy(23,9); cout << "SUMAR LOS ELEMENTOS DE LAS MATRICES";
    for(I=0;I<5;I++)
     for(J=0;J<5;J++)
      {
       MATRIZ3[I][J] = MATRIZ1[I][J] + MATRIZ2[I][J];
       }
    for(I=0;I<5;I++)
     {
      gotoxy(10,F);
      for(J=0;J<5;J++)
       {
	 cout <<setw(5)<< MATRIZ3[I][J] <<"  ";
	 getch();
	}
	 F++;
       }
     textcolor(YELLOW);
     textbackground(BLUE);
     break;
    case 3:
     textcolor(WHITE);
     textbackground(RED);
     TITULOS();
     CUADROS();
     for (K=0;K<5;K++)
      {
	for(I=0;I<4;I++)
	 for(J=I+1;J<5;J++)
	  {
	   if(MATRIZ3[K][I] > MATRIZ3[K][J])
	    {
	     Aux = MATRIZ3[K][J];
	     MATRIZ3[K][J]= MATRIZ3[K][I];
	     MATRIZ3[K][I] = Aux;
	     }
	   }
	}
     gotoxy(24,10); cout << " ELEMENTOS DE LA MATRIZ ORDENADOS ";
     gotoxy(8,14); cout << " Presione <ENTER> para observar los elementos uno a uno [   ]";
     gotoxy(74,14);getch();
     F=16;
     for(K=0;K<5;K++)
      {
       gotoxy(10,F);
       for(J=0;J<5;J++)
	{
	cout <<setw(9)<< MATRIZ3[K][J] <<"  ";
	getch();
	}
	F++;
       }
     gotoxy(28,22); cout <<"Presione cualquier tecla para continuar ";
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
  gotoxy(20,6); cout << " CAPTURA, CONSULTA Y SUMA DE DOS MATRICES ";
  gotoxy(27,7); cout << " BIDIMENSIONALES - MATRIZ ";
 }

void CUADROS()
{
 int M,K;
 for(M=3;M<=78;M++)
 {
  gotoxy(M,2); cout <<"Í";
  gotoxy(M,23); cout <<"Í";
  delay (5);
 }
for(K=2;K<=23;K++)
 {
 gotoxy(2,2); cout <<"É";
 gotoxy(2,K); cout <<"º";
 gotoxy(2,23); cout <<"È";
 gotoxy(78,2); cout <<"»";
 gotoxy(78,K); cout <<"º";
 gotoxy(78,23); cout <<"¼";
 delay(5);
 }
}

void CUADROS2()
{
int P,K;
for(K=4;K<=18;K++)
 {
 gotoxy(12,K); cout << "*";
 gotoxy(69,K); cout << "*";
 delay(5);
 }
for(P=12;P<=68;P++)
 {
 gotoxy(P,4); cout <<"*";
 gotoxy(P,18); cout <<"*";
 delay(5);
 }
}
void CUADROS3()
{
int O,P;
for(O=14;O<=40;O++)
 {
 gotoxy(O,12); cout <<"Í";
 gotoxy(O,16); cout <<"Í";
 gotoxy(O,14); cout <<"Í";
 delay (5);
 }
 for (P=12;P<=16;P++)
 {
 gotoxy(14,12); cout <<"É";
 gotoxy(14,P); cout <<"º";
 gotoxy(14,14); cout <<"Ì";
 gotoxy(14,16); cout <<"È";
 gotoxy(40,12); cout <<"»";
 gotoxy(40,14); cout <<"¹";
 gotoxy(40,P); cout <<"º";
 gotoxy(40,16); cout <<"¼";
 delay(5);
 }
}

void CUADROS4()
{
int M,K;
for(M=9;M<=47;M++)
 {
 gotoxy(M,14); cout <<"Í";
 gotoxy(M,20); cout <<"Í";
 delay (5);
 }
for(K=14;K<=20;K++)
 {
 gotoxy(9,14); cout <<"É";
 gotoxy(9,K); cout <<"º";
 gotoxy(9,20); cout <<"È";
 gotoxy(47,14); cout <<"»";
 gotoxy(47,K); cout <<"º";
 gotoxy(47,20); cout <<"¼";
 delay(5);
 }
}
