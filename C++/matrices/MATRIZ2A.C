#include <stdio.h>
#include <conio.h>

int cuadro(int izq, int arr, int der, int abaj);

 int k,i,j,NUM,R,P,A,B,FIL,COL,n,m;
 int matriz[10][10];

main()

{

 principal();
 opcion();

}
principal()
   {

      clrscr();
      cuadro(1,1,79,25);
      cuadro(8,5,71,24);
      gotoxy(22,7);
      printf("******************MENU*****************");
      gotoxy(17,10);
      printf("   1................   MATRIZ 5 X 5  ");
      gotoxy(17,12);
      printf("   2................   MATRIZ n X m    ");
      gotoxy(17,16);
      printf("   3................   SALIR           ");
      gotoxy(17,22);
      printf("        DIGITE LA OPCION DESEADA : [ ] ");
      gotoxy(22,23);
      printf("***************************************");
      gotoxy(53,22);

      }

      opcion()

      {

       int opcion = 0;
       scanf("%d",&opcion);
       clrscr();
       switch(opcion)
		      {
			case 1:  original();
				 break;
			case 2:  parcial();
				 break;
			case 3:	 salir();
				 break;
			default: error();
	}
 }
 original()
	  {
          int matriz[5][5];

	  cuadro(1,1,79,25);
	  cuadro(19,8,60,12);

	 gotoxy (22,10);
	 printf ("DIGITE EL NUMERO A RESALTAR : ");
	 scanf ("%d",&NUM);

	 clrscr();

	  k = 0;
	  for (i=0;i<5;i++)
	      for (j=0;j<1;j++) {
		   if (NUM == k) {
		       P = 0;
		       R = j;
		       gotoxy (19,22);
		       printf ("COLUMNA : %d, FILA : %d",i,j);
		      }
		  matriz[j][i] = k++;
		  }


	  for (i=1;i<5;i++)
	      for (j=(5-1);j>=0;j--)  {
		  if (NUM == k)  {
		      P = i;
		      R = j;
		      gotoxy (17,22);
		      printf ("COLUMNA : %d, FILA : %d",i,j);
		 }
		  matriz[i][j] = k++;
		  }

	      FIL = 8;
	      for (i=0;i<5;i++) {
		  COL = 11;
		  FIL = FIL + 2;
		  for (j=0;j<5;j++){
		      gotoxy (COL,FIL);
		      printf ("%6d",matriz[i][j]);
		      printf ("\n\n");
		      COL = COL + 8;
		      }
	}

	 k = 1;
	  for (i=0;i<4;i++)
	      for (j=0;j<1;j++) {
		   if (NUM == k) {
		       P = 0;
		       R = j;
		       gotoxy (19,22);
		       printf ("COLUMNA : %d, FILA : %d",i,j);
		      }
		  matriz[j][i] = k++;
		  }


	  for (i=1;i<5;i++)
	      for (j=(5-1);j>=0;j--)  {
		  if (NUM == k)  {
		      P = i;
		      R = j;
		      gotoxy (17,22);
		      printf ("COLUMNA : %d, FILA : %d",i,j);
		 }
		  matriz[i][j] = k++;
		  }

	      FIL = 8;
	      for (i=0;i<5;i++) {
		  COL = 11;
		  FIL = FIL + 2;
		  for (j=0;j<5;j++){
		      gotoxy (COL,FIL);
		      printf ("%6d",matriz[i][j]);
		      printf ("\n\n");
		      COL = COL + 8;
		      }
	}

	  A = (P * 8) + 11;
	  B = (R * 2) + 10;

	  textcolor (RED | BLINK);
	  gotoxy (A,B);
	  cprintf ("%6d",NUM);
	  printf ("\n\n");
	  textcolor(CYAN);
	  getch();
	  clrscr();

	  return(principal(),opcion());
}
parcial()
{

	cuadro(1,1,79,25);
	cuadro(19,8,59,12);
	 gotoxy(22,10);
	 printf("DIGITE EL NUMERO A RESALTAR: ");
	 scanf("%d",&NUM);
	 clrscr();
	 cuadro (1,1,79,25);
	 cuadro (11,9,68,11);
	 cuadro (11,12,68,14);
	 gotoxy(18,10);
	 printf("DIGITE EL NUMERO DE FILAS <MAXIMO DE 10>: ");
	 scanf("%d",&n);
	 gotoxy(18,13);
	 printf("DIGITE EL NUMERO DE COLUMNAS <MAXIMO DE 10>: ");
	 scanf("%d",&m);

	 clrscr();

         k =1;
	  for (i=0;i<m;i++)
	      for (j=(n-1);j>=0;j--)  {
		  if (NUM == k)  {
		      P = i;
		      R = j;
		      cuadro (20,1,59,3);
		      gotoxy (27,2);
		      printf ("COLUMNA : %d, FILA : %d",i,j);
		 }
		  matriz[i][j] = k++;
		  }

	      FIL = 3;
	      for (i=0;i<n;i++) {
		  COL = 3;
		  FIL = FIL + 2;
		  for (j=0;j<m;j++){
		      gotoxy (COL,FIL);
		      printf ("%3d",matriz[j][i]);
		      printf ("\n");
		      COL = COL + 8;
		      }
	}

	  A = (P * 8) + 3;
	  B = (R * 2) + 5;

	  textcolor (RED | BLINK);
	  gotoxy (A,B);
	  cprintf ("%3d",NUM);
	  printf ("\n");
	  textcolor (CYAN);
	  getch();
	  clrscr();
	  return(principal(),opcion());

	}

	error()
	{
        cuadro(1,1,79,25);
	cuadro(19,8,59,12);
	cuadro(19,13,57,17);

	gotoxy(25,10);
	printf("******OPCION INVALIDA******");
	gotoxy(25,15);
	printf("*****TECLEE <ENTER>*******");
	getch();
	return(principal(),opcion());

	}

	salir()
	{
        cuadro(1,1,79,25);
	cuadro(19,8,59,12);
	cuadro(19,13,59,17);
	gotoxy(22,10);
	printf("******EL PROGRAMA HA TERMINADO******");
	gotoxy(26,15);
	printf("******PULSE <ENTER>******");
	getch();

	}

	cuadro (int izq, int arr, int der, int abaj)
	{
	 int I;
	 gotoxy (izq,arr);
	 putchar(201);
	 gotoxy (der,arr);
	 putchar(187);
	 gotoxy (izq,abaj);
	 putchar(200);
	 gotoxy (der,abaj);
	 putchar(188);

	 for (I=(arr+1);I<=(abaj-1);I++){
	      gotoxy(izq,I);
	      putchar(186);
	      gotoxy(der,I);
	      putchar(186);
	 }

	 for(I=(izq+1);I<=(der-1);I++){
	     gotoxy(I, arr);
	     putchar(205);
	     gotoxy(I,abaj);
	     putchar(205);
	 }

    }