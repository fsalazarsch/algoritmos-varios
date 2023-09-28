//clave de cuatro pos.
#include<stdio.h>
#include<conio.h>
 int v[4],j[4],i,c,e;
  main()
   {
    j[0]=7;
    j[1]=4;
    j[2]=7;
    j[3]=0;
    
    gotoxy(4,4);
    printf("Digite su clave(4 numeros)\n");     {
     for(i=0;i<=3;i++)
      {
       scanf("%d",&v[i]);
      }
     
     for(i=0;i<=3;i++)
     
       if(v[i]==j[i])
         
	printf("Acceso otorgado\n");
          else
       
	printf("Acceso denegado\n");
	}
	getch();  
        return(0);
	}
