/***********************************************************
* ESTE PROGRAMA PERMITE CALCULAR LA NOMINA DEL ALMACEN LA  *
* TRAMPA,QUIEN CUENTA CON UN GRUPO DE VENDEDORES POR LINEA *
* DE ARTICULO QUE TIENEN UN SALARIO BASICO,PRIMA DE ANTI-  *
* GUEDAD Y UNA COMISION EN LAS VENTAS.                     *
***********************************************************/
# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# include <stdio.h>
# include <fstream.h>
# include <iomanip.h>
# include <dos.h>
void presentacion();
void CONTODO();
void color();
void LINEAS();
void PANTALLAZO();
void MARCO();
int MENU();
int SUBMENU();
void CAPTURA();
void CONSULTA();
void LIQUIDACION();
void DETALLE();
void DETALLE_SN();
void cuadro();
char LINEA_VENTA();
float LINEA_TV(float VTAS);
float LINEA_MUEBLES(float VTAS);
struct REGISTRO {
     long CEDULA;
     char NOMBRE[30];
     float SB;
     int TIEMPO;
     char LINEA;
     float VTAS;
     } EMP;
     void main(void)
	 {
         clrscr();
         char OPCION='S';
	 int SW;
	 while (OPCION=='S')
	    {
	     SW=MENU();
	    switch (SW) {
	      case 1:
	      CAPTURA();
	      break;
	      case 2:
	      CONSULTA();
	      break;
	      case 3:
	      LIQUIDACION();
	      break;
	      case 4:
	      OPCION='N';
	      break;
	      }
	     }         color();
	 }
int MENU()
  {
  presentacion();
  int j;
  gotoxy(32,6); cout << "   M E N U  ";
  gotoxy(23,12); cout << "1 - CAPTURA DE DATOS";
  gotoxy(23,13); cout << "2 - CONSULTA DE DATOS";
  gotoxy(23,14); cout << "3 - LIQUIDACION";
  gotoxy(23,15); cout << "4 - SALIR DEL PROGRAMA";
  do {
     gotoxy(20,20); cout << "SELECIONE UNA OPCION  :"; cin >> j;
     }while ((j<1)||(j>4));
  return j;
 }
 int SUBMENU()
   {
   presentacion();
   int j;
   textbackground(RED);
   gotoxy(28,6); cout <<"   S U B M E N U  ";
   gotoxy(23,12); cout << "1 - INDIVIDUAL POR EMPLEADO";
   gotoxy(23,13); cout << "2 - TODOS LOS EMPLEDOS";
   gotoxy(23,14); cout << "3 - SALIR DEL SUBMENU";
   do {
      gotoxy(20,20); cout << "seleccione una opcion :  ";
      cin >> j;
      } while ((j<1)||(j>3));
   return j;
  }
