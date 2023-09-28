#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<alloc.h>
#include<iostream.h>
void marcar();
void marco(); 
void cuadros();
class parcial2
{
  struct pacho{
  char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
  struct pacho *ant;
  struct pacho *sig;

 };

 public:
 char cod[10],op;
  char nom[40];
  int cant;
  int depe,sw;
  long int valor; 
  pacho *nn,*p,*ptr;
  void adicionar();
  void visualizar();
  void menu();
  void eliminar();
  void dep_alm();
  void consultar_cod();
  void consultar_admon();
  void consultar_rech(); 
  void consultar();
  parcial2(pacho *l){ptr=l;}
  char valido;
  int lon;
  int entero(int x,int y);
  int largo(int x,int y);

};
///////////////////////////////////////////////////////////////////
void marcar(int c1,int f1,int c2,int f2,int fondo)

{
   int i1,i2;
       switch(fondo)
       {
	  case 1: fondo=176; break;

	  case 2: fondo= 177;break;

	  case 3: fondo= 178;break;

	  case 4: fondo= 32;break;

	    default:
			fondo= 32;


	  }

	   for(i1=f1;i1<=f2;i1++)

	   for(i2=c1;i2<=c2;i2++)
	       {

		 gotoxy(i2,i1);
		 cprintf("%c",fondo);

		 }

	    }

/////////////////////////////////////////////////////////////////////////////
void  marco(ci,cf,fi,ff)
{
 int i;
 textcolor(1);textbackground(14);
 for(i=ci;i<=cf;i++)
 {
  delay(4); gotoxy(i,fi); printf("Õ");
  delay(4); gotoxy(i,ff); printf("Õ");
  }
 for(i=fi;i<=ff;i++)
 {
  delay(4); gotoxy(ci,i); printf("∫");
  delay(4); gotoxy(cf,i); printf("∫");
  }
 gotoxy(ci,fi); printf("…");
 gotoxy(ci,ff); printf("»");
 gotoxy(cf,fi); printf("ª");
 gotoxy(cf,ff);
 printf("º");
 textcolor(14); textbackground(0);
 }
/////////////////////////////////////////////////////////////////
void cuadros(int x1, int y1, int x2, int y2)
{
  int i;
  for(i=x1;i<=x2;i++)
  {
    gotoxy(i,y1); cprintf("ﬂ");
    gotoxy(i,y2); cprintf("‹");
  }

  for(i=y1;i<=y2;i++)
  {
    gotoxy(x1,i); cprintf("€");
    gotoxy(x2,i); cprintf("€");
  }

}


