#include <stdio.h>
#include <conio.h>

void MULTIPLI(void);
void ORDENAR(void);
void BUSQUEDA(void);
void UNIR(void);
void PROM(void);
void MAYMEN(void);
void BELEMENT(void);
void SUMDIAGO(void);
void exit(void);
void CARGAR(void);
void menu(void);
void opcion(void);
void INTERS(void);
void CARTRIZ(void);
void BELEMENT(void);
void MENUS(void);
void escoger(void);
void CARUSUA(void);
void COMPARAR(void);

int  opci,col,cont,esco,x,vec1,mayo,meno,vec2,y,obj;
long prom,prome,promed,aux,auxi;
int  opci,inter,posi,pos,nume,i,j,k,l;
long aa[15],bb[15],cc[20],dd[40],matriz[30][30];

main()
	 {
	  clrscr();
	  menu();
	  return(0);
	 }

void ventana(int kk)
		   {
		   int COL;
		   char *titu;
		   switch(kk)
			 {
			  case 0 :titu ="PROGRAMACION ESTRUCTURADA";
					  COL=28;
					  break;
			  case 1 :titu ="CARGAR VECTORES";
					  COL=33;
					  break;
			  case 2 :titu ="MULTIPLICAR VECTORES";
					  COL=30;
					  break;
			  case 3 :titu ="ORDENAR VECTORES";
					  COL=32;
					  break;
			  case 4 :titu ="BUSQUEDA EN LOS VECTORES";
					  COL=28;
					  break;
			  case 5 :titu ="UNION DE LOS DOS VECTORES";
					  COL=28;
					  break;
			  case 6 :titu ="INTERSECTAR VECTORES";
					  COL=30;
					  break;
			  case 7 :titu ="COMPARACION DE LOS VECTORES";
					  COL=27;
					  break;
			  case 8 :titu ="PROMEDIO DE LOS VECTORES";
					  COL=28;
					  break;
			  case 9 :titu ="NUMEROS MAYOR Y MENOR EN LOS VECTORES";
					  COL=22;
					  break;
			  case 10:titu ="CARGA LA MATRIZ ";
					  COL=33;
					  break;
			  case 11:titu ="BUSQUEDA EN LA MATRIZ";
					  COL=29;
					  break;
			  case 12:titu ="SUMA DIAGONAL DE LA MATRIZ";
					  COL=23;
					  break;
			  case 13:titu ="CARGAR LA MATRIZ POR TECLADO";
					  COL=22;
					  break;
			  case 14:titu ="MENU PARA CARGAR LA MATRIZ";
					  COL=23;
					  break;
			  default:        break;
		      }
     window(1,1,80,25);
     textbackground(2);
     clrscr();
     gotoxy(COL,1);
     printf(titu);
     window(2,2,79,24);
     textbackground(3);
     clrscr();
	     }
void CARGAR()
	     {
	      ventana(1);
	      for(k=1;k<16;k++)
		 {
		  aa[k]=0;
		  bb[k]=0;
		 }
		 for(k=1;k<19;k++)
		  cc[k]=0;
		    for(k=1;k<38;k++)
			dd[k]=0;
		 gotoxy(17,10);
		 printf("DIGITE EL NUMERO DE DATOS DEL PRIMER VECTOR:");
		 gotoxy(87,10);
		 scanf("%d",&vec1);
		 gotoxy(17,13);
		 printf("DIGITE EL NUMERO DE DATOS DEL SEGUNDO VECTOR:");
		 gotoxy(86,13);
		 scanf("%d",&vec2);
		   clrscr();
		   col=8;
		   cont=1;
		   gotoxy(13,5);
		   printf("VECTOR NUMERO 1");
		   for (k=1;k<=vec1;k++)
		       {
			gotoxy(10,col);
			printf ("DIGITE NUMERO     :");
			gotoxy(25,col);printf ("%d",cont++);
			gotoxy(30,col);scanf("%ld",&aa[k]);
			col++;
		       }
		       col=8;
		       cont=1;
		       gotoxy(49,5);
		       printf("VECTOR NUMERO 2");
		       for (k=1;k<=vec2;k++)
			   {
			   gotoxy(47,col);
			   printf("DIGITE NUMERO     :");
			   gotoxy(62,col);
			   printf("%d",cont++);
			   gotoxy(67,col);
			   scanf("%ld",&bb[k]);
			   col++;
			   }
		}
void MULTIPLI()
	       {
		 long multi;
		 col=7;
		 nume=1;
		 ventana(2);
		 if(vec1<=vec2)
		    obj=vec2;
		    else
		    obj=vec1;
			for(k=1;k<=obj;k++)
			   {
			    multi=aa[k]*bb[k];
			    gotoxy(12,col);
			    printf("LA MULTIPLICACION DEL     NUMERO DE LOS VECTORES ES:");
			    gotoxy(34,col);
			    printf("%d",nume++);
			    gotoxy(65,col++);
			    printf("%ld",multi);
			   }
			getch();
		      }

