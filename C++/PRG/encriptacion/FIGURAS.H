#define pi 3.14159265359



 void pantalla(int x1,int y1,int x2,int y2,int COLORS)
      {
       setfillstyle(1,COLORS);
       bar(x1,y1,x2,y2);
      }


      void impresi(int ver,int ho,char ** menu,int tope)
     {
      int i=0;
      settextstyle(3,0,2);
      setcolor(WHITE);
      for(;i<=tope;i++)
       {
	outtextxy(ver,ho,&(*menu[i]));
	ho+=20;
       }
    }



  void videoinver(int color1,int color2)
  {
  setcolor(color1);
  setbkcolor(color2);
  }

   void videonorm(int color1,int color2)
  {
  setcolor(color1);
  setbkcolor(color2);
  }



 void l_dda(float x1,float y1,float x2,float y2,int color)
 {
    float dy=y2-y1 , dx=x2-x1;
    float incx=0, incy=0;
    float paso=0;
    int cont=0;

    if(abs(dx)>abs(dy))
       paso=abs(dx);
    else
       paso=abs(dy);

     incx=dx/paso;
     incy=dy/paso;
     while(cont<=paso)
      {
       putpixel(x1,y1,color);
       x1+=incx;
       y1+=incy;
       cont++;
      }
   }



 void c_trigo(int h,int k,int rad,int color)
 {
 int a=rad,b=rad;
 int x=0,y=0;
 float pi2=pi/2;
 float teta=pi2/100;

 while(teta<pi2)
 {
  x=a*cos(teta);
  y=b*sin(teta);
      putpixel(x+h,y+k,color);
      putpixel(h-x,y+k,color);
      putpixel(h-x,k-y,color);
      putpixel(x+h,k-y,color);
  teta+=0.001;
  }
 }



 void c_arco(int h,int k,int rad,float ang_ini,float ang_fin,int color)
  {
  int a=rad,b=rad;
  int x=0,y=0;
  float aux=0;

  if(ang_ini > ang_fin)
    {
    aux=ang_ini;
    ang_ini=ang_fin;
    ang_fin=aux;
    }

 while(ang_ini<ang_fin)
 {
  x=a*cos(ang_ini);
  y=b*sin(ang_ini);

    putpixel(h+x,k-y,color);
    ang_ini+=0.001;
  }
 }




 void e_trigo(int h,int k,int rad_x,int rad_y,int color)
 {
 int x=0,y=0;
 float pi2=pi/2;
 float teta=pi2/100;

 while(teta<pi2)
 {
  x=rad_x*cos(teta);
  y=rad_y*sin(teta);
      putpixel(h+x,k+y,color);
      putpixel(h-x,k+y,color);
      putpixel(h-x,k-y,color);
      putpixel(h+x,k-y,color);
  teta+=0.001;
  }
 }



 void e_arco(int h,int k,int rad_x,int rad_y,float ang_ini,float ang_fin,int color)
  {
  int x=0,y=0;
  float aux=0;
  if(ang_ini>ang_fin)
    {
    aux=ang_ini;
    ang_ini=ang_fin;
    ang_fin=aux;
    }

 while(ang_ini<ang_fin)
 {
  x=rad_x*cos(ang_ini);
  y=rad_y*sin(ang_ini);

    putpixel(h+x,k-y,color);
    ang_ini+=0.001;
  }
 }






