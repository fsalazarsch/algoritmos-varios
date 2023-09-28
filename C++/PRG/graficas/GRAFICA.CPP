#include<alloc.h>
#include<ctype.h>
#include"fcntl.h"
#include"io.h"
#include"iostream.h"
#include"graphics.h"
#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include"stdlib.h"
#include"string.h"
#include<math.h>

  double xmin=-20,xmax=20,ymin=-20,ymax=20,xscl=6,yscl=6;
  double expo1,cohef1,angulo,a,b;
  char eje,op,variable,funci[20]="",vec[3]="",msg[200];


  void far *buf[10];
  unsigned int size;
   int i,f,e,xm,ym;
void grafica();
void leer2();
void leer();
void dibujar2(double Xmin,double Xmax,double Ymin,double Ymax,int si);
void dibujar(double Xmin,double Xmax,double Ymin,double Ymax,int si);
void menu();
char lee_op(char S,char N);
char lee_op2(char S,char N);
double lee_nu(int x,int y,int n,char pri);
void dib_ret(int x,int y);
void bor_ret(int x,int y);
void pantalla1(int x1,int y1,int x2,int y2,char *pt);
void pantalla2(int x1,int y1,int x2,int y2,int q,char *pt);
void botton1(int x1,int y1,int x2,int y2,char *pt);
void int_pot();
void rango();
void error(char *er);
void vajar();
void lee_imagen(int x1,int y1,int x2,int y2,void *p);
void botton2(int x1,int y1,int x2,int y2,char *pt);

/**********************************************************************/

void menu()
{ do
  { cleardevice();
    setcolor(15);
    outtextxy(130,150,"1. grafica de funciones");
    outtextxy(130,170,"2. grafica de funciones trigonometricas");
    outtextxy(130,190,"3. rangos de las graficas");
    outtextxy(130,210,"4. salir");
    outtextxy(130,230,"digite su opcion: [ ]");
    op=lee_op2('1','4');
    switch(op)
    { case '1' : { leer(); int_pot(); break; }
      case '2' : { leer2(); break; }
      case '3' : { rango(); break; }
    }
  }while(op!='4');
}

/**********************************************************************/

void lee_imagen(int x1,int y1,int x2,int y2,void *p)
{ unsigned int size;
  size = imagesize(x1,y1,x2,y2);
  p = new char[size+1];
  getimage(x1,y1,x2,y2,p);
}  


/**********************************************************************/

char lee_op2(char S,char N)
{  char a;
   do
   { a=toupper(getche());
   }while(a<S||a>N); 
   return(a);
}


/**********************************************************************/

char lee_op(char S,char N)
{  char a;
   do
   { a=toupper(getche());
   }while(a!=S&&a!=N); 
   return(a);
}

/**********************************************************************/

