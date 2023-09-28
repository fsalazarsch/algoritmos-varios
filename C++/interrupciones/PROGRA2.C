#include"stdio.h"
#include"dos.h"
main()
{
 union REGS ent,sal;
 ent.h.ah=0x19;
 sal.h.al=0x02;
 int86(0x19,&ent,&sal);
 return(0);
}

