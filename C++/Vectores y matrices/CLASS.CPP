
//*************VECTORES***************************

# include <iostream.h>
# include <conio.h>
# include <ctype.h>
# include <stdio.h>
# include <iomanip.h>
# include <dos.h>
void contexto();
void cuadro();
void cuadro1();
void pantallazo();
void marco();
int menu();
int submenu();
float devengado(float sb, int dt);
void main(void)
  {
   int j,sub,i,f,k,dt[15],l=0, u;
   float sb[15],sbd[15],sn,prima,total,sal;
   char op,cap,sw,s='S';
   char nombre[15][30];
   long ced[15],cedula;
   textcolor(1);
   textbackground(2);
   op='S';
   pantallazo();
   while(op=='S')
       {
       marco();
       textcolor(WHITE);
       textbackground(RED);
       j=menu();
       cap='S';
       sub=1;
       switch(j) {
       case 1:
	     i=0;
	     while((i<15)&&(cap=='S'))
	    {
	    marco();
	    textbackground(25);
	    contexto();
	    gotoxy(32,6); cout <<"CAPTURA DE DATOS";
	    gotoxy(36,10); cin >> ced[i];
	    gotoxy(36,11); gets(nombre[i]);
	    gotoxy(36,12); cin >> dt[i];
	    gotoxy(36,13); cin >> sb[i];
	    i++;
	    do {
	       gotoxy(32,20); cout <<"desea continuar S/N ";
	       cap=getch();
	       cap=toupper(cap);
	       } while ((cap!='S')&&(cap!='N'));
	      }
	   break;
	 case 2:
	     while(sub!=3)
	       {
	  marco();
	  sub=submenu();
	       switch(sub) {
		case 1 :
		      marco();
		      gotoxy(30,6); cout <<" CONSULTA POR EMPLEADO";
		      gotoxy(20,8); cout << " CEDULA "; cin >> cedula;
		      gotoxy(20,8); cout << "                             ";
		      s='N';
		    for (l=0; l<i;l++)
		    if (cedula==ced[l])
		       {
		       s='S';
		       break;
		       }
		    if(s=='S')
		       {
		       contexto();
		       gotoxy(36,10); cout << ced[l];
		       gotoxy(36,11); cout << nombre[l];
		       gotoxy(36,12); cout << dt[l];
		       gotoxy(36,13); cout << sb[l];
		       gotoxy(20,18); cout << " presione cualquier tecla para continuar ";
		       getch();
		       }
		      else
		       {
		       gotoxy(20,14); cout << "ESTE EMPLEADO NO EXISTE...POR FAVOR VERIFIQUE ";
		       getch();
		       }
		       break;
		     case 2:
		       marco();
		       cuadro1();
		       textcolor(BLACK);
		       textbackground(WHITE);
		       gotoxy(25,6); cout <<"CONSULTA DE TODOS LOS EMPLEADOS";
		       gotoxy(4,8); cout << "CEDULA     NOMBRE                    DIAS TRAB.          SAL.BAS.   ";
		       f=10;
		       for (l=0;l<i; l++)
		       {
		       if (f<=20)
			      {
			      gotoxy(4,f); cout << setw(8) << ced[l];
			      gotoxy(14,f); cout << nombre[l];
			      gotoxy(44,f); cout << setw(2) << dt[l];
			      gotoxy(52,f); cout << setw(8) << sb[l];
			      f++;
			      delay(500);
			       }
			     getch();
			     if (f>20)
			       {
			       l++;
			       marco();
			       cuadro1();
			       gotoxy(25,6); cout <<"CONSULTA DE TODOS LOS EMPLEADOS";
			       f=10;
			       gotoxy(4,6); cout << "CEDULA     NOMBRE                    DIAS TRAB.           SAL.BAS.   ";
			       cuadro();
			       gotoxy(4,f); cout << setw(8) << ced[l];
			       gotoxy(14,f); cout << nombre[l];
			       gotoxy(44,f); cout << setw(2) << dt[l];
			       gotoxy(52,f); cout << setw(8) << sb[l];
			       f++; delay(500);
			       }
			      getch();
			    }
			    getch();
			    break;
			   }
			 }
		       break;
			 case 3:
			  while (sub!=3)
			 {
			 marco();
			 textcolor(CYAN);
			 textbackground(MAGENTA);
			 j=submenu();
			 switch (j){
			 case 1:
			 marco();
			 gotoxy(35,6); cout << "LIQUIDACION";
			 gotoxy(30,7); cout << "INDIVIDUAL POR EMPLEADOS";
			 gotoxy(20,8); cout << " CEDULA "; cin >> cedula;
			 gotoxy(20,8); cout << "                             ";
			 s='N';
		     for (l=0; l<i;l++)
		       if (cedula==ced[l])
		       {
		       s='S';
		       break;
		       }
		      if(s=='S')
			{
			 contexto();
			 gotoxy(40,10); cout << ced[l];
			 gotoxy(40,11); cout << (nombre[l]);
			 gotoxy(40,12); cout << dt[l];
			 gotoxy(40,13); cout << sb[l];
			 sal=devengado(sb[l],dt[l]);
			 prima=sal*0.05;
			 sn=sal+prima;
			 gotoxy(35,18); cout << "SALARIO NETO : " << setw(9) << sn;
			 gotoxy(35,17); cout << "PRIMA        : " << setw(9) << prima;
			 gotoxy(26,21); cout << "presione cualquier tecla para continuar";
			 getch();
			}
			else
		       {
		       gotoxy(20,14); cout << "ESTE EMPLEADO NO EXISTE...POR FAVOR VERIFIQUE ";
		       getch();
		       }
		       break;
		     case 2:
			marco();
			cuadro();
			gotoxy(25,6); cout << "LIQUIDACION DE TODOS LOS EMPLEADOS";
			gotoxy(4,8); cout << "CEDULA   º  NOMBRE                  º  PRIMA   ºDEVENG.ºDTº  SAL NETO    ";
			f=10;
		       for (l=0;l<i; l++)
			 {
			 sal=devengado(sb[l],dt[l]);
			 prima=sal*0.05;
			 sn=sal+prima;
		       if (f<=20)
			      {
			       gotoxy(4,f); cout << setw(8) << ced[l];
			       gotoxy(14,f); cout << nombre[l];
			       gotoxy(41,f); cout << setw(6) << prima;
			      // gotoxy(51,f); cout << setw(8) << sal[l];
			       gotoxy(60,f); cout << setw(2) << dt[l];
			       gotoxy (64,f); cout << setw(8) << sn;
			       f++;
				delay(500);
			       }
			       getch();
			     if (f>20)
			       {
			       l++;
			       marco();
			       cuadro();
			       gotoxy(25,6); cout <<"LIQUIDACION DE TODOS LOS EMPLEADOS";
			       f=10;
			       gotoxy(4,8); cout << "CEDULA   º  NOMBRE                  º  PRIMA   ºDEVENG.ºDTº  SAL NETO    ";
			       gotoxy(4,f); cout << setw(8) << ced[l];
			       gotoxy(14,f); cout << nombre[l];
			       gotoxy(42,f); cout << setw(6) << prima;
			      // gotoxy(51,f); cout << setw(8) << sal[l];
			       gotoxy(60,f); cout << setw(2) << dt[l];
			       gotoxy (64,f); cout << setw(8) << sn;
			       f++; delay(500);
				}
			       }
			       getch();
			     break;
			     case 3 :
		       sub=3;
		       break;
			}
		       }
		       break;
			 case 4:
			     {
			     clrscr();
			     gotoxy(22,17); textcolor(80+125);cprintf("­GRACIAS POR UTILIZAR NUESTROS SERVICIOS!");
			     gotoxy(34,6); textcolor(18+125);cprintf ( "DISE¥ADO POR :");
			     gotoxy(25,10); textcolor(1);cprintf ( "ALVARO A. CARRILLO ARAUJO.");
			     gotoxy(33,12); textcolor(1);cprintf ( "Y COMPA¥IA....");
			     gotoxy(23,22); textcolor(70+125);cprintf ( "PRESIONE CUALQUIER TECLA PARA TERMINAR");
			     getch();
			     }
			     op='N';
			     break;
			     op='N';
			     break;
			 }
		       }
		      }
  void contexto()
     {
     gotoxy(15,10); cout << " CEDULA          : ";
     gotoxy(15,11); cout << " NOMBRES         : ";
     gotoxy(15,12); cout << " DIAS TRABAJADOS : ";
     gotoxy(15,13); cout << " SALARIO BASICO  : ";
     }