///////////////////////////////////////////
int parcial2::entero(int x,int y)
{ char *cad;
  int n,sw,j;

      
do
  { 
 
    gotoxy(x,y);sw=0;
   (35,10);textcolor(14);textbackground(0); 
    textcolor(14);textbackground(0);
    clreol();
    scanf("\n");gets(cad);
    n=strlen(cad);
    for(j=0;j<n;j++)
    if(!isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
  return(atoi(cad));
} 
//////////////////////////////////////////////
 int parcial2::largo(int x,int y)
{ char *cad;
  int n,sw,j;

      
do
  { gotoxy(x,y);sw=0;

(35,11);textcolor(14);textbackground(0); 
    textcolor(14);textbackground(0);
   clreol();
   scanf("\n");gets(cad);
   n=strlen(cad);
   for(j=0;j<n;j++)
    if(!isdigit(cad[j])){ sw=1; break;}
  }while(sw==1);
   return(atol(cad));
} 




//////////////////////////////////////////////////////////////////
void parcial2::menu()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[11],"ADICIONAR     ");
 strcpy(opciones[12],"CONSULTAR     ");
 strcpy(opciones[13],"ELIMINAR      ");
 strcpy(opciones[14],"VISUALIZAR    ");
 strcpy(opciones[15],"SALIR         ");

do
 {
 
 clrscr();
 
 textbackground(15);
 gotoxy(4,3);textcolor(128+12); 
 delay(14);gotoxy(4,3);cprintf("€ ");
 textbackground(15);
 gotoxy(5,4);textcolor(128+2); 
 delay(14);gotoxy(5,4);cprintf("€ ");
 textbackground(7);
 gotoxy(6,5);textcolor(128+5);  
 delay(14);gotoxy(6,5);cprintf("€ ");
 textbackground(7);
 gotoxy(7,6);textcolor(128+7);  
 delay(14);gotoxy(7,6);cprintf("€ ");
 textbackground(3);
 gotoxy(8,7);textcolor(128+9);  
 delay(14);gotoxy(8,7);cprintf("€ ");  
 textbackground(3);
 gotoxy(9,8);textcolor(128+14);  
 delay(14);gotoxy(9,8);cprintf("€ ");  
 textbackground(5);
 gotoxy(11,8);textcolor(128+4);  
 delay(14);gotoxy(11,8);cprintf("€ ");  
 textbackground(4);
 gotoxy(13,8);textcolor(128+8);  
 delay(14);gotoxy(13,8);cprintf("€ ");  
 gotoxy(19,9);cprintf("MENU PRINCIPAL ");
 textbackground(15);
 gotoxy(13,17);textcolor(128+12); 
 delay(14);gotoxy(13,17);cprintf("€ ");
 textbackground(5);
 gotoxy(11,17);textcolor(128+2); 
 delay(14);gotoxy(11,17);cprintf("€ ");
 textbackground(7);
 gotoxy(9,17);textcolor(128+5);  
 delay(14);gotoxy(9,17);cprintf("€ ");
 textbackground(7);
 gotoxy(8,18);textcolor(128+7);  
 delay(14);gotoxy(8,18);cprintf("€ ");
 textbackground(3);
 gotoxy(7,19);textcolor(128+9);  
 delay(14);gotoxy(7,19);cprintf("€ ");  
 textbackground(3);
 gotoxy(6,20);textcolor(128+14);  
 delay(14);gotoxy(6,20);cprintf("€ ");  
 textbackground(5);
 gotoxy(5,21);textcolor(128+4);  
 delay(14);gotoxy(5,21);cprintf("€ ");  
 textbackground(14);
 gotoxy(4,22);textcolor(128+8);  
 delay(14);gotoxy(4,22);cprintf("€ ");  
  textcolor(14);  
 textcolor(7); textbackground(0);
 cuadros(39,5,62,14);
 marco(39,62,5,14);
 textcolor(14);                               
     delay(14);gotoxy(40,6);cprintf ("   ‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹‹   ");
     delay(14);gotoxy(40,7);cprintf ("   €€   €€ €€€ €€€€   ");
     delay(14);gotoxy(40,8);cprintf ("   €€ €€€   €   €€€   ");    
     delay(14);gotoxy(40,9);cprintf ("   €€ €€€€ €€€ €€€€   ");
     delay(14);gotoxy(40,10);cprintf("   €€‹‹‹€€‹€€€‹€€€€   ");
     delay(14);gotoxy(40,11);cprintf("     €     €‹‹‹‹€     ");    
     delay(14);gotoxy(40,12);cprintf("     €‹‹‹‹‹€‹‹‹‹€     ");
     delay(14);gotoxy(40,13);cprintf("                      ");    

                                                           
 textcolor(14); textbackground(0);
 cuadros(18,10,35,16);
 marco(18,35,10,16);
 textcolor(14); textbackground(0);
 cuadros(2,2,78,24); 
 marco(2,78,2,24);
 textcolor(14); textbackground(0);
 for(f=11; f<=15;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=11;
  textcolor(1); textbackground(0);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(0);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(3);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=15)
     f=f+1;
     else

    f=11;

    textcolor(14);textbackground(0);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(15);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=11)
   f=f-1;
   else

    f=15;
    textcolor(14);textbackground(3);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(3);

  }
  }
   while(tecla!=13);


 switch(f)
 {
 case 11: adicionar();break;
 case 12: consultar();break; 
 case 13: eliminar(); break;
 case 14: visualizar(); break;
 case 15: default:printf("FINAL");
 }

}
 while(f!=15);
}

