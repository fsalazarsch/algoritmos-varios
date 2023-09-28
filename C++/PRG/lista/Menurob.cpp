#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "dos.h"
#include "ctype.h"
#define go {gotoxy(1,24);}
#define getnodo (tiponodo *) malloc(sizeof(tiponodo));
typedef struct nodo tiponodo;
struct nodo
{ int referencia;
   long punt;
tiponodo*sig;
};

struct registro
{int referencia ;
 char nombre [20];
 char color  [20];
 char talla [20];
 char valor [20];
 int activo;
 };
/**************************************************/
 FILE *ptr;
 tiponodo *s,*cab,*pq,*q,*nodo1;
 registro agenda;
void crear();
void listar();
void listarL();
void piso();
void eliminar();
void eliminar1();
void modificar();
void cargar(int ref,long punt);
buscar1(int re);
buscar(int ref);
void boli (int f1,int f2, int col1,int col2);
menu();
void cuad(int ci,int fi,int cf,int ff);
void pantalla(int fila, int columna);
void borr();
void cargarA();
abrirA();
abrirR();
int tama=sizeof(agenda);
int cant,sw;
void validarn(int fil,int col);

char vec[5][13],vec1[4][12];
char nombre,color,talla,valor;
int i=0,u,referencia,tecla,res,opcion,activo,r,k;
int e,des,tota,total,cod,hay=0;
void main()
{
  do
 {
 piso();
 cuad(1,3,80,22);
 textbackground(3);gotoxy(1,2);cprintf("                                                                                ");
 textbackground(7);
 textbackground(4);gotoxy(1,1);cprintf("                                                                                ");
 gotoxy(24,1);textcolor(15);cprintf("C E N T R O C O M E R C I A L - A Z U C A R" );
 textbackground(7);
 strcpy(vec[0],"   ADICION  ");
 strcpy(vec[1],"MODIFICACION");
 strcpy(vec[2],"  LISTAR    ");
 strcpy(vec[3],"  ELIMINAR  ");
 strcpy(vec[4],"   SALIR    ");
 opcion=menu();
  if (opcion==0)
     crear();
   if (opcion==1)
     modificar();
     if (opcion==2)
      listar();
	 if (opcion==3)
	  eliminar();

}while (opcion!=4);

}

/*****void listarL()
{ q=cab;
  while (q!=NULL)
   { printf("\n%d\n",q->referencia);
     printf("\n%ld\n",q->punt);
     q=q->sig;
    }
}     */



void piso()
{   for (u=1;u<23;u++)
   { //gotoxy(1,u);
     textcolor(1);
     cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
   }
 }
 /*******************************************************/

 void cuad(int ci,int fi,int cf,int ff)
 {  int i;
   i=ci;
   textcolor(0);
   for (i=ci;i<=cf;i++)
   {
    gotoxy(i,fi);cprintf("Í");
    gotoxy(i,ff);cprintf("Í");
   }
   i=fi;
   for (fi=i;i<=ff;i++)
   {
     gotoxy(ci,i);cprintf("º");
     gotoxy(cf,i);cprintf("º");
   }
    gotoxy(ci,fi);cprintf("É");
    gotoxy(cf,fi);cprintf("»");
    gotoxy(ci,ff);cprintf("È");
    gotoxy(cf,ff);cprintf("¼");
 }

 /*******************************************************/
void pantalla (int fila, int columna)
{//boli(49,5,75,9);
  textcolor(0);
 gotoxy(columna,fila);cprintf  ("referencia  ");
 gotoxy(columna,fila+1);cprintf("nombre      ");
 gotoxy(columna,fila+2);cprintf("color       ");
 gotoxy(columna,fila+3);cprintf("talla       ");
 gotoxy(columna,fila+4);cprintf("valor       ");
}
/**************************************************************/
 abrirA()
{ptr=fopen("agenda.dat","a+b");
 if(ptr==NULL)
 {printf("ERROR DE APERTURA");
 getch();
 return(0);
 }
 else
 return(1);
}
/*********************************************************/
abrirR()
{ptr=fopen("agenda.dat","r+b");
 if(ptr==NULL)
 {printf("ERROR DE APERTURA");
 getch();
 return(0);
 }
 else
 return(1);
}

