
#include "stdio.h"
#include "conio.h"
#include "string.h"
#define go {gotoxy(1,24);}
char vec[5][13];
static char adi[4][13]={"geovani","diosa","sandra","anghie"};
static char modi[4][13]={"centros","syscom","loperena","politecnico"};
void cuadro(int x1, int y1, int x2, int y2, char a1[],char a2[],char a3[],char a4[],char a5[],char a6[]);
int menuV(int fi,int col);
int menuH(void);
void boli(int fi,int ff,int c,int cf);
centraM(char men[],int f);
char c1[]="³",c2[]="Ä",c3[]="Ú",c4[]="Ù",c5[]="¿",c6[]="À";
char a1[]="º",a2[]="Í",a3[]="É",a4[]="¼",a5[]="»",a6[]="È";
int res;
void main()
{ int i;
  clrscr();
  strcat(vec[0],"  ADICION   ");
  strcat(vec[1],"MODIFICACION");
  strcat(vec[2],"  CONSULTA  ");
  strcat(vec[3],"  BORRADO   ");
  strcat(vec[4],"   SALIR    ");
  textcolor(5);
  cuadro(3,1,23,80,a1,a2,a3,a4,a5,a6);
  textbackground(11);
  textcolor(9);
  boli(1,1,1,80);
  centraM("UNIV/SANTANDER",1);
  textbackground(4);
  boli(2,2,1,80);
  centraM("CENTRO CERAMICO EL BUEN AMIGO",2);
  textbackground(4);
  boli(24,24,1,80);
  textbackground(11);
  boli(4,4,2,79);
  res=menuH();
}
void boli(int fi,int ff,int ci,int cf)
{ int i,j;
  for(i=fi;i<=ff;i++)
  { for(j=ci;j<=cf;j++)
   { gotoxy(j,i);cprintf(" ");}}
}
int menuH(void)
{ int i,j=0,r;
  char tecla;
  do
  { r=2;
   textbackground(0);
  /*clrscr();*/
   for(i=0;i<5;i++)
     { if (i==j)
      { textcolor(1);
	textbackground(7);
	gotoxy(2+r,4);cprintf("%s",vec[i]);
	}
      else
	{ textcolor(0);textbackground(11);
	  gotoxy(2+r,4);cprintf("%s",vec[i]);}
	r+=15;
	textcolor(3);
	switch(j)
	{ case 0:go;printf("Modulo para la adicion de clientes  ");
		 break;
	  case 1:go;printf("Modulo para la modificacion clientes");
		 break;
	  case 2:go;printf("Modulo para la consulta de cliente  ");
		 break;
	  case 3:go;printf("Modulo para el borrado de clientes  ");
		 break;
	  case 4:go;printf("Modulo para salir de la aplicacion  ");
		 break;
       }
      }
       tecla=getch();
	if (tecla==80)
	{  if (j<4)
	    j++;
	   else
	    j=0;
	}
	 if (tecla==72)
	   { if (j!=0)
	      j--;
	     else
	      j=4;
	   }
  }
  while (tecla!=13);
  return(j);
}
int menuV(int fi, int col)
{ int i,j=0;
  char tecla;
  do
  {
   textbackground(0);
  /* clrscr();*/
   for(i=0;i<5;i++)
     { if (i==j)
      { textcolor(1);
	textbackground(7);
	gotoxy(col,fi+i);cprintf("%s",vec[i]);
	}
      else
	{ textcolor(0);textbackground(11);
	  gotoxy(col,fi+i);cprintf("%s",vec[i]);}
	  }
       tecla=getch();
	if (tecla==80)
	{  if (j<4)
	    j++;
	   else
	    j=0;
	}
	 if (tecla==72)
	   { if (j!=0)
	      j--;
	     else
	      j=4;
	   }
  }
  while (tecla!=13);
  return(j);
}
void cuadro(int x1, int y1, int x2, int y2, char a1[],char a2[],char a3[],char a4[],char a5[],char a6[])
{  int i;
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
centraM(char men[],int f)
{ int lon,col;
  lon=strlen(men);
  col=(80-lon)/2;
  gotoxy(col,f);cprintf("%s",men);
}












