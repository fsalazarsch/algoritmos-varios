//*********************archivo********************************


#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>

void MARCO();
void recuadro(int x, int x2, int y, int y2, int z);
void MARCO_MENU();
int TECLA2();
void ENTRADA(int z);
void MENU_CONSULTA();
void MENU_PRINCIPAL();
void MENU_CAPTURA();
void MARCO_MOSTRAR();
void CAPTURA();
void CONSULTA();
char LINEA_VENTA();
void MARCO_FINAL();
void MES(int coli, int colf,int fil);
int TECLA();
void INDEXADO();
void  CUADRO(int ci, int cf, int fi, int ff);

struct REGISTRO{
 float CEDULA;
 char NOMBRE[20];
 float SB;
 int TIEMPO;
 char LINEA;
 float VTAS;
} EMP;


main()
{
 char opcion='S';
 int sw,op;
 ENTRADA(1);
 while(opcion=='S')
 {
  //textmode(C4350);  //modo grafico pequeЄo
  clrscr();
  MARCO_MENU();
  MENU_PRINCIPAL();
  op=TECLA();
  switch(op){
  case 1:
   CAPTURA();
   break;
  case 2:
   CONSULTA();
   break;
  case 4:
    ENTRADA(1);
    exit(0);
  case 5:
   INDEXADO();
 }//EL SWICHE
} // EL WHILE
} // EL PROGRAMA

void recuadro(int x, int x2, int y, int y2, int z)
{
 int fila, columna;
 if(z==1)
 {    
  for (columna=y; columna<=y2; columna++)
      {
	gotoxy(columna,x); cprintf("Ф");
	gotoxy(columna,x2); cprintf("Ф");
      }
  for (fila=x; fila<=x2; fila++)
      {
	gotoxy(y,fila); cprintf("Г");
	gotoxy(y2,fila); cprintf("Г");
      }
gotoxy(y,x); cprintf("к");
gotoxy(y2,x); cprintf("П");
gotoxy(y,x2); cprintf("Р");
gotoxy(y2,x2); cprintf("й");
}
 else

   for(fila=x; fila<=x2; fila++)
     for(columna=y; columna<=y2; columna++)
      {
       gotoxy(columna,fila); cprintf("л");
      }
}


void MARCO_MENU()
{
int x,y;
textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(x=1; x<=24; x++)
  for(y=1; y<=80; y++)
  {
   gotoxy(y,x); cout <<"В";
  }

textcolor(BLUE); recuadro(3,5,5,75,2);
textcolor(RED); recuadro(2,4,4,74,2);
textcolor(WHITE); textbackground(RED);recuadro(2,4,4,74,1);
textcolor(BLUE); recuadro(21,23,5,75,2);
textcolor(RED); recuadro(20,22,4,74,2);
textcolor(WHITE); textbackground(RED); recuadro(20,22,4,74,1);
textcolor(BLUE); recuadro(9,18,25,55,2);
textcolor(RED); recuadro(8,17,24,54,2);
textcolor(WHITE);textbackground(RED);recuadro(8,17,24,54,1);
textcolor(15+128);
gotoxy(28,3); cprintf("ELECTROMARCAS DEL CESAR");
textcolor(15);
}


void MENU_PRINCIPAL()
{
gotoxy(33,10); cprintf("MENU PRINCIPAL");
gotoxy(28,12); cprintf("1. CAPTURA DE EMPLEADOS");
gotoxy(28,13); cprintf("2. CONSULTA DE EMPLEADOS");
gotoxy(28,14); cprintf("3. LIQUIDACION EMPLEADOS");
gotoxy(28,15); cprintf("4. SALIR DEL PROGRAMA(ESC)");
gotoxy(5,21); cprintf("Utilice las teclas(%c%c) y presione Enter,Si necesita ayuda precione F1",24,25);
}