////////////////////////////////////////
void parcial2::consultar()
{
 int tecla,f,i;
 char opciones[25][45];
 strcpy(opciones[19], "CONSULTAR POR CODIGO           ");
 strcpy(opciones[20], "CONSULTAR POR RECURSOS HUMANOS ");
 strcpy(opciones[21], "CONSULTAR POR DPTO ADMON       ");
  strcpy(opciones[22],"CONSULTAR POR DPTO ALMACEN     ");
 strcpy(opciones[23], "REGRESAR AL MENU PRINCIPAL     ");


do
 {
 gotoxy(39,17);printf("MENU CONSULTAR "); 
   textcolor(14);textbackground(1);
   cuadros(35,5,72,9);
  
     textcolor(14+14);                               
     delay(14);gotoxy(36,6);cprintf("  ‹      ‹   ‹‹‹‹  ‹‹‹  ‹‹‹   ‹‹‹‹  ");
     delay(14);gotoxy(36,7);cprintf("  €      €   €‹‹‹   €   €‹€   €‹‹‹  ");
     delay(14);gotoxy(36,8);cprintf("  €‹‹‹   €   ‹‹‹€   €   € €   ‹‹‹€  ");    

 gotoxy(39,17);cprintf("MENU CONSULTAR "); 
 textcolor(14); textbackground(0);
 cuadros(18,18,51,24);
 marco(18,51,18,24);
 textcolor(14); textbackground(0);
 cuadros(2,2,80,24); 
 marco(2,80,2,24);
 textcolor(12); textbackground(8);
 for(f=19; f<=23;f++)
 {
  gotoxy(20,f); cprintf(opciones[f]);
  }
  f=19;
  textcolor(0); textbackground(15);
  gotoxy(20,f); cprintf(opciones[f]);
  textcolor(14); textbackground(1);
 do
 {
  do
  { tecla=getch(); }
     while((tecla!=80)&&(tecla!=72)&&(tecla!=13));
    if (tecla==80)
    {
     textcolor(14);textbackground(1);
     gotoxy(20,f);cprintf(opciones[f]);
     if(f!=23)
     f=f+1;
     else

    f=19;

    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(1);

  }
  if(tecla==72)
  {
   textcolor(14);textbackground(1);
   gotoxy(20,f);cprintf(opciones[f]);
   if(f!=19)
   f=f-1;
   else

    f=23;
    textcolor(0);textbackground(15);
    gotoxy(20,f);cprintf(opciones[f]);
    textcolor(14);textbackground(0);

  }
  }
   while(tecla!=13);


 switch(f)
 {                     


 case 19: consultar_cod(); break;
 case 20: consultar_rech (); break;
 case 21: consultar_admon (); break;
 case 22: dep_alm();break;
 case 23: menu(); 

 }

}while(f!=23);
}
/////////////////////////////////////////////////////////////////////
void parcial2::adicionar()
{ char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
  int i,j,sw,st;
  char valido;
  int n;


do{

do 
{ clrscr();
   textcolor(14);textbackground(3);
   cuadros(2,2,80,24);
   textcolor(4);textbackground(3);
   cuadros(18,7,70,13);
   textcolor(6+128); textcolor(6+128);                                                             
   delay(14);gotoxy(20,4);cprintf("  ‹‹‹‹  ‹‹‹‹ ‹‹‹  ‹  ‹‹‹‹  ‹  ‹  ‹    ‹‹‹  ‹‹‹  ");
   delay(14);gotoxy(20,5);cprintf("  €‹‹€  €‹‹€  €   €  €     €  €  €    € €  €‹‹  ");
   delay(14);gotoxy(20,6);cprintf("  €  €  € €   €   €  €‹‹‹  €‹‹€  €‹‹  €‹€  ‹‹€  ");

        
         nn=new pacho;
         valido='n';
         gotoxy(20,8);cout<<"DIGITE EL CODIGO     :" ;gets(cod);
         n = strlen(cod);
         for(j=0;j<=n-1;j++)
	{
	 if(n>4)
	  {   textcolor(4);textbackground(3);
              cuadros(19,16,40,18);
              gotoxy(20,17);
	      cout<<"FUERA DE RANGO";
	      valido='m';
	      getch();
	      break;
	  }

	 else
	  {
	   if((!(isdigit(cod[j])))&&(!(isalpha(cod[j]))))
	    { textcolor(8);textbackground(3);
              cuadros(14,16,50,18);
              gotoxy(15,17);
	     textcolor(1);cout<<"LO SIENTO VIEJO ACCESO DENEGADO ";
	     valido='m';
	     getch();
	     break;   
            }
	   else
	    {
	     p=ptr;

	     while(p!=NULL)
	     {
	      if(strcmp(p->cod,cod)==0)
	       { textcolor(5);textbackground(15);
                cuadros(19,16,40,18);
                gotoxy(20,17);
		cout<<" CODIGO EXISTENTE";
		valido='m';
		getch();
		break;
	       }
	      p=p->sig;
	     }    
     	    }
	   }
	 }
    }while(valido=='m');

   strcpy(nn->cod,cod);
	   
  do
      {
	valido='n';
	gotoxy(42,9);
	cout<<"             ";
	gotoxy(20,9);cout<<"DIGITE EL NOMBRE     :" ;
        gotoxy(42,9);gets(nom);
        n=strlen(nom);
	for(j=0;j<=n-1; j++)
	  {
	   if(!(isalpha(nom[j])))
	    {textcolor(4);textbackground(3);
             gotoxy(20,17);
	     textcolor(128);cout<<"PULSE SOLO LETRAS";
	     valido='m';
	     getch();
	     gotoxy(20,17);
	     cout<<"                                 ";
	     break;
	    }
	  }
       }while(valido=='m');

  
   gotoxy(20,10);cout<<"DIGITE EL VALOR      :" ;
   valor=largo(42,10);   
   textcolor(14);textbackground(3); 
   cuadros(18,7,70,13); 
   gotoxy(20,11);cout<<"DIGITE LA CANTIDAD   :" ;
   cant=entero(42,11);    
   textcolor(14);textbackground(3); 
   cuadros(18,7,70,13); 
   textcolor(14);textbackground(3); 
   cuadros(33,13,55,18); 
   gotoxy(34,14);cout<<"OPCIONES :" ;
   gotoxy(34,15);cout<<"1.DPTO ALMACEN :" ;
   gotoxy(34,16);cout<<"2.RECURSOS HUM :" ;
   gotoxy(34,17);cout<<"3.DPTO ADMON   :" ;
   textcolor(14);textbackground(15);
   cuadros(2,2,80,24);
   textcolor(1);textbackground(15);
   textcolor(1+128); textcolor(1+128);                                                             
   delay(14);gotoxy(3,4);cprintf("     ‹‹‹‹  ‹‹‹  ‹‹‹  ‹‹‹ ‹‹‹  ‹‹‹‹  ‹‹‹  ‹‹‹‹  ‹‹‹  ‹  ‹‹‹  ‹‹‹            ");
   delay(14);gotoxy(3,5);cprintf("     €  €  €‹   €‹€  €‹  € €  €  €  €‹   €  €  €    €  €‹€  €‹‹            ");                                             
   delay(14);gotoxy(3,6);cprintf("     €‹‹€  €‹‹  €    €‹‹ € €  €‹‹€  €‹‹  €  €  €‹‹  €  € €  ‹‹€            ");
   gotoxy(20,12);cout<<"DEPENDENCIAS         :" ;
  do{
    depe=entero(42,12);;
    textcolor(14);textbackground(3); 
    cuadros(18,7,70,13); 
    textcolor(14);textbackground(3); 
  }while((depe!=1)&(depe!=2)&&(depe!=3));	
  
  
  strcpy(nn->nom,nom);
  nn->valor=valor; 
  nn->cant=cant;
  nn->depe=depe;
  nn->sig=nn->ant=NULL;
 
  if(ptr==NULL)
   ptr=nn;
   else
  
  {p=ptr;
   while(p->sig!=NULL)
   p=p->sig;
   p->sig=nn;
   nn->ant=p;
  }
  gotoxy(29,20);cout<<"..EXITOS VIEJO ";


  gotoxy(18,22);cout<<" DESEA ADICIONAR OTRO ARTICULO [S/N]";
  op=toupper(getche());
  }while(op!='N');

} 
////////////////////////////////////////////////////////////////////
void parcial2::visualizar()
{
int fill=6;
  
clrscr();
   textcolor(4);textbackground(14);
   cuadros(2,2,80,24);

 if(ptr==NULL)
	{gotoxy(25,8); cout<<"LISTA SIN PROCESAR   ";
          }
  else{
    gotoxy(3,7);cout<<"CODIGO       NOMBRE       VALOR       CANTIDAD       DEPENDENCIA";
    textcolor(8);textbackground(15);
    delay(14);gotoxy(15,3);cprintf("  ‹     ‹  ‹‹‹  ‹‹‹  ‹‹‹  ‹‹‹‹  ‹‹‹  ‹‹‹           ");
    delay(14);gotoxy(15,4);cprintf("  €     €  €‹‹   €   €‹€  €  €  € €  €‹‹           ");                                             
    delay(14);gotoxy(15,5);cprintf("  €‹‹   €  ‹‹€   €   € €  €‹‹€  €‹€  ‹‹€           ");

     textcolor(4);textbackground(15);    
     cuadros(2,2,80,6);
  p=ptr;

	  while(p!=NULL)
      {
       gotoxy(3,2+fill);cout<<p->cod;
       gotoxy(16,2+fill);cout<<p->nom;
       gotoxy(32,2+fill);cout<<p->valor;
       gotoxy(43,2+fill);cout<<p->cant;
       gotoxy(59,2+fill);cout<<p->depe;
	
	fill++;
	p=p->sig;
	
       }
     } 
gotoxy(20,22);printf("PULSE ENTER PARA REGRESAR");
getche();
}


