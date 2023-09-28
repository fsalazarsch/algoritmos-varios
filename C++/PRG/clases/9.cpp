#include"iostream.h"
#include"conio.h"
const int lon=20;
void pantalla();
void marco(int x1,int y1,int x2,int y2);

class car{
private:
char marca[20];
unsigned long placa;
int modelo;
public:
void leerdato()
{
clrscr();
cout<<"\nIntroduzca la marca:";
cin>>marca;
cout<<"\nIntroduzca placa:";
cin>>placa;
cout<<"\nIntroduzca modelo:";
cin>>modelo;
}
void escribirdato()
{
gotoxy(12,7);cout<<"\n marca:"<<marca;
gotoxy(12,8);cout<<"\n placa:"<<placa;
gotoxy(12,9);cout<<"\n modelo:"<< modelo;
}
};
class car_lujo:public car
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
car::leerdato();
gotoxy(5,12);cout<<"\nIntroduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,14);cout<<"\nIntroduzca Destino:";
cin>>destino;
}
void escribirdato()
{
car::escribirdato();
gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
}
};
class car_servpublico:public car
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
car::leerdato();
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>destino;
}
void escribirdato()
{
car::escribirdato();

gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
}
};
class camiones:public car
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
car::leerdato();
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>destino;
}
void escribirdato()
{
car::escribirdato();

gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
}

};

 void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); cprintf("%c",218); //Ú
  gotoxy(x2, y1); cprintf("%c",191); //¿
  gotoxy(x1, y2); cprintf("%c",192); //À
  gotoxy(x2, y2); cprintf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);cprintf("%c",196);//196Ä
       gotoxy(i, y2);cprintf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);cprintf("%c",179); //³
       gotoxy(x2, i);cprintf("%c",179);}
  }


/*void pantalla()
{
int i;

  textbackground(7);
  window(4,3,79,5);
  clrscr();marco(1,1,76,3);

  textbackground(6);
  window(2,2,77,4);
  clrscr();marco(1,1,76,3);textcolor(15);
  gotoxy(28,2);cprintf("H  Y  U  N  D  A  Y  ");


  /*textbackground(7);
  window(4,22,79,24);
  clrscr();marco(1,1,76,3);

    */
  /*
  textbackground(6);
  window(2,21,77,23);
  clrscr();//marco(1,1,76,3);
  gotoxy(8,2);
  cout<<"[Captura  De Informacion Del tipo De Auto... presione <enter>]";


  textbackground(7);
  window(16,8,70,17);
  clrscr();marco(1,1,54,10);

  getch();

}*/

void main()
{
clrscr();
textbackground(7);
  window(4,3,79,5);
  clrscr();marco(1,1,76,3);

  textbackground(6);
  window(2,2,77,4);
  clrscr();marco(1,1,76,3);textcolor(15);
  gotoxy(28,2);cprintf("H  Y  U  N  D  A  Y  ");

textbackground(6);
  window(2,21,77,23);
  clrscr();//marco(1,1,76,3);
  gotoxy(8,2);
  cout<<"[Captura  De Informacion Del tipo De Auto... presione <enter>]";


  textbackground(7);
  window(16,8,70,17);
  clrscr();marco(1,1,54,10);

car_lujo cl1,cl2;
car_servpublico csp1,csp2;
camiones cam1,cam2;
textcolor(35);
gotoxy(5,5);cout<<"\n Introduzca Datos Carros De Lujo .1";
cl1.leerdato();
gotoxy(5,5);cout<<"\n Introduzca Datos Carros De Lujo .2";
cl2.leerdato();
gotoxy(5,5);cout<<"\n Introduzca  Datos Carros De Servicio Publico.1";
csp1.leerdato();
gotoxy(5,5);cout<<"\n Introduza Datos Carros De Servicio Publico .2";
csp2.leerdato();
gotoxy(5,5);cout<<"\n Introduzca      Datos        Camiones      .1";
cam1.leerdato();
gotoxy(5,5);cout<<"\n Introduzca      Datos        Camiones      .1";
cam2.leerdato();
//***************pantalla****************//
clrscr();
gotoxy(5,3);cout<<"\n  DATOS     CARROS    DE    LUJO    .1";
cl1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n  DATOS     CARROS    DE    LUJO    .2";
cl2.escribirdato();
getch();
gotoxy(5,3);cout<<"\n  DATOS CARROS DE  SERVICIO PUBLICO .1";
csp1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n  DATOS CARROS DE SERVICIO PUBLICO . 2";
csp2.escribirdato();
getch();
gotoxy(5,3);cout<<"\n  DATOS         CAMIONES            .1";
cam1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n  DATOS         CAMIONES            .2";
cam2.escribirdato();
getch();
}