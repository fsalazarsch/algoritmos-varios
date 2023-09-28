#include<stdio.h>
#include<io.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<time.h>
#include<alloc.h>
#include<fcntl.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>

void llenar();
void compa();
void suma_fila();
void mayor_fila();
void suma_columna();
void visualizar();

void menu()
{

char op;
 do{
 clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);

    textcolor(4);
    //normvideo;
    gotoxy (30,8); printf("<< MENU PRINCIPAL >>");

  gotoxy(22,3);printf("CORPORACION UNIVERSITARIA DEL SANTANDER");
  gotoxy(29,5);printf("EUCARDO FABIAN PE¥ALOZA");
  gotoxy(32,22);printf("CODIGO: 96132053");
  gotoxy(28,10);printf("[1]. CREACION DE UNA LISTA");
  gotoxy(28,11);printf("[2]. VISUALIZAR LA LISTA");
  gotoxy(28,12);printf("[3]. INSERTAR UN NODO ANTES");
  gotoxy(28,13);printf("[4]. INSERTAR UN NODO DESPUES");
  gotoxy(28,14);printf("[5]. INSERTAR ENTRE NODOS");
  gotoxy(28,15);printf("[6]. ELIMINAR NODO");
  gotoxy(28,16);printf("[7]. SALIR DEL PROGRAMA..");

    textcolor(128+4);
    gotoxy (28,18); cprintf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)
	  {
    case '1':llenar();break;
    case '2':compa();break;
    case '3':suma_fila();break;
    case '4':mayor_fila();break;
    case '5':suma_columna();break;
    case '6':visualizar();break;
    case '7':exit(0);
    getche();

     }
     }while(op!='7');

     }
void llenar(){}
void compa(){}
void suma_fila(){}
void mayor_fila(){}
void suma_columna(){}
void visualizar(){}

main(){
clrscr();
menu();
}