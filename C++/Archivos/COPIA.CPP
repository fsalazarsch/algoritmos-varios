
//*****************ARCHIVOS******************

//Este programa permite calcular la nota de cualquier 
//materia de la U.P.C.
//Autor: El m…s vago de todos.
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>

void CAPTURA();
void MOSTRAR();
int MENU();
void CUADRO(int ci,int cf,int fi,int ff);
void CALCULO();
void CONTEXTO();

struct ARCHIVO{
   int cod;
   char nombre [30];
   long tel;
   char direccion [30];
   }EST;

void main(void)
{
 int con=14;
 int X,Y,K,P,T,men;
 float A,B,C,N1,N2,N3,DEF;
 float s=36;
 char OP='S';
 char nom[20];
 char mat[20];
 textcolor(2);
 textbackground(1);
 CUADRO(2,78,2,24);
 gotoxy(28,20);cout<<"¨LA CONTRASE¥A ES ?";cin>>con;
   if(con==14)
     {
      for(P=5;P<=70;P++)
       {
      gotoxy(P,9);cout<<"*"; // para hacer un cuadro mas peque¤o
      gotoxy(P,11);cout<<"*";
      }
     for(K=9;K<=11;K++)
     {
      gotoxy(5,K);cout<<"*";  //para hacer un cuadro mas peque¤o
      gotoxy(70,K);cout<<"*";
      }
     for(T=6;T<=69;T++)
     {
     s+=1;
     _setcursortype(_NOCURSOR);
     gotoxy(T,10);cout<<"Û";  // para llenar el cuadro peque¤o
     delay(100);//se utiliza para hacer pausa en cualquier momento y inicializa el archivo dos.h
     gotoxy(73,10);cout<<s<<"%";
     }
     gotoxy(28,12);cout<<"CONTRASE¥A CORRECTA";
     delay(2000);
     gotoxy(5,8);cout<<"                                                                      ";  
     gotoxy(5,9);cout<<"                                                                      ";  
     gotoxy(5,10);cout<<"                                                                     "; 
     gotoxy(5,11);cout<<"                                                                     "; 
     gotoxy(5,12);cout<<"                                                                     "; 
     gotoxy(28,20);cout<<"	                                                              ";
     sound(51000); // se utiliza para colocar la musica
     delay(50); // para que vaya mas despacio
     nosound();   // para que se acabe la musica
    }
   else {
   for(P=5;P<=70;P++)
       {
      gotoxy(P,9);cout<<"*"; // para hacer un cuadro mas peque¤o
      gotoxy(P,11);cout<<"*";
      }
     for(K=9;K<=11;K++)
     {
      gotoxy(5,K);cout<<"*";  //para hacer un cuadro mas peque¤o
      gotoxy(70,K);cout<<"*";
      }
     for(T=6;T<=69;T++)
     {
     s+=1;
     _setcursortype(_NOCURSOR);
     gotoxy(T,10);cout<<"Û";  // para llenar el cuadro peque¤o
     delay(100);//se utiliza para hacer pausa en cualquier momento y inicializa el archivo dos.h
     gotoxy(73,10);cout<<s<<"%";
     }
     gotoxy(28,12);cout<<"CONTRASE¥A INCORRECTA";
     delay(2000);
     exit(0);
    }
    _setcursortype(_NORMALCURSOR);
 while (OP=='S')
  {
   CUADRO(2,78,2,24);
   men = MENU();
   switch(men){
    case 1:
     CAPTURA();
      break;
    case 2:
     MOSTRAR();
     break;
    case 3:
     CALCULO();
     break;
    case 4:
     OP='N';
     break;
   }
  }
}      

void CUADRO(int ci,int cf,int fi,int ff)
{
 int O;
 clrscr();
 gotoxy(27,4);cout<<"UNIVESRSIDAD POPULAR DEL CESAR";
 for(O=ci;O<=cf;O++)
 {
  gotoxy(O,fi);cout<<"ÎÎ";
  gotoxy(O,ff);cout<<"ÎÎ";
  }
 for(O=fi;O<ff;O++)
 {
  gotoxy(ci,O);cout<<"ÎÎ";
  gotoxy(cf,O);cout<<"ÎÎ";
  }
 gotoxy(ci,fi);cout<<"ÎÎ";
 gotoxy(cf,fi);cout<<"ÎÎ";
 gotoxy(ci,ff);cout<<"ÎÎ";
 gotoxy(cf,ff);cout<<"ÎÎ";
 }