void leer()
{ int ref=1; char pos;
  cleardevice(); op='N';
  pantalla1(50,60,580,420,"INTEGRAL DE LA POTENCIA");
  botton1(265,385,350,407,"Aceptar");
  outtextxy(200,185,"[         ]"); 
  outtextxy(170,340,"[ DIGITE COEFICIENTE DE LA VARIABLE ]");
  botton2(210,178,274,196,"");
   cohef1=lee_nu(218,185,5,' ');
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
  outtextxy(170,340,"[        DIGITE LA VARIABLE         ]");
  outtextxy(296,185,"[   ]");
  botton2(305,178,324,196,"");
   variable=lee_op2('A','Z');
  sprintf(msg,"%c",variable);
   outtextxy(312,185,msg);
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
  outtextxy(170,340,"[  DIGITE EXPONENTE DE LA VARIABLE  ]");
  botton2(355,178,419,196,"");
  outtextxy(344,185,"[         ]");
   expo1=lee_nu(363,184,5,' ');
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
    size = imagesize(180,164,446,298);
  buf[1] = new char [size+1];
   getimage(180,164,446,298,buf[1]);
  pantalla2(180,164,446,298,2,"LIMITES DE INTEGRACION");
  outtextxy(250,210,"DESEA EVALUAR");
  botton1(320,250,370,272,"No");
  size = imagesize(320,250,370,272);
  buf[2] = new char [size+1];
   getimage(320,250,370,272,buf[2]);
  botton1(230,250,280,272,"Si");
  size = imagesize(230,250,280,272);
  buf[3] = new char [size+1];
   getimage(230,250,280,272,buf[3]);
  do
  { switch(ref)
    { case 1: { setlinestyle(1,1,1); rectangle(235,255,275,267);
		setlinestyle(0,1,1); op='S';
		putimage(320,250,buf[2],0); break;
	      }
      case 2: { setlinestyle(1,1,1); rectangle(325,255,365,267);
		setlinestyle(0,1,1); op='N';  
		putimage(230,250,buf[3],0); break;
	      }
    }
    do
    { pos=getche();
    }while(pos!='\r'&&pos!='\t');
    if(ref==1) ref=2;
     else ref=1;
  }while(pos!='\r');
  putimage(180,164,buf[1],0);
  delete buf[1];
  delete buf[2];
  delete buf[3];

  if(ref==2) 
  { botton2(160,218,226,236,"");
    outtextxy(150,225,"[         ]");
    ref=1;
    setfillstyle(SOLID_FILL,7);
    bar(170,340,474,350);
    outtextxy(170,340,"[     DIGITE EL LIMITE INFERIOR     ]");
     a=lee_nu(168,225,5,' ');
    setfillstyle(SOLID_FILL,7);
    bar(170,340,474,350);
    outtextxy(170,340,"[     DIGITE EL LIMITE SUPERIOR     ]");
    botton2(160,138,226,156,"");
    outtextxy(150,145,"[         ]");
     b=lee_nu(168,145,5,' ');
    pantalla2(180,164,446,298,2,"EJES A EVALUAR");
    outtextxy(205,210,"EVALUAR RESPECTO A QUE EJE");
    botton1(210,250,260,272,"X");
    size = imagesize(210,250,260,272);
    buf[1] = new char [size+1];
     getimage(210,250,260,272,buf[1]);
    botton1(283,250,333,272,"Y");
    size = imagesize(283,250,333,272);
    buf[2] = new char [size+1];
     getimage(283,250,333,272,buf[2]);
    botton1(357,250,407,272,"AMBOS");
    size = imagesize(357,250,407,272);
    buf[3] = new char [size+1];
     getimage(357,250,407,272,buf[3]);
    do
    { switch(ref)
      { case 1: { setlinestyle(1,1,1); rectangle(215,255,255,267);
		  setlinestyle(0,1,1); eje='X';
		  putimage(357,250,buf[3],0); break;
		}
	case 2: { setlinestyle(1,1,1); rectangle(288,255,328,267);
		  setlinestyle(0,1,1); eje='Y';  
		  putimage(210,250,buf[1],0); break;
		}
	case 3: { setlinestyle(1,1,1); rectangle(362,255,402,267);
		  setlinestyle(0,1,1); eje='A';  
		  putimage(283,250,buf[2],0); break;
		}
      }
      do
      { pos=getche();
      }while(pos!='\r'&&pos!='\t');
      if(ref==3) ref=1;
       else ref++;
    }while(pos!='\r');
    delete buf[1];
    delete buf[2];
    delete buf[3];
  }
}

/**********************************************************************/

void pantalla1(int x1,int y1,int x2,int y2,char *pt)
{ setcolor(15);
  rectangle(x1,y1,x2,y1+20);
  setfillstyle (SOLID_FILL,1);
  bar(x1+3,y1+3,x2-3,y1+17);
  rectangle(x1,y1+20,x2,y2);
  setfillstyle (SOLID_FILL,7);
  bar(x1+3,y1+23,x2-3,y2-3);             
  outtextxy((x2-x1-6-strlen(pt)*8)/2+x1,y1+7,pt);
  setcolor(0);
}

/**********************************************************************/

void pantalla2(int x1,int y1,int x2,int y2,int q,char *pt)
{ setcolor(15);
  setfillstyle(SOLID_FILL,0);
  bar(x1+1,y1+1,x2,y2);
  setfillstyle(SOLID_FILL,8);
  bar(x1+2,y1+1,x2-1,y2-1);
  setfillstyle(SOLID_FILL,15);
  bar(x1,y1,x2-2,y2-2);
  setfillstyle(SOLID_FILL,7);
  bar(x1+2,y1+1,x2-2,y2-2);
  setfillstyle(SOLID_FILL,4);
  bar(x1+3,y1+2,x2-3,y1+20);
  if(q==1) outtextxy(x1+10,y1+7,pt);
  else outtextxy((x2-x1-6-strlen(pt)*8)/2+x1,y1+7,pt);
  setcolor(0);
  
}

/**********************************************************************/

void botton1(int x1,int y1,int x2,int y2,char *pt)
{ setcolor(0);
  setfillstyle (SOLID_FILL,15);
  bar(x1,y1,x2,y2);              
  setfillstyle (SOLID_FILL,0);
  bar(x1+1,y1+1,x2,y2);
  setfillstyle (SOLID_FILL,7);
  bar(x1+1,y1+1,x2-1,y2-1);
  outtextxy((x2-x1-strlen(pt)*8)/2+x1,y1+7,pt);
}

