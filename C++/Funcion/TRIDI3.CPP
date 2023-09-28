#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int maxx,maxy;

   initgraph(&gdriver, &gmode, "\\tc\\bgi");

   errorcode = graphresult();
   if (errorcode != grOk)
   /* an error occurred */
   {
      printf("Error de inicializacion grafica: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
   /* termina con un codigo de error  */
      exit(1);
   }

   maxx = getmaxx();
   maxy = getmaxy();
   int I1X,I1Y,I2X,I2Y,I3X,I3Y,I4X,I4Y,I5X,I5Y,
       II1X,II1Y,II2X,II2Y,II3X,II3Y,II4X,II4Y,II5X,II5Y,
       III1X,III1Y,III2X,III2Y,III3X,III3Y,III4X,III4Y,III5X,III5Y,
       IV1X,IV1Y,IV2X,IV2Y,IV3X,IV3Y,IV4X,IV4Y,IV5X,IV5Y,VALOR,I;

  VALOR = maxx/80;

  I1X=(maxx/2)+(VALOR*30);
  I1Y=(maxy/2);
  I2X=(maxx/2)+(VALOR*26);
  I2Y=(maxy/2)-(VALOR*4);
  I3X=(maxx/2)+(VALOR*20);
  I3Y=(maxy/2)-(VALOR*6);
  I4X=(maxx/2)+(VALOR*12);
  I4Y=(maxy/2)-(VALOR*8);
  I5X=(maxx/2)+(VALOR*6);
  I5Y=(maxy/2)-(VALOR*9);   
   
  II1X=(maxx/2);
  II1Y=(maxy/2)-(VALOR*9);
  II2X=(maxx/2)-(VALOR*6);
  II2Y=(maxy/2)-(VALOR*9);
  II3X=(maxx/2)-(VALOR*12);
  II3Y=(maxy/2)-(VALOR*8);
  II4X=(maxx/2)-(VALOR*20);
  II4Y=(maxy/2)-(VALOR*6);
  II5X=(maxx/2)-(VALOR*26);
  II5Y=(maxy/2)-(VALOR*4);   
  
  III1X=(maxx/2)-(VALOR*30);
  III1Y=(maxy/2);
  III2X=(maxx/2)-(VALOR*26);
  III2Y=(maxy/2)+(VALOR*4);
  III3X=(maxx/2)-(VALOR*20);
  III3Y=(maxy/2)+(VALOR*6);
  III4X=(maxx/2)-(VALOR*12);
  III4Y=(maxy/2)+(VALOR*8);
  III5X=(maxx/2)-(VALOR*6);
  III5Y=(maxy/2)+(VALOR*9);   

  IV1X=(maxx/2);
  IV1Y=(maxy/2)+(VALOR*9);
  IV2X=(maxx/2)+(VALOR*6);
  IV2Y=(maxy/2)+(VALOR*9);
  IV3X=(maxx/2)+(VALOR*12);
  IV3Y=(maxy/2)+(VALOR*8);
  IV4X=(maxx/2)+(VALOR*20);
  IV4Y=(maxy/2)+(VALOR*6);
  IV5X=(maxx/2)+(VALOR*26);
  IV5Y=(maxy/2)+(VALOR*4);   

   int BI1X,BI1Y,BI2X,BI2Y,BI3X,BI3Y,BI4X,BI4Y,BI5X,BI5Y,
       BII1X,BII1Y,BII2X,BII2Y,BII3X,BII3Y,BII4X,BII4Y,BII5X,BII5Y,
       BIII1X,BIII1Y,BIII2X,BIII2Y,BIII3X,BIII3Y,BIII4X,BIII4Y,BIII5X,BIII5Y,
       BIV1X,BIV1Y,BIV2X,BIV2Y,BIV3X,BIV3Y,BIV4X,BIV4Y,BIV5X,BIV5Y;

 
  BI1X=(maxx/2)+(VALOR*30);
  BI1Y=(maxy/4);
  BI2X=(maxx/2)+(VALOR*26);
  BI2Y=(maxy/4)-(VALOR*4);
  BI3X=(maxx/2)+(VALOR*20);
  BI3Y=(maxy/4)-(VALOR*6);
  BI4X=(maxx/2)+(VALOR*12);
  BI4Y=(maxy/4)-(VALOR*8);
  BI5X=(maxx/2)+(VALOR*6);
  BI5Y=(maxy/4)-(VALOR*9);   
   
  BII1X=(maxx/2);
  BII1Y=(maxy/4)-(VALOR*9);
  BII2X=(maxx/2)-(VALOR*6);
  BII2Y=(maxy/4)-(VALOR*9);
  BII3X=(maxx/2)-(VALOR*12);
  BII3Y=(maxy/4)-(VALOR*8);
  BII4X=(maxx/2)-(VALOR*20);
  BII4Y=(maxy/4)-(VALOR*6);
  BII5X=(maxx/2)-(VALOR*26);
  BII5Y=(maxy/4)-(VALOR*4);   

  BIII1X=(maxx/2)-(VALOR*30);
  BIII1Y=(maxy/4);
  BIII2X=(maxx/2)-(VALOR*26);
  BIII2Y=(maxy/4)+(VALOR*4);
  BIII3X=(maxx/2)-(VALOR*20);
  BIII3Y=(maxy/4)+(VALOR*6);
  BIII4X=(maxx/2)-(VALOR*12);
  BIII4Y=(maxy/4)+(VALOR*8);
  BIII5X=(maxx/2)-(VALOR*6);
  BIII5Y=(maxy/4)+(VALOR*9);   

  BIV1X=(maxx/2);
  BIV1Y=(maxy/4)+(VALOR*9);
  BIV2X=(maxx/2)+(VALOR*6);
  BIV2Y=(maxy/4)+(VALOR*9);
  BIV3X=(maxx/2)+(VALOR*12);
  BIV3Y=(maxy/4)+(VALOR*8);
  BIV4X=(maxx/2)+(VALOR*20);
  BIV4Y=(maxy/4)+(VALOR*6);
  BIV5X=(maxx/2)+(VALOR*26);
  BIV5Y=(maxy/4)+(VALOR*4);   

  for (I=1;I<=10;I++)
  {
   delay(250);
   cleardevice();
   line (I1X,I1Y,II1X,II1Y);
   line (II1X,II1Y,III1X,III1Y);
   line (III1X,III1Y,IV1X,IV1Y);
   line (IV1X,IV1Y,I1X,I1Y);

   line (BI1X,BI1Y,BII1X,BII1Y);
   line (BII1X,BII1Y,BIII1X,BIII1Y);
   line (BIII1X,BIII1Y,BIV1X,BIV1Y);
   line (BIV1X,BIV1Y,BI1X,BI1Y);

   line (I1X,I1Y,BI1X,BI1Y);
   line (II1X,II1Y,BII1X,BII1Y);
   line (III1X,III1Y,BIII1X,BIII1Y);
   line (IV1X,IV1Y,BIV1X,BIV1Y);
   
   delay(250);
   cleardevice();
   line (I2X,I2Y,II2X,II2Y);
   line (II2X,II2Y,III2X,III2Y);
   line (III2X,III2Y,IV2X,IV2Y);
   line (IV2X,IV2Y,I2X,I2Y);

   line (BI2X,BI2Y,BII2X,BII2Y);
   line (BII2X,BII2Y,BIII2X,BIII2Y);
   line (BIII2X,BIII2Y,BIV2X,BIV2Y);
   line (BIV2X,BIV2Y,BI2X,BI2Y);
   
   line (I2X,I2Y,BI2X,BI2Y);
   line (II2X,II2Y,BII2X,BII2Y);
   line (III2X,III2Y,BIII2X,BIII2Y);
   line (IV2X,IV2Y,BIV2X,BIV2Y);

   delay(250);
   cleardevice();
   line (I3X,I3Y,II3X,II3Y);
   line (II3X,II3Y,III3X,III3Y);
   line (III3X,III3Y,IV3X,IV3Y);
   line (IV3X,IV3Y,I3X,I3Y);

   line (BI3X,BI3Y,BII3X,BII3Y);
   line (BII3X,BII3Y,BIII3X,BIII3Y);
   line (BIII3X,BIII3Y,BIV3X,BIV3Y);
   line (BIV3X,BIV3Y,BI3X,BI3Y);

   line (I3X,I3Y,BI3X,BI3Y);
   line (II3X,II3Y,BII3X,BII3Y);
   line (III3X,III3Y,BIII3X,BIII3Y);
   line (IV3X,IV3Y,BIV3X,BIV3Y);

   delay(250);
   cleardevice();
   line (I4X,I4Y,II4X,II4Y);
   line (II4X,II4Y,III4X,III4Y);
   line (III4X,III4Y,IV4X,IV4Y);
   line (IV4X,IV4Y,I4X,I4Y);

   line (BI4X,BI4Y,BII4X,BII4Y);
   line (BII4X,BII4Y,BIII4X,BIII4Y);
   line (BIII4X,BIII4Y,BIV4X,BIV4Y);
   line (BIV4X,BIV4Y,BI4X,BI4Y);

   line (I4X,I4Y,BI4X,BI4Y);
   line (II4X,II4Y,BII4X,BII4Y);
   line (III4X,III4Y,BIII4X,BIII4Y);
   line (IV4X,IV4Y,BIV4X,BIV4Y);

   delay(250);
   cleardevice();
   line (I5X,I5Y,II5X,II5Y);
   line (II5X,II5Y,III5X,III5Y);
   line (III5X,III5Y,IV5X,IV5Y);
   line (IV5X,IV5Y,I5X,I5Y);

   line (BI5X,BI5Y,BII5X,BII5Y);
   line (BII5X,BII5Y,BIII5X,BIII5Y);
   line (BIII5X,BIII5Y,BIV5X,BIV5Y);
   line (BIV5X,BIV5Y,BI5X,BI5Y);

   line (I5X,I5Y,BI5X,BI5Y);
   line (II5X,II5Y,BII5X,BII5Y);
   line (III5X,III5Y,BIII5X,BIII5Y);
   line (IV5X,IV5Y,BIV5X,BIV5Y);

   }

   getch();
   closegraph();
   return 0;
}

