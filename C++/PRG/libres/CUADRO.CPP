#include "stdio.h"
#include "conio.h"
#include "string.h"
  void cuadro(int x1,int y1,int x2,int y2,char a1[],char a2[],char a3[],char a4[],char a5[],char a6[]);
  char c1[]="³",c2[]="Ä",c3[]="Ú",c4[]="Ù",c5[]="¿",c6[]="À";
  char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È";
  void main()
  { clrscr ();
    cuadro(3,1,23,80,a1,a2,a3,a4,a5,a6);
    cuadro(4,5,20,60,c1,c2,c3,c4,c5,c6);
    getch();
  }

  void boli (int fi,int ff,int ci, int cf)
  {  int i,j;
     for (i=fi;i<=ff;i++)
     { for(j=ci;j<=cf;j++)
	{ gotoxy(j,i);cprintf(" ");}}
   }
   void cuadro(int x1,int y1,int x2,int y2, char a1[],char a2[],char a3[],char a4[],char a5[],char a6[])
    { int i;
      for(i=x1;i<=x2;i++)
      { gotoxy(y1,i);cprintf(a1);
	gotoxy(y2,i);cprintf(a1);}
	for(i=y1;i<=y2;i++)
	  { gotoxy(i,x1);cprintf(a2);
	    gotoxy(i,x2);cprintf(a2);}
	    gotoxy(y1,x1);cprintf(a3);
	    gotoxy(y2,x2);cprintf(a4);
	    gotoxy(y2,x1);cprintf(a5);
	    gotoxy(y1,x2);cprintf(a6);
     }
     void centraM(char men[],int f)
     { int lon,col;
	lon=strlen(men);
	col=(80-lon)/2;
	gotoxy(col,f);cprintf("%s",men);
      }