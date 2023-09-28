/* ELABORAR UN ALGORITMO QUE LEA UN NUMERO N Y CALCULE EL N-ESIMO TERMINO DE
   LA SECUENCIA DE FIBONACCI. LOS TERMINOS DE LA SECUENCIA, SE CUENTAN ASI:
   0 1 1 2 3 5 8 13 21... */
    
   # include <stdio.h>
   int a,b,c,i,n;
   void main()
   {
    clrscr();
    a = 0;
    b = 1;
    c = 0;
    i = 1;
    printf("DIGITE CANTIDAD DE NUMEROS A CALCULAR: ");  	
    scanf("%d",&n);
    while(i<=n){
	  a = b;
	  b = c;
	  c = a + b;
	  i = i + 1;}
	  printf("EL N-ESIMO TERMINO DE LA SECUENCIA DE FIBONACCI ES: ");
	  printf("%d",c);
	  getche();}


      