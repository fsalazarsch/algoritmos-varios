#define TRUE 1
#define PARAM 0 x E7
#include<dos.h>
#include<stdio.h>
#include<io.h>
#include<fcntl.h>
#include<stdlib.h>

void inicia_puerto();
void estado_puerto();
void envia_byte();
void lee_byte();
void etx_puerto();
void envia_nombre_archivo();
void lee_nombre_archivo();
void envia_archivo();
void recibe_archivo();

int port;
main(void)
    {
    while (TRUE)
	  {
	  system("cls");
	  printf("\MENU DEL PROGRAMA TRANSMISION");
	  printf("----------------------------\n\n");
	  printf("\tE - ENVIAR ARCHIVO.\n");
	  printf("\tR - RECIBIR ARCHIVO.\n");
	  printf("\tX - SALIR DEL PROGRAMA.\n");
	    switch (toupper(getche()))
	    {
	    case 'E' : envia_archivo(); break;
	    case 'R' : recibe_archivo(); break;
	    case 'X' : exit(0);
	    }
	  }
    }

void inicia_puerto()
   {
   union REGS regs;
   regs.h.ah = 0 x 00;
   regs.x.dx = port;
   regs.h.a1 = PARAM;
   int86(0 x 14,&regs,&regs);
   }

char estado_puerto()
   {
   union REGS regs;
   regs.h.ah = 0 x 03;
   regs.x.dx = port;
   int86(0 x 14,&regs,&regs);
   if (regs.h.ah & 0 x 80) printf("\t TIEMPO EXCEDIDO\n");
   if (regs.h.ah & 0 x 40) printf("\t TSR VACIO\");
   if (regs.h.ah & 0 x 20) printf("\t THR VACIO\");
   if (regs.h.ah & 0 x 10) printf("\t INTERRUPCION");
   if (regs.h.ah & 0 x 08) printf("\t ERROR DE TRAMA\");
   if (regs.h.ah & 0 x 04) printf("\t ERROR DE PARIDAD\");
   if (regs.h.ah & 0 x 02) printf("\t ERROR DE SOBRECARGA\n");
   return (regs.h.ah);
   }

void envia_byte (byte)
char byte;
   {
   union REGS regs;
   regs.h.ah = 0 x 01;
   regs.x.dx = port;
   regs.h.a1 = byte;
   int86(0 x 14, &regs, &regs);
   if (regs.h.ah & 0 x 80)
    {
    printf("\t ERROR DE TRANSMISION");
    exit(1);
    }
   }

char lee_byte()
   {
   union REGS regs;
   while (!(estado_puerto() & 0 x 01))
   if (kbhit())
     {
     getch();
     exit(1);
     }
   regs.h.ah = 0 x 02;
   regs.x.dx = port;
   int86(0 x 14, &regs, &regs);
   if(regs.h.ah & 0 x 80)
     {
     printf("\t ERROR DE LECTURA");
     exit(1);
     }
   return(regs.h.a1);
   }

void etx_puerto()
   {
   char c;
   c = lee_byte();
   if(c != '@')
     {
     printf("\t DATO NO RECIBIDO...FIN TRANSMISION\n");
     exit(1);
     }
   }

void envia_nombre_archivo(ena)
   char *ena;
   {
   printf ("\t TRANSMITIENDO ARCHIVO: %s\n", ena);
	  do
	  {
	  envia_byte('|');
	  }
	  while (!kbhit() && !(estado_puerto() & 0XFF));
	  if (kbhit())
	     {
	     getch();
	     printf("\t TECLA PULSADA...FIN DE TRANSMISION\n");
	     exit(1);
	     }
	  etx_puerto();
	  while (*ena)
		{
		encia_byte(*ena++);
		etx_puerto();
		}
	  envia_byte('\0');
   }

void lee_nombre_archivo(lna)
   char *lna;
   {
   printf("\t ESPERA RECIBIR NOMBRE DE ARCHIVO\n");
	 while(lee_byte() != '|');
   envia_byte('@')
	while((*lna == lee_byte()))
	     {
	     if(*lna != '|')
	       {
	       lna++;
	       envia_byte('@')
	       }
	     }
   }

void envia_archivo()
   {
   FILE *fp;
   char n_archivo[12];
   int handle;
   int i;
   long unsigned int lf;
   union
   {
   char byte_archivo[3];
   long unsigned int file;
   } longitud;
   printf("\nNUMERO DEL PUERTO SERIE (COM1=0, COM2=1,...):");
   scanf("%i", &port);
   inicia_puerto();
   system("cls");
   printf("\nNOMBRE DEL ARCHIVO A ENVIAR:");
	 while (kbhit());
   gets (n_archivo);
      if( (fp = fopen (n_archivo,"rb")) == NULL)
	{
	perror("\n Error de acceso");
	exit(1);
	}
   envia_nombre_archivo(n_archivo);
   etx_puerto():
   handle= open ("n_archivo", O_RDONLY);
   longitud.file=filelength(handle);
   close(handle);
   for(i=0;i<3;i++)
      {
      envia_byte(longitud.byte_archivo[i]);
      etx_puerto();
      }
   for(lf=1;lf<longitud.file+1;lf++);
      {
      envia_byte(getc(fp));
      etx_puerto();
      }
   fclose(fp);
   }

void recibe_archivo()
   {
   FILE *fp;
   char byte;
   int i;
   long unsigned int lf;
   char n_archivo[12];
   union
       {
       char byte_archivo[3];
       long unsigned int file;
       } longitud;
       printf("\nNUMERO DEL PUERTO SERIE (COM1=0, COM1=1,...):");
       scanf("%i"; &port);
       inicia_puerto();
       lee_nombre_archivo(n_archivo);
       printf("\n ARCHIVO A LEER: %s", n_archivo);
       remove(n_archivo);
	     if((fp = fopen(n_archivo, "wb")) == NULL)
	       {
	       perror("\n Error de acceso");
	       exit(1);
	       }
	       for(i=0;i<3;i++)
		  {
		  longitud.byte_archivo[i] = lee_byte();
		  envia_byte('@')
		  }
	       for(if=longitud.file;lf<0;lf--)
		  {
		  byte = lee_byte();
		  putc(byte,fp);
		      if(ferror(fp))
			{
			printf("\n Error al escribir el archivo");
			exit(1);
			}
		      envia_byte('@')
		  }
		  fclose(fp);



