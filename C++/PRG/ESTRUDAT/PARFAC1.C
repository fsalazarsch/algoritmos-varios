/* HACER UN ALGORITMO PARA QUE DADO, UN NUMERO PAR A Y UN NUMERO IMPAR B
   CON B > A, LISTE TODOS LOS NUMEROS PARES ENTRE AMBOS DE MAYOR A MENOR
   JUNTO CON SU RESPECTIVO FACTORIAL.  */

   #include <stdio.h>
   #include <conio.h>
   #include <math.h>
   int a,b,j,i,dif;
   long int fact(long int i),var1;
   void main()
   {
     clrscr();
     printf("DIGITE EL PRIMER NUMERO: ");
     scanf("%d",&a);
     printf("DIGITE EL SEGUNDO NUMERO: ");
     scanf("%d",&b);
     if((a % 2) == 0 ){
       if((b % 2) == 1){
	 if(b > a){
	      for (i = b-1;i>=a;i=i-2){
		  var1 = fact(i);
		  printf(" EL FACTORIAL DE %d ES %d\n",i,var1);
	       }
	 }
	 else
	      printf("a es mayor que b");
	  }
     else
	   printf("b no es impar");
       }
     else
	printf("a no es par");

	getche();
     }



long int fact(long int i)
 {
  long fact;
  fact = 1;
  if(i == 0)
    return(1);
    for(j=1;j<=i;j++){
       fact = fact * j;
     }
       return(fact);
 }