/*********************************************************************/

void botton2(int x1,int y1,int x2,int y2,char *pt)
{ setcolor(0);
  setfillstyle (SOLID_FILL,15);
  bar(x1,y1,x2+2,y2+2);
  setfillstyle (SOLID_FILL,7);
  bar(x1,y1,x2+1,y2+1);
  setfillstyle (SOLID_FILL,0);
  bar(x1,y1,x2,y2);
  setfillstyle (SOLID_FILL,15);
  bar(x1+1,y1+1,x2,y2);
  outtextxy((x2-x1-strlen(pt)*8)/2+x1,y1+7,pt);
}

/**********************************************************************/

void fle4(int n,char s)
{ char c,cad1[50],cad2[50];
  do
  { cleardevice();
    grafica();
    botton1(25,435,110,457,"Aceptar");
    setlinestyle(1,1,1); rectangle(30,440,105,452);
    setlinestyle(0,1,1);

    circle(575,420,41);
    circle(575,420,21);
    circle(575,420,16);

    if(xm>319) botton2(540,410,560,430,"");
     else botton1(540,410,560,430,"");

    if(xm<319) botton2(590,410,610,430,"");
     else botton1(590,410,610,430,"");

    if(ym<239) botton2(564,435,584,455,"");
     else botton1(564,435,584,455,"");

    if(ym>239) botton2(564,385,584,405,"");
     else botton1(564,385,584,405,"");

    sprintf(msg,"%c",30);
    outtextxy(570,392,msg);
    sprintf(msg,"%c",31);
    outtextxy(570,442,msg);

    setfillstyle (7,1);
    bar(615,30,630,45);

    if(n==1)
    { sprintf(cad1,"%.1lf",cohef1);
      sprintf(cad2,"%.1lf",expo1);
      strcpy(msg,cad1);
      sprintf(cad1,"%c",variable);
      strcat(msg,"(");
      strcat(msg,cad1);
      strcat(msg,")^");
      strcat(msg,cad2);
      outtextxy(50,100,msg);
      dibujar(xmin,xmax,ymin,ymax,1);
    }
     else
     if(n==2)
     { sprintf(cad1,"%.1lf",cohef1);
       sprintf(cad2,"%.1lf",expo1);
       strcpy(msg,cad1);
       strcat(msg,"(");
       strcat(msg,funci);
       strcat(msg,")^");
       strcat(msg,cad2);
       outtextxy(50,100,msg);
       dibujar2(xmin,xmax,ymin,ymax,1);
     }
    if(n==1&&s=='S') dibujar(a,b,ymin,ymax,2);
     else if(n==2&&s=='S') dibujar2(a,b,ymin,ymax,2);

    setfillstyle (SOLID_FILL,7);
    bar(615,30,630,45);

    do
    { c=getche();
    }while(c!=72&&c!=75&&c!=77&&c!=80&&c!='\r');
    switch(c)
    { case 75: { xm+=50; break; }
      case 77: { xm-=50; break; }
      case 72: { ym+=50; break; }
      case 80: { ym-=50; break; }
    }
  }while(c!='\r');
}

/**********************************************************************/

void rango()
{ botton2(295,143,378,163,"");
  size = imagesize(295,143,380,165);
  buf[1] = new char [size+1];
  getimage(295,143,380,165,buf[1]);
  cleardevice();
  pantalla1(80,80,520,400,"PARAMETROS DE GAMA DE LOS GRAFICOS");
  buf[2] = new char [size+1];
  getimage(295,143,380,165,buf[2]);
  outtextxy(200,150,"Xmin .....:");
  outtextxy(200,180,"Xmax .....:");
  outtextxy(200,210,"Xscl .....:");
  outtextxy(200,240,"Ymin .....:");
  outtextxy(200,270,"Ymax .....:");
  outtextxy(200,300,"Yscl .....:");
  botton1(250,350,335,372,"Aceptar");
  size = imagesize(250,350,335,372);
  buf[3] = new char [size+1];
  getimage(250,350,335,372,buf[3]);
  vajar(); 
  delete buf[1];
  delete buf[2];
  delete buf[3];
}

/**********************************************************************/
  
