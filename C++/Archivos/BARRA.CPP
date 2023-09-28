//************ARCHIVOS*******************

# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# include <stdio.h>
# include <fstream.h>
# include <iomanip.h>
# include <dos.h>
# include <time.h>
void PRESENTA();
void NAHEBER();
void CONTODO();
void MEJOR();
void LINEAS();
void PANTALLAZO();
void PANTALLAZO1();
void MARCO();
void NELA();
int MENU();
int SUBMENU();
void CAPTURA();
void CONSULTA();
struct REGISTRO {
     long CODIGO;
     char NOMBRE[30];
     char ASIGNATURA[15];
     float NOTA1;
     float NOTA2;
     float NOTA3;
	 } ALU;

     void main(void)
	 {

	 clrscr();
	 char OPCION='S';
	 int SW;
	 //float PROME1;
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
	      OPCION='N';
	      break;
	      }
	     }
	  }

int MENU()
  {
  PRESENTA();
  int W;
  textcolor(2);
  gotoxy(26,6); cprintf("M E N U  P R I N C I P A L");
  textcolor(15);
  gotoxy(21,5); cout<<"L I Q U I D A C I O N  DE  N O T A S";
  gotoxy(25,12); cout << "1.CAPTURA DE DATOS";
  gotoxy(25,13); cout << "2.CONSULTA DE DATOS";
  gotoxy(25,14); cout << "3.SALIR DEL PROGRAMA";
  do {
     textcolor(2);
     gotoxy(22,20); cprintf("SELECIONE UNA OPCION ==> "); cin >> W;
     textcolor(15);
     }while ((W<1)||(W>3));
  return W;
 }
 int SUBMENU()
   {
   PRESENTA();
   int j;
   textbackground(RED);
   textcolor(2);
   gotoxy(22,6); cprintf("P R O C E S O  D E  C O N S U L T A");
   textcolor(15);
   gotoxy(23,12); cout << "1.INDIVIDUAL POR ALUMNO";
   gotoxy(23,13); cout << "2.TOTAL APROBADOS";
   gotoxy(23,14); cout << "3.TOTAL REPROBADOS ";
   gotoxy(23,15); cout << "4.SALIR DEL SUBMENU";
   do {
      textcolor(2);
      gotoxy(20,20); cprintf("SELECCIONE UNA OPCCION ==>  ");cin >> j;
      textcolor(15);
	    } while ((j<1)||(j>4));
   return j;
  }
