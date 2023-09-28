//PROGRAMA DE ARCHIVO*****************
//PONCHA****************************
#include<io.h>
#include<dos.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int id1,id2;

 struct
 {   int num;
     char tipo;
     float iva;
     float valor;
     float descuento;
  } reg_factura;

  struct
  {
    int num;
    float abono;
  }reg_abonos;

  void abrir_facturas();
  void adicionar_facturas();
  void realbonos();
  void abonos_facturas();
  void adicionar_abonos();
  void abrir_abonos();
  void ver_facturas();
  void menu(); 
  void consultar_estado();
  void crear_archivo();  
  void cuadro(int x1,int x2,int y1,int y2);
  void plantilla();



  /*****************************************************************/
  void abrir_facturas()
  {
     id1=_open("a:\\factura.dat",4);
       if (id1==-1)
	 {
	  clrscr();
	  printf("ENTRAMOS A CREAR ARCHIVO FACTURA.DAT");
	  delay(500);
	  id1=_creat("a:\\factura.dat",0);

	  if(id1==-1)
	    {
	    clrscr();
	    printf("imposible crear archivo FACTURA.DAT");
	    delay(500);
	    exit(0);
	    }
	  }

  }

  /********************************************************************/
  void abrir_abonos()
  {
     id2=_open("a:\\factura.dat",4);
       if (id2==-1)
	 {
	  clrscr();
	  printf("ENTRAMOS A CREAR ARCHIVO FACTURA.DAT");
	  delay(500);
	  id2=_creat("a:\\factura.dat",0);

	  if(id2==-1)
	    {
	    clrscr();
	    printf("imposible crear archivo FACTURA.DAT");
	    delay(500);
	    exit(0);
	    }
	  }

  }

      /*******************************************************/
  void adicionar_facturas()

 {
   int num,bytes,lon,i,st=0;
   char tipo,op,clave,cadena[20],eva[20],ides[20],val[20],llave;
   float valor=0,ivat=0,des,iva=0,valort=0;
   
   abrir_facturas();
       gotoxy(11,2);
   printf(" A D I C I O N   D E   R E G I S T R O S                ");
	gotoxy(25,16);printf(" ญ Abriendo archivo ! ");
	delay(1000);


   do{
      clrscr();
      //cuadro(6,53,4,17);
   
       plantilla();
      do
	{
	 clave='n';
	 gotoxy(30,6);
	 clreol();
	 cuadro(6,53,4,21);
	 //printf("       ");
	 gotoxy(28,7);printf("FACTURA No: ");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
	    {
	     gotoxy(21,14);
	     clave='s';
	     break;
	    }              
	  }
	 }while(clave=='s');

	  num=atol(cadena);
	  lseek(id1,0l,0);
	  while(!eof(id1))
	    { bytes=_read(id1,&reg_factura,sizeof(reg_factura));
	     
	      if (bytes!=sizeof(reg_factura))
		{clrscr();
		 gotoxy(21,14);
		 printf(" ERROR DE LECTURA EN FACTURA");
		 getch();exit(0);
		}
		      
	       if (reg_factura.num==num)
		 st=1;
	    }
	 if(st==0){
	       reg_factura.num=num;


	       gotoxy(20,8);printf("[D->CONTADO -- C->CREDITO] ");
	       gotoxy(10,10);printf("TIPO :[   ]");
	       do{
		 gotoxy(17,10);
		 //clreol();
		 //cuadro(6,53,4,17);
		 printf(" ");
		 
		 tipo=toupper(getche());
		 
	       }while((tipo!='D')&&(tipo!='C'));
		 gotoxy(53,10);printf("บ");
 
		 reg_factura.tipo=tipo;
	  //perror ("tipo");

		 // gotoxy(10,11);printf("VALOR............ :");		  
		  //gets(val);
	  
		     do
		      {
			    clave='n';
			    gotoxy(29,11);
			    clreol();
			    cuadro(6,53,4,21);
			    gotoxy(10,11);printf("VALOR............ :");scanf("\n");
			    gets(val);
			    
			    lon = strlen(val);
				 for(i=0;i<=lon-1; i++)
				  {
				   if(!isdigit(val[i]))
				    {
				     gotoxy(21,14);
				     clave='s';
				     break;
				    }              
				  }
		     }while(clave=='s');

		     valor=atof(val);
	  

		 gotoxy(33,12);printf("%");
		// gotoxy(10,12);printf("IVA.............. :");//scanf("\n");
		 
	  
		     do
		      {
			    clave='n';
			    gotoxy(29,12);
			    clreol();

			   cuadro(6,53,4,21);
			   gotoxy(33,12);printf("%");
			   gotoxy(10,12);printf("IVA.............. :"); scanf("\n");
			   gets(eva);
			   lon = strlen(eva);
				 for(i=0;i<=lon-1; i++)
				  {
				   if(!isdigit(eva[i]))
				    {
				     gotoxy(21,14);
				     clave='s';          
				     break;
				    }              
				  }
		     }while(clave=='s');

		     iva=atof(eva);
	  



		 ivat=iva/100;
	   
		 // gotoxy(10,13);printf("DESCUENTO........ :");scanf("\n");
		 // gets(ides);
		     do
		      {
			    llave='n';
			    gotoxy(29,13);
			    clreol();
			    cuadro(6,53,4,21);
			    gotoxy(10,13);printf("DESCUENTO........ :");scanf("\n");
			    gets(ides);

			    lon = strlen(ides);
				 for(i=0;i<=lon-1; i++)
				  {
				   if(!isdigit(ides[i]))
				    {
				     gotoxy(21,14);
				     llave='s';
				     break;
				    }              
				  }
		     }while(llave=='s');

		     des=atof(ides);


		  valort=valor * ivat;
	   
		  reg_factura.valor=(valor+valort)-des;
		  reg_factura.descuento=des;
		  reg_factura.iva=iva;

		     lseek(id1,0l,2);
		     bytes=_write(id1,&reg_factura,sizeof(reg_factura));
			if(bytes!=sizeof(reg_factura))
			  {
			    printf(" ERROR DE LECTURA ");
			    delay(500);
			    exit(0);
			  }
			 else 
			  {
			    gotoxy(15,18);printf("ญญ FACTURA ACEPTADA !!");  
			   }       
	
	  
	      }	  
	      else{clrscr();
		 gotoxy(15,12);
		  printf("ญญ ESTA FACTURA YA EXISTE !! "); 
		  delay(1300);
		  break;
		}




	    gotoxy(12,19);printf(" DESEA ALMACENAR OTRO REGISTRO  (S/N)?");
	    op=toupper(getch());

	      
	     
		     
  }while(op!='N');
     close (id1);
   

}       
   /***************************************************************/

