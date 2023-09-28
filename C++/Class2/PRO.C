#include <conio.h>
#include <stdio.h>
#include <graphics.h>

typedef struct registro
 {
   char codigo [6];
   char nombre [30];
   float n1;
   float n2;
   float n3;
   float ex;
   float prom;
  };
  FILE *fp;
    struct registro reg;
    long int posfp=0, contfp=0;
    int gdmodo = DETECT;
    int gmmodo;

	void inicio ()
	 {
	   initgraph(&gdmodo,&gmmodo," ");
	 }
	 void menu()
	  {
		char op;
		setcolor(1);
		setbkcolor(12);
		cleardevice();
		marco(1,1,639,478,15);
		settextjustify (CENTER_TEXT,CENTER_TEXT);
		settextstyle (3,0,3);
		outtextxy(320,30,"MENU PRINCIPAL");
		outtextxy(320,80,"1.  ADICIONAR");
		outtextxy(320,100,"2.  MODIFICAR");
		outtextxy(320,120,"3.  CONSULTAR");
		outtextxy(307,140,"4.  BORRAR");
		outtextxy(306,160,"5.  SALIR");
		outtextxy(320,250,"Digite Opcion  [   ]");
		gotoxy(10,20);
		op=getche();
		switch(op)
		{
		  case '1':
		  adicionar();
		  break;
		  case '2':
		  modificar();
		  break;
		  case '3':
		  consultar();
		  break;
		  case '4':
		  eliminar();
		  default:
		  printf ("Ninguan opcion seleccionada");
		 }
	   }
	void main()
	  {
	    inicio();
	    menu();                   	  }

	marco (int x1, int y1, int xf, int yf, int col)
	 {
	   setcolor(col);
	   moveto(x1, y1);
	   lineto (xf,y1);
	   lineto (xf, yf);
	   lineto (x1, yf);
	   lineto (x1, y1);
	 }

  adicionar()
	{
	  FILE *fp;
	  long int posfp=0,contfp=0;
	  char op='s';
	  struct registro reg;
	  if((fp=fopen("archivo","a"))==NULL)
	  printf ("no esta");
	  else
	  {
		while (op!='N')
		    {
			 posfp=(contfp++)*sizeof(reg);
			 fseek(fp,posfp,SEEK_SET);
			 clrscr();
			 setcolor(11);
			 setbkcolor(12);
			 cleardevice();
			 marco(1,1,639,478,15);
			 settextjustify (CENTER_TEXT,CENTER_TEXT);
			 settextstyle (3,0,3);
			 outtextxy(280,30,"PANTALLA PARA INGRESO");
			 outtextxy(275,105,"Codigo :");
			 gotoxy(42,8);
			 gets(reg.codigo);
			 flushall();
			 outtextxy(275,131,"Nombre :");
			 gotoxy(42,10);
			 gets(reg.nombre);
                         flushall();
			 outtextxy(280,160,"Nota # 1 :");
			 gotoxy(42,12);
			 scanf("%f",&reg.n1);
                         flushall();
			 outtextxy(280,190,"Nota # 2 :");
			 gotoxy(42,14);
			 scanf("%f",&reg.n2);
                         flushall();
			 outtextxy(280,219,"Nota # 3 :");
			 gotoxy(42,16);
			 scanf("%f",&reg.n3);
                         flushall();
			 outtextxy(280,247,"E. Final :");
			 gotoxy(42,18);
			 scanf("%f",&reg.ex);
                         flushall();
			 reg.prom=(reg.n1+reg.n2+reg.n3+reg.ex)/4;
			 outtextxy(280,274,"Promedio :");
			 gotoxy(42,20);printf("%.1f",reg.prom);
			 fwrite(&reg,sizeof(reg),1,fp);
			 gotoxy(28,23);printf("DIGITE  'N'  PARA ABANDORNAR");
			 op=toupper(getch());

		   }
		 fclose(fp);
		 menu();
	}

  }




