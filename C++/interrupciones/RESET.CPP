#include<stdio.h>
#include<conio.h>
#include<dos.h>
void salida();
void entrada();
int opc;
main()
{
gotoxy(10,6);
printf("Enrique Briceño.");
gotoxy(10,8);
printf("Codigo 445431.");
gotoxy(10,10);
printf("Programa para resetear el equipo.");
gotoxy(10,12);
printf("1.No resetea el equipo.");
gotoxy(10,14);
printf("2.Resetea el equipo.");
gotoxy(10,16);
printf("Teclee su opcion:");
scanf("%d",&opc);
switch(opc)
{
 case 1:
       { entrada(); return(0);}
 case 2:
       { salida();}
 default:
       { clrscr();}
}
return(0);
}

void salida()
{
union REGS in,out;
in.h.ah=0x19;
int86(0x19,&in,&out);
out.h.al=0x02;
}

void entrada()
{
 gotoxy(10,18);
 printf("Esta adentro");
}