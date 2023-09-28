  #include<conio.h>
  #include<stdio.h>
 // #include<stdlib.h>
  #include<dos.h>
  #include<iostream.h>
// #include<ctype.h>
  void main()
  {
  clrscr();
 void caracol();
  caracol();
  getch();

 }



void caracol()
{
 int max,min,i,j,x,k,n,matriz[100][100];
  clrscr();
 cout<<"digite el orden de la matriz: ";
  cin>>max;
  min=k=x=0;
  for(i=min;i<max;i++)
   for(j=min;j<max;j++)
    { cout<<" matriz[i][j]"<< i+1,j+1;
     cin>> matriz[i][j];
    }
  n=max*2-1;
  clrscr();
  cout<<"\n\nRespuesta...:  ";
  for(i=min;i<n;i++)
  { for(j=min;j<max;j++)
    { if(i%2==0)
      { if(x==min) k=j;
	else
	{ if(k==min) break;
	  k--;
	}
      }
      else
      { if(k==max-1)
	{ if(x==max-1) break;
	  x++;
	}
	else
	{ if(x==min+1) break;
	  x--;
	}
      }
      delay(300);//la libreria es la dos.h
      gotoxy(k*7+20,x+3);cprintf("%d",matriz[x][k]);
    }
    if((i+1)%4==0)
    { min++; max--; }
  }
  getche();
}
void caracol(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); cprintf("%c",218); //Ú
  gotoxy(x2, y1); cprintf("%c",191); //¿
  gotoxy(x1, y2); cprintf("%c",192); //À
  gotoxy(x2, y2); cprintf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);cprintf("%c",196);//Ä
       gotoxy(i, y2);cprintf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);cprintf("%c",179); //³
       gotoxy(x2, i);cprintf("%c",179);
       }}
