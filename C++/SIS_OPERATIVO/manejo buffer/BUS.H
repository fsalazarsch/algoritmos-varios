# define escriba(t,tm,c,x,y,cad) {setcolor(c);settextstyle(t,0,tm);outtextxy(x,y,cad) ;}



 void bus(void)
  {
   unsigned userpart=1;
   cleardevice();

  setbkcolor(15);
  setcolor(13);
  setlinestyle(SOLID_LINE,userpart,2);
  rectangle(2,2,638,478); //Borde externo
  rectangle(4,4,636,476); //Borde interno



  setcolor(5);
  //arco exterior

  setlinestyle(SOLID_LINE,userpart,3);
  //carro
  line(160,60,460,60);arc(160,75,90,180,15);arc(461,75,0,90,15);
  line(145,75,145,250);arc(160,251,180,270,15);
  line(160,266,460,266);arc(461,251,270,360,15);
  line(476,75,476,250);
  //segunda ventana donde estan los ojos
  arc(160,286,90,180,20); arc(461,286,0,90,20);
  line(140,287,140,400); line(481,287,481,400);
  arc(160,394,180,270,20);arc(461,394,270,360,20);
  line(160,414,460,414);
  //nariz
  setcolor(13);
  rectangle(260,320,360,325);rectangle(260,340,360,345);rectangle(260,330,360,335);
  setfillstyle(1,13);floodfill(263,323,13);setfillstyle(1,13);floodfill(263,343,13);
  setfillstyle(1,13);floodfill(263,333,13);
  setcolor(14);
  circle(220,320,30);circle(405,320,30);
  setfillstyle(1,14);floodfill(225,325,14);
  setfillstyle(1,14);floodfill(410,325,14);
  setcolor(12);
  arc(310,360,180,0,30);
  //dos ventanas internas
  setcolor(12);
  rectangle(170,90,450,185);
  setfillstyle(10,12);floodfill(175,95,12);
  setcolor(9);
  rectangle(170,195,300,250);rectangle(320,195,450,250);
  setfillstyle(4,9);floodfill(175,200,9);
  setfillstyle(4,9);floodfill(325,200,9);

 //ruedas
  setcolor(8);
  rectangle(180,414,220,425);rectangle(400,414,440,425);
  setfillstyle(1,8);floodfill(185,419,8);
  setfillstyle(1,8);floodfill(405,419,8);

  setcolor(13);
  rectangle(130,440,490,465);  //rectangulos de opci¢n
  setfillstyle(11,13);floodfill(175,445,13);
  settextstyle(DEFAULT_FONT,0,1);
  outtextxy(140,451,"<< DIGITA CUALQUIER TECLA PARA CONTINUAR >>");

  settextstyle(2,0,4);
  outtextxy(140,20,"UNIVERSIDAD ANTONIO NARI¥O");

  settextstyle(1,0,2);
  textcolor(13);
  outtextxy(174,120,"!!SISTEMAS OPERATIVOS!!");
  delay(2000);

  setcolor(2);
  rectangle(170,90,450,185);
  setfillstyle(1,2);floodfill(175,95,2);
  escriba(0,1,8,180,95,"           ELABORADO POR:");
  escriba(0,1,8,180,115,"YAZMIN LOMBANA      CODIGO 494262");
  escriba(0,1,8,180,135,"JENNY FONSECA       CODIGO 491778");
  escriba(0,1,8,180,155,"ISABEL BAUTISTA     CODIGO 494256");
  delay(2000);

  setcolor(7);
  rectangle(170,90,450,185);
  setfillstyle(1,7);floodfill(175,95,7);
  escriba(0,1,8,180,95,"          PRESENTADO AL:");
  escriba(0,1,8,180,135,"   INGENIERO ROBERTO FERNANDEZ");
  escriba(0,1,8,180,175,"SANTAFE DE BOGOTA OCTUBRE/23/97");
  delay(2000);

  setcolor(13);
  rectangle(170,90,450,185);
  setfillstyle(10,13);floodfill(175,95,13);
  settextstyle(1,0,2);
  outtextxy(174,120,"!!SIMULACION BUFFER!!");
  getch();


 }

