#include <stdio.h>
#include <conio.h>
#include <dos.h>

#define VIDEO 0x10
main()
{
   union REGS regs;

   regs.h.ah = 0;  
   regs.h.dh = 0;
   regs.h.dl = 0;
   regs.h.bh = 1;
   int86(VIDEO, &regs, &regs);
   return(0);
}

