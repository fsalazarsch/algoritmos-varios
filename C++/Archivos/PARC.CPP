//******************ARCHIVOS***************************

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdio.h>
#include <dos.h>
#include <math.h>

void CUADRO(int ci,int cf,int fi,int ff);
void CAPTURA();
void CONSULTA();
int MENU();

struct ARCHIVO{
  long CODIGO;
  char NOM[20];
  char MAT[15];
  float N1;
  float N2;
  float N3;
 }EST;

void main(void)
{
 int SW,F;
 char OP='S',M='S';
 while(OP == 'S')
 {
 ofstream NOTAS("C:\NOTAS.DAT",ios::app);
 M='S';
  SW=MENU();
  switch(SW){
   case 1:
    while(M == 'S')
     {
       CAPTURA();
       gotoxy(58,10);cin>>EST.CODIGO;
       gotoxy(52,11);gets(EST.NOM);
       gotoxy(52,12);cin>>EST.MAT;
       gotoxy(52,13);cin>>EST.N1;
       gotoxy(52,14);cin>>EST.N2;
       gotoxy(52,15);cin>>EST.N3;
       NOTAS.write((char *)&EST,sizeof(ARCHIVO));
	do{
	   gotoxy(24,22);cout<<"DESEA CONTINUAR CAPTURANDO -S/N-";
	   M=getch();
	   M=toupper(M);
	   gotoxy(24,22);cout<<"                                ";
	   } while((M != 'S')&&(M != 'N'));
       }
     NOTAS.close();
     break;
    case 2:
      CUADRO(2,78,2,24);
      gotoxy(31,5);cout<<"CONSULTA DE DATOS";
      gotoxy(7,7);cout<<"CODIGO       NOMBRE         ASIGNATURA    NOTA_1  NOTA_2  NOTA_3";
      F=9;
      ifstream NOTAS("C:\NOTAS.DAT");
      while(! NOTAS.eof())
      {
       NOTAS.read((char *)&EST,sizeof(ARCHIVO));
       if(NOTAS.eof())
	 break;
       gotoxy(7,F);cout<<setw(4)<<EST.CODIGO;
       gotoxy(16,F);cout<<EST.NOM;
       gotoxy(33,F);cout<<setw(10)<<EST.MAT;
       gotoxy(50,F);cout<<setw(2)<<EST.N1;
       gotoxy(58,F);cout<<setw(2)<<EST.N2;
       gotoxy(66,F);cout<<setw(2)<<EST.N3;
       if(F<=20)
	 F++;
	else
	 {
	  CUADRO(2,78,2,24);
	  gotoxy(31,5);cout<<"CONSULTA DE DATOS";
	  gotoxy(5,7);cout<<"CODIGO     NOMBRE    ASIGNATURA    NOTA_1    NOTA_2   NOTA_3";
	  F=9;
	  gotoxy(26,22);cout<<"Presione cualquier tecla para continuar...";
	  getch();
	  gotoxy(26,22);cout<<"                                          ";
	  }
	gotoxy(26,22);cout<<"Presione cualquier tecla para continuar...";
	getch();
	gotoxy(26,22);cout<<"                                          ";
       }
     NOTAS.close();
     break;
    case 3:
     OP='N';
     break;   
   }
 }
}

int MENU()
{
 int OP;
 CUADRO(2,78,2,24);
 gotoxy(31,5);cout<<"REGISTRO DE NOTAS";
 gotoxy(36,10);cout<<"<< M E N U >>";
 gotoxy(32,12);cout<<"1- CAPTURA DE DATOS";
 gotoxy(32,13);cout<<"2- CONSULTA DE DATOS";
 gotoxy(32,14);cout<<"3- SALIR";
 do{
    gotoxy(26,22);cout<<"Seleccione una alternativa :[ ]";
    gotoxy(55,22);cin>>OP;;
    OP=toupper(OP);
    } while((OP <1)||(OP >3));
 return OP;
 }


void CAPTURA()
{ 
 CUADRO(2,78,2,24);
 gotoxy(32,5);cout<<"CAPTURA DE DATOS";
 gotoxy(29,10);cout<<"CODIGO DEL ESTUDIANTE :981040";
 gotoxy(29,11);cout<<"NOMBRE DEL ESTUDIANTE :";
 gotoxy(29,12);cout<<"ASIGNATURA            :";
 gotoxy(29,13);cout<<"NOTA 1                :";
 gotoxy(29,14);cout<<"NOTA 2                :";
 gotoxy(29,15);cout<<"NOTA 3                :";
 }

void CUADRO(int ci,int cf,int fi,int ff)
{
 int O;
 clrscr();
 textcolor(WHITE);
 textbackground(YELLOW);
 sound(1000);
 delay(100);
 nosound();
 gotoxy(25,4);cout<<"UNIVERSIDAD POPULAR DEL CESAR";
 for(O=ci;O<=cf;O++)
 {
  gotoxy(O,fi);cout<<"Î";
  gotoxy(O,ff);cout<<"Î";
  }
 for(O=fi;O<ff;O++)
 {
  gotoxy(ci,O);cout<<"Î";
  gotoxy(cf,O);cout<<"Î";
  }
 gotoxy(ci,fi);cout<<"Î";
 gotoxy(cf,fi);cout<<"Î";
 gotoxy(ci,ff);cout<<"Î";
 gotoxy(cf,ff);cout<<"Î";
 delay(10);
 }
