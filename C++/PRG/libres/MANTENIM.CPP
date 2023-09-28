# include "conio.h"
# include "stdio.h"
# include "iostream.h"
# include "dos.h"
# include "ctype.h"
# include "stdlib.h"
# include "string.h"



inline void escriba(int x,int y,char letra[])
{ 
gotoxy(x,y); cprintf("%s",letra);
}

float ex;
int tipo;

int reg_pro=0;
int reg_con=0;
int reg_cen=0;
int reg_mov=0;

void menu_pincipal();


/*****opciones del menu*****/
void mantenimiento();
void consulta_de_datos();
void digitacion_de_movimientos();
void informes();


/*****opciones de mantenimiento*****/
void mantenimiento_concepto();
void mantenimiento_producto();
void mantenimiento_centros();


/*****opciones de consulta de datos*****/
void consulta_inventarios();
void consulta_basico_producto();
void consulta_movimiento();
void consulta_centros();


/********opciones de informes*********/
void estadistico_producto1();
void estadistico_producto2();

void pantalla1();



/**************************CLASES***************************/

class conceptos
{
    char cod[4];
    char des[30];
    char tip[2];
    public:
    void crear();
    void modificar();
    void retirar();
    void consultar();
    void mostrar_conceptos();
    int busca_conceptos(char[]);
} cpto[10];



class productos
{
    char cod[10];
    char nom[30];
    char unidad[15];
    float vlrcom;
    float vlrven;
    float existencia;

    public:
	   //productos();
	   void crear();
	   void modificar();
	   void retirar();
	   void consultar();
	   void mostrar_productos();
	   int busca_productos(char[],float);
}prod[10];


class centros
{
   char cod[10];
   char des[40];

   public:
	   void crear();
	   void modificar();
	   void retirar();
	   void consultar();
	   void mostrar_centros();
	   int busca_centros(char[]);
}cent[10];


	   
class mvtos
{
   char doc[10];
   char pro[10];
   char cpt[4];
   char cen[5];
   float cant;
   float vlrmvto;
   
   public:
	   void crear();
	   void modificar();
	   void retirar();
	   void consultar();
	   void mostrar_movimientos();
}mvt[10]; 





void pantalla1()
{   
	  textcolor(10);
	  clrscr();
	  escriba(12,1," ===========================================================");
	  escriba(27,2," LACTEOS DEL  CARIBE LIMITADA ");
	  escriba(17,3,"SISTEMA DE INFORMACION GERENCIAL - MODULO DE VENTA ");
	  escriba(38,4,"CURSO S3E");
	  escriba(12,5," ===========================================================");  
	    
}


/************************MENU PRINCIPAL***************************/

void menu_principal()
{   
	char op;
	clrscr();
	do{
	   pantalla1();
	   escriba(31,13,"1- MANTENIMIENTO ");
	   escriba(31,14,"2- CONSULTA  ");
	   escriba(31,15,"3- MOVIMIENTOS  ");
	   escriba(31,16,"4- INFORMES");
	   escriba(31,17,"5- SALIR");
	   escriba(28,20,"ELIJA UNA OPCION [ ]");
	   gotoxy(46,20);op=getch();
	   switch(op)
	   {
	      case '1':
			mantenimiento();
			break;
	      case '2':
			consulta_de_datos();
			break;
	      case '3': 		
			digitacion_de_movimientos();
			break;
	      case '4':		
			informes();
			break;
	      case '5': 
			break;
	    }
	  }while(op!='5');
}
   

/************************MANTENIMIENTOS***************************/

void mantenimiento()
{
	char op;
	clrscr();
	do{
	   clrscr();
	   escriba(34,6,"MANTENIMIENTOS");
	   escriba(31,8,"1- MANTENIMIENTO DE CONCEPTOS ");
	   escriba(31,9,"2- MANTENIMIENTO DE PRODUCTOS  ");
	   escriba(31,10,"3- MANTENIMIENTO DE CENTROS ");
	   escriba(31,11,"4- SALIR");
	   escriba(28,13,"ELIJA UNA OPCION [ ]");
	   gotoxy(46,13);op=getch();
	   switch(op)
	   {
	      case '1':
			mantenimiento_concepto();
			break;
	      case '2':
			mantenimiento_producto();
			break;
	      case '3': 		
			mantenimiento_centros();
			break;
	      case '4':		
			break;
	    }
	  }while(op!='4');
}


/*********************MANTENIMIENTO DE CONCEPTOS***************************/