int TECLA()
{
int op;
char tecla,tes;
gotoxy(27,12); cprintf("");
gotoxy(27,12);
_setcursortype(_NOCURSOR);
do{
     tecla=getch();
     if(tecla==27)
     {
       ENTRADA(1);
       exit(0);
      }
      //pregunto por la f1
      else if(tecla==59){clrscr();MARCO_MENU();
      gotoxy(35,9);cprintf("COMMANDOS");
      gotoxy(27,11);cprintf(" F2ЏЏ para captura");
      gotoxy(27,12);cprintf(" F3ЏЏ para consulta");
      gotoxy(27,13);cprintf(" F4ЏЏ para liquidacion");
      gotoxy(27,14);cprintf(" F5ЏЏ para consulta indexada");
      gotoxy(27,15);cprintf(" ECSЏЏ para salir de ");
      gotoxy(34,16);cprintf("los menus");
      gotoxy(27,21);cprintf("INGENIERO ALVARO A CARRILLO ARAUJO");
      tecla=getch();
       if(tecla==27)//para salir de la ayuda
	break;     //y enviar al menu principal
      }

      //pregunto por la f2
      else if(tecla==60){op=1;return op;}
      //pregunto por la f3
      else if(tecla==61){op=2;return op;}
       //pregunto por la f4   '>'
       else if(tecla==62){op=3;return op;}
       //pregunto por la f5    '?'
       else if(tecla==63){op=5;return op;}

     else if(tecla==80)
      {
	cout <<" ";
	if(wherey()==12)
	  {
	   gotoxy(27,wherey()+1); cprintf("");
	   gotoxy(27,wherey());
	  }
	    else 
	     if(wherey()==15)
	      {
	       gotoxy(27,12); cprintf("");
	       gotoxy(27,12);
	      }else
	       {
		  gotoxy(27,wherey()+1); cprintf("");
		  gotoxy(27,wherey());

	       }
    }

   else if(tecla==72)
    {
     cout<<" ";
       if(wherey()==15)
       {
	gotoxy(27,wherey()-1); cprintf("");
	gotoxy(27,wherey());
       }else
	 if(wherey()==12)
	 {
	  gotoxy(27,15); cprintf("");
	  gotoxy(27,15);
	 }else
	 {
	  gotoxy(27,wherey()-1); cprintf("");
	  gotoxy(27,wherey());
	 }
    }
}while(tecla!=13);

op=wherey();
if(op==12)
op=1;
if(op==13)
op=2;
if(op==14)
op=3;
if(op==15)                                                          
op=4;

return op;
}


void MARCO_MOSTRAR()
{
int x,y;
textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(x=1; x<=24; x++)
  for(y=1; y<=80; y++)
  {
   gotoxy(y,x); cout <<"В";
  }

textcolor(BLUE); recuadro(2,4,5,75,2);
textcolor(RED); recuadro(1,2,4,74,2);
textcolor(WHITE); textbackground(RED);recuadro(1,3,4,74,1);

//textcolor(BLUE); recuadro(22,24,5,75,2);
textcolor(RED); recuadro(21,22,4,74,2);
textcolor(WHITE); textbackground(RED); recuadro(21,23,4,74,1);

textcolor(BLUE); recuadro(7,19,5,75,2);
textcolor(RED); recuadro(6,18,4,74,2);
textcolor(WHITE);textbackground(RED);recuadro(6,18,4,74,1);
textcolor(15+128);
gotoxy(28,2); cprintf("ELECTROMARCAS DEL CESAR");
textcolor(15);
}


void MENU_CAPTURA()
{
  int tecla;
      MARCO_MOSTRAR();
    gotoxy(28,6); cprintf("MENU CAPTURA DE EMPLEADO");
    gotoxy(10,7); cprintf("NOMBRE Y APELLIDO  :");
    gotoxy(10,9); cprintf("CEDULA             :");
    gotoxy(10,11); cprintf("ASIGNACION BASICA  :");
    gotoxy(10,13); cprintf("TIEMPO DE SERVICIO :");
    gotoxy(10,15); cprintf("LINEA ARTICULO     :");
    gotoxy(10,17); cprintf("VALOR EN LAS VENTAS:");
    textbackground(BLUE);
    MES(30,50,7);//NOMBRE 1.columna inicial 2.columna final 3.fila
    _setcursortype(_NORMALCURSOR);
    MES(30,42,9);//CEDULA
    MES(30,42,11);//ASIG BASICA
    MES(30,32,13);//TIEMPO DE SERVICIO
    MES(30,31,15);//LINEA DE ARTICULO
    MES(30,42,17);//VALOR DE LAS VENTAS
    gotoxy(30,7);
  }


