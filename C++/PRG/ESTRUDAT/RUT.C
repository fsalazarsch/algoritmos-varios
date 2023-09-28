#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>

void inicio();
void ruta_minima();
void introducir();
void multiplicar();
void imprimir(int x[50][50], int comi, int final);
void comprob(char t[4]);
void funcion(int s,int t,int *pd,int precede[50]);
void cancelar();
void menu();

int i,j,k,l,aux,cont,aux1,aux2,sw,ws=0;
int c[50][50], a[50][50], b[50][50],val[50][50];


/**************************************************/
main () 
{
 char c;
 clrscr();
 menu();
}

/**************************************************/
void inicio()
{ 
 char dato[4];
 char lon[4];
 char elem[4];
 char pes[4],op;
 int xval;
 clrscr(); i=0;
 window(1,1,80,25);
 clrscr();
 window(1,1,80,25);
 clrscr();
 for(i=1;i<2001;i++)
 printf("²");
 window(1,1,80,25);textbackground(0);
 window(12,9,70,18);textbackground(1);clrscr();
 window(12,10,70,18);textbackground(12);clrscr();
 i=0;
 
   do {
     do {
	gotoxy(10,3);printf("                                       ");
	gotoxy(10,3); printf("NUMERO DE ELEMENTOS EN EL GRAFO:");
	gets(dato);
	comprob(dato);
	if (sw == 0){
	 aux2 = atoi(dato);
	 if (aux2 > 50 || aux2 < 2){
	  gotoxy(7,9);cprintf("... NUMERO DE ELEMENTOS ENTRE [2] y [50] ...");
	  getche();
	  gotoxy(7,9);cprintf("                                              ");
       }
     }
    }while (aux2 > 50 || aux2 < 2 || sw == 1);
				
  /*	
		gotoxy(11,18);cprintf("                                                           ");
		gotoxy(18,18);cprintf("Y SE RECOMIENDE UN NUMERO NO MAYOR DE [6] ELEMENTOS");
		sleep(2);*/



	 gotoxy(7,9);cprintf("                                                   ");
	 gotoxy(7,9);cprintf("...PULSE <S> PARA CORREGIR, SINO <ENTER>...");
	 op = getche();
	 gotoxy(7,9);cprintf("                                             ");

      }while(op == 'S' || op == 's');
      do {    
	gotoxy(10,4);cprintf("                                                     ");
	gotoxy(10,4);cprintf("DIGITE LOS CAMINOS [N] QUE DESEA CALCULAR : ");
	gets(lon);
	comprob(lon);
	if (sw == 0){
	 aux1 = atoi(lon);
	 if (aux1 < 2 || aux1 > 99){
	  gotoxy(7,9);cprintf("... EL CAMINO [N] DEBE ESTAR ENTRE [2] ¢ [99] ...");
	  gotoxy(7,9);cprintf("                                                 ");
	 }
	}
       }while (aux1 > 99 || aux1 < 2 || sw == 1);
	
     for (i=0;i<aux2;i++){
      for (j=0;j<aux2;j++){
       do{     
	 gotoxy(7,8);cprintf("                                              ");
	 gotoxy(7,8);printf("...DIGITE [1] PARA DECIR SI ¢ [0] PARA DECIR NO...");
	 gotoxy(10,5);printf("                                          ");
	 gotoxy(10,5);printf("DEL NODO [%d] AL NODO [%d] EXISTE RUTA? ",i+1,j+1);
	 gets(elem);
	 comprob(elem);
	 if (sw == 0){
	  aux = atoi(elem);
	  if (aux < 0 || aux > 1){
	   gotoxy(7,9);cprintf("... LOS DATOS DEBEN SER [0] ¢ [1] ...");
	   gotoxy(7,9);cprintf("                                      ");
	  }
	 }
	}while(sw == 1 || aux > 1 || aux < 0);
	b[i][j] = a[i][j] = aux;
	if (aux == 1 && i != j){
	 do{
	  gotoxy(10,6);cprintf("                                            ");
	  gotoxy(10,6);cprintf("DIGITE EL COSTO DEL NODO [%d] AL NODO [%d] :",i+1,j+1);
	  gets(pes);
	  comprob(pes);
	  gotoxy(10,6);printf("                                                ");
	  if (sw == 0){
	   xval = atoi(pes);
	   if (xval < 0 || xval > 1000){
	    gotoxy(7,9);cprintf("                                            ");
	    gotoxy(7,9);cprintf("... EL VALOR DEBE ESTAR ENTRE [0] y [99] ...");
	    gotoxy(7,9);cprintf("                                             ");
	   }
	  }
	 }while(sw == 1 || xval > 1000 || xval < 0);
	  val[i][j] = xval;
       }	  
	else
	 val[i][j] = 300;
	  if (i == j)
	  val[i][j] = b[i][j] = a[i][j] = 0;
	}
       }
	ws=1;
	multiplicar();
	//ruta_minima();
	
}

