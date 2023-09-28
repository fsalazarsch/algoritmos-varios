#include"iostream.h"
#include"conio.h"
const int lon=20;

class profesores{
private:
char materia[20];
char carrera[20];
char grupo[20];
char hora[30];
char jornada[30];
public:
void leerdato()
{
textcolor(4);
gotoxy(5,7);cout<<"\nIntroduzca la carrera:";
cin>>carrera;
gotoxy(5,8);cout<<"\nIntrodusca Tipo de materia:";
cin>>materia;
gotoxy(5,9);cout<<"\nIntroduzca hora:";
cin>>hora;
gotoxy(5,10);cout<<"\nIntroduzca grupo:";
cin>>grupo;
gotoxy(5,11);cout<<"\nIntroduzca jornada:";
cin>>jornada;clrscr();



}
void escribirdato()
{
gotoxy(29,7);cout<<"\n carrera:"<<carrera;
gotoxy(29,8);cout<<"\n materia:"<<materia;
gotoxy(29,9);cout<<"\n hora:"<< hora;
gotoxy(29,10);cout<<"\n grupo:"<<grupo;
gotoxy(29,11);cout<<"\n jornada:"<<jornada;

}

};

class profesores_1:public profesores
{
private:
char universidad[lon];
char ubicacion[lon];
public:
void leerdato()
{
profesores::leerdato();
gotoxy(5,11);cout<<"\nIntroduzca nombre de la universidad:";
cin>>universidad;
gotoxy(5,12);cout<<"\nIntroduzca ubicacion de la universidad:";
cin>>ubicacion;


}
void escribirdato()
{
profesores::escribirdato();

gotoxy(29,11);cout<<"\n universidad:"<<universidad;
gotoxy(29,12);cout<<"\n ubicacion:"<< ubicacion;

}
};
class profesores_2:public profesores
{
private:
char universidad[lon];
char ubicacion[lon];
public:
void leerdato()
{
profesores::leerdato();
gotoxy(5,11);cout<<"Introduzca nombre del universidad:";
;cin>>universidad;
gotoxy(5,12);cout<<"Introduzca ubicacion de la univesidad:";
cin>>ubicacion;
}
void escribirdato()
{
profesores::escribirdato();

gotoxy(29,11);cout<<"\n universidad:"<<universidad;
gotoxy(29,12);cout<<"\n ubicacion:"<< ubicacion;


}
};
class profesores_3:public profesores
{
private:
char universidad[lon];
char ubicacion[lon];
public:
void leerdato()
{
profesores::leerdato();
gotoxy(5,11);cout<<"Introduzca nombre del universidad:";
cin>>universidad;
gotoxy(5,12);cout<<"Introduzca ubicacion de la universidad:";
cin>>ubicacion;
}
void escribirdato()
{
profesores::escribirdato();

gotoxy(29,11);cout<<"\n universidad:"<<universidad;
gotoxy(29,12);cout<<"\n ubicacion:"<< ubicacion;

}

};

void main()
{
clrscr();
 profesores_1 nc1,nc2;
 profesores_2 cn1,cn2;
 profesores_3 ad1,ad2;
textbackground(15);
textcolor(5);
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.1";
nc1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.2";
nc2.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.3";
cn1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.4";
cn2.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.5";
ad1.leerdato();
gotoxy(5,5);cout<<"\n INTRODUZCA DATOS  DEL DOCENTE.6";
ad2.leerdato();
//***************pantalla****************//
clrscr();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.1";
nc1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.2";
nc2.escribirdato();
getch();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.3";
cn1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.4";
cn2.escribirdato();
getch();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.5";
ad1.escribirdato();
getch();
gotoxy(5,3);cout<<"\n    DATOS DEL DOCENTE.6";
ad2.escribirdato();
getch();
}