void MES(int coli, int colf,int fil)
{
 int p;
 for(p=coli;p<colf;p++){gotoxy(p,fil);cprintf(" ");}
}


void CAPTURA()
{
 char tecla;
 int CONT=0,h;
  char cap='S';
 ofstream ARCHIVO("C:\ALVARO.DAT",ios::app);
 while(cap=='S')
  {
    MENU_CAPTURA();
   gotoxy(30,7); gets(EMP.NOMBRE);
   gotoxy(30,9); cin >>EMP.CEDULA;
   gotoxy(30,11); cin >>EMP.SB;
   gotoxy(30,13); cin >>EMP.TIEMPO;
   EMP.LINEA=LINEA_VENTA();
   gotoxy(30,17); cin >>EMP.VTAS;
   ARCHIVO.write((char *)&EMP,sizeof(REGISTRO));

   _setcursortype(_NOCURSOR);
     gotoxy(10,22);cout<<"ALMACENANDO  DATOS";
	      textcolor(15);
	      gotoxy(30,22);cprintf("ВВВВВВВВВВВВВВВВВВВВВ");
	      for(h = 30; h <= 50; h++)
	      {
	      gotoxy(55,22),cout<<"%";
	      gotoxy(52,22);cout<<CONT;
	      textbackground(BLUE);
	      gotoxy(h,22);cprintf(" ");
	      textbackground(0);
	      delay(100);
	      CONT+=5;
	      }
	      delay(1000);
	      textbackground(RED);
	      gotoxy(10,22); cprintf("                                               ");
	      _setcursortype(_NORMALCURSOR);

     do {
       gotoxy(20,22);cprintf("DESEA SEGUIR CAPTURANDO EMPLEADOS (S/N)  [_]");
       gotoxy(62,22);cap=getch();
       cap=toupper(cap);
       }while(cap!='N' && cap!='S');
  }
 ARCHIVO.close(); //para cerrar el while
} //para cerrar la funcion



