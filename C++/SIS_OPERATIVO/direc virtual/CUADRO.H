void cuadro(int caso,int color,int x1,int y1,int x2,int y2)
{
 int i;
 char e1,e2,e3,e4,v,h;
 switch (caso)
 {
	case 0: e1='�';e2='�';e3='�';e4='�';h='�';v='�';break;
	case 1: e1='�';e2='�';e3='�';e4='�';h='�';v='�';break;
 }
 textcolor(color);
 for (i=x1;i<=x2;i++)
	{
	 gotoxy(i,y1);putch(h);
	 gotoxy(i,y2);putch(h);
	}
	for(i=y1;i<=y2;i++)
	{
	 gotoxy(x1,i);putch(v);
	 gotoxy(x2,i);putch(v);
	}
	gotoxy(x1,y1);putch(e1);
	gotoxy(x2,y1);putch(e2);
	gotoxy(x1,y2);putch(e3);
	gotoxy(x2,y2);putch(e4);
}