void PANTALLAZO()
 {
 gotoxy(15,9); cout << "CEDULA                :[             ]";
 gotoxy(15,10); cout <<"NOMBRES Y APELLIDOS   :[                      ]";
 gotoxy(15,11); cout <<"TIEMPO SERVICIO (AЅOS):[    ]";
 gotoxy(15,12); cout <<"ASIGNACION BASICA     :[        ]";
 gotoxy(15,13); cout <<"LINEA DE ARTICULO     :[    ]";
 gotoxy(15,14); cout <<"VALOR DE LAS VENTAS   :[                   ]";
 }
   void MARCO()
{
clrscr();
int I,k,m;
textcolor(WHITE);
textbackground(BLACK);
  color();
      for(k = 7; k <= 23; k++)
	 for(m = 3; m <= 79; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" ");
	   }

   for(k = 8; k <= 22; k++)
	    for(m = 3; m <= 78; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" ");
	  }
	  /********************/
	   for(k = 3; k <= 6; k++)
	 for(m = 4; m <= 79; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" ");
	   }
      gotoxy(25,4);cout<<"         ALMACEN EL MEJOR          ";
      gotoxy(25,5);cout<<" PROSESO DE LIQUIDACION DE NOMINA  ";
}

     void CAPTURA()
	{
	char CAP='S';
	ofstream ARCHIVO("VENDEDOR.DAT",ios::app);
	while ( CAP == 'S')
	     {
	     MARCO();
	     PANTALLAZO();
	     gotoxy(32,6); cout << "CAPTURA DE DATOS";
	     gotoxy(40,9); cin >> EMP.CEDULA;
	     gotoxy(40,10); gets(EMP.NOMBRE);
	     gotoxy(40,11); cin >> EMP.TIEMPO;
	     gotoxy(40,12); cin >> EMP.SB;
	     EMP.LINEA = LINEA_VENTA();
	     gotoxy(40,14); cin >> EMP.VTAS;
	     ARCHIVO.write((char *) &EMP, sizeof(REGISTRO));
	     do {
		gotoxy(23,20); cout <<"desea continuar capturando S/N ";
		CAP=getch();
		CAP=toupper(CAP);
		} while ((CAP!='S')&&(CAP!='N'));
	      }
	     ARCHIVO.close();
	    }
	    char LINEA_VENTA()
	       {
	       char LINEA;
	       do {
		  gotoxy(5,22); cout << "T - TV, C - computador, E - estufas, M - muebles, A - adornos";
		  gotoxy(40,13);LINEA=getch();
		LINEA=  toupper(LINEA);
		  gotoxy(5,22); cout << "                                                             ";
		  } while ((LINEA!='T')&&(LINEA!='C')&&(LINEA!='A')&&(LINEA!='E')&&(LINEA!='M'));
	       return LINEA;
	       }
		/*********PRESENTACION DE DATOS DE CONSULTA GENERAL***/
	 void  CUADRO(void)
	     {
	     int i ;
    gotoxy(5,8);cout<<"NOMBRE                     CEDULA     S.BASICO  TIEMPO  LINEA  VAL.VENTAS ";
	      for (i=7; i<=22; i++)
     {
     gotoxy(3,i); cout <<"л";
     gotoxy(79,i); cout <<"л";
     }
    for (i=3; i<=78; i++)
     {
     gotoxy(i,7); cout <<"лл";
     gotoxy(i,22); cout <<"лл";
     }
	for (i=7; i<=22; i++)
     {
      gotoxy(30,i); cout <<"л";
      gotoxy(42,i); cout <<"л";
      gotoxy(52,i); cout <<"л";
      gotoxy(60,i); cout <<"л";
      gotoxy(66,i); cout <<"л";
	 }
	 }

   /**************PRESENTACION DE DATOS DE LIQUIDACION GENERAL ********************************************************/
	 void  CUADRO2(void)
	     {
	     int i ;
    gotoxy(5,8);cout<<"NOMBRE                     CEDULA   S.BASICO    PRIMA   COMISION   S.NETO";

	      for (i=3; i<=78; i++)
		 {
		 gotoxy(i,7); cout <<"лл"; delay(5);
		 gotoxy(i,22); cout<<"лл";delay(5);
		 }
	       for (i=7; i<=22; i++)
		   {
		   gotoxy(69,i); cout <<"л"; delay(5);
		   gotoxy(49,i); cout <<"л"; delay(5);
		   gotoxy(40,i); cout <<"л"; delay(5);
		   gotoxy(30,i); cout <<"л"; delay(5);
		   gotoxy(59,i); cout <<"л"; delay(5);
		   gotoxy(3,i); cout <<"л"; delay(5);
		   gotoxy(79,i); cout <<"л";delay(5);
		   }
	}
	/***********************************************************/
	       void CONSULTA()
		  {
		  long CEDULA;
		  int F,SUB = 1;
		   ifstream ARCHIVO("VENDEDOR.DAT");
		  if (ARCHIVO.fail())
		    {
		    gotoxy(26,12); cout << "ARCHIVO NO EXISTE.....OJO"; getch();
		    SUB = 3;
		    }
		    ARCHIVO.close();
		  while (SUB != 3)
		      {
		       SUB=SUBMENU();
		      switch ( SUB ) {
			 case 1:
			   ifstream ARCHIVO("VENDEDOR.DAT");
			  MARCO();
			  gotoxy(30,6); cout << "CONSULTA POR EMPLEADO";
			  gotoxy(15,9); cout << "CEDULA                :[       ]";
			  gotoxy(40,9); cin >> CEDULA;
			  while (! ARCHIVO.eof() )
			       {
			       ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
			       if (CEDULA == EMP.CEDULA)
				  {
				   PANTALLAZO();
				   gotoxy(40,9); cout << EMP.CEDULA;
				   gotoxy(40,10); cout << EMP.NOMBRE;
				   gotoxy(40,11); cout << EMP.TIEMPO;
				   gotoxy(40,12); cout << EMP.SB;
				   gotoxy(40,13); cout << EMP.LINEA;
				   gotoxy(40,14); cout << EMP.VTAS;
				   gotoxy(21,22); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
				   break;
				   }
				   }
				if (ARCHIVO.eof())
				   {
				   gotoxy(16,12); cout <<"ESTE EMPLEADO NO EXISTE.....POR FAVOR VERIFIQUE";
				   getch();
				   }
				   ARCHIVO.close();

				   break;
				 case 2:
				     CONTODO();
				     break;
					}
				       }
				     }
				  /*********************************/
				    void LIQUIDACION()
					{
					int F;
					char SW = 'S';
					float PRIMA,COMISION,SN;
					ifstream ARCHIVO("VENDEDOR.DAT");
					MARCO();
					if (ARCHIVO.fail())
					  {
					  gotoxy(26,12); cout << "ARCHIVO NO EXISTE......OJO"; getch();
					  SW = 'N';
					  }
					  else
					  {
					  gotoxy(35,6); cout << "LIQUIDACION";
					  F = 10;
					 CUADRO2();
					  }
				       while (( ! ARCHIVO.eof()) && ( SW != 'N'))
					    {
					    ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
					     if ( ARCHIVO.eof())
					     break;
					     gotoxy(31,F); cout <<setw(9)<< EMP.CEDULA;
					     gotoxy(5,F); cout << EMP.NOMBRE;
					     PRIMA = EMP.SB * EMP.TIEMPO / 100;
					     switch (EMP.LINEA) {
					       case 'T':
					       COMISION = LINEA_TV(EMP.VTAS);
					       break;
					       case 'C' :
					       COMISION = EMP.VTAS * 0.10;
					       break;
					       case 'E' :
					       if (EMP.VTAS > 3000000)
						  COMISION = EMP.VTAS * 0.13;
						  else
						   COMISION = 0;
					       case 'M' :
						 COMISION = LINEA_MUEBLES(EMP.VTAS);
						 break ;
					       case 'A' :
						COMISION = EMP.VTAS * 0.17;
						break;
					      }
					     SN = EMP.SB + PRIMA + COMISION;
					     gotoxy(41,F); cout << setw(8) << EMP.SB;
					     gotoxy(51,F);printf("%8.1f",PRIMA);
					     gotoxy(61,F); printf("%8.1f",COMISION);
					     gotoxy(70,F);  printf("%8.1f",SN);
					      if ( F <= 20)
					      F++;
					     else
					      {
					      gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
					      MARCO();
					     F=10;
					      }
					    }
					  gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
					  ARCHIVO.close();
					 }
					 /***********************************/
				      float LINEA_TV(float VTAS)
				      {
				      float COMISION;
				      if (VTAS <4000000)
					COMISION = 0;
					else
					 if (VTAS < 8000000)
					    COMISION = VTAS * 0.06;
					    else
					    if (VTAS <= 20000000)
					      COMISION = VTAS * 0.10;
					      else
					       COMISION = VTAS * 0.15;
					    return COMISION;
					    }
					    /*********************************/
					    float LINEA_MUEBLES(float VTAS)
					       {
					       float COMISION;
						if (VTAS <7000000)
						  COMISION = 0;
						  else
						    if (VTAS <= 9000000)
						      COMISION = VTAS * 0.09;
						      else
							COMISION = VTAS *0.12;
						      return COMISION;
						      }
						     void cuadro()
						     {
						     int i,k;
						     for(i=3;i<=76;i++)
						      {
						       delay(11);
						       gotoxy(i,3);cout<<"ў";
						       gotoxy(i,22);cout<<"ў";
							}
							for(k=4;k<=22;k++)
							  {
							  delay(11);
							  gotoxy(3,k);cout<<"ў";
							  gotoxy(76,k);cout<<"ў";
							   }
							  gotoxy(3,3);cout<<"ў";							  gotoxy(76,3);cout<<"ў";
							  gotoxy(3,22);  cout<<"ў";
							  gotoxy(76,22);cout<<"ў";
							   }
 /*************************************************************************/
      void  presentacion()
   {
   int k,m;
	 color();
	for (m = 1; m <= 80; m++)
	 {
	 textcolor(2);
	 gotoxy(m,1);cprintf("ѕ");
	 gotoxy(m,24);cprintf("ѕ");
	 delay(5);
	 }
	for (m = 1; m <= 24; m++)
	 {
	 textcolor(2);
	 gotoxy(1,m);cprintf("ѕѕ");
	 gotoxy(79,m);cprintf("ѕѕ");
	 delay(5);
	 }
       /*********************/

       for(k = 4; k <= 8; k++)
	 for(m = 20; m <= 60; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" ");
	   }
   for(k = 3; k <= 7; k++)
	    for(m = 18; m <= 58; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" ");
	  }
	/******************/

	  for(k = 11; k <= 17; k++)
	    for(m = 23; m <= 58; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" ");
	  }
	  for(k = 10; k <= 16; k++)
	    for(m = 21; m <= 56; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" ");

	  }
	  /********************/
	  for(k = 20; k <= 22; k++)
	    for(m = 20; m <= 60; m++)
	 {
	  textbackground(BLACK);
	  gotoxy(m,k);cprintf(" ");

	  }
	  for(k = 19; k <= 21; k++)
	    for(m = 18; m <= 58; m++)
	 {
	  textbackground(RED);
	  gotoxy(m,k);cprintf(" ");
	  }
	  /**********************/
	   textbackground(RED);
	  textcolor(WHITE);
	  gotoxy(23,4);cprintf("A L M A C E N   EL   M E J O R");
	  textcolor(2);
	  gotoxy(20,5);cout<<"PROCESO  DE  LIQUIDACION  DE  NOMINA";
	  LINEAS();
      }
       void LINEAS()
 {
 int k;
 textcolor(WHITE);
 gotoxy(18,3);cprintf("Щ");
 gotoxy(58,3);cprintf("Л");
 gotoxy(18,7);cprintf("Ш");
 gotoxy(58,7);cprintf("М");
    for(k = 4; k <= 6; k++)
      {
	gotoxy(18,k);cprintf("К");
	gotoxy(58,k);cprintf("К");
	}

	for(k = 19; k <= 57; k++)
	{
	gotoxy(k,3);cprintf("Э");
	gotoxy(k,7);cprintf("Э");
	}

	 gotoxy(21,10);cprintf("Щ");
	 gotoxy(21,16);cprintf("Ш");
	 gotoxy(56,10);cprintf("Л");
	 gotoxy(56,16);cprintf("М");
	   for(k = 11; k <= 15; k++)
	   {
	    gotoxy(21,k);cprintf("К");
	    gotoxy(56,k);cprintf("К");
	   }

	    for(k = 22; k <= 55; k++)
	    {
	    gotoxy(k,10);cprintf("Э");
	    gotoxy(k,16);cprintf("Э");
	   }
	   textcolor(WHITE);
	   gotoxy(18,19);cprintf("Щ");
	   gotoxy(58,19);cprintf("Л");
	   gotoxy(18,21);cprintf("Ш");
	   gotoxy(58,21);cprintf("М");

	gotoxy(18,20);cprintf("К");
	gotoxy(58,20);cprintf("К");
		for(k = 19; k <= 57; k++)
	{
	gotoxy(k,19);cprintf("Э");
	gotoxy(k,21);cprintf("Э");
	}

	textcolor(2);
  }
			   void CONTODO()
			   {
			    int F=10;
				   MARCO();
				   gotoxy(26,6); cout << "CONSULTA TODOS LOS EMPLEADOS";
				   CUADRO();
				   ifstream ARCHIVO("VENDEDOR.DAT");
				      while (! ARCHIVO.eof())
					{
					ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
					if ( ARCHIVO.eof())
					break;
					gotoxy(33,F);cout<<setw(9)<<EMP.CEDULA;
					gotoxy(5,F); cout << EMP.NOMBRE;
					gotoxy(43,F); cout << setw(8) << EMP.SB;
					gotoxy(55,F); cout << setw(3) << EMP.TIEMPO;
					gotoxy(63,F); cout << EMP.LINEA;
					gotoxy(67,F); cout << setw(10) << EMP.VTAS;
					if( F <= 20 )
					    F++;
                                          else					 
					 {
					 gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
					 MARCO();
					 F=10;
					 }
					 }
					 gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
					}
	  void color()
	   {

      int m, k, j=1;
	  for(k =1 ; k <= 80; k++)
	    for(m =1 ; m <= 24; m++)
	 {
	  textcolor(j);
	  gotoxy(k,m);cprintf("В");delay(1);
	  j+=38;
	  if(j>250)
	  j=1;
	  }
       }




