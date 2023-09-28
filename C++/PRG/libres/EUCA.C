#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <dos.h>
#include <io.h>

#define localizar (struct empleado*) malloc(sizeof(struct empleado))  

void mensaje(char[90],int);
void cuadrop(int,int,int,int);
void limpia();
void cuadrog(int,int,int,int);
void pantalla();
void seleccion();
void opcion(int,int);
void teclas();
void ventana1(int);
void ventana2(int);
void ventana3();
void ventana4(int);
void ventana5();
void ventana6();
void fondo();
void fondo1(int);
void adic_emp();
void modi_emp();
void elim_emp(); 
void cap_codigo();
void salir();
void cap_nombre();
void cap_apellido();
void cap_civil();
void cap_edad();
void cap_sexo();
void cap_cargo();
void cap_sueldo();
int buscar_cod();
void adiciona();
void adic(int,int);
void cap_nueva_nov();
int hash();
void elimina(int,int);
void adic_nov();
int hash1();
void cargar();
void nove();
void liquidacion();
void con_emp();
void con_nov();
void con_nov_fecha();
void imprimir();


int i,j,tecla,cont=0,cont1=0,pos=0;

struct empleado
{
 char codigo[10];
 char nombre[20];
 char apellido[20];
 char civil[15];
 char edad[4];
 char sexo;
 char cargo[15];
 char sueldo[10];
 struct empleado *sig;
}emp[100],r;

struct empl
{
 char codigo[10];
 char nombre[20];
 char apellido[20];
 char civil[15];
 char edad[4];
 char sexo;
 char cargo[15];
 char sueldo[10];
}f;

struct novedades
{
 char codigo[3];
 char des[30];
 char tipo;
}nov,novedad[50];

struct nove
{
 char codigo[9];
 char cod[3];
 long valor;
 char fecha[10];
 char tipo;
}n[50];

struct liqui
{
 char codigo[10];
 char nombre[20];
 char apellido[20];
 long sueldo;
 long salario;
}lq[100];

struct empleado  *p,*q,*nuevo,*d;

void main()
{
 cargar();
 pantalla();
}               
void fondo()
{
 int i,f;
 textbackground(7); 
 textcolor(17);
 for(i=2;i<=79;i++)
   {
    for (f=6;f<=24;f++)
	 {
	  gotoxy(i,f);cprintf("°");
	 }
   }
} 
void fondo1(int c)
{
 int i,f;
 textbackground(c); 
 for(i=2;i<=79;i++)
   {
    for (f=6;f<=24;f++)
	 {
	  gotoxy(i,f);cprintf(" ");
	 }
   }
}
void pantalla()
{
 int f,i,op=0,ver=0;
 clrscr();
 textbackground(7); 
 textcolor(17);
 for(i=1;i<=80;i++)
   {
    for (f=1;f<=25;f++)
	 {
	  gotoxy(i,f);cprintf(" ");
	 }
   }
 fondo();
 textcolor(4);
 gotoxy(2,2);cprintf("                      BUSQUEDA RAPIDA EN VECTORES 'HASH'                   ");
 textcolor(4);
 gotoxy(3,3);cprintf("FREDDY ALFONSO MOSQUERA LUQUE                 Cod. 96131566             S5E");
 textcolor(0);
 cuadrog(1,1,80,4);
 teclas();
 textcolor(0);
 mensaje("Escoja una Opcion del Menu principal                                    ",25);
 while(1)
 { 
  tecla=getch();
  tecla=toupper(tecla);
  switch(tecla)
	  {
	   case 50 : {op=1;ver=11;opcion(op,ver);break;}
	   case 49 : {op=2;ver=21;opcion(op,ver);break;}
	   case 38 : {op=3;ver=31;opcion(op,ver);break;}
	   case 46 : {op=4;ver=41;opcion(op,ver);break;}
	   case 23 : {op=5;ver=51;opcion(op,ver);break;}
	   case 31 : {op=6;ver=61;opcion(op,ver);break;}
	   case 27 : {op=0;ver=0;opcion(op,ver);fondo();break;}
	   case 77 : {if (op==6) op=1;else (op=op+1);
			    if (op==1) ver=11;
			    if (op==2) ver=21;
			    if (op==3) ver=31;
			    if (op==4) ver=41;
			    if (op==5) ver=51;
			    if (op==6) ver=61;	
			    opcion(op,ver);break;}
	   case 75 : {if (op==1 || op==0) op=6;else (op=op-1);
			    if (op==1) ver=11;
			    if (op==2) ver=21;
			    if (op==3) ver=31;
			    if (op==4) ver=41;
			    if (op==5) ver=51;
			    if (op==6) ver=61;	
			    opcion(op,ver);break;}
	   case 80 : {if (ver==13) ver=10;
			    if (ver==22) ver=20;
			    if (ver==43) ver=40;
			    ver=ver+1;opcion(op,ver);break;}
	  case 72 : {if (ver==11) ver=14;
			    if (ver==21) ver=23;
			    if (ver==41) ver=44;
			    ver=ver-1;opcion(op,ver);break;}
	  case 13 : { switch(ver)
			    { 
					case 11 : {adic_emp();break;}
					case 12 : {modi_emp();break;}
					case 13 : {elim_emp();break;}
					case 21 : {adic_nov();break;}
					case 22 : {nove();break;}
					case 31 : {liquidacion();break;}
					case 41 : {con_emp();break;}
					case 42 : {con_nov();break;}
					case 43 : {con_nov_fecha();break;}
					case 51 : {imprimir();break;}
					case 61 : {salir();exit(1);break;}

				}
			  }
	    }
  }
}
void opcion(op,ver)
{
 switch(op)
 {
   case 0 : {teclas();mensaje("Escoja una Opcion del Menu principal                              ",25);}break;
   case 1 : {teclas();textbackground(2);textcolor(0);
		  gotoxy(5,5);cprintf("antenimiento");textcolor(4);
		  gotoxy(4,5);cprintf("M");ventana1(ver);};break; 
   case 2 : {teclas();textbackground(2);textcolor(0);
		  gotoxy(21,5);cprintf("Novedades ");textcolor(4);
		  gotoxy(21,5);cprintf("N");ventana2(ver);};break;
   case 3 : {teclas();textbackground(2);textcolor(0);
		  gotoxy(34,5);cprintf("Liquidaci¢n"); textcolor(4);
		  gotoxy(34,5);cprintf("L");ventana3();};break; 
  case 4 :  {teclas();textbackground(2);textcolor(0);
		  gotoxy(49,5);cprintf("Consultas"); textcolor(4);
		  gotoxy(49,5);cprintf("C");ventana4(ver);};break; 
  case 5 :  {teclas();textbackground(2);textcolor(0);
		  gotoxy(60,5);cprintf("Imprimir"); textcolor(4);
		  gotoxy(60,5);cprintf("I");ventana5();};break; 
  case 6 :  {teclas();textbackground(2);textcolor(0);
		  gotoxy(71,5);cprintf("Salir"); textcolor(4);
		  gotoxy(71,5);cprintf("S");ventana6();};break; 
 }
}

