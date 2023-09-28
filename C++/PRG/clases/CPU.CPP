/* Şßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßİ
 Ş biosequip and _bios_equiplist İ   <BIOS.H>
 ŞÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜİ

 Checks equipment

 Declaration:
  ş int biosequip(void);
  ş unsigned _bios_equiplist(void);

 Remarks:
biosequip and _bios_equiplist use BIOS
interrupt 0x11 to return an integer describing
the equipment connected to the system.

 Return Value:
The return value is interpreted as a
collection of bit-sized fields.

    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Number of parallel printers installed:
    ³                      00 = 0; 01 = 1; 10 = 2; 11 = 3
    ³   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ Serial printer attached
    ³   ³  ÚÄÄÄÄÄÄÄÄÄÄÄÄ Game I/O attached
    ³   ³  ³     ÚÄÄÄÄÄÄ Number of COM ports: 000 = 0, 001 = 1,..., 111 = 7
    ³   ³  ³     ³     Ú Direct memory access (DMA)
    ³   ³  ³     ³     ³   0 = Machine has DMA; 1 = Machine doesn't have DMA
 ÉÍÍÑÍÍÎÍÍÎÍÍÎÍÍÑÍÍÑÍÍÎÍÍÎÍÍÑÍÍËÍÍÑÍÍËÍÍÑÍÍËÍÍËÍÍ»
 º15³14º13º12º11³10³ 9º 8º 7³ 6º 5³ 4º 3³ 2º 1º 0º
 ÈÍÍÏÍÍÊÍÍÊÍÍÊÍÍÏÍÍÏÍÍÊÍÍÎÍÍÏÍÍÎÍÍÏÍÍÎÍÍÏÍÍÎÍÍÎÍÍ¼
 Number of disk drives:  ÄÄÄÙ     ³     ³    ³  ³
   00 = 0; 01 = 1; 10 = 2; 11 = 3 ³     ³    ³  ³
 Initial video mode  ÄÄÄÄÄÄÄÄÄÄÄÄÄÙ     ³    ³  ³
   00 = Unused                          ³    ³  ³
   01 = 40x25 BW with color card        ³    ³  ³
   10 = 80x25 BW with color card        ³    ³  ³
   11 = 80x25 BW with mono card         ³    ³  ³
 Motherboard RAM size  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ    ³  ³
   00 = 16K; 01 = 32K; 10 = 48K; 11 = 64K    ³  ³
 Floating-point coprocessor  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ  ³
 Boot from disk  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

 ş NOTE: DOS only sees two ports but can be
pushed to see four; the IBM PS/2 can see up to
eight.

 Portability:
 É DOS Ñ UNIX Ñ ANSI C Ñ C++ Only »
 º Yes ³      ³        ³          º
 ÈÍÍÍÍÍÏÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍ¼

 Examples:
  biosequip example
  _bios_equiplist example*/

/* biosequip example
ßßßßßßßßß
ßßßßßßßßßß*/

#include <bios.h>
#include <stdio.h>
#include <conio.h>

#define CO_PROCESSOR_MASK 0x0003
#define Disk_driver 0x0005

int main(void)
{  clrscr();
   int equip_check;
   int Disk_check;

   equip_check = biosequip();

   if (equip_check & CO_PROCESSOR_MASK)
      printf("There is a math coprocessor installed.\n");
   else
      printf("No math coprocessor installed.\n");

     Disk_check = biosequip();
     if ((Disk_check & Disk_driver) == 00)
	printf("No tiene unidad de disco.\n");
     else
	{if ((Disk_check & Disk_driver) == 01)
	  printf("Tiene una (1) unidad de disco.\n");
	 else
	   {if ((Disk_check & Disk_driver) == 02)
	      printf("Tiene una (2) unidad de disco.\n");
	    else
	       {if ((Disk_check & Disk_driver) == 03)
		printf("Tiene una (3) unidad de disco.\n");
		else
		     printf("Error en lectura");
		}
	     }
	 }







   getch();
   return 0;
}