void mantenimiento_concepto()
{  
      conceptos con;
      char op;
      do{
	 clrscr();
	 textcolor(10);
	 escriba(12,6," ===========================================================");
	 escriba(20,7," L A C T E O S   D E L   C A R I B E  LTDA. ");
	 escriba(21,8,"        MANTENIMIENTO DE CONCEPTOS  ");
	 escriba(12,11," ===========================================================");  
	 escriba(12,13," CODIGO       :  ");
	 escriba(12,14," NOMBRE       :  ");
	 escriba(12,15," TIPO         :         C=Credito  o  D= Decontado      ");
	 escriba(12,17,"===========================================================");
	 escriba(4,19,"[1] ADICIONAR    [2] CONSULTAR   [3] MODIFICAR  [4] RETIRAR  [5]SALIR ");
         escriba(4,21,"DIGITE SU OPCION [ ]");
         gotoxy(22,21);
	 op=getch();
	 switch(op)
	 {
	      case '1': con.crear();
			break;

	      case '2': con.consultar();	
			break;


	      case  '3': con.modificar();
			 break;


	      case  '4': con.retirar();
			 break;


	      case   '5': break;
			  
	  }	
	}while(op!='5');

}



void conceptos::crear()
{
  char cod[3];
  int entre=0;
  escriba(15,10,"OPCION (1). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(4,21);
      clreol();
      escriba(34,15,"C=Credito  o  D= Decontado");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_con; i++)
     {
      if(strcmp(cod,cpto[i].cod)==0)
      {
           textcolor(128+10);escriba(59,9,"! YA EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
	   entre=1;
	}
       }
     if(entre==1)
      continue;
      strcpy(cpto[reg_con].cod,cod);
      gotoxy(28,14);
      gets(cpto[reg_con].des);
      gotoxy(28,15); 
      gets(cpto[reg_con].tip); 
      reg_con++;
  }



}


