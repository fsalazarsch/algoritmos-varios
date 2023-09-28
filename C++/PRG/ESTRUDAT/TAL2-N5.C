/* EN UN CONJUNTO DE N NUMEROS,DE 4 DIGITOS CADA UNO,SE PUEDE TENER O NO EL
   DIGITO 2 COMO PARTE DEL NUMERO.HACER UN ALGORITMO PARA DETERMINAR CUANTOS 
   NUMEROS CONTIENE DICHO DIGITO,ADEMAS CALCULE LA SUMA DE AQUELLOS QUE NO
   LO CONTIENEN.*/

   # include<stdio.h>
   int n,cn,cnc,num,n1,n2,n3,n4,n5,n6,n7;
   main()
   {
    clrscr();
    printf("DIGITE NUMERO DE 4 DIGITOS ");
    scanf("%d",&n);
    cn = 0;
    cnc = 0;
    for (num = 1;num<= n;num++);
    { 
	if ((num >=0)&&(num<=9999))
	   n1 = num / 1000;
	   n2 = num % 1000;
	   n3 = n2 / 100;
	   n4 = n2 % 100;
	   n5 = n4 / 10;
	   n6 = n4 % 10;
	   n7 = n6 / 1;
	   if ((n1==2)&&(n3 == 2)&&(n5 == 2)&&(n7 == 2))
	      cn = cn + 1;
	    else
	      cnc = cnc + num;
	   }

    printf("CANTIDAD DE NUMEROS QUE CONTIENE DIGITO 2 ");
    scanf("%d",&cn);
    printf("CANTIDAD DE NUMEROS QUE NO LO CONTIENEN");
    scanf("%d",&cnc);
    getche();
}