char LINEA_VENTA()
 {
  char linea;
  do {
       gotoxy(5,22); cprintf("T->Televisores  C->Computadores  E-> Estufas A-> Adornos  M-> Muebles");
       gotoxy(30,15); cin >>linea;
       linea=toupper(linea);
      }while(linea!='C' && linea!='T' && linea!='M' && linea!='A' && linea!='E');
       gotoxy(5,22);textbackground(RED);cprintf("                                                                     ");
   return linea;
}

 void CONSULTA()
 {
  float CED;
  int f,sub=1,op2,F=10;
  char sw='S',seguir='S';
ifstream ARCHIVO("C:\ALVARO.DAT");
 if (ARCHIVO.fail())
  {
    MARCO_MOSTRAR();
    gotoxy(22,12);textcolor(4+125);cprintf("ARCHIVO NO EXISTE.....OJO!");getch();
    sub=3;
  }
 while(sub != 3)
 {
  MENU_CONSULTA();
  _setcursortype(_NOCURSOR);
  op2=TECLA2();
    switch(op2) {
     case 1:
     seguir='S';
      while(seguir=='S')
      {
      sw='S';
      ifstream ARCHIVO("C:\ALVARO.DAT");
      MARCO_MOSTRAR();
      _setcursortype(_NORMALCURSOR);
     gotoxy(28,8); cprintf("MENU CONSULTA POR EMPLEADO");
     gotoxy(10,10); cprintf("DIGITE NUMERO CEDULA EMPLEADO  [           ]");
     gotoxy(42,10); cin >>CED;
     while(! ARCHIVO.eof() && (sw=='S'))
      {
       ARCHIVO.read((char *) &EMP, sizeof(REGISTRO));
       if(CED==EMP.CEDULA)
	sw='N';
      }
      if(ARCHIVO.eof() && (sw=='S'))
	{
	 gotoxy(20,15);textcolor(15+128); cprintf("EL EMPLEADO NO SE ENCUENTRA REGISTRADO");
	 textcolor(WHITE);
       }
      if(sw=='N')
      {
      textcolor(BLUE); textbackground(WHITE);
      gotoxy(7,12);cprintf("NOMBRE Y APELLIDO         LINEA     SALARIO      VENTAS    TIEMPO");
      textbackground(RED); textcolor(WHITE);
      gotoxy(6,14); cprintf(EMP.NOMBRE);
      gotoxy(35,14); cprintf("%c",EMP.LINEA);
      gotoxy(42,14); cprintf("%7.0f", EMP.SB);
      gotoxy(55,14); cprintf("%8.0f",EMP.VTAS);
      gotoxy(69,14); cprintf("%i",EMP.TIEMPO);
      sw='S';
      }
       do {
	 gotoxy(16,22); cprintf("DESEA SEGUIR CONSULTANDO OTRO EMPLEADO (S/N): [_]");
	 gotoxy(63,22); seguir=getch();
	 seguir=toupper(seguir);
	}while(seguir!='S' && seguir!='N');
      ARCHIVO.close();
    } //EL WHILE
    break;
    case 2:
     MARCO_FINAL();
     textcolor(BLUE); textbackground(WHITE);
     gotoxy(5,9); cprintf("NOMBRE Y APELLIDO        CEDULA   SALARIO    VENTAS     TIEMPO  LINEA");
     textbackground(RED); textcolor(WHITE);
     ifstream ARCHIVO("C:\ALVARO.DAT");
       while(!ARCHIVO.eof())
       {
	 ARCHIVO.read((char *)&EMP,sizeof(REGISTRO));
	 if(ARCHIVO.eof()) break;
	 gotoxy(5,F); cprintf(EMP.NOMBRE);
	 gotoxy(28,F); cprintf("%8.0f",EMP.CEDULA);
	 gotoxy(36,F); cprintf("%9.0f",EMP.SB);
	 gotoxy(49,F); cprintf("%8.0f",EMP.VTAS);
	 gotoxy(63,F); cprintf("%i",EMP.TIEMPO);
	 gotoxy(71,F); cprintf("%c",EMP.LINEA);
	 if (F==19)
	    {
	      gotoxy(20,21); cprintf("Presione cualquier tecla para continuar");
	      getch();
	      F=10;
	      MARCO_FINAL();
	      textcolor(BLUE); textbackground(WHITE);
	      gotoxy(5,9); cprintf("NOMBRE Y APELLIDO      CEDULA    SALARIO    VENTAS     TIEMPO   LINEA");
	      textbackground(RED); textcolor(WHITE);
	    }
	  else
	  ++F;
       }//CIERRA EL WHILE DEL CASE 2
      ARCHIVO.close();
       gotoxy(20,21); cprintf("Presione cualquier tecla para salir");
       getch();
    break;
    case 3:
    sub=3;
    break;
 }  //  EL SWICHE
}   //EL WHILE
ARCHIVO.close();
}   //FUNCION


  void MARCO_FINAL()
 {
int x,y;
textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(x=1; x<=24; x++)
  for(y=1; y<=80; y++)
  {
   gotoxy(y,x); cout <<"В";
  }

textcolor(BLUE); recuadro(3,5,5,75,2);
textcolor(RED); recuadro(2,4,4,74,2);
textcolor(WHITE); textbackground(RED);recuadro(2,4,4,74,1);
textcolor(BLUE); recuadro(9,23,5,75,2);
textcolor(RED); recuadro(8,22,4,74,2);
textcolor(WHITE);textbackground(RED);recuadro(8,22,4,74,1);
gotoxy(15,3); cprintf("REPORTE TOTAL DE EMPLEADOS ELECTROMARCAS DEL CESAR");
}