/***********************************************************/
void crear()
{  int ref;
 if (abrirA()==1)
  {
    do
    {
	boli(4,5,34,9);
	cuad(3,4,35,10);
	pantalla(5,4);

	boli(23,23,4,74);
	boli(5,4,11,34);
	//boli(23,9,14,35);
	gotoxy(23,5);scanf("%d",&ref);
	    if (buscar(ref)==0)
	      {fflush(stdin);
	       agenda.referencia=ref;
	       gotoxy(23,6);gets(agenda.nombre       );
	       gotoxy(23,7);gets(agenda.color       );
	       gotoxy(23,8);gets(agenda.talla    );
	       gotoxy(23,9);gets(agenda.valor     );
	       agenda.activo=0;
	       boli(23,23,28,69);
	       gotoxy(28,23);textcolor(0);cprintf("DATOS CORRECTOS S/N");
	       gotoxy(47,23);res=getch();
	       res=toupper(res);
		 if (res=='S')
		  {
		   fwrite(&agenda,tama,1,ptr);
		   total=ftell(ptr)/tama;
		   des=(long)((total-1)*tama);
		   cargar(cod,des);
		  }
	       }
	      else  { boli(23,23,8,69);
		     gotoxy(8,23);textcolor(0);//cprintf("!!ESTA REFERENCIA YA SE ENCUENTRA!!<<<Enter para continuar>>>");
		     getch();
		    }
		      boli(23,23,8,69);
		       gotoxy(28,23);textcolor(0);cprintf("DESEA CONTINUAR S/N [ ]");
		       gotoxy(49,23);res=getch();
		       res=toupper(res);
	 }while(res!='N');
  }
	    fclose(ptr);
 }
/*****************************************************************/
void cargar(int ref,long punt)
{    nodo1=getnodo;
     nodo1->sig=NULL;
     nodo1->referencia=ref;
     nodo1->punt=punt;
      if (cab==NULL)
	cab=nodo1;
       else
       {
	 q=cab;
	 s=q;
	 sw=0;
	  while((q!=NULL)&&(sw==0))
	   {
	     if (nodo1->referencia<q->referencia)
	     sw=1;
	     else
	     {
	       s=q;
	       q=q->sig;
	     }
	    }
	       if(q==s)
		{
		  q=nodo1->sig;//=cab;
		  cab=nodo1;

		  }
	       //}
		    else
		     {
			if (q==NULL)
			{
			   s->sig=nodo1;
			   nodo1->sig=NULL;

			 }
			  else
			    {
			      s->sig=nodo1;
			     nodo1->sig=q;
	     }
	}
     }
}
//     }while(res!='N');


/*****************************************************************/
void cargarA()
{ if (abrirR()==1)
   { rewind(ptr);
      while (!feof(ptr))
	{ fread(&agenda,tama,1,ptr);
	 if (!feof(ptr))
	  { if (agenda.activo==0)
	    { total=ftell(ptr)/tama;
	     des=(long)((total-1)*tama);
	     cargar(agenda.referencia,des);
	    }
	  }

	 }
    }
    fclose(ptr);
 }
/*********************************************************/
menu()
{
do
 {r=2;
  textcolor(0);
  textbackground(4);
  for (i=0;i<5;i++)
   {if (i==k)
    {textcolor(0);
     textbackground(5);
     gotoxy(2+r,2);cprintf("%s",vec[i]);
     }
     else
      {textcolor(15);textbackground(3);
       gotoxy(2+r,2);cprintf("%s",vec[i]);}
       r+=15;
       textcolor(0);
       textbackground(7);
       switch(k)
       {case 0:go;textbackground(4);gotoxy(1,24);cprintf("                                                                                ");
		     gotoxy(1,24);textcolor(15);cprintf(" ESTAS SON LAS OPCIONES DEL MENU ");
		  textbackground(7);	break;
	case 1:go; textbackground(4);gotoxy(1,24);cprintf("                                                                                ");
		gotoxy(20,24);textcolor(15); cprintf("MODULO DE MODIFICACION DE MERCANCIA ");
		 textbackground(7);	 break;
	case 2:go;  textbackground(4);gotoxy(1,24);cprintf("                                                                                ");
	 gotoxy(20,24);textcolor(15);cprintf("MODULO DE CONSULTA DE MERCANCIA     ");
	       textbackground(7);break;
	case 3:go; textbackground(4);gotoxy(1,24);cprintf("                                                                                ");
	 gotoxy(20,24);textcolor(15);cprintf("MODULO PARA ELIMINAR MERCANCIA   ");
	       textbackground(7);break;
	case 4:go; textbackground(4);gotoxy(1,24);cprintf("                                                                                ");
	 gotoxy(20,24);textcolor(15);cprintf("MODULO PARA SALIR DE LA APLICACION       ");
	       textbackground(7);break;
       }
      }
      tecla=getch();
       if(tecla==77)
       {if (k<4)
	 k++;
	 else
	 k=0;
       }
       if (tecla==75)
	{if (k!=0)
	 k--;
	 else
	  k=4;
	}
 }
 while (tecla!=13);
 return(k);
 }
