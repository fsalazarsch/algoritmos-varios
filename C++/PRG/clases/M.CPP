#include <alloc.h>
#include<time.h>
#include<stdio.h>
#include<alloc.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define l(x) textcolor(x);
#define f(x) textbackground(x); 

void crear_nodo();
void multiplica();
void imprime(int x[50][50], int co, int fi);
void comprobar(char t[4]);
void DIJKSTRA(int s,int t,int *pd,int precede[50]);
void consultar();      //inicia_DIJKSTRA();
void cuadro();
void menu();
void adicionar_nodo();
void eliminar();

int i,j,k,l,xelem,cont,xlon,xtam,sw,SW=0;
int c[50][50], a[50][50], b[50][50],peso[50][50];

//**********************************
main () 
{
	char c;
	clrscr();
	cuadro();
	menu();
}
//********************
void crear_nodo()
{ 
char tam[4];
char lon[4];
char elemento[4];
char pes[4],op;
int valor;
clrscr();
cuadro();
	
do {

     gotoxy(15,8);printf("                                                    ");
	gotoxy(15,8); printf("DIGITE EL NUMERO DE CIUDADES EN EL GRAFO [2,6]:");  
	gets(tam);
	comprobar(tam);
	if (sw == 0){
	xtam = atoi(tam);
	if (xtam > 50 || xtam < 2){
	gotoxy(20,19);cprintf("                                       ");
		}
		}
	  }while (xtam > 50 || xtam < 2 || sw == 1);
	  
do {
gotoxy(15,9);printf("                                                     ");
gotoxy(15,9);printf("CUANTAS RUTAS DESEA CALCULAR [2,99]? ");
gets(lon);
comprobar(lon);
if (sw == 0){
  xlon = atoi(lon);
 }
  }while (xlon > 99 || xlon < 2 || sw == 1);
	
  for (i=0;i<xtam;i++){
    for (j=0;j<xtam;j++){
	do{
	gotoxy(15,10);printf("                                              ");
				 
	gotoxy(15,10);printf("SI=[1]  Y  NO=[0]");
	gotoxy(15,11);printf("                                          ");
	gotoxy(15,11);printf("DE LA CUIDAD %d A LA CIUDAD %d HAY RUTA? ",i+1,j+1);
	gets(elemento);
	comprobar(elemento);
				
 if (sw == 0){
  xelem = atoi(elemento);
   if (xelem < 0 || xelem > 1){	
     }
  }  
}while(sw == 1 || xelem > 1 || xelem < 0);

b[i][j] = a[i][j] = xelem;
if (xelem == 1 && i != j){
  do{	
gotoxy(15,12);printf("                                            ");
gotoxy(15,12);printf("DIGITE EL PESO DE LA CIUDAD %d A LA CIUDAD %d [0,99]: ",i+1,j+1);
gets(pes);
comprobar(pes);
gotoxy(15,12);printf("                                                               ");
if (sw == 0){
valor = atoi(pes);
if (valor < 0 || valor > 99){
				
	}
  }    

  }while(sw == 1 || valor > 99 || valor < 0);
	peso[i][j] = valor;
	}
	else
	peso[i][j] = 300;
if (i == j)
peso[i][j] = b[i][j] = a[i][j] = 0;
	}
	}
SW=1;
multiplica();
       
      
    }	

//**********************
void multiplica()
{
int fila,columna,m;
int precede[50][50];
 clrscr();
 for (l=1;l<xlon;l++){
	for (i=0;i<xtam;i++){
		for (k=0;k<xtam;k++){
			c[i][k] = 0;
			for (j=0;j<xtam;j++)
					c[i][k] = (c[i][k] + (a[i][j] * b[j][k]));
		}
	}
	for (i=0;i<xtam;i++)
		for(j=0;j<xtam;j++)
			b[i][j] = c[i][j];
 }

columna = 11;
fila = 14;
			// de aqui pa'bajo imprime las matrices
gotoxy(12,13);printf("MATRIZ INICIAL");
imprime(a,columna+1,fila);
gotoxy(56,13);printf("MATRIZ DE PESO");
imprime(peso,columna+46,fila);
			//IMPRIME EL PESO 0 (CERO) DE NODOS QUE NO ES ADYACENTE

columna = 47;fila = 14;
for (i=0;i<xtam;i++){
	for (j=0;j<xtam;j++){
		if (peso[i][j] == 300){
			gotoxy(columna,fila);printf ("0  ");
		}
		columna=columna+3;
	}
	fila++; columna = 47;
}

}
//************************
void imprime(int x[50][50], int co, int fi)
{
 int i,j,columna;
 columna = co;

	for (i=0;i<xtam;i++){
		for (j=0;j<xtam;j++){
			gotoxy(co,fi);printf ("%d",x[i][j]);
			co = co+3;
		}
		fi++;
		co = columna;
	}
}

