#include<stdio.h>
#include<dos.h>
#include<conio.h>
main()
{
union REGS ser,noser;
ser.h.ah=0x19;
noser.h.ah=0x19;
int86(0x19,&ser,&noser);
return (0);
}