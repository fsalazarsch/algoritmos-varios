# include <fstream.h>
# include <conio.h>
int main()
{
 clrscr();
 char letra;
 fstream letras("letras.txt",ios::in|ios::out);

 letras.seekg(7,ios::beg);
 letra=letras.get();
 letras.seekp(0,ios::end);
 gotoxy(20,12);cout<<letra;
 //letras<<letra;

 letras.seekg(14,ios::beg);
 letra=letras.get();
 letras.seekp(0,ios::end);
 gotoxy(21,12);cout<<letra;
 //letras<<letra;

 letras.seekg(11,ios::beg);
 letra=letras.get();
 letras.seekp(0,ios::end);
 gotoxy(22,12);cout<<letra;
 //letras<<letra;

 letras.seekg(0,ios::beg);
 letra=letras.get();
 letras.seekp(0,ios::end);
 gotoxy(23,12);cout<<letra;
 //letras<<letra;

 //letras.seekg(-2,ios::end);
 while(!letras.eof())
 cout.put((char)letras.get());
 letras.close();
 getch();
 return 0;

}