//***********************************
void comprobar(char t[4])
{
	int i;
	sw = 0;
	for(i=0;t[i]!='\0';i++){
		if (isdigit(t[i])==0){
			textcolor(LIGHTRED);
			gotoxy(20,19);cprintf("­ Este dato no debe ser un CARACTER !");
			textcolor(LIGHTGRAY);
			gotoxy(20,19);cprintf("                                     ");
			sw = 1;
			break;
		}
	}
	if (t[0] == '\0')
		sw = 1;
}
//**********************
void consultar()        //inicia_DIJKSTRA()
{
char op,inic[4],fin[4];
int pdd, precede[50],sw2,xinic,xfin,fila,columna;
clrscr();

 do {	
while(sw == 1 || sw2 == 1);
 
 do {	
	sw2 = 0;
	gotoxy(20,19);printf("                              ");
	gotoxy(20,19);printf("Digite el elemento final: ");
	gets(fin);
	comprobar(fin);
	gotoxy(20,19);printf("                              ");
	if (sw == 0){
		xfin = atoi(fin);
		if (xfin > xtam || xfin < 1) {
			textcolor(12);
			gotoxy(20,19);printf("                                 ");
			gotoxy(20,19);printf("­ Este nodo o vertice no Existe !");
			
			textcolor(7);
			gotoxy(20,19);printf("                                 ");
			sw2 = 1;
		}
	}
 }while(sw == 1 || sw2 == 1);
 gotoxy(15,12);printf("                                             ");
 gotoxy(15,12);textcolor(3);cprintf("La ruta m¡nima entre el nodo %d y %d es: ",xinic,xfin);
 DIJKSTRA(xinic-1,xfin-1,&pdd,precede);
 if (pdd == 0){
	gotoxy(15,12);printf("                                         ");
	gotoxy(15,12);printf("No hay ruta m¡nima del nodo %d al %d",xinic,xfin);
 }
 else{
	gotoxy(56,12);cprintf("    ");
	gotoxy(56,12);textcolor(LIGHTCYAN);cprintf("%d",pdd); // RESULTADO DE RUTA MINIMA
 }
 gotoxy(18,19);printf("                                                ");
 gotoxy(18,19);printf("Pulse < C > y continue o cualquiera para salir");
 op = getche();
 gotoxy(18,19);printf("                                                ");
 gotoxy(15,12);printf("                                               ");
 gotoxy(56,12);cprintf("    ");textcolor(LIGHTGRAY);
}while (op == 'c' || op == 'C');
getche();
}

