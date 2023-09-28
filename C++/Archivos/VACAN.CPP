//***********ARCHIVOS**************************

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <fstream.h>
#include <iomanip.h>
#include <dos.h>

void barra_menu();
int tecla();
char tecla_menu();
void cuadro( int x,int x2, int y, int y2);
void fondo();
void menu_captura();
void captura();
void menu_consulta_ind();
void consulta_ind();
void consulta_aprob();
void consulta_reprob();
struct registro {
   long CODIGO;
   char NOMBRE[30];
   char MATERIA[20];
   float NOTA1;
   float NOTA2;
   float NOTA3;
   float DEF;
  }est;

void main()
{
 char opcion='S';
 int op;
 while(opcion=='S')
   {
     fondo();
     op=tecla();
	switch(op) {
	case 1:
	    captura();
	 break;
	case 2:
	  consulta_ind();
	  break;
	case 3:
	  consulta_aprob();
	  break;
	case 4:
	  consulta_reprob();
	break;
	case 5:
	   opcion='N';
	break;
	}

}
}

void menu_captura()
{
  fondo();
  cuadro(9,18,5,75);
  gotoxy(25,9); cout <<"MENU CAPTURA DATOS ALUMNO";
  gotoxy(15,11); cout <<"CODIGO        [             ]";
  gotoxy(15,12); cout <<"NOMBRE        [                         ]";
  gotoxy(15,13); cout <<"ASIGNATURA    [                   ]";
  gotoxy(15,14); cout <<"PRIMERA NOTA  [   ]";
  gotoxy(15,15); cout <<"SEGUNDA NOTA  [   ]";
  gotoxy(15,16); cout <<"TERCERA NOTA  [   ]";
}

void captura()
{
 char opcion='S';
 ofstream archivo("NOTAS.DAT", ios::app);
 while(opcion=='S')
   {
     menu_captura();
     gotoxy(30,11); cin>>est.CODIGO;
     gotoxy(30,12); gets(est.NOMBRE);
     gotoxy(30,13); gets(est.MATERIA);
     do {
	  gotoxy(30,14); cin>>est.NOTA1;
	}while(est.NOTA1<0 || est.NOTA1 >5);
     do {
     gotoxy(30,15); cin>>est.NOTA2;
	}while(est.NOTA2<0 || est.NOTA2 >5);
     do {
     gotoxy(30,16); cin>>est.NOTA3;
	}while(est.NOTA3<0 || est.NOTA3 >5);

     est.DEF=((est.NOTA1*0.3)+(est.NOTA2*0.3)+(est.NOTA3*0.4));
     archivo.write((char*)&est, sizeof(registro));
     ofstream consulta("consulta.dat", ios::app);
     consulta.write((char*)&est, sizeof(registro));
     consulta.close();
     opcion=tecla_menu();

   }
archivo.close();
 }

void menu_consulta_ind()
{
 fondo();
 cuadro(6,19,5,75);
 gotoxy(25,6); cout <<"MENU CONSULTA INDIVIDUAL ESTUDIANTE";
 gotoxy(15,8); cout <<"DIGITE CODIGO ESTUDIANTE   [          ]";
}

void consulta_ind()
{
 char SUICHE, opcion='S';
 long COD;
  ifstream consulta("consulta.dat");
    if (consulta.fail())
       {
	 gotoxy(15,15);  cout <<"El archivo no existe o fue eliminado";
	 getch();
	 consulta.close();
       }
	else
	{
	  while(opcion=='S')
	  {
	    SUICHE='N';
	    fondo();
	    menu_consulta_ind();
	    ifstream consulta("consulta.dat");
	    gotoxy(43,8); cin >>COD;
	    while(!consulta.eof() && SUICHE=='N')
		{
		  consulta.read((char*)&est, sizeof(registro));
		  if(COD==est.CODIGO)
		  SUICHE='S';
		}
	    if(consulta.eof())
	     {
	      gotoxy(15,10); cout <<"El alumno no se encuentra en registro";
	     }
	      else
	       {
		gotoxy(15,10); cout <<"NOMBRE            "<<est.NOMBRE;
		gotoxy(15,11); cout <<"ASIGNATURA        "<<est.MATERIA;
		gotoxy(15,12); cout <<"PRIMERA NOTA      "<<est.NOTA1;
		gotoxy(15,13); cout <<"SEGUNDA NOTA      "<<est.NOTA2;
		gotoxy(15,14); cout <<"TERCERA NOTA      "<<est.NOTA3;
		gotoxy(15,15); cout <<"NOTA DEFINITIVA   "<<est.DEF;

	       }
	     opcion=tecla_menu();
	     }

	}
consulta.close();
}

