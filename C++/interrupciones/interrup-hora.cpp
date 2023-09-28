 #include <dos.h>
 #include <bios.h>
 #include <conio.h>
 #include <stdio.h>

 void main(void)
 {
  union REGS entrada, salida;
  char b[512];
  entrada.h.ah = 0x2c;  /* numero de funcion que obtiene la hora */
  clrscr();
  printf("Son las");
     gotoxy(9,1);
     intdos(&entrada, &salida);
     printf("%.2d:%.2d:%.2d", salida.h.ch,salida.h.cl,salida.h.dh);

  
  entrada .h.ah=0x19;
  salida.h.ah=0x02;
  int86(0x19,&entrada,&salida);
   
 }