void vajar()
{ char pos,pos2; int ref=1;
  do
  { switch(ref)
    { case 1: { dib_ret(295,143); bor_ret(250,350); break; }
      case 2: { dib_ret(295,173); bor_ret(295,143); break; }
      case 3: { dib_ret(295,203); bor_ret(295,173); break; }
      case 4: { dib_ret(295,233); bor_ret(295,203); break; }
      case 5: { dib_ret(295,263); bor_ret(295,233); break; }
      case 6: { dib_ret(295,293); bor_ret(295,263); break; }
      case 7: { dib_ret(250,350); bor_ret(295,293); break; }
    }
    setcolor(0);
    sprintf(msg,"%.2lf",xmin);
    outtextxy(300,150,msg);
    sprintf(msg,"%.2lf",xmax);
    outtextxy(300,180,msg);
    sprintf(msg,"%.2lf",xscl);
    outtextxy(300,210,msg);
    sprintf(msg,"%.2lf",ymin);
    outtextxy(300,240,msg);
    sprintf(msg,"%.2lf",ymax);
    outtextxy(300,270,msg);
    sprintf(msg,"%.2lf",yscl);
    outtextxy(300,300,msg);
    do
    { pos=getche();
      if(pos=='\r'&&ref==7) break;
    }while(pos!='\t'&&pos!='.'&&pos!='+'&&pos!='-'&&(pos<'0'||pos>'9'));
    if(pos!='\t')
    { pos2=pos;
      switch(ref)
      { case 1: { do
		  { xmin=lee_nu(300,150,4,pos2);
		    if(xmin>=xmax) error("Xmin deve ser menor que Xmax");
		     else
		     if(xmin<-200||xmin>200) error("fuera de rango"); pos2=' ';
		  }while(xmin>=xmax||xmin<-200||xmin>200); break;
		}
	case 2: { do
		  { xmax=lee_nu(300,180,4,pos2);
		    if(xmax<=xmin) error("Xmax deve ser mayor que Xmin");
		     else
		     if(xmax<-200||xmax>200) error("fuera de rango"); pos2=' ';
		  }while(xmax<=xmin||xmax<-200||xmax>200); break;
		}

	case 3: { do
		  { xscl=lee_nu(300,210,4,pos2);
		    if(xscl<=0||xscl>15) error("fuera de rango"); pos2=' ';
		  }while(xscl<=0||xscl>15); break;
		}

	case 4: { do
		  { ymin=lee_nu(300,240,4,pos2);
		    if(ymin>=ymax) error("Ymin deve ser menor que Ymax");
		     else
		     if(ymin<-200||ymin>200) error("fuera de rango"); pos2=' ';
		  }while(ymin>=ymax||ymin<-200||ymin>200); break;
		}
	case 5: { do
		  { ymax=lee_nu(300,270,4,pos2);
		    if(ymax<=ymin) error("Ymax deve ser mayor que Ymin");
		     else
		     if(ymax<-200||ymax>200) error("fuera de rango"); pos2=' ';
		  }while(ymax<=ymin||ymax<-200||ymax>200); break;
		}

	case 6: { do
		  { yscl=lee_nu(300,300,4,pos2);
		    if(yscl<=0||yscl>15) error("fuera de rango"); pos2=' ';
		  }while(yscl<=0||yscl>15); break;
		}
      }
    }
    if(ref==7&&pos=='\t') ref=1;
    else ref++;
  }while(pos!='\r'&&ref!=8);

}

/**********************************************************************/

void dib_ret(int x,int y)
{ if(y==350)
  { setlinestyle(1,1, 1);
    rectangle(x+5,y+5,x+80,y+17);
    setlinestyle(0,1, 1);
  }
  else
   putimage(x,y,buf[1],0);

}

/**********************************************************************/

void bor_ret(int x,int y)
{ if(y==350) 
   putimage(x,y,buf[3],0);
  else
   putimage(x,y,buf[2],0);
}

/**********************************************************************/

double lee_nu(int x,int y,int n,char pri)
{ char info[10]="";
  int i=0,pun=0;
  double num;
  info[i]=pri;
  setfillstyle (SOLID_FILL,15);
  bar(x-3,y-3,x+54,y+10);
  while(i<n)
  { setcolor(0);  
    sprintf(msg,"%c",info[i]);
    msg[1]='\0';
    outtextxy(x+i*8,y,msg);
    if(info[i]=='\b'&&i>0) 
    { if(info[i-1]=='.') pun=0; 
      i-=2; 
    }
    else 
    { if(info[i]=='\r'&&i>0&&info[i-1]!='.') break;
      if((info[i]=='-'||info[i]=='+')&&i==0) i++;
      else
       if(info[i]=='.'&&i<n&&pun==0) { i++; pun=1; }
      if((!isdigit(info[i]))||(info[i]=='¥')||(info[i]=='¤')) i--;
    }
    setcolor(15); i++;
    outtextxy(x+i*8,y,"ÛÛ");
    info[i]=getche();
    info[i+1]='\0';
  }
  setcolor(15);
  outtextxy(x+i*8,y,"Û");
  setcolor(0);
  info[i]='\0';
  num=atof(info);
  return(num);    
}

