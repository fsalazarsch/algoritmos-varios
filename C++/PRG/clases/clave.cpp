#include<stdio.h>
#include<conio.h>
#include<varios.h>
#include<string.h>
// Este programa captura una clave
// clave.cpp

main()
{
  char password[]="SISTEMAS";
  char clave[10];
  int op;
  int i=0;

  while (1)
   {
    i++;
    clrscr();
    if(i>3)
      {
       clrscr();
       pos(10,10);printf("EL PROGRAMA QUEDA BLOQUEADO");
       pos(12,10);printf("  Usted tiene mala suerte!");
       break;
      }
     else
     {
       pos(10,4),printf("DIGITE LA CLAVE DE ACCESO --> ");
       scanf("\n"); gets(clave);
       if(strcmp(strupr(clave),password)==0)
        {
         clrscr();
	 pos(10,10);printf ("Usted Tiene acceso al programa!");getch(); break;
        }
       else
	{
          clrscr();
          pos(10,10);printf("Clave incorrecta, digite nuevamente la clave");
          getch();
         }
       }
}
}