int TECLA2()
{
int op,i=1;
char tecla;
gotoxy(27,12); cprintf("");
gotoxy(27,12);
do{
   tecla=getch();
    if(tecla==27) // para salir del submenu
     {i=0;break;} //y enviar al menu principal tanto del case2 y case3.
    else if(tecla==80)
      {
	cout <<" ";
	if(wherey()==12)
	  {
	   gotoxy(27,wherey()+1); cprintf("");
	   gotoxy(27,wherey());
	  }
	    else 
	     if(wherey()==14)
	      {
	       gotoxy(27,12); cprintf("");
	       gotoxy(27,12);
	      }else
	       {
		  gotoxy(27,wherey()+1); cprintf("");
		  gotoxy(27,wherey());

	       }
    }

   else if(tecla==72)
    {
     cout<<" ";
       if(wherey()==14)
       {
	gotoxy(27,wherey()-1); cprintf("");
	gotoxy(27,wherey());
       }else
	 if(wherey()==12)
	 {
	  gotoxy(27,14); cprintf("");
	  gotoxy(27,14);
	 }else
	 {
	  gotoxy(27,wherey()-1); cprintf("");
	  gotoxy(27,wherey());
	 }
    }
}while(tecla!=13);
if(i==1){
op=wherey();
if(op==12)
op=1;
if(op==13)
op=2;
if(op==14)
op=3;
}
else
{
 op=3;
}
return op;
}


void MENU_CONSULTA()
{
MARCO_MENU();
gotoxy(33,10); cprintf("MENU CONSULTA");
gotoxy(28,12); cprintf("1. INDIVIDUAL");
gotoxy(28,13); cprintf("2. TODOS LOS EMPLEADOS");
gotoxy(28,14); cprintf("3. IR A MENU PRINCIPAL");
gotoxy(17,21); cprintf("Utilice las teclas (%c%c) y presione Enter ",24,25);
}


/*int void CLAVE()
{
int CONT,comienzo;
char clave,clave1,clave2,clave3,clave4,clave5;
ENTRADA(1);
MARCO_MENU();
for(a=1;a<=3;a++){
 gotoxy(26,10);textcolor(1);cprintf("<<DIGITE LA CLAVE[       ]>>");
  gotoxy(44,10);clave=getch();
  clave=toupper(clave);
  gotoxy(44,10);cout<<"*";
  gotoxy(45,10);clave1=getch();
  clave1=toupper(clave1);
  gotoxy(45,10);cout<<"*";
  gotoxy(46,10);clave2=getch();
  clave2=toupper(clave2);
  gotoxy(46,10);cout<<"*";
  gotoxy(47,10);clave3=getch();
  clave3=toupper(clave3);
  gotoxy(47,10);cout<<"*";
  gotoxy(48,10);clave4=getch();
  clave4=toupper(clave4);
  gotoxy(48,10);cout<<"*";
  gotoxy(49,10);clave5=getch();
  clave5=toupper(clave5);
  gotoxy(49,10);cout<<"*";
  gotoxy(50,10);
  getch();
   if (clave == 'O' && clave1 == 'R' && clave2 == 'A' && clave3 == 'V'&& clave4 == 'L' && clave5 == 'A')
   {
      comienzo=1;
   }

     else if(a==3)
      {
      gotoxy(25,13);cprintf("<<USTED SALDRA DEL PROGRAMA>>");
      gotoxy(30,15);cprintf("<<ACCESO DENEGADO>>");
      getch();
      ENTRADA(1);exit(0);
      }
  gotoxy(30,15);textcolor(a+152);cprintf("<<ACCESO DENEGADO>>");
  gotoxy(30,15);textcolor(a+152);cout<<a;
 }
retur comienzo;
} */

