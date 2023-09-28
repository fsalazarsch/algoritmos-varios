	     //********0PROGRAMA DE GRAFOS********* 
	     //*****LUISA BECERRA******************
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>

void CREACION();
void GRAFOS();
void OPERATION();
void VISUALIZAR(int x[30][30], int co, int fi);
void ALARMA();
void ACCESO(char [4]);
void NO_SE(int s,int t,int *pd,int precede[30]);
void RUTA_MIN();
void CUADROS(int x1,int x2,int y1,int y2);
void MENU();
void AGREGAR();
void ELIMINAR();
void CUADRO3(int x1,int x2,int y1,int y2);
void CUADRO2(int x1,int x2,int y1,int y2);
int i,j,k,l,CONT,NAUX,sw=1,NLON,NSTM,SW,ST=0;
int c[30][30], a[30][30], b[30][30],VALOR[30][30];

//***************************************************************************
//**************************MAIN*************************************************
main () 
{
	char c;
	textbackground(15);
	clrscr();
       GRAFOS();
       getche();
      MENU();
}
//************************************CREAR RUTAS****************************
//***************************************************************************
void CREACION()
       {char grande[4];
	char longitud[4];
	char elementos[4];
	char pesos[4],op,aux[10];
	int xVALOR;
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);

 i=0;   

      

	do {
	  do {        
	        textbackground(5);
		textcolor(14);
		gotoxy(30,5); cprintf("<< CREACION DE RUTAS >>");
		gotoxy(15,8);printf("                                       ");
		gotoxy(15,8); printf("CUANTOS NODOS QUIERE EN EL GRAFOS:");
		  gets(grande);
		  ACCESO(grande);
			 /* do{
		  
    gotoxy(i+49,8);
    textbackground(15);
    clreol();
      aux[i]=getche();
    if(aux[i]=='\b'&&i>0) i-=8;
       
    else
     {
     
     if(aux[i]=='\r'&&i>0) break;
     if(!isdigit(aux[i])) i--;
     
     }
    
    i++;
  }while(i<8);
   aux[i]='\0';*/		
		if (SW == 0){
			
			NSTM = atoi(grande);
			if (NSTM > 30 || NSTM < 2){
				textcolor(1);
			 textbackground(15);
			 
				gotoxy(20,18);cprintf("<< DIGITE UNA CANTIDAD DE [2] A [30] >>");
				ALARMA();
				
				textbackground(15);
				gotoxy(20,18);cprintf("                                        ");
			}
		}
	  }while (NSTM > 30 || NSTM < 2 || SW == 1);
		textcolor(1);
		textbackground(15);
		 
		textbackground(15);
				
		gotoxy(18,18);cprintf("PARA LA MEJOR COMPRENSION DE ESTE PROGRAMA");
		sleep(2);
		gotoxy(18,18);cprintf("                                    ");
		gotoxy(11,18);cprintf("SE RECOMIENDA LA COMPAฅIA DE PADRES O ADULTOS RESPONSABLES");
		sleep(2);
		gotoxy(11,18);cprintf("                                                           ");
		gotoxy(18,18);cprintf("Y SE RECOMIENDA UN NUMERO NO MAYOR DE [6] ELEMENTOS");
		sleep(2);
		gotoxy(18,18);cprintf("                                                   ");
		gotoxy(21,20);cprintf("REEMPLAZAR:[R] CONTINUAR: <ENTER>");
		op = getche();
		textbackground(15);
		gotoxy(21,20);cprintf("                                        ");

	  }while(op== 'r' || op == 'R');
	do {    textcolor(4);
		gotoxy(15,9);cprintf("                                                     ");
		gotoxy(15,9);cprintf("DIGITE LAS RUTAS QUE DESEA CALCULAR : ");
		gets(longitud);
		ACCESO(longitud);
		if (SW == 0){
			NLON = atoi(longitud);
			if (NLON < 2 || NLON > 99){
				textcolor(1);
			 textbackground(15);
			 
				gotoxy(18,18);cprintf("<< DIGITE LA RUTA DE [2] A [99] >>");
				ALARMA();
				
				textbackground(15);
				gotoxy(18,18);cprintf("                                                 ");
			}
		}
	}while (NLON > 99 || NLON < 2 || SW == 1);
	
	for (i=0;i<NSTM;i++){
		for (j=0;j<NSTM;j++){
			do{     
				textcolor(1);
				textbackground(15);
				gotoxy(15,20);cprintf("                                              ");
				gotoxy(15,20);cprintf("DIGITE [1] PARA DECIR SI ข [0] PARA DECIR NO");
				gotoxy(15,11);printf("                                          ");
				gotoxy(15,11);printf("DEL NODO [%d] AL NODO [%d] HAY RUTA ?:",i+1,j+1);
				gets(elementos);
				ACCESO(elementos);
				if (SW == 0){
					NAUX = atoi(elementos);
					if (NAUX > 1 || NAUX < 0){
						textcolor(1);
						textbackground(15);
						
						gotoxy(25,18);cprintf("<< ERROR LOS DATOS DEBEN SER [0] ข [1] >>");
						ALARMA();
						
						textcolor(4);
						textbackground(15);
						gotoxy(25,18);cprintf("                                          ");
					}
				}
			}while(SW == 1 || NAUX > 1 || NAUX < 0);
			b[i][j] = a[i][j] = NAUX;
			if (NAUX == 1 && i != j){
			  do{	textcolor(4);
				gotoxy(15,12);cprintf("                                            ");
				gotoxy(15,12);cprintf("DIGITE EL VALOR DEL NODO [%d] AL NODO [%d] ",i+1,j+1);
				gets(pesos);
				ACCESO(pesos);
				textbackground(15);
				gotoxy(15,12);printf("                                            ");
				if (SW == 0){
					xVALOR = atoi(pesos);
					if (xVALOR < 0 || xVALOR > 99){
						
						textcolor(1);
						textbackground(15);
						
						gotoxy(20,18);cprintf("                                                ");
						gotoxy(20,18);cprintf("<< ERROR EL VALOR DEBE SER DE [0] A [99] >>");
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
	textcolor(14);
	textbackground(1);

	gotoxy(30,15);cprintf("<< RUTAS COMPLETAS >>");
	ALARMA();
	getche();
	MENU();
	
}
//******************************OPERACTION********************************
//************************************************************************
void OPERATION()
{
int fil,col,m;
int precede[30][30];
 if(ST==1){
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

	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);

col = 11;
fil = 9;
textcolor(14);
 textbackground(5);
CUADROS(9,30,7,18);
 CUADROS(30,53,7,18);
 CUADROS(53,72,7,18);
textcolor(14);
 textbackground(5);
gotoxy(30,5); cprintf("<< MUESTRA DE MATRIZ >>");
textcolor(14);
 textbackground(5);
gotoxy(12,8);cprintf("MATRIZ INICIAL");
VISUALIZAR(a,col+1,fil);
textcolor(14);
 textbackground(5);
gotoxy(32,8);cprintf("MATRIZ DE LONGITUD %d",NLON);
VISUALIZAR(c,col+21,fil);
gotoxy(56,8);cprintf("MATRIZ DE PESO");

VISUALIZAR(VALOR,col+46,fil);

col = 47;fil = 9;
for (i=0;i<NSTM;i++){
	for (j=0;j<NSTM;j++){
		if (VALOR[i][j] == 300){
			gotoxy(col,fil);printf ("0  ");
		}
		col=col+3;
	}
	fil++; col = 47;
getche();
MENU();
}
}
else {
	   textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);

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
//***********************************************************************
//************************VISUALIZAR*************************************
void VISUALIZAR(int x[30][30], int co, int fi)
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
//**********************************************************************
//***************************VALIDA LETRAS******************************
void ACCESO(char t[4])
{
	int i,r;
	SW = 0;
	
	for(i=0;t[i]!='\0';i++){
		if (isdigit(t[i])==0){
			textcolor(1);
			 textbackground(15);
			 
			gotoxy(20,18);cprintf("<<ERROR NO DIGITE CARACTER >>");
			ALARMA();
			gotoxy(20,18);cprintf("                                         ");
			SW = 1;
			break;
		}
	}
	if (t[0] == '\0')
		SW = 1;
	}
//****************************************************************
//**********************ALARMA**********************************************
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
//***********************************************************
//**************************RUTA MINIMA*********************
void RUTA_MIN()
{
char op,inic[4],fin[4];
int pdd, precede[30],SW2,xinic,xfin,fil,col;
  
	clrscr();
 textcolor(4);
 textbackground(15);
 clrscr();
 textcolor(0);
 textbackground(15);
 CUADROS(2,79,2,23);
 CUADROS(5,76,4,21);
 CUADROS(8,73,6,19);
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);

 textcolor(14);
 textbackground(5);
gotoxy(30,5); cprintf("<< RUTA MINIMA >>");
if(ST==1){
do {
 
 do {	
	SW2 = 0;
	
	textcolor(4);
 textbackground(15);
	gotoxy(20,8);printf("                              ");
	textcolor(4);
 textbackground(15);
	gotoxy(20,8);printf("DIGITE EL NODO INICIAL: ");
	gets(inic);
	ACCESO(inic);
	gotoxy(20,8);printf("                              ");
	if (SW == 0){
		xinic = atoi(inic);
		if (xinic > NSTM || xinic < 1) {
			textcolor(1);
			textbackground(15);
			
			gotoxy(20,18);cprintf("                                 ");
			gotoxy(20,18);cprintf("<< ESTE NODO NO EXISTE >>");
			ALARMA();
			MENU();
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
	gotoxy(20,8);printf("                              ");
	gotoxy(20,8);printf("DIGITE EL NODO FINAL: ");
	gets(fin);
	ACCESO(fin);
	textcolor(4);
	textbackground(15);
	gotoxy(20,8);printf("                              ");
	if (SW == 0){
		xfin = atoi(fin);
		if (xfin > NSTM || xfin < 1) {
			gotoxy(20,18);printf("                                 ");
			textcolor(1);
			 textbackground(15);
			 
			gotoxy(20,18);printf("<< ESTE NODO NO EXISTE >>");
			ALARMA();
			textcolor(4);
			textbackground(15);
			gotoxy(20,19);printf("                                 ");
			SW2 = 1;
		}
	}
 }while(SW == 1 || SW2 == 1);
 gotoxy(15,12);printf("                                             ");
 gotoxy(15,12);textcolor(4);cprintf("LA RUTA MINIMA ENTRE EL NODO [%d] y [%d] ES : " ,xinic,xfin);
 NO_SE(xinic-1,xfin-1,&pdd,precede);
 if (pdd == 0){
	textcolor(4);
	textbackground(15);
	gotoxy(15,12);printf("                                         ");
	gotoxy(15,12);printf("NO HAY RUTA MINIMA DEL NODO [%d] AL [%d]",xinic,xfin);
 }
 else{  textcolor(4);
	textbackground(15);
	gotoxy(56,12);cprintf("    ");
	gotoxy(56,12);textcolor(4);cprintf("%d",pdd); 
 
 }
 textcolor(1);
 textbackground(15);
 gotoxy(18,20);printf("                                                ");
 gotoxy(18,20);cprintf("CONTINUAR : [S] o <ENTER> PARA SALIR");
 op = getche();
 gotoxy(18,20);printf("                                                ");
 gotoxy(15,12);printf("                                               ");
 gotoxy(56,12);cprintf("    ");
}while (op == 's' || op == 'S');
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
//*******************************************************
//***********************NOSE******************************
void NO_SE(int s,int t,int *pd,int precede[30])
{  
	int distancia[30],perm[30];
	int actual,i,k,dc;
	int smalldist,newdist;
 
	for(i=0;i<NSTM;++i){
		perm[i] = 0;
		distancia[i] = 1000;
	}
	perm[s] = 1; 
	distancia[s] = 0;
	actual = s;
	while(actual != t){
		smalldist = 1000;  
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
		perm[actual] = 1; 
	}
  *pd = distancia[t];
  
} 
//*************************************************
//*****************************CUADROS************
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
//****************************CUADRO2*****************

 void CUADRO2(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(5);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("");
       gotoxy(j,y2);cprintf("");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("ÛÛ");
       gotoxy(x2,i);cprintf("ÛÛ");
       }
     gotoxy(x1,y1);cprintf("ÛÛ");
     gotoxy(x2,y1);cprintf("ÛÛ");
     gotoxy(x1,y2);cprintf("ÛÛ");
     gotoxy(x2,y2);cprintf("ÛÛ");
  //return(0);
}

/*****************************************************/

//****************************** MENU******************
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
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
 //*******************************
 CUADRO2(26,51,9,16);  
CUADRO3(26,51,9,16);
    
    textbackground(0);
    textcolor(14);
    textcolor(14+128);
    gotoxy (29,8); cprintf("<< MENU PRINCIPAL >>");
    textcolor(4);
  gotoxy(22,3);printf("CORPORACION UNIVERSITARIA DEL SANTANDER");  
  gotoxy(29,5);printf("DARWIN HELMUTHS LEON PEREZ");
  gotoxy(29,22);printf("CODIGO: 96132068");
  gotoxy(28,10);printf("[1]. INICIO DE RUTAS");
  gotoxy(28,11);printf("[2]. ELIMINAR RUTAS");
  gotoxy(28,12);printf("[3]. ADICIONAR");
  gotoxy(28,13);printf("[4]. RUTA MINIMA");
  gotoxy(28,14);printf("[5]. MATRIZ DE ADY");
  gotoxy(28,15);printf("[6]. SALIR DEL PROGRAMA");
  //*****************************************
  textcolor(0);
  textbackground(15);
  gotoxy(28,10);cprintf("[1].");
  textcolor(1);
  gotoxy(28,11);cprintf("[2].");
  textcolor(4);
  gotoxy(28,12);cprintf("[3].");
  textcolor(14);
  gotoxy(28,13);cprintf("[4].");
  textcolor(8);
  gotoxy(28,14);cprintf("[5].");
  textcolor(9);
  gotoxy(28,15);cprintf("[6].");
//*****************************************  
    
    gotoxy (28,18);printf("DIGITE OPCION [ ]");gotoxy(43,18);
    op=toupper(getche());
    switch(op)                              
	  {
    case '1':CREACION();break;
    case '2':ELIMINAR();break;
    case '3':AGREGAR();break;
    case '4':RUTA_MIN();break;
    case '5':OPERATION();getche();break; 
    case '6':exit(0);break;
    getche();  
     }
     }while(op!='6');
     }


/*****************************************************/
//*******************AGREGAR**************************
void AGREGAR()
{
	char grande[4];
	char longitud[4];
	char elementos[4];
	char pesos[4],op;
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
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
 textbackground(5);
 textcolor(14);
 gotoxy(30,5); cprintf("<< AGREGAR OTRA RUTA >>");
  if (ST == 1) {
	for (i=NSTM;i<NSTM+1;i++){
		for (j=0;j<NSTM+1;j++){
			do{
				textcolor(1); 
				textbackground(15);
				gotoxy(15,20);printf("                                              ");
				gotoxy(15,20);cprintf("ESCRIBA [1] PARA CONTESTAR SI 0 [0] PARA DECIR NO");

				gotoxy(15,11);printf("                                          ");
				gotoxy(15,11);printf("DEL NODO [%d] AL NODO [%d] HAY RUTA ?: ",i+1,j+1);
				gets(elementos);
				ACCESO(elementos);
				if (SW == 0){
					NAUX = atoi(elementos);
					if (NAUX < 0 || NAUX > 1){
						textcolor(1);
						     textbackground(15);
						     textcolor(4+128);
						textcolor(1); 
						textbackground(15);
						gotoxy(25,18);cprintf("<< DIGITE [0] ข [1] >>");
						ALARMA();
						textcolor(4);
						gotoxy(25,18);cprintf("                                 ");
					}
				}
			}while(SW == 1 || NAUX > 1 || NAUX < 0);
			b[i][j] = a[i][j] = NAUX;
			if (NAUX == 1 && i != j){
			  do{	
				gotoxy(15,12);printf("                                                   ");
				gotoxy(15,12);printf("DIGITE EL VALOR DEL NODO [%d] AL NODO [%d] ",i+1,j+1);
				gets(pesos);
				ACCESO(pesos);
				gotoxy(15,12);printf("                                                   ");
				if (SW == 0){
					xVALOR = atoi(pesos);
					if (xVALOR < 0 || xVALOR > 99){
						textcolor(1);
						textbackground(15);
						
						gotoxy(20,18);cprintf("                                        ");
						gotoxy(20,18);cprintf("<< EL VALOR DEBE SER DE [0] A [99] >>");
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
	OPERATION();
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
//********************************************************************
//*******************ELIMINAR*****************************************
void ELIMINAR()
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
 CUADRO2(3,77,3,22);  
 CUADRO2(6,74,5,20);
 textbackground(5);
 textcolor(14);
 gotoxy(30,5); cprintf("<< ELIMINAR RUTAS >>");
	if (ST == 1) {
	do{      textcolor(4);
		 textbackground(15);
		 gotoxy(15,8);printf("                             ");	
		 gotoxy(15,8);printf("DIGITE NODO A ELIMINAR: ");	
		 gets(elim);
		 ACCESO(elim);
		 if (SW == 0){
			 xelim = atoi(elim);
			 if (xelim < 0 || xelim > NSTM){
				 textcolor(1);
				 textbackground(15);
				 
				 gotoxy(25,18);cprintf("El NODO DEBE SER [ %d ]",NSTM);
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
//**********************PANTALLA******************************************
//************************************************************************
void GRAFOS()
{

CUADRO2(8,73,3,22);  
CUADRO3(8,73,2,23);

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
textcolor(1);
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
//*************************************************************************

//****************************

 void CUADRO3(int x1,int x2,int y1,int y2)
{
     int j,i,k;
     textcolor(5);textbackground(0);
     for(j=x1;j<=x2;j++)
       { 
       gotoxy(j,y1);cprintf("ÛÛ");
       gotoxy(j,y2);cprintf("ÛÛ");
       }
     for(i=y1;i<=y2-1;i++)
       { 
       gotoxy(x1,i);cprintf("");
       gotoxy(x2,i);cprintf("");
       }
     gotoxy(x1,y1);cprintf("");
     gotoxy(x2,y1);cprintf("");
     gotoxy(x1,y2);cprintf("");
     gotoxy(x2,y2);cprintf("");
  //return(0);
}

/*****************************************************/
