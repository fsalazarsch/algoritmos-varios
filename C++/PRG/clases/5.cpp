#include"iostream.h"
#include"conio.h"
const int lon=20;
class carros{
private:
char marca[20];
unsigned long placa;
int modelo;
public:
void leerdato()
{
textbackground(15);
textcolor(5);
gotoxy(17,7);cout<<"\nINTRODUZCA LA MARCA DEL CARRO:";
cin>>marca;
gotoxy(15,8);cout<<"\nINTRODUZCA PLACA DEL CARRO:";
cin>>placa;
gotoxy(15,9);cout<<"\nINTRODUZCA EL MODELO DEL CARRO:";
cin>>modelo;
}
void escribirdato()
{
clrscr();
gotoxy(5,7);cout<<"\n marca:"<<marca;
gotoxy(5,8);cout<<"\n placa:"<<placa;
gotoxy(5,9);cout<<"\n modelo:"<< modelo;
}
};
class carros_lujo:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(1,13);cout<<"\nINTRODUZCA NOMBRE DEL COMPRADOR: ";
cin>>comprador;
gotoxy(1,15);cout<<"\nINTRODUZCA DESTINO DEL CARRO: ";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();
gotoxy(1,10);cout<<"\n comprador:"<<comprador;
gotoxy(1,11);cout<<"\n destino:"<< destino;
}
};
class carros_servpublico:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(1,13);cout<<"INTRODUZCA NOMBRE DEL COMPRADOR: ";
cin>>comprador;
gotoxy(1,15);cout<<"INTRODUZCA DESTINO DEL CARRO: ";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();

gotoxy(1,10);cout<<"\n comprador:"<<comprador;
gotoxy(1,11);cout<<"\n destino:"<< destino;
}
};
class camiones:public carros
{
private:
char comprador[lon];
char destino[lon];
public:
void leerdato()
{
carros::leerdato();
gotoxy(1,13);cout<<"INTRODUZCA NOMBRE DEL COMPRADOR: ";
cin>>comprador;
gotoxy(1,15);cout<<"INTRODUZCA DESTINO DEL CARRO: ";
cin>>destino;
}
void escribirdato()
{
clrscr();
carros::escribirdato();
gotoxy(1,10);cout<<"\n comprador:"<<comprador;
gotoxy(1,11);cout<<"\n destino:"<< destino;
}

};
void main()
{

carros_lujo cl1,cl2;
carros_servpublico csp1,csp2;
camiones cam1,cam2;
clrscr();
gotoxy(1,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJO1 ";
cl1.leerdato();
gotoxy(1,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJO2 ";
cl2.leerdato();
gotoxy(1,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO1";
csp1.leerdato();
gotoxy(1,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO2";
csp2.leerdato();
gotoxy(1,5);cout<<"\n INTRODUZCA      DATOS        CAMIONES       1";
cam1.leerdato();
gotoxy(1,5);cout<<"\n INTRODUZCA      DATOS        CAMIONES       2";
cam2.leerdato();
//************************************************************************//
clrscr();
gotoxy(1,8);cout<<"\n  DATOS     CARROS    DE    LUJO    1";
cl1.escribirdato();
getch();
gotoxy(1,8);cout<<"\n  DATOS     CARROS    DE    LUJO    2";
cl2.escribirdato();
getch();
gotoxy(1,8);cout<<"\n  DATOS CARROS DE  SERVICIO PUBLICO 1";
csp1.escribirdato();
getch();
gotoxy(1,8);cout<<"\n  DATOS CARROS DE SERVICIO PUBLICO  2";
csp2.escribirdato();
getch();
gotoxy(1,8);cout<<"\n  DATOS         CAMIONES            1";
cam1.escribirdato();
getch();
gotoxy(1,8);cout<<"\n  DATOS         CAMIONES            2";
cam2.escribirdato();
getch();
}