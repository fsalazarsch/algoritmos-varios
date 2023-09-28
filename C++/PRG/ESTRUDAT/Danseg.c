#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
struct dangela
 {
   char ced[15],nombre[40],apellido[40],sexo;
   long float sueldo;
  }info[300],aux;
char nom[40],ape[40],sex,ced[15];
int j,i,l,m;
long float suel;
void menu();
void menu_visual();
void inic();
b_libre();
void menu_ordenar();
void ordenar_apellido();
void lis_general();
void menu_modificar();
void menu_modificar2();
void vis_cod();
void introducir();
void mod_sex();
void insertar();
void ordenar_nombre();
void mod_ape();
void ordenar_cedula();
void eliminar();
void mod_ced();
void mod_cod();
void mod_nom();
void hom_queiguales();
void muj_quedocien();
void marco(int x1,int y1,int x2,int y2);
void cuadro_visual(int x1,int y1,int x2,int y2);
/*****************************************************************/
void main()
{ clrscr();
menu();
}
/*****************************************************************/
void marco(int x1,int y1,int x2,int y2)
{ int i;
  gotoxy(x1, y1); printf("%c",218); //Ú
  gotoxy(x2, y1); printf("%c",191); //¿
  gotoxy(x1, y2); printf("%c",192); //À
  gotoxy(x2, y2); printf("%c",217); //Ù
       for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",196);//Ä
       gotoxy(i, y2);printf("%c",196);}
    for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",179); //³
       gotoxy(x2, i);printf("%c",179);} 
  }
/******************************************************************/
void menu()
{char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
 for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(5);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(4);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("MENU PRINCIPAL");

  textbackground(5);
  window(27,12,59,19);clrscr();marco(1,1,33,8);
  
  textbackground(4);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(6,2);
  cprintf("1.INTRODUCIR EMPLEADO");
  gotoxy(6,3);
  cprintf("2.VISUALIZAR");
  gotoxy(6,4);
  cprintf("3.ORDENAR");
  gotoxy(6,5);
  cprintf("4.MODIFICAR");
  gotoxy(6,6);
  cprintf("5.ELIMINAR");
  gotoxy(6,7);
  cprintf("6.SALIR");


 textcolor(15);
 gotoxy(5,2);cprintf("");gotoxy(5,2);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(5,wherey()+5);
	     cprintf("");
	     gotoxy(5,wherey());
	   }
	    else
	    {

	      gotoxy(5,wherey()-1);
	      cprintf("");
	      gotoxy(5,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==7)
	  {
	     gotoxy(5,wherey()-5);
	     cprintf("");
	     gotoxy(5,wherey());
	  }
	 else
	 {
	     gotoxy(5,wherey()+1);
	     cprintf("");
	     gotoxy(5,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==7)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:insertar();break;
       case 3:menu_visual();break;
       case 4:menu_ordenar();break;
       case 5:menu_modificar();break;
       case 6:eliminar();break;
       case 7:break;
      }

  }
    } while(SALIR!='S');
}

/******************************************************************/
void menu_visual()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
 } 
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(5);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(4);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("VISUALIZACION");

  textbackground(5);
  window(27,12,59,19);clrscr();marco(1,1,33,8);
  
  textbackground(4);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,2);
  cprintf("1.LISTADO GENERAL");
  gotoxy(4,3);
  cprintf("2.VISUALIZAR POR CEDULA");
  gotoxy(4,4);
  cprintf("3.MUJ. CON SUELDO < A 200000");
  gotoxy(4,5);
  cprintf("4.HOM. CON SUELDO DE 300000");
  gotoxy(4,6);
  cprintf("5.MENU PRINCIPAL");


 textcolor(15);
 gotoxy(3,2);cprintf("");gotoxy(3,2);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(3,wherey()+4);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==6)
	  {
	     gotoxy(3,wherey()-4);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==6)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:lis_general();break;
       case 3:vis_cod();break;
       case 4:muj_quedocien();break;
       case 5:hom_queiguales();break;
      }

  }
    } while(SALIR!='S');
}

