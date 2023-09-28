//****************ARCHIVOS*******************************


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
void LINEAS();
void PANTALLAZO();
void MARCO();
void nela();
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
	     }
	 }
int MENU()
  {
  presentacion();
  int W;
  gotoxy(28,6); cout <<  "M E N U  P I N C I P A L";
  gotoxy(25,12); cout << "1.CAPTURA DE DATOS";
  gotoxy(25,13); cout << "2.CONSULTA DE DATOS";
  gotoxy(25,14); cout << "3.LIQUIDACION";
  gotoxy(25,15); cout << "4.SALIR DEL PROGRAMA";
  do {
     gotoxy(22,20); cout << "SELECIONE UNA OPCION ==> "; cin >> W;
     }while ((W<1)||(W>4));
  return W;
 }
 int SUBMENU()
   {
   presentacion();
   int j;
   textbackground(RED);
   gotoxy(28,6); cout <<  " C O N S U L T A  ";
   gotoxy(23,12); cout << "1.INDIVIDUAL POR EMPLEADO";
   gotoxy(23,13); cout << "2.TODOS LOS EMPLEDOS";
   gotoxy(23,14); cout << "3.SALIR DEL SUBMENU";
   do {
      gotoxy(20,20); cout << "SELECCIONE UNA OPCCION ==>  ";cin >> j;
	    } while ((j<1)||(j>3));
   return j;
  }
void PANTALLAZO()
 {
 gotoxy(15,9); cout << "CEDULA                :[          ]";
 gotoxy(15,10); cout <<"NOMBRES Y APELLIDOS   :[                      ]";
 gotoxy(15,11); cout <<"TIEMPO SERVICIO (A¥OS):[   ]";
 gotoxy(15,12); cout <<"ASIGNACION BASICA     :[         ]";
 gotoxy(15,13); cout <<"LINEA DE ARTICULO     :[ ]";
 gotoxy(15,14); cout <<"VALOR DE LAS VENTAS   :[          ]";
 }
   void MARCO()
{
 int I;
       clrscr();
       textcolor(WHITE);
       textbackground(BLUE);
       gotoxy (24,4);cout <<"R E L O G E R I A   N A M E G O";
       gotoxy (23,5);cout <<"PROCESO DE LIQUIDACION DE NOMINAS";
       for (I=2;I<=79;I++)
	  {
	    gotoxy (I,2); cout<<"õ";
	    gotoxy (I,24); cout<<"õ";
	   }
       for (I=3;I<=23;I++)
	  {
	    gotoxy (2,I); cout<<"õõ";
	    gotoxy (78,I); cout<<"õõ";
	   }
       }
