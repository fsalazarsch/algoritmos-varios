#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <dos.H>
#include <ctype.h>
#include <alvaro.h>


int main(void)
{
    alv calculo;
   char OP='S';
while(OP=='S'){
   textcolor(1);
   textbackground(0);
   clrscr();
    
    textbackground(WHITE);    
    calculo.CUADRO(2,78,1,25);  
    textcolor(0);  
    calculo.BOTON(0,20,30,22,22,7,2,0,"Guardar");
    textbackground(WHITE);//no se quite (para los textos)
    calculo.BOTON(0,45,54,22,22,7,2,0,"Salir");
    textbackground(WHITE);//no se quite (para los textos)
    calculo.MES(29,59,10);//NOMBRE 1.columna inicial 2.columna final 3.fila
    calculo.MES(29,41,12);//CEDULA
    calculo.MES(29,39,14); //TELEFONO
    calculo.MES(29,49,16);// DIRECCION
    calculo.MES(29,39,18);// TARJETA
    calculo.MES(29,33,20);// CLAVE
  gotoxy(10,10);PR"NOMBRE Y APELLIDO:                                  ";
  gotoxy(10,12);PR"CEDULA:                                  ";
  gotoxy(10,14);PR"TELEFONO:                                  ";
  gotoxy(10,16);PR"DIRECCION:                                  ";
  gotoxy(10,18);PR"TARJETA:                                  ";
  gotoxy(10,20);PR"CLAVE:                                  ";
  gotoxy(35,3);PR"Esc ¯¯¯¯ SALIR";
  calculo.MENU(29,10,12,59); // NOMBRE 1. tama¤o 2.la fila 3. la fila siguiente 4.columna final
  calculo.MENU(12,12,14,41); //CEDULA
  calculo.MENU(10,14,16,39); //TELEFONO
  calculo.MENU(20,16,18,49); //DIRECCION
  calculo.MENU(10,18,20,39); //TARJETA
  calculo.MENU(4,20,22,33); //CLAVE
  calculo.BOTON(0,20,30,22,22,7,3,0,"Guardar");
  calculo.BOTON(1,20,30,22,22,7,2,0,"Guardar");
 gotoxy(26,24);PR"DESEA SEGUIR (S/N)";
  do{
      OP = getch ();
      OP = toupper(OP);
      //gotoxy(26,16);PR"                                      ";
      }while((OP != 'S') && (OP != 'N'));
 }

}