/********************************************************************/

buscar(int ref)
{int sw=0;
   rewind(ptr);
   fread(&agenda,tama,1,ptr);
   while(!feof(ptr)&&(sw==0))
   {if ((agenda.referencia==ref)&&(agenda.activo==0))
     sw=1;
     else
       fread(&agenda,tama,1,ptr);
    }

    return(sw);

}

/********************************************************************/
buscar1(int ref)
{int sw=0;
   pq=cab;
   while((pq!=NULL)&&(sw==0))
   {if (cod==pq->referencia)
     sw=1;
       else
       pq->sig=q;
    }
      return(sw);
 }

/*********************************************************/

void boli (int f1, int f2, int col1, int col2)
{int z, d;
 {for (z=f1;z<=f2;z++)
   for (d=col1;d<col2;d++)
    {gotoxy(d,z);cprintf(" ");
    }
  }
}

/*********************************************************************/

/*void validar(int fil,int col)
{ int di=0;
 cad[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+di,col);res=getch();
      if ((res>='a' && res<='z')||(res>='A' && res<='Z')||(res==' '))
	{
	    cad[di++]=res;
	    gotoxy(fil-1+di,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cad[0] == ' ');
 cad[di]='\0';
 }
/********************************************************************/

/*void validarn(int fil,int col)
{ int ni=0;
  cad[0]=' ';
  do
 {
   do
     {

      gotoxy(fil+ni,col);res=getch();
      if ((res>='0' && res<='9')||(res==' '))
	{
	    cad[ni++]=res;
	    gotoxy(fil-1+ni,col);printf("%c",res);
	}
      }
  while (res!=13);
 }
 while (cad[0] == ' ');
 cad[ni]='\0';
 }/*

/*****************************************************************/
void eliminar()
{int ref;
do
  {
	if(abrirR()==1)
	 {
	  boli(23,23,4,79);
	  cuad(48,4,75,10);
	 // boli(5,9,59,75);
	  pantalla(5,49);
       // eliminar1();
	  gotoxy(68,5);scanf("%d",&ref);
	    if (buscar(ref)==1)
	    {
	     boli(5,5,60,75);
	     gotoxy(68,5);printf("%d",agenda.referencia     );
	     gotoxy(68,6);puts(agenda.nombre      );
	     gotoxy(68,7);puts(agenda.color       );
	     gotoxy(68,8);puts(agenda.talla   );
	     gotoxy(68,9);puts(agenda.valor    );
	     gotoxy(23,23);textcolor(0);cprintf(" DESEA BORRAR S/N [ ]");
	     gotoxy(54,23);e=getch();boli(23,23,22,65);
	       if (toupper(e)=='S')
		{  agenda.activo=1;
		   total=ftell(ptr)/tama;
		   des=(long)((total-1)*tama);
		   fseek(ptr,des,SEEK_SET);
		   fwrite(&agenda,tama,1,ptr);
		   boli(23,23,4,79);
		   gotoxy(10,23);printf("DATOS ELIMINADOS<PRESIONE ENTER PARA CONTINUAR> ");
		      getch();
				  }
		    else
		       {boli(23,23,4,79);
			gotoxy(4,23);printf("!!ESTOS DATOS NO HAN SIDO ELIMINADO!!<<Enter para continuar>>");
			getch();
		       }
	      }
		  else
			{boli(23,23,4,79);
			 gotoxy(28,23);printf("ESTE REFERENCIA NO EXISTE<PRESIONE ENTER PARA CONTINUAR>");
			 getch();
			}
		       boli(23,23,4,79);
		       gotoxy(23,23);printf("DESEA CONTINUAR ELIMINANDO S/N [ ]");
		       gotoxy(56,23);res=getch();
		       res=toupper(res);
	  }
	 }while (res!='N');

  fclose(ptr);
}