/**********************************************************************/

void error(char *er)
{ int lon,i,y,f;
  size = imagesize(180,164,447,298);
  buf[4] = new char [size+1];
  getimage(180,164,447,298,buf[4]);
  pantalla2(180,164,446,298,1,"Error....");
  setcolor(4);
  circle(220,219,20);
  floodfill(220,219,4);
  setcolor(15);
  for(i=207;i<=213;i++)
  { line(i,210,i+20,230);
    line(i+20,210,i,230);
  }
  setcolor(0);
  lon=strlen(er);
  y=200;
  if(lon<=20) outtextxy(260,200,er);
  else
   for(f=0,i=0;i<lon;i++,f++)
   { sprintf(msg,"%c",er[i]);
     if(f==20)
     { f=0; y+=30; }
     outtextxy(260+f*8,y,msg);
   }
  botton1(270,260,355,282,"Aceptar");
  setlinestyle(1,1, 1);
  rectangle(275,265,348,277);
  setlinestyle(0,1, 1);
  getche();
  putimage(180,164,buf[4],0);
  delete buf[4];
}

/**********************************************************************/

void int_pot()
{ char op2,pos;
  double auxE,auxC,auxA,auxB,a1,a2;
  int ax,ref=1;
  do
  { cleardevice();
    pantalla1(50,60,580,420,"INTEGRAL DE LA POTENCIA");
    botton1(265,385,350,407,"Aceptar");
    if((eje=='Y')||(eje=='A')) 
    { auxA=pow(a*cohef1,expo1);
      auxB=pow(b*cohef1,expo1);
      auxC=1/cohef1;
      auxE=1/expo1;
    } 
    else
    { auxC=cohef1;
      auxE=expo1;
      auxA=a;
      auxB=b;
    }
    settextstyle(3,HORIZ_DIR,1);
    sprintf(msg,"%.1lf(%c)",cohef1,variable); 
    outtextxy(130,140,msg);
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
    ax=132+strlen(msg)*10;
    sprintf(msg,"%.1lf",expo1); 
    outtextxy(ax,140,msg);
    settextstyle(3,HORIZ_DIR,1);
    moveto(ax+strlen(msg)*10,140);
    if(eje=='Y') 
     outtext("dy");
    else
     outtext("dx");
    if(auxE==-1) 
    { sprintf(msg,"%.1lf ln(%c)",cohef1,variable);
      outtextxy(130,230,msg);
      ax=132+strlen(msg)*10;
    }
    else
    { sprintf(msg,"%.1lf(%c)",cohef1/(expo1+1),variable); 
      outtextxy(130,230,msg);
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
      ax=132+strlen(msg)*10;
      sprintf(msg,"%.1lf",expo1+1); 
      outtextxy(ax,230,msg);
      settextstyle(3,HORIZ_DIR,1);
      ax+=strlen(msg)*10;
    }
    if(op=='S')
     outtextxy(ax,230,"]");
    else
     outtextxy(ax,230,"+ C");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
    if(op=='S')
    { sprintf(msg,"%.1lf",b);
      outtextxy(125,125,msg);
      outtextxy(ax+8,220,msg);
      sprintf(msg,"%.1lf",a);
      outtextxy(125,180,msg);
      outtextxy(ax+8,260,msg);
      if(expo1==-1) 
      { if(a<0) a=1/(a*(-1));
	else
	 if(b<0) b=1/(b*(-1));
	a2=(log(b)-log(a))*cohef1;
	sprintf(msg,"area = %.2lf uý",a2); 
      }
      else
      { a2=(pow(b,expo1+1)-pow(a,expo1+1))*(cohef1/(expo1+1));
	sprintf(msg,"area = %.1lf uý",a2); 
      }  
      settextstyle(3,HORIZ_DIR,1);
      outtextxy(125,310,msg);
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
    }
    if(eje=='A')
    { 
      settextstyle(3,HORIZ_DIR,1);
      sprintf(msg,"%.1lf(%c)",auxC,variable); 
      outtextxy(350,140,msg);
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
      ax=352+strlen(msg)*10;
      sprintf(msg,"%.1lf",auxE); 
      outtextxy(ax,140,msg);
      settextstyle(3,HORIZ_DIR,1);
      outtextxy(ax+strlen(msg)*10,140,"dy");
      if(auxE==-1) 
      { sprintf(msg,"%.1lf ln(%c)",auxC,variable);
	outtextxy(350,230,msg);
	ax=352+strlen(msg)*10;
      }
      else
      { sprintf(msg,"%.1lf(%c)",auxC/(auxE+1),variable); 
	outtextxy(350,230,msg);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
	ax=352+strlen(msg)*10;
	sprintf(msg,"%.1lf",auxE+1); 
	outtextxy(ax,230,msg);
	settextstyle(3,HORIZ_DIR,1);
	ax+=strlen(msg)*10;
      }
      outtextxy(ax,230,"]");
      settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
      if(op=='S')
      { sprintf(msg,"%.1lf",auxB);
	outtextxy(345,125,msg);
	outtextxy(ax+8,220,msg);
	sprintf(msg,"%.1lf",auxA);
	outtextxy(345,180,msg);
	outtextxy(ax+8,260,msg);
	if(auxE==-1) 
	{ if(auxA<0) auxA=1/(auxA*(-1));
	  else
	   if(auxB<0) auxB=1/(auxB*(-1));
	  a1=(log(auxB)-log(auxA))*auxC;
	  sprintf(msg,"area = %.2lf uý",a1); 
	}
	else
	{ a1=(pow(auxB,auxE+1)-pow(auxA,auxE+1))*(auxC/(auxE+1));
	  sprintf(msg,"area = %.1lf uý",a1); 
	}
	settextstyle(3,HORIZ_DIR,1);
	outtextxy(355,310,msg);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,1);
      }

    }
    
  botton1(480,385,565,407,"Grafica");
  size = imagesize(480,385,565,407);
  buf[2] = new char [size+1];
   getimage(480,385,565,407,buf[2]);

  size = imagesize(265,385,350,407);
  buf[3] = new char [size+1];
   getimage(265,385,350,407,buf[3]);
   ref=2;
    do
    { switch(ref)
       { case 1: { setlinestyle(1,1,1); rectangle(270,390,345,402);
		   setlinestyle(0,1,1); op2='S';
		   putimage(480,385,buf[2],0); break;
		 }
	 case 2: { setlinestyle(1,1,1); rectangle(485,390,560,402);
		   setlinestyle(0,1,1); op2='N';  
		   putimage(265,385,buf[3],0); break;
		 }
       }
       do
       { pos=getche();
       }while(pos!='\r'&&pos!='\t');
       if(ref==1) ref=2;
	else ref=1;
    }while(pos!='\r');
    delete buf[2];
    delete buf[3];
    if(op2=='N')
     fle4(1,op);
  }while(op2=='N');

}

