#include <stdio.h>
#include <conio.h>
struct {
     char codigo[10];
     char nombre [40];
     char apellido[40];
     char telefono [25];
     char direccion [25];
     char fecha [10];
     float valor;
}  empleado [200];
long float g;
void captura (char cod_para[], int t,int opcion, int x, int y),capt_codi(char cod_para[], int t);
 void datos();
 void ver();
 void promedio();
 void modificar();
 void menu();
 void eliminar();
 void menuOrdenar();
   char cod[10],nomb[40],apel[40],dir[25],tel[25],fec[10];
    int sw,max=0;
    int i=0;

   long float vlr;
//programa principal
  void main()
{
  menu();
}// fin de programa
  void datos()
{
  int j;
  char op;
  float  auxf;
  int k,h;
textbackground(9);
do
{
      clrscr();
/******************************ADICIONAR*************/
      textbackground(3);
      textcolor(13);
      gotoxy(8,2);
      cprintf("CODIGO    :");
      captura(empleado[i].codigo,9,1,19,2);
      gotoxy(8,3);
      cprintf("NOMBRE    : ");
      captura (empleado [i].nombre,39,2,19,3);
      gotoxy(8,4);
      cprintf("APELLIDO  :");
      captura(empleado [i].apellido,39,2,19,4);
      gotoxy(8,5);
      cprintf("TELEFONO  :");
      captura(empleado[i].telefono,24,1,19,5);
      gotoxy(8,6);
      cprintf("DIRECCION :");
      captura(empleado[i].direccion,24,3,19,6);
      gotoxy(8,7);
      cprintf("FECHA     :");
      captura (empleado[i].fecha,9,3,19,7);
      gotoxy(8,8);
      cprintf("VALOR     :");
      scanf("%lf",&g);
      empleado [i].valor=g;
      gotoxy(8,24);
      cprintf ("DESEA ADICIONAR OTRO EMPLEADO..\n");
      op=toupper(getche());
      if(op=='S'){ i++;}
 } while (op=='S');
ver();
}
/************************VISUALIZAR*************************/
 void ver(){
 int j;
 clrscr();
 for (j=0;j<=i;j++)
 {
      printf("%s\n", empleado[j].codigo);
      printf("%s\n", empleado[j].nombre);
      printf("%s\n", empleado[j].apellido);
      printf("%s\n", empleado[j].direccion);
      printf("%d\n", empleado[j].telefono);
      printf("%d\n", empleado[j].fecha);
      printf("%lf\n", empleado[j].valor);
      cprintf("************************************\n");

 
 }
 getche();
 menu();
 }
 /*****************************/
void cuadros(int x1,int x2,int y1,int y2)
    {
     int j,i,k;clrscr();
     textcolor(3);textbackground(13);
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
     textcolor(14);textbackground(3);

   }

void menu()  
      {
      int tecla;
       int f;
       char opc[16][60];
      do {
		strcpy(opc[10]," ADICIONAR DATOS      ");
		strcpy(opc[11]," ELIMINAR ELEMENTOS   ");
		strcpy(opc[12]," MODIFICAR ELEMENTOS  ");
		strcpy(opc[13]," ORDENAR LOS LISTADOS ");
		strcpy(opc[14]," PROMEDIO DE VALORES  ");
		strcpy(opc[15]," SALIR DEL MENU       ");

		clrscr();
		textcolor(14);textbackground(13);
		cuadros(16,50,8,17);
		textcolor(14);textbackground(13);

		for(f=10;f<=15;f++)
		 {  gotoxy(20,f);cprintf("%s",opc[f]);}
		    f=10;
		    textcolor(3);textbackground(7);
		    gotoxy(20,f);cprintf("%s",opc[f]);
		    textcolor(15);textbackground(3);

		 do {
		     do {tecla=getch();} 
			while((tecla==80)&&(tecla==72)&&(tecla==13));

		     if(tecla==80)
		       {   textcolor(14);textbackground(0);
			   gotoxy(20,f);cprintf("%s",opc[f]);

			  if (f!=15)
			    { f++;
			      textcolor(0); textbackground(7);
			      gotoxy(20,f);  cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			    }
			else
			    { f=10;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f);cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			    }
			}

		     if(tecla == 72)
			{  textcolor(14);textbackground(0);
			   gotoxy(20,f);cprintf("%s",opc[f]);

			   if (f!=10)
			    { f--;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f); cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			    }
			else
			    { f=15;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f); cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			     }
			    }
	     }while(tecla!=13);

		     switch(f)
		     {
		      case  10 :datos() ; break;
		      case  11 :eliminar() ; break;
		      case  12 :modificar(); break;
		      case  13 :menuOrdenar(); break;
		      case  14 :promedio(); break;
		     }

   }while(f !=15);
  } //Fin del menu

  void menuOrdenar()  

	  {
	    int tecla;
	     int f;
	     char opc[15][60];

	    do {
		strcpy(opc[10]," ORDENAR POR CODIGO DE USUARIO   ");
		strcpy(opc[11]," ORDENAR POR NOMBRE DEL USUARIO  ");
		strcpy(opc[12]," ORDENAR POR APELLIDO DE USUARIO ");
		strcpy(opc[13]," SALIR DEL MENU       ");

		clrscr();
		textcolor(14);textbackground(13);
		cuadros(16,55,8,15);
		textcolor(14);textbackground(13);

		for(f=10;f<=13;f++)
		 {  gotoxy(20,f);cprintf("%s",opc[f]);}
		    f=10;
		    textcolor(0);textbackground(7);
		    gotoxy(20,f);cprintf("%s",opc[f]);
		    textcolor(14);textbackground(0);

		 do {
		     do {tecla=getch();} 
			while((tecla==80)&&(tecla==72)&&(tecla==13));

		     if(tecla==80)
		       {   textcolor(14);textbackground(0);
			   gotoxy(20,f);cprintf("%s",opc[f]);

			  if (f!=13)
			    { f++;
			      textcolor(13); textbackground(7);
			      gotoxy(20,f);  cprintf("%s",opc[f]);
			      textcolor(14);textbackground(13);
			    }
			else
			    { f=10;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f);cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			    }
			}

		     if(tecla == 72)
			{  textcolor(14);textbackground(0);
			   gotoxy(20,f);cprintf("%s",opc[f]);

			   if (f!=10)
			    { f--;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f); cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			    }
			else
			    { f=13;
			      textcolor(0);textbackground(7);
			      gotoxy(20,f); cprintf("%s",opc[f]);
			      textcolor(14);textbackground(0);
			     }
			    }
	     }while(tecla!=13);

		     switch(f)
		     {
		      case  10 : ; break;
		      case  11 : ; break;
		      case  12 : ; break;
		      case  13 : ; break;
   }
   }while(f !=13);
  } //Fin del menu de consultas