/******************************************************************/
void menu_modificar2()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(5);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(4);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(4,2);textcolor(3);
  cprintf("MODIFICANDO");

  textbackground(5);
  window(27,12,59,19);clrscr();marco(1,1,33,8);
  
  textbackground(4);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,2);
  cprintf("1.MODIFICAR 	NOMBRE");
  gotoxy(4,3);
  cprintf("2.MODIFICAR APELLIDO");
  gotoxy(4,4);
  cprintf("3.MODIFICAR SEXO");
  gotoxy(4,5);
  cprintf("4.REGRESAR");
  textcolor(15);
 gotoxy(3,2);cprintf("");gotoxy(3,2);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==2)
	   {
	     gotoxy(3,wherey()+3);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-3);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 2:{mod_nom();break;}
       case 3:{mod_ape();break;}
       case 4:{mod_sex();break;}
      }

  }
    } while(SALIR!='S');
}

/******************************************************************/

void menu_ordenar()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(5);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(4);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(4,2);textcolor(3);
  cprintf(" ORDENAR");

  textbackground(5);
  window(27,12,59,19);clrscr();marco(1,1,33,8);
  
  textbackground(4);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,3);
  cprintf("1.ORDENAR POR CEDULA");
  gotoxy(4,4);
  cprintf("2.ORDENAR POR NOMBRE");
  gotoxy(4,5);
  cprintf("3.ORDENAR POR APELLIDO");
  gotoxy(4,6);
  cprintf("4.MENU PRINCIPAL");
 /* gotoxy(4,6);
  cprintf("5.MENU PRINCIPAL");*/


 textcolor(15);
 gotoxy(3,3);cprintf("");gotoxy(3,3);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==3)
	   {
	     gotoxy(3,wherey()+3);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==6)
	  {
	     gotoxy(3,wherey()-3);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==6)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       
       case 3:{ordenar_cedula();break;}
       case 4:{ordenar_nombre();break;}
       case 5:{ordenar_apellido();break;}
      }

  }
    } while(SALIR!='S');
}

/******************************************************************/

void menu_modificar()
{ char op,tecla,SALIR;
  int u;
 do
 { window(1,1,80,25);
   textbackground(15);

   textcolor(1);
 
   clrscr();
   SALIR='N';
  
  for (u=1;u<26;u++)
 {
 delay(15);
 gotoxy(1,u);
 cprintf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
 
 }
  gotoxy(15,25);textcolor(0);
  cprintf("[Utilice las teclas (%c%c) del cursor y presione <enter>]",24,25);
  marco(1,1,80,24);marco(3,2,78,23);marco(5,3,76,22);

  textbackground(5);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(4);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(5,2);textcolor(3);
  cprintf("MODIFICAR");

  textbackground(5);
  window(27,12,59,19);clrscr();marco(1,1,33,8);
  
  textbackground(4);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(4,3);
  cprintf("1.MODIFICAR DATOS PERSONALES");
  gotoxy(4,4);
  cprintf("2.MODIFICAR SUELDO");
  gotoxy(4,5);
  cprintf("3.MENU PRINCIPAL");

 textcolor(15);
 gotoxy(3,3);cprintf("");gotoxy(3,3);


 do
 {
   tecla=getch();
      if(tecla==72)
      {
	printf(" ");
	  if(wherey()==3)
	   {
	     gotoxy(3,wherey()+2);
	     cprintf("");
	     gotoxy(3,wherey());
	   }
	    else
	    {

	      gotoxy(3,wherey()-1);
	      cprintf("");
	      gotoxy(3,wherey());
	    }
       }

       if(tecla==80)
       {
	     printf(" ");
	 if(wherey()==5)
	  {
	     gotoxy(3,wherey()-2);
	     cprintf("");
	     gotoxy(3,wherey());
	  }
	 else
	 {
	     gotoxy(3,wherey()+1);
	     cprintf("");
	     gotoxy(3,wherey());
	 }
       }
   } while(tecla!=13);

   op=wherey();

   if(op==5)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {
       case 3:menu_modificar2();break;
       case 4:mod_cod();break;
      }

  }
    } while(SALIR!='S');

}


