#include <graphics.h>
#include <conio.h>
main()
{
int gd,gm;
initgraph(&gd,&gm,"c:\\borlandc\\bgi");
circle(100,100,10);
rectangle(150,150,200,200);
getch();
getch();
return 0;
}