# include <IOSTREAM.H>
# include <CONIO.H>
# include <DOS.H>
void CUADROS();
void main(void)
{
 textcolor(RED);
 textbackground(BLUE);
 clrscr();
 textcolor(RED);
 textbackground(BLACK);
 window(15,5,60,20);
 clrscr();
 textbackground(WHITE);
 window(17,6,62,21);
 clrscr();
 CUADROS();
 _setcursortype(_NOCURSOR);

 getch();

}

void CUADROS()
{
int I,J;
for(I=2;I<=44;I++)
 {
 gotoxy(I,2); cout <<"Í";
 gotoxy(I,16); cout <<"Í";
  _setcursortype(_NOCURSOR);
 delay (20);
 }
for(J=3;J<=15;J++)
 {
 gotoxy(2,2); cout <<"É";
 gotoxy(2,J); cout <<"º";
 gotoxy(2,16); cout <<"È";
 gotoxy(44,2); cout <<"»";
 gotoxy(44,J); cout <<"º";
 gotoxy(44,16); cout <<"¼";
  _setcursortype(_NOCURSOR);
 delay(20);
 }
}