void insertar()
{int i,l,m,sw=0;
window(1,1,80,25);
textbackground(4);
clrscr();
window(1,1,80,25);
clrscr();

printf("DIGITE LA CEDULA :");scanf("\n");
gets(ced);
l=strlen(ced);
     while (l>15)
     {

     gotoxy(4,5);printf("DIGITE LA CEDULA : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	gotoxy (4,5);printf("DIGITE LA CEDULA : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);


for(i=0;i<=j;i++)
{if(!strcmp(info[i].ced,ced))
 {sw=1; break;}
 }
if (sw==0){
for(i=j;i<300;i++)
{printf("DIGITE EL NOMBRE : ");scanf("\n");gets(nom);
printf("DIGITE EL APELLIDO : ");scanf("\n");gets(ape);
printf("DIGITE EL SEXO F(2),M(1) : ");scanf("\n");sex=getchar();
while(sex<'1' || sex >'2')
      sex=getchar();

printf("DIGITE EL SUELDO : ");scanf("\n");scanf("%lf",&suel);
      
strcpy(info[i].ced,ced);
strcpy(info[i].nombre,nom);
strcpy(info[i].apellido,ape);
info[i].sexo=sex;
info[i].sueldo=suel;j++;
break;
}
}
}
/********************************************************************/
void lis_general()
{ int i;
window(1,1,80,25);
clrscr();
for(i=0;i<j;i++)
{  
printf("%s\n",info[i].ced);
printf("%s\n",info[i].nombre);
printf("%s\n",info[i].apellido);
printf("%c\n",info[i].sexo);
printf("%lf\n",info[i].sueldo);

}
getche();
}

void vis_cod()
{int i;
window(1,1,80,25);
clrscr();
for(i=1;i<2001;i++)
printf("²");
window(1,1,80,25);textbackground(0);
window(12,9,70,18);textbackground(4);clrscr();
window(12,10,70,18);textbackground(15);clrscr();
gotoxy(12,5); printf("DIGITE EL CODIGO A VISUALIZAR : ");
window(54,14,61,14);textbackground(4);clrscr();
scanf("\n");
gets(ced);
l=strlen(ced);
     while(l>15) 
	  {

     gotoxy(4,5);printf("CODIGO  : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	printf("CODIGO : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);

window(1,1,80,25);clrscr();
for(i=0;i<300;i++)
{if(!strcmp(info[i].ced,ced))
{printf("%s\n",info[i].ced);
printf("%s\n",info[i].nombre);
printf("%s\n",info[i].apellido);
printf("%c\n",info[i].sexo);
printf("%lf\n",info[i].sueldo);
}
}
getche();
}

void muj_quedocien()
{ int i,c;
window(1,1,80,25);
textbackground(0);textcolor(15);clrscr();
cuadro_visual(9,2,70,25);
c=5;
for(i=0;i<300;i++)
{ if((info[i].sueldo<200000)&&(info[i].sexo=='2')){
gotoxy(10,c);cprintf("%s",info[i].ced);
gotoxy(19,c);cprintf("%s",info[i].nombre);
gotoxy(33,c);cprintf("%s",info[i].apellido);
gotoxy(51,c);cprintf("%c",info[i].sexo);
gotoxy(54,c);cprintf("%.2lf",info[i].sueldo);
c++;
}
}

getche();
}
void hom_queiguales()
{ int i,c;
window(1,1,80,25);
textbackground(0);textcolor(15);clrscr();
cuadro_visual(9,2,70,25);
c=5;
for(i=0;i<300;i++)
{ if((info[i].sueldo==300000)&&(info[i].sexo=='1')){
gotoxy(10,c);cprintf("%s",info[i].ced);
gotoxy(19,c);cprintf("%s",info[i].nombre);
gotoxy(33,c);cprintf("%s",info[i].apellido);
gotoxy(51,c);cprintf("%c",info[i].sexo);
gotoxy(54,c);cprintf("%.2lf",info[i].sueldo);
c++;
}
}
getche();
}

void mod_cod()
{int i;
window(1,1,80,25);
clrscr();
printf("DIGITE LA CEDULA  : ");scanf("\n");
gets(ced);
l=strlen(ced);
     while (l>15)
     {

     gotoxy(4,5);printf("DIGITE LA CEDULA  : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	gotoxy (4,5);printf("DIGITE LA CEDULA  : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);


for(i=0;i<300;i++)
{if(!strcmp(info[i].ced,ced))
{printf("%s\n",info[i].nombre);
printf("%s\n",info[i].apellido);
printf("%lf\n",info[i].sueldo);
printf("DIGITE EL NUEVO SUELDO :");
scanf("%lf",&suel);
info[i].sueldo=0;
info[i].sueldo=suel;

}
}
getche();
}
void eliminar()
{int k,i;
window(1,1,80,25);
clrscr();
window(1,1,80,25);
clrscr();
for(i=1;i<2001;i++)
printf("²");
window(1,1,80,25);textbackground(0);
window(12,9,70,18);textbackground(4);clrscr();
window(12,10,70,18);textbackground(15);clrscr();
gotoxy(1,5);printf("DIGITE LA CEDULA DEL EMPLEADO A ELIMINAR : "); 
window(54,14,61,14);textbackground(4);clrscr();

scanf("\n");
gets(ced);
l=strlen(ced);
     while(l>15)
     {

     gotoxy(4,5);printf("DIGITE LA CEDULA : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	gotoxy (4,5);printf("DIGITE LA CEDULA : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);


for(i=0;i<j;i++)
 {
   if(!strcmp(info[i].ced,ced))
	{
	 printf("%s\n",info[i].ced);
	 printf("%s\n",info[i].nombre);
	 printf("%s\n",info[i].apellido);
	 printf("%c\n",info[i].sexo);
	 printf("%lf\n",info[i].sueldo);
	 printf("%d",j);
	  for(k=i;k<j;k++)
	   {
	    strcpy(info[i].ced,info[i+1].ced);
	    strcpy(info[i].nombre,info[i+1].nombre);
	    strcpy(info[i].apellido,info[i+1].apellido);
	    info[i].sexo=info[i+1].sexo;
	    info[i].sueldo=info[i+1].sueldo;
	   }j--; printf("%d",j);
	}
}
getche();
}
/***********************************************************/
void cuadro_visual(int x1,int y1,int x2,int y2)
{ int i;
	for(i=(x1+1);i<=(x2-1);i++){
       gotoxy(i, y1);printf("%c",205);  //Í
       gotoxy(i, y2);printf("%c",205);
       gotoxy(i,4);printf("%c",205);
       gotoxy(i,23);printf("%c",205);}

	for(i=(y1+1);i<=(y2-1);i++){
       gotoxy(x1, i);printf("%c",186);  //º
       gotoxy(x2, i);printf("%c",186);
       gotoxy(18,i-1);printf("%c",186);
       gotoxy(32,i-1);printf("%c",186);
       gotoxy(48,i-1);printf("%c",186);
       gotoxy(53,i-1);printf("%c",186);
       }

       gotoxy(9,2); printf("%c",201);    //É
       gotoxy(70,2); printf("%c",187);   //»
       gotoxy(9,25); printf("%c",200);   //È
       gotoxy(70,25); printf("%c",188);   //¼

 /* Ë */ gotoxy(18,2); printf("%c",203);gotoxy(18,4); printf("%c",206);
	 gotoxy(32,2); printf("%c",203);gotoxy(32,4); printf("%c",206);
	 gotoxy(48,2); printf("%c",203);gotoxy(48,4); printf("%c",206);//Î
	 gotoxy(53,4); printf("%c",206);gotoxy(53,2); printf("%c",203);

       gotoxy(18,23); printf("%c",202);gotoxy(32,23); printf("%c",202);
       gotoxy(48,23); printf("%c",202);gotoxy(53,23); printf("%c",202);//Ê

       gotoxy(9,4); printf("%c",204);  //Ì
       gotoxy(70,4); printf("%c",185); //¹

       gotoxy(11,3); printf("CODIGO");
       gotoxy(22,3); printf("NOMBRE");
       gotoxy(37,3); printf("APELLIDO");
       gotoxy(49,3); printf("SEXO");
       gotoxy(59,3); printf("SUELDO");
     }
/**********************************************************************/
void mod_nom()
{int i;
window(1,1,80,25);
clrscr();
window(1,1,80,25);
clrscr();
for(i=1;i<2001;i++)
printf("²");
window(1,1,80,25);textbackground(0);
window(12,9,70,18);textbackground(4);clrscr();
window(12,10,70,18);textbackground(15);clrscr();
gotoxy(12,5); printf("DIGITE EL CODIGO A VISUALIZAR : ");
window(54,14,61,14);textbackground(4);clrscr();

scanf("\n");
gets(ced);
l=strlen(ced);
     while((l<8) || (l>8))
     {

     gotoxy(4,5);printf("DIGITE LA CEDULA : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	printf("DIGITE LA CEDULA : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);
for(i=0;i<300;i++)
{ 
if(!strcmp(info[i].ced,ced))
  {printf("%s",info[i].ced,ced);
   printf("DIGITE EL NUEVO NOMBRE : ");
   gets(nom);
   l=strlen(nom);
     while(l>40) 
     {

     gotoxy(4,5);printf("DIGITE EL NUEVO NOMBRE : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
      
   strcpy(info[i].nombre,nom);
   }
 }
}
void mod_ape()
{int i;
window(1,1,80,25);
clrscr();
window(1,1,80,25);
clrscr();
for(i=1;i<2001;i++)
printf("²");
window(1,1,80,25);textbackground(0);
window(12,9,70,18);textbackground(4);clrscr();
window(12,10,70,18);textbackground(15);clrscr();
gotoxy(12,5); printf("DIGITE EL CODIGO A VISUALIZAR : ");
window(54,14,61,14);textbackground(4);clrscr();

scanf("\n");
gets(ced);
l=strlen(ced);
     while((l<8) || (l>8))
     {

     gotoxy(4,5);printf("DIGITE LA CEDULA : ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	gotoxy (4,5);printf("DIGITE LA CEDULA : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);


for(i=0;i<300;i++)
{ if(!strcmp(info[i].ced,ced))
  {printf("%s",info[i].ced,ced);
   printf("DIGITE EL NUEVO APELLIDO :  ");
   gets(ape);
   l=strlen(ape);
     while(l>40) 
     {

     gotoxy(4,5);printf("DIGITE EL NUEVO APELLIDO ");
     gotoxy(13,5);clreol();scanf("\n");
     gets(ape);l=strlen(ape);}
      
   strcpy(info[i].apellido,ape);
   }
 }
}
void mod_sex()
{int i;
clrscr();
window(1,1,80,25);
clrscr();
for(i=1;i<2001;i++)
printf("²");
window(1,1,80,25);textbackground(0);
window(12,9,70,18);textbackground(4);clrscr();
window(12,10,70,18);textbackground(15);clrscr();
gotoxy(12,5); printf("DIGITE EL CODIGO A VISUALIZAR : ");
window(54,14,61,14);textbackground(4);clrscr();
scanf("\n");
gets(ced);
l=strlen(ced);
     while((l<8) || (l>8))
     {

     gotoxy(12,5);printf("DIGITE LA CEDULA : ");
     gotoxy(23,5);clreol();scanf("\n");
     gets(ced);l=strlen(ced);}
     do
     {
     for(i=0;i<l;i++)

	if(isdigit(ced[i])==0) m=1;
	if(m==1) {gotoxy(4,5);
	gotoxy(4,5);printf("DIGITE LA CEDULA : ");
    gotoxy(13,5); clreol(); }
    }while(m==1);


for(i=0;i<300;i++)
{ if(!strcmp(info[i].ced,ced))
  {printf("%s",info[i].ced,ced);
   printf("DIGITE EL NUEVO SEXO :  ");
   sex=getchar();
   while(sex<'1' || sex >'2')
      {sex=getchar();
      }
   info[i].sexo=sex;
   }               
   }
}
void ordenar_cedula()
{ int k;
clrscr();
for(i=0;i<j-1;i++)
{for(k=i+1;k<j;k++)
{
if(strcmp(info[i].ced,info[k].ced)>0)
{strcpy(ced,info[i].ced);
strcpy(info[i].ced,info[k].ced);
strcpy(info[k].ced,ced);

strcpy(nom,info[i].nombre);
strcpy(info[i].nombre,info[k].nombre);
strcpy(info[k].nombre,nom);

strcpy(ape,info[i].apellido);
strcpy(info[i].apellido,info[k].apellido);
strcpy(info[k].apellido,ape);

sex=info[i].sexo;
info[i].sexo=info[k].sexo;
info[k].sexo=sex;

suel=info[i].sueldo;
info[i].sueldo=info[k].sueldo;
info[k].sueldo=suel;


}}}
}
void ordenar_nombre()
{int k;
clrscr();
for(i=0;i<j-1;i++)
 for(k=i+1;k<j;k++)
  if(strcmp(info[i].nombre,info[k].nombre)>0)
   {aux=info[i];
   info[i]=info[k];
   info[k]=aux;
   }
   }




void ordenar_apellido()
{int k;
clrscr();
for(i=0;i<j-1;i++)
{for(k=i+1;k<=j;k++)
{if(strcmp(info[i].apellido,info[i+1].apellido)>0)
{strcpy(ced,info[i].ced);
strcpy(info[i].ced,info[i+1].ced);
strcpy(info[i+1].ced,ced);

strcpy(nom,info[i].nombre);
strcpy(info[i].nombre,info[i+1].nombre);
strcpy(info[i+1].nombre,nom);

strcpy(ape,info[i].apellido);
strcpy(info[i].apellido,info[i+1].apellido);
strcpy(info[i+1].apellido,ape);

sex=info[i].sexo;
info[i].sexo=info[i+1].sexo;
info[i+1].sexo=sex;

suel=info[i].sueldo;
info[i].sueldo=info[i+1].sueldo;
info[i+1].sueldo=suel;

}}}}
