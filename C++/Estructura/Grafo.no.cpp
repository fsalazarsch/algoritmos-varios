#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

 struct arch_nodo
 {
 char ciudad[20];
 };

 struct arch_arista
 {
 char origen[20];
 char destino[20];
 int distancia;
 };

 struct nodo 
 {
 char ciudad[20];
 struct nodo *sig;
 struct arco *ady;
 };

 struct arco
 {
  int info;
  struct arco *sig;
  struct nodo *dest;
 };

 struct nodo *mul;
 struct arch_nodo dato,auxdato;
 struct arch_arista arista,auxarista;
 int dno,dar,i,j,st,sw,lon,auxdno,auxdar;
 char ciudad[20],origen[20],destino[20],valido,op;



//*****************************************************************************
 crear_archivo_nodo()
   {
    char control1;
    int aux;
    
      clrscr();
	control1='S';

     	  if ((dno=_open("a:\\ciudad.dat",1))!=-1)
	    {
	    gotoxy(2,5);printf("CUIDADO ESTE ARCHIVO YA EXISTE");
	    gotoxy(2,7);printf("DESEA BORRARLO (S/N) ");
	    control1=toupper(getch());
	    }  
	   else
	    {
	      if ((dno=_creat("a:\\ciudad.dat",0))==-1)
	       {
		printf(" ERROR AL INTENTAR CREAR ARCHIVO CIUDAD...");
		getch();exit(1);
	       }
	    } 

	 if(control1!='N')
	   {
	    if ((dno=_creat("a:\\ciudad.dat",0))==-1)
	     {
	      perror("_creat");
	      printf(" ERROR AL INTENTAR CREAR ARCHIVO CIUDAD...");
	      getch();exit(1);
	     }
	   adicionar_archivo_nodo(); 
	   }
	  return(0);
    }

