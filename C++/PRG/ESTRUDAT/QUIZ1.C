/* ELABORE UN PROGRAMA QUE CALCULE LA SIGUIENTE SUMATORIA:
   SUMA = 2+4+6+8+10+.....+2N
   EL DATO N SE DEBE LEER UTILIZANDO LA INSTRUCCION LEA,Y EL PROGRAMA DEBE
   IMPRIMIR EL RESULTADO. */

   # include<stdio.h>
   int n,i,sum;
   char enter;
   void main()
   {
    clrscr();
    printf("DIGITE CANTIDAD DE NUMEROS A SUMAR: ");
    scanf("%d",&n);
    i = 1;
    sum = 0;
    while(i<n)
    {
     sum = sum + (i*2);
     i = i + 1;

    }
     printf("LA SUMATORIA ES...");
     printf("%d",sum);
     printf("%s",&enter);
     getche();
   }