void teclas()
{
 int i;
 textbackground(7);
 for(i=1;i<=80;i++)
 { 
   gotoxy(i,5);
   cprintf(" ");
 }
 textcolor(0);
 gotoxy(1,5);cprintf("   Mantenimiento    Novedades    Liquidaci¢n    Consultas  Imprimir   Salir     ");
 textcolor(4);
 gotoxy(4,5);cprintf("M");
 gotoxy(21,5);cprintf("N");
 gotoxy(34,5);cprintf("L");
 gotoxy(49,5);cprintf("C");
 gotoxy(60,5);cprintf("I");
 gotoxy(71,5);cprintf("S");
 gotoxy(1,25);
 textcolor(0);
}
void ventana1(ver)
{ 
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(3,1,20,5);
 switch(ver)
 {
  case 11 :  {textbackground(2);textcolor(0);
		   gotoxy(4,2);cprintf("Adicionar       ");textbackground(7);
		   gotoxy(4,3);cprintf("Modificar       ");
		   gotoxy(4,4);cprintf("Eliminar        ");
		   mensaje("Adicion de Empleados                                            ",20);break;}
  case 12 :  { gotoxy(4,2);cprintf("Adicionar       ");
		   textbackground(2);textcolor(0);
		   gotoxy(4,3);cprintf("Modificar       ");
		   textbackground(7);gotoxy(4,4);cprintf("Eliminar        ");
		   mensaje("Modificacion de Registro de Empleado                              ",20);break;}
  case 13 :  {gotoxy(4,2);cprintf("Adicionar       ");
		   gotoxy(4,3);cprintf("Modificar       ");
		   textbackground(2);textcolor(0);
		   gotoxy(4,4);cprintf("Eliminar        ");
		   mensaje("Eliminar Registro de Empleados                                    ",20);break;}
 }
window(1,1,80,25);
}
void ventana2(ver)
{
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(22,1,39,4);
 switch(ver)
 {
   case 21 :  {textbackground(2);textcolor(0);
		   gotoxy(23,2);cprintf("Adicionar       ");textbackground(7);
		   textbackground(7);gotoxy(23,3);cprintf("Nueva Novedad   ");
		   mensaje("Adicion de Novedad                                          ",20);break;}
   case 22 :  { gotoxy(23,2);cprintf("Adicionar       ");
		   textbackground(2);textcolor(0);
		   gotoxy(23,3);cprintf("Nueva Novedad   ");
		   mensaje("Adicionar Nueva Novedad                                       ",20);break;}
  }
 window(1,1,80,25);
}
void ventana3()
{
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(35,1,50,3);
 textbackground(2);textcolor(0);
 gotoxy(36,2);cprintf("Liquidaci¢n   ");
 window(1,1,80,25);
 mensaje("Liquidaci¢n de la Nomina                                              ",25);
}
void ventana4(ver)
{ 
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(49,1,70,5);
 switch(ver)
 {
  case 41 :  {textbackground(2);textcolor(0);
		   gotoxy(50,2);cprintf("Consulta x Empleado ");textbackground(7);
		   gotoxy(50,3);cprintf("Consulta de Novedad ");
		   gotoxy(50,4);cprintf("Novedad por empleado");
		   mensaje("Consulta x Empleado                                               ",20);break;}
  case 42 :  { gotoxy(50,2);cprintf("Consulta x Empleado ");
		   textbackground(2);textcolor(0);
		   gotoxy(50,3);cprintf("Consulta de Novedad ");
		   textbackground(7);
		   gotoxy(50,4);cprintf("Novedad por Empleado");
		   mensaje("Consulta de Novedades                                              ",20);break;}
  case 43 :  { gotoxy(50,2);cprintf("Consulta x Empleado ");
		   gotoxy(50,3);cprintf("Consulta de Novedad ");
		   textbackground(2);textcolor(0);
		   gotoxy(50,4);cprintf("Novedad por Empleado");
		   mensaje("Consulta de Novedades                                              ",20);break;}

  }
window(1,1,80,25);
}

void ventana5()
{
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(60,1,70,3);
 textbackground(2);textcolor(0);
 gotoxy(61,2);cprintf("Nomina   ");
 window(1,1,80,25);
 mensaje("Imprimir Nomina                                                     ",25);
}
void ventana6()
{
 fondo();
 window(2,6,79,25);
 textcolor(0);
 cuadrop(69,1,77,3);
 textbackground(2);textcolor(0);
 gotoxy(70,2);cprintf("Salir  ");
 window(1,1,80,25);
 mensaje("Finalizar el programa                                                      ",25);
}

void adic_emp()
{
 int sw=0,sw1=0,c;char opcion;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(27,6);cprintf("ADICION REGISTRO DE EMPLEADO");
 cuadrop(3,8,45,23);cuadrop(46,8,78,15);
 gotoxy(4,8);cprintf("Datos Personales");
 gotoxy(47,8);cprintf("Laborales");
 gotoxy(4,11);cprintf("Codigo......: ");
 gotoxy(4,13);cprintf("Nombres.....: ");
 gotoxy(4,15);cprintf("Apellidos...: ");
 gotoxy(4,17);cprintf("Est. Civil..: ");
 gotoxy(4,19);cprintf("Edad........: ");
 gotoxy(4,21);cprintf("Sexo........: ");
 textbackground(1);
 gotoxy(47,11);cprintf("Cargo.....: ");
 gotoxy(47,13);cprintf("Sueldo....: ");
while(sw1==0)
{
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(18,13);cprintf("                      ");
 gotoxy(18,15);cprintf("                      ");
 gotoxy(18,17);cprintf("          ");
 gotoxy(18,19);cprintf("   ");
 gotoxy(18,21);cprintf("  ");
 gotoxy(59,11);cprintf("               ");
 gotoxy(59,13);cprintf("               ");
 textbackground(15);textcolor(0);
 gotoxy(50,18);cprintf("    A c e p t a r     ");
 gotoxy(50,21);cprintf("      S a l i r       ");
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==1)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==0) {break;}
   }
 limpia();
 cap_nombre();
 cap_apellido();
 cap_civil();
 cap_edad();
 cap_sexo();
 cap_cargo();
 cap_sueldo();
 textbackground(2);textcolor(4);
 gotoxy(50,18);cprintf("    A c e p t a r     ");
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) {adiciona();break;}
	   if (sw==1) {adiciona();sw1=1;break;}
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(50,18);cprintf("    A c e p t a r     ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("      S a l i r       ");
	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(50,18);cprintf("    A c e p t a r     ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("      S a l i r       ");
	  }
  }
 }
 fondo();
}
void con_nov_fecha()
{
 int i,c,h,j;long total;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("CONSULTA NOVEDADES POR CLIENTE");
 gotoxy(4,11);cprintf("Codigo......: ");
 gotoxy(27,11);cprintf("Nombres.....: ");
 gotoxy(53,11);cprintf("Apellidos...: ");
 gotoxy(4,13);cprintf("Sueldo.......: ");
 gotoxy(14,15);cprintf("FECHA");
 gotoxy(34,15);cprintf("NOVEDAD");
 gotoxy(50,15);cprintf("VALOR");
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(37,11);cprintf("               ");
 gotoxy(62,11);cprintf("               ");
 gotoxy(18,13);cprintf("          ");
 textcolor(0);
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==0)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==1) {break;}
  }
  h=hash();
  if (strcmp(emp[h].codigo,r.codigo)==0)
    {
	gotoxy(37,11);cprintf("%s",emp[h].nombre);
	gotoxy(62,11);cprintf("%s",emp[h].apellido);
	gotoxy(18,13);cprintf("%s",emp[h].sueldo);
    }
 else
    {
	p=&emp[h];
	while(p->sig != NULL)
		 {
		  p=p->sig;
		  if (strcmp(p->codigo,r.codigo)==0)
			 {
			   textbackground(15);textcolor(0);
			   gotoxy(37,11);cprintf("%s",p->nombre);
			   gotoxy(62,13);cprintf("%s",p->apellido);
			   gotoxy(18,13);cprintf("%s",p->sueldo);
			 }
		 }
     }	
  textbackground(9);
  textcolor(15);
  c=0;total=0;
  for(i=0;i<=cont1;i++)
   {
    if (strcmp(r.codigo,n[i].codigo)==0)
       {
        c=c+1;
        gotoxy(14,17+i);cprintf("%s",n[i].fecha);
        gotoxy(50,17+i);cprintf("%ld",n[i].valor);
        total=total+n[i].valor;
        for (j=0;j<=cont;j++)
           {
	if (strcpy(n[i].cod,novedad[j].codigo)==0)
	gotoxy(34,17+i);cprintf("%s",novedad[j].des);
	j=cont;
           }
       }
   }
 gotoxy(50,18+c);cprintf("%ld",total);
 getch();
 fondo();
}