//**********************************************************

     void CAPTURA()
	{
	char CAP='S';
	ofstream ARCHIVO("C:\VENDE.DAT",ios::app);
	while ( CAP == 'S')
	     {
	     MARCO();
	     PANTALLAZO();
	     gotoxy(26,6); cout << "C A P T U R A  DE  D A T O S";
	     gotoxy(39,9); cin >> EMP.CEDULA;
	     gotoxy(39,10); gets(EMP.NOMBRE);
	     gotoxy(39,11); cin >> EMP.TIEMPO;
	     gotoxy(39,12); cin >> EMP.SB;
	     EMP.LINEA = LINEA_VENTA();
	     gotoxy(39,14); cin >> EMP.VTAS;
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
		   gotoxy(39,13);cout<<" ";
		   gotoxy(7,22);cout<<"  -> TV    -> Computador,   -> Estufas,   -> Muebles,   -> Adornos";
		   textcolor(15 + 128);
		   gotoxy(7,22);cprintf("T");
		   gotoxy(16,22);cprintf("C");
		   gotoxy(33,22);cprintf("E");
		   gotoxy(47,22);cprintf("M");
		   gotoxy(61,22);cprintf("A");
		   gotoxy(39,13);LINEA=getch();
		   textcolor(2);
		  LINEA=  toupper(LINEA);
		  gotoxy(39,13);cout<< LINEA;
		  textbackground(RED);
		  gotoxy(5,22); cprintf("                                                                    ");
		  
		  } while ((LINEA!='T')&&(LINEA!='C')&&(LINEA!='A')&&(LINEA!='E')&&(LINEA!='M'));
		return LINEA;
	       }

	 void  CUADRO()
	     {
	     int n,i ;
    textbackground(0+15);
    gotoxy(4,8);cprintf("                                                                       ");
    textcolor(RED);
    gotoxy(5,8);cprintf("NOMBRE                     CEDULA     S.BASICO  TIEMPO  LINEA  VAL.VENTAS");
	      for (i=10; i<=22; i++)
	       for (n=4; n<=77; n++)
	       {
	       textbackground(BLUE);
	       gotoxy(n,i);cprintf(" ");
	       textcolor(15);
	       }
	 }

   /**************PRESENTACION DE DATOS DE LIQUIDACION GENERAL ********************************************************/
	 void  CUADRO2(void)
	     {
	     int n,i ;
	      textbackground(15+0);
	      gotoxy(4,8);cprintf("                                                                          ");
	      textcolor(RED);						     
	      gotoxy(5,8);cprintf("NOMBRE                     CEDULA   S.BASICO    PRIMA   COMISION   S.NETO");
	      textcolor(15);
	      for (i=4; i<=77; i++)
		  for (n=10; n<=22; n++)
		 {
		 textbackground(BLUE);
		 gotoxy(i,n);cprintf(" ");
		 }
	      
	}
	/***********************************************************/
	       void CONSULTA()
		  {
		  long CEDULA;
		  int F,SUB = 1;
		   ifstream ARCHIVO("C:\VENDE.DAT");
		  if (ARCHIVO.fail())
		    {		     
		    nela();
		    gotoxy(26,12); cout << "ARCHIVO NO EXISTE.....OJO"; 
		    gotoxy(26,20);cout<<"<<PRESIONE CUALQUIER TECLA>>";getch();
		    SUB = 3;
		    }
		    ARCHIVO.close();
		  while (SUB != 3)
		      {
		       SUB=SUBMENU();
		      switch ( SUB ) {
			 case 1:
			   ifstream ARCHIVO("C:\VENDE.DAT");
			  MARCO();
			  gotoxy(30,6); cout << "CONSULTA POR EMPLEADO";
			  textbackground(BLUE);
			  gotoxy(39,9);cprintf("          ");
			  gotoxy(15,9); cout << "CEDULA                :[          ]";
			  gotoxy(39,9); cin >> CEDULA;
			  while (! ARCHIVO.eof() )
			       {
			       ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
			       if (CEDULA == EMP.CEDULA)
				  {
				   PANTALLAZO();
				   gotoxy(39,9); cout << EMP.CEDULA;
				   gotoxy(39,10); cout << EMP.NOMBRE;
				   gotoxy(39,11); cout << EMP.TIEMPO;
				   gotoxy(39,12); cout << EMP.SB;
				   gotoxy(39,13); cout << EMP.LINEA;
				   gotoxy(39,14); cout << EMP.VTAS;
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
					ifstream ARCHIVO("C:\VENDE.DAT");
					nela();
					if (ARCHIVO.fail())
					  {
					  gotoxy(27,5);cout<<"<<PROCESO DE LIQUIDACION>>";
					  gotoxy(26,12); cout << "ARCHIVO NO EXISTE......OJO"; 
					  SW = 'N';
					  }
					  else
					  {
					  
					  gotoxy(27,5); cout << "PROCESO DE LIQUIDACION";
					  F = 10;
					 CUADRO2();
					  }
				       while (( ! ARCHIVO.eof()) && ( SW != 'N'))
					    {
					    ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
					     if ( ARCHIVO.eof())
					     break;
					     gotoxy(30,F); cout <<setw(9)<< EMP.CEDULA;
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
						   break;
					       case 'M' :
						 COMISION = LINEA_MUEBLES(EMP.VTAS);
						 break ;
					       case 'A' :
						COMISION = EMP.VTAS * 0.17;
						break;
					      }
					     SN = EMP.SB + PRIMA + COMISION;
					     gotoxy(41,F); cout << setw(8) << EMP.SB;
					     gotoxy(51,F);cout<<setw(8)<< PRIMA;
					     gotoxy(61,F); cout<< setw(8) << COMISION;
					     gotoxy(70,F);cout<< setw(8) << SN;
					      if ( F <= 20)
					      F++;
					     else
					      {
					      gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; getch();
					      textbackground(RED);
					      MARCO();
					      CUADRO2();
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
						       delay(5);
						       gotoxy(i,3);cout<<"þ";
						       gotoxy(i,22);cout<<"þ";
							}
							for(k=4;k<=22;k++)
							  {
							  delay(5);
							  gotoxy(3,k);cout<<"þ";
							  gotoxy(76,k);cout<<"þ";
							   }
							  gotoxy(3,3);cout<<"þ";							  gotoxy(76,3);cout<<"þ";
							  gotoxy(3,22);  cout<<"þ";
							  gotoxy(76,22);cout<<"þ";
							   }
 /*************************************************************************/
      void  presentacion()
   {
   
   clrscr();
    int k,m;

       
       for (m = 1; m <= 80; m++)
       for (k = 1; k <= 24; k++)
       {
       textbackground(0);
	 textcolor(15);
	 gotoxy(m,k);cprintf("²");
	 
	 }

	for (m = 1; m <= 80; m++)
	 {
	 textcolor(2);
	 gotoxy(m,1);cprintf("õ");
	 gotoxy(m,24);cprintf("õ");
	 delay(5);
	 }
	for (m = 1; m <= 24; m++)
	 {
	 textcolor(2);
	 gotoxy(1,m);cprintf("õõ");
	 gotoxy(79,m);cprintf("õõ");
	 textcolor(15);
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
	  gotoxy(25,4);cprintf("R E L O G E R I A  N A M E G O  ");
	  textcolor(2);
	  gotoxy(20,5);cout<<"PROCESO  DE  LIQUIDACION  DE  NOMINA";
	  textcolor(15);
	  LINEAS();
      }
       void LINEAS()
 {
 int k;
 textcolor(WHITE);
 gotoxy(18,3);cprintf("É");
 gotoxy(58,3);cprintf("»");
 gotoxy(18,7);cprintf("È");
 gotoxy(58,7);cprintf("¼");
    for(k = 4; k <= 6; k++)
      {
	gotoxy(18,k);cprintf("º");
	gotoxy(58,k);cprintf("º");
	}

	for(k = 19; k <= 57; k++)
	{
	gotoxy(k,3);cprintf("Í");
	gotoxy(k,7);cprintf("Í");
	}

	 gotoxy(21,10);cprintf("É");
	 gotoxy(21,16);cprintf("È");
	 gotoxy(56,10);cprintf("»");
	 gotoxy(56,16);cprintf("¼");
	   for(k = 11; k <= 15; k++)
	   {
	    gotoxy(21,k);cprintf("º");
	    gotoxy(56,k);cprintf("º");
	   }

	    for(k = 22; k <= 55; k++)
	    {
	    gotoxy(k,10);cprintf("Í");
	    gotoxy(k,16);cprintf("Í");
	   }
	   textcolor(WHITE);
	   gotoxy(18,19);cprintf("É");
	   gotoxy(58,19);cprintf("»");
	   gotoxy(18,21);cprintf("È");
	   gotoxy(58,21);cprintf("¼");

	gotoxy(18,20);cprintf("º");
	gotoxy(58,20);cprintf("º");
		for(k = 19; k <= 57; k++)
	{
	gotoxy(k,19);cprintf("Í");
	gotoxy(k,21);cprintf("Í");
	}

	textcolor(WHITE);
  }
			   void CONTODO()
			   {
			    int F=10;
				   MARCO();
				   gotoxy(26,6); cout << "CONSULTA TODOS LOS EMPLEADOS";
				   CUADRO();
				   ifstream ARCHIVO("C:\VENDE.DAT");
				      while (! ARCHIVO.eof())
					{
					ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
					if ( ARCHIVO.eof())
					break;
					gotoxy(30,F);cout<<setw(9)<<EMP.CEDULA;
					gotoxy(5,F); cout << EMP.NOMBRE;
					gotoxy(43,F); cout << setw(8) << EMP.SB;
					gotoxy(55,F); cout << setw(3) << EMP.TIEMPO;
					gotoxy(63,F); cout << EMP.LINEA;
					gotoxy(67,F); cout << setw(10) << EMP.VTAS;
					 
					if( F <= 20 )					
					F++; 
					else
					{
					
					 gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR";getch(); 
					 textbackground(RED);
					 MARCO();
					 CUADRO();
					 F=10;									 
					 }
					 
					{
					gotoxy(21,23); cout << "PULSE CUALQUIER TECLA PARA CONTINUAR"; 
					}
					}
					getch();
					}
					
	  void nela()
	   {
	   clrscr();
	   int m;
	  for(m =1 ; m <= 80; m++)
	  {
	   gotoxy(m,1);cout<<"²";
	   gotoxy(m,24);cout<<"²";
	   delay(3);
	   }
	    for(m =1 ; m <= 24; m++)
	    {
	    gotoxy(1,m);cout<<"²²";
	    gotoxy(79,m);cout<<"²²";
	    delay(3);
            textcolor(WHITE);
	    gotoxy(25,4);cprintf("R E L O G E R I A  N A M E G O  ");
	    textcolor(2);
	    gotoxy(29,5);cout<<"PROCESO  DE  CONSULTA";
	    }
	 }
	 




