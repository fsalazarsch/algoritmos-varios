#include<stdio.h>
#include<conio.h>
#include<dos.h>
void pan();
int op;
main()
{
gotoxy(5,6);
printf("Programa que limpia la pantalla");
gotoxy(5,9);printf("si desea limpiar la pantalla digite 1\n");
scanf("%d,&op");
switch (op)
{
case 1: pan();
default : clrscr();
}
return(0);
}
void pan()
{
geninterrupt(10);
}