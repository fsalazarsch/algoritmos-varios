#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
void cuadro();
void clave();
void menu();
int i,j;
main()

{
   
     cuadro();
     gotoxy(27,7);
	   printf("BIENVENIDO AL PROGRAMA");
     gotoxy(29,13);
	   printf("Desarrollado por:");
     gotoxy(29,15);
	   printf("OSCAR IVAN VARELA");
     gotoxy(31,16); printf("Cod. 445391");
     gotoxy(26,19);
	   printf("Universidad Antonio Nariño");
     gotoxy(22,23);
	   printf("Presione una tecla para continuar");
     getch();
     menu();
     return(0);
     }
void menu()
{
 int i,j;
 clrscr();
 for (i=4;i<=75;i++)
  {
  gotoxy(i,4); printf("@");
  gotoxy(i,24);
  printf("@");
  }
  for(j=4;j<=24;j++)
   {                    
   gotoxy(4,j); printf("!!");
   gotoxy(75,j); printf("!!");
   }
 char t;
 gotoxy(30,10);
 printf("DESEA RESETEAR EL EQUIPO");
 gotoxy(11,13);
 printf("Presione < S > PARA RESETEAR U OTRA LETRA PARA CANCELAR");
 gotoxy(70,13);
 t=getch();
 if (t=='s' || t=='S')
   {
   union REGS ent,sal;
   ent.h.ah=0x19;
   int86(0x19,&ent,&sal);
    
   }
 else
   {
   clrscr();
   _exit(0);
   }

}

   
       void cuadro()
	  {
	  int i,j;
	  clrscr();
	  
	  for (i=4;i<=75;i++)
	      {
	      gotoxy(i,4); printf("=");
	      gotoxy(i,24);
	      printf("=");
	      }
	  for(j=4;j<=24;j++)
	     {
	     gotoxy(4,j); printf("|");
	     gotoxy(75,j); printf("|");
	     }
	  }
  