#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void error();
void cuadro();
void menu();
void cuad();
void factorial();
void expobase();
void fibonacci();
void sumatoria();
void invertir();
void salir();
void clave();

main()
     {
     textcolor(GREEN);
     textbackground(RED);
     cuadro();
     gotoxy(27,7);
	   printf("BIENVENIDO AL PROGRAMA");
     gotoxy(33,13);
	   printf("JORGE GOMEZ");
     gotoxy(20,15);
	   printf("UNIVERSIDAD ANTONIO NARI¥O - ING ELECTRONICA");
     gotoxy(22,23);
	   printf("Presione una tecla para continuar");
     getch();
     cuadro();
     clave();
     getch();
     return(0);
     }
     void menu()
	   {
	   int opc;
	   cuadro();
	   gotoxy(30,5);
		 printf("MENU PRINCIPAL");
	   gotoxy(15,8);
		 printf("1.- Cuadrado de un numero");
	   gotoxy(15,9);
		 printf("2.- Factorial de un numero");
	   gotoxy(15,10);
		 printf("3.- Hallar de una base N y exponente N su resultado");
	   gotoxy(15,11);
		 printf("4.- Halla N posiciones de la secuencia fibonacci");
	   gotoxy(15,12);
		 printf("5.- Halla la sumatoria 1+1/2+1/3....1/n");
	   gotoxy(15,13);
		 printf("6.- Invertir un numero N");
	   gotoxy(15,14);
		 printf("7.- Salir");
	   gotoxy(15,22);
		 printf("Seleccione su posicion y presione ENTER");
	   gotoxy(58,22);
		 scanf("%d", &opc);
	   clrscr();
	   cuadro();
     switch (opc)
	    {
	    case 1:
		  {
		  cuad();
		  menu();
		  }
	    case 2:
		  {
		  factorial();
		  menu();
		  }
	    case 3:
		  {
		  expobase();
		  menu();
		  }
	    case 4:
		   {
		   fibonacci();
		   menu();
		   }
	    case 5:
		  {
		  sumatoria();
		  menu();
		  }
	    case 6:
		  {
		  invertir();
		  menu();
		  }
	    case 7:
		  salir();
	    default:
		   {
		   clrscr();
		   error();
		   }
	    }
     }

     /* Funciones */
     void error()
	   {
	   cuadro();
	   gotoxy(30,10);
		 printf("Numero no valido");
	   gotoxy(15,13);
		 printf("Digite cualquier tecla para volver al menu principal");
	   getch();
	   menu();
	   }

     void salir()
	   {
	   char t;
	   gotoxy(30,10);
		 printf("Fin del programa");
	   gotoxy(15,13);
		 printf("Presione < S > para continuar o < N > para cancelar");
	   gotoxy(70,13);
		 t=getch();
	   if (t=='s' || t=='S')
	      {
	      exit(0);
	      }
	   else
	      {
	      menu();
	      }
	  }

     void cuad()
	  {
	  int cuad,num;
	  gotoxy(25,7);
		printf("Halla el cuadrado de un numero");
	  gotoxy(20,11);
		printf("Digite un numero para obtener su cuadrado:  ");
	  scanf("%d", &num);
	  cuad=num*num;
	  gotoxy(20,11);
		printf("                                               ");
	  gotoxy(25,13);
		printf("El numero leido es        :%d",num);
	  gotoxy(25,15);
		printf("El cuadrado del numero es :%d",cuad);
	  gotoxy(20,23);
		printf("Presione una tecla para regresar al menu");
	  getch();

	  }

     void factorial()
	  {
	   int e,cont,fact,fin;
	   gotoxy(28,7);
		 printf("FACTORIAL DE UN NUMERO");
	   gotoxy(31,11);
		 printf("Digite el numero");
	   scanf("%d", &fin);
	   gotoxy(25,11);
		 printf("                            ");
	   fact=1;
	   cont=0;
	   e=18;
	   while(cont<fin)
		{
		++cont;
		fact=fact*cont;
		gotoxy(e,14); printf("%d",fact);
		e+=2;
		}
	   gotoxy(20,23);
		 printf("Presione una tecla para regresar al menu");
	   getch();
	   }

     void expobase()
	  {
	  int con,bas,exp,res;
	  gotoxy(14,7);
		printf("ELEVA UN NUMERO ( N ) A CUALQUIER EXPONENTE ( N )");
	  gotoxy(23,11);
		printf("Digite el numero para la base ");
	  scanf("%d",&bas);
	  gotoxy(20,11);
		printf("                                    ");
	  res=bas;
	  gotoxy(20,11);
		printf("Digite el numero para el exponente ");
	  scanf("%d",&exp);
	  gotoxy(20,11);
		printf("                                           ");
	  for(con=1;con<exp;con++)
	     {
	     res=res*bas;
	     }
	  gotoxy(27,11);
		printf("La base es:      %d",bas);
	  gotoxy(27,14);
		printf("El exponente es: %d",exp);
	  gotoxy(27,17);
		printf("El resultado es: %d",res);
	  gotoxy(20,23);
		printf("Presione una tecla para regresar al menu");
	  getch();
	  }

     void fibonacci()
	  {
	  int a,b,c,e,fin,cl,z;
	  gotoxy(24,17); printf("Halla la serie fibonacci");
	  gotoxy(20,11); printf("Digite el numero ==>"); scanf("%d",&z);
	  gotoxy(20,11); printf("                     ");
	  a=0;
	  b=1;
	  c=0;
	  gotoxy(20,14); printf("%d",a);
	  gotoxy(24,14); printf("%d",b);
	  cl=1;
	  e=27;
	  for (cl=1;cl<z;++cl)
	      {
	      c=a+b;
	      gotoxy(e,14); printf("%d ",c);
	      a=b;
	      b=c;
	      e=e+4;
	      }
	  gotoxy(20,23); printf("Presione una tecla para regresar al menu"); getch();
	  }

     void sumatoria()
	  {
	  float ddo,con,res,sum;
	  gotoxy(18,7); printf("Halla la sumatoria");
	  gotoxy(20,11); printf("Digite el numero para el dividendo ==>"); scanf("%f", &ddo);
	  gotoxy(20,11); printf("                   ");
	  sum=0;
	  for (con=1;con<ddo;con++)
	      {
	      res=1/con;
	      sum=sum+res;
	      }
	  gotoxy(20,11); printf("El dividendo es ==>%2.2f",ddo);
	  gotoxy(20,13); printf("La sumatoria es ==>%2.2f",sum);
	  gotoxy(20,23); printf("Presione una tecla para regresar al menu"); getch();
	  }

     void invertir()
	  {
	  int i,j,col,aux,vec[3];
	  gotoxy(20,11); printf("Invierte tres numeros digitados");
	  gotoxy(20,11); printf("Digite cada numero y presione ENTER");
	  col=36;
	  for (i=0;i<=2;i++);
	      {
	      gotoxy(col,14); scanf("%d",&vec[i]);
	      col+=2;
	      }
	  gotoxy(20,11); printf("               ");
	  gotoxy(30,12); printf("Numeros digitados");
	  col=36;
	  for (i=0;i<=2;i++)
	      {
	      for (j=1;j<=2;j++)
		 {
		 if (i<j)
		    {
		    aux=vec[i];
		    vec[i]=vec[j];
		    vec[j]=aux;
		    }
		 }
		 gotoxy(col,19); printf("%d",vec[i]);
		 col+=2;
	      }
	      gotoxy(30,17);
	      for (j=0;j<=2;j++)
		   {
		   printf("%d",vec[j]);
		   }
	      gotoxy(20,23); printf("Presione una tecla para regresar al menu"); getch();
	  }

     void cuadro()
	  {
	  int i,j;
	  clrscr();
	  textcolor(GREEN);
	  for (i=4;i<=75;i++)
	      {
	      gotoxy(i,4); printf("=");
	      gotoxy(i,24);
	      printf("=");
	      }
	  for(j=4;j<=24;j++)
	     {
	     gotoxy(4,j); printf("|");
	     gotoxy(75,j); printf("|");
	     }
	  }

     void clave()
	  {
	  int con;
	  char j,n;
	  cuadro();
	  gotoxy(20,14); printf("Digite clave : ");
	  gotoxy(50,14); j=getch(); gotoxy(50,14); putchar(42);
	  gotoxy(55,14); n =getch(); gotoxy(55,14); putchar(42);
	  if (j==74 &&n==74)
	     {
	     menu();
	     }
	 else
	    {
	    gotoxy(26,24); printf("Clave errada ==> intente nuevamente");
	    getch();
	    gotoxy(26,24); printf("                    ");
	    gotoxy(50,14); printf("        ");
	    clave();
	    }
	 }