void modi_emp()
{
 char opcion,op;int sw=0,sw1=0,c,h,w=0;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("ELIMINACION REGISTRO DE EMPLEADO");
 cuadrop(3,8,45,23);cuadrop(46,8,78,15);
 gotoxy(4,8);cprintf("Datos Personales");
 gotoxy(47,8);cprintf("Laborales");
 gotoxy(4,11);cprintf("Codigo......: ");
 gotoxy(4,13);cprintf("Nombres.....: ");
 gotoxy(4,15);cprintf("Apellidos...: ");
 gotoxy(4,17);cprintf("Est. Civil..: ");
 gotoxy(4,19);cprintf("Edad........: ");
 gotoxy(4,21);cprintf("Sexo........: ");
while(sw1==0)
{
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(18,13);cprintf("                      ");
 gotoxy(18,15);cprintf("                      ");
 gotoxy(18,17);cprintf("          ");
 gotoxy(18,19);cprintf("   ");
 gotoxy(18,21);cprintf("  ");
 gotoxy(59,11);cprintf("               ");
 gotoxy(59,13);cprintf("               ");
 textbackground(1);textcolor(15);
 gotoxy(47,11);cprintf("Cargo.....: ");
 gotoxy(47,13);cprintf("Sueldo....: ");
 textbackground(15);textcolor(0);
 gotoxy(50,18);cprintf(" M o d i f i c a r    ");
 gotoxy(50,21);cprintf("     S a l i r        ");
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==0)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==1) {break;}
  }
 mensaje("Mod.  1.Nombre  2.Apellido  3.Est.Civil  4.Edad  5.Sexo  6.Cargo  7.Sueldo",25);
 h=hash();
 if (strcmp(emp[h].codigo,r.codigo)==0)
    {
	w=1;
	strcpy(r.codigo,emp[h].codigo);
	strcpy(r.nombre,emp[h].nombre);
	strcpy(r.apellido,emp[h].apellido);
	strcpy(r.edad,emp[h].edad);
	strcpy(r.civil,emp[h].civil);
	r.sexo=emp[h].sexo;
	strcpy(r.cargo,emp[h].cargo);
	strcpy(r.sueldo,emp[h].sueldo);
	textbackground(15);textcolor(0);
	gotoxy(18,13);cprintf("%s",emp[h].nombre);
	gotoxy(18,15);cprintf("%s",emp[h].apellido);
	gotoxy(18,17);cprintf("%s",emp[h].civil);
	gotoxy(18,19);cprintf("%s",emp[h].edad);
	gotoxy(18,21);cprintf("%c",emp[h].sexo);
	gotoxy(59,11);cprintf("%s",emp[h].cargo);
	gotoxy(59,13);cprintf("%s",emp[h].sueldo);
    }
 else
    {
	p=&emp[h];
	while(p->sig != NULL)
		 {
		  p=p->sig;
		  if (strcmp(p->codigo,r.codigo)==0)
			 {
			   strcpy(r.codigo,p->codigo);
			   strcpy(r.nombre,p->nombre);
			   strcpy(r.apellido,p->apellido);
			   strcpy(r.civil,p->civil);
			   strcpy(r.edad,p->edad);
			   r.sexo=p->sexo;
			   strcpy(r.cargo,p->cargo);
			   strcpy(r.sueldo,p->sueldo);
			   textbackground(15);textcolor(0);
			   gotoxy(18,13);cprintf("%s",p->nombre);
			   gotoxy(18,15);cprintf("%s",p->apellido);
			   gotoxy(18,17);cprintf("%s",p->civil);
			   gotoxy(18,19);cprintf("%s",p->edad);
			   gotoxy(18,21);cprintf("%c",p->sexo);
			   gotoxy(59,11);cprintf("%s",p->cargo);
			   gotoxy(59,13);cprintf("%s",p->sueldo);
			 }
		 }
	
    }
 op=getch();
 switch(op)
 {
  case '1' :  {gotoxy(18,13);cprintf("                      ");cap_nombre();break;}
  case '2' :  {gotoxy(18,15);cprintf("                      ");cap_apellido();break;}
  case '3' :  {gotoxy(18,17);cprintf("          ");cap_civil();break;}
  case '4' :  {gotoxy(18,19);cprintf("   ");cap_edad();break;}
  case '5' :  {gotoxy(18,21);cprintf("  ");cap_sexo();break;}
  case '6' :  {gotoxy(59,11);cprintf("               ");cap_cargo();break;}
  case '7' :  {gotoxy(59,13);cprintf("               ");cap_sueldo();break;}
 }
 textbackground(2);textcolor(4);
 gotoxy(50,18);cprintf("  M o d i f i c a r   ");
 textbackground(15);textcolor(0);
 gotoxy(50,21);cprintf("      S a l i r       ");
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) {adic(h,w);break;}
	   if (sw==1) {adic(h,w);sw1=1;break;}
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(50,18);cprintf("  M o d i f i c a r   ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("      S a l i r       ");
	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(50,18);cprintf("  M o d i f i c a r   ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("      S a l i r       ");
	  }
  }
}
fondo();
}
void elim_emp()
{
 int c,h,sw=0,a;char opcion;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("ELIMINACION REGISTRO DE EMPLEADO");
 cuadrop(3,8,45,23);cuadrop(46,8,78,15);
 gotoxy(4,8);cprintf("Datos Personales");
 gotoxy(47,8);cprintf("Laborales");
 gotoxy(4,11);cprintf("Codigo......: ");
 gotoxy(4,13);cprintf("Nombres.....: ");
 gotoxy(4,15);cprintf("Apellidos...: ");
 gotoxy(4,17);cprintf("Est. Civil..: ");
 gotoxy(4,19);cprintf("Edad........: ");
 gotoxy(4,21);cprintf("Sexo........: ");
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(18,13);cprintf("                      ");
 gotoxy(18,15);cprintf("                      ");
 gotoxy(18,17);cprintf("          ");
 gotoxy(18,19);cprintf("   ");
 gotoxy(18,21);cprintf("  ");
 gotoxy(59,11);cprintf("               ");
 gotoxy(59,13);cprintf("               ");
 textbackground(1);
 gotoxy(47,11);cprintf("Cargo.....: ");
 gotoxy(47,13);cprintf("Sueldo....: ");
 textbackground(15);textcolor(0);
 gotoxy(50,18);cprintf("  E l i m i n a r     ");
 gotoxy(50,21);cprintf("  C a n c e l a r     ");
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==0)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==1) {break;}
  }
 h=hash();
 if (strcmp(emp[h].codigo,r.codigo)==0)
    {
	a=1;
	strcpy(r.codigo,emp[h].codigo);
	strcpy(r.nombre,emp[h].nombre);
	strcpy(r.apellido,emp[h].apellido);
	strcpy(r.edad,emp[h].edad);
	strcpy(r.civil,emp[h].civil);
	r.sexo=emp[h].sexo;
	strcpy(r.cargo,emp[h].cargo);
	strcpy(r.sueldo,emp[h].sueldo);
	textbackground(15);textcolor(0);
	gotoxy(18,13);cprintf("%s",emp[h].nombre);
	gotoxy(18,15);cprintf("%s",emp[h].apellido);
	gotoxy(18,17);cprintf("%s",emp[h].civil);
	gotoxy(18,19);cprintf("%s",emp[h].edad);
	gotoxy(18,21);cprintf("%c",emp[h].sexo);
	gotoxy(59,11);cprintf("%s",emp[h].cargo);
	gotoxy(59,13);cprintf("%s",emp[h].sueldo);
    }
 else
    {
	a=2;
	p=&emp[h];
	while(p->sig != NULL)
		 {
		  q=p;
		  p=p->sig;
		  if (strcmp(p->codigo,r.codigo)==0)
			 {
			   strcpy(r.codigo,p->codigo);
			   strcpy(r.nombre,p->nombre);
			   strcpy(r.apellido,p->apellido);
			   strcpy(r.civil,p->civil);
			   strcpy(r.edad,p->edad);
			   r.sexo=p->sexo;
			   strcpy(r.cargo,p->cargo);
			   strcpy(r.sueldo,p->sueldo);
			   textbackground(15);textcolor(0);
			   gotoxy(18,13);cprintf("%s",p->nombre);
			   gotoxy(18,15);cprintf("%s",p->apellido);
			   gotoxy(18,17);cprintf("%s",p->civil);
			   gotoxy(18,19);cprintf("%s",p->edad);
			   gotoxy(18,21);cprintf("%c",p->sexo);
			   gotoxy(59,11);cprintf("%s",p->cargo);
			   gotoxy(59,13);cprintf("%s",p->sueldo);
			   break;
			 }
		 }
	 }
 textbackground(2);textcolor(4);
 gotoxy(50,18);cprintf("   E l i m i n a r    ");
 textbackground(15);textcolor(0);
 gotoxy(50,21);cprintf("   C a n c e l a r    ");
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) {elimina(h,a);break;}
	   if (sw==1) {break;}
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(50,18);cprintf("   E l i m i n a r    ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("   C a n c e l a r    ");
	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(50,18);cprintf("   E l i m i n a r    ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("   C a n c e l a r    ");
	  }
  }
 fondo();
}

