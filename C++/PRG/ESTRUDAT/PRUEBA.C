
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>

void INICIAR();
void GRAFOS();
void MULTIPLICAR();
void IMPRIMIR(int x[50][50], int co, int fi);
void ALARMA();
void COMPROBAR(char t[4]);
void DIJKSTRA(int s,int t,int *pd,int precede[50]);
void RUTA_MIN();
void CUADROS(int x1,int x2,int y1,int y2);
void MENU();
void INSERTAR();
void CANSELAR();

int i,j,k,l,NAUX,CONT,NLON,NSTM,SW,ST=0;
int c[50][50], a[50][50], b[50][50],VALOR[50][50];

//**********************************
main () 
{
	char c;
	clrscr();
       GRAFOS();
       getche();
      MENU();
}
//********************
void INICIAR()
{ 
	char tam[4];
	char lon[4];
	char elem[4],info[10];
	char pes[4],op;
	int xVALOR,i;
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
	 i=0;
	 gotoxy(i+49,8);
	
	do {
	  do {  
		gotoxy(15,8);printf("                                       ");
		gotoxy(15,8); printf("NUMERO DE ELEMENTOS EN EL GRAFOS:");

		scanf(info);
		gets(tam);
		COMPROBAR(tam);

		if (SW == 0){
			NSTM = atoi(tam);
			if (NSTM > 50 || NSTM < 2){
				textcolor(1);
			 textbackground(15);
			 
				gotoxy(20,18);cprintf("<< ESTE NUMERO DEBE ESTAR [2] y [50] >>");
				ALARMA();
				
				textbackground(15);
				gotoxy(20,18);cprintf("                                       ");
			}
		  else
     {
     if(info[i]=='\r'&&i>0) break;
     if(!isdigit(info[i])) i--;
     }
    i++;
		}
	  }while (NSTM > 50 || NSTM < 2 || SW == 1);
		textcolor(1);
		textbackground(15);
		 
		textbackground(15);
				
		gotoxy(18,18);cprintf("PARA LA MEJOR COMPRENSION DE ESTE PROGRAMA");
		sleep(2);
		gotoxy(18,18);cprintf("                                    ");
		gotoxy(11,18);cprintf("SE RECOMIENDA LA COMPAฅIA DE PADRES O ADULTOS RESPONSABLES");
		sleep(2);
		gotoxy(11,18);cprintf("                                                           ");
		gotoxy(18,18);cprintf("Y SE RECOMIENDE UN NUMERO NO MAYOR DE [6] ELEMENTOS");
		sleep(2);
		gotoxy(18,18);cprintf("                                                   ");
		gotoxy(21,18);cprintf("PULSE <C> PARA CORREGIR, SINO <ENTER>");
		op = getche();
		textbackground(15);
		gotoxy(21,18);cprintf("                                        ");

	  }while(op == 'c' || op == 'C');
	do {    textcolor(4);
		gotoxy(15,9);cprintf("                                                     ");
		gotoxy(15,9);cprintf("DIGITE LOS CAMINOS [N] QUE DESEA CALCULAR : ");
		gets(lon);
		COMPROBAR(lon);
		if (SW == 0){
			NLON = atoi(lon);
			if (NLON < 2 || NLON > 99){
				textcolor(1);
			 textbackground(15);
			 
				gotoxy(18,18);cprintf("<< EL CAMINO [N] DEBE ESTAR ENTRE [2] ข [99] >>");
				ALARMA();
				
				textbackground(15);
				gotoxy(18,18);cprintf("                                                 ");
			}
		}
	}while (NLON > 99 || NLON < 2 || SW == 1);
	
	for (i=0;i<NSTM;i++){
		for (j=0;j<NSTM;j++){
			do{     textbackground(15);
				gotoxy(15,10);cprintf("                                              ");
				gotoxy(15,10);printf("DIGITE [1] PARA DECIR SI ข [0] PARA DECIR NO");
				gotoxy(15,11);printf("                                          ");
				gotoxy(15,11);printf("DEL NODO [%d] AL NODO [%d] HAY RUTA? ",i+1,j+1);
				gets(elem);
				COMPROBAR(elem);
				if (SW == 0){
					NAUX = atoi(elem);
					if (NAUX < 0 || NAUX > 1){
						textcolor(1);
						textbackground(15);
						
						gotoxy(25,18);cprintf("<< LOS DATOS DEBEN SER [0] ข [1] >>");
						ALARMA();
						
						textcolor(4);
						textbackground(15);
						gotoxy(25,18);cprintf("                                    ");
					}
				}
			}while(SW == 1 || NAUX > 1 || NAUX < 0);
			b[i][j] = a[i][j] = NAUX;
			if (NAUX == 1 && i != j){
			  do{	textcolor(4);
				gotoxy(15,12);cprintf("                                            ");
				gotoxy(15,12);cprintf("DIGITE EL COSTO DEL NODO [%d] AL NODO [%d] ",i+1,j+1);
				gets(pes);
				COMPROBAR(pes);
				textbackground(15);
				gotoxy(15,12);printf("                                            ");
				if (SW == 0){
					xVALOR = atoi(pes);
					if (xVALOR < 0 || xVALOR > 99){
						
						textcolor(1);
						textbackground(15);
						
						gotoxy(20,18);cprintf("                                        ");
						gotoxy(20,18);cprintf("<< EL VALOR DEBE ESTAR ENTRE [0] y [99] >>");
						ALARMA();
						
						textcolor(4);
						textbackground(15);
						gotoxy(20,18);cprintf("                                           ");
					}
				}
			  }while(SW == 1 || xVALOR > 99 || xVALOR < 0);
				VALOR[i][j] = xVALOR;
			}
			else
				VALOR[i][j] = 300;
			if (i == j)
					VALOR[i][j] = b[i][j] = a[i][j] = 0;
		}
	}
	ST=1;
	MULTIPLICAR();
	//RUTA_MIN();
	
}
//**********************
void MULTIPLICAR()
{
int fil,col,m;
int precede[50][50];
 for (l=1;l<NLON;l++){
	for (i=0;i<NSTM;i++){
		for (k=0;k<NSTM;k++){
			c[i][k] = 0;
			for (j=0;j<NSTM;j++)
					c[i][k] = (c[i][k] + (a[i][j] * b[j][k]));
		}
	}
	for (i=0;i<NSTM;i++)
		for(j=0;j<NSTM;j++)
			b[i][j] = c[i][j];
 }

}
//************************
void IMPRIMIR(int x[50][50], int co, int fi)
{
 int i,j,col;
 col = co;

	for (i=0;i<NSTM;i++){
		for (j=0;j<NSTM;j++){
			gotoxy(co,fi);printf ("%d",x[i][j]);
			co = co+3;
		}
		fi++;
		co = col;
	}
}

