# include <iostream.h>
# include <conio.h>
#include<ctype.h>
#include<stdio.h>

struct pelicula1
{
int uno;
private:
int dos;  //variables no accesibles desde
int tres; //el programa principal
};

class pelicula
     {
     int i; //no accesible desde el programa principal
     public:
     struct  pelicula1 alvaro;
     pelicula(char *nombre,char *act_pp,char *act_sc);
     pelicula();
     ~pelicula();
};


pelicula::pelicula(char *nombre,char *act_pp,char *act_sc)
{
cout<<"EL NOMBRE ES : "<<nombre<<endl;
cout<<"EL ACTOR PRINCIPAL ES  : "<<act_pp<<endl;
cout<<"EL ACTOR SECUNDARIO ES  : "<<act_sc<<endl;
getch();
}

pelicula::pelicula()
{
cout<<"AUTOR : ALVARO"<<endl;
getch();
}


pelicula::~pelicula()
{
cout<<"destruyendo"<<endl;getch();
}

void main()
{
clrscr();
pelicula alv("AAAAAA","AAAAAAAAA","AAAAAAAAA"); //constructor con parametros
pelicula alv1("BBBBBBB","BBBBBBBBB","BBBBBBBBB"); //constructor con parametros
pelicula inicio;  //constructor sin parametros

inicio.alvaro.uno=1;
cout<<inicio.alvaro.uno<<endl;getch();
/*alvaro.uno=1;
alvaro.dos=2;
alvaro.tres=3;
cout<<alvaro.uno <<" "<<alvaro.dos<<" "<<alvaro.tres;getch();*/
}
