#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
 int opc;
 void menu();
 void geset();
 void salir();
 void cancelar();
 void grafico();
 main()
  {
   menu();
   return(0);
  }
 void menu()
  {
   clrscr();
   grafico();
   gotoxy(22,8);
   printf(" Interrupciones ");
   gotoxy(9,11);
   printf("1.Terminar el programa.\n");
   gotoxy(9,12);
   printf("2.Abortar el programa. \n");
   gotoxy(9,13);
   printf("3.Resetear el equipo. \n");
   gotoxy(10,15);
   printf("Digite su opcion:  ");
   scanf("%d",&opc);
   switch(opc)
   {
    case 1:
	    salir();
    case 2: 
	    cancelar();
    case 3: 
	    geset();
   }
  }	     
 void geset()
  {
   int le;
   clrscr();
   grafico();
   gotoxy(12,8);
   printf("Desea resetear el equipo?");
   gotoxy(12,9);
   printf("Digite Si(1) Digite No(0): ");
   gotoxy(12,10);
   scanf("%d",&le);
   if(le==1)
   {
   gotoxy(12,11);
   printf("Espere un momento....");
   union REGS e,s;
   e.h.ah=0x19;
   int86(0x19,&e,&s);
   s.h.al=0x00;
   }
   else
   menu();
  }
 void salir()
  {
   int bi;
   clrscr();
   grafico();
   gotoxy(12,8);
   printf("Desea Terminar el programa ?");
   gotoxy(12,9);
   printf("Si digite(1) o No digite(0): \n");
   gotoxy(12,10);
   scanf("%d",&bi);
   if(bi==1)
    {
     clrscr();
     grafico();
     gotoxy(20,10);
     printf("Programa terminado");
     exit(0);
    }
   else
    menu();
   }
    
  void cancelar()
   {
     int bo;
     clrscr();
     grafico();
   gotoxy(12,8);
   printf("Desea abortar el programa ?");
   gotoxy(12,9);
   printf("Si digite(1) o No digite(0)");
   gotoxy(12,10);
   scanf("%d",&bo);
   if(bo==1)
    {
     abort();
    }
   else
    menu();
   }
  void grafico()
  {
   int i;
   for(i=1;i<=50;i++)
    {
     gotoxy(i+4,5);
     printf("œ");
    }
   for (i=1;i<=14;i++)
   {
    gotoxy(5,i+5);
    printf("ƒ");
   }
   for (i=1;i<=50;i++)
   {
    gotoxy(i+4,19);
    printf("ƒ");
   }
  for (i=1;i<=14;i++)
   {
    gotoxy(54,i+5);
    printf("ƒ");
   }
  }