modificar()
  {
     FILE *fp, *auxi;
     char op ='s';
     long int posfp=0, contfp=0, posauxi=0,contaux=0;
     char codigo[6];
     char codi[6];
     if ((fp=fopen("archivo","r"))==NULL)
       printf ("no abrio");
     if ((auxi=fopen("auxi","w"))==NULL)
       printf ("no se abrio");
     while(op!='N')
	{
	   posfp=(contfp++)*sizeof(reg);
	   fseek(fp,posfp,SEEK_SET);
	   fread(&reg,sizeof(reg),1,fp);
	   cleardevice();
	   outtextxy(280,100,"Codigo :");
	   gotoxy(42,8);
	   gets(codi);
	   flushall();
	   while(!feof(fp))
	     {
	       if (strncmp(codi,reg.codigo)==0)
		 {
		   pantalla();
		   gotoxy(30,20);printf("Digite la Opcion a Modificar");
		   gotoxy(10,20);
		   op=getche();
		   switch(op)
		     {
		       case 'c':
		       gotoxy(55,8);
		       gets(reg.codigo);
		       flushall();
		       break;
		       case 'n':
		       gotoxy(55,10);
		       break;
		       case '1':
		       gotoxy(55,12);
		       break;
		       case '2':
		       gotoxy(55,14);
		       break;
		       case '3':
		       gotoxy(55,16);
		       break;
		       case 'ex':
		       gotoxy(55,18);
		       default:
		       gotoxy(10,20);
		       op=getche();
		       printf ("Ninguan opcion seleccionada");
		     }
		    posauxi=(contaux++)*sizeof(reg);
		    fseek(auxi,posauxi,SEEK_SET);
		    fwrite(&reg,sizeof(reg),1,auxi);
		    posfp=(contfp++)*sizeof(reg);
		    fseek(fp, posfp, SEEK_SET);
		    fread(&reg,sizeof(reg),1,fp);
		  }
		   else
		     {
		       posauxi=(contaux++)*sizeof(reg);
		       fseek(auxi,posauxi,SEEK_SET);
		       fwrite(&reg,sizeof(reg),1,auxi);
		       posfp=(contfp++)*sizeof(reg);
		       fseek(fp, posfp, SEEK_SET);
		       fread(&reg,sizeof(reg),1,fp);
		     }
	     }
	   fclose(fp);
	   fclose(auxi);
	   remove("archivo");
	   rename ("auxi","archivo");
     }
  }

pantalla()
 {
   char op;
   setcolor(11);
   setbkcolor(12);
   cleardevice();
   marco(1,1,639,478,15);
   settextjustify (CENTER_TEXT,CENTER_TEXT);
   settextstyle (3,0,3);
   outtextxy(320,30,"PANTALLA PARA          ");
   outtextxy(270,94,"Codigo   :");
   gotoxy(45,7);printf("%s",reg.codigo);
   outtextxy(270,118,"Nombre   :");
   gotoxy(45,9);printf("%s",reg.nombre);
   outtextxy(270,144,"Nota # 1 :");
   gotoxy(45,11);printf("%.1f",reg.n1);
   outtextxy(270,174,"Nota # 2 :");
   gotoxy(45,13);printf("%.1f",reg.n2);
   outtextxy(270,205,"Nota # 3 :");
   gotoxy(45,15);printf("%.1f",reg.n3);
   outtextxy(270,234,"E. Final :");
   gotoxy(45,17);printf("%.1f",reg.ex);
   outtextxy(270,258,"Promedio :");
   gotoxy(45,19);printf("%.1f",reg.prom);
 }

 leercod()
  {
  gotoxy(12,12);printf("*******");
  gotoxy(12,14);printf("lea");
}


consultar()
 {
   char op ='s';
   long int posfp=0, contfp=0;
   char codi[6];
   int sw=0;
   if ((fp=fopen("archivo","r"))==NULL)
       printf ("no abrio");
       else
	 {
	   contfp=0;
	   while (op!='N')
	     {
	       posfp=(contfp++)*sizeof(reg);
	       fseek(fp,posfp,SEEK_SET);
	       fread(&reg,sizeof(reg),1,fp);  /*  +++ aqui sucio codigo ++++++ */
	       cleardevice();
	       leercod();
	       /*outtextxy(280,100,"Codigo :");
	       gotoxy(42,8);*/
	       gets(codi);
	       flushall();
		 if (strncmp(codi,reg.codigo)==0)
		   {
		     sw=1;
		     pantalla();
		     outtextxy(320,30,"              CONSULTAR");
		     if (sw==0)
		      printf("registro no existente");
		       else
		       {
			gotoxy(30,22);printf("DESEA OTRA CONSULTA");
			 op=toupper(getch());
			}
		     }
		   }
   fclose(fp);
   menu();
  }
 }



eliminar()
{
FILE *fp, *aux;
char codi [6];
char op ='s';
if ((fp=fopen("archivo","r"))==NULL)
       printf ("no abrio");
     if ((aux=fopen("aux","w"))==NULL)
       {
       printf ("no se abrio");
       contfp=0;
       posfp=(contfp++)*sizeof(reg);
       fseek(fp,posfp,SEEK_SET);
       fread(&reg,sizeof(reg),1,fp);
       while (op!='N')
	 {
	   gets(codi);
	   while(!feof(fp));
	   {
	     if (strncmp(codi,reg.codigo)==0)
	     {
	       posfp=(contfp++)*sizeof(reg);
	       fseek(fp,posfp,SEEK_SET);
	       fread(&reg,sizeof(reg),1,fp);
	     }
	     else
	     {
	       posfp=(contfp++)*sizeof(reg);
	       fseek(fp,posfp,SEEK_SET);
	       fread(&reg,sizeof(reg),1,aux);
	     }
	}
	}
       }





    }