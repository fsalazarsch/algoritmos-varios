#include <stdio.h>
#include <string.h>
#include <conio.h>
#define max 10
int cola[10];
int frente,final,dato;
char op;
void meter_final(),meter(),meter_frente(),meter_fre(),sacar_frente(),ver_cola(),menu2(),menu(),menu3(),sacar(),sacar_final(),sacar_fin();
void main()
{
 clrscr();
 menu();
 getche();
}
void menu()
{
do
{
 do
 {
 clrscr();
 printf("        MENU PRINCIPAL\n");
 printf("\n");
 printf("1. INSERTAR VALORES A LA COLA\n");
 printf("2. SACAR VALORES DE LA COLA\n");
 printf("3. SALIR\n");
 printf(" DIGITE LA OPCION  ");
 op=getche();
 printf("\n");
 }while (op<'1'	|| op>'3');
 switch(op)
 {
  case '1':
	  {
	    menu2();
	    break;
	  }
  case '2':
	  {
	   menu3();
	   break;
	   }
  case '3':
	   break;

  }
  }while(op!='3');
}
void menu2()
{
 do
 {
 do
 {
 clrscr();
 printf("  MENU PARA INSERTAR EN UNA BICOLA\n");
 printf("1. INSERTAR POR EL FRENTE\n");
 printf("2. INSERTAR POR EL FINAL\n");
 printf("3. SALIR\n");
 printf(" DIGITE LA OPCION  ");
 op=getche();
 printf("\n");
 }while (op<'1'|| op>'3');
 switch(op)
 {
  case '1':
	  {
	   meter_frente();
	   break;
	   }
   case '2':
	   {
	   meter_final();
	   break;
	   }
    case '3':
	    break;
    }
    }while(op!='3');
    menu();
}
void menu3()
{
 do
 {
 do
 {
 clrscr();
 printf("  MENU PARA SACAR EN UNA BICOLA\n");
 printf("1. SACAR POR EL FRENTE\n");
 printf("2. SACAR POR EL FINAL\n");
 printf("3. SALIR\n");
 printf(" DIGITE LA OPCION  ");
 op=getche();
 printf("\n");
 }while (op<'1'|| op>'3');
 switch(op)
 {
  case '1':
	  {
	   sacar_frente();
	   break;
	   }
   case '2':
	   {
	   sacar_final();
	   break;
	   }
    case '3':
	    break;
    }
    }while(op!='3');
    menu();
}
void meter_final()
{
 frente=0;
 final=0;
 do
 {
  clrscr();
  printf("INTRODUZCA UN DATO  ");
  scanf("%d",&dato);
  //meter(cola,dato);
  ver_cola();
  printf("\n");
  printf("DESEA INTRODUCIR MAS DATOS A LA BICOLA(s/n): ");
  op=getche();
  printf("\n");
  }while (op != 'n');
}

void meter_frente()
{
 frente=0;
 final=0;
 do
 {
  clrscr();
  printf("INTRODUZCA UN DATO  ");
  scanf("%d",&dato);
//  meter(cola,dato);
  ver_cola();
  printf("\n");
  printf("DESEA INTRODUCIR MAS DATOS A LA BICOLA(s/n): ");
  op=getche();
  printf("\n");
  }while (op != 'n');
 }
void meter(int cola[],int dato)
{
 if (((frente==1) && (final== max)) || (frente == final+1))
     printf("COLA ESTA LLENA\n");
 else
 {
   if (frente==0)
   {
     frente=1;
     final=1;
     }
   else
     if (final== max)
	final=1;
     else
	final++;
   cola[final]=dato;
  }
}
void ver_cola()
{
  int i;
  for (i=frente;i<=final;i++)
      printf("%d ",cola[i]);
  getche();
}
void meter_fre(int cola[],int dato)
{
 if (((frente==1) && (final== max)) || (frente == final+1))
     printf("BICOLA ESTA LLENA\n");
 else
 {
   if (frente==0)
   {
     frente=1;
     final=1;
     }
   else
     if (final== max)
	final=1;
     else
	final++;
   cola[final]=dato;
  }
}
void sacar_frente()
{
 frente =1;
 final= 9;
 do
 {
   clrscr();
   printf("DESEA ELIMINAR UN DATO DE LA BICOLA?(s/n): ");
   op=getche();
   if (op=='s')
  // sacar(cola,dato);
   printf("DESEA SACAR OTRO DATO (s/n): ");
   op=getche();
   printf("\n");
  }while(op!='n');
}
void sacar_final()
{
 frente =1;
 final= 9;
 do
 {
   clrscr();
   printf("DESEA ELIMINAR UN DATO DE LA COLA?(s/n): ");
   op=getche();
   if (op=='s')
   //sacar_fin(cola,dato);
   printf("DESEA SACAR OTRO DATO (s/n): ");
   op=getche();
   printf("\n");
  }while(op!='n');
}
void sacar(int cola[],int dato)
{
 if (frente==0)
 {
   printf("\n");
   printf("COLA VACIA\n");
   getche();
 }
 else
 {
  dato=cola[frente];
  if (frente== final)
  {
   frente=0;
   final=0;
  }
  else
     if (frente==max)
       frente=1;
     else
	frente++;
  printf("\n");
  printf("EL DATO %d FUE ELIMINADO DE LA COLA\n",dato);
  ver_cola();
}
}
void sacar_fin(int cola[],int dato)
{
 if (frente==0)
 {
   printf("\n");
   printf("COLA VACIA\n");
   getche();
 }
 else
 {
  dato=cola[frente];
  if (frente== final)
  {
   frente=0;
   final=0;
  }
  else
     if (frente==max)
       frente=1;
     else
	frente++;
  printf("\n");
  printf("EL DATO %d FUE ELIMINADO DE LA COLA\n",dato);
  ver_cola();
}
}