//*********************************************************************************

 adicionar_archivo_nodo()
  { 
    char continuar,control;
    int aux;

     clrscr();

   do
     {
	do
	{
	 clrscr();
	 valido='n';
	 gotoxy(29,7);
	 printf("               ");
	 gotoxy(2,7);printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciudad);strupr(ciudad);
	 lon = strlen(ciudad);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(ciudad[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR NOMBRE !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

       if ((dno=_open("a:\\ciudad.dat",4))==-1)
	 { 
	  clrscr();
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD... ");
	  getch();exit(1);
	 }

       control='N';
       while(((aux=_read(dno,&dato,sizeof(dato)))!=0)&&(control=='N'))
	 {
	   if (aux!=sizeof(dato))
	      {
	       printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
	       getch();exit(1);
	      }
		      
	   if (strcmp(dato.ciudad,ciudad)==0)
	       control='S';
	 }
       if (control=='S')
	   printf("\nESTA CIUDAD YA EXISTE ...");
       else
	  {
	   strcpy(dato.ciudad,ciudad);
	   if ((aux=_write(dno,&dato,sizeof(dato)))!=(sizeof(dato)))
	      {
	       printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
	       getch();exit(1);
	      }
	  }
	close(dno);
	printf("\nDESEA ADICIONAR MAS CIUDADES ...(S/N) ");
	continuar=toupper(getch());
      }while(continuar!='N');

   return(0);
 }


//********************************************************************************************
adicionar_grafo_nodo()
  { 
    char continuar,control;
    int aux;

     clrscr();

   do
     {
	do
	{
	 clrscr();
	 valido='n';
	 gotoxy(29,7);
	 printf("               ");
	 gotoxy(2,7);printf("DIGITE NOMBRE DE LA CIUDAD:");
	 scanf("\n"); gets(ciudad);strupr(ciudad);
	 lon = strlen(ciudad);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(ciudad[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR NOMBRE !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

       if ((dno=_open("a:\\ciudad.dat",4))==-1)
	 { 
	  clrscr();
	  printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD... ");
	  getch();exit(1);
	 }

       control='N';
       while(((aux=_read(dno,&dato,sizeof(dato)))!=0)&&(control=='N'))
	 {
	   if (aux!=sizeof(dato))
	      {
	       printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
	       getch();exit(1);
	      }
		      
	   if (strcmp(dato.ciudad,ciudad)==0)
	       control='S';
	 }
       if (control=='S')
	   printf("\nESTA CIUDAD YA EXISTE ...");
       else
	  {
	   strcpy(dato.ciudad,ciudad);
	   if ((aux=_write(dno,&dato,sizeof(dato)))!=(sizeof(dato)))
	      {
	       printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
	       getch();exit(1);
	      }
	  }
	close(dno);
	printf("\nDESEA ADICIONAR MAS CIUDADES ...(S/N) ");
	continuar=toupper(getch());
      }while(continuar!='N');

   return(0);
 }


//********************************************************************************************


 crear_archivo_arista()
  {
   char control1;
   int aux;

   clrscr();
   control1='S';
    if ((dar=_open("a:\\arcos.dat",1))!=-1)
       {
       gotoxy(2,5);printf("CUIDADO ESTE ARCHIVO YA EXISTE");
       gotoxy(2,7);printf("DESEA BORRARLO (S/N) ");
       control1=toupper(getch());
       }
    else
      { 
       if ((dar=_creat("a:\\arcos.dat",0))==-1)
	      { printf(" ERROR AL INTENTAR CREAR ARCHIVO ARCOS...");
	       getch();exit(1);
	      }
	    }  

	   if(control1!='N')
	    {
	     if ((dar=_creat("a:\\arcos.dat",0))==-1)
	      { printf(" ERROR AL INTENTAR CREAR ARCHIVO ARCOS...");
	       getch();exit(1);
	      }
	     adicionar_archivo_arista();
	    }
    return(0);

  }


//*********************************************************************************

 adicionar_archivo_arista()
  {
   char auxor,auxdes,control,continuar;
   int aux,costo;

	do
	{ clrscr();
	  do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	  if ((dar=_open("a:\\arcos.dat",4))==-1)
	   {gotoxy(2,5);printf("ERROR AL INTENTAR ABRIR ARCHIVO ARCOS");
	    getch();exit(1);
	   } 
	   
	   control='F';
	   
	     while(((aux=_read(dar,&arista,sizeof(arista)))!=0)&&(control=='F'))
	       {  if (aux!=sizeof(arista))
		   { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS ..."); 
		     getch();exit(1);
		    }
		      
		   if ((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		     control='V';
	       
		   if ((strcmp(arista.origen,destino)==0)&&(strcmp(arista.destino,origen)==0))
		     control='V';
	   
	       }
	   
	      if (control=='V')
		printf("\n...ESTA RUTA YA EXISTE ...");
		else
		  { auxor='F'; auxdes='F';
		     if((dno=_open("a:\\ciudad.dat",1))==-1)
		       { clrscr();
			 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
			 getch();exit(1);
		       }

		      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
			{ if (aux!=sizeof(dato))
			   { printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD...");
			     getch();exit(1);
			   }

			  if (strcmp(dato.ciudad,origen)==0)
			    auxor='V';
			  if (strcmp(dato.ciudad,destino)==0)
			   auxdes='V';
			}

			if(auxor=='F')
			  printf("\nCIUDAD ORIGEN NO EXISTE...");
			  else
			   { if(auxdes=='F')
			       printf("\nCIUDAD DESTINO NO EXISTE...");
			       else
				{ printf("DIGITE SU COSTO : ");scanf("%d",&costo);
				  strcpy(arista.origen,origen);
				  strcpy(arista.destino,destino);
				  arista.distancia=costo;

				    if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				     { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				       getch();exit(1);
				     }

				  strcpy(arista.origen,destino);
				  strcpy(arista.destino,origen);
				  arista.distancia=costo;

				    if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				     { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				       getch();exit(1);
				     }

				}

			   }
		   close(dno);
		  }
	      close(dar);
	  printf("\nDESEA ADICIONAR OTRA RUTA (S/N) ");
	  continuar=toupper(getch());
	} while(continuar!='N');
   return(0);
 }


//*******************************************************************************

 adicionar_grafo_arista()
  {
   char auxor,auxdes,control,continuar;
   int aux,costo;

	do
	{ clrscr();
	  do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	  if ((dar=_open("a:\\arcos.dat",4))==-1)
	   {gotoxy(2,5);printf("ERROR AL INTENTAR ABRIR ARCHIVO ARCOS");
	    getch();exit(1);
	   } 
	   
	   control='F';
	   
	     while(((aux=_read(dar,&arista,sizeof(arista)))!=0)&&(control=='F'))
	       {  if (aux!=sizeof(arista))
		   { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS ..."); 
		     getch();exit(1);
		    }
		      
		   if ((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		     control='V';
	       
		   if ((strcmp(arista.origen,destino)==0)&&(strcmp(arista.destino,origen)==0))
		     control='V';
	   
	       }
	   
	      if (control=='V')
		printf("\n...ESTA RUTA YA EXISTE ...");
		else
		  { auxor='F'; auxdes='F';
		     if((dno=_open("a:\\ciudad.dat",1))==-1)
		       { clrscr();
			 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
			 getch();exit(1);
		       }

		      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
			{ if (aux!=sizeof(dato))
			   { printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD...");
			     getch();exit(1);
			   }

			  if (strcmp(dato.ciudad,origen)==0)
			    auxor='V';
			  if (strcmp(dato.ciudad,destino)==0)
			   auxdes='V';
			}

			if(auxor=='F')
			  printf("\nCIUDAD ORIGEN NO EXISTE...");
			  else
			   { if(auxdes=='F')
			       printf("\nCIUDAD DESTINO NO EXISTE...");
			       else
				{ printf("DIGITE SU COSTO : ");scanf("%d",&costo);
				  strcpy(arista.origen,origen);
				  strcpy(arista.destino,destino);
				  arista.distancia=costo;

				    if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				     { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				       getch();exit(1);
				     }

				  strcpy(arista.origen,destino);
				  strcpy(arista.destino,origen);
				  arista.distancia=costo;

				    if ((aux=_write(dar,&arista,sizeof(arista)))!=(sizeof(arista)))
				     { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO ARCOS...");
				       getch();exit(1);
				     }

				}

			   }
		   close(dno);
		  }
	      close(dar);
	  printf("\nDESEA ADICIONAR OTRA RUTA (S/N) ");
	  continuar=toupper(getch());
	} while(continuar!='N');
   return(0);
 }


//*******************************************************************************
 borrar_archivo_nodo()
  {
   int aux;
   char segir,control;

   do
    {
     clrscr();
      do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(25,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD A BORRAR:");
	  scanf("\n"); gets(ciudad);strupr(ciudad);
	  lon = strlen(ciudad);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(ciudad[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');

     if((dno=_open("a:\\ciudad.dat",1))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	 getch();exit(1);
       }

     if((auxdno=_creat("a:\\auxciud.dat",0))==-1)
       { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR DE CIUDAD...");
	 getch();exit(1);
       }

     if((auxdno=_open("a:\\auxciud.dat",2))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR CIUDAD ");
	 getch();exit(1);
       }
     control='N';
	    while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
	     { if (aux!=sizeof(dato))
		 { printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
		   getch();exit(1);
		 }

		if (strcmp(dato.ciudad,ciudad)!=0)
		  { strcpy(auxdato.ciudad,dato.ciudad);
		     if ((aux=_write(auxdno,&auxdato,sizeof(auxdato)))!=(sizeof(auxdato)))
		      {  printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
			 getch();exit(1);
		      }
		    control='S';
		  }
	     }
	  close(dno);
	  close(auxdno);
	  unlink("a:\\ciudad.dat");
	  rename("a:\\auxciud.dat","a:\\ciudad.dat");

	  if(control=='N')
	   printf("CIUDAD A BORRAR NO EXISTIA EN ARCHIVO CIUDAD ");
	    else
	     { 
	       if((dar=_open("a:\\arcos.dat",1))==-1)
		 { clrscr();
		   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
		   getch();exit(1);
		 }

	       if ((auxdar=_creat("a:\\auxarco.dat",0))==-1)
		 { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
		   getch();exit(1);
		 }


	       if((auxdar=_open("a:\\auxarco.dat",2))==-1)
		 { clrscr();
		   printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR ARCOS ");
		   getch();exit(1);
		 }
		  while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
		    { if (aux!=sizeof(arista))
		       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
			 getch();exit(1);
		       }

		       if ((strcmp(arista.origen,ciudad)!=0)&&(strcmp(arista.destino,ciudad)!=0))
			{ auxarista=arista;
			  if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			    { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			      getch();exit(1);
			    }
			}

		    }

		 close(dar);
		 close(auxdar);
		 unlink("a:\\arcos.dat");
		 rename("a:\\auxarco.dat","a:\\arcos.dat");
	     }
	  printf("\nDESEA CONTINUAR (S/N) ");
	  segir=toupper(getch());
	} while(segir!='N');
    return(0);
  }


//****************************************************************************************   

borrar_grafo_nodo()
  {
   int aux;
   char segir,control;

   do
    {
     clrscr();
      do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(25,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD A BORRAR:");
	  scanf("\n"); gets(ciudad);strupr(ciudad);
	  lon = strlen(ciudad);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(ciudad[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');

     if((dno=_open("a:\\ciudad.dat",1))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	 getch();exit(1);
       }

     if((auxdno=_creat("a:\\auxciud.dat",0))==-1)
       { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR DE CIUDAD...");
	 getch();exit(1);
       }

     if((auxdno=_open("a:\\auxciud.dat",2))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR CIUDAD ");
	 getch();exit(1);
       }
     control='N';
	    while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
	     { if (aux!=sizeof(dato))
		 { printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
		   getch();exit(1);
		 }

		if (strcmp(dato.ciudad,ciudad)!=0)
		  { strcpy(auxdato.ciudad,dato.ciudad);
		     if ((aux=_write(auxdno,&auxdato,sizeof(auxdato)))!=(sizeof(auxdato)))
		      {  printf("ERROR AL INTENTAR GRABAR EN ARCHIVO CIUDAD...");
			 getch();exit(1);
		      }
		    control='S';
		  }
	     }
	  close(dno);
	  close(auxdno);
	  unlink("a:\\ciudad.dat");
	  rename("a:\\auxciud.dat","a:\\ciudad.dat");

	  if(control=='N')
	   printf("CIUDAD A BORRAR NO EXISTIA EN ARCHIVO CIUDAD ");
	    else
	     { 
	       if((dar=_open("a:\\arcos.dat",1))==-1)
		 { clrscr();
		   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
		   getch();exit(1);
		 }

	       if ((auxdar=_creat("a:\\auxarco.dat",0))==-1)
		 { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
		   getch();exit(1);
		 }


	       if((auxdar=_open("a:\\auxarco.dat",2))==-1)
		 { clrscr();
		   printf("ERROR AL INTENTAR CREAR EL ARCHIVO AUXILIAR ARCOS ");
		   getch();exit(1);
		 }
		  while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
		    { if (aux!=sizeof(arista))
		       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
			 getch();exit(1);
		       }

		       if ((strcmp(arista.origen,ciudad)!=0)&&(strcmp(arista.destino,ciudad)!=0))
			{ auxarista=arista;
			  if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			    { printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			      getch();exit(1);
			    }
			}

		    }

		 close(dar);
		 close(auxdar);
		 unlink("a:\\arcos.dat");
		 rename("a:\\auxarco.dat","a:\\arcos.dat");
	     }
	  printf("\nDESEA CONTINUAR (S/N) ");
	  segir=toupper(getch());
	} while(segir!='N');
    return(0);
  }


//****************************************************************************************   


 borrar_archivo_arista()
   {
    int aux; 
    char segir;

     do
     {
     clrscr();

       do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

       if((dar=_open("a:\\arcos.dat",1))==-1)
	 { clrscr();
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	   getch();exit(1);
	 }

       if ((auxdar=_creat("a:\\auxarco.dat",0))==-1)
	 { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
	   getch();exit(1);
	 }

       if((auxdar=_open("a:\\auxarco.dat",2))==-1)
	 { clrscr();
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO AUXILIAR ARCOS ");
	   getch();exit(1);
	 }
	
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   { if (aux!=sizeof(arista))
	       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
		}

	      if ((strcmp(arista.origen,origen)!=0)||(strcmp(arista.destino,destino)!=0))
	       {  if ((strcmp(arista.origen,destino)!=0)||(strcmp(arista.destino,origen)!=0))
		   { auxarista=arista;
		      if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			{ printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			  getch();exit(1);
			}
		   }

	       }	

	   }

	   close(dar);
	   close(auxdar);
	   unlink("a:\\arcos.dat");
	   rename("a:\\auxarco.dat","a:\\arcos.dat");
	   printf("\nDESEA CONTINUAR (S/N) ");
	  segir=toupper(getch());
	} while(segir!='N');
   return(0);
   }

//*************************************************************************************
 borrar_grafo_arista()
   {
    int aux; 
    char segir;

     do
     {
     clrscr();

       do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

       if((dar=_open("a:\\arcos.dat",1))==-1)
	 { clrscr();
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	   getch();exit(1);
	 }

       if ((auxdar=_creat("a:\\auxarco.dat",0))==-1)
	 { printf(" ERROR AL INTENTAR CREAR ARCHIVO AUXILIAR ARCOS...");
	   getch();exit(1);
	 }

       if((auxdar=_open("a:\\auxarco.dat",2))==-1)
	 { clrscr();
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO AUXILIAR ARCOS ");
	   getch();exit(1);
	 }
	
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   { if (aux!=sizeof(arista))
	       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
		}

	      if ((strcmp(arista.origen,origen)!=0)||(strcmp(arista.destino,destino)!=0))
	       {  if ((strcmp(arista.origen,destino)!=0)||(strcmp(arista.destino,origen)!=0))
		   { auxarista=arista;
		      if ((aux=_write(auxdar,&auxarista,sizeof(auxarista)))!=(sizeof(auxarista)))
			{ printf("ERROR AL INTENTAR GRABAR EN ARCHIVO AUXILIAR DE ARCOS ...");
			  getch();exit(1);
			}
		   }

	       }	

	   }

	   close(dar);
	   close(auxdar);
	   unlink("a:\\arcos.dat");
	   rename("a:\\auxarco.dat","a:\\arcos.dat");
	   printf("\nDESEA CONTINUAR (S/N) ");
	  segir=toupper(getch());
	} while(segir!='N');
   return(0);
   }

//*************************************************************************************


  imprimir_archivo_nodo()
   {
    int aux;

   clrscr();
     if((dno=_open("a:\\ciudad.dat",1))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	 getch();exit(1);
       }


      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
       { if (aux!=sizeof(dato))
	  { printf(" ERROR DE LECTURA EN ARCHIVO ciudad ..."); 
	    getch();exit(1);
	  }

	  printf("%s\n",dato.ciudad);
       }

  getch();
  close(dno);
  return(0);
  } 

//*******************************************************************************
 imprimir_grafo_nodo()
   {
    int aux;

   clrscr();
     if((dno=_open("a:\\ciudad.dat",1))==-1)
       { clrscr();
	 printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD ");
	 getch();exit(1);
       }


      while ((aux=_read(dno,&dato,sizeof(dato)))!=0)
       { if (aux!=sizeof(dato))
	  { printf(" ERROR DE LECTURA EN ARCHIVO ciudad ..."); 
	    getch();exit(1);
	  }

	  printf("%s\n",dato.ciudad);
       }

  getch();
  close(dno);
  return(0);
  } 

//*******************************************************************************

 imprimir_archivo_arista()
  {
   int aux;
    clrscr();

    if((dar=_open("a:\\arcos.dat",1))==-1)
      { clrscr();
	printf("ERROR AL INTENTAR LEER EL ARCHIVO  ARCOS ");
	getch();exit(1);
      }
	
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   { if (aux!=sizeof(arista))
	       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
		}
	    printf("ORIGEN : %s DESTINO : %s COSTO : %d \n",arista.origen,arista.destino,arista.distancia );
	   }
	   getch();
     close(dar);
   return(0);
 }


//******************************************************************************
 imprimir_grafo_arista()
  {
   int aux;
    clrscr();

    if((dar=_open("a:\\arcos.dat",1))==-1)
      { clrscr();
	printf("ERROR AL INTENTAR LEER EL ARCHIVO  ARCOS ");
	getch();exit(1);
      }
	
	 while ((aux=_read(dar,&arista,sizeof(arista)))!=0)
	   { if (aux!=sizeof(arista))
	       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
		}
	    printf("ORIGEN : %s DESTINO : %s COSTO : %d \n",arista.origen,arista.destino,arista.distancia );
	   }
	   getch();
     close(dar);
   return(0);
 }


//******************************************************************************

cuadros(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(12);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("Í");
       gotoxy(j,y2);cprintf("Í");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("º");
       gotoxy(x2,i);cprintf("º");
       }
     gotoxy(x1,y1);cprintf("É");
     gotoxy(x2,y1);cprintf("»");
     gotoxy(x1,y2);cprintf("È");
     gotoxy(x2,y2);cprintf("¼");
   return(0);
}

menu()
{ int tecla;
  int f;
  char opciones[35][75];
  textcolor(10);textbackground(1);

  do{ 
  clrscr();                                        
  strcpy(opciones[10], " CREAR ARCHIVOS    ");
  strcpy(opciones[11], " CONSULTAR DATOS   ");
  strcpy(opciones[12], " ADICIONAR DATOS   ");
  strcpy(opciones[13], " IMPRIMIR INFORME  ");
  strcpy(opciones[15], " ELIMINAR DATOS    ");
  strcpy(opciones[14], " MODIFICAR DATOS   ");
  strcpy(opciones[16], " RECORRER EL GRAFO ");
  strcpy(opciones[17], " TERMINAR O SALIR  ");

  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");								
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,18);
	textcolor(10);textbackground(1);
	for(f=10;f<=17;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=17)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=17;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   10:menu1() ;break;
		      case   11:menu2() ;break;
		      case   12:menu3() ;break;
		      case   13:menu4() ;break;
		      case   14:menu5() ;break;
		      case   15:menu6() ;break;
		      case   16:break;
		     }
	   }while(f !=17);
	return(0);
  }

//****************************************************************************

menu1()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10], " CREAR ARCHIVO NODOS   ");
  strcpy(opciones[11], " CREAR ARCHIVO ARISTAS ");
  strcpy(opciones[12], "   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,13);
	textcolor(10);textbackground(1);
	for(f=10;f<=12;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=12)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=12;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:crear_archivo_nodo() ;break;
		      case    11:crear_archivo_arista() ;break;
		     }
	   }while(f !=12);
	return(0);
  }


consulta_nodo()
   {
    char segir,encontro;
    int x;
     do{
       clrscr();
	gotoxy(4,7);printf("DIGITE NOMBRE CIUDAD A CONSULTAR:");
	scanf("\n");gets(ciudad);strupr(ciudad);
	if((dno=_open("a:\\ciudad.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(dno,&dato,sizeof(dato)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(dato))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if(strcmp(dato.ciudad,ciudad)==0)
		   {encontro='s';
		   clrscr();
		   printf("%s\n",dato.ciudad);
		  }
	      }
	   if(encontro=='n')
	    {
	      gotoxy(11,9);printf("NO EXISTE CIUDAD A CONSULTAR");
	      getch();
	     }
	     close(dno);
	     gotoxy(16,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getch());
	     }while(segir=='S');
      return(0);	     
     }
//*****************************************************************************
consgra_nodo()
   {
    char segir,encontro;
    int x;
     do{
       clrscr();
	gotoxy(4,7);printf("DIGITE NOMBRE CIUDAD A CONSULTAR:");
	scanf("\n");gets(ciudad);strupr(ciudad);
	if((dno=_open("a:\\ciudad.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(dno,&dato,sizeof(dato)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(dato))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if(strcmp(dato.ciudad,ciudad)==0)
		   {encontro='s';
		   clrscr();
		   printf("%s\n",dato.ciudad);
		  }
	      }
	   if(encontro=='n')
	    {
	      gotoxy(11,9);printf("NO EXISTE CIUDAD A CONSULTAR");
	      getch();
	     }
	     close(dno);
	     gotoxy(16,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getch());
	     }while(segir=='S');
      return(0);	     
     }
//*****************************************************************************

consulta_arista()
 {
  char encontro,segir;
  int x;
  do{
  clrscr();
	do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	if((dar=_open("a:\\arcos.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(dar,&arista,sizeof(arista)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(arista))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		   {encontro='s';
		   clrscr();
		   printf("ORIGEN : %s DESTINO : %s COSTO : %d \n",arista.origen,arista.destino,arista.distancia );
		  }
	      }
	   if(encontro=='n')
	    {clrscr();
	      gotoxy(11,7);
	      printf("NO EXISTE ESTA RUTA");
	      getch();
	     }
	     close(dar);
	     gotoxy(17,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }

//************************************************************************************
consgra_arista()
 {
  char encontro,segir;
  int x;
  do{
  clrscr();
	do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	if((dar=_open("a:\\arcos.dat",1))==-1)
	  {printf("ERROR DE APERTURA");getch();exit(1);
	   }encontro='n';
	    while(((x=_read(dar,&arista,sizeof(arista)))!=0)&&(encontro=='n'))
	     {if(x!=sizeof(arista))
	       {printf("ERROR DE LECTURA");getch();exit(1);
		}
		 if((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		   {encontro='s';
		   clrscr();
		   printf("ORIGEN : %s DESTINO : %s COSTO : %d \n",arista.origen,arista.destino,arista.distancia );
		  }
	      }
	   if(encontro=='n')
	    {clrscr();
	      gotoxy(11,7);
	      printf("NO EXISTE ESTA RUTA");
	      getch();
	     }
	     close(dar);
	     gotoxy(17,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }

//************************************************************************************

modificar_archivo_arista()
{
 int x,con;
	do
	  {
	  clrscr();
	  valido='n';
	  gotoxy(23,7);
	  printf("               ");
	  gotoxy(2,7);printf("DIGITE CIUDAD ORIGEN:");
	  scanf("\n"); gets(origen);strupr(origen);
	  lon = strlen(origen);
	  for(i=0;i<=lon-1; i++)
	   {
	    if(!(isalpha(origen[i])))
	     {
	      gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	      delay(1500);
	      gotoxy(10,20);
	      clreol();
	      valido='m';
	      break;
	    }
	  }
	 }while(valido=='m');
       do
	{
	 clrscr();
	 valido='n';
	 gotoxy(24,8);
	 printf("               ");
	 gotoxy(2,8);printf("DIGITE CIUDAD DESTINO:");
	 scanf("\n"); gets(destino);strupr(destino);
	 lon = strlen(destino);
	 for(i=0;i<=lon-1; i++)
	  {
	   if(!(isalpha(destino[i])))
	    {
	     gotoxy(10,20);printf("ERROR AL DIGITAR CIUDAD !");
	     delay(1500);
	     gotoxy(10,20);
	     clreol();
	     valido='m';
	     break;
	    }
	  }
	 }while(valido=='m');

	if((dar=_open("a:\\arcos.dat",1))==-1)
	   {
	   printf("ERROR DE APERTURA");getch();exit(1);
	   }
	   encontro='n';  con=0;
	    while(((x=_read(dar,&arista,sizeof(arista)))!=0)&&(encontro=='n'))
	     {
	      if(x!=sizeof(arista))
	       {
		printf("ERROR DE LECTURA");getch();exit(1);
		}  con++;
		 if((strcmp(arista.origen,origen)==0)&&(strcmp(arista.destino,destino)==0))
		   {encontro='s';
		   clrscr();
		   printf("DIGITE COSTO :"); scanf("%d,&arista.distancia );
		   lseek(dar,(long)((con-1)*(sizeof(arista))),0);
		   if((b=_write(dar,&arista,sizeof(arista)))!=sizeof(arista))
		    {
		     clrscr();
		     printf("error al grabar");  getch();exit();
		    }
		  }
	      }

	   if(encontro=='n')
	    {clrscr();
	      gotoxy(11,7);
	      printf("NO EXISTE ESTA RUTA");
	      getch();
	     }
	     close(dar);
	     gotoxy(17,16);printf("DESEA CONSULTAR MAS (S/N)");
	     segir=toupper(getche());
	     }while(segir=='S');
	  return(0);
     }
	 
menu2()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10], " CONSULTAR ARCHIVO NODOS   ");
  strcpy(opciones[11], " CONSULTAR ARCHIVO ARISTAS ");
  strcpy(opciones[12], " CONSULTAR EN GRAFO ARISTAS");
  strcpy(opciones[13], " CONSULTAR EN GRAFO NODOS  ");
  strcpy(opciones[14], "   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,15);
	textcolor(10);textbackground(1);
	for(f=10;f<=14;f++)
	  {
	  gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:consulta_nodo();break;
		      case    12:consulta_arista();break;
		      case    13:consgra_arista();break;
		      case    14:consgra_nodo();break;
		     }
	   }while(f !=12);
	return(0);
  }


//************************************************************************************


menu3()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{ 
  clrscr();                                       
  strcpy(opciones[10]," ADICIONAR ARCHIVO NODOS   ");
  strcpy(opciones[11]," ADICIONAR ARCHIVO ARISTAS ");
  strcpy(opciones[12]," ADICIONAR NODOS AL GRAFO  ");
  strcpy(opciones[13]," ADICIONAR ARISTAS AL GARFO");
  strcpy(opciones[14],"   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,15);
	textcolor(10);textbackground(1);
	for(f=10;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    10:adicionar_archivo_nodo() ;break;
		      case    11:adicionar_archivo_arista() ;break;
		      case    12:adicionar_grafo_arista();break;
		      case    13:adicionar_grafo_nodo();break;
		     }
	   }while(f !=14);
	return(0);
  }


//************************************************************************************




menu4()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{                        
  clrscr();                 
  strcpy(opciones[11]," IMPRIMIR ARCHIVO NODOS   ");
  strcpy(opciones[12]," IMPRIMIR ARCHIVO ARISTAS ");
  strcpy(opciones[13]," IMPRIMIR GRAFO           ");
  strcpy(opciones[14],"   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,10,15);
	textcolor(10);textbackground(1);
	for(f=11;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=11;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=11;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=11)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case    11:imprimir_archivo_nodo() ;break;
		      case    12:imprimir_archivo_arista() ;break;
		      case    13:imprimir(); break;
		     }
	   }while(f !=14);
	return(0);
     }


//******************************************************************************




menu5()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10]," ELIMINAR ARCHIVO NODOS   ");
  strcpy(opciones[11]," ELIMINAR ARCHIVO ARISTAS ");
  strcpy(opciones[12]," ELIMINAR NODOS AL GRAFO  ");
  strcpy(opciones[13]," ELIMINAR ARISTAS AL GARFO");
  strcpy(opciones[14],"   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,15);
	textcolor(10);textbackground(1);
	for(f=10;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   10:borrar_archivo_nodo() ;break;
		      case   11:borrar_archivo_arista() ;break;
		      case   12:borrar_grafo_nodo();break;
		      case   13:borrar_grafo_arista();break;
		     }
	   }while(f !=14);
       return(0);
    }


//*****************************************************************************



menu6()
{ int tecla;
  int f;
  char opciones[27][70];
  textcolor(10);textbackground(1);

  do{
  clrscr();                                         
  strcpy(opciones[10]," MODIFICAR ARCHIVO NODOS   ");
  strcpy(opciones[11]," MODIFICAR ARCHIVO ARISTAS ");
  strcpy(opciones[12]," MODIFICAR NODOS AL GRAFO  ");
  strcpy(opciones[13]," MODIFICAR ARISTAS AL GARFO");
  strcpy(opciones[14],"   SALIR O TERMINAR    ");
  gotoxy(20,4);printf("CORPORACION UNIVERSATARIA DE SANTANDER");
  gotoxy(22,5);printf("FACULTAD DE INGENIERIA DE SISTEMAS");
  gotoxy(32,6);printf("U  D  E  S");
  textcolor(10);textbackground(0);
  gotoxy(25,20);printf("HEYNER ALEXANDER AROCA ARAUJO");
  gotoxy(31,21);printf("CODIGO 95131119");
  gotoxy(35,22);printf("S  5  A");
	textcolor(10);textbackground(1);
	cuadros(2,79,2,24);
	cuadros(22,55,9,15);
	textcolor(10);textbackground(1);
	for(f=10;f<=14;f++)

	 {gotoxy(25,f);cprintf("%s",opciones[f]);}
	  f=10;
	  textcolor(0);textbackground(7);
	  gotoxy(25,f);cprintf("%s",opciones[f]);
	  textcolor(10);textbackground(1);

	  do
	  {
	      do
	      { tecla=getch();} 
	      while((tecla==80)&&(tecla==72)&&(tecla==13));

	    if(tecla==80)
	    { 
	     textcolor(10);textbackground(1);
	     gotoxy(25,f);cprintf("%s",opciones[f]);
	     if (f!=14)
	      {
	      //gotoxy(25,f);clreol();
	      f++;
	      textcolor(0); textbackground(7);
	      gotoxy(25,f);  cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);

	      //gotoxy(25,f);cprintf("%c",putchar(17));
	      }
	      else
	     {
	      f=10;
	      textcolor(0);textbackground(7);
	      gotoxy(25,f);cprintf("%s",opciones[f]);
	      textcolor(10);textbackground(1);
	      }
	     }

	      if(tecla == 72)
	       {  
		textcolor(10);textbackground(1);
		gotoxy(25,f);cprintf("%s",opciones[f]);

		if (f!=10)
		{
		//gotoxy(25,f);clreol();
		f--;
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		//gotoxy(25,f);cprintf("%c",putchar(17));
		textcolor(10);textbackground(1);

		}
		else
		{ 
		f=14;
		//gotoxy(25,f);clreol();
		textcolor(0);textbackground(7);
		gotoxy(25,f); cprintf("%s",opciones[f]);
		textcolor(10);textbackground(1);}
		}
	       } 
	  while(tecla!=13);


		     switch(f)
		     {
		      case   10:break;
		      case   11:break;
		      case   12:break;
		      case   13:break;
		     }
	   }while(f !=14);
	return(0);
     }

//******************************************************************************

  cargar_grafo()
   {
    struct nodo *aux, *nuevo,*aux2,*ayu1,*auxnodo,*auxnodo2;
    struct arco *auxarco,*nuevo1;
    char ciudad[20],origen[20],destino[20];
    int control,aux1,info;
 

    if ((dno=_open("a:\\ciudad.dat",1))==-1)
      { clrscr();
	printf("ERROR AL INTENTAR ABRIR EL ARCHIVO CIUDAD... ");
	getch();exit(1);
      }



   while ((aux1=_read(dno,&dato,sizeof(dato)))!=0)
   { if (aux1!=sizeof(dato))
	{ printf(" ERROR DE LECTURA EN ARCHIVO CIUDAD ..."); 
	  getch();exit(1);
	 }
       strcpy(ciudad,dato.ciudad);
 
     ayu1=mul;
      while ((ayu1!=NULL)&&(strcmp(ciudad,ayu1->ciudad)!=0))
       ayu1=ayu1->sig;
	 if(ayu1!=NULL)
	  printf(" ESTA CIUDAD YA EXISTE\n\n");
	  else
	  { nuevo=malloc(sizeof(struct nodo));
	    strcpy(nuevo->ciudad,ciudad);
	    nuevo->sig=NULL;
	    nuevo->ady=NULL;
	      if (mul==NULL)
		  mul=nuevo;
		   else
		      {  if (strcmp (nuevo->ciudad,mul->ciudad)<0)
			   {nuevo->sig=mul;
			    mul=nuevo;
			   }
			    else
			    {
			      aux2=mul;  control=0;
			       while ((aux2!=NULL)&&(control!=1))
				 { if (strcmp(nuevo->ciudad,aux2->ciudad)>0)
				   {aux=aux2;
				    aux2=aux2->sig;
				   }
				   else
				    control=1;
				 }

				if(aux2==NULL)
				 aux->sig=nuevo;
				 else
				  {aux->sig=nuevo;
				   nuevo->sig=aux2;
				  }

			    }

		       }


	  }

   }

  close(dno); /* CERRAR ARCHIVO CIUDAD*/

      if((dar=_open("a:\\arcos.dat",1))==-1)
	 { clrscr();
	   printf("ERROR AL INTENTAR ABRIR EL ARCHIVO ARCOS ");
	   getch();exit(1);
	 }
	
	 while ((aux1=_read(dar,&arista,sizeof(arista)))!=0)
	   { if (aux1!=sizeof(arista))
	       { printf(" ERROR DE LECTURA EN ARCHIVO ARCOS...");
		 getch();exit(1);
	       }

	      strcpy(origen,arista.origen);
	      strcpy(destino,arista.destino);
	      info=arista.distancia;

	      auxnodo=mul;
	    while ((auxnodo!=NULL) && (strcmp(auxnodo->ciudad,origen)!=0))
	      {
		auxnodo=auxnodo->sig;
	      }
	     if (auxnodo==NULL)
	      {
	       printf("Ciudad Origen: %s no Existe",origen);
	       return(1);
	       }
	       else
		{
		 auxnodo2=mul;
		 while ((auxnodo2!=NULL) && (strcmp(auxnodo2->ciudad,destino)!=0))
		  {
		    auxnodo2=auxnodo2->sig;
		  }
		 if (auxnodo2==NULL)
		   {
		    printf("Ciudad Destino: %s no Existe",destino);
		    return(1);
		    }
		 else
		  {
		  nuevo1=malloc(sizeof(struct arco));
		  nuevo1->info=info;
		  nuevo1->sig=NULL;
		  nuevo1->dest=auxnodo2;
		 if (auxnodo->ady==NULL)
		   auxnodo->ady=nuevo1;
		 else
		  {
		   auxarco=auxnodo->ady;
		  while (auxarco->sig!=NULL)
		   auxarco=auxarco->sig;
		  auxarco->sig=nuevo1;
	    }
	 }
      }

   }

close(dar);
  return(0);
}

//*********************************************************************************


imprimir()
 {
  struct nodo *auxnodo;
  struct arco *auxarco;

  clrscr();
  auxnodo=mul;
  while (auxnodo!=NULL)
    {
      printf("Origen: %s        y sus Adyacentes son: \n",auxnodo->ciudad);
      auxarco=auxnodo->ady;
      while (auxarco!=NULL)
	{
	  printf("%s info: %d  ",auxarco->dest->ciudad,auxarco->info);
	  auxarco=auxarco->sig;
	}
      printf("\n\n\n");
      auxnodo=auxnodo->sig;
    }
  getch();
  return(0);
}


//******************************************************************************


  void main()
   { 
    clrscr();
    textcolor(10); textbackground(1);
    cargar_grafo();
    menu();
    textmode(-1);clrscr();
   }

//************************************FINAL*****************************************


