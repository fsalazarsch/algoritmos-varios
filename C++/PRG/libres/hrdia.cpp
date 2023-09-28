#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
char t;
main()
{
printf("Desea saber la hora?\nTeclee s para continuar o cualquier tecla para tecla para salir.\nTeclee ahora:");
scanf("%c",&t);
if(t=='s')
{
union REGS in,out;
in.h.ah=0x2c;
intdos(&in,&out);
gotoxy(1,4);
printf("La hora actual es:%2d:%2d:%2d:%2d",out.h.ch,out.h.cl,out.h.dh,out.h.dl);
if(out.h.ch>=12)
    printf(" PM\nBuenas tardes, bienvenido al programa reloj!");
else
    printf(" AM\nBuenos dias,bienvenido al programa reloj!");
  getch();
}
else
printf("Programa terminado");
abort();
return(0);
}