///////////////////////////////////////////////////////////////
void parcial2::eliminar()
{ char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
  char op,sw1=0;

 
 clrscr();
    textcolor(4);textbackground(15);
   cuadros(2,2,80,24);
    textcolor(14);textbackground(3);
    delay(14);gotoxy(15,3);cprintf("  ‹‹‹   ‹     ‹   ‹‹‹‹‹‹‹   ‹   ‹‹‹‹‹   ‹‹‹‹   ‹‹‹‹        ");
    delay(14);gotoxy(15,4);cprintf("  €‹    €     €   €  €  €   €   €   €   €‹‹€   €‹‹€        ");                                             
    delay(14);gotoxy(15,5);cprintf("  €‹‹   €‹‹   €   €     €   €   €   €   €  €   € €         ");

  do{
  cuadros(17,14,60,16);
   gotoxy(18,15); cout<<" DESEA ELIMINAR EL PRIMER ARTICULO [S/N]";
  op=toupper(getche());
  }while((op!='N')&&(op!='S'));
 if(op=='S')
  { sw1=1;

  if(ptr==NULL)
   {gotoxy(20,6);cout<<" LISTA VACIA:" ;
    
     }
   else
     { p=ptr;
       ptr=p->sig;
       ptr->ant=p->sig=NULL;
        free(p);
      }
  
  
 }


} 