/**********************************************************************/

void leer2()
{ int ref=1,b1; char pos,op2;
  cleardevice(); op='N';
  pantalla1(50,60,580,420,"GRAFICAS  DE  FUNCIONES  TRIGONOMETRICAS");
  botton1(265,385,350,407,"Aceptar");
  outtextxy(150,185,"[         ]");
  outtextxy(170,340,"[ DIGITE COEFICIENTE DE LA FUNCION ]");
  botton2(160,178,224,196,"");
   cohef1=lee_nu(168,185,5,' ');
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
  outtextxy(170,340,"[        ESCOJA LA FUNCION         ]");

  b1=138;
do
{ botton2(253,b1,344,b1+18,"");
  outtextxy(260,145,"Seno");
  outtextxy(260,165,"Coseno");
  outtextxy(260,185,"Tangente");
  outtextxy(260,205,"Cotangente");
  outtextxy(260,225,"Secante");
  outtextxy(260,245,"Cosecante");
  outtextxy(243,185,"[            ]");
  do
  { pos=getche();
  }while(pos!='\r'&&pos!=72&&pos!=80);
  switch(pos)
    { case 80: if(b1==238) b1=138;
		 else b1+=20;
	       break;
      case 72: if(b1==138) b1=238;
		 else b1-=20;
		break;
      case '\r': break;
    }
  setfillstyle(SOLID_FILL,7);
  bar(249,138,347,260);
}while(pos!='\r');
  switch(b1)
  { case 138: strcpy(funci,"seno"); break;
    case 158: strcpy(funci,"coseno"); break;
    case 178: strcpy(funci,"tangente"); break;
    case 198: strcpy(funci,"cotangente"); break;
    case 218: strcpy(funci,"secante"); break;
    case 238: strcpy(funci,"cosecante"); break;
  }
  botton2(253,178,344,196,"");
  outtextxy(260,185,funci);
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
  outtextxy(170,340,"[  DIGITE EXPONENTE DE LA FUNCION  ]");
  botton2(375,178,439,196,"");
  outtextxy(364,185,"[         ]");
   expo1=lee_nu(383,184,5,' ');
  setfillstyle(SOLID_FILL,7);
  bar(170,340,474,350);
  size = imagesize(180,164,446,298);
  buf[1] = new char [size+1];
   getimage(180,164,446,298,buf[1]);
  pantalla2(180,164,446,298,2,"LIMITES DE LA FUNCION");
  outtextxy(250,210,"DESEA EVALUAR");
  botton1(320,250,370,272,"No");
  size = imagesize(320,250,370,272);
  buf[2] = new char [size+1];
   getimage(320,250,370,272,buf[2]);
  botton1(230,250,280,272,"Si");
  size = imagesize(230,250,280,272);
  buf[3] = new char [size+1];
   getimage(230,250,280,272,buf[3]);
  do
  { switch(ref)
    { case 1: { setlinestyle(1,1,1); rectangle(235,255,275,267);
		setlinestyle(0,1,1); op='S';
		putimage(320,250,buf[2],0); break;
	      }
      case 2: { setlinestyle(1,1,1); rectangle(325,255,365,267);
		setlinestyle(0,1,1); op='N';  
		putimage(230,250,buf[3],0); break;
	      }
    }
    do
    { pos=getche();
    }while(pos!='\r'&&pos!='\t');
    if(ref==1) ref=2;
     else ref=1;
  }while(pos!='\r');
  putimage(180,164,buf[1],0);
  delete buf[1];
  delete buf[2];
  delete buf[3];

  if(ref==2) 
  { botton2(160,218,226,236,"");
    outtextxy(150,225,"[         ]");
    ref=1;
    setfillstyle(SOLID_FILL,7);
    bar(170,340,474,350);
    outtextxy(170,340,"[     DIGITE EL LIMITE INFERIOR     ]");
     a=lee_nu(168,225,5,' ');
    setfillstyle(SOLID_FILL,7);
    bar(170,340,474,350);
    outtextxy(170,340,"[     DIGITE EL LIMITE SUPERIOR     ]");
    botton2(160,138,226,156,"");
    outtextxy(150,145,"[         ]");
     b=lee_nu(168,145,5,' ');
    size = imagesize(180,164,446,298);
    buf[4] = new char [size+1];
     getimage(180,164,446,298,buf[4]);
    pantalla2(180,164,446,298,2,"EJES A EVALUAR");
    outtextxy(205,210,"EVALUAR RESPECTO A QUE EJE");
    botton1(210,250,260,272,"X");
    size = imagesize(210,250,260,272);
    buf[1] = new char [size+1];
     getimage(210,250,260,272,buf[1]);
    botton1(283,250,333,272,"Y");
    size = imagesize(283,250,333,272);     
    buf[2] = new char [size+1];
     getimage(283,250,333,272,buf[2]);
    botton1(357,250,407,272,"A");
    size = imagesize(357,250,407,272);
    buf[3] = new char [size+1];
     getimage(357,250,407,272,buf[3]);
    do
    { switch(ref)
      { case 1: { setlinestyle(1,1,1); rectangle(215,255,255,267);
		  setlinestyle(0,1,1); eje='X'; 
		  putimage(357,250,buf[3],0); break;
		}
	case 2: { setlinestyle(1,1,1); rectangle(288,255,328,267);
		  setlinestyle(0,1,1); eje='Y';  
		  putimage(210,250,buf[1],0); break;
		}
	case 3: { setlinestyle(1,1,1); rectangle(362,255,402,267);
		  setlinestyle(0,1,1); eje='A';  
		  putimage(283,250,buf[2],0); break;
		}
      }
      do
      { pos=getche();
      }while(pos!='\r'&&pos!='\t');
      if(ref==3) ref=1;
       else ref++;
    }while(pos!='\r');
    putimage(180,164,buf[4],0);
    delete buf[1];
    delete buf[2];
    delete buf[3];
    delete buf[4];
  }



  botton1(480,385,565,407,"Grafica");
  size = imagesize(480,385,565,407);
  buf[2] = new char [size+1];
   getimage(480,385,565,407,buf[2]);

  size = imagesize(265,385,350,407);
  buf[3] = new char [size+1];
   getimage(265,385,350,407,buf[3]);
  ref=2;
  do
  { switch(ref)
    { case 1: { setlinestyle(1,1,1); rectangle(270,390,345,402);
		setlinestyle(0,1,1); op2='S';
		putimage(480,385,buf[2],0); break;
	      }
      case 2: { setlinestyle(1,1,1); rectangle(485,390,560,402);
		setlinestyle(0,1,1); op2='N';
		putimage(265,385,buf[3],0); break;
	      }
    }
    do
    { pos=getche();
    }while(pos!='\r'&&pos!='\t');
    if(ref==1) ref=2;
     else ref=1;
  }while(pos!='\r');
    delete buf[2];
    delete buf[3];
    if(op2=='N')
     fle4(2,op);
}