//***********************************
void COMPROBAR(char t[4])
{
	int i;
	SW = 0;
	for(i=0;t[i]!='\0';i++){
		if (isdigit(t[i])==0){
			textcolor(1);
			 textbackground(15);
			 
			gotoxy(20,18);cprintf("<< ESTE DATO NO DEBE SER CARACTER >>");
			ALARMA();
			gotoxy(20,18);cprintf("                                     ");
			SW = 1;
			break;
		}
	}
	if (t[0] == '\0')
		SW = 1;
}
//**********************
void ALARMA()
{
	int i;
	for(i=1;i<4;i++){
		delay(100);
		sound(900);
		delay(190);
		sound(500);
		delay(100);
	}
	 nosound();
}
//**************************
void RUTA_MIN()
{
char op,inic[4],fin[4];
int pdd, precede[50],SW2,xinic,xfin,fil,col;
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);

do {
 
 do {	
	SW2 = 0;
	textcolor(4);
 textbackground(15);
	gotoxy(20,18);printf("                              ");
	textcolor(4);
 textbackground(15);
	gotoxy(20,18);printf("DIGITE EL ELEMENTO INICIAL: ");
	gets(inic);
	COMPROBAR(inic);
	gotoxy(20,18);printf("                              ");
	if (SW == 0){
		xinic = atoi(inic);
		if (xinic > NSTM || xinic < 1) {
			textcolor(1);
			textbackground(15);
			
			gotoxy(20,18);cprintf("                                 ");
			gotoxy(20,18);cprintf("<< ESTE NODO O VERTICE NO EXISTE >>");
			ALARMA();
			textcolor(4);
			textbackground(15);
			gotoxy(20,18);cprintf("                                    ");
			SW2 = 1;
		}
	}
 }while(SW == 1 || SW2 == 1);
 
 do {	
	SW2 = 0;
	textcolor(4);
	textbackground(15);
	gotoxy(20,18);printf("                              ");
	gotoxy(20,18);printf("DIGITE EL ELEMENTO FINAL: ");
	gets(fin);
	COMPROBAR(fin);
	textcolor(4);
	textbackground(15);
	gotoxy(20,18);printf("                              ");
	if (SW == 0){
		xfin = atoi(fin);
		if (xfin > NSTM || xfin < 1) {
			gotoxy(20,18);printf("                                 ");
			textcolor(1);
			 textbackground(15);
			 
			gotoxy(20,18);printf("<< ESTE NODO O VERTICE NO EXISTE >>");
			ALARMA();
			textcolor(4);
			textbackground(15);
			gotoxy(20,19);printf("                                 ");
			SW2 = 1;
		}
	}
 }while(SW == 1 || SW2 == 1);
 gotoxy(15,12);printf("                                             ");
 gotoxy(15,12);textcolor(4);cprintf("LA RUTA MINIMA ENTRE EL NODO [%d] y [%d] ES : ",xinic,xfin);
 DIJKSTRA(xinic-1,xfin-1,&pdd,precede);
 if (pdd == 0){
	textcolor(4);
	textbackground(15);
	gotoxy(15,12);printf("                                         ");
	gotoxy(15,12);printf("NO HAY RUTA MINIMA DEL NODO [%d] AL [%d]",xinic,xfin);
 }
 else{  textcolor(4);
	textbackground(15);
	gotoxy(56,12);cprintf("    ");
	gotoxy(56,12);textcolor(4);cprintf("%d",pdd); // RESULTADO DE RUTA MINIMA
 }
 textcolor(4);
 textbackground(15);
 gotoxy(18,18);printf("                                                ");
 gotoxy(18,18);printf("DIGITE <C> Y CONTINUE o <ESC> PARA SALIR");
 op = getche();
 gotoxy(18,18);printf("                                                ");
 gotoxy(15,12);printf("                                               ");
 gotoxy(56,12);cprintf("    ");
}while (op == 'c' || op == 'C');
MENU();
}
//**********************************
void DIJKSTRA(int s,int t,int *pd,int precede[50])
{  
	int distancia[50],perm[50];
	int actual,i,k,dc;
	int smalldist,newdist;
 
	for(i=0;i<NSTM;++i){
		perm[i] = 0;//NOMIEMBRO
		distancia[i] = 300;//INFINITO
	}
	perm[s] = 1; //MIEMBRO
	distancia[s] = 0;
	actual = s;
	while(actual != t){
		smalldist = 300;  //INFINITO
		dc = distancia[actual];
		for(i=0;i<NSTM;++i)
			if(perm[i] == 0){
				newdist = dc + VALOR[actual][i];
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
//****************************

 void CUADROS(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(14);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("อ");
       gotoxy(j,y2);cprintf("อ");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("บ");
       gotoxy(x2,i);cprintf("บ");
       }
     gotoxy(x1,y1);cprintf("ษ");
     gotoxy(x2,y1);cprintf("ป");
     gotoxy(x1,y2);cprintf("ศ");
     gotoxy(x2,y2);cprintf("ผ");
  //return(0);
}

/*****************************************************/
//******************************
void MENU()
{
	

char op,c;
 do{
 clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
  
    textcolor(14+128);
    textcolor(14);
    gotoxy (30,8); cprintf("<< MENU PRINCIPAL >>");
    textcolor(4);
  gotoxy(22,3);printf("CORPORACION UNIVERSITARIA DEL SANTANDER");  
  gotoxy(29,5);printf("DARWIN HELMUTHS LEON PEREZ");
  gotoxy(29,22);printf("CODIGO: 96132068");
  gotoxy(28,10);printf("[1]. INICIO DE RUTAS");
  gotoxy(28,11);printf("[2]. CANCELAR RUTAS");
  gotoxy(28,12);printf("[3]. ADICIONAR");
  gotoxy(28,13);printf("[4]. RUTA MINIMA");
  gotoxy(28,14);printf("[5]. SALIR DEL PROGRAMA..");
  
    
    gotoxy (28,18);printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case '1':INICIAR();break;
    case '2':CANSELAR();break;
    case '3':INSERTAR();break;
    case '4':RUTA_MIN();break;
    case '5':exit(0);
    getche();  
     }
     }while(op!='5');
   
     }


/*****************************************************/

//************************************
void INSERTAR()
{
	char tam[4];
	char lon[4];
	char elem[4];
	char pes[4],op;
	int xVALOR;
	clrscr();
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 
  if (ST == 1) {
	for (i=NSTM;i<NSTM+1;i++){
		for (j=0;j<NSTM+1;j++){
			do{
				gotoxy(15,10);printf("                                              ");
				gotoxy(15,10);printf("ESCRIBA [1] PARA CONTESTAR SI 0 [0] PARA DECIR NO");
				gotoxy(15,11);printf("                                          ");
				gotoxy(15,11);printf("DEL NODO %d AL NODO %d HAY RUTA ? ",i+1,j+1);
				gets(elem);
				COMPROBAR(elem);
				if (SW == 0){
					NAUX = atoi(elem);
					if (NAUX < 0 || NAUX > 1){
						textcolor(1);
						     textbackground(15);
						     textcolor(4+128);
						gotoxy(25,18);cprintf("<< LOS DATOS DEBEN SER [0] ข [1] >>");
						ALARMA();
						textcolor(4);
						gotoxy(25,18);cprintf("                                 ");
					}
				}
			}while(SW == 1 || NAUX > 1 || NAUX < 0);
			b[i][j] = a[i][j] = NAUX;
			if (NAUX == 1 && i != j){
			  do{	
				gotoxy(15,12);printf("                                            ");
				gotoxy(15,12);printf("DIGITE EL COSTO DEL NODO %d AL NODO %d ",i+1,j+1);
				gets(pes);
				COMPROBAR(pes);
				gotoxy(15,12);printf("                                    	");
				if (SW == 0){
					xVALOR = atoi(pes);
					if (xVALOR < 0 || xVALOR > 99){
						textcolor(1);
						textbackground(15);
						
						gotoxy(20,18);cprintf("                                        ");
						gotoxy(20,18);cprintf("<< LOS VALORES DEBEN ESTAR ENTRE [0] y [99] >>");
						ALARMA();
						textcolor(4);
						textcolor(4);
						textbackground(15);
						gotoxy(20,18);cprintf("                                        ");
					}
				}
			  }while(SW == 1 || xVALOR > 99 || xVALOR < 0);
				VALOR[i][j] = xVALOR;
			}
			else
				VALOR[i][j] = 300;
			if (i == j)
					VALOR[i][j] = b[i][j] = a[i][j] = 0;
		}
	}
	NSTM++;
	MULTIPLICAR();
  //RUTA_MIN();
  }
  else {
	  textcolor(1);
     textbackground(15);
     
	  gotoxy(30,18);cprintf("<< NO EXISTEN NODOS >>");
	  ALARMA();
	  textcolor(4);
	  textbackground(15);
	  gotoxy(25,18);cprintf("                         ");		
	}
	MENU();
}
//*******************************************
void CANSELAR()
{
	char elim[4];
	int xelim,i,x;
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 
	if (ST == 1) {
	do{      textcolor(4);
		 textbackground(15);
		 gotoxy(15,10);printf("                             ");	
		 gotoxy(15,10);printf("DIGITE NODO A CANCELAR: ");	
		 gets(elim);
		 COMPROBAR(elim);
		 if (SW == 0){
			 xelim = atoi(elim);
			 if (xelim < 0 || xelim > NSTM){
				 textcolor(1);
				 textbackground(15);
				 
				 gotoxy(25,18);cprintf("<< El NODO DEBE SER < %d >>",NSTM);
				 ALARMA();
				 textcolor(4);
				 textbackground(15);
				 gotoxy(25,18);cprintf("                                 ");
			 }
		 }
	}while(SW == 1 || xelim > NSTM || xelim < 0);
	xelim--;
	for (i=xelim;i<=xelim;i++){
		for (j=0;j<NSTM;j++){
			 c[i][j] = 0;
			 VALOR[i][j] = 0;
			 b[i][j] = 0;
			 a[i][j] = 0;
		}
	}
	}
	else {
				 textcolor(1);
				 textbackground(15);
				 gotoxy(30,18);cprintf("<< NO EXISTEN NODOS >>");
				 ALARMA();
				 textcolor(4);
				 textbackground(15);
				 gotoxy(25,18);cprintf("                         ");		
	}
	MENU();
}
//**********************
void GRAFOS()
{

textcolor(14); textbackground(0);
gotoxy(12,4); cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
gotoxy(12,5); cprintf("บ                                                         บ");
gotoxy(12,6); cprintf("บ                                                         บ");
gotoxy(12,7); cprintf("บ                                                         บ");
gotoxy(12,8); cprintf("บ                                                         บ");
gotoxy(12,9); cprintf("บ                                                         บ");
gotoxy(12,10);cprintf("บ                                                         บ");
gotoxy(12,11);cprintf("บ                                                         บ");
gotoxy(12,12);cprintf("บ                                                         บ");
gotoxy(12,13);cprintf("บ                                                         บ");
gotoxy(12,14);cprintf("บ                                                         บ");
gotoxy(12,15);cprintf("บ                                                         บ");
gotoxy(12,16);cprintf("บ                                                         บ");
gotoxy(12,17);cprintf("บ                                                         บ");
gotoxy(12,18);cprintf("บ                                                         บ");
gotoxy(12,19);cprintf("บ                                                         บ");
gotoxy(12,20);cprintf("บ                                                         บ");
gotoxy(12,21);cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
textcolor(15+128); textbackground(0);
gotoxy(22,20);cprintf("<< <ENTER> PARA IR AL MENU PRINCIPAL >>");
textcolor(14); textbackground(0);
textcolor(15+128);
gotoxy(28,5);cprintf("<< ESTRUCTURA DE DATOS >>");
textcolor(14); textbackground(15);

gotoxy(15,6); cprintf("ษอออออออออออออออออออออออออออออออออออออออออออออออออออป");
gotoxy(15,7); cprintf("บ                                                   บ");
gotoxy(15,8); cprintf("บ  ÛÛÛÛÛÛ    ÛÛÛÛ     ÛÛÛÛ    ÛÛÛÛÛ   ÛÛÛÛ    ÛÛÛÛ  บ");
gotoxy(15,9); cprintf("บ ÛÛ    ÛÛ  ÛÛÛÛÛÛ   ÛÛ  ÛÛ  ÛÛ   ÛÛ ÛÛ  ÛÛ  ÛÛ  ÛÛ บ");
gotoxy(15,10);cprintf("บ ÛÛ    ÛÛ  ÛÛ   Û   ÛÛ  ÛÛ  ÛÛ   ÛÛ ÛÛ  ÛÛ   Û     บ");
gotoxy(15,11);cprintf("บ ÛÛ        ÛÛ  ÛÛ   ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ    Û    บ");
gotoxy(15,12);cprintf("บ ÛÛ        ÛÛ ÛÛ    ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ     Û   บ");
gotoxy(15,13);cprintf("บ ÛÛ  ÛÛÛ   ÛÛÛÛ     ÛÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛ  ÛÛ     ÛÛ  บ");
gotoxy(15,14);cprintf("บ ÛÛ    ÛÛ  ÛÛ ÛÛ    ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ      ÛÛ บ");
gotoxy(15,15);cprintf("บ ÛÛ    ÛÛ  ÛÛ  ÛÛ   ÛÛ  ÛÛ  ÛÛ      ÛÛ  ÛÛ  ÛÛ ÛÛÛ บ");
gotoxy(15,16);cprintf("บ  ÛÛÛÛÛÛ   ÛÛ   ÛÛ  ÛÛ  ÛÛ  ÛÛ       ÛÛÛÛ    ÛÛÛÛ  บ");
gotoxy(15,17);cprintf("บ                                                   บ");
gotoxy(15,18);cprintf("บ                                                   บ");
gotoxy(15,19);cprintf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออผ");
textcolor(0);
gotoxy(17,18);cprintf("Derechos Reservados del Autor: DARWIN H. LEON P.");
sleep(2);
gotoxy(17,18);cprintf("                                                 ");
gotoxy(22,18);cprintf("PROHIBIDO DARLE [F2] A ESTE PROGRAMA");
sleep(2);
gotoxy(19,18);cprintf("                                     ");
gotoxy(19,18);cprintf("DE HACERLO SE AUTODESTRUIRA SU DISKETTE");
sleep(2);
gotoxy(19,18);cprintf("                                       ");
}