void consulta_aprob()
{
  int L;
  ifstream consulta("consulta.dat");
    if (consulta.fail())
       {
	 gotoxy(15,15);  cout <<"El archivo no existe o fue eliminado";
	 getch();
	 consulta.close();
       }
	else
	  {
	    fondo();
	    cuadro(7,19,5,75);
	    ifstream consulta("consulta.dat");
	    gotoxy(7,8); cout <<"CODIGO     NOMBRE           ASIGNATURA      NOTA1-NOTA2-NOTA3  DEF";

	    L=10;
	    do {
		 consulta.read((char*)&est, sizeof(registro));
		   if(consulta.eof()) break;
		   if(est.DEF>=3.0)
		     {
		       gotoxy(7,L); cout <<est.CODIGO;
		       gotoxy(18,L); cout <<est.NOMBRE;
		       gotoxy(35,L); cout <<est.MATERIA;
		       gotoxy(51,L); cout <<est.NOTA1;
		       gotoxy(57,L); cout <<est.NOTA2;
		       gotoxy(63,L); cout <<est.NOTA3;
		       gotoxy(70,L); cout <<est.DEF;
			 L++;
			 if(L==18)
			   {
			    gotoxy(15,21); cout <<"Presione cualquier tecla para continuar";
			    getch();
			    L=10;
			    fondo();
			    cuadro(7,19,5,75);
			    gotoxy(7,8); cout <<"CODIGO     NOMBRE       ASIGNATURA          NOTA1-NOTA2-NOTA3  DEF";
			   }
		    }
       }while(!consulta.eof());
       gotoxy(25,21); cout <<"Presione cualquier tecla para salir";
       getch();

}
consulta.close();
}

void consulta_reprob()
{
  int L;
  ifstream consulta("consulta.dat");
    if (consulta.fail())
       {
	 gotoxy(15,15);  cout <<"El archivo no existe o fue eliminado";
	 getch();

       }
	else
	  {
	    fondo();
	    cuadro(7,19,5,75);
	    gotoxy(7,8); cout <<"CODIGO     NOMBRE           ASIGNATURA      NOTA1-NOTA2-NOTA3  DEF";

	    L=10;
	    do {
		 consulta.read((char*)&est, sizeof(registro));
		   if(consulta.eof()) break;
		   if(est.DEF<3.0)
		     {
		       gotoxy(7,L); cout <<est.CODIGO;
		       gotoxy(18,L); cout <<est.NOMBRE;
		       gotoxy(35,L); cout <<est.MATERIA;
		       gotoxy(51,L); cout <<est.NOTA1;
		       gotoxy(57,L); cout <<est.NOTA2;
		       gotoxy(63,L); cout <<est.NOTA3;
		       gotoxy(70,L); cout <<est.DEF;
			 L++;
			 if(L==18)
			   {
			    gotoxy(15,21); cout <<"Presione cualquier tecla para continuar";
			    getch();
			    L=10;
			    fondo();
			    cuadro(7,19,5,75);
			    gotoxy(7,8); cout <<"CODIGO     NOMBRE       ASIGNATURA          NOTA1-NOTA2-NOTA3  DEF";
			   }
		    }
       }while(!consulta.eof());
       consulta.close();
       gotoxy(25,21); cout <<"Presione cualquier tecla para salir";
       getch();

}
}