/**********************************************************************/

void dibujar(double Xmin,double Xmax,double Ymin,double Ymax,int si)
{ double a1,a2,ff;
  for(ff=Xmin;ff<=Xmax;ff+=0.001)
  {  if(si==1) setcolor(2);
      else setcolor(1);
     if(expo1==0) a1=1;
     else                                        
      if(ff==0) a1=0;
      else 
       a1=pow(ff,expo1);
    a2=a1*cohef1;
    if((a2>=Ymin)&&(a2<=Ymax))
    { outtextxy(ff*xscl+xm-3,ym-6-a2*yscl,".");
      if(si!=1) 
      { if(eje=='A')
	{ line(ff*xscl+xm,ym-a2*yscl,ff*xscl+xm,ym);      
	  setcolor(4);
	  line(ff*xscl+xm,ym-a2*yscl,xm,ym-a2*yscl);       
	}
	else
	 if(eje=='X') line(ff*xscl+xm,ym-a2*yscl,ff*xscl+xm,ym);      
	   else line(ff*xscl+xm,ym-a2*yscl,xm,ym-a2*yscl);       
      }
    }
  } 
}

/**********************************************************************/

void dibujar2(double Xmin,double Xmax,double Ymin,double Ymax,int si)
{ double a1,a2,ff;
  for(ff=Xmin;ff<=Xmax;ff+=0.001)
  { if(si==1) setcolor(2);
     else setcolor(1);
    if(!strcmp(funci,"seno")) a1=sin(ff);        
    else
     if(!strcmp(funci,"coseno")) a1=cos(ff);     
    else
     if(!strcmp(funci,"tangente")) a1=tan(ff);
    else
     if(!strcmp(funci,"cotangente")) 
     { if(sin(ff)==0) continue; 
       else
	if(cos(ff)==0) a1=0;
	else       
	 a1=(cos(ff)/sin(ff));
     }
     else
      if(!strcmp(funci,"secante"))
      { if(cos(ff)==0) continue; 
	a1=(1/cos(ff)); 
      }
      else
       { if(sin(ff)==0) continue; 
	 a1=(1/sin(ff));
       }
    if(expo1==0) a1=1;
    else 
     if(ff==0) a1=0;
     else 
      a1=pow(a1,expo1);
    a2=a1*cohef1;
    if((a2>=Ymin)&&(a2<=Ymax))
    { outtextxy(ff*xscl+xm-3,ym-6-a2*yscl,".");
      if(si!=1) 
      { if(eje=='A')
	{ line(ff*xscl+xm,ym-a2*yscl,ff*xscl+xm,ym);      
	  setcolor(4);
	  line(ff*xscl+xm,ym-a2*yscl,xm,ym-a2*yscl);       
	}
	else
	 if(eje=='X') line(ff*xscl+xm,ym-a2*yscl,ff*xscl+xm,ym);      
	   else line(ff*xscl+xm,ym-a2*yscl,xm,ym-a2*yscl);       
      }
    }
  } 
}

/**********************************************************************/

void grafica()
{  pantalla1(0,0,639,479,"GRAFICA DE FUNCIONES");
   line(xm,22,xm,479);
   line(2,ym,639,ym);
   sprintf(msg,"%c",30);
   outtextxy(xm-2.5,23,msg);
   sprintf(msg,"%c",31);
   outtextxy(xm-2.5,479-7,msg);
   outtextxy(639-8,ym-3,"");
   outtextxy(3,ym-3,"");
   outtextxy(xm-30,30,"(Y)");
   outtextxy(xm-38,479-15,"(-Y)");
   outtextxy(10,ym-17,"(-X)");
   outtextxy(639-30,ym-17,"(X)");
   for(i=17;i<=639-20;i+=40)
   { outtextxy(i,ym,"|");
     outtextxy(xm,i,"-");
   }
}

/**********************************************************************/

void main()
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   xm = getmaxx()/2;
   ym = getmaxy()/2;
   menu();
   closegraph();
}

/**********************************************************************/

