#include<stdio.h>
#include<conio.h>
#include<dos.h>
void SCRCL();
main()
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        clrscr();
void SCRCL();
{
union REGS regs;
regs.h.ah=6;
regs.h.al=10;
regs.h.ch=0;
regs.h.cl=0;
regs.h.dh=23;
regs.h.dl=79;
regs.h.bh=7;
int86(0x10,&regs,&regs);
 return(0);
 }
}