/**************************************************/
void multiplicar()
{
int fil,col,m;
int precede[50][50];
 for (l=1;l<aux1;l++){
  for (i=0;i<aux2;i++){
   for (k=0;k<aux2;k++){
    c[i][k] = 0;
    for (j=0;j<aux2;j++)
     c[i][k] = (c[i][k] + (a[i][j] * b[j][k]));
    }
   }
    for (i=0;i<aux2;i++)
     for(j=0;j<aux2;j++)
      b[i][j] = c[i][j];
  }

}


/**************************************************/
void imprimir(int x[50][50], int comi, int final)
{
 int i,j,col;
 col = comi;

 for (i=0;i<aux2;i++){
  for (j=0;j<aux2;j++){
   gotoxy(comi,final);printf ("%d",x[i][j]);
   comi = comi+3;
  }
   final++;
   comi = col;
 }
}


/**************************************************/
void comprob(char t[4])
{
 int i;
 sw = 0;
 for(i=0;t[i]!='\0';i++){
  if (isdigit(t[i])==0){
   gotoxy(7,9);cprintf("... PULSE SOLO NUMEROS... >>");
   gotoxy(7,9);cprintf("                             ");
   sw = 1;
   break;
  }
}
  if (t[0] == '\0')
   sw = 1;
}
/**************************************************/
void introducir()
{
 char dato[4];
 char lon[4];
 char elem[4];
 char pes[4],op;
 int xval;
 clrscr(); i=0;
 window(1,1,80,25);
 clrscr();
 window(1,1,80,25);
 clrscr();
 for(i=1;i<2001;i++)
 printf("²");
 window(1,1,80,25);textbackground(0);
 window(12,9,70,18);textbackground(1);clrscr();
 window(12,10,70,18);textbackground(12);clrscr();
 i=0;
 
 if (ws == 1) {
  for (i=aux2;i<aux2+1;i++){
   for (j=0;j<aux2+1;j++){
   do{
     gotoxy(4,8);printf("                                              ");
     gotoxy(4,8);printf("...ESCRIBA [1] PARA CONTESTAR SI 0 [0] PARA DECIR NO...");
     gotoxy(10,3);printf("     					  ");
     gotoxy(10,3);printf("DEL NODO %d AL NODO %d HAY RUTA ? ",i+1,j+1);
     gets(elem);
     comprob(elem);
     if (sw == 0){
      aux = atoi(elem);
       if (aux < 0 || aux > 1){
	gotoxy(7,9);cprintf("... LOS DATOS DEBEN SER [0] ¢ [1] ...");
	gotoxy(7,9);cprintf("                                      ");
	}
      }
     }while(sw == 1 || aux > 1 || aux < 0);
       b[i][j] = a[i][j] = aux;
       if (aux == 1 && i != j){
	 do{	
	  gotoxy(10,4);printf("                                            ");
	  gotoxy(10,4);printf("DIGITE EL COSTO DEL NODO %d AL NODO %d :",i+1,j+1);
	  gets(pes);
	  comprob(pes);
	  gotoxy(10,6);printf("                                    	");
	  if (sw == 0){
	    xval = atoi(pes);
	    if (xval < 0 || xval > 99){
	     gotoxy(7,9);cprintf("                                        ");
	     gotoxy(7,9);cprintf("... LOS VALORES DEBEN ESTAR ENTRE [0] y [99] ...");
	     gotoxy(7,9);cprintf("                                                ");
	    }
	   }
	  }while(sw == 1 || xval > 99 || xval < 0);
		val[i][j] = xval;
	}
	 else
	 val[i][j] = 300;
	 if (i == j)
	  val[i][j] = b[i][j] = a[i][j] = 0;
	}
       }
	aux2++;
	multiplicar();
  //ruta_minima();
  }
  else {
       gotoxy(10,9);cprintf("... NO EXISTEN NODOS EN EL GRAFO...");
       gotoxy(10,9);cprintf("                                   ");		
	}
	menu();
}


/**************************************************/
void cancelar()
{
 char elim[4];
 int xelim,i,x;
 clrscr();

 if (ws == 1) {
  do{      textcolor(4);
   textbackground(15);
   gotoxy(15,10);printf("                             ");	
   gotoxy(15,10);printf("DIGITE NODO A CANCELAR: ");	
   gets(elim);
   comprob(elim);
   if (sw == 0){
    xelim = atoi(elim);
    if (xelim < 0 || xelim > aux2){
     gotoxy(25,18);cprintf("... El NODO DEBE SER < %d ...",aux2);
     gotoxy(25,18);cprintf("                                 ");
    }
   }
  }while(sw == 1 || xelim > aux2 || xelim < 0);
  xelim--;
  for (i=xelim;i<=xelim;i++){
   for (j=0;j<aux2;j++){
    c[i][j] = 0;
    val[i][j] = 0;
    b[i][j] = 0;
    a[i][j] = 0;
  }
 }
}
else {
      gotoxy(30,18);cprintf("... NO EXISTEN NODOS EN EL GRAFO ...");
      gotoxy(25,18);cprintf("                                    ");		
      }
     menu();
}


