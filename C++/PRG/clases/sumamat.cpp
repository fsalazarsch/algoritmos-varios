# include <stdio.h>
# include <conio.h>

main()
{
 //Este programa realiza sumatroria de una matriz (De filas y de Columnas)
 // sumama.cpp

 
 int matriz[10][10],x,j,n,i,va[10],vb[10];
  

 /*Cargo la matriz*/
 clrscr();
 printf("\n\n **** ESTE PROGRAMA REALIZA LA SUMATORIA DE LOS ELEMENTOS ****\n");
 printf("         ****  DE UNA MATRIZ INGRESADA POR TECLADO ****\n\n\n");
 printf("    DIGITE EL TAMANO DE LA MATRIZ--->");
 scanf("%d",&n);
 printf("\n DIGITE LOS VALORES :\n");
 for(x=0;x<n;x++)
   {
     for(j=0;j<n;j++)
      {
       gotoxy(5*(j+1),(x+6)*2);
       scanf("%d",&matriz[x][j]);
       }
   }

 /* Sumo las filas*/
 printf("\n LA SUMATORIA DE FILAS ES   :");
  //inicializo el vector en cero
 for(x=0;x<n;x++)
   {
    for(j=0;j<n;j++)
       {
	va[x]=0;
       }
   }
 for(x=0;x<n;x++)
  {
  for(j=0;j<n;j++)
     {
         va[x]=va[x]+matriz[x][j];
     }
  printf("%d  ",va[x]);
  }



 /*Sumo las columnas*/
 printf("\n LA SUMATORIA DE COLUMNAS ES: ");
 //inicializo el vector en cero
 for(j=0;j<n;j++)
   {
    for(x=0;x<n;x++)
       {
        vb[j]=0;
       }
   }
 for(j=0;j<n;j++)
   {
   for(x=0;x<n;x++)
       {
        vb[j]=vb[j]+matriz[x][j];
       }
     printf("%d  ",vb[j]);
    }
}