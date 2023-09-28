//*********VECTORES*******************


#include <iostream.h>
#include <dos.h>
#include <conio.h>
#include <ctype.h>
#include<stdio.h>
#include<math.h>
void titulos();
void inicio();
void cuadro(int C1,int F1,int C2,int F2);
void cuadro(int C1,int F1,int C2,int F2)
{
  int i;
  for(i=C1+1;i<C2;i++){
  gotoxy(i,F1);cprintf("Í");delay(1.8);gotoxy(i,F2);cprintf("Í");delay(10.8);}
  for(i=F1+1;i<F2;i++){
  gotoxy(C1,i);cprintf("º");delay(1.8); gotoxy(C2,i);cprintf("º");delay(10.8);}
  gotoxy(C1,F1);cprintf("É");gotoxy(C1,F2);cprintf("È");
  gotoxy(C2,F1);cprintf("»");gotoxy(C2,F2);cprintf("¼");
 }
void inicio()
{
int i,j;
textcolor(15); textbackground(17);

for(i=1; i<26; i++)
{
for(j=1; j<81; j++)
{
delay(1);
gotoxy(j,i); cout<<"²°";

}

}
}
int vector1[100];
int vector2[100];
int vector3[100];
void main()
{
  char op='S';
  while(op=='S')
  {
  clrscr();
  inicio();
  clrscr();
  cuadro(1,1,80,24);
  cuadro(3,7,78,22);
  cuadro(16,2,68,6);
  titulos();
  int i,n;
  gotoxy(22,10);cout<<"DIGITE EL TAMA¥O DE LOS VECTORES: [    ]";
  gotoxy(57,10);cin>>n;
    for (i=0;i<n;i++)
  {
  gotoxy(15,12);cout<<"DIGITE UN VALOR PARA LA POSICION "<<i+1<<" DEL VECTOR 1: [       ] ";
  gotoxy(66,12);cin>>vector1[i];
  gotoxy(15,14);cout<<"DIGITE UN VALOR PARA LA POSICION "<<i+1<<" DEL VECTOR 2: [       ] ";
  gotoxy(66,14);cin>>vector2[i];

  }
    for(i=0;i<n;i++)
    {
    vector3[i]=vector1[i]*vector2[i];
    }
      gotoxy(22,17);cout<<"Multiplicacion de los vectores: ";
      gotoxy(19,19);
      for(i=0;i<n;i++)
      cout<<vector3[i]<<"  ";
      do{
      gotoxy(39,21);cout<<"DESEA CONTINUAR PROCESANDO DATOS S/N";
      op=getch();
      op=toupper(op);
      }while((op!='N')&&(op!='S'));
     }
getch();}
/*******************************************/
void titulos()
  {
    gotoxy(20,3);cout<<"PROGRAMAS DE PRACTICA PARA SEGUNDO PARCIAL";
    gotoxy(20,4);cout<<"MULTIPLICACION DE UN ARREGLO UNIDIMENSIONAL";
    gotoxy(23,5);cout<<"PROFESOR: CARLOS EMILIANO O¥ATE GOMEZ";
   }

