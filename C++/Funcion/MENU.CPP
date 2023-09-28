#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <dos.H>
#include <ctype.h>

void CUADRO(int ci, int cf, int fi, int ff);
void MENU(int tam,int fil, int filsig, int colfi);
void MES(int coli, int colf, int fil);
int main(void)
{
   char OP='S';
   int ter;
while(OP=='S'){
   textcolor(1);
   textbackground(BLACK);
   clrscr();
    textbackground(WHITE);
    CUADRO(2,78,1,25);
    MES(29,59,10);//NOMBRE 1.columna inicial 2.columna final 3.fila
    MES(29,41,12);//CEDULA
    MES(29,39,14); //TELEFONO
    MES(29,49,16);// DIRECCION
    MES(29,39,18);// TARJETA
    MES(29,33,20);// CLAVE
  gotoxy(10,10);cout<<"NOMBRE Y APELLIDO:                                  ";
  gotoxy(10,12);cout<<"CEDULA:                                  ";
  gotoxy(10,14);cout<<"TELEFONO:                                  ";
  gotoxy(10,16);cout<<"DIRECCION:                                  ";
  gotoxy(10,18);cout<<"TARJETA:                                  ";
  gotoxy(10,20);cout<<"CLAVE:                                  ";
  gotoxy(35,3);cout<<"Esc ¯¯¯¯ SALIR";
  MENU(29,10,12,59); // NOMBRE 1. tama¤o 2.la fila 3. la fila siguiente 4.columna final
  MENU(12,12,14,41); //CEDULA
  MENU(10,14,16,39); //TELEFONO
  MENU(20,16,18,49); //DIRECCION
  MENU(10,18,20,39); //TARJETA
  MENU(4,20,22,33); //CLAVE
  gotoxy(26,24);cout<<"DESEA SEGUIR (S/N)";
  do{
      OP = getch ();
      OP = toupper(OP);
      //gotoxy(26,16);cout<<"                                      ";
      }while((OP != 'S') && (OP != 'N'));

 }
     textbackground(BROWN);
     clrscr();
     textbackground(BLUE);
     CUADRO(3,78,1,25);
     gotoxy(20,5);textcolor(2);cprintf("GRACIAS POR UTILIZAR NUESTROS SERVICIOS");
     gotoxy(4,18);textcolor(2);cprintf("PARA MAYOR INFORMACION CONSULTE AL INGENIERO:");
     gotoxy(50,20);textcolor(2);cprintf("ALVARO A CARRILLO ARUJO");
     _setcursortype(_NOCURSOR);
     getch();

}

void MENU(int tam,int fil,int filsig,int colfi)
{
   char ch[30];
   int col,j,k,TECLA,RETROCESO,s;
   textcolor(BLACK);
  gotoxy(29,fil);
  col=29;
  _setcursortype(_SOLIDCURSOR);
   k=0;
  for(j=0;j<=tam;j++)//CAMBIA EL TAMA¥O DEL VECTOR
  {
  TECLA=getche();
   if(TECLA==27)
     exit(0);
    else if (TECLA==13)
  {
     gotoxy(29,filsig);
     break;
   }
  else if(TECLA==8)
      {
      if(wherex()==28) //CAMBIA LA COLUMNA INICIAL
      {gotoxy(29,fil);--j;}//CAMBIA LA COLUMNA +1
      else{--col;--j;k=1;}
      }
     else{ch[j]=TECLA;gotoxy(++col,fil);}
  if(k==1)
  {--j;k=0;}
  if(wherex()==colfi)//CAMBIA LA COLUMNA FINAL
  for(k=1;k<100;k++)
 {
   gotoxy(colfi-1,fil); //CAMBIA LA COLUMNA -1
   TECLA=getch();
   if(TECLA==27)
     exit(0);
   else if(TECLA==13)
   {k=2500;j=50;}
   else if(TECLA==8)
   {--col;--j;gotoxy(col,fil);k=140;}
 }
if (TECLA==13){
   gotoxy(29,filsig);
   break;}
}
}
void MES(int coli, int colf,int fil)
{
  int p;
for(p=coli;p<colf;p++){gotoxy(p,fil);cprintf(" ");}
}

void CUADRO(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Í";
gotoxy(o,ff); cout<<"Í";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"º";
gotoxy(cf,o); cout<<"º";
}
gotoxy(ci,fi); cout<<"É";
gotoxy(cf,fi); cout<<"»";
gotoxy(ci,ff); cout<<"È";
gotoxy(cf,ff); cout<<"¼";

}