void main()
{
 clrscr();
 menu(); 
 getche();
 } 

 /*******************************************************************/

  void ver_facturas()
 {
    int bytes,j=5;
    abrir_facturas();
    abrir_abonos();
    clrscr();
	  gotoxy(19,2);printf("V I S U A L I Z A C I O N\n"); 
	  gotoxy(1,3);printf("FACTURA No   TIPO FACT    VALOR FACT    DESCUENTO FACT   ");      



    while (!eof(id1))
    {
      bytes=_read(id1,&reg_factura,sizeof(reg_factura));
	 if (bytes!=sizeof(reg_factura))
	  { 

	 
	    printf(" error de lectura");      
	    delay(500);
	    exit(0);
	  }
	  gotoxy(3,j);printf("%d\n",reg_factura.num);      
	  gotoxy(28,j);printf("%.2f\n",reg_factura.valor);
	  gotoxy(17,j);printf("%c\n",reg_factura.tipo);
	  gotoxy(44,j);printf("%.2f\n",reg_factura.descuento);
	  //gotoxy(53,j);printf("%.2f\n",reg_factura.iva);

	   j++;


	   gotoxy(15,20);printf("ฎ PRESIONE ENTER PARA VOLVER AL MENU ฏ");

	 
	  
	     }
	 
	 
	   getche();

	 close(id1);
	 close(id2);
	

   }		
    /*****************************************************************


    /**************************************************************/

