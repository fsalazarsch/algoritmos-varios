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
cout<<"\nIntroduzca la marca:";
cin>>marca;
cout<<"\nIntroduzca placa:";
cin>>placa;
cout<<"\nIntroduzca modelo:";
cin>>modelo;
}
void escribirdato()
{
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
gotoxy(5,12);cout<<"\nIntroduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,14);cout<<"\nIntroduzca Destino:";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();
gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
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
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();

gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
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
gotoxy(5,13);cout<<"Introduzca nombre del comprador:";
cin>>comprador;
gotoxy(5,15);cout<<"Introduzca destino de viaje :";
cin>>destino;
}
void escribirdato()
{
carros::escribirdato();

gotoxy(5,10);cout<<"\n comprador:"<<comprador;
gotoxy(5,11);cout<<"\n destino:"<< destino;
}

};
void main()
{
clrscr();
carros_lujo cl1,cl2;
carros_servpublico csp1,csp2;
camiones cam1,cam2;
textcolor(35);
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJO .1";
cl1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE LUJO .2";
cl2.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO.1";
csp1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS CARROS DE SERVICIO PUBLICO .2";
csp2.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA      DATOS        CAMIONES       .1";
cam1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA      DATOS        CAMIONES       .2";
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