//////////////////////////////////////////////////////////////////////////
void parcial2::dep_alm()
 {char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
 

  clrscr();
  
   textcolor(4);textbackground(3);
   cuadros(2,2,80,24);
   textcolor(14);textbackground(15);
   textcolor(4);textbackground(15);
   cuadros(2,2,80,6);
   textcolor(4+128); textcolor(4+128);                                                             
   delay(14);gotoxy(3,3);cprintf(" ‹‹‹‹‹  ‹‹‹‹  ‹‹‹‹  ‹‹‹‹‹  ‹‹‹‹    ‹‹‹‹  ‹    ‹‹‹‹‹‹‹  ‹‹‹‹  ‹‹‹  ‹‹‹  ‹‹‹‹ ");
   delay(14);gotoxy(3,4);cprintf(" €   €  €‹    €‹‹€    €    €  €    €‹‹€  €    €  €  €  €‹‹€  €    €‹   €  € ");                                             
   delay(14);gotoxy(3,5);cprintf(" €‹‹‹€  €‹‹‹  €       €    €‹‹€ ‹  €  €  €‹‹  €     €  €  €  €‹‹  €‹‹  €  € ");
   

   p=ptr;
 
  while(p!=NULL)
  {if(p->depe==1)
   {textcolor(9);textbackground(15);
    cuadros(5,7,40,13);
  
    gotoxy(6,8);cout<<"CODIGO DEL ARTICULO:"<<p->cod;                                    
    gotoxy(6,9);cout<<"NOMBRE DEL ARTICULO:"<<p->nom;
    gotoxy(6,10);cout<<"VALOR DEL ARTICULO:"<<p->valor;
    gotoxy(6,11);cout<<"CANTIDAD DEL ARTICULO:"<<p->cant;
    gotoxy(6,12);cout<<"DEPENDENCIA DEL ARTICULO:"<<p->depe;
    getch(); 
    }

     p=p->sig;
   
}    
consultar(); 

 
}

//////////////////////////////////////////////////////////////////////

