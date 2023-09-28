/*******************VECTORES****************/

/******************* Archivos cabecera ****************/
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

/******************* Subrutinas ****************/
void MARCO_MENU();
void MARCO_MOSTRAR();
void MARCO_FINAL();
void ENTRADA(int z);
int TECLA();
int TECLA2();
int MENU_PRINCIPAL();
void MENU_CAPTURA();
int MENU_CONSULTA();
void LINEA_EMP(char TIPO[15],int J);
int MENU_LIQUIDACION();
float CAP_COMISION(char ARTICULO, float VENTAS);
void recuadro(int x, int x2, int y, int y2, int z);
void MENU(int tam,int fil, int filsig, int colfi);
void MES(int coli, int colf, int fil);

void main(void)
{
int op, x,y, op2, op3, I=0,J,a,tecla,h,CONT;
char opcion, MENU='S',tec2[1], op_seguir='S',clave,clave1,clave2,clave3,clave4,clave5;
float  VENTAS[15], SALARIO[15], NETO[15];
float CEDULA[15], VALOR, COMISION[15], PRIMA[15];
int TIEMPO[15],LINEA;
char TIPO[15],NOMBRE[15][40], SUICHE='N';
ENTRADA(1);
MARCO_MENU();
/******************* CONTRASEЅA ****************/
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
     goto comienzo;
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
while (MENU=='S')
{
opcion='S';
comienzo:
MARCO_MENU();
op=MENU_PRINCIPAL();
switch(op) {
case 1:
opcion='S';
 _setcursortype(_NORMALCURSOR);
while(I<15 && opcion=='S')
  {
   _setcursortype(_NORMALCURSOR);
   MENU_CAPTURA();// para salir del case y enviar
//no se puede porque al usar gets debe ir al principio
//   tecla=getche();
//    if (tecla==27)break;  //al menu principal
//    else{gotoxy(30,7);cout<<tec2;}//para imprimir el caracter
   gotoxy(30,7); gets(NOMBRE[I]);
   gotoxy(30,9); cin >>CEDULA[I];
   gotoxy(30,11); cin >>SALARIO[I];
   gotoxy(30,13); cin >>TIEMPO[I];
   do {
       gotoxy(5,22); cprintf("T->Televisores  C->Computadores  E-> Estufas A-> Adornos  M-> Muebles");
       gotoxy(30,15); cin >>TIPO[I];
       TIPO[I]=toupper(TIPO[I]);
      }while(TIPO[I]!='C' && TIPO[I]!='T' && TIPO[I]!='M' && TIPO[I]!='A' && TIPO[I]!='E');
       gotoxy(5,22);textbackground(RED);cprintf("                                                                     ");
       gotoxy(30,17); cin >>VENTAS[I];

       PRIMA[I]=SALARIO[I]*TIEMPO[I]/100;
       COMISION[I]=CAP_COMISION(TIPO[I],VENTAS[I]);
       NETO[I]=SALARIO[I]+PRIMA[I]+COMISION[I];
       for(y=0; y<40; y++)
       NOMBRE[I][y]=toupper(NOMBRE[I][y]);
       CONT=0;

/******************* Barra progresiva ****************/
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
       gotoxy(62,22); opcion=getch();
       opcion=toupper(opcion);
       }while(opcion!='N' && opcion!='S');
I++;
MENU='S';
}//del while(I<15 && opcion=='S')

break;

case 2:
opcion='S';
 while(opcion=='S')
  {
    _setcursortype(_NOCURSOR);
    op2=MENU_CONSULTA();
    switch(op2) {
     case 1:
     do
     {
     MARCO_MOSTRAR();
     SUICHE='N';
     _setcursortype(_NORMALCURSOR);
     gotoxy(28,8); cprintf("MENU CONSULTA POR EMPLEADO");
     gotoxy(10,10); cprintf("DIGITE NUMERO CEDULA EMPLEADO  [           ]");
     gotoxy(42,10); cin >>VALOR;
     for(J=0; J<I; J++)
	 if(VALOR==CEDULA[J])
	   {
	    SUICHE='S';
	    break;
	   }
     if(SUICHE=='S')
     {
      textcolor(BLUE); textbackground(WHITE);
      gotoxy(6,12); cprintf("NOMBRE Y APELLIDO         ARTICULO     SALARIO      VENTAS    TIEMPO");
      textbackground(RED); textcolor(WHITE);
      gotoxy(6,14); cprintf(NOMBRE[J]);
      LINEA_EMP(TIPO,J);
      gotoxy(44,14); cprintf("%7.0f", SALARIO[J]);
      gotoxy(56,14); cprintf("%8.0f",VENTAS[J]);
      gotoxy(69,14); cprintf("%i",TIEMPO[J]);
    }
    else
       {
	 textcolor(15+128);
	 gotoxy(20,15); cprintf("EL EMPLEADO NO SE ENCUENTRA REGISTRADO");
	 textcolor(WHITE);
       }

    do {
	 gotoxy(20,21); cprintf("DESEA SEGUIR CONSULTANDO OTRO EMPLEADO (S/N): [_]");
	 gotoxy(67,21); op_seguir=getch();
	 op_seguir=toupper(op_seguir);
	}while(op_seguir!='S' && op_seguir!='N');

    }while(op_seguir=='S');
    break;
    case 2:
     MARCO_FINAL();
     textcolor(BLUE); textbackground(WHITE);
     gotoxy(5,9); cprintf("NOMBRE Y APELLIDO        CEDULA   SALARIO    VENTAS     TIEMPO  LINEA");
     textbackground(RED); textcolor(WHITE);
     LINEA=11;
       for(J=0; J<I; J++, LINEA++)
       {
	 gotoxy(5,LINEA); cprintf(NOMBRE[J]);
	 gotoxy(28,LINEA); cprintf("%9.0f",CEDULA[J]);
	 gotoxy(38,LINEA); cprintf("%7.0f", SALARIO[J]);
	 gotoxy(49,LINEA); cprintf("%8.0f",VENTAS[J]);
	 gotoxy(62,LINEA); cprintf("%2i",TIEMPO[J]);
	 gotoxy(70,LINEA); cprintf("%c",TIPO[J]);
	 if (LINEA==19)
	    {
	      gotoxy(20,21); cprintf("Presione cualquier tecla para continuar");
	      getch();
	      LINEA=10;
	      MARCO_FINAL();
	      textcolor(BLUE); textbackground(WHITE);
	      gotoxy(5,9); cprintf("NOMBRE Y APELLIDO      CEDULA    SALARIO    VENTAS     TIEMPO   LINEA");
	      textbackground(RED); textcolor(WHITE);
	    }
       }
       gotoxy(20,21); cprintf("Presione cualquier tecla para salir");
       getch();
    break;
    case 3:
    opcion='N';
    break;
    }
  }
break;
case 3:
opcion='S';
  while (opcion=='S')
   {
    op3=MENU_LIQUIDACION();
    switch(op3) {
     case 1:
     do {
     MARCO_MOSTRAR();
     SUICHE='N'; 
     gotoxy(28,8); cprintf("MENU CONSULTA POR EMPLEADO");
     gotoxy(10,10); cprintf("DIGITE NUMERO CEDULA EMPLEADO  [           ]");
     gotoxy(42,10); cin >>VALOR;
	for(J=0; J<I; J++)
	 if(VALOR==CEDULA[J])
	   {
	    SUICHE='S';
	    break;
	   }
     if(SUICHE=='S')
     {
      textcolor(BLUE); textbackground(WHITE);
      gotoxy(5,12); cprintf("NOMBRE Y APELLIDO       SALARIO      PRIMA     COMISION      NETO    ");
      textbackground(RED); textcolor(WHITE);
      gotoxy(5,14); cprintf(NOMBRE[J]);
      gotoxy(29,14); cprintf("%7.0f", SALARIO[J]);
      gotoxy(39,14); cprintf("%8.0f",PRIMA[J]);
      gotoxy(52,14); cprintf("%8.0f",COMISION[J]);
      gotoxy(64,14); cprintf("%8.0f",NETO[J]);

    }
    else
       {
	 textcolor(15+128); 
	 gotoxy(20,15); cprintf("EL EMPLEADO NO SE ENCUENTRA REGISTRADO");
	 textcolor(WHITE);     
       }

     do {
	 gotoxy(20,21); cprintf(" DESEA SEGUIR LIQUIDANDO OTRO EMPLEADO (S/N): [_]");	 
	 gotoxy(67,21); op_seguir=getch();
	 op_seguir=toupper(op_seguir);
	}while(op_seguir!='S' && op_seguir!='N');

     }while(op_seguir=='S');
     break;
     case 2:
      MARCO_FINAL();
      textcolor(BLUE); textbackground(WHITE);
      gotoxy(5,9); cprintf("NOMBRE Y APELLIDO     CEDULA    VENTAS    COMISON    PRIMA     NETO  ");
      textbackground(RED); textcolor(WHITE);                            
      LINEA=11;
       for(J=0; J<I; J++, LINEA++)
       {
	 gotoxy(5,LINEA); cprintf(NOMBRE[J]);
	 gotoxy(25,LINEA); cprintf("%9.0f",CEDULA[J]);
	 gotoxy(35,LINEA); cprintf("%9.0f", VENTAS[J]);
	 gotoxy(45,LINEA); cprintf("%9.0f",COMISION[J]);
	 gotoxy(56,LINEA); cprintf("%7.0f",PRIMA[J]);
	 gotoxy(64,LINEA); cprintf("%9.0f",NETO[J]);
	 if (LINEA==19)
	    {
	      gotoxy(20,21); cprintf("Presione cualquier tecla para continuar");
	      getch();
	      LINEA=10;
	      MARCO_FINAL();
	      textcolor(BLUE); textbackground(WHITE);
	      gotoxy(5,9); cprintf("NOMBRE Y APELLIDO      CEDULA    SALARIO    VENTAS     TIEMPO   LINEA");
	      textbackground(RED); textcolor(WHITE);
	    }
       }
       gotoxy(20,21); cprintf("Presione cualquier tecla para salir");
       getch();
     break;
     case 3:
     opcion='N';
     break;
   }
}
break;

case 4:
ENTRADA(2);
MENU='N';
break;
}//del switche
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
gotoxy(x,20);cprintf("INGENIERO:  ALVARO CARRILLO");
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
       exit(0);
      //pregunto por la f1
      else if(tecla==59){clrscr();MARCO_MENU();
      gotoxy(35,9);cprintf("COMMANDOS");
      gotoxy(27,11);cprintf(" F2ЏЏ para captura");
      gotoxy(27,12);cprintf(" F3ЏЏ para consulta");
      gotoxy(27,13);cprintf(" F4ЏЏ para liquidacion");
      gotoxy(27,14);cprintf(" ECSЏЏ para salir de ");
      gotoxy(34,15);cprintf("los menus");
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


int MENU_PRINCIPAL()
{
int op;
gotoxy(33,10); cprintf("MENU PRINCIPAL");
gotoxy(28,12); cprintf("1. CAPTURA DE EMPLEADOS");
gotoxy(28,13); cprintf("2. CONSULTA DE EMPLEADOS");
gotoxy(28,14); cprintf("3. LIQUIDACION EMPLEADOS");
gotoxy(28,15); cprintf("4. SALIR DEL PROGRAMA(ESC)");
gotoxy(5,21); cprintf("Utilice las teclas(%c%c) y presione Enter,Si necesita ayuda precione F1",24,25);
op=TECLA();
return op;
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
 MES(30,60,7);//NOMBRE 1.columna inicial 2.columna final 3.fila
 _setcursortype(_NORMALCURSOR);
 MES(30,42,9);//CEDULA
 MES(30,42,11);//ASIG BASICA
 MES(30,32,13);//TIEMPO DE SERVICIO
 MES(30,31,15);//LINEA DE ARTICULO
 MES(30,42,17);//VALOR DE LAS VENTAS
 gotoxy(30,7);
}
int MENU_CONSULTA()
{
int op;
MARCO_MENU();
gotoxy(33,10); cprintf("MENU CONSULTA");
gotoxy(28,12); cprintf("1. INDIVIDUAL");
gotoxy(28,13); cprintf("2. TODOS LOS EMPLEADOS");
gotoxy(28,14); cprintf("3. IR A MENU PRINCIPAL");
gotoxy(17,21); cprintf("Utilice las teclas (%c%c) y presione Enter ",24,25);
op=TECLA2();
return op;
}
void LINEA_EMP(char TIPO[15],int J)
{
if (TIPO[J]=='C')
	   {
	    gotoxy(32,14); cprintf("COMPUTADOR");
	   }
	     else if (TIPO[J]=='T')
	     {
	       gotoxy(32,14); cprintf("TELEVISOR");
	     }
	      else if (TIPO[J]=='M')
	      {
	       gotoxy(32,14); cprintf("MUEBLES");
	      }
	       else if (TIPO[J]=='A')
	       {
		gotoxy(32,14); cprintf("ADORNOS");
	       }
		else 
		 {
		  gotoxy(32,14); cprintf("ESTUFAS");
		 }
}
int MENU_LIQUIDACION()
{
int op;
MARCO_MENU();
gotoxy(31,10); cprintf("MENU LIQUIDACIрN");
gotoxy(28,12); cprintf("1. INDIVIDUAL");
gotoxy(28,13); cprintf("2. TODOS LOS EMPLEADOS");
gotoxy(28,14); cprintf("3. IR A MENU PRINCIPAL");
gotoxy(17,21); cprintf("Utilice las teclas (%c%c) y presione Enter",24,25);
op=TECLA2();
return op;
}
float CAP_COMISION(char ARTICULO, float VENTAS)
{
float COMISION;
switch(ARTICULO) {

case 'T':
  if(VENTAS<4000000)
   COMISION=0;
    else
     if(VENTAS<8000000)
      COMISION=VENTAS*0.06;
       else 
	if(VENTAS<20000000)
	 COMISION=VENTAS*0.10;
	  else
	   COMISION=VENTAS*0.15;
break;
case 'C':
 COMISION=VENTAS*0.10;
break;
case 'E':
 if(VENTAS>3000000)
 COMISION=VENTAS*0.13;
  else
    COMISION=0;
break;
case 'A':
 COMISION=VENTAS*0.17;
break;
case 'M':
 if(VENTAS<7000000)
  COMISION=0;
   else if (VENTAS<=9000000)
    COMISION=VENTAS*0.09;
     else
      COMISION=VENTAS*0.12;
break;
}
return COMISION;
}
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

void MES(int coli, int colf,int fil)
{
  int p;
for(p=coli;p<colf;p++){gotoxy(p,fil);cprintf(" ");}
}
