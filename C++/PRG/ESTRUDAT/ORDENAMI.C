#include<stdio.h>
#include<math.h>
#include<alloc.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<io.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
void main();
void metodo_de_burbuja();
void metodo_de_insercion();
void el_shell_sort();
void el_quick_sort();
void el_radix_sort();
void captura();


  void main(){

      char op;

 do{



     clrscr();



   textcolor(10);textbackground(4);
   clrscr();
   gotoxy(10,5);printf("*=====================MENU PRINCIPAL======================*");
   textcolor(12);textbackground(7);
   gotoxy(30,10);printf("1.LLENAR VECTOR");
   gotoxy(30,11);printf("2.METODO BURBUJA");
   gotoxy(30,12);printf("3.METODO INSERCION");
   gotoxy(30,13);printf("4.METODO SHELL");
   gotoxy(30,14);printf("5.METODO QUICK SORT");
   gotoxy(30,15);printf("6.METODO DE RADIX SORT");
   gotoxy(30,16);printf("7.SALIR DEL PROGRAMA");

   gotoxy(26,21);printf("DIGITE LA OPCION QUE DESEE==>:");op=getch();
      switch(op)
   {
    // case '1':clrscr();captura();break();
     //case '2':clrscr();metodo_de_burbuja();break();
    // case '3':clrscr();metodo_de_insercion();break();
    // case '4':clrscr();el_shell_sort();break();
    // case '5':clrscr();el_quick_sort();break();
    // case '6':clrscr();el_radix_sort();break();
     case '7':exit(0);break;

     }

}while(op!='6');
}