void cuadro( int x,int x2, int y, int y2)
{
  int fila, columna;

  for(fila=x; fila<=x2; fila++)
     {
       gotoxy(y,fila), cout <<"º";
       gotoxy(y2,fila), cout <<"º";
     }
  for(columna=y; columna<=y2; columna++)
     {
       gotoxy(columna,x), cout <<"Í";
       gotoxy(columna,x2), cout <<"Í";

     }
 gotoxy(y,x); cout <<"É";
 gotoxy(y2,x); cout <<"»";
 gotoxy(y,x2); cout <<"È";
 gotoxy(y2,x2); cout <<"¼";
}

int tecla()
{
 char tecla;
 int op, menu;
 repite:
 fondo();
 textbackground(GREEN);
 gotoxy(8,4); cprintf("Captura");
 gotoxy(8,4);
 do{
     tecla=getch();

     if (tecla=='M')
	{
	if(wherex()==8)
	  {
	   textbackground(BLUE);
	   gotoxy(8,4); cprintf("Captura");
	   textbackground(GREEN);
	   gotoxy(18,4); cprintf("Consulta");
	   gotoxy(18,4);
	  } else if(wherex()==18)
	    {
	     textbackground(BLUE);
	     gotoxy(18,4); cprintf("Consulta");
	     textbackground(GREEN);
	     gotoxy(30,4); cprintf("Salir");
	     gotoxy(30,4);
	    }else if (wherex()==30)
	      {
	      textbackground(BLUE);
	      gotoxy(30,4); cprintf("Salir");
	      textbackground(GREEN);
	      gotoxy(8,4); cprintf("Captura");
	      gotoxy(8,4);
	      }
	}
	 else if (tecla=='K')
	   {
	   if(wherex()==30)
	   {
	    textbackground(BLUE);
	    gotoxy(30,4); cprintf("Salir");
	    textbackground(GREEN);
	    gotoxy(18,4); cprintf("Consulta");
	    gotoxy(18,4);
	   }else if(wherex()==18)
	    {
	     textbackground(BLUE);
	     gotoxy(18,4); cprintf("Consulta");
	     textbackground(GREEN);
	     gotoxy(8,4); cprintf("Captura");
	     gotoxy(8,4);
	    }else if (wherex()==8)
	      {
	      textbackground(BLUE);
	      gotoxy(8,4); cprintf("Captura");
	      textbackground(GREEN);
	      gotoxy(30,4); cprintf("Salir");
	      gotoxy(30,4);
	      }
	  }

   }while(tecla!=80 && tecla!=13);
   if(wherex()==8)
    op=1;
    else if(wherex()==18)
      op=2;
      else
	op=3;
    switch(op) {
    case 1:
       do {
	cuadro(5,7,8,18);
	textbackground(GREEN);
	gotoxy(9,6); cprintf("Alumnos");
	tecla=getch();
	if (tecla=='M' || tecla=='K')
	goto repite;
	}while(tecla!=13);
	menu=1;
	break;
    case 2:

	 cuadro(5,8,18,30);
	 textbackground(GREEN);
	 gotoxy(19,6); cprintf("Individual");
	 textbackground(BLUE);
	 gotoxy(19,7); cprintf("Todos");
	 gotoxy(19,6);
	 do {
	 tecla=getch();
	  if(tecla==80)
	    {
	      if(wherey()==6)
	       {
		gotoxy(19,6); cprintf ("Individual");
		textbackground(GREEN);
		gotoxy(19,7); cprintf("Todos");
		gotoxy(19,7);
	       }else
		 {
		  gotoxy(19,6); cprintf("Individual");
		  textbackground(BLUE);
		  gotoxy(19,7); cprintf("Todos");
		  gotoxy(19,6);
		 }
	    }
	  else if (tecla==72)
	   {
	   if(wherey()==6)
	       {
		gotoxy(19,6); cprintf("Individual");
		textbackground(GREEN);
		gotoxy(19,7); cprintf("Todos");
		gotoxy(19,7);
	       }else
		 {
		  gotoxy(19,6); cprintf("Individual");
		  textbackground(BLUE);
		  gotoxy(19,7); cprintf("Todos");
		  gotoxy(19,6);
		 }
	    }
	}while(tecla!=13);
	if(wherey()==6)
	  menu=2;
	  else
	    menu=3;
	      if(menu==3)
		{
		  cuadro(6,9,31,42);
		  gotoxy(32,7); cout<<"Aprobados";
		  gotoxy(32,8); cout <<"Reprobados";
		  do {
		      tecla=getch();
		    if(tecla==80)
		       {
			if(wherey()==7)
			 {
			  gotoxy(32,7); cprintf ("Aprobados");
			  textbackground(GREEN);
			  gotoxy(32,8); cprintf("Reprobados");
			  gotoxy(32,8);
			 }else
			   {
			    gotoxy(32,7); cprintf("Aprobados");
			    textbackground(BLUE);
			    gotoxy(32,8); cprintf("Reprobados");
			    gotoxy(32,7);
			   }
			}
			else if (tecla==72)
			 {
			  if(wherey()==7)
			    {
			     gotoxy(32,7); cprintf("Aprobados");
			     textbackground(GREEN);
			     gotoxy(32,8); cprintf("Reprobados");
			     gotoxy(32,8);
			    }else
			      {
				gotoxy(32,7); cprintf("Aprobados");
				textbackground(BLUE);
				gotoxy(32,8); cprintf("Reprobados");
				gotoxy(32,7);
			      }
			   }
			   if (tecla=='M' || tecla=='K')
				goto repite;
		      }while(tecla!=13);
		 if (wherey()==7)
		     menu=3;
		 if (wherey()==8)
		     menu=4;
		}



     break;
    case 3:
      do {
	   cuadro(5,7,30,45);
	   gotoxy(32,6); cprintf("Salir Prog.");
	   tecla=getch();
	   if (tecla=='M' || tecla=='K')
	    goto repite;
	 }while(tecla!=13);
     menu=5;
    break;
 }
return menu;
}

