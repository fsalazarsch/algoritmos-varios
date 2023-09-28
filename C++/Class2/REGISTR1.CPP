#include <iostream.h>
#include <conio.h>
#include <stdio.h>

struct autor{
						 char nombre[25];
						 char ape[25];
						};
struct tema{
						 char modulo[4];
						 char area[10];
						 };
struct libro{
						 char nomlib[30];
						 struct autor aut;
						 struct tema tem;
						}lib[3];

void main (void)
{
int i,j;
clrscr();
for(i=0;i<=2;i++)
{
	gotoxy(10,5); puts("* TITULO DEL LIBRO  *");
	gotoxy(15,7); gets(lib[i].nomlib);
	gotoxy(10,9); puts("*  APELLIDO DEL AUTOR  *");
	gotoxy(15,11);gets(lib[i].aut.ape);
	gotoxy(10,13); puts("*  NOMBRE DEL AUTOR  *");
	gotoxy(15,15);gets(lib[i].aut.nombre);
	gotoxy(10,17); puts("*  MODULO  *");
	gotoxy(15,19);gets(lib[i].tem.modulo);
	gotoxy(10,21); puts("*  AREA DE CONOCIMIENTO  *");
	gotoxy(15,23);gets(lib[i].tem.area);
clrscr();
 /*	j=10;/*/
}
j=10;
for(i=0;i<=2;i++)
{
	gotoxy(j,5); printf("%5s",lib[i].nomlib);
	gotoxy(j,9); printf("%5s",lib[i].aut.ape);
	gotoxy(j,13); printf("%5s",lib[i].aut.nombre);
	gotoxy(j,17); printf("%5s",lib[i].tem.modulo);
	gotoxy(j,21); printf("%5s",lib[i].tem.area);

 j+=25;
} getch();
}




