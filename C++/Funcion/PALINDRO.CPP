#include "iostream.h"
#include "conio.h"
#include "stdio.h"
#include "string.h"
#include "dos.h"
#include "ctype.h"
void CUADRO(int ci, int cf, int fi, int ff);
main(){
char v[100],aux[100];
int r; char op='S';
while(op=='S')
{
clrscr();
CUADRO(1,80,1,24);
gotoxy(30,3);textcolor(7);cprintf("PALABRAS PALINDROMES");
gotoxy(20,10);textcolor(7);cprintf("Escriba una palabra : ");gets(v);
strcpy(aux,v);
strrev(v);
r=strcmp(v,aux);
if(r==0){textcolor(4+150);gotoxy(20,20);cprintf("es palindrome.....!");}
else
{textcolor(4+150);gotoxy(20,20);cprintf("no es palindrome.....!");}
do{
    gotoxy(25,22);textcolor(7);cprintf("DESEA CONTINUAR -S/N- [ ]");
    gotoxy(48,22);op=getch();
    op=toupper(op);
    }while(op != 'N' && op != 'S');
}
return (0);
}

void CUADRO(int ci, int cf, int fi, int ff)
{
int o;int fm=1;
textcolor(GREEN);
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cprintf("Í");
gotoxy(o,ff); cprintf("Í");
gotoxy(fm,5); cprintf("Í");
gotoxy(fm,22);cprintf("Í");
gotoxy(fm,15);cprintf("Í");fm++;
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cprintf("º");
gotoxy(cf,o); cprintf("º");
}
gotoxy(ci,fi); cprintf("É");
gotoxy(cf,fi); cprintf("»");
gotoxy(ci,ff); cprintf("È");
gotoxy(cf,ff); cprintf("¼");
}