char tecla_menu()
{
 char tecla, op;
 textbackground(GREEN);
     gotoxy(20,20); cprintf("Continuar");
     gotoxy(50,20); cout <<"Salir";
     gotoxy(20,20);

 do
	  {
	    tecla=getch();
		if(tecla=='M')
		  {
		   if(wherex()==20)
		    {
		      textbackground(1);
		      gotoxy(20,20); cprintf("Continuar");
		      textbackground(2);
		      gotoxy(50,20); cprintf("Salir");
		      gotoxy(50,20);
		    }
		     else
		       {
			 textbackground(2);
			 gotoxy(20,20); cprintf("Continuar");
			 textbackground(1);
			 gotoxy(50,20); cprintf("Salir");
			 gotoxy(20,20);
		       }
		 }
		else if (tecla=='K')
			if(wherex()==20)
			   {
			      textbackground(1);
			      gotoxy(20,20); cprintf("Continuar");
			      textbackground(2);
			      gotoxy(50,20); cprintf("Salir");
			      gotoxy(50,20);
			   }
			    else
			     {
			     textbackground(2);
			     gotoxy(20,20); cprintf("Continuar");
			     textbackground(1);
			     gotoxy(50,20); cprintf("Salir");
			     gotoxy(20,20);
			     }
		}while(tecla!=13);
	 if(wherex()==20)
	 op='S';
	 else if(wherex()==50)
	 op='N';
return op;

}
void barra_menu()
{
gotoxy(8,4); cprintf("Captura");
gotoxy(18,4); cprintf("Consulta");
gotoxy(30,4); cprintf("Salir");
}
void fondo()
{
  textcolor(WHITE);
  textbackground(BLUE);
  clrscr();
  cuadro(2,24,2,78);
  gotoxy(30,2); cout <<"  COLEGIO DE SANTANDER  ";
  barra_menu();
}