void conceptos::modificar()
{
  char cod[3],op;
  char de[30],tp[2],c;
  int entre=0;
  escriba(15,10,"OPCION (3). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(4,21);
      clreol();
      escriba(34,15,"C=Credito  o  D= Decontado");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_con; i++)
     {
       if(strcmp(cod,cpto[i].cod)==0)
       {
         gotoxy(28,14);
         cout<<cpto[i].des;
         gotoxy(28,15); 
         cout<<cpto[i].tip; 
         escriba(4,21,"DESEA MODIFICARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
           escriba(34,15,"C=Credito  o  D= Decontado");
           strcpy(cpto[i].cod,cod);
           gotoxy(28,14);
           strcpy(de,cpto[i].des);
           c=getch();
           if(c!='\r')
           {
             gotoxy(28,14);
             clreol();
             gets(de);
           }
           strcpy(cpto[i].des,de);
           gotoxy(28,15); 
           strcpy(tp,cpto[i].tip);
           c=getch();
           if(c!='\r')
           {
              gotoxy(28,15);
              clreol();
              gets(tp);
           }   
           strcpy(cpto[i].tip,tp);
           entre=1;
           break;
         }
         if(op=='N')
         {
           textcolor(128+10);escriba(50,9,"! MODIFICACION NO EFEUTUADA !");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           textcolor(128+10);escriba(54,9,"! FUE MODIFICADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(54,9);
	   clreol();
     }

 }
}


void conceptos::retirar()
{
  char cod[3],op;
  int entre=0;
  escriba(15,10,"OPCION (4). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(4,21);
      clreol();
      escriba(34,15,"C=Credito  o  D= Decontado");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_con; i++)
     {
       if(strcmp(cod,cpto[i].cod)==0)
       {
         gotoxy(28,14);
         cout<<cpto[i].des;
         gotoxy(28,15); 
         cout<<cpto[i].tip; 
         escriba(4,21,"DESEA ELIMINARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
             entre=1;
             for(int j=i;j<=reg_con;j++)
             {
                strcpy(cpto[j].cod,cpto[j+1].cod);
                strcpy(cpto[j].des,cpto[j+1].des);
                strcpy(cpto[j].tip,cpto[j+1].tip);
             }
         }
         else
         {
           textcolor(128+10);escriba(50,9,"! ELIMINACION NO EFEUTUADA!");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           reg_con--;
           textcolor(128+10);escriba(55,9,"! FUE RETIRADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(55,9);
	   clreol();
     }

 }
}


void conceptos::consultar()
{
  char cod[3];
  int entre=0;
  escriba(15,10,"OPCION (2). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(4,21);
      clreol();
      escriba(34,15,"C=Credito  o  D= Decontado");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_con; i++)
     {
      if(strcmp(cod,cpto[i].cod)==0)
      {
          gotoxy(28,14);
          cout<<cpto[i].des;
          gotoxy(28,15); 
          cout<<cpto[i].tip; 
          entre=1;
          getch();
          break;
      }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
    
  }
}


/************************MANTENIMIENTO DE PRODUCTO*************************/

void mantenimiento_producto()
{
      productos pro;
      char op;
      do{
	 clrscr();
	 textcolor(10);
	 escriba(12,6," ===========================================================");
	 escriba(20,7," L A C T E O S  D E L   C A R I B E  LTDA. ");
	 escriba(21,8,"    MANTENIMIENTO DE PRODUCTOS  ");
	 escriba(12,11," ===========================================================");  
	 escriba(12,13," CODIGO       :  ");
	 escriba(12,14," NOMBRE       :  ");
	 escriba(12,15," UNIDAD       :          (Lts - Grs - Klg) ");
	 escriba(12,16," VALOR COMPRA :  ");
	 escriba(12,17," VALOR VENTA  :  ");
         escriba(12,18," EXISTENCIA   :  ");
	 escriba(12,19,"===========================================================");
	 escriba(4,20,"[1] ADICIONAR    [2] CONSULTAR   [3] MODIFICAR  [4] RETIRAR  [5]SALIR ");
         escriba(4,22,"DIGITE SU OPCION [ ]");
         gotoxy(22,22);
	 op=getch();
	 switch(op)
	 {
	      case '1': pro.crear();
			break;

	      case '2': pro.consultar();	
			break;


	      case  '3': pro.modificar();
			 break;


	      case  '4': pro.retirar();
			 break;


	      case   '5': break;
			  
	  }	
	}while(op!='5');

}


void productos::crear()
{
  char cod[10];
  int entre=0;
  escriba(15,10,"OPCION (1). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(28,16);
      clreol();
      gotoxy(28,17);
      clreol();
      gotoxy(28,18);
      clreol();
      gotoxy(4,22);
      clreol();
      escriba(34,15,"   (Lts - Grs - Klg) ");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_pro; i++)
     {
      if(strcmp(cod,prod[i].cod)==0)
      {
           textcolor(128+10);escriba(59,9,"! YA EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
	   entre=1;
      }
     }
     if(entre==1)
      continue;
      strcpy(prod[reg_pro].cod,cod);
      gotoxy(28,14);
      gets(prod[reg_pro].nom);
      gotoxy(28,15); 
      gets(prod[reg_pro].unidad); 
      gotoxy(28,16);
      cin>>prod[reg_pro].vlrcom;
      gotoxy(28,17);
      cin>>prod[reg_pro].vlrven;
      gotoxy(28,18);
      cin>>prod[reg_pro].existencia;
      reg_pro++;
  }
}

void productos::consultar()
{
  char cod[10];
  int entre=0;
  escriba(15,10,"OPCION (2). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(28,16);
      clreol();
      gotoxy(28,17);
      clreol();
      gotoxy(28,18);
      clreol();
      gotoxy(4,22);
      clreol();
      escriba(34,15,"   (Lts - Grs - Klg) ");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_pro; i++)
     {
      if(strcmp(cod,prod[i].cod)==0)
      {
          gotoxy(28,14);
	  cout<<prod[i].nom;
	  gotoxy(28,15); 
	  cout<<prod[i].unidad;
	  gotoxy(28,16); 
	  cout<<prod[i].vlrcom;
	  gotoxy(28,17); 
	  cout<<prod[i].vlrven;
          gotoxy(28,18); 
	  cout<<prod[i].existencia;
          entre=1;
          getch();
          break;
      }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
  }
}



void productos::modificar()
{
  char cod[10],op,c;
  char no[30];
  char un[15];
  float vcom;
  float vven;
  float exis;

  int entre=0;
  escriba(15,10,"OPCION (3). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(28,16);
      clreol();
      gotoxy(28,17);
      clreol();
      gotoxy(28,18);
      clreol();
      gotoxy(4,22);
      clreol();
      escriba(34,15,"   (Lts - Grs - Klg) ");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_pro; i++)
     {
       if(strcmp(cod,prod[i].cod)==0)
       {
         gotoxy(28,14);
	 cout<<prod[i].nom;
	 gotoxy(28,15); 
	 cout<<prod[i].unidad; 
	 gotoxy(28,16); 
	 cout<<prod[i].vlrcom;
	 gotoxy(28,17); 
	 cout<<prod[i].vlrven;
         gotoxy(28,18); 
	 cout<<prod[i].existencia;
	 escriba(4,21,"DESEA MODIFICARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
	   escriba(34,15,"   (Lts - Grs - Klg) ");
	   strcpy(prod[i].cod,cod);
	   gotoxy(28,14);
           strcpy(no,prod[i].nom);
           c=getch();
           if(c!='\r')
           {
              gotoxy(28,14);
              clreol();
	      gets(no);
           }
           strcpy(prod[i].nom,no);
	   gotoxy(28,15); 
           strcpy(un,prod[i].unidad);
           c=getch();
           if(c!='\r')
           {
              gotoxy(28,15);
              clreol();
	      gets(un);
           }
           strcpy(prod[i].unidad,un);
	   gotoxy(28,16); 
           vcom=prod[i].vlrcom;
           c=getch();
           if(c!='\r')
           {
               gotoxy(28,16);
	       clreol();
	       cin>>vcom;
               escriba(34,15,"   (Lts - Grs - Klg) ");
           }
	   prod[i].vlrcom=vcom;   
	   gotoxy(28,17); 
           vven=prod[i].vlrven;
           c=getch();
           if(c!='\r')
           {
              gotoxy(28,17);
              clreol();
	      cin>>vven;
           }
	   prod[i].vlrven=vven;   
           gotoxy(28,18);
           exis=prod[i].existencia;
           c=getch();
           if(c!='\r')
           {
              gotoxy(28,18);
              clreol();
	      cin>>exis;
           }
	   prod[i].existencia=exis;   
	   entre=1;
           break;
         }
         if(op=='N')
         {
           textcolor(128+10);escriba(50,9,"! MODIFICACION NO EFEUTUADA !");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           textcolor(128+10);escriba(54,9,"! FUE MODIFICADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(54,9);
	   clreol();
     }

 }

}


void productos::retirar()
{
  char cod[3],op;
  int entre=0;
  escriba(15,10,"OPCION (4). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(28,15);
      clreol();
      gotoxy(28,16);
      clreol();
      gotoxy(28,17);
      clreol();
      gotoxy(28,18);
      clreol();
      gotoxy(4,22);
      clreol();
      escriba(34,15,"    (Lts - Grs - Klg)");
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_pro; i++)
     {
       if(strcmp(cod,prod[i].cod)==0)
       {
         gotoxy(28,14);
	 cout<<prod[i].nom;
	 gotoxy(28,15); 
	 cout<<prod[i].unidad; 
	 gotoxy(28,16); 
	 cout<<prod[i].vlrcom; 
	 gotoxy(28,17); 
	 cout<<prod[i].vlrven; 
         gotoxy(28,18); 
	 cout<<prod[i].existencia; 
         escriba(4,21,"DESEA ELIMINARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
             entre=1;
	     for(int j=i;j<=reg_pro;j++)
	     {
		strcpy(prod[j].cod,prod[j+1].cod);
		strcpy(prod[j].nom,prod[j+1].nom);
		strcpy(prod[j].unidad,prod[j+1].unidad);
		prod[j].vlrcom=prod[j+1].vlrcom;
		prod[j].vlrven=prod[j+1].vlrven;
                prod[j].existencia=prod[j+1].existencia;
	     }
	 }
         else
         {
           textcolor(128+10);escriba(50,9,"! ELIMINACION NO EFEUTUADA!");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
	   reg_pro--;
           textcolor(128+10);escriba(55,9,"! FUE RETIRADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(55,9);
	   clreol();
     }

 }

}




/************************MANTENIMIENTO DE CENTROS/*************************/

void mantenimiento_centros()
{
      centros cen;
      char op;
      do{
	 clrscr();
	 textcolor(10);
	 escriba(12,6," ===========================================================");
	 escriba(20,7," L A C T E O S  D E L   C A R I B E  LTDA. ");
	 escriba(21,8,"    MANTENIMIENTO DE CENTROS  ");
	 escriba(12,11," ===========================================================");  
	 escriba(12,13," CODIGO       :  ");
	 escriba(12,14," NOMBRE       :  ");
	 escriba(12,16,"===========================================================");
	 escriba(4,18,"[1] ADICIONAR    [2] CONSULTAR   [3] MODIFICAR  [4] RETIRAR  [5]SALIR ");
         escriba(4,20,"DIGITE SU OPCION [ ]");
         gotoxy(22,20);
	 op=getch();
	 switch(op)
	 {
	      case '1': cen.crear();
			break;

	      case '2': cen.consultar();	
			break;


	      case  '3': cen.modificar();
			 break;


	      case  '4': cen.retirar();
			 break;


	      case   '5': break;
			  
	  }	
	}while(op!='5');

}



void centros::crear()
{
  char cod[10];
  int entre=0;
  escriba(15,10,"OPCION (1). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(4,20);
      clreol();
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_cen; i++)
     {
      if(strcmp(cod,cent[i].cod)==0)
      {
	   textcolor(128+10);escriba(59,9,"! YA EXISTE !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
	   entre=1;
      }
     }
     if(entre==1)
      continue;
      strcpy(cent[reg_cen].cod,cod);
      gotoxy(28,14);
      gets(cent[reg_cen].des);
      reg_cen++;
  }

}


void centros::consultar()
{
  char cod[10];
  int entre=0;
  escriba(15,10,"OPCION (2). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(4,20);
      clreol();
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_cen; i++)
     {
      if(strcmp(cod,cent[i].cod)==0)
      {
          gotoxy(28,14);
	  cout<<cent[i].des;
          entre=1;
          getch();
          break;
      }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
  }

}


void centros::modificar()
{
  char cod[3],op;
  char de[40],c;
  int entre=0;
  escriba(15,10,"OPCION (3). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(4,20);
      clreol();
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_cen; i++)
     {
       if(strcmp(cod,cent[i].cod)==0)
       {
         gotoxy(28,14);
         cout<<cent[i].des;
         escriba(4,21,"DESEA MODIFICARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
           strcpy(cent[i].cod,cod);
           gotoxy(28,14);
           strcpy(de,cent[i].des);
           c=getch();
           if(c!='\r')
           {
             gotoxy(28,14);
             clreol();
             gets(de);
           }
           strcpy(cent[i].des,de);
           entre=1;
           break;
         }
         if(op=='N')
         {
           textcolor(128+10);escriba(50,9,"! MODIFICACION NO EFEUTUADA !");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           textcolor(128+10);escriba(54,9,"! FUE MODIFICADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(54,9);
	   clreol();
     }

 }

}


void centros::retirar()
{
  char cod[10],op;
  int entre=0;
  escriba(15,10,"OPCION (4). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(27,13);
      clreol();
      gotoxy(28,14);
      clreol();
      gotoxy(4,20);
      clreol();
      gotoxy(28,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_cen; i++)
     {
       if(strcmp(cod,cent[i].cod)==0)
       {
         gotoxy(28,14);
         cout<<cent[i].des;
         escriba(4,21,"DESEA ELIMINARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
             entre=1;
             for(int j=i;j<=reg_cen;j++)
             {
                strcpy(cent[j].cod,cent[j+1].cod);
                strcpy(cent[j].des,cent[j+1].des);
             }
         }
         else
         {
           textcolor(128+10);escriba(50,9,"! ELIMINACION NO EFEUTUADA!");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
           textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           reg_cen--;
           textcolor(128+10);escriba(55,9,"! FUE RETIRADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(55,9);
	   clreol();
     }

 }

}





/**********************CONSULTA DE DATOS*****************************/



void consulta_de_datos()
{
	char op;
	conceptos con;
	productos pro;
	centros cen;
	mvtos mov;
	clrscr();
	do{
	   clrscr();
	   escriba(27,6,"CONSULTA DE DATOS");
	   escriba(31,8,"1- CONSULTA DE CONCEPTOS DE INVENTARIOS");
	   escriba(31,9,"2- CONSULTA DE DATOS BASICOS DE PRODUCTOS  ");
	   escriba(31,10,"3- CONSULTA DE MOVIMIENTOS ");
	   escriba(31,11,"4- CONSULTA DE CENTROS");
	   escriba(31,12,"5- SALIR");
	   escriba(28,13,"ELIJA UNA OPCION [ ]");
	   gotoxy(46,13);op=getch();
	   switch(op)
	   {
	      case '1':
			con.mostrar_conceptos();
			break;
	      case '2':
			pro.mostrar_productos();
			break;
	      case '3': 		
			mov.mostrar_movimientos();
			break;
	      case '4':		
			cen.mostrar_centros();
			break;
	      case '5':
			break;
	    }
	  }while(op!='5');

}




void conceptos::mostrar_conceptos()
{
     int entre=0,y=4;
     clrscr();
     escriba(35,1,"CONCEPTOS");
     escriba(12,3,"CODIGO                 DESCRIPCION                   TIPO");
     for(int i=0;i<=reg_con; i++)
     {
	  gotoxy(12,y);
	  cout<<cpto[i].cod;
	  gotoxy(36,y);
	  cout<<cpto[i].des;
	  gotoxy(66,y); 
	  cout<<cpto[i].tip;
	  entre=1;
	  y++; 

     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE LISTA !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     getch();
}


void productos::mostrar_productos()
{
     int entre=0,y=4;
     clrscr();
     escriba(35,1,"PRODUCTOS");
     escriba(4,3,"CODIGO        NOMBRE         UNIDAD          VLR.COMPRA          VLR.VENTA");
     for(int i=0;i<reg_pro; i++)
     {
	  gotoxy(4,y);
	  cout<<prod[i].cod;
	  gotoxy(18,y);
	  cout<<prod[i].nom;
	  gotoxy(35,y); 
	  cout<<prod[i].unidad;
	  gotoxy(52,y); 
	  cout<<prod[i].vlrcom;
	  gotoxy(72,y); 
	  cout<<prod[i].vlrven;

	  entre=1;
	  y++; 

     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE LISTA !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     getch();


}


void mvtos::mostrar_movimientos()
{
     int entre=0,y=4;
     clrscr();
     escriba(35,1,"  MOVIMIENTOS");
     escriba(2,3,"DOCUMENTO     PRODUCTO      CONCEPTO      CENTRO      CANTIDAD      VALOR");
     for(int i=0;i<reg_mov; i++)
     {
	  gotoxy(3,y);
	  cout<<mvt[i].doc;
	  gotoxy(16,y);
	  cout<<mvt[i].pro;
	  gotoxy(30,y); 
	  cout<<mvt[i].cpt;
	  gotoxy(44,y); 
	  cout<<mvt[i].cen;
	  gotoxy(56,y); 
	  cout<<mvt[i].cant;
	  gotoxy(70,y); 
	  cout<<mvt[i].vlrmvto;
	  entre=1;
	  y++; 

     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE LISTA !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     getch();

}


void centros::mostrar_centros()
{
     int entre=0,y=4;
     clrscr();
     escriba(35,1,"CENTROS");
     escriba(15,3,"CODIGO DE CENTRO              DESCRIPCION DE CENTRO");
     for(int i=0;i<reg_cen; i++)
     {
	  gotoxy(18,y);
	  cout<<cent[i].cod;
	  gotoxy(50,y);
	  cout<<cent[i].des;
	  entre=1;
	  y++; 

     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE LISTA !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     getch();
    


}



/***********************MOVIMIENTO******************************/

void digitacion_de_movimientos()
{
      mvtos mt;
      char op;
      do{
	 clrscr();
	 textcolor(10);
	 escriba(12,6," ===========================================================");
	 escriba(20,7," L A C T E O S  D E L   C A R I B E  LTDA. ");
	 escriba(21,8,"         MOVIMIENTOS  ");
	 escriba(12,11," ===========================================================");  
	 escriba(12,13," Numero de Documento :  ");
	 escriba(12,14," Codigo de Producto  :          [                       ] ");
	 escriba(12,15," Centro de Costo     :          [                       ] ");
	 escriba(12,16," Tipo de Cocepto     :          [                       ] ");
	 escriba(12,17," Cantidad            :  ");
	 escriba(12,18," Valor Unitario      :  ");
	 escriba(12,19,"===========================================================");
	 escriba(4,21,"[1] ADICIONAR    [2] CONSULTAR   [3] MODIFICAR  [4]SALIR ");
	 escriba(4,23,"DIGITE SU OPCION [ ]");
	 gotoxy(22,23);
	 op=getch();
	 switch(op)
	 {
	      case '1': mt.crear();
			break;

	      case '2': mt.consultar();	
			break;


	      case  '3': mt.modificar();
			 break;


	      case  '4': 
			 break;
			  
	  }	
	}while(op!='5');


}

void mvtos::crear()
{
  conceptos con;
  productos pro;
  centros cen;
  char cod[10],produ[10],conce[3],cent[5];
  int entre=0,sw;
  float venta;
  escriba(15,10,"OPCION (1). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      venta=0;
      ex=0;
      gotoxy(34,13);
      clreol();
      gotoxy(34,14);
      clreol();
      gotoxy(34,15);
      clreol();
      gotoxy(34,16);
      clreol();
      gotoxy(34,17);
      clreol();
      gotoxy(34,18);
      clreol();
      gotoxy(4,23);
      clreol();
      gotoxy(44,14);
      cout<<"[                       ]";
      gotoxy(44,15);
      cout<<"[                       ]";
      gotoxy(44,16);
      cout<<"[                       ]";
      gotoxy(34,13);cin>>cod;	  
      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_mov; i++)
     {
      if(strcmp(cod,mvt[i].doc)==0)
      {
	   textcolor(128+10);escriba(59,9,"! YA EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
	   entre=1;
      }
     }
     if(entre==1)
      continue;
      strcpy(mvt[reg_mov].doc,cod);
      do{
	   gotoxy(34,14);
	   clreol();
	   gotoxy(44,14);
	   cout<<"[                       ]";
	   gotoxy(34,14);
	   gets(produ);
	   sw=pro.busca_productos(produ,venta);
	   if(sw==0)
	   {
	      textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	      delay(2000);
	      textcolor(10);
	      gotoxy(59,9);
	      clreol();
	   }
	 }while(sw==0);
      strcpy(mvt[reg_mov].pro,produ);
      do{
	   gotoxy(34,15);
	   clreol();
	   gotoxy(44,15);
	   cout<<"[                       ]";
	   gotoxy(34,15);
	   gets(cent);
	   sw=cen.busca_centros(cent);
	   if(sw==0)
	   {
	      textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	      delay(2000);
	      textcolor(10);
	      gotoxy(59,9);
	      clreol();
	   }

	 }while(sw==0);
      strcpy(mvt[reg_mov].cen,cent);
      do{
	   gotoxy(34,16);
	   clreol();
	   gotoxy(44,16);
	   cout<<"[                       ]";
	   gotoxy(34,16); 
	   gets(conce); 
	   sw=con.busca_conceptos(conce);
	   if(sw==0)
	   {
	      textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	      delay(2000);
	      textcolor(10);
	      gotoxy(59,9);
	      clreol();
	   }

	 }while(sw==0);
      strcpy(mvt[reg_mov].cpt,conce);
      gotoxy(34,17);
      cin>>mvt[reg_mov].cant;
      ex=mvt[reg_mov].cant;
      gotoxy(34,18);
      cin>>venta;
      mvt[reg_mov].vlrmvto=venta;
      pro.busca_productos(produ,venta);
      reg_mov++;
  }
}


int productos::busca_productos(char produ[],float ven)
{
     int exis=0;
     for(int i=0;i<=reg_pro; i++)
     {
      if(strcmp(produ,prod[i].cod)==0)
      {
	 gotoxy(50,14);
	 cout<<prod[i].nom;
	 if(tipo==1)
	 {
	   prod[i].vlrcom+=ven;
           prod[i].existencia=prod[i].existencia+ex;
	 }
	 if(tipo==0)
	 {
	   prod[i].vlrven+=ven;
           prod[i].existencia=prod[i].existencia-ex;
	 }
	 exis=1;
	 break;
      }
     }
     return(exis);

}

int centros::busca_centros(char cen[])
{
     int ex=0;
     for(int i=0;i<=reg_cen; i++)
     {
      if(strcmp(cen,cent[i].cod)==0)
      {
	 gotoxy(50,15);
	 cout<<cent[i].des;
	 ex=1;
	 break;
      }
     }
     return(ex);

}

int conceptos::busca_conceptos(char co[])
{
     int exi=0,n;
     for(int i=0;i<=reg_con; i++)
     {
      if(strcmp(co,cpto[i].cod)==0)
      {
	 if(strrchr(cpto[i].tip,'D')!=NULL)
	 {
           gotoxy(50,16);
           cout<<"DE CONTADO";
	   tipo=1;
	 }
	 if(strrchr(cpto[i].tip,'C')!=NULL)
	 {
           gotoxy(50,16);
           cout<<"CREDITO";
	   tipo=0;
	 }

	 exi=1;
	 break;
      }
     }
     return(exi);

}





void mvtos::consultar()
{
  char cod[10];
  int entre=0;
  escriba(15,10,"OPCION (2). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(34,13);
      clreol();
      gotoxy(34,14);
      clreol();
      gotoxy(34,15);
      clreol();
      gotoxy(34,16);
      clreol();
      gotoxy(34,17);
      clreol();
      gotoxy(34,18);
      clreol();
      gotoxy(4,23);
      clreol();
      gotoxy(44,14);
      cout<<"[                       ]";
      gotoxy(44,15);
      cout<<"[                       ]";
      gotoxy(44,16);
      cout<<"[                       ]";
      gotoxy(34,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_mov; i++)
     {
      if(strcmp(cod,mvt[i].doc)==0)
      {
	  gotoxy(34,14);
	  cout<<mvt[i].pro;
	  gotoxy(34,15); 
	  cout<<mvt[i].cen;
	  gotoxy(34,16); 
	  cout<<mvt[i].cpt;
	  gotoxy(34,17); 
	  cout<<mvt[i].cant;
	  gotoxy(34,18); 
	  cout<<mvt[i].vlrmvto;
	  entre=1;
	  getch();
	  break;
      }
     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
	   textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
  }

}


void mvtos::modificar()
{
/*
  char cod[10],op,c;
  char no[30];
  char un[15];
  char cn[5];
  float vven;
  float exis;

  int entre=0;
  escriba(15,10,"OPCION (3). Para salir digite (*) en codigo");
  while(1)
  {
      entre=0;
      gotoxy(34,13);
      clreol();
      gotoxy(34,14);
      clreol();
      gotoxy(34,15);
      clreol();
      gotoxy(34,16);
      clreol();
      gotoxy(34,17);
      clreol();
      gotoxy(28,18);
      clreol();
      gotoxy(4,23);
      clreol();
      gotoxy(34,13);cin>>cod; 

      if(cod[0]=='*')
       break;

     for(int i=0;i<=reg_mov; i++)
     {
       if(strcmp(cod,mvto[i].doc)==0)
       {
	 gotoxy(34,14);
	 cout<<mvto[i].pro;
	 gotoxy(34,15); 
	 cout<<mvto[i].cen; 
	 gotoxy(34,16); 
	 cout<<mvto[i].cpt;
	 gotoxy(34,17); 
	 cout<<mvto[i].cant;
	 gotoxy(34,18); 
	 cout<<mvto[i].vlrmvto;
	 escriba(4,21,"DESEA MODIFICARLO ?(S/N) ");
         op=toupper(getch());
         if(op=='S')
         {
	   strcpy(mvto[i].doc,cod);
	   gotoxy(34,14);
	   strcpy(no,mvto[i].pro);
	   c=getch();
	   if(c!='\r')
	   {
	      gotoxy(34,14);
	      clreol();
	      gets(no);
	   }
	   strcpy(mvto[i].pro,no);
	   gotoxy(34,15); 
	   strcpy(un,mvto[i].cen);
	   c=getch();
           if(c!='\r')
           {
	      gotoxy(34,15);
	      clreol();
	      gets(un);
           }
	   strcpy(mvto[i].cen,un);
	   gotoxy(34,16); 
	   strcpy(cn,mvto[i].cpt);
	   c=getch();
           if(c!='\r')
           {
	       gotoxy(34,16);
	       clreol();
	       gets(cn);
	   }
	   strcpy(mvto[i].cen=cn);   
	   gotoxy(34,17); 
	   vven=mvto[i].cant;
	   c=getch();
	   if(c!='\r')
	   {
	      gotoxy(34,17);
	      clreol();
	      cin>>vven;
           }
	   mvto[i].cant=vven;   
	   gotoxy(34,18);
	   exis=mvto[i].vlrmvto;
	   c=getch();
	   if(c!='\r')
	   {
	      gotoxy(34,18);
	      clreol();
	      cin>>exis;
           }
	   mvto[i].vlrmvto=exis;   
	   entre=1;
           break;
         }
         if(op=='N')
         {
           textcolor(128+10);escriba(50,9,"! MODIFICACION NO EFEUTUADA !");
	   delay(2000);
           textcolor(10);
	   gotoxy(50,9);
	   clreol();
           entre=2;
           break;
         }
       }
     }
     if(entre==0)
     {
	   textcolor(128+10);escriba(59,9,"! NO EXISTE !");
	   delay(2000);
           textcolor(10);
	   gotoxy(59,9);
	   clreol();
     }
     if(entre==1)
     {
           textcolor(128+10);escriba(54,9,"! FUE MODIFICADO !");
	   delay(2000);
           textcolor(10);
	   gotoxy(54,9);
	   clreol();
     }

 }

  */

}
void mvtos::retirar()
{

}





/************************INFORME*******************************/

void informes()
{
	char op;
	clrscr();
	do{
	   clrscr();
	   escriba(32,7,"INFORME");
	   escriba(31,9,"1- ESTADISTICO PRODUCTOS 1 ");
	   escriba(31,10,"2- ESTADISTICO PRODUCTOS 2  ");
	   escriba(31,11,"3- SALIR");
	   escriba(28,13,"ELIJA UNA OPCION [ ]");
	   gotoxy(46,13);op=getch();
	   switch(op)
	   {
	      case '1':
			estadistico_producto1();
			break;
	      case '2':
			estadistico_producto2();
	      case '3':
			break;
	    }
	  }while(op!='3');

}


void estadistico_producto1()
{
}


void estadistico_producto2()
{
}





void  main ()     
{
      clrscr();
      menu_principal();
}