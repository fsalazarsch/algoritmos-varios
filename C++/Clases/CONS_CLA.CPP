# include <iostream.h>
# include <conio.h>
#include<ctype.h>
#include<stdio.h>


class pelicula
     {
     public:
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


pelicula:: ~pelicula()
{
cout<<"destruyendo"<<endl;getch();
}

void main()
{
clrscr();
pelicula alv("AAAAAA","AAAAAAAAA","AAAAAAAAA"); //constructor con parametros
pelicula alv1("BBBBBBB","BBBBBBBBB","BBBBBBBBB"); //constructor con parametros
pelicula al;  //constructor sin parametros
}