void con_emp()
{
 int c,h,sw=0,sw1=0;char opcion;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("CONSULTA REGISTRO DE EMPLEADO");
 cuadrop(3,8,45,23);cuadrop(46,8,78,15);
 gotoxy(4,8);cprintf("Datos Personales");
 gotoxy(47,8);cprintf("Laborales");
 gotoxy(4,11);cprintf("Codigo......: ");
 gotoxy(4,13);cprintf("Nombres.....: ");
 gotoxy(4,15);cprintf("Apellidos...: ");
 gotoxy(4,17);cprintf("Est. Civil..: ");
 gotoxy(4,19);cprintf("Edad........: ");
 gotoxy(4,21);cprintf("Sexo........: ");
 gotoxy(47,11);cprintf("Cargo.....: ");
 gotoxy(47,13);cprintf("Sueldo....: ");
 while(sw1==0)
 {
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(18,13);cprintf("                      ");
 gotoxy(18,15);cprintf("                      ");
 gotoxy(18,17);cprintf("          ");
 gotoxy(18,19);cprintf("   ");
 gotoxy(18,21);cprintf("  ");
 gotoxy(59,11);cprintf("               ");
 gotoxy(59,13);cprintf("               ");
 textbackground(15);textcolor(0);
 gotoxy(50,18);cprintf("        M a s         ");
 gotoxy(50,21);cprintf("      S a l i r       ");
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==0)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==1) {break;}
  }
 h=hash();
 if (strcmp(emp[h].codigo,r.codigo)==0)
    {
	strcpy(r.codigo,emp[h].codigo);
	strcpy(r.nombre,emp[h].nombre);
	strcpy(r.apellido,emp[h].apellido);
	strcpy(r.edad,emp[h].edad);
	strcpy(r.civil,emp[h].civil);
	r.sexo=emp[h].sexo;
	strcpy(r.cargo,emp[h].cargo);
	strcpy(r.sueldo,emp[h].sueldo);
	textbackground(15);textcolor(0);
	gotoxy(18,13);cprintf("%s",emp[h].nombre);
	gotoxy(18,15);cprintf("%s",emp[h].apellido);
	gotoxy(18,17);cprintf("%s",emp[h].civil);
	gotoxy(18,19);cprintf("%s",emp[h].edad);
	gotoxy(18,21);cprintf("%c",emp[h].sexo);
	gotoxy(59,11);cprintf("%s",emp[h].cargo);
	gotoxy(59,13);cprintf("%s",emp[h].sueldo);
    }
 else
    {
	p=&emp[h];
	while(p->sig != NULL)
		 {
		  q=p;
		  p=p->sig;
		  if (strcmp(p->codigo,r.codigo)==0)
			 {
			   strcpy(r.codigo,p->codigo);
			   strcpy(r.nombre,p->nombre);
			   strcpy(r.apellido,p->apellido);
			   strcpy(r.civil,p->civil);
			   strcpy(r.edad,p->edad);
			   r.sexo=p->sexo;
			   strcpy(r.cargo,p->cargo);
			   strcpy(r.sueldo,p->sueldo);
			   textbackground(15);textcolor(0);
			   gotoxy(18,13);cprintf("%s",p->nombre);
			   gotoxy(18,15);cprintf("%s",p->apellido);
			   gotoxy(18,17);cprintf("%s",p->civil);
			   gotoxy(18,19);cprintf("%s",p->edad);
			   gotoxy(18,21);cprintf("%c",p->sexo);
			   gotoxy(59,11);cprintf("%s",p->cargo);
			   gotoxy(59,13);cprintf("%s",p->sueldo);
			   break;
			 }
		 }
	 }
 textbackground(2);textcolor(4);
 gotoxy(50,18);cprintf("        M a s         ");
 textbackground(15);textcolor(0);
 gotoxy(50,21);cprintf("      S a l i r       ");
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) {break;}
	   if (sw==1) {sw1=1;break;}
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(50,18);cprintf("        M a s         ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("      S a l i r       ");
	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(50,18);cprintf("        M a s         ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("      S a l i r       ");
	  }
    }
  }
 fondo();
}
void liquidacion()
{
 int sw;
 for(i=0;i<100;i++)
	{
	  sw=0;
	  if(emp[i].codigo[0]!='\x0')
	    {
		for (j=0;j<=pos;j++)
		  {
		   if (strcmp(lq[j].codigo,emp[i].codigo)==0)
			 sw=1;
		  }
		  if (sw==0)
		    { 
			strcpy(lq[pos].codigo,emp[i].codigo);
			strcpy(lq[pos].nombre,emp[i].nombre);
			strcpy(lq[pos].apellido,emp[i].apellido);
			lq[pos].sueldo=atol(emp[i].sueldo);
			pos++;
		    }
	    }
	  if(emp[i].sig!=NULL)
		{
		   q=&emp[i];
		   while(q->sig!=NULL)
			{
			  q=q->sig;
			  for (j=0;j<=pos;j++)
				{
				 if (strcmp(lq[j].codigo,q->codigo)==0)
				    sw=1;
				 }
			  if (sw==0)
			    { 
				  strcpy(lq[pos].codigo,q->codigo);
				  strcpy(lq[pos].nombre,q->nombre);
				  strcpy(lq[pos].apellido,q->apellido);
				  lq[pos].sueldo=atol(q->sueldo);
				  pos++;
				}
			}
		}
	 }
 for (i=0;i<=pos-1;i++)
	 {
	  for (j=0;j<=50;j++)
		  {
			if (strcmp(lq[i].codigo,n[j].codigo)==0)
			  {
			    if (n[j].tipo=='+')
				   lq[i].salario=(lq[i].sueldo+n[j].valor);
			    else
				   lq[i].salario=(lq[i].sueldo-n[j].valor); 					    
			   }
		   }
	 }  
  for (i=0;i<=pos-1;i++)
    {
	if (lq[i].salario==0)
	   lq[i].salario=lq[i].sueldo;
	}
 fondo1(9);
 textbackground(1);textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(30,6);cprintf("NOMINA DE EMPLEADOS");
 gotoxy(5,8);cprintf("CODIGO");
 gotoxy(18,8);cprintf("NOMBRE");
 gotoxy(34,8);cprintf("APELLIDO");
 gotoxy(52,8);cprintf("SUELDO");
 gotoxy(64,8);cprintf("SALARIO");
 for (i=0;i<=pos-1;i++)
	{
	 gotoxy(4,10+i);cprintf("%s",lq[i].codigo);
	 gotoxy(16,10+i);cprintf("%s",lq[i].nombre);
	 gotoxy(32,10+i);cprintf("%s",lq[i].apellido);
	 gotoxy(52,10+i);cprintf("%ld",lq[i].sueldo);
	 gotoxy(66,10+i);cprintf("%ld",lq[i].salario);
	}
 mensaje("Presione una tecla para continuar                      ",25);
 getch();
 fondo();
}
void imprimir()
{
 int i;char salario[10],sueldo[10];
 fprintf(stdprn,"\n\n\n\n\n\n\r");
 fprintf(stdprn,"                            NOMINA DE EMPLEADOS\n\n\n\n\r");       
 for (i=0;i<=pos-1;i++)
   { 
	ltoa(lq[i].sueldo,sueldo,10);
	ltoa(lq[i].salario,salario,10);
	fprintf(stdprn,"   Codigo   : %s\n\r",lq[i].codigo); 
	fprintf(stdprn,"   Nombre   : %s\n\r",lq[i].nombre); 
	fprintf(stdprn,"   Apellido : %s\n\r",lq[i].apellido);
	fprintf(stdprn,"   Sueldo   : %s\n\r",sueldo); 
	fprintf(stdprn,"   Salario  : %s\n\n\n\r",salario); 
   }
}
void cap_codigo()
{
 int i=0,sw=0,c;char codi;
 strcpy(r.codigo,"");
 gotoxy(18,11);
 while (i<=7)
 {
  codi=getch();
  if (codi>=48 && codi<=57)
    {
	 r.codigo[i]=codi;
	 gotoxy(18+i,11);cprintf("%c",r.codigo[i]);
	 i=i+1;sw=1;
    }  
  if ((codi==8) && (sw==1)) 
    {
	i=i-1;
	gotoxy(18+i,11);cprintf(" ");
	gotoxy(18+i,11);
	if (i==0) sw=0;
    }		 
   }
}

