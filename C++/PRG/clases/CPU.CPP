/* ���������������������������������
 � biosequip and _bios_equiplist �   <BIOS.H>
 ���������������������������������

 Checks equipment

 Declaration:
  � int biosequip(void);
  � unsigned _bios_equiplist(void);

 Remarks:
biosequip and _bios_equiplist use BIOS
interrupt 0x11 to return an integer describing
the equipment connected to the system.

 Return Value:
The return value is interpreted as a
collection of bit-sized fields.

    �������������������� Number of parallel printers installed:
    �                      00 = 0; 01 = 1; 10 = 2; 11 = 3
    �   ���������������� Serial printer attached
    �   �  ������������� Game I/O attached
    �   �  �     ������� Number of COM ports: 000 = 0, 001 = 1,..., 111 = 7
    �   �  �     �     � Direct memory access (DMA)
    �   �  �     �     �   0 = Machine has DMA; 1 = Machine doesn't have DMA
 �����������������������������������������������ͻ
 �15�14�13�12�11�10� 9� 8� 7� 6� 5� 4� 3� 2� 1� 0�
 �����������������������������������������������ͼ
 Number of disk drives:  ����     �     �    �  �
   00 = 0; 01 = 1; 10 = 2; 11 = 3 �     �    �  �
 Initial video mode  ��������������     �    �  �
   00 = Unused                          �    �  �
   01 = 40x25 BW with color card        �    �  �
   10 = 80x25 BW with color card        �    �  �
   11 = 80x25 BW with mono card         �    �  �
 Motherboard RAM size  ������������������    �  �
   00 = 16K; 01 = 32K; 10 = 48K; 11 = 64K    �  �
 Floating-point coprocessor  �����������������  �
 Boot from disk  ��������������������������������

 � NOTE: DOS only sees two ports but can be
pushed to see four; the IBM PS/2 can see up to
eight.

 Portability:
 � DOS � UNIX � ANSI C � C++ Only �
 � Yes �      �        �          �
 ��������������������������������ͼ

 Examples:
  biosequip example
  _bios_equiplist example*/

/* biosequip example
���������
����������*/

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


