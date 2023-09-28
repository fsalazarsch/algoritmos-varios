#include "iostream.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

#define limpiar clrscr();
#define pos gotoxy


class factura
{
  private:
  	 char empresa[20];
	 char nfact[5];
	 char fecha[8];
	 char concepto[30];
	 float cant;
	 float  vunit;
	 float vtotal;
	 float iva;
	 char clave[5];
	 int op,c,f,i;
	 char tecla;
	 int nreg;
	 int reg;

  public:
        void acceso();
        void menu();
        void captura();
        void reporte();
        void finalizar();
 };


  


 


void factura::acceso()
{
  
  do
  {
   limpiar
   pos(20,9);cout <<  " ";
   pos(20,10);cout << " WELCOME TO MANANGER PROGRAM         ";
   pos(20,12);cout << " PLEASE ENTER YOU PASSWORD [     ]   ";
   pos(20,13);cout << " ";
   for (i=0; i<=4; i++)
   {
    pos(49+i,12);tecla=getch();cout << '*';
    clave[i]=tecla;
    }clave[i]='\0';

    strcpy(clave,strupr(clave));
   
    if (strcmp(clave,"RACSO")==0)
    {
     menu();
    }
    else
    {
     c++;
     limpiar
     pos(33,12);cout << "E R R O R..";
     pos(30,14);cout << "A C C E S    D E N I E D ";
     pos(30,20);cout << "Pulse  Enter ==> ACCESO ";
     getch();
     }
   
   }while(c<3); 
  
  
  
 }



void factura::menu()
{

  while (1)
  {
   limpiar
    pos(32,12);cout <<"MENU PRINCIPAL";
    pos(29,14);cout <<" 1. CAPTURAR        ";
    pos(29,15);cout <<" 2. REPORTE GENERAL ";
    pos(29,16);cout <<" 3. FINALIZAR ";
  
    pos(29,18);cout <<"DIGITE OPCION [   ]";
    pos(45,18);cin >>op;

   
   
   if (op>3)
   {
     limpiar
     pos(29,14);cout << "Opcion Fuera de Rango";
     getch();
    }

    switch(op)
    {                  
	      case 1:captura();break;

	      case 2:reporte();break;

	      case 3:finalizar();break;
		     
     }
  }


}




void factura::captura()
{
    
    nreg=1;
    while(1)
    {
     
     limpiar
      pos(25,10);cout <<"EMPRESA         :  ";
      pos(25,11);cout <<"No. VENTA       :  ";
      pos(25,12);cout <<"FECHA           :  ";
      pos(25,13);cout <<"CONCEPTO        :  ";
      pos(25,14);cout <<"CANTIDAD        :  ";
      pos(25,15);cout <<"VOLOR UNITARIO  :  ";
      pos(25,16);cout <<"VALOR TOTAL     :  ";
      pos(25,17);cout <<"IVA             :  ";

     pos(43,10);cin >>empresa;
     //if (strcmp(empresa,"*")==0)break;
     if (empresa[0]=='*')break;
     pos(43,11);cin >>nfact;
     pos(43,12);cin >>fecha;
     pos(43,13);cin >>concepto;
     pos(43,14);cin >>cant;
     pos(43,15);cin >>vunit;
     pos(43,16);cin >>vtotal;
     pos(43,17);cin >>iva;
     nreg++;
       
      
    }

	 
}


void factura::reporte()
{
    
         limpiar
	  pos(4,1);cout <<"   INFORME GENERAL DE LAS VENTAS   ";
	  
	  pos(3,3);cout <<"EMPRESA      F No.  FECHA   CANT. CONCEPTO    V.UNIT     VTOT.        IVA";
                        
	  f=5;
	  for (i=1;i<nreg;i++)
          {

	   pos(3,f);cout <<empresa;
	   pos(16,f);cout <<nfact;
	   pos(23,f);cout <<fecha;
	   pos(38,f);cout <<concepto;
	   pos(27,f);cout <<cant;
	   pos(49,f);cout <<vunit;
	   pos(60,f);cout <<vtotal;
	   pos(70,f);cout <<iva;
           f++;
          
          }


getch();		
}  


void factura::finalizar()
{
 exit(0);
 }



 main()
 {

  factura fac;
  fac.acceso();
  fac.menu();
  fac.captura();
  fac.reporte();
  fac.finalizar();

  };
