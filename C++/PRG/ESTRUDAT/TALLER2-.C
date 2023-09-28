/* MATEMATICAMENTE SE HA DADO NOMBRES A LOS NUMEROS CUANDO SE ENCUENTRA QUE
   ESTOS TIENEN UNA CIERTA CUALIDAD.POR EJEMPLO,EXISTEN LOS NUMEROS PARES,
   IMPARES,PRIMOS,AMIGOS,GEMELOS,PERFECTO,ETC.
    
   CONSIDERE LOS NUMEROS PERFECTOS.UN NUMERO ES PERFECTO CUANDO DICHO NUMERO
   ES IGUAL A LA SUMA DE LOS DIVISORES MENORES A EL.
   EJ: 6 = 1+2+3
       28 = 1+2+4+7+14

   DISE¥E UN ALGORITMO QUE PERMITE BUSCAR DENTRO DE LOS NUMEROS NATURALES
   LOS PRIMEROS N NUMEROS PERFECTOS. */


 # include<stdio.h>
 int n,sum,x,b,i;
 main()
  {
  clrscr();
  printf("DIGITE CANTIDAD DE NUMEROS A EVALUAR: ");
  scanf("%d",&n);
  sum = 0;
  for(b = 2;b<=n;b++);
  {
   for(i = 1;i<=b;i++);
   {
    if (b%i==0)
	x = b/i;
	if (x<0)
	   sum = sum + x;
	 }
     }    
    if (sum == b)
       printf("EL NUMERO PERFECTO ES: ");
       scanf("%d",&b);
     }