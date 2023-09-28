#include <conio.h>
#include <stdio.h>
#include <dos.h>
main()
     {
     textcolor(GREEN);
     textbackground(RED);
     cuadro();
     gotoxy(27,7);printf("<<BIENVENIDO AL PROGRAMA>>");
     gotoxy(27,11);printf("Autor==>JAMES JIMMY GOMEZ");
     gotoxy(27,12);printf("Codigo    4902514");
     gotoxy(26,17);printf("CORPORACION INTERNACIONAL PARA");
     gotoxy(27,18);printf("EL DESARROLLO EDUCATIVO");
     gotoxy(28,20);printf("  CIDE");
     gotoxy(25,23);printf("PRESIONE UNA TECLA PARA CONTINUAR");getch();
     cuadro();
     clave();
     }
     menu()
     {
int opc;
     cuadro();
     gotoxy(30,5);printf("MENU PRINCIPAL");
     gotoxy(15,8);printf("1.CUADRADO DE UN NUMERO");
     gotoxy(15,9);printf("2.FACTORIAL DE UN NUMERO");
     gotoxy(15,10);printf("3.HALLAR DE UNA BASE N Y EXPONENTE N SU RESULTADO");
     gotoxy(15,11);printf("4.HALLAR N POSICIONES DE LA SECUENCIA FIBONACCI");
     gotoxy(15,12);printf("5.HALLAR LA SUMATORIA 1+1/2+1/3+...1/n");
     gotoxy(15,13);printf("6.INVERTIR UN NUMERO N");
     gotoxy(15,14);printf("7.SALIR");
     gotoxy(15,22);printf("TOME SU POSICION Y PRESIONE<<ENTER>>");
     gotoxy(58,22);scanf("%d",&opc);
     clrscr();
     cuadro();
     switch(opc)
           {
	   case 1:cuad();
			         menu();
	   case 2: factorial();
				 menu();
	   case 3:expobase();
				 menu();
	   case 4:fibonacci();
				 menu();
	   case 5:sumatoria();
				 menu();
	   case 6:invertir();
				 menu();
	   case 7:salir();
				 default;clrscr();
	   }
     }

                            /* ERROR */

     error()
	   {
	   cuadro();
	   gotoxy(30,10);printf("NUMERO NO VALIDO");
	   gotoxy(15,13);printf("DIGITE CUALQUIER TECLA PARA VOLVER AL MENU PRINCIPAL");
	   getch();
	   menu();
	   }

                          /*  SALIR DEL PROGRAMA PRINCIPAL */

    salir()
	   {
	   char t;
	   gotoxy(30,10);printf("FIN DEL PROGRAMA");
	   gotoxy(15,13);printf("PRESIONE <S> PARA CONTINUAR O <N> PARA CANCELAR");
	   gotoxy(70,13);t=getch();
	   if(t=='s' }} t=='S')
		  {
		  exit(0);
		  }
	   else
		  {
		  menu();
		  }
	    }
                             /*PROGRAMA CUADRADO  */


     cuad()
	    {
	    int cuad,num;
	    gotoxy(20,7);printf("<<HALLA EL CUADRADO DE UN NUMERO>>");
	    gotoxy(20,11);printf("DIGITE UN NUMERO PARA OBTENER SU CUADRO");scanf("%d",&num);
	    cuad=num*num;
	    gotoxy(20,11);printf("               ")
	    gotoxy(20,13);printf("EL NUMERO LEIDO ES  :%d",num);
	    gotoxy(20,15);printf("EL CUADRADO DEL NUMERO ES:%d",cuad);
	    gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();
	    }


			     /*	PROGRAMA FACTORIAL   */


    factorial()/* INICIA PROGRAMA DE FACTORIAL 1,2,6,24,120,720,...*/
	       {
	       int e, cont, fact, fin;
	       gotoxy(25,7);printf("<<FACTORIAL DE UN NUMERO>>");
	       gotoxy(25,11);printf("HALLAR FACTORIAL DE ===>");scanf("%d",&fin);
	       gotoxy(25,11);printf("             ");
	       fact=1;
	       cont=0;
	       e=20;
	       while(cont<fin)
			  {
			  ++cont;
			  gotoxy(e,14);printf("%d",fact);
			  e+=6;
			  }
	       gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();
	       }



      		                  /*   PROGRAMA EXPONENCIAL    */

         expobase()
	    {
	    int con, bas, exp, res;
	    gotoxy(12,7);printf("<<HALLE UN NUMERO DE BASE N CON EXPONENTE A LA N>>");
	    gotoxy(20,11);printf("DIGITE EL NUMERO PARA LA BASE==>
	    gotoxy(20,11);printf("DIGITE EL NUMERO PARA EL EXPONENTE==>");scanf("%d",&exp);
	    gotoxy(20,11);printf("       ");
	    for(con=1;con<exp;con++)
		  {
		  res=res*bas;
		  }
		  gotoxy(27,11);printf("LA BASE ES  ==>%d",bas);
		  gotoxy(27,13);printf("EL EXPONENTE ES ==>%d",exp);
		  gotoxy(27,17);printf("EL RESULTADO ES ==>%d",res);
	    gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();
	    }
	    	   


                   
		       	/* PROGRAMA SERIE FIBONACCI   0 1 1 2 3 5 8 13 21 ...   */


   fibonacci()
	   {
	   int a, b, c, e, fin, cl, z;
	   gotoxy(18,7);printf("<<HALLA SERIE FIBONACCI HASTA N>>");
	   gotoxy(20,11);printf("DIGITE NUMERO MAYOR QUE ==>0==>");scanf("%d",&z);
	   gotoxy(20,11);printf("    ");
	   a=0;
	   b=1;
	   c=0;
	   gotoxy(20,14);printf("%d",a);
	   gotoxy(24,14);printf("%d",b);
	   cl=1;
	   e=26;
	   for(cl=1;cl<z;cl++)

			       {

		   c=a+b;
		   gotoxy(e,14);printf("%d",c);
		   a=b;
		   b=c;
		   e=e+4;
		   }
	   gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();

	   }



                           /*   CIERRA SERIE DE FIBONACCI  */



    sumatoria()
		 {
		 float ddo,con,res,sum;
		 gotoxy(18,7);printf("<<HALLA LA SUMATORIA DE 1/2+1/3+..1/n>>");
		 gotoxy(20,11);printf("DIGITE UN NUMERO PARA EL DIVIDENDO==>");scanf("%f",&ddo);
                 gotoxy(20,11);printf("       ");
		 sum=0;
		 for(con=1;con<ddo;con++)
			{
			res=1/con;
			sum=sum+res;
			}
			gotoxy(20,11);printf("EL DIVIDENDO ES==>%2.2f",ddo);
			gotoxy(20,13);printf("LA SUMATORIA ES==>%2.2f",sum);
			gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();
			}


				   /*PROGRAMA INVERTIR  */


     invertir()
		 {
		 int i,j,col,aux,vec[3];
		 gotoxy(20,7);printf("<<INVIERTE TRES NUMEROS DIGITADOS>>");
		 gotoxy(20,11);printf("DIGITE CADA NUMERO Y PRESIONE <<ENTER>>");
		 col=36;
		 for(i=0;i<=2;i++)
		       {
		       gotoxy(col,14);scanf("%d",&vec[i]);
		       col+=2;
		       }
	   gotoxy(20,11);printf("        ");
		 gotoxy(30,12);printf("<NUMEROS DIGITADOS>");
		 col=36;
		 for(i=0;i<=2;i++)
		       {
		       for(j=1;j<=2;j++)
			     {
			     if(i<j)
				     {
				     aux=vec[i];




				     vec[i]=vec[j];
				     vec[j]=aux;
				     }
			      }
			gotoxy(col,19);printf("%d",vec[i]);
			col+=2;
			}
			gotoxy(30,17);printf("<NUMEROS INVERTIDOS>");
			gotoxy(20,23);printf("PRESIONE UNA TECLA PARA REGRESAR AL MENU");getch();
			
			}
                         



				      /*  PROGRAMA CUADRADO  */



     cuadro()
		  {
	          int i,j;                              
		  clrscr();   
	          textcolor(GREEN);
	          for(i=4;i<=75;i++)
		        {
			gotoxy(i,4);printf("=");
			gotoxy(i,24);printf("=");
			}
		  for(j=4;j<=24;j++)
			{
			gotoxy(4,j);printf("|");
			gotoxy(75,j);printf("|");
			}

		   }


     clave()

	   {
	   int con;
	   char j,n;
	   cuadro();
	   gotoxy(20,14);printf("DIGITE CLAVE  :  ");
	   gotoxy(50,14);j=getch();gotoxy(50,14);putchar(42); /*j,n equivale al valor del getch */
	   gotoxy(55,14);n=getch();gotoxy(55,14);putchar(42); /*42 en ascci equivale al **/
	   if(j==74 && n==74)
	           {
	           menu();
	           }
	   else
	   {
	   gotoxy(26,24);printf("clave errada==>intente nuevamente");
	   getch();
	   gotoxy(26,24);printf("        ");
	   gotoxy(50,14);printf("    ");
	   clave ();
	   }

     }