void CAPTURA()
 {
  char OPCION='S'; 
  ofstream COPIA("c:\COPIA.DAT",ios::app);
  while (OPCION=='S')
  {
   gotoxy(28,5);cout<<"CAPTURA DE DATOS BASICOS";
    
 gotoxy(13,10);cout<<"C¢digo            :[981040      ]";
 gotoxy(13,11);cout<<"Nombre y apellido :[                             ]";
 gotoxy(13,12);cout<<"Telefono          :[          ]";
 gotoxy(13,13);cout<<"Direccion         :[                             ]";
 gotoxy(39,10);cin>>EST.cod;
 gotoxy(33,11);gets(EST.nombre);
 gotoxy(33,12);cin>>EST.tel;
 gotoxy(33,13);gets(EST.direccion);
 COPIA.write((char *)&EST,sizeof(ARCHIVO));
 gotoxy(26,16);cout<<"DESEA CONTINUAR -S/N- ";
 do{
      OPCION = getch ();
      OPCION = toupper(OPCION);
      gotoxy(26,16);cout<<"                                      ";                   
      }while((OPCION != 'S') && (OPCION != 'N'));
   }
 COPIA.close();
}

void MOSTRAR()
{
 ifstream COPIA("c:\COPIA.DAT");
 while(! COPIA.eof())
  {
   gotoxy(25,5);cout<<"SISTEMA INTEGRADO DE INFORMACION"; 
 gotoxy(13,10);cout<<"C¢digo            :[981040      ]";
 gotoxy(13,11);cout<<"Nombre y apellido :[                             ]";
 gotoxy(13,12);cout<<"Telefono          :[          ]";
 gotoxy(13,13);cout<<"Direccion         :[                             ]";
 COPIA.read((char *) &EST,sizeof(ARCHIVO));
 gotoxy(39,10);cout<<EST.cod;
 gotoxy(33,11);cout<<EST.nombre;
 gotoxy(33,12);cout<<EST.tel;
 gotoxy(33,13);cout<<EST.direccion;
 gotoxy(26,16);cout<<"Pulse cualquier tecla para continuar... ";
 getch();
 }
 COPIA.close();
}
 
int MENU()
{
 int men;
 gotoxy(25,10);cout<<"1_ CAPTURA DE DATOS";
 gotoxy(25,11);cout<<"2_ MOSTRAR DATOS";
 gotoxy(25,12);cout<<"3_ DEFINITIVA";
 gotoxy(25,13);cout<<"4_ SALIR DEL PROGRAMA";
 do{
    gotoxy(20,22);cout<<"Seleccione alguna alternativa y presione <ENTER>:[ ]";
    gotoxy(70,22);cin>>men;
    gotoxy(20,22);cout<<"                                                    ";
   } while  (( men < 1) || (men > 4));
 return men;
}
   
void CALCULO()
{
 int ne=0;
 float pro=0,tp,N1,N2,N3,A,B,C,DEF;
 CUADRO(2,78,2,24);
 ifstream COPIA("c:\COPIA.DAT");
 while(! COPIA.eof())
 {
  COPIA.read ((char *) &EST,sizeof(ARCHIVO));
  if (COPIA.eof())
   break;
 gotoxy(5,3);cout<<EST.cod;
 gotoxy(15,3);cout<<EST.nombre;    
 gotoxy(31,3);cout<<"NOTAS DE LA MATERIA";
 gotoxy(27,5);cout<<"PROMEDIO DEL ESTUDIANTE";
 gotoxy(20,12);cout<<"                                                   ";
 gotoxy(33,10);cout<<"Nota 1 = ";
 gotoxy(33,11);cout<<"Nota 2 = ";
 gotoxy(33,12);cout<<"Nota 3 = ";
 gotoxy(44,10);cin>>A;
 gotoxy(44,11);cin>>B;
 gotoxy(44,12);cin>>C;
 N1=A*0.30;
 N2=B*0.30;
 N3=C*0.40;
 DEF=N1+N2+N3;                             
 if (DEF < 3)
  {
   sound(1500);
   delay(2500);
   nosound();
   gotoxy(31,15);cout<<"REPROBO LA MATERIA "<<" "<<DEF;
   getch();
    }
  else
   {
    sound(2500);
    delay(1500);
    nosound();
    gotoxy(31,15);cout<<"APROBO LA MATERIA " <<" "<<DEF;
    getch();
    }
  ne=ne + 1;
  pro= pro + DEF;
  tp= pro/ne;
  gotoxy(28,20);cout<<"Numero de estudiantes:"<<" " <<ne;
  gotoxy(28,21);cout<<"Total promedio       :"<<" "<<tp;
}
}						