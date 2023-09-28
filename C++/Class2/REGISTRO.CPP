# include <stdio.h>
# include <conio.h>

struct autor  {
		 char nombre[20];
		 char ape[25];
	      };

struct tema   {
		 char modulo [4];
		 char area [10];
	      };

struct libro  {
		 char nomlib [30];
		 struct autor aut;
		 struct tema tem;
	      }lib[3];

void main (void)
{
     int i,j;
     clrscr();
     for( i=0;i<=2;i++)
     {
	gotoxy(4,2);printf("****************************");
	gotoxy(4,3);printf("  CONTROL DE BIBLIOTECA");
	gotoxy(4,4);printf("****************************");
	gotoxy (10,5); puts ("TITULO DEL LIBRO\n\n");
	gotoxy(4,3);printf("*");
	gotoxy(4,5);printf("*");
	gotoxy(4,6);printf("*");
	gotoxy(4,7);printf("*");
	gotoxy(4,8);printf("*");
	gotoxy(4,9);printf("*");
	gotoxy(4,10);printf("*");
	gotoxy(4,11);printf("*");
	gotoxy(4,12);printf("*");
	gotoxy(4,13);printf("*");
	gotoxy(4,14);printf("*");
	gotoxy(4,15);printf("*");
	gotoxy(4,16);printf("*");
	gotoxy(4,17);printf("*");
	gotoxy(4,18);printf("*");
	gotoxy(4,19);printf("*");
	gotoxy(4,20);printf("*");
	gotoxy(4,21);printf("*");
	gotoxy(4,22);printf("*");
	gotoxy(4,23);printf("*");
	gotoxy(4,24);printf("*");
	gotoxy(4,25);printf("*");
	gotoxy(31,3);printf("*");
	gotoxy(31,5);printf("*");
	gotoxy(31,6);printf("*");
	gotoxy(31,7);printf("*");
	gotoxy(31,8);printf("*");
	gotoxy(31,9);printf("*");
	gotoxy(31,10);printf("*");
	gotoxy(31,11);printf("*");
	gotoxy(31,12);printf("*");
	gotoxy(31,13);printf("*");
	gotoxy(31,14);printf("*");
	gotoxy(31,15);printf("*");
	gotoxy(31,16);printf("*");
	gotoxy(31,17);printf("*");
	gotoxy(31,18);printf("*");
	gotoxy(31,19);printf("*");
	gotoxy(31,20);printf("*");
	gotoxy(31,21);printf("*");
	gotoxy(31,22);printf("*");
	gotoxy(31,23);printf("*");
	gotoxy(31,24);printf("*");
	gotoxy(31,25);printf("*");
	gotoxy(4,25);printf("****************************");
	gotoxy (15,7); gets (lib[i].nomlib);
	gotoxy (10,9); puts ("APELLIDO DEL AUTOR\n\n");
	gotoxy (15,11); gets (lib [i].aut.ape);
	gotoxy (10,13); puts("EL NOMBRE DEL AUTOR");
	gotoxy (15,15); gets(lib[i].aut.nombre);
	gotoxy (10,17); puts ("MODULO\n\n");
	gotoxy (15,19); gets (lib[i].tem.modulo);
	gotoxy (10,21); puts ("AREA DE CONOCIMIENTO\n\n");
	gotoxy (15,23); gets (lib[i].tem.area);

	clrscr();
     }
     j=8;
     for(i=0;i<=2;i++)
     {
	gotoxy (j,5); printf ("%8s", lib[i].nomlib);
	gotoxy (j,6); printf ("%8s", lib[i].aut.ape);
	gotoxy (j,7); printf ("%8s ",lib[i].aut.nombre );
	gotoxy (j,8); printf ("%8s", lib [i].tem.modulo);
	gotoxy (j,9); printf ("%8s",lib[i].tem.area);
	j+=15;
     }
     getch();
}