/**************************************************/
void ruta_minima()
{
char op,inic[4],fin[4];
int pdd, precede[50],sw2,xinic,xfin,fil,col;


do {
 do {	
  sw2 = 0;
  gotoxy(20,18);printf("                              ");
  gotoxy(20,18);printf("DIGITE EL ELEMENTO INICIAL: ");
  gets(inic);
  comprob(inic);
  gotoxy(20,18);printf("                              ");
  if (sw == 0){
   xinic = atoi(inic);
   if (xinic > aux2 || xinic < 1) {
    gotoxy(20,18);cprintf("                                 ");
    gotoxy(20,18);cprintf("... ESTE NODO NO EXISTE ...");
    gotoxy(20,18);cprintf("                            ");
    sw2 = 1;
   }
  }
 }while(sw == 1 || sw2 == 1);
 
 do {	
   sw2 = 0;
   gotoxy(20,18);printf("                              ");
   gotoxy(20,18);printf("DIGITE EL ELEMENTO FINAL: ");
   gets(fin);
   comprob(fin);
   gotoxy(20,18);printf("                              ");
   if (sw == 0){
   xfin = atoi(fin);
   if (xfin > aux2 || xfin < 1) {
   gotoxy(20,18);printf("                                 ");
   gotoxy(20,18);printf("... ESTE NODO NO EXISTE ...");
   gotoxy(20,19);printf("                                 ");
   sw2 = 1;
  }
 }
}while(sw == 1 || sw2 == 1);
 gotoxy(15,12);printf("                                             ");
 gotoxy(15,12);cprintf("LA RUTA MINIMA ENTRE EL NODO [%d] y [%d] ES : ",xinic,xfin);
 funcion(xinic-1,xfin-1,&pdd,precede);
 if (pdd == 0){
  gotoxy(15,12);printf("                                         ");
  gotoxy(15,12);printf("... NO HAY RUTA MINIMA DEL NODO [%d] AL [%d]...",xinic,xfin);
 }
 else{ 
    gotoxy(56,12);cprintf("    ");
    gotoxy(56,12);textcolor(4);cprintf("%d",pdd); // RESULTADO DE RUTA MINIMA
   }
    gotoxy(18,18);printf("                                                ");
    gotoxy(18,18);printf("...DIGITE <S> PARA CONTINUAR o <ESC> PARA SALIR...");
    op = getche();
    gotoxy(18,18);printf("                                                  ");
    gotoxy(15,12);printf("                                                  ");
    gotoxy(56,12);cprintf("    ");
   }while (op == 'c' || op == 'C');
  menu();
}


/**************************************************/
void funcion(int s,int t,int *pd,int precede[50])
{  
 int distancia[50],perm[50];
 int actual,i,k,dc;
 int smalldist,newdist;
 
 for(i=0;i<aux2;++i){
  perm[i] = 0;//NOMIEMBRO
  distancia[i] = 300;//INFINITO
 }
  perm[s] = 1; //MIEMBRO
  distancia[s] = 0;
  actual = s;
  while(actual != t){
   smalldist = 300;  //INFINITO
   dc = distancia[actual];
   for(i=0;i<aux2;++i)
   if(perm[i] == 0){
    newdist = dc + val[actual][i];
    if (newdist < distancia[i]) {
     distancia[i] = newdist;
     precede[i] = actual;
    }
     if (distancia[i] <= smalldist) {
      smalldist = distancia[i];
      k=i;
     }
    }
      actual = k;
      perm[actual] = 1; //MIEMBRO
     }
  *pd = distancia[t];
  
} 



/*****************************************************/
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


/**************************************************/
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

  textbackground(0);
  window(35,7,50,9);clrscr();marco(1,1,16,3);
  
  textbackground(1);
  window(33,6,48,8);clrscr();marco(1,1,16,3);
  gotoxy(2,2);textcolor(3);
  cprintf("menu PRINCIPAL");

  textbackground(0);
  window(27,12,59,19);clrscr();
  
  textbackground(1);
  window(25,11,57,18);clrscr();marco(1,1,33,8);
  textcolor(3);
  gotoxy(6,2);
  cprintf("1.INICIAR RUTAS");
  gotoxy(6,3);
  cprintf("2.INSERTAR NODOS");
  gotoxy(6,4);
  cprintf("3.CANCELAR RUTAS");
  gotoxy(6,5);
  cprintf("4.RUTA MINIMA");
  gotoxy(6,6);
  cprintf("5.SALIR");


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
	     gotoxy(5,wherey()+4);
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
	     gotoxy(5,wherey()-4);
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

   if(op==6)
    {
       SALIR='S';
    }

  else
  {

     switch(op)
     {

       case 2:inicio();break;
       case 3:window(1,1,80,25);clrscr();introducir();break;
       case 4:window(1,1,80,25);clrscr();cancelar();break;
       case 5:window(1,1,80,25);clrscr();ruta_minima();break;
       case 6:exit(0);
  
      
      }

  }
    } while(SALIR!='S');
}