void ORDENAR()
	      {
		col=8;j=1;
		ventana(3);
		i=vec1;
		while(i>=j)
		     {
		       k=vec1;
		       while(k>j)
			    {
			     if(aa[k]<aa[k-1])
			       {
				aux=aa[k-1];
				aa[k-1]=aa[k];
				aa[k]=aux;
			       }
			     k--;
			    }
			  j++;
		      }
		     k=1;
		     i=vec2;
		     while(i>=k)
			  {
			  j=vec2;
			  while(j>k)
			       {
				if(bb[j]<bb[j-1])
				  {
				   auxi=bb[j-1];
				   bb[j-1]=bb[j];
				   bb[j]=auxi;
				  }
			       j--;
			       }
			    k++;
			  }
		   for(k=1;k<=vec1;k++)
		   {
		    gotoxy(10,6);
		    printf("PRIMER VECTOR ORDENADO");
		    gotoxy(20,col++);
		    printf("%ld",aa[k]);
		   }
		   col=8;
		   for(k=1;k<=vec2;k++)
		   {
		    gotoxy(40,6);printf("SEGUNDO VECTOR ORDENADO");
		    gotoxy(50,col++);printf("%ld",bb[k]);
		   }
		 getch();
	       }
void BUSQUEDA()
	       {
		  int si1,si2,mov;
		  ventana(4);
                  gotoxy(19,7);
		  printf ("DIGITE EL NUMERO A BUSCAR EN LOS VECTORES");
		  gotoxy(34,9); printf("ÉÍÍÍÍÍ»");
		  gotoxy(34,10);printf("º     º");
		  gotoxy(34,11);printf("ÈÍÍÍÍÍ¼");
		  gotoxy(36,10);
		  scanf("%d",&nume);
		  clrscr();
		  mov = 8;
		  si1 = 0;
		  si2 = 0;
		    for(k=1;k<=vec1;k++)
		       {
			if (aa[k]==nume)
			   {
			    posi=k;
			    gotoxy(10,mov);
			    printf("EL NUMERO SE ENCUENTRA EN LA POSICION No       DEL VECTOR 1");
			    gotoxy(51,mov++);
			    printf("%d",posi);
			    si1 = si1+1;
			   }
		       }
		    for(k=1;k<=vec2;k++)
		       {
			if (bb[k]==nume)
			   {
			    pos=k;
			    gotoxy(10,mov);
			    printf("EL NUMERO SE ENCUENTRA EN LA POSICION No       DEL VECTOR 2");
			    gotoxy(51,mov++);
			    printf("%d",pos);
			    si2=si2+1;
			   }
		       }
		       if (si1 == 0)
			  if (si2 == 0)
			     {
			      gotoxy(15,10);
			      printf("EL NUMERO A BUSCAR NO SE ENCUENTRA EN LOS VECTORES");
			     }
		  getch();
	   }
void UNIR()
	       {
		  int COL;
		  ventana(5);
		  COL=2;
		  for(k=1;k<=vec1;k++)
		      {
		      gotoxy(37,COL++);
		      printf("%ld",aa[k]);
		      }
		      for(k=1;k<=vec2;k++)
			 {
			 gotoxy(37,COL++);
			 printf("%ld",bb[k]);
			 }
	       getch();
	     }
void INTERS()
	     {
	      int si,con,mayo,meno;
	      clrscr();
	      si=5;
	      con=0;
	      ventana(6);
	      if(vec1<=vec2)
		{
		 mayo=vec2;
		 meno=vec1;
		}
		 else
		{
		 mayo=vec1;
		 meno=vec2;
		}
		for(j=1;j<=mayo;j++)
		   {
		    for(k=1;k<=meno;k++)
		       {
			if(aa[j]==bb[k])
			  {
			   cc[i]=aa[j];
			   gotoxy(15,si);
			   printf("EL NUMERO DE INTERSECCION DEL VECTOR ES:  ");
			   gotoxy(55,si++);
			   printf("%ld",cc[i]);
			   con=con+1;
			   }
		       }
			if(con==0)
			  {
			   gotoxy(15,10);
			   printf("LOS VECTORES NO TIENEN NUMERO DE INTERSECCION");
			  }
		    }
		getch();
	      }
void MAYMEN()
	      {
		long may,men,ma,me;
		long mayor,menor;
		col=5;j=1;
		ventana(9);
		may=aa[1];
		men=aa[1];
		for(k=1;k<=vec1;k++)
		   {
		   if(may<aa[k])
		      may=aa[k];
		      else if(men>aa[k])
			      men=aa[k];
		   }
		ma=bb[1];
		me=bb[1];
		for(k=1;k<=vec2;k++)
		   {
		   if(ma<bb[k])
		      ma=bb[k];
		      else if(me>bb[k])
			      me=bb[k];
		   }
		if(may>ma)
		   mayor=may;
		   else mayor=ma;
		if(men<me)
		   menor=men;
		   else menor=me;
	 gotoxy(10,6);
	 printf(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               