void parcial2::consultar_cod()
{
 char cod[10];
 int sw;
 sw=0;
do{

 clrscr();
  
   textcolor(7);textbackground(15);
   cuadros(2,2,80,24);
   textcolor(14);textbackground(15);
   cuadros(2,2,80,6);							
   delay(14);gotoxy(3,3);cprintf("                     ‹‹‹  ‹‹‹  ‹‹‹‹  ‹  ‹‹‹‹  ‹‹‹                            ");
   delay(14);gotoxy(3,4);cprintf("                     €    € €  €  €  €  € ‹‹  € €                            ");                                             
   delay(14);gotoxy(3,5);cprintf("                     €‹‹  €‹€  €‹‹€  €  €‹‹€  €‹€                            ");
 

 gotoxy(15,8);cout<<"DIGITE CODIGO A CONSULTAR:";
 cin>>cod;
 p=ptr;
 while(p!=NULL)
  {
   if(strcmp(p->cod,cod)==0)
   {
    
    
    cuadros(14,9,50,14);
    sw=1;
    gotoxy(15,10);cout<<"CODIGO DEL ARTICULO:"<<p->cod;
    gotoxy(15,11);cout<<"NOMBRE DEL ARTICULO:"<<p->nom;
    gotoxy(15,12);cout<<"VALOR DEL ARTICULO:"<<p->valor;
    gotoxy(15,13);cout<<"CANTIDAD DEL ARTICULO:"<<p->cant;
    gotoxy(15,12);cout<<"DEPENDENCIA DEL ARTICULO:"<<p->depe;
    getch();
   	
 }

   p=p->sig;
  }
    if(sw==0)
	  { textcolor(4);textbackground(15);
            cuadros(24,14,45,16);							
            gotoxy(25,15); cout<<"CODIGO SIN PROCESAR" ;
	   
	  }
    
  gotoxy(18,22);cout<<" DESEA CONSULTAR OTRO ARTICULO [S/N]";
  op=toupper(getche());
  }while(op!='N');

}
          
////////////////////////////////////////////////////////////////////

void parcial2::consultar_admon()
{
  char cod[10];
  char nom[40];
  long int va=0;
  
  int cant,cont=0;
  int depe;
clrscr();
 textcolor(14);textbackground(0);
   cuadros(2,2,80,24);
   cuadros(2,2,80,7);
   textcolor(14);textcolor(14);                                                              
   delay(14);gotoxy(4,4);cprintf("  ‹‹‹‹   ‹‹‹   ‹‹‹  ‹‹‹  ‹‹‹      ‹‹‹   ‹‹‹‹   ‹‹‹‹‹   ‹‹‹   ‹‹‹‹  ");
   delay(14);gotoxy(4,5);cprintf("  €  €   €‹    €‹€   €   € €      €‹€   €  €   € € €   € €   €  €  ");                                             
   delay(14);gotoxy(4,6);cprintf("  €‹‹€   €‹‹   €     €   €‹€   ‹  € €   €‹‹€   €   €   €‹€   €  €  ");
  
 
p=ptr;

  while(p!=NULL)
  {
   if(p->depe==3)
   {
    
    textcolor(7);textbackground(0);
    cuadros(14,8,45,14);
     va=(p->valor*p->cant)+va;
     cont++;
    
    
   }
   p=p->sig;
    
}
   
    gotoxy(15,11);cout<<"VALOR DEL ARTICULO:"<<va;
    gotoxy(15,12);cout<<"CANTIDAD DEL ARTICULO:"<<cont;

   consultar(); 

}
 
/***************************************************************************/
void parcial2::consultar_rech() 
{
  char cod[10];
  char nom[40];
  long int valor;
  int cant;
  int depe;
 

  clrscr();
  
    textcolor(14);textbackground(0);
    cuadros(2,2,80,24);
   textcolor(14);textbackground(0);
   textcolor(8+128); textcolor(3+128);                                                             
   delay(14);gotoxy(7,4);cprintf("  ‹‹‹‹  ‹‹‹  ‹‹‹  ‹‹‹ ‹‹‹  ‹‹‹‹  ‹‹‹  ‹‹‹‹  ‹‹‹  ‹  ‹‹‹  ‹‹‹   ");
   delay(14);gotoxy(7,5);cprintf("  €  €  €‹   €‹€  €‹  € €  €  €  €‹   €  €  €    €  €‹€  €‹‹   ");                                             
   delay(14);gotoxy(7,6);cprintf("  €‹‹€  €‹‹  €    €‹‹ € €  €‹‹€  €‹‹  €  €  €‹‹  €  € €  ‹‹€   ");

   p=ptr;
 
  while(p!=NULL)
  {if(p->depe==2)
   {
    textcolor(11);textbackground(0);
    cuadros(5,7,40,13);
        
    gotoxy(6,8);cout<<"CODIGO DEL ARTICULO:"<<p->cod;
    gotoxy(6,9);cout<<"NOMBRE DEL ARTICULO:"<<p->nom;
    gotoxy(6,10);cout<<"VALOR DEL ARTICULO:"<<p->valor;
    getch(); 
    }

     p=p->sig;
   
}    
consultar(); 

 
}

//////////////////////////////////////////////////////
void main()
{ clrscr();
 parcial2 objeto(NULL);
 objeto.menu();
}              


