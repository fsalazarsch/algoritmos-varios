//********************MATRIZ*************************


   # include <iostream.h>
   # include <conio.h>
   # include <iomanip.h>
   # include <dos.h>          
   main()
   {
     int k,j,f=17,c;
     int mat[100][100];
     long mat_res[100][100];
     clrscr();
     gotoxy(26,5);cout<<"digite tama¤o de la matriz [__]";gotoxy(54,5);cin>>c;
     gotoxy(26,9);cout<<"ASIGNAR VALORES A LA MATRIZ";
     for(k=0;k<c;k++)
      {
      for(j=0;j<c;j++)
       {
	gotoxy(10,15);cout<<"introduzca un valor entero  [     ]"<<" fila "<< k <<" columna " << j;
	gotoxy(39,15);cin>>mat[k][j]; 
       }
      }
      gotoxy(26,16);cout<<"traspuesta de la matriz";
     for(k=0;k<c;k++)
     {
      gotoxy(25,f);
      for(j=0;j<c;j++)
      {
       mat_res[k][j]=mat[j][k]; 
     cout<<setw(5)<<mat_res[k][j]<<"  ";
       getch(); 
      }
     f++;
    }
  }

