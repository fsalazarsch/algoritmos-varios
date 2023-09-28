
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
	/*char *op;*/
		char op;
		setcolor(RED);
		setbkcolor(BLUE);
		cleardevice();
		marco(1,1,639,478,15);
		settextjustify (CENTER_TEXT,CENTER_TEXT);
		settextstyle (4,0,4);
		outtextxy(320,30,"MENU PRINCIPAL");
		settextjustify (TOP_TEXT,TOP_TEXT);
		outtextxy(320,80,"1.  ADICIONAR");
		outtextxy(320,110,"2.  MODIFICAR");
		outtextxy(320,140,"3.  BORRAR    ");
		outtextxy(320,170,"4.  CONSULTAR");
		outtextxy(320,200,"5.  SALIR      ");
		outtextxy(320,250,"Digite Opcion  [    ]");
		/*op[0]=getch();*/
		op=getch();
		/*sleep(2);
		outtextxy(300,250,op);*/
		switch(op)
		{
		  case '1':
		  adicionar();
		  break;
		  case '2':
		  modificar();
		  break;
		  default:
		  printf ("Ninguan opcion seleccionada");
		 }
	   }
	void main()
	  {
	    inicio();
	    menu();
          	  }

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
	  if((fp=fopen("pruprg","a"))==NULL)
	  printf ("no esta");
	  else
	  {
		while (op!='N')
		  {
			 posfp=(contfp++)*sizeof(reg);
			 fseek(fp,posfp,SEEK_SET);
			 clrscr();
			 setcolor(BLUE);
			 setbkcolor(BLACK);
			 cleardevice();
			 marco(1,1,639,478,15);
			 settextjustify (CENTER_TEXT,CENTER_TEXT);
			 settextstyle (3,0,3);
			 outtextxy(320,30,"PANTALLA PARA INGRESO");
			 settextjustify (TOP_TEXT,TOP_TEXT);
			 outtextxy(320,100,"Codigo :");
			 gotoxy(52,8);
			 scanf("%c",&reg.codigo);
			 flushall();
			 outtextxy(320,140,"Nombre :");
			 gotoxy(52,10);
			 scanf("%c",&reg.nombre);
			 flushall();
			 outtextxy(320,180,"Nota # 1 :");gotoxy(52,13);
			 scanf("%f",&reg.n1);
			 flushall();
			 outtextxy(320,220,"Nota # 2 :");gotoxy(52,15);
			 scanf("%f",&reg.n2);
                         flushall();
			 outtextxy(320,260,"Nota # 3 :");gotoxy(52,18);
			 scanf("%f",&reg.n3);
                         flushall();
			 outtextxy(320,300,"E. Final :");gotoxy(52,20);
			 scanf("%f",&reg.ex);
                         flushall();
			 reg.prom=(reg.n1+reg.n2+reg.n3+reg.ex)/4;
			 outtextxy(320,350,"Promedio :");gotoxy(52,24);
			 printf("%f",reg.prom);
			 fwrite(&reg,sizeof(reg),1,fp);

			 op=toupper(getch());
		  menu();
		   }
		 fclose(fp);
	}

  }
    modificar()
        	{
	FILE *fp, *auxi;
	char op ='s';
	long int posfp=0, contfp=0, posauxi=0,contauxi=0;
	int codigo;
	if ((fp=fopen("pruprg","r"))==NULL)
	  printf ("NO SE EFECTUO LA APERTURA");
	if ((auxi=fopen("auxiliar","w"))==NULL)
	  printf ("NO SE EFECTUO LA APERTURA");
	  else
	  {
		while(op!='N')
		  {
			posfp=(contfp++)*sizeof(reg);
			fseek(fp,posfp,SEEK_SET);
			fread(&reg,sizeof(reg),1,fp);
			cleardevice();
			gotoxy(10,20);printf("INSERTE CODIGO A MODIFICAR :");
			scanf("%d",&codigo);
	 while(!feof(fp))
         	   {
	    if (strcmp(codigo,reg.codigo)==0)
	       {
	       posauxi=(contauxi++)*sizeof(reg);
	       fseek(auxi,posauxi,SEEK_SET);
	       fwrite(&reg,sizeof(reg),1,auxi);
               	       posfp=(contfp++)*sizeof(reg);
			fseek(fp,posfp,SEEK_SET);
			fread(&reg,sizeof(reg),1,fp);
			cleardevice();
			scanf("%d",&codigo);
	       }

		 else
		   {
		   /*  posauxi=(contauxi++)*sizeof(reg);
		     fseek(auxi,posauxi,SEEK_SET);
		     fwrite(&reg,sizeof(reg),1,auxi);
		     posfp=(contfp++)*sizeof(reg);
		     fseek(fp, posfp, SEEK_SET);
		     fread(&reg,sizeof(reg),1,fp);*/
		     outtextxy(320,350,"No se pudo ");gotoxy(52,24);
		   }
		}
	     }
	     fclose(fp);
	     fclose(auxi);
	     remove("pruprg");
	     rename ("auxiliar","pruprg");
	   }
	   }