void ENTRADA(int z)
{
int x,y;
textcolor(WHITE);
textbackground(BLUE);
for(x=1, y=20; x<8; x++,y--)
{
clrscr();
gotoxy(5,x);   cout <<"мллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллм";
gotoxy(5,x+1); cout <<"ллп  л лллп  лп  л     л   пллп  пл  ллл  лп  пл   пллп  лп  плп    лл";
gotoxy(5,x+2); cout <<"лл ллл ллл ллл ллллл ллл лл лл лл л л л л л лл л лл лл ллл лл л лллллл";
gotoxy(5,x+3); cout <<"лл ппл ллл ппл ллллл ллл    лл лл л лл лл л пп л    лл ллл пп лм   ллл";
gotoxy(5,y-3); cout <<"лл ммл ллл ммл ллллл ллл л ллл лл л ллллл л мм л л ллл ллл мм ллллл лл";
gotoxy(5,y-2); cout <<"лл ллл ллл ллл ллллл ллл лл лл лл л ллллл л лл л лл лл ллл лл ллллл лл";
gotoxy(5,y-1); cout <<"ллм  лм  лм  лм  ллл ллл ллл лм  мл ллллл л лл л ллл лм  л лл л    млл";
gotoxy(5,y);   cout <<"пллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллп";
gotoxy(x+15,20);cprintf("INGENIERO:  ALVARO CARRILLO");
delay(100);
}
if (z==1)
{
textcolor(15+128);
gotoxy(20,16); cprintf("Presione cualquier tecla para continuar");
textcolor(15);
getch();
} else
{
textcolor(15+128);
gotoxy(20,16); cprintf("Presione cualquier tecla para salir");
textcolor(15);
getch();
}

}

void INDEXADO()
{
  int sub=1;
  float CED;
       clrscr();
       MARCO();
       CUADRO(8,55,9,11);
      _setcursortype(_NORMALCURSOR);
     gotoxy(10,10); cprintf("DIGITE NUMERO CEDULA EMPLEADO");
     textbackground(RED);MES(41,54,10);//CEDULA , 1.columna inicial 2.columna final 3.fila
     gotoxy(9,10);cprintf(" ");
     gotoxy(39,10);textcolor(BLUE);cprintf("лл");
     gotoxy(54,10);cprintf(" ");
     gotoxy(42,10);textcolor(BLACK);cin>>CED;
  fstream ARCHIVO("C:\ALVARO.DAT",ios::in/ios::out);
   if (ARCHIVO.fail())
  {
    //MARCO_MOSTRAR();
    gotoxy(22,12);textcolor(4+125);cprintf("ARCHIVO NO EXISTE.....OJO!");getch();
    sub=3;
  }
 while(sub != 3)
 {
 ARCHIVO.seekp(2,ios::beg);
 ARCHIVO<<ARCHIVO;

}
ARCHIVO.close();
}

void CUADRO(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Э";
gotoxy(o,ff); cout<<"Э";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"К";
gotoxy(cf,o); cout<<"К";
}
gotoxy(ci,fi); cout<<"Щ";
gotoxy(cf,fi); cout<<"Л";
gotoxy(ci,ff); cout<<"Ш";
gotoxy(cf,ff); cout<<"М";
}

void MARCO()
{
int x,y;
textcolor(WHITE);
textbackground(BLUE);
clrscr();
for(x=1; x<=24; x++)
  for(y=1; y<=80; y++)
  {
   gotoxy(y,x); cout <<"В";
  }

textcolor(BLUE); recuadro(3,5,5,75,2);
textcolor(RED); recuadro(2,4,4,74,2);
textcolor(WHITE); textbackground(RED);recuadro(2,4,4,74,1);
textcolor(BLUE); recuadro(21,23,5,75,2);
textcolor(RED); recuadro(20,22,4,74,2);
textcolor(WHITE); textbackground(RED); recuadro(20,22,4,74,1);
//textcolor(BLUE); recuadro(9,18,25,55,2);
//textcolor(RED); recuadro(8,17,24,54,2);
//textcolor(WHITE);textbackground(RED);recuadro(8,17,24,54,1);
textcolor(15+128);
gotoxy(28,3); cprintf("ELECTROMARCAS DEL CESAR");
textcolor(15);
}
