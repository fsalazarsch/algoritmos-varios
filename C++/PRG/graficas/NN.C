#include<stdio.h>
#include<conio.h>
#include<graphics.h>

main()
{
  int z,p,i,j,GraphDriver,GraphMode,ErrorCode;			/* Used to read the aspect ratio*/
   int k;
  GraphDriver = DETECT; 		/* Request auto-detection	*/
  initgraph( &GraphDriver, &GraphMode, "C:\\borlandc\\bgi" );
  ErrorCode = graphresult();		/* Read result of initialization*/
  if( ErrorCode != grOk ){		/* Error occured during init	*/
    printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
    exit( 1 );}
do{
 j=getmaxx();
 for (i=1;i<=getmaxx();i++)
 {
 cleardevice();
 setcolor(4);
 settextstyle(4,0,10);
 outtextxy(j,30,"ALVARO");
 j=j-1;delay(15 );
if(i==getmaxx())
{
 for (k=1;k<=102;k++)
 {
 cleardevice();
 setcolor(4);
 settextstyle(4,0,10);
 outtextxy(j,30,"ALVARO");
 j=j+1;delay(15);}

 }
 }
}while(!kbhit());
 getch();
 closegraph();
 }