/***************************MODIFICAR**************/
void modificar()
{
char codigo[10];
clrscr();
printf(" DIGITE EL CODIGO ");
gets(codigo);sw=0;
for (i=1; i<=max;i++)
 if(strcmp(codigo,empleado[i].codigo)==0)
 {   sw=1;break;  }
   if (sw==0) printf (" NO EXISTE  ");
     else
      {
	 printf(" DIGITE EL NOMBRE ");
	 gets (empleado[i].nombre);
	 printf(" DIGITE EL APELLIDO ");
	 gets (empleado[i].apellido);
	 printf (" DIGITE EL TELEFONO ");
	 gets (empleado[i].telefono);
	 printf (" DIGITE LA DIRECCION ");
	 gets (empleado[i].direccion);
	 printf (" DIGITE FECHA ");
	 gets (empleado[i].fecha);
	 printf  (" DIGITE EL VALOR ");
	 scanf ("%f",&empleado[i].valor);
	 }
	 getche();
	 }
/***************/
 void captura(char cod_para[],int t,int opcion,int x,int y){
    char c='';
    int n=0;
    gotoxy(x,y);
    switch(opcion)
    {
        case 1:
		while ((c!='\r') && (n<t))
		 {			
		        c=getche();
		         if(isdigit(c)){
			    cod_para[n]=c;
			     n++;
			  }
			 else{
			 gotoxy(x+n,y);
			 clreol();
		     }
		   }
		   cod_para[n]='\0';
		    
		    break;
         case 2:
		while ((c!='\r') && (n<t))
		 {			
		        c=getche();
		         if(isalpha(c) || (c == ' ')){
			    cod_para[n]=c;
			     n++;
			  }
			 else{
			 gotoxy(x+n,y);
			 clreol();
		     }
		   }
		   cod_para[n]='\0';
		   break;

	       
	     case 3:     
	      while ((c!='\r') && (n<t))
		 {			
			c=getche();
		    cod_para[n]=c;
		     n++;
		   }
		   cod_para[n]='\0';
		   break;
	      }


 }
/***********************ORDENAR*************************/
void ordenar()
{
int j=i=0;
while(i!=200)
{ 
   while(j!=199)
   {
   j++;
       if(strcmp(empleado[i].codigo,empleado[j].codigo)>0)
       {    
	    strcpy(cod,empleado[j].codigo);
	    strcpy(nomb,empleado[j].nombre);
	    strcpy(apel,empleado[j].apellido);
	    strcpy(tel,empleado[j].telefono);
	    strcpy(dir,empleado[j].direccion);
	    strcpy(fec,empleado[j].fecha);
	    vlr=empleado[j].valor;

	    strcpy(empleado[j].nombre,empleado[i].nombre);
	    strcpy(empleado[j].codigo,empleado[i].codigo);
	    strcpy(empleado[j].apellido,empleado[i].apellido);
	    strcpy(empleado[j].telefono,empleado[i].telefono);
	    strcpy(empleado[j].direccion,empleado[i].direccion);
	    strcpy(empleado[j].fecha,empleado[i].fecha);
	    empleado[j].valor=empleado[i].valor;

	    strcpy(empleado[i].apellido,apel);
	    strcpy(empleado[i].codigo,cod);
	    strcpy(empleado[i].nombre,nomb);
	    strcpy(empleado[i].telefono,tel);
	    strcpy(empleado[i].direccion,dir);
	    strcpy(empleado[i].fecha,fec);
	    empleado[i].valor=vlr;	    
       }
   }
 i++;
}
}
/**********************ELIMINAR******************/
void eliminar()
{
int j=0,i=0;
     clrscr();
  printf(" DIGITE EL CODIGO DESEADO ");
   gets(cod); sw=0;
    for(i=1;i<=max;i++)
     if (strcmp (cod,empleado[i].codigo)==0)
     {
      sw=1; break;
      }
      if(sw==0) printf (" NO EXISTE ");
       else
       {
	for(j=i; j<max; j++)
	 empleado [j]=empleado [j+1];
	  max--;
	  }
	   getche();
	   }
/*****************PROMEDIO***********************/
void promedio()
{
int i,j;
float prom;
clrscr();
while (j!=0)
{
 j++;
 for(i=1;i>j;i++)
 {
   prom=prom+ (vlr,empleado[i].valor);
   
   }
   prom=prom/j;
 }
 i++;
 getche();
 }