/********************************************************************/

void modificar()
{int ref,pg,preg;char opc;
 do
 {
    if (abrirR()==1)
    {
  //   boli(5,23,10,10);
     boli(23,23,14,75);
       cuad(19,4,51,10);
       pantalla(5,20);
       gotoxy(39,5);scanf("%d",&ref);
       if (buscar(ref)!=0)
       { fflush(stdin);
		gotoxy(39,6);puts(agenda.nombre);
		gotoxy(39,7);puts(agenda.color);
		gotoxy(39,8);puts(agenda.talla);
		gotoxy(39,9);puts(agenda.valor);
		gotoxy(4,23);printf(" DESEA MODIFICAR S/N[ ]");
		gotoxy(50,23);pg=getch();

	    if (toupper(pg)!='N')
		{  gotoxy(39,6);gets(agenda.nombre);
		   gotoxy(39,7);gets(agenda.color);
		   gotoxy(39,8);gets(agenda.talla);
		   gotoxy(39,9);gets(agenda.valor);
		   total=ftell(ptr)/tama;
		   des=(long)((total-1)*tama);
		   fseek(ptr,des,SEEK_CUR);
		   fwrite(&agenda,tama,1,ptr);
		   boli(23,23,4,79);
		   gotoxy(31,23);printf("DATOS ACTUALIZADO");
		   getch();
      //	  delay(1000);sound(100);sleep(2);nosound();

		  }
	     }
		 else
		  {gotoxy(12,23);textcolor(0);cprintf("!!ESTE CODIGO NO EXISTE!!<<enter para continuar>>");
		   getch();
	      //}
	     //}
	   }
		boli(4,10,19,51);
		//boli(23,23,4,78);
		boli(23,23,4,78);
		gotoxy(18,23);printf("DESEA CONTINUAR CON OTRO REGISTRO S/N [ ]");
		gotoxy(57,23);preg=getch();
		preg=toupper(preg);
       }
     } while (preg!='N');
	 fclose(ptr);
   }

 void listar()
{  if (abrirR()==1)
     { 	 cuad(35,4,66,10);
	 rewind(ptr);
	 fread(&agenda,tama,1,ptr);
	 while(!feof(ptr))
	 {
	    boli(5,9,46,66);
	    pantalla(5,36);
	    if (agenda.activo==0)
	    {
	      gotoxy(55,5);printf("%d",agenda.referencia);
	      gotoxy(55,6);puts(agenda.nombre);
	      gotoxy(55,7);puts(agenda.color);
	      gotoxy(55,8);puts(agenda.talla);
	      gotoxy(55,9);puts(agenda.valor);
	      getch();
	    }
	      fread(&agenda,tama,1,ptr);
	   }
	   }
	    else
	    {
	     gotoxy(13,23);textcolor(0);cprintf("!!NO HAY DATO EN LA LISTA<PRESIONE ENTER PARA DIGITAR>");
	     getch();
	    }
      fclose(ptr);
   }
void eliminar1()
{ int referencia,ref;
gotoxy(68,5);scanf("%d",referencia);
   sw=0;
  if(buscar(ref)==0)
   { sw=1;
   }
    else
     {
       if((q==s)&&(q->sig==NULL))
       { cab=NULL;
	 free(q);
       }
       else
	 {if((q==s)&&(q->sig!=NULL))
	  {cab=q->sig;
	   free(q);
	  }
	   else
	   {if((q!=s)&&(q->sig==NULL))
	     {  s->sig=NULL;
	       free(q);
	     }
		else
		{if((q!=s)&&(q->sig!=NULL))
		 { s->sig=q->sig;
		   free(q);
		 }

		}
	    }
	 }
      }

}

void borr()

{ ptr=fopen("agenda.dat","w+b");
}