void PANTALLAZO()
 {
 gotoxy(15,9); cout << "CODIGO                :[          ]";
 gotoxy(15,10); cout <<"NOMBRES Y APELLIDOS   :[                        ]";
 gotoxy(15,11); cout <<"ESCRIBA LA ASIGNATURA :[               ]";
 gotoxy(15,12); cout <<"DIGITE LA NOTA #1     :[   ]";
 gotoxy(15,13); cout <<"DIGITE LA NOTA #2     :[   ]";
 gotoxy(15,14); cout <<"DIGITE LA NOTA #3     :[   ]";
 }
 void PANTALLAZO1()
 {
 gotoxy(15,9); cout << "CODIGO                :[          ]";
 gotoxy(15,10); cout <<"NOMBRES Y APELLIDOS   :[                      ]";
 gotoxy(15,11); cout <<"LA ASIGNATURA ES      :[                      ]";
 gotoxy(15,12); cout <<"LA PRIMERA NOTA ES    :[    ]";
 gotoxy(15,13); cout <<"LA SEGUNDA NOTA ES    :[    ]";
 gotoxy(15,14); cout <<"LA TERCERA NOTA ES    :[    ]";
 }
   void MARCO()
{
 int I;
       clrscr();
       textbackground(RED);
       textcolor(2+128);
       gotoxy (21,4);cprintf("U N I V E R S I D A D   N A M E G O");
       textcolor(15);
       gotoxy (23,5);cout <<"PROCESO DE LIQUIDACION DE NOTAS";
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
	int h,CONT=0;
	ofstream ARCHIVO("SO.DAT",ios::app);
	while ( CAP == 'S')
	     {
	     MARCO();
	     PANTALLAZO();
	     textbackground(RED);
	     textcolor(2);
	     gotoxy(26,6); cprintf("C A P T U R A  DE  D A T O S");
	     textcolor(15);
	     gotoxy(39,9); cin >> ALU.CODIGO;
	     gotoxy(39,10); gets(ALU.NOMBRE);
	     gotoxy(39,11); gets(ALU.ASIGNATURA);
	     gotoxy(39,12); cin >> ALU.NOTA1;
	     gotoxy(39,13); cin>> ALU.NOTA2;
	     gotoxy(39,14); cin>> ALU.NOTA3;
	     ARCHIVO.write((char *) &ALU, sizeof(REGISTRO));

	     do {
		textcolor(2);
		gotoxy(23,20); cprintf("DESEA CONTINUAR CAPTURANDO S/N ");
		textcolor(15);
		CAP=getch();
		CAP=toupper(CAP);
		} while ((CAP!='S')&&(CAP!='N'));
	      }

	      gotoxy(23,20);cout<<"                                  ";
	      gotoxy(32,19);cout<<"ALMACENANDO  DATOS";
	      textcolor(15);
	      gotoxy(30,20);cprintf("²²²²²²²²²²²²²²²²²²²²²");
	      for(h = 30; h <= 50; h++)
	      {
	      gotoxy(25,20),cout<<"%";
	      gotoxy(26,20);cout<<CONT;
	      textbackground(BLUE);
	      gotoxy(h,20);cprintf(" ");
	      textbackground(0);
	      delay(500);
	      CONT+=5;
	      }
	      delay(1000);

	     ARCHIVO.close();
	    }

 void  CUADRO()
    {
    int n,i ;
    textbackground(0+15);
    gotoxy(4,8);cprintf("                                                                          ");
    textcolor(RED);
    gotoxy(5,8);cprintf("CODIGO   NOMBRE            ASIGNATURA     NOTA#1  NOTA#2  NOTA#3   PROME");
       for (i=10; i<=22; i++)
       for (n=4; n<=77; n++)
	{
       textbackground(BLUE);
       gotoxy(n,i);cprintf(" ");
       textcolor(15);
	}
      }
 /***********************************************************/
 void CONSULTA()
   {
   long CODIGO;
   int F,SUB = 1;
   ifstream ARCHIVO("SO.DAT");
   if (ARCHIVO.fail())
     {
     NAHEBER();
     textcolor(2+128);
     gotoxy(29,12); cprintf("<<ARCHIVO NO EXISTE>>");
     textcolor(15);
     gotoxy(26,20);cout<<"<<PRESIONE CUALQUIER TECLA>>";getch();
     SUB = 4;
     }
     ARCHIVO.close();
      while (SUB != 4)
	{
	SUB=SUBMENU();
	switch ( SUB ) {
      case 1:
       ifstream ARCHIVO("SO.DAT");
       MARCO();
       textcolor(2);
       gotoxy(28,6); cprintf("CONSULTA POR EMPLEADO");
       textcolor(15);
       gotoxy(15,9); cout << "CODIGO ==>       :[          ]";
       gotoxy(34,9); cin >> CODIGO;
       while (! ARCHIVO.eof() )
	{
	ARCHIVO.read((char *) &ALU, sizeof(REGISTRO));
	if (CODIGO == ALU.CODIGO)
	{
	 PANTALLAZO1();
	 gotoxy(39,9); cout << ALU.CODIGO;
	 gotoxy(39,10); cout << ALU.NOMBRE;
	 gotoxy(39,11); cout << ALU.ASIGNATURA;
	 gotoxy(39,12); cout << ALU.NOTA1;
	 gotoxy(39,13); cout << ALU.NOTA2;
	 gotoxy(39,14); cout << ALU.NOTA3;
	 textcolor(2);
	 gotoxy(21,22); cprintf("PULSE CUALQUIER TECLA PARA CONTINUAR "); getch();
	 textcolor(15);
	   break;
	 }
       }
      if (ARCHIVO.eof())
	 {
	 textcolor(2+128);
	 gotoxy(28,12); cprintf("ESTE EMPLEADO NO EXISTE");
	 textcolor(15);
	 gotoxy(27,21);cout<<"por favor presione <ENTER> ";
	 textcolor(2+128);
	 gotoxy(46,21);cprintf("<ENTER>");
	 textcolor(15);
	 getch();
	 }
	 ARCHIVO.close();
	   break;
       case 2:
	  CONTODO();
	  break;
       case 3:
	  MEJOR();
	  break;

      }
   }
 }
 /*********************************/
 void  PRESENTA()
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
	  textcolor(2+128);
	  gotoxy(22,4);cprintf("U N I V E R S I D A D  N A M E G O  ");
	  textcolor(15);
	  gotoxy(21,5);cout<<"L I Q U I D A C I O N  DE  N O T A S";
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
   float PROME=0;
   int F=10;
   MARCO();
   textcolor(2);
   gotoxy(26,6); cprintf("CONSULTA TODOS LOS ALUMNOS");
   textcolor(15);
   CUADRO();
   ifstream ARCHIVO("SO.DAT");
   while (! ARCHIVO.eof())
     {
     ARCHIVO.read((char*) &ALU, sizeof(REGISTRO));
     if ( ARCHIVO.eof())
      break;
      PROME=(ALU.NOTA1*0.3+ALU.NOTA2*0.3+ALU.NOTA3*0.4);
      if (PROME >= 3)
      {
      gotoxy(5,F);cout<<setw(5)<<ALU.CODIGO;
      gotoxy(14,F); cout << ALU.NOMBRE;
      gotoxy(32,F); cout <<  ALU.ASIGNATURA;
      gotoxy(49,F); cout << ALU.NOTA1;
      gotoxy(57,F); cout << ALU.NOTA2;
      gotoxy(65,F); cout <<  ALU.NOTA3;
      gotoxy(73,F);cout<<  PROME;

	if( F <= 20 )
	 F++;

	 else
	  {

	   textbackground(RED);
	   textcolor(2);
	   gotoxy(21,23); cprintf("PULSE CUALQUIER TECLA PARA CONTINUAR");getch();
	   textcolor(15);
	   textbackground(RED);
	   MARCO();
	   CUADRO();
	    F=10;
	   }

	 {
	 }
	  textbackground(RED);
	  textcolor(2);
	  gotoxy(21,23); cprintf("PULSE CUALQUIER TECLA PARA CONTINUAR");
	  textcolor(15);
	  }

	 }
         getch();
	}

  void MEJOR()
   {
   float PROME=0;
   int F=10;

   MARCO();
   textcolor(2);
   gotoxy(22,6); cprintf("CONSULTA LOS ALUMNOS QUE REPROBARON");
   textcolor(15);
   CUADRO();
   ifstream ARCHIVO("SO.DAT");
   while (! ARCHIVO.eof())
     {
     ARCHIVO.read((char*) &ALU, sizeof(REGISTRO));
     PROME=(ALU.NOTA1*0.3+ALU.NOTA2*0.3+ALU.NOTA3*0.4);
     if ( ARCHIVO.eof())
	break;

      if (PROME < 3  )
      {
      gotoxy(5,F);cout<<setw(5)<<ALU.CODIGO;
      gotoxy(14,F); cout << ALU.NOMBRE;
      gotoxy(32,F); cout <<  ALU.ASIGNATURA;
      gotoxy(49,F); cout << ALU.NOTA1;
      gotoxy(57,F); cout << ALU.NOTA2;
      gotoxy(65,F); cout <<  ALU.NOTA3;
      gotoxy(73,F); cout<<  PROME;

      if( F <= 20 )
	 F++;

	 else
	  {

	   textbackground(RED);
	   textcolor(2);
	   gotoxy(21,23); cprintf("PULSE CUALQUIER TECLA PARA CONTINUAR");getch();
	   textcolor(15);
	   textbackground(RED);
	   MARCO();
	   CUADRO();
	    F=10;
	   }

	 {
	 }
	  textbackground(RED);
	  textcolor(2);
	  gotoxy(21,23); cprintf("PULSE CUALQUIER TECLA PARA CONTINUAR");
	  textcolor(15);
	  }

	 }
	 getch();

	}
void NELA()
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
	    textcolor(2+128);
	    gotoxy(22,4);cprintf("U N I V E R S I D A D  N A M E G O  ");
	    textcolor(15);
	    gotoxy(29,5);cout<<"PROCESO  DE  CONSULTA";
	    }
	 }


void NAHEBER()
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
	    textcolor(2);
	    gotoxy(22,4);cprintf("U N I V E R S I D A D  N A M E G O  ");
	    textcolor(15);
	    gotoxy(29,5);cout<<"PROCESO  DE  CONSULTA";
	    }
	 }