//**********************************
void DIJKSTRA(int s,int t,int *pd,int precede[50])
{
	int distancia[50],perm[50];
	int actual,i,k,dc;
	int smalldist,newdist;
 
	for(i=0;i<xtam;++i){
		perm[i] = 0;//NOMIEMBRO
		distancia[i] = 300;//INFINITO
	}
	perm[s] = 1; //MIEMBRO
	distancia[s] = 0;
	actual = s;
	while(actual != t){
		smalldist = 300;  //INFINITO
		dc = distancia[actual];
		for(i=0;i<xtam;++i)
			if(perm[i] == 0){
				newdist = dc + peso[actual][i];
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
		perm[actual] = 1; 
	}
  *pd = distancia[t];
}
//****************************
void cuadro()
{ 	int i;
	for (i=10;i<=70;i++) {
		gotoxy(i,4);cprintf("Í");
		gotoxy(i,20);cprintf("Í");
		gotoxy(i,18);cprintf("Í");
		gotoxy(i,6);cprintf("Í");
	}
	for (i=5;i<=20;i++) {
		gotoxy(10,i);cprintf("º");
		gotoxy(70,i);cprintf("º");
	}
	gotoxy(10,4);cprintf("É");
	gotoxy(70,4);cprintf("»");
	gotoxy(10,20);cprintf("È");
	gotoxy(70,20);cprintf("¼");
	textcolor(LIGHTCYAN);
	gotoxy(19,5); cprintf("****** PROGRAMA DE COSTO MINIMO ******");
	textcolor(LIGHTGRAY);

} 
/***************************************************************************/
void menu()
{ char c[35],op;int n,i;
do{
//* marcar(0,15);
 window(1,1,80,25);
 textbackground(1);clrscr();
 textcolor(14);
 gotoxy(6,4);printf("  M   E   N   U      P   R   I   N   C   I    P    A   L ");
 
  textcolor(14);
 /*delay(30);*/gotoxy(28,9);cprintf("1. INICIAR                    ");
 /*delay(30);*/gotoxy(28,10);cprintf("2. ELIMINAR   ");
  /*delay(30);*/gotoxy(28,11);cprintf("3. ADICIONAR  ");
  /*delay(30);*/gotoxy(28,12);cprintf("4. CONSULTAR ");
  /*delay(30);*/gotoxy(28,13);cprintf("5. MATRICES    ");
  /*delay(30);*/gotoxy(28,14);cprintf("6. SALIR        ");
  /*delay(30);*/gotoxy(18,19);cprintf("   DIGITE SU OPCION :              ");
  

  do
  {
   gotoxy(39,19);clreol(); op=getch();
  }while((op>'6') ||(op<'1'));
   switch(op){
   case'1':crear_nodo();;break;
   case'2':clrscr(); eliminar(); break;
   case'3':clrscr(); adicionar_nodo(); break;
   case'4':clrscr(); consultar(); break;
   case'5':multiplica();break;
   case'6':exit(0);
  }
}while(op!='6');
}

/**************************************************************************/
//************************************
void adicionar_nodo()

{
	char tam[4];
	char lon[4];
	char elemento[4];
	char pes[4],op;
	int valor;
	clrscr();
	cuadro();
  if (SW == 1) {
	for (i=xtam;i<xtam+1;i++){
		for (j=0;j<xtam+1;j++){
			do{
				gotoxy(15,10);printf("                                              ");
				gotoxy(15,10);printf("Escriba 1 para contestar SI, ¢ 0 para decir NO");
				gotoxy(15,11);printf("                                          ");
				gotoxy(15,11);printf("Del nodo %d al nodo %d hay ruta? ",i+1,j+1);
				gets(elemento);
				comprobar(elemento);
				if (sw == 0){
					xelem = atoi(elemento);
					if (xelem < 0 || xelem > 1){
						textcolor(LIGHTRED);
						gotoxy(25,19);cprintf("­ Los datos deben ser 0 ¢ 1 !");
						textcolor(LIGHTGRAY);
						gotoxy(25,19);cprintf("                                 ");
					}
				}
			}while(sw == 1 || xelem > 1 || xelem < 0);
			b[i][j] = a[i][j] = xelem;
			if (xelem == 1 && i != j){
			  do{	
				gotoxy(15,12);printf("                                            ");
				gotoxy(15,12);printf("Digite el costo del nodo %d al nodo %d ",i+1,j+1);
				gets(pes);
				comprobar(pes);
				gotoxy(15,12);printf("                                            ");
				if (sw == 0){
					valor = atoi(pes);
					if (valor < 0 || valor > 99){
						textcolor(LIGHTRED);
						gotoxy(20,19);cprintf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    nodos !");
	  textcolor(LIGHTGRAY);
	  gotoxy(25,19);cprintf("                         ");		
	}
      }

//*******************************************
void eliminar()
{
	char elim[4];
	int xelim,i,x;
	clrscr();
	cuadro();
	if (SW == 1) {
	do{
		 gotoxy(15,10);printf("                             ");	
		 gotoxy(15,10);printf("Escriba Nodo a cancelar: ");	
		 gets(elim);
		 comprobar(elim);
		 if (sw == 0){
			 xelim = atoi(elim);
			 if (xelim < 0 || xelim > xtam){
				 textcolor(12);
				 gotoxy(25,19);cprintf("­ El Nodo debe ser menor que %d !",xtam);
				 textcolor(7);
				 gotoxy(25,19);cprintf("                                 ");
			 }
		 }
	}while(sw == 1 || xelim > xtam || xelim < 0);
	xelim--;
	for (i=xelim;i<=xelim;i++){
		for (j=0;j<xtam;j++){
			 c[i][j] = 0;
			 peso[i][j] = 0;
			 b[i][j] = 0;
			 a[i][j] = 0;
		}
	}
	}
	else {
		textcolor(LIGHTRED);
				 gotoxy(30,19);cprintf("­ No existen nodos !");
				 textcolor(LIGHTGRAY);
				 gotoxy(25,19);cprintf("                         ");		
	}
       //menu();
}
//**********************
