#include<stdio.h>
#include<conio.h>
#include<iostream.h>
char opc;
int a[3][3],b[3][3],c[3][3],i,j,cont;
void primero();
void segundo();
void tercero();
void cuarto();
void main()
{
 while(1)
  {
  clrscr();
  gotoxy(15,5);cout<<"______________________________________";
  gotoxy(15,7);cout<<"CORPORACION UNIVERCITARIA DE SANCANDER";
  gotoxy(17,9);cout<<"FACULTAD DE INGENIERIA DE SISTEMAS";
  gotoxy(29,11);cout<<"CURSO S2E";
  gotoxy(15,13);cout<<"_____________________________________";
  gotoxy(29,15);cout<<"1.PRIMERO";
  gotoxy(29,16);cout<<"2.SEGUNDO";
  gotoxy(29,17);cout<<"3.TERCERO";
  gotoxy(29,18);cout<<"4.CUARTO";
  gotoxy(29,19);cout<<"5.CUARTO";
  gotoxy(24,23);cout<<"DIGITE LA OPCION [ ]";
  gotoxy(15,20);cout<<"______________________________________";
  gotoxy(20,43);opc=getchar();
  switch(opc)
   {
   case'1':clrscr();primero();break;
   case'2':clrscr();segundo();break;
   case'3':clrscr();tercero();break;
   case'4':clrscr();cuarto();break;
   case'5':return;
   }
  }
}
void primero()
 {
 clrscr();
 int i,j,m[5][5];
 for(i=0;i<=4;i++){
  for(j=0;j<=4;j++){
  if(i==j)
     {
     m[i][j]=1;
     }
     else
     m[i][j]=0;
     }
   }
    
   cout<<"\t";
   cout<<"\n";
  
  for(i=0;i<=4;i++){
  for(j=0;j<=4;j++)
 
 cout<<"\t"<<m[i][j];
   cout<<"\t";
   cout<<"\n";
	}
  
 getch();

 }
void segundo()
{
clrscr();
gotoxy(5,2);cout<<"  digite los datos para la matriz A ";
for(i=0;i<=2;i++)
      {
      for(j=0;j<=2;j++)
      {
      gotoxy(j*4+3,i+5);
      cin>>a[i][j];
      gotoxy(j*3+4,i+5);
     }
   }
/********************************************************************/
gotoxy(15,10);cout<<"  digite los datos para la matriz B ***";
for(i=0;i<=2;i++)
      {
      for(j=0;j<=2;j++)
      {

       gotoxy(j*4+3,i+15);
       cin>>b[i][j];
      gotoxy(j*3+4,i+15);
     
     }
   }
   getch();
   clrscr();

      for(i=0;i<=2;i++)
	{
	for(j=0;j<=2;j++)
	 { 
	  if(i>=j)
	  {

	   c[i][j]=a[i][j]*b[j][i];
	   }
	   else
	   c[i][j]=0;
       
       }  
       }
   for(i=0;i<=2;i++)
     {
     for(j=0;j<=2;j++)
      
      cout<<"\t"<<c[i][j];
      cout<<"\n";
	
 }
 getch();
 }

void tercero()
{
clrscr();
  int D[3][3],sum,n=3,i,j,C[3][3],A[3][3];
 int k=0,res,d[10],a;
   clrscr();
  cout<<"DIGITE LOS NUMEROS DE LA MATRIZ\n";

  for(i=0;i<n;i++)
   {
   for(j=0;j<n;j++) {
   gotoxy(j*4+3,i+5);
    cin>>a;
    gotoxy(j*3+4,i*5);

   D[i][j]=a;
  }
  }
//********************//********************//********************
  for(i=0;i<3;i++)
    {
     res=0;
    for(j=0;j<3;j++)
      res=res+D[j][i];
      d[i]=res;
      }
    for(i=0;i<3;i++){
       k=k+1;

cout<<"%s %d %s %d\n","La suma de la columnaa es",k,"es",d[i];
cout<<"\n";
  }
//********************//*******************//*****************

for(i=0;i<3;i++)
    {
    res=0;
    for(j=0;j<3;j++)
      res=res+D[i][j];
	d[i]=res;
      }
     for(i=0;i<3;i++){
	 k=k+1;

cout<<"%s %d %s %d\n","La suma de la fila es ",k,"es",d[i];
  }
getche();
}

void cuarto(){clrscr();}
