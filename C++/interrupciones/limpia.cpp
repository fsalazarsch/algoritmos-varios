#include<conio.h>
#include<dos.h>
main()
	/*este programa limpia la pantalla*/
{
union REGS ent, sal;
ent.h.ah=0x2;
intdos(&ent,&sal);
sal.h.dh=15;
sal.h.dl=10;
getch();
return(0);
}