int menu()
  {
  int j;
  gotoxy(32,7);textcolor(15+127);cprintf ("   M E N U  ");
  gotoxy(23,10); textcolor(15);cprintf ( "1 - CAPTURA DE DATOS");
  gotoxy(23,11); textcolor(15);cprintf ("2 - CONSULTA DE DATOS");
  gotoxy(23,12); textcolor(15);cprintf ("3 - LIQUIDACION");
  gotoxy(23,13); textcolor(15);cprintf ("4 - SALIR DEL PROGRAMA");
  do {
     gotoxy(20,18); textcolor(25);cprintf ("seleccione una alternativa y presione <ENTER> :  "); cin >>j;
     }while ((j<1)||(j>4));
  return j;
 }
 int submenu()
   {
   int j;
   textbackground(RED);
   gotoxy(28,6);textcolor(17+129);cprintf ("  S U B M E N U  ");
   gotoxy(23,10); textcolor(15);cprintf ("1 - INDIVIDUAL POR EMPLEADO");
   gotoxy(23,11); textcolor(15);cprintf ("2 - TODOS LOS EMPLEDOS");
   gotoxy(23,12); textcolor(15);cprintf ("3 - SALIR DEL SUBMENU");
   do {
      gotoxy(20,18); textcolor(26);cprintf ("seleccione una alternativa y presione <ENTER> :  ");
      cin >>j;
      } while ((j<1)||(j>3));
   return j;
  }
  void marco()
   {
   int i,k;
   clrscr();
   gotoxy(25,3); textcolor(BLACK);cprintf ("PROCESO DE LIQUIDACION DE NOMINA");
   gotoxy(32,4); textcolor(BLACK);cprintf ("ALMACEN GIYOCA");
   for(i=2;i<=78;i++)
     {
     delay(5);
     gotoxy(i,2);cout<<"Í";
     gotoxy(i,24);cout<<"Í";
     }
     for(k=3;k<=23;k++)
       {
       delay(5);
       gotoxy(2,k);cout<<"º";
       gotoxy(79,k);cout<<"º";
       }
       gotoxy(2,2);cout<<"É";
       gotoxy(79,2);cout<<"»";
       gotoxy(2,24);  cout<<"È";
       gotoxy(79,24);cout<<"¼";
    }
  float devengado(float sb, int dt)
      {
      float sbd;
      sbd=(sb/30)*dt;
      return sbd;
      }
     void pantallazo()
     {
clrscr();
int ED,PE, ES, PM=0,PF=0;
char NOMBRE[30],SX,w,x, OP;
for (w=3; w<=20; w++)
	{
	gotoxy(3,w); cout <<"²±²";
	}
       for (w=3; w<=76; w++)
	{
	gotoxy(w,20); cout <<"²";
	gotoxy(w,19); cout <<"²";
	}
	for (w=18; w>=3; w--)
	  {
	  gotoxy(74,w); cout <<"²±²";
	  }
	  for (w=76; w>=3; w--)
	    {
	    gotoxy(w,3); cout <<"²";
	    gotoxy(w,4); cout <<"²";
	    }
	    for (w=6; w<=73; w++)
	     for (x=5; x<=18; x++)
		{
		gotoxy(w,x); cout <<"ž";
		}
		for (w=18; w<=60; w++)
		  for (x=8; x<=15; x++)
		    {
		    gotoxy(w,x); cout <<"°";
		    }
		    gotoxy(30,10);cout<<"      ALVARO       ";
		    gotoxy(30,11);cout<<"        Y          ";
		    gotoxy(30,12);cout<<"     COMPA¥IA      ";
		    gotoxy(20,23); cout << "PRESIONE CUALQUIER TECLA PARA COMENZAR"; getch();
		    }
    void cuadro()
    {
    int I, J, K;
for(I=3; I<78; I++)
   {
    gotoxy(I,7);cout <<"Í";
    gotoxy(I,9);cout <<"Í";
    gotoxy(I,22);cout <<"Í";
    }
    for(I=8; I<22; I++)
      {
      gotoxy(3,I);cout<<"º";
      gotoxy(13,I);cout<<"º";
      gotoxy(40,I);cout<<"º";
      gotoxy(51,I);cout<<"º";
      gotoxy(59,I);cout<<"º";
      gotoxy(62,I);cout<<"º";
      gotoxy(78,I);cout<<"º";
      }
      gotoxy(3,7);cout << "É";
      gotoxy(78,7);cout <<"»";
      gotoxy(3,22);cout <<"Ó";
      gotoxy(59,22);cout << "Ð";
      gotoxy(13,22);cout << "Ð";
      gotoxy(40,22);cout << "Ð";
      gotoxy(51,22);cout << "Ð";
      gotoxy(62,22);cout << "Ð";
      gotoxy(13,7);cout << "Ò";
      gotoxy(40,7);cout << "Ò";
      gotoxy(51,7);cout << "Ò";
      gotoxy(62,7);cout << "Ò";
      gotoxy(59,7);cout << "Ò";
      gotoxy(78,22);cout <<"¼";
      }
   void cuadro1()
     {
     int I, J, K;
   for(I=3; I<78; I++)
    {
    gotoxy(I,7);cout <<"Í";
    gotoxy(I,9);cout <<"Í";
    gotoxy(I,22);cout <<"Í";
    }
    for(I=8; I<22; I++)
      {
      gotoxy(3,I);cout<<"º";
      gotoxy(13,I);cout<<"º";
      gotoxy(40,I);cout<<"º";
      gotoxy(51,I);cout<<"º";
      gotoxy(78,I);cout<<"º";
      }
      gotoxy(3,7);cout << "É";
      gotoxy(78,7);cout <<"»";
      gotoxy(3,22);cout <<"Ó";
      gotoxy(13,22);cout << "Ð";
      gotoxy(40,22);cout << "Ð";
      gotoxy(51,22);cout << "Ð";
      gotoxy(13,7);cout << "Ò";
      gotoxy(40,7);cout << "Ò";
      gotoxy(51,7);cout << "Ò";
      gotoxy(78,22);cout <<"¼";
      }


