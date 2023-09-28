# include <stdio.h>
# include <conio.h>
# include <graphics.h>
typedef struct registro
{
   char codigo[6];
   char nombre[30];
   float n1;
   float n2;
   float n3;
   float ex;
   float prom;
};
 FILE *fp;
 struct registro reg;
 int gdmodo=DETECT;
 int gmmodo;
 void inicia()
 {
 initgraph(&gdmodo, &gmmodo, " ");
 }
 marco(int xi, int yi, int xf, int yf, int mao)
    {
    cleardevice();
    setcolor(mao);
    moveto(xi, yi);
    lineto(xf, yi);
    lineto(xf, yf);
    lineto(xi, yf);
    lineto(xi, yi);
    }
    void menu()
      {
      char op[1];
      setbkcolor(1);
      marco(1,1,639,478,15);
      settextjustify(CENTER_TEXT, CENTER_TEXT);
      setcolor(12);
      settextstyle(3,0,4);
      outtextxy(320,70, "****MENU PRINCIPAL****");
      setcolor(10);
      outtextxy(170,200, "1. Adicionar");
      setcolor(13);
      outtextxy(170,250, "2. Modificar");
      setcolor(14);
      outtextxy(460,200, "3. Eliminar");
      setcolor(11);
      outtextxy(460,250, "4. Imprimir:");
      settextstyle(3,0,2);
      outtextxy(470,280, "a. Por Pantalla");

      outtextxy(485,310, "b. Por impresora");
      settextstyle(3,0,2);
      setcolor(15);
      outtextxy(320,400, "Digite la Opcion [   ]");
      op[0]=getch();
      switch(op[0]) {
       case '1' : adicionar();
		  menu();
		  break;
      case '2' : modificar();
		  menu();
		  break;
      }
    }
       void main()
	{
	inicia();
	menu();
	}
	 adicionar()
	 {
	 FILE *fp;
	 long int postp=0, cod, contfp=0;
	 char op='S';
	 if((fp=fopen("muestra", "a"))==NULL)
	 {
	 printf(+"­­­IMPOSIBLE ABRIR EL ARCHIVO!!!");
	 }
	   else
	   {
	   while(op!='N')
	   {
	     setbkcolor(1);
	     marco(1,1,639,478,15);
	     settextjustify(CENTER_TEXT, CENTER_TEXT);
	     setcolor(10);
	     settextstyle(3,0,4);
	     outtextxy(320,70, "****OPCION ADICIONAR****");
	     settextstyle(3,0,2);
	     setcolor(15);
	     outtextxy(100,149, "Codigo   :  ");
	     gotoxy(20,10);
	     gets(reg.codigo);
	     flushall();
	     outtextxy(100,180, "Nombre   :  ");
	     gotoxy(20,12);
	     gets(reg.nombre);
	     flushall();
	     outtextxy(100,212, "Nota 1   :  ");
	     gotoxy(20,14);
	     scanf("%f", &reg.n1);
	     flushall();
	     outtextxy(100,242, "Nota 2   :  ");
	     gotoxy(20,16);
	     scanf("%f", &reg.n2);
	     flushall();
	     outtextxy(100,274, "Nota 3   :  ");
	     gotoxy(20,18);
	     scanf("%f", &reg.n3);
	     flushall();
	     outtextxy(100,305, "Examen   :  ");
	     gotoxy(20,20);
	     scanf("%f", &reg.ex);
	     flushall();
	     outtextxy(100,336, "Promedio :  ");
	     gotoxy(20,22);
	     reg.prom=((reg.n1+reg.n2+reg.n3+reg.ex)/4);
	     printf("%2.2f", reg.prom);

	     postp=(contfp++)*sizeof(reg);
	     fseek(fp, postp, SEEK_SET);
	     fwrite(&reg, sizeof(reg),1,fp);
	     outtextxy(100,400,"Desea continuar?");
	     op=toupper(getch());
	     }
	   fclose(fp);
	 }
	 getch();
  }
	modificar()
	 {
	 FILE *fp, *auxi;
	 char op='S';
	 char cod[6];
	 long int posfp=0, contfp=0, posaux=0, contaux=0;
	 if((fp=fopen("muestra", "r"))==NULL)
	 printf("­­­IMPOSIBLE ABRIR EL ARCHIVO!!!");

	 if((auxi=fopen("Auxiliar", "w"))==NULL)
	 printf("IMPOSIBLE ABRIR EL ARCHIVO");

	 else
	 {
	    gets(cod);op='s';
	     posfp=(contfp++)*sizeof(reg);
	     fseek(fp, posfp, SEEK_SET);
	     fread(&reg, sizeof(reg), 1, fp);
	     while(op!='N')
	     {
	       while(!feof(fp))
	       {
		  if(strcmp(cod,reg.codigo)==0)
		  {
                        outtextxy(100,149, "Codigo   :  ");
			gotoxy(20,10);
			gets(reg.codigo);
			flushall();
			outtextxy(100,180, "Nombre   :  ");
			gotoxy(20,12);
			gets(reg.nombre);
			flushall();
			outtextxy(100,212, "Nota 1   :  ");
			gotoxy(20,14);
			scanf("%f", &reg.n1);
			flushall();
			outtextxy(100,242, "Nota 2   :  ");
			gotoxy(20,16);
			scanf("%f", &reg.n2);
			flushall();
			outtextxy(100,274, "Nota 3   :  ");
			gotoxy(20,18);
			scanf("%f", &reg.n3);
			flushall();
			outtextxy(100,305, "Examen   :  ");
			gotoxy(20,20);
			scanf("%f", &reg.ex);
			flushall();
			outtextxy(100,336, "Promedio :  ");
			gotoxy(20,22);
			reg.prom=((reg.n1+reg.n2+reg.n3+reg.ex)/4);
			printf("%2.2f", reg.prom);
			posaux=(contaux++)*sizeof(reg);
			fseek(auxi, posaux, SEEK_SET);
			fwrite(&reg, sizeof(reg), 1, auxi);
			posfp=(contfp++)*sizeof(reg);
			fseek(fp, posfp, SEEK_SET);
			fread(&reg, sizeof(reg), 1, fp);
		  }
		  else
		  {
			posfp=(contfp++)*sizeof(reg);
			fseek(fp, posfp, SEEK_SET);
			fread(&reg, sizeof(reg), 1, fp);
			posfp=(contfp++)*sizeof(reg);
			fseek(fp, posfp, SEEK_SET);
			fread(&reg, sizeof(reg), 1, fp);
		   }
	       }
               outtextxy(100,400,"Desea continuar?");
	     op=toupper(getch());
	    }
	fclose(fp);
        fclose(auxi);
	remove("muestra");
	rename("auxiliar", "muestra");
     }
  }