void cap_nombre()
{
 int i=0,sw=0,j;char nomb;
 gotoxy(18,13);
 while (i<=19)
 {
  nomb=getch();
  if (nomb>=65 && nomb<=122 || nomb==32)
    {
	 r.nombre[i]=nomb;
	 gotoxy(18+i,13);cprintf("%c",r.nombre[i]);
	 i=i+1;sw=1;
    }  
  if ((nomb==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.nombre[i],"");
	gotoxy(18+i,13);cprintf(" ");
	gotoxy(18+i,13);
	if (i==0) sw=0;
    }		 
  if (nomb==13 && i>=1)
	 {
	   strcpy(r.nombre[i],"");
	   break;
	}
 }	
}
void cap_apellido()
{
 int i=0,sw=0;char apel;
 gotoxy(18,15);
 while (i<=19)
 {
  apel=getch();
  if (apel>=65 && apel<=122 || apel==32)
    {
	 r.apellido[i]=apel;
	 gotoxy(18+i,15);cprintf("%c",r.apellido[i]);
	 i=i+1;sw=1;
    }  
  if ((apel==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.apellido[i],"");
	gotoxy(18+i,15);cprintf(" ");
	gotoxy(18+i,15);
	if (i==0) sw=0;
    }		 
  if (apel==13 && i>=1)
	 {
	   strcpy(r.apellido[i],"");
	   break;
	 }
  }	
}
void cap_civil()
{
 int i=0,sw=0;char civil;
 gotoxy(18,17);
 while (i<=9)
 {
  civil=getch();
  if (civil>=65 && civil<=122 || civil==32)
    {
	 r.civil[i]=civil;
	 gotoxy(18+i,17);cprintf("%c",r.civil[i]);
	 i=i+1;sw=1;
    }  
  if ((civil==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.civil[i],"");
	gotoxy(18+i,17);cprintf(" ");
	gotoxy(18+i,17);
	if (i==0) sw=0;
    }		 
  if (civil==13 && i>=1)
	 {
	   strcpy(r.civil[i],"");
	   break; 
 }	 }
}
void cap_edad()
{
 int i=0,sw=0;char ed;
 gotoxy(18,19);
 while (i<2)
 {
  ed=getch();
  if (ed>=48 && ed<=57)
    {
	 r.edad[i]=ed;
	 gotoxy(18+i,19);cprintf("%c",r.edad[i]);
	 i=i+1;sw=1;
    }  
  if ((ed==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.edad[i],"");
	gotoxy(18+i,19);cprintf(" ");
	gotoxy(18+i,19);
	if (i==0) sw=0;
    }		 
  if (ed==13 && i>=1) 
	 {
	   strcpy(r.edad[i],"");
	   break;
	 }
 }	
}
void cap_sexo()
{
 char sex;
 r.sexo=' ';
 gotoxy(18,21);
 while (1)
 {
  sex=getch();
  sex=toupper(sex);
  if ( sex=='M'|| sex=='F')
    {
	 r.sexo=sex;
	 gotoxy(18,21);cprintf("%c",r.sexo);
    }  
  if (sex==13 && (r.sexo == 'M'|| r.sexo =='F'))
	break;
 }	
}
void cap_cargo()
{
 int i=0,sw=0;char car;
 gotoxy(59,11);
 while (i<=14)
 {
  car=getch();
  if (car>=65 && car<=122)
    {
	 r.cargo[i]=car;
	 gotoxy(59+i,11);cprintf("%c",r.cargo[i]);
	 i=i+1;sw=1;
    }  
  if ((car==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.cargo[i],"");
	gotoxy(59+i,11);cprintf(" ");
	gotoxy(59+i,11);
	if (i==0) sw=0;
    }		 
  if (car==13 && i>=1)
	{
	  strcpy(r.cargo[i],"");
	  break;
	}
  }	
}
void cap_sueldo()
{
 int i=0,sw=0,j;char sl;
 gotoxy(59,13);
 while (i<=7)
 {
  sl=getch();
  if (sl>=48 && sl<=57)
    {
	 r.sueldo[i]=sl;
	 gotoxy(59+i,13);cprintf("%c",r.sueldo[i]);
	 i=i+1;sw=1;
    }  
  if ((sl==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(r.sueldo[i],"");
	gotoxy(59+i,13);cprintf(" ");
	gotoxy(59+i,13);
	if (i==0) sw=0;
    }		 
 if (sl==13 && i>=1)
	{
	  strcpy(r.sueldo[i],"");
	  break;
	}
 }	
}
int buscar_cod()
{
 int h,a,sw;
 h=hash();
 sw=0;
 if (strcmp(emp[h].codigo,"") == 0)
	a=0;
 else
   {
    if (strcmp(emp[h].codigo,r.codigo) == 0)
	  a=1;
    else
	  {
	    p=&emp[h];
	    while(p->sig != NULL	)
		 {
		  p=p->sig;
		  if (strcmp(p->codigo,r.codigo)==0)
			 {a=1;sw=1;}
		 }
		if (sw==0) a=0;
	  }
    }	 
return(a);
} 

void adiciona()
{
 int h;
 h=hash();
 if (emp[h].codigo[0]=='\x0')
    {

	strcpy(emp[h].codigo,r.codigo);
	strcpy(emp[h].nombre,r.nombre);
	strcpy(emp[h].apellido,r.apellido);
	strcpy(emp[h].edad,r.edad);
	strcpy(emp[h].civil,r.civil);
	emp[h].sexo=r.sexo;
	strcpy(emp[h].cargo,r.cargo);
	strcpy(emp[h].sueldo,r.sueldo);
    }
 else
    {
	nuevo=localizar;
	strcpy(nuevo->codigo,r.codigo);
	strcpy(nuevo->nombre,r.nombre);
	strcpy(nuevo->apellido,r.apellido);
	strcpy(nuevo->civil,r.civil);
	strcpy(nuevo->edad,r.edad);
	nuevo->sexo=r.sexo;
	strcpy(nuevo->cargo,r.cargo);
	strcpy(nuevo->sueldo,r.sueldo);
	q=&emp[h];
	while(q->sig!=NULL)
	   {
		q=q->sig;
	   }
	   q->sig=nuevo;
    }
}

int hash()
{
 int a,b;
 switch(r.codigo[3])
 {
  case '1' : a=1;break;
  case '2' : a=2;break;
  case '3' : a=3;break;
  case '4' : a=4;break;
  case '5' : a=5;break;
  case '6' : a=6;break;
  case '7' : a=7;break;
  case '8' : a=8;break;
  case '9' : a=9;break;
 }
 switch(r.codigo[6])
 {
  case '1' : b=1;break;
  case '2' : b=2;break;
  case '3' : b=3;break;
  case '4' : b=4;break;
  case '5' : b=5;break;
  case '6' : b=6;break;
  case '7' : b=7;break;
  case '8' : b=8;break;
  case '9' : b=9;break;
 }
 a=a*10;
 return(a+b);
}
int hash1()
{
 int a,b;
 switch(f.codigo[3])
 {
  case '1' : a=1;break;
  case '2' : a=2;break;
  case '3' : a=3;break;
  case '4' : a=4;break;
  case '5' : a=5;break;
  case '6' : a=6;break;
  case '7' : a=7;break;
  case '8' : a=8;break;
  case '9' : a=9;break;
 }
 switch(f.codigo[6])
 {
  case '1' : b=1;break;
  case '2' : b=2;break;
  case '3' : b=3;break;
  case '4' : b=4;break;
  case '5' : b=5;break;
  case '6' : b=6;break;
  case '7' : b=7;break;
  case '8' : b=8;break;
  case '9' : b=9;break;
 }
 a=a*10;
 return(a+b);
}

void mensaje(char men[60],int c)
{
 textcolor(5);textbackground(7);
 gotoxy(2,c);cprintf(" %s",men);
}

void cuadrop( x1, y1, x2, y2)
{
 for(i=x1;i<x2;i=i+1)
  {       	
   gotoxy(i,y1);
   cprintf("Ä");
   gotoxy(i,y2);
   cprintf("Ä");
  }
  for (j=y1;j<y2;j=j+1)
   {
    gotoxy(x1,j);
    cprintf("³");
    gotoxy(x2,j);
    cprintf("³");
    }
   gotoxy(x1,y1);
  cprintf("Ú");
  gotoxy(x1,y2);
  cprintf("À");
  gotoxy(x2,y1);
  cprintf("¿");
  gotoxy(x2,y2);
  cprintf("Ù");
} 
void cuadrog( x1, y1, x2, y2)
{
 for(i=x1;i<x2;i=i+1)
  {
   gotoxy(i,y1);
   cprintf("Í");
   gotoxy(i,y2);
   cprintf("Í");
  }
 for (j=y1;j<y2;j=j+1)
  {
   gotoxy(x1,j);
   cprintf("º");
   gotoxy(x2,j);
   cprintf("º");
  }
 gotoxy(x1,y1);
 cprintf("É");
 gotoxy(x1,y2);
 cprintf("È");
 gotoxy(x2,y1);
 cprintf("»");
 gotoxy(x2,y2);
 cprintf("¼");
}

void limpia()
{
 int j;
 for (j=0;j<=20;j++)
	 strcpy(r.nombre[j],'\x0');
 for (j=0;j<=20;j++)
	 strcpy(r.apellido[j],'\x0');
 for (j=0;j<=15;j++)
	 strcpy(r.civil[j],"");
 for (j=0;j<=4;j++)
	 strcpy(r.edad[j],'\x0');
 r.sexo=' ';
 for (j=0;j<=15;j++)
	 strcpy(r.cargo[j],'\x0');
 for (j=0;j<=10;j++)
	 strcpy(r.sueldo[j],'\x0');
}
void adic(int h,int val)
{
   if (val==1)
	{
	strcpy(emp[h].codigo,r.codigo);
	strcpy(emp[h].nombre,r.nombre);
	strcpy(emp[h].apellido,r.apellido);
	strcpy(emp[h].edad,r.edad);
	strcpy(emp[h].civil,r.civil);
	emp[h].sexo=r.sexo;
	strcpy(emp[h].cargo,r.cargo);
	strcpy(emp[h].sueldo,r.sueldo);
    }
 else
    {
	strcpy(p->codigo,r.codigo);
	strcpy(p->nombre,r.nombre);
	strcpy(p->apellido,r.apellido);
	strcpy(p->civil,r.civil);
	strcpy(p->edad,r.edad);
	p->sexo=r.sexo;
	strcpy(p->cargo,r.cargo);
	strcpy(p->sueldo,r.sueldo);
  }
}
void elimina(int h,int a)
{
 if (a==1)
 {
   d=emp[h].sig;
   strcpy(emp[h].codigo,d->codigo);
   strcpy(emp[h].nombre,d->nombre);
   strcpy(emp[h].apellido,d->apellido);
   strcpy(emp[h].edad,d->edad);
   strcpy(emp[h].civil,d->civil);
   emp[h].sexo=d->sexo;
   strcpy(emp[h].cargo,d->cargo);
   strcpy(emp[h].sueldo,d->sueldo);
   emp[h].sig=d->sig;
 }
 else
 {
  q->sig=p->sig;
  free(p); 
 }
} 
void adic_nov()
{
 int c,sw=0,sw1=0;char sl,sueldo[9],opcion,fecha[10];
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(27,6);cprintf("ADICION NOVEDAD DE EMPLEADO");
 cuadrop(3,8,78,19);
 gotoxy(4,11);cprintf("Codigo Emp...: ");
 gotoxy(4,13);cprintf("Codigo Nov...: ");
 gotoxy(4,15);cprintf("Valor........: ");
 gotoxy(4,17);cprintf("Fecha........: ");
 while(sw1==0)
 {
 textbackground(15);
 gotoxy(18,11);cprintf("        ");
 gotoxy(18,13);cprintf("  ");
 gotoxy(18,15);cprintf("         ");
 gotoxy(18,17);cprintf("      ");
 textbackground(15);textcolor(0);
 gotoxy(42,11);cprintf("   A c e p t a r    ");
 gotoxy(42,15);cprintf("     S a l i r      ");
 gotoxy(18,11);
 while(1)
  {
   cap_codigo();
   c=buscar_cod();
	if (c==0)
	  {
	    textbackground(15);
	    gotoxy(18,11);cprintf("        ");
	  }
	 if (c==1) {break;}
  }
  strcpy(n[cont1].codigo,r.codigo);
  cap_nueva_nov();
  gotoxy(18,15);cprintf("         "); 
  gotoxy(18,15);
  i=0;
  while (i<=5)
  {
  sl=getch();
  if (sl>=48 && sl<=57)
    {
	 sueldo[i]=sl;
	 gotoxy(18+i,15);cprintf("%c",sueldo[i]);
	 i=i+1;sw=1;
    }  
  if ((sl==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(sueldo[i],"");
	gotoxy(18+i,15);cprintf(" ");
	gotoxy(18+i,15);
	if (i==0) sw=0;
    }		 
  if (sl==13 && i>=1)
	{
	  strcpy(sueldo[i],"");
	  break;
	}
  }	
  n[cont1].valor=atol(sueldo);
  i=0;
  gotoxy(18,17);
  while (i<=6)
  {
  sl=getch();
  if (sl>=48 && sl<=57)
    {
	 fecha[i]=sl;
	 gotoxy(18+i,17);cprintf("%c",fecha[i]);
	 i=i+1;sw=1;
    }  
  if ((sl==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(fecha[i],"");
	gotoxy(18+i,17);cprintf(" ");
	gotoxy(18+i,17);
	if (i==0) sw=0;
    }		 
  if (sl==13 && i>=1)
	{
	  strcpy(fecha[i],"");
	  break;
	}
  }
  textbackground(2);textcolor(4);
  gotoxy(42,11);cprintf("   A c e p t a r    ");
  textbackground(15);textcolor(0);
  gotoxy(42,15);cprintf("     S a l i r      ");
  sw=0;
  while(1)
  {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) 
		 {
		   strcpy(n[cont1].valor,sueldo);
		   strcpy(n[cont1].fecha,fecha);
		   cont1++;
		   break;
		 }

	   if (sw==1) 
		 {
		   strcpy(n[cont1].valor,sueldo);
		   cont1++;
		   sw1=1;break;
		 }
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(42,11);cprintf("   A c e p t a r    ");
	  textbackground(2);textcolor(4);
	  gotoxy(42,15);cprintf("     S a l i r      ");

	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(42,11);cprintf("   A c e p t a r    ");
	   textbackground(15);textcolor(0);
	   gotoxy(42,15);cprintf("     S a l i r      ");

	  }
    }
  }
 fondo();
}

void cargar()
{  
   int a,h,n;
	a=_open("c:\\empleados.dat",4);
	if(a==-1)
	{
		a=_creat("c:\\empleados.dat",FA_ARCH);
		if(a==-1)
		{
			gotoxy(10,3);
			textbackground(1),textcolor(3+128);
			cprintf("Error el Archivo");
			getch();
			exit(0);
		}
	}
	h=0;
	lseek(a,0L,0);
	while(!eof(a))
	{
		if ((_read(a,&f,sizeof(f)))!=sizeof(f))
		{
			clrscr();
			gotoxy(10,6);
			cprintf("Error de lectura en el sistema");
		}
		else
		{
			h=hash1();
			if(emp[h].codigo[0]=='\x0')
			{
				strcpy(emp[h].codigo,f.codigo);
				strcpy(emp[h].nombre,f.nombre);
				strcpy(emp[h].apellido,f.apellido);
				strcpy(emp[h].civil,f.civil);
				strcpy(emp[h].edad,f.edad);
				emp[h].sexo=f.sexo;
				strcpy(emp[h].cargo,f.cargo);
				strcpy(emp[h].sueldo,f.sueldo);
				emp[h].sig=NULL;
			}
			else
			{
				nuevo=localizar;
				strcpy(nuevo->codigo,f.codigo);
				strcpy(nuevo->nombre,f.nombre);
				strcpy(nuevo->apellido,f.apellido);
				strcpy(nuevo->civil,f.civil);
				strcpy(nuevo->edad,f.edad);
				nuevo->sexo=f.sexo;
				strcpy(nuevo->cargo,f.cargo);
				strcpy(nuevo->sueldo,f.sueldo);
				nuevo->sig=NULL;
				q=&emp[h];
				while(q->sig!=NULL)
				{
					q=q->sig;
				}
				q->sig=nuevo;
			}
		}
	}
	_close(a);
	n=_open("c:\\novedades.dat",4);
	if(n==-1)
	{
		n=_creat("c:\\novedades.dat",FA_ARCH);
		if(n==-1)
		{
			gotoxy(10,6);
			cprintf("Error de entrada del sistema");
			getch();
			exit(0);
		}
	}

	lseek(n,0L,0);
	while(!eof(n))
	{
		if ((_read(n,&nov,sizeof(nov)))!=sizeof(nov))
		{
			clrscr();
			gotoxy(10,6);
			cprintf("Error de lectura en el Archivo");
		}
		else
		{
		  if (nov.codigo[0]!='\x0')
			{
			  strcpy(novedad[cont].codigo,nov.codigo);
			  strcpy(novedad[cont].des,nov.des);
			  novedad[cont].tipo=nov.tipo;
			  cont++;
			}
		}
	}
	_close(n);
}
void nove()
{
 int i=0,sw=0,sw1=0,j,s;char ed,opcion;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("ADICION A LA BASE DE DATOS");
 cuadrop(3,10,75,18);
 gotoxy(4,11);cprintf("Codigo.........: ");
 gotoxy(4,13);cprintf("Descripcion....: ");
 gotoxy(4,15);cprintf("Concepto (+/-).:");
 textbackground(15);
while(sw1==0)
{
 gotoxy(21,11);cprintf("  ");
 gotoxy(21,13);cprintf("                                 ");
 gotoxy(21,15);cprintf(" ");
 textbackground(1);
 textbackground(15);textcolor(0);
 gotoxy(25,21);cprintf("   A c e p t a r    ");
 gotoxy(50,21);cprintf("     S a l i r      ");
 gotoxy(21,11);
 while(1)
 {
  i=0;
  while (i<2)
  {
   ed=getch();
   if (ed>=48 && ed<=57)
    {
	 nov.codigo[i]=ed;
	 gotoxy(21+i,11);cprintf("%c",nov.codigo[i]);
	 i=i+1;sw=1;
    }  
   if ((ed==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(nov.codigo[i],"");
	gotoxy(21+i,11);cprintf(" ");
	gotoxy(21+i,11);
	if (i==0) sw=0;
    }		 
  if (ed==13 && i>=1) 
	 {
	   strcpy(nov.codigo[i],"");
	   break;
	 }
  }
 for(j=0;j<=50;j++)
  {
   if (strcmp(nov.codigo,novedad[j].codigo)!=0)
	s=1; 
   if (strcmp(nov.codigo,novedad[j].codigo)==0)
	{s=0;j=50;gotoxy(21,11);cprintf("  ");}
  }
  if (s==1) break;
 }
 gotoxy(21,13);sw=0;
 i=0;
 while (i<=30)
 {
  ed=getch();
  if (ed>=65 && ed<=122 || ed==32)
    {
	 nov.des[i]=ed;
	 gotoxy(21+i,13);cprintf("%c",nov.des[i]);
	 i=i+1;sw=1;
    }  
  if ((ed==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(nov.des[i],"");
	gotoxy(21+i,13);cprintf(" ");
	gotoxy(21+i,13);
	if (i==0) sw=0;
    }		 
  if (ed==13 && i>=1)
	 {
	   strcpy(nov.des[i],"");
	   break;
	 }
  }
 gotoxy(21,15);
 nov.tipo=' ';
 i=0;
 while (1)
 {
  ed=getch();
  if ( ed=='+'|| ed=='-')
    {
	 nov.tipo=ed;
	 gotoxy(21,15);cprintf("%c",nov.tipo);
    }  
  if (ed==13 && (nov.tipo == '+'|| nov.tipo =='-'))
	break;
 }
 textbackground(2);textcolor(4);
 gotoxy(25,21);cprintf("   A c e p t a r    ");
 textbackground(15);textcolor(0);
 gotoxy(50,21);cprintf("     S a l i r      ");
 sw=0;
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) 
		 {
		   strcpy(novedad[cont].codigo,nov.codigo);
		   strcpy(novedad[cont].des,nov.des);
		   novedad[cont].tipo=nov.tipo;
		   cont++;
		   break;
		 }

	   if (sw==1) 
		 {
		   strcpy(novedad[cont].codigo,nov.codigo);
		   strcpy(novedad[cont].des,nov.des);
		   novedad[cont].tipo=nov.tipo;
		   cont++;
		   sw1=1;break;
		 }
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(25,21);cprintf("   A c e p t a r    ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("     S a l i r      ");

	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(25,21);cprintf("   A c e p t a r    ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("     S a l i r      ");

	  }
  }
 }
  fondo();
}

void con_nov()
{
 int i,sw=0,sw1=0,j,s,a;char ed,opcion;
 fondo1(9);
 textcolor(15);
 cuadrog(2,6,79,24);
 gotoxy(25,6);cprintf("ADICION A LA BASE DE DATOS");
 cuadrop(3,10,75,18);
 gotoxy(4,11);cprintf("Codigo.........: ");
 gotoxy(4,13);cprintf("Descripcion....: ");
 gotoxy(4,15);cprintf("Concepto (+/-).:");
 textbackground(15);
 while(sw1==0)
 {
   gotoxy(21,11);cprintf("  ");
   gotoxy(21,13);cprintf("                                 ");
   gotoxy(21,15);cprintf(" ");
   textbackground(1);
   textbackground(15);textcolor(0);
   gotoxy(25,21);cprintf("       M a s        ");
   gotoxy(50,21);cprintf("     S a l i r      ");
   gotoxy(21,11);
   while(1)
   {
    i=0;
    while (i<2)
	{
	  ed=getch();
	  if (ed>=48 && ed<=57)
	    {
		 nov.codigo[i]=ed;
		 gotoxy(21+i,11);cprintf("%c",nov.codigo[i]);
		 i=i+1;sw=1;
	    }  
	 if ((ed==8) && (sw==1)) 
	   {
	    i=i-1;
	    strcpy(nov.codigo[i],"");
	    gotoxy(21+i,11);cprintf(" ");
	    gotoxy(21+i,11);
	    if (i==0) sw=0;
	   }  		 
	if (ed==13 && i>=1) 
	 {
	   strcpy(nov.codigo[i],"");
	   break;
	 }
   }
   for(j=0;j<=50;j++)
    {
	  if (strcmp(nov.codigo,novedad[j].codigo)!=0)
		s=0;
	  if (strcmp(nov.codigo,novedad[j].codigo)==0)
		 {s=1;a=j;j=50;}
    }
    if (s==0) 
	  {gotoxy(21,11);cprintf("  ");}
    else
	  break;
  }
 gotoxy(21,13);cprintf("%s",novedad[a].des);
 gotoxy(21,15);cprintf("%c",novedad[a].tipo);
 textbackground(2);textcolor(4);
 gotoxy(25,21);cprintf("       M a s        ");
 textbackground(15);textcolor(0);
 gotoxy(50,21);cprintf("     S a l i r      ");
 sw=0;
 while(1)
 {
	 opcion=getch();
   if (opcion==13)
	 {
	   if (sw==0) 
		 {
		   break;
		 }

	   if (sw==1) 
		 {
		   sw1=1;break;
		 }
	 }
   if (opcion==9)
	 {
	  if (sw==1) sw=0;  
	  else    sw=1;
	 }
   if (sw==1)
	 { 
	  textbackground(15);textcolor(0);
	  gotoxy(25,21);cprintf("       M a s        ");
	  textbackground(2);textcolor(4);
	  gotoxy(50,21);cprintf("     S a l i r      ");

	  }
   if (sw==0)
	  {
	   textbackground(2);textcolor(4);
	   gotoxy(25,21);cprintf("       M a s        ");
	   textbackground(15);textcolor(0);
	   gotoxy(50,21);cprintf("     S a l i r      ");

	  }
  }

 }
 fondo();
}
void salir()
{
  int a,n,error;
	a=_open("c:\\empleados.dat",4);
	if(a==-1)
	{
		a=_creat("c:\\empleados.dat",FA_ARCH);
		if(a==-1)
		{
			gotoxy(10,3);
			textbackground(1),textcolor(3+128);
			cprintf("Error el Archivo");
			getch();
			exit(0);
		}
	}
  lseek(a,0L,0);
  for(i=0;i<100;i++)
	{
	  if(emp[i].codigo[0]!='\x0')
	    {
		 error=_write(a,&emp[i],sizeof(f));
		 if (error!= sizeof(f))
			cprintf("No es posible escribir el archivo");
		 if(emp[i].sig!=NULL)
		   {
		    q=&emp[i];
		    while(q->sig!=NULL)
			 {
			  q=q->sig;
			  error=_write(a,q,sizeof(f));
			  if (error!= sizeof(f))
				cprintf("No es posible escribir el archivo");
			 }
		  }
	  }
	}
   _close(a);
	n=_open("c:\\novedades.dat",4);
	if(n==-1)
	{
		n=_creat("c:\\novedades.dat",FA_ARCH);
		if(n==-1)
		{
			gotoxy(10,6);
			cprintf("Error de entrada del sistema");
			getch();
			exit(0);
		}
	}
   lseek(n,0L,0);
   for(i=0;i<50;i++)
	{
	  if (novedad[i].codigo[0]!='\x0')
	   {
		 error=_write(n,&novedad[i],sizeof(nov));
		 if (error!= sizeof(nov))
		 cprintf("No es posible escribir el archivo");
	   }
	}
  _close(n);
}
void cap_nueva_nov()
{
 int i,sw,s,sw1=0;char ed;
 gotoxy(18,13);
 while(sw1==0)
 {
  i=0;
  while (i<2)
  {
   ed=getch();
   if (ed>=48 && ed<=57)
    {
	 n[cont1].cod[i]=ed;
	 gotoxy(18+i,13);cprintf("%c",n[cont1].cod[i]);
	 i=i+1;sw=1;
    }  
   if ((ed==8) && (sw==1)) 
    {
	i=i-1;
	strcpy(n[cont1].cod[i],"");
	gotoxy(18+i,13);cprintf(" ");
	gotoxy(18+i,13);
	if (i==0) sw=0;
    }		 
  if (ed==13 && i>=1) 
	 {
	   strcpy(n[cont1].cod[i],"");
	   break;
	 }
  }
 for(j=0;j<=50;j++)
  {
	 if (strcmp(n[cont1].cod,novedad[j].codigo)!=0)
		 sw=1;
	 if (strcmp(n[cont1].cod,novedad[j].codigo)==0)
		{
		 j=50;sw=0;
		 sw1=1;n[cont1].tipo=novedad[j].tipo;
		}
   }
  if (sw==1) {gotoxy(18,13);cprintf("  ");gotoxy(18,13);}
 }
}