void menu()
{
char op;
do
{textbackground(1);
clrscr();
//window(1,1,80,25);
//cierre(5,65);
//cuadro(4,18,6,62);
//cuadro(7,11,19,68);
//cuadro(23,23,25,58);
textbackground(1);
window(12,3,68,23);clrscr();
textcolor(14);
//gotoxy(10,2);cprintf("CORPORACION UNIVERSITARIA DE SANTANDER ");
//gotoxy(15,4);cprintf(" ROBERTO ARAGON CURSO S2A ");
gotoxy(11,7);cprintf("ฎ ฎ M E N U  P R I N C I P A L ฏ ฏ");
gotoxy(18,10); cprintf("1.  CREAR ARCHIVOS ");
gotoxy(18,11); cprintf("2.  ADICIONAR REGISTRO");
gotoxy(18,12); cprintf("3.  VISUALIZAR REGISTROS");
gotoxy(18,13); cprintf("4.  CONSULTAR ESTADO");
gotoxy(18,14); cprintf("5.  REALIZAR ABONOS");
gotoxy(18,15); cprintf("6.  TERMINAR");
/*gotoxy(18,16); cprintf("7.  ");*/

//window(1,1,80,25);
gotoxy(15,20); cprintf("D I G I T E  L A  O P C I O N [ ] " );
do{
   gotoxy(46,20);printf(" ");
   gotoxy(46,20);op=getche();
  }while(op<'1'||op>'6');
 switch(op)
 {

   case '1' : clrscr(); crear_archivo();break;
   case '2' : clrscr(); adicionar_facturas();break;
   case '3' : clrscr(); ver_facturas();break;   
   case '4' : clrscr(); consultar_estado();break;
   case '5' : clrscr(); realbonos();break;
  /*case '6' : clrscr();break;*/
 }
 }while (op!='6');
}
/***********************************************************************/
void consultar_estado()
{
    char clave,cadena[10],tp;
    int bytes,ft,i,lon,sw=0;
    abrir_facturas();
    plantilla();
    do
	{
	 clave='n';
	 gotoxy(41,7);
	 clreol();
	 cuadro(6,53,4,21);
	 //printf("       ");
	 gotoxy(28,7);printf("FACTURA No:");
	 scanf("\n"); gets(cadena);
	 lon = strlen(cadena);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(cadena[i])))||(lon>5))
	    {
	     gotoxy(21,14);
	     clave='m';
	     break;
	    }
	  }
	 }while(clave=='m');

	ft=atol(cadena);
	   
	 
			    
    while (!eof(id1))
    {
      bytes=_read(id1,&reg_factura,sizeof(reg_factura));
	 if (bytes!=sizeof(reg_factura))
	  { 
	    printf(" error de lectura");      
	    delay(500);
	    exit(0);
	  }
	 if (reg_factura.num==ft)
	  {
	   clrscr();
	  plantilla();
	  abrir_abonos();
	  sw=1;
	  gotoxy(41,7);printf("%d\n",reg_factura.num);      
	  gotoxy(31,11);printf("%.2f\n",reg_factura.valor);
	  gotoxy(17,10);printf("%.c\n",reg_factura.tipo);
	  gotoxy(31,12);printf("%.2f\n",reg_factura.iva);
	  gotoxy(31,13);printf("%.2f\n",reg_factura.descuento);
		    
	  close(id2);
	  }

	  
    }		

    if (sw==0)	
     { gotoxy(15,7);printf("FACTURA INEXISTENTE"); }     
	  

      getche();
      close(id1);
	

  }
  /***********************************************************************/
   void crear_archivo()
{    int sw=0;
     char res;
     printf("              C R E A R    A R C H I V O S                  ");
     gotoxy(25,12);printf("  ! Creando archivos ญ  ");
     if((id1=_open("A:\\FACTURA.DAT",4))!=-1)sw=1;
     if((id2=_open("A:\\ABONOS.DAT ",4))!=-1)sw=2;
     if(sw>0)
	{
	gotoxy(20,10);printf(" ARCHIVO YA EXISTE ");
	gotoxy(20,11);printf("Desea sobrescribir?(s/n)");res=toupper(getch());
	}
     if(sw==0 || res=='S')
     {
	if((id1=_creat("A:\\FACTURA.DAT",0))==-1)
	   {  clrscr();gotoxy(10,15);
		printf("ERROR DE CREACION DEL ARCHIVO FACTURA.DAT");
		getch();exit(1);
	    }
	if((id2=_creat("A:\\ABONOS.DAT",0))==-1)
	   {  clrscr();gotoxy(10,15);
		printf("ERROR DE CREACION DEL ARCHIVO ABONOS.DAT");
		getch();exit(1);
	   }
      }
}



 /*******************************************************************/
  void realbonos()
  {
   int bytes,ft,sw=0,lon,i,ab,b;
   char fact[10],clave,arena[15];
   abrir_facturas();
   abrir_abonos();
    clrscr();
	do
	{
	 clave='n';
	 gotoxy(30,6);
	 clreol();
	 cuadro(6,53,4,21);
	//printf("       ");
	 plantilla();
	 gotoxy(28,7);printf("FACTURA No:");
	 scanf("\n"); gets(fact);
	 lon = strlen(fact);
	 for(i=0;i<=lon-1; i++)
	  {
	   if((!(isdigit(fact[i])))||(lon>5))
	    {
	     gotoxy(21,14);
	     clave='s';
	     break;
	    }
	  }
	 }while(clave=='s');


	ft=atol(fact);


      /*while( (b=_read(id2,&reg_abonos,sizeof(reg_abonos))) != 0)
      {
	 if(b != sizeof(reg_abonos) )
	 {printf("ERROR DE LECTURA");
	 getch();exit(1);}
      }*/






      while (!eof(id1))
       {
	bytes=_read(id1,&reg_factura,sizeof(reg_factura));
	     if (bytes!=sizeof(reg_factura))
	      { 
		printf(" error de lectura");      
		 delay(500);
		 exit(0);
	       }
	      if (reg_factura.num==ft)

		 {   
		    // clrscr();
		    
		    //gotoxy(15,7);printf("factura #:... %d\n",reg_factura.num);      
		    gotoxy(31,11);printf("%.2f\n",reg_factura.valor);
		    gotoxy(18,10);printf("%c\n",reg_factura.tipo);
		    gotoxy(31,12);printf("%.2f\n",reg_factura.iva);
		    gotoxy(31,13);printf("%.2f\n",reg_factura.descuento);

		     sw=1;
		     if(reg_factura.tipo=='C')
		      {
			  gotoxy(15,15);printf("DIGITE EL ABONO:");
			 
			  do
			 {
			    clave='n';
			    gotoxy(31,10);
			      clreol();
			     cuadro(6,53,4,21);
			     //printf("       ");
			       gotoxy(15,15);printf("DIGITE EL ABONO:");
			       scanf("\n"); gets(arena);
			       lon = strlen(arena);
			       for(i=0;i<=lon-1; i++)
				{
				 if((!(isdigit(arena[i])))||(lon>5))
				    {
				       gotoxy(21,14);
					 clave='s';
				       break;
					}                
				  }
			    }while(clave=='s');

				ab=atof(arena);



			  if (reg_factura.valor>=0)

			    if (ab <= reg_factura.valor)
			     {

			       reg_abonos.abono=ab;
			       reg_factura.valor= (reg_factura.valor - reg_abonos.abono);
			       gotoxy(15,16);printf("SALDO:..... %.2f\n",reg_factura.valor);
			

			       bytes=_write(id1,&reg_factura,sizeof(reg_factura));
				if (bytes!=sizeof(reg_factura))
				    { 
				       printf(" ERROR DE LECTURA ");      
					delay(500);      
					exit(0);
				     }
										
			      }
			     else
				{ clrscr();
			       gotoxy(15,11);printf(" EL ABONO ES SUPERIOR!! ");
			       break;
			       }
			   else
			   {
			    gotoxy(15,11);printf(" FACTURA CANCELADA !! ");
			    break;}

			   }
			  else
			    { clrscr();
			      gotoxy(15,10);printf("LA FACTURA FUE CANCELADA DE CONTADO");
			      break;
			    }

		 }   
		 
		    
	getche();     
		
    }		
    if (sw==0)

      {	 clrscr(); 
      gotoxy(15,6);printf("FACTURA INEXISTENTE !! ");
      getche();
      }
     getche();
    close(id1);
    close(id2);

 }  

      /*************************************************************/ 		      
 void cuadro(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     for(j=x1;j<=x2;j++)
       {
       gotoxy(j,y1);printf("อ");
       gotoxy(j,y2);printf("อ");
       }
     for(i=y1;i<=y2-1;i++)
       {   
       gotoxy(x1,i);printf("บ");
       gotoxy(x2,i);printf("บ");
       }
     gotoxy(x1,y1);printf("ษ");
     gotoxy(x2,y1);printf("ป");
     gotoxy(x1,y2);printf("ศ");
     gotoxy(x2,y2);printf("ผ");
}
	/*******************************************************/
void plantilla()
{
 clrscr();
 cuadro(6,53,4,21);
 gotoxy(23,5);printf("E M P R E S A   XXX");
 gotoxy(28,7);printf("FACTURA No:");
 gotoxy(10,10);printf("TIPO :[  ]");
// gotoxy(20,9);printf("[D->CONTADO -- C->CREDITO]");
 gotoxy(10,11);printf("VALOR............ :");
 gotoxy(10,12);printf("IVA.............. :");
 gotoxy(10,13);printf("DESCUENTO........ :");

}	 
	 
	 
	 
	 
	 