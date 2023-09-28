# include<alvaro.h>
# include<conio.h>
# include<stdio.h>

main()
{
 alv TIR;
 char nom[30];
 textbackground(RED);
 clrscr();
 TIR.CUADRO(1,79,2,25);
 gotoxy(20,20);PR"NOMBRE";
 gotoxy(30,20);gets(nom);
 getch();
 gotoxy(20,21);cout<<nom;
 getch();
}