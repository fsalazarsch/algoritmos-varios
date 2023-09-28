#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>


int h,w,modulos[5][5],memaux[2][2],taux[30],tpag[30],memreal[10],virtual[30],tiempo[30];
int swtabla=0,swmemaux=0,swmemreal=0,swcontrol=0,nummod;
char cad[100];

#define enter 13
#define esc 27
#define f1 59



/* La funcion principal hace el llamado a las rutinas que inician el
modo grafico y ejecutan la presentacion y el tutor*/

main()
{
clrscr();
inicio_grafico();
inicio();
simmemdos();
return 0;
}

/*Esta rutina inicializa el modo grafico, detectando una targeta vga y
configurando la pantalla a una resolucion de 640x480 (VGAHI) */

int inicio_grafico(void)
{
int gdriver=VGA, gmode=VGAHI, error=0;
struct viewporttype vp;

initgraph(&gdriver,&gmode,"");
error=graphresult();

if(error != grOk){
	    printf("ERROR...... EN LA INICIALIZACION GRAFICA");
	    getch();
	    exit(1);
	    }
else{
    getviewsettings(&vp);
    h=vp.bottom;
    w=vp.right;
	}
return 0;
}  

inicio()
{
register i;
int c,t,p;

for(i=0;i<2500;++i){
		    c=random(h);
		    t=random(w);
                    p=random(MAXCOLORS);
		    setcolor(p);
		    line(w/2,h/2,t,c);
		    sound(random(1000));
		    if(kbhit()){
				getch();
				break;
				 }
			    }
nosound();
settextstyle(1,0,4);
setcolor(15);
outtextxy(40,67,"SIMULACION ASIGNACION DE MEMORIA");
settextstyle(1,0,3);
outtextxy(w/2-190,h/4+30,"PRESENTADO A: ");
outtextxy(w/2-45,h/4+50,"Ing. ROBERTO ORTIZ");
outtextxy(170,(h+10)/2,"ALEXANDER MORALES COD. 492916");
outtextxy(170,(h+50)/2,"LEONARDO PARRA    COD. 493064");
outtextxy(170,(h+90)/2,"CARMENZA FUENTES  COD. 492676");

settextstyle(0,0,2);
setcolor(7);
outtextxy(100,h-59,"UNIVERSIDAD ANTONIO NARI¥O");
settextstyle(0,0,1);
outtextxy(170,h-20,"pulse <ENTER> para continuar .....");
getch();

return 0;
}


/* Esta rutina ejerce el control del programa, dependiendo de la tecla
pulsada y hace el correspondiente llamado a la subrutina escogida.*/


simmemdos()
{
int sw=0;
char c;

dib_mem();
inicio_sim();

while(!(sw))
    {
	if(kbhit()){
		 c=getch();
		  if(!c) c=getch();
		  switch(c){
			case enter :if(swcontrol){
					admor_mem();
					redibuja();
					sleep(2);
					visu_tab();
					}
					else admor_mem();
					break;
			case esc : sw=1;break;
			case f1 :
				if(swcontrol){
					admor_mem();
					redibuja();
					swcontrol=0;
					}
				else{
					admor_mem();
					redibuja();
					sleep(3);
					visu_tab();
					swcontrol=1;
					}
				break;
			       }
			}
	}
closegraph();
return 0;
}

/* Esta rutina escoge aleatoriamente si asigna o desasigna procesos a memoria */

admor_mem()
{
int temp;

if(!swtabla) subeproceso();
else{
	temp=random(5);
	if(temp==0){
		     if(swtabla<30) subeproceso();
		     else bajaproceso();
		}
	if(temp==1){
		if(!swmemreal) subeproceso();
		else bajaproceso();
		}
	if(temp==2){
		if(swmemreal<10) auxtoreal();
		else bajaproceso();
		}
	if(temp==3){
		if(swmemreal<10) tablatoreal();
		else bajaproceso();
		}
	if(temp==4){
		if(swmemaux<3) pasaaux();
		else bajaproceso();
		}
}

tomatiempo();
return 0;
}

/* Esta rutina descarga de memoria real un proceso */

bajaproceso()
{
int i,j,k,l,m,n,vble;

if(!swmemreal){
	subeproceso();
	 return 0;
	 }

swmemreal--;

do{
	vble=random(10);
	}while(!memreal[vble]);

for(i=0;i<30;i++){
		if(taux[i]==memreal[vble]) j=i;
		}

for(k=0;k<5;k++)
for(l=0;l<5;l++)
{
		if(modulos[k][l]==memreal[vble]){
			m=k;
			n=l;
			}
		}
i=taux[j];
tpag[j]=0;
taux[j]=0;
virtual[j]=0;
memreal[vble]=0;
tiempo[j]=0;

setfillstyle(1,5);
bar(201,56+j*13,229,67+j*13);
bar(281,56+j*13,379,67+j*13);
bar(431,56+j*13,459,67+j*13);

sprintf(cad,"%c",'0');
outtextxy(209,59+j*13,cad);

setfillstyle(1,9);
bar(541,101+vble*30,599,129+vble*30);
outtextxy(440,60+j*13,"*");

setfillstyle(1,2);
bar(29+m*20,301+n*20,47+m*20,319+n*20);
sprintf(cad,"%d",modulos[m][n]);
outtextxy(30+m*20,309+n*20,cad);


setfillstyle(1,3);
bar(2,h-22,w-5,h-2);
sprintf(cad," --> Sale el proceso : %d de la Memoria Real",i);
outtextxy(20,h-17,cad);

return 0;
}

/* Esta rutina subre procesos de la tabla auxiliar a la memoria real */

tablatoreal()
{
int vble,temp;

if(!swtabla) return 0;

do{
do{
	temp=random(30);
	}while(!taux[temp]);
}while(virtual[temp]!=1);

swmemreal++;
swtabla--;
virtual[temp]=3;


do{
	vble=random(10);
	}while(memreal[vble]);

memreal[vble]=taux[temp];
tpag[temp]=1;

setfillstyle(1,4);
bar(201,56+temp*13,229,67+temp*13);
bar(281,56+temp*13,379,67+temp*13);
bar(431,56+temp*13,459,67+temp*13);
bar(541,101+vble*30,599,129+vble*30);

sprintf(cad,"%d",memreal[vble]);

outtextxy(209,59+temp*13,cad);
outtextxy(565,110+vble*30,cad);
outtextxy(313,60+temp*13,"REAL");

setfillstyle(1,5);
bar(431,56+temp*13,459,67+temp*13);

setfillstyle(1,3);
bar(2,h-22,w-5,h-2);
sprintf(cad," --> Entra el proceso : %d de la Tabla Auxiliar a la memoria real",memreal[vble]);
outtextxy(20,h-17,cad);

return 0;
}

/* Esta rutina carga procesos desde la memoria auxiliar a la memoria real */

auxtoreal()
{
int i,k,l,vble,temp;

if(swmemreal>9 || !swmemaux) return 0;

do{
	k=random(2);
	l=random(2);
	}while(!memaux[k][l]);

do{
	    vble=random(10);
	    }while(memreal[vble]);

for(i=0;i<30;i++){
	if(memaux[k][l]==taux[i]){
		 virtual[i]=3;
		 temp=i;
		 }
	}


swmemaux--;
swmemreal++;

tpag[temp]=2;
memreal[vble]=memaux[k][l];
memaux[k][l]=0;


setfillstyle(1,1);
bar(51+k*20,91+l*20,69+k*20,109+l*20);

setfillstyle(1,0);
bar(201,56+temp*13,229,67+temp*13);
bar(281,56+temp*13,379,67+temp*13);
bar(431,56+temp*13,459,67+temp*13);
bar(541,101+vble*30,599,129+vble*30);

sprintf(cad,"%d",memreal[vble]);

outtextxy(209,59+temp*13,cad);
outtextxy(565,110+vble*30,cad);
outtextxy(313,60+temp*13,"REAL");

setfillstyle(1,3);
bar(2,h-22,w-5,h-2);
sprintf(cad," --> Entra el proceso : %d de la Memoria Auxiliar a la memoria real",memreal[vble]);
outtextxy(20,h-17,cad);

return 0;
}

/* Esta rutina carga un proceso en memoria virtual y modifica la tabla auxiliar
y de paginaci¢n */

subeproceso()
{
int k,l,vble,temp,m,n;

if(swtabla>29 && swtabla>=nummod) return 0;
	  do{
	  do{
		k=random(5);
		l=random(5);
		}while(modulos[k][l]<1);

	  do{
		  vble=random(30);
	  }while(taux[vble]!=0 && virtual[vble]>0);
	  temp=0;
	  for(m=0;m<30;m++){
		if(taux[m]==modulos[k][l]) temp++;
			}
	  for(m=0;m<2;m++)
		for(n=0;n<2;n++)
			if(memaux[m][n]==modulos[k][l]) temp++;
	   }while(temp);

	  taux[vble]=modulos[k][l];

	  virtual[vble]=1;

	  setfillstyle(1,1);
	  bar(29+k*20,301+l*20,47+k*20,318+l*20);
	  bar(201,55+vble*13,229,67+vble*13);
	  bar(281,56+vble*13,379,67+vble*13);

	  sprintf(cad,"%d",modulos[k][l]);
	  outtextxy(30+k*20,308+l*20,cad);

	  sprintf(cad,"%d",taux[vble]);
	  outtextxy(210,58+vble*13,cad);

	  outtextxy(300,59+vble*13,"PROGRAMA");

	  bar(431,56+vble*13,459,67+vble*13);

swtabla++;
tiempo[vble]=1;

setfillstyle(1,3);
bar(2,h-22,w-5,h-2);
sprintf(cad," --> Entra el proceso : %d a la Tabla Auxiliar y de P ginas",taux[vble]);
outtextxy(20,h-17,cad);

return 0;
}

/* Esta rutina pasa un proceso de la memoria virtual a la memoria auxiliar */

pasaaux()
{
int k,l,valor;

if(!swtabla) return 0;

do{
	k=random(2);
	l=random(2);
	}while(memaux[k][l]);

do{
do{
	valor=random(30);
	}while(!taux[valor]);
}while(virtual[valor]!=1);

memaux[k][l]=taux[valor];
swmemaux++;
swtabla--;

virtual[valor]=2;

setfillstyle(1,10);
bar(201,56+valor*13,229,67+valor*13);
bar(281,56+valor*13,379,67+valor*13);
bar(51+k*20,91+l*20,69+k*20,109+l*20);

setfillstyle(1,5);
bar(431,56+valor*13,459,67+valor*13);

sprintf(cad,"%d",taux[valor]);

outtextxy(54+k*20,96+l*20,cad);
outtextxy(209,59+valor*13,cad);
outtextxy(315,60+valor*13,"AUX");
outtextxy(440,60+valor*13,"*");

setfillstyle(1,3);
bar(2,h-22,w-5,h-2);
sprintf(cad," --> Entra el proceso : %d de la Tabla Auxiliar a la Memoria Auxiliar",taux[valor]);
outtextxy(20,h-17,cad);

return 0;
}

/* Esta rutina inicializa los arreglos */


inicio_sim()
{
int jt,k,l;

settextstyle(0,0,1);
randomize();
do{
	nummod=random(25);
	}while(nummod<10);

for(k=0;k<5;k++)
	for(l=0;l<5;l++)
		modulos[k][l]=0;

for(k=0;k<2;k++)
	for(l=0;l<2;l++)
		memaux[k][l]=0;


for(jt=1;jt<=nummod;jt++){
	do{
		k=random(5);
		l=random(5);
		}while(modulos[k][l]!=0);

	modulos[k][l]=jt;
	sprintf(cad,"%d",modulos[k][l]);
	outtextxy(30+k*20,307+l*20,cad);
	}

for(jt=0;jt<30;jt++){
	 virtual[jt]=0;
	 taux[jt]=0;
	 tiempo[jt]=0;
	 }

return 0;
}

/* Esta rutina visualiza las pantallas de la simulaci¢n */

dib_mem()
{
register i;

setlinestyle(0,0,2);
setcolor(15);
setfillstyle(1,0);
bar(0,0,w,h);
rectangle(0,0,w,h);

setfillstyle(1,2);
bar(0,0,w,40);
rectangle(0,0,w,40);
settextstyle(1,0,2);
setcolor(14);
outtextxy(130,10,"SIMULACION ASIGNACION DE MEMORIA");


setfillstyle(1,3);
bar(0,h-24,w,h);
setcolor(15);
rectangle(0,h-24,w,h);


setfillstyle(1,1);
bar3d(50,90,90,130,10,1);
setcolor(11);
rectangle(50,90,90,130);
rectangle(50,90,70,110);
rectangle(70,110,90,130);

setfillstyle(1,2);
bar3d(28,300,128,400,10,1);
setcolor(11);
rectangle(28,300,128,400);
for(i=28;i<130;i+=20) line(i,300,i,400);
for(i=300;i<410;i+=20) line(28,i,128,i);

setfillstyle(1,5);
bar3d(200,55,230,445,10,1);
bar3d(280,55,380,445,10,1);
bar3d(430,55,460,445,10,1);

setcolor(14);
rectangle(200,55,230,445);
rectangle(280,55,380,445);
rectangle(430,55,460,445);

for(i=68;i<450;i+=13){
	line(200,i,230,i);
	line(280,i,380,i);
	line(430,i,460,i);
	}

setfillstyle(1,9);
bar3d(540,100,600,400,10,1);

setcolor(14);
rectangle(540,100,600,400);
for(i=130;i<410;i+=30) line(540,i,600,i);

setcolor(15);
settextstyle(0,1,1);
outtextxy(190,200,"Tabla Auxiliar");
outtextxy(270,190,"Memoria Virtual");
outtextxy(420,190,"Tabla de P ginas");
settextstyle(0,0,1);
outtextxy(20,150,"Mem. Auxiliar");
outtextxy(25,415,"M¢d. Cargables");
outtextxy(533,420,"Mem. Real");

for(i=0;i<30;i++){
	 outtextxy(440,60+i*13,"*");
	 sprintf(cad,"%c",'0');
	 outtextxy(209,60+i*13,cad);
	 }


return 0;
}

/* esta rutina despliega las tablas de informaci¢n de los procesos y la memoria */

visu_tab()
{
int i,j,k=0;

setfillstyle(1,5);
bar(0,0,w,h);
setcolor(14);
rectangle(0,0,w,h);
setcolor(1);

outtextxy(10,20,"Tabla Aux.");
outtextxy(113,20,"Tabla P g.");
outtextxy(210,20,"T. del proc");
outtextxy(330,20,"Mem. Virtual (Kb)");
outtextxy(500,20,"Mem. Real (Kb)");
setcolor(15);

for(i=0;i<5;i++)
	for(j=0;j<5;j++){
		if(modulos[i][j]>0){
			sprintf(cad,"%d",modulos[i][j]);
			outtextxy(30,40+k,cad);
			k+=12;
			}
		  }
		  k=0;
for(i=0;i<30;i++){
		sprintf(cad,"%d",taux[i]);
		outtextxy(150,40+k,cad);

		if(taux[i]>0)
			sprintf(cad,"%d",256*i);
		outtextxy(370,40+k,cad);

		sprintf(cad,"%d",tiempo[i]);
		outtextxy(250,40+k,cad);

		k+=12;
		}
		k=0;
for(i=0;i<10;i++){
		if(memreal[i]>0)
			sprintf(cad,"%d",256*i);
		else sprintf(cad,"%d",memreal[i]);
		outtextxy(550,40+k,cad);
		k+=12;
		}

return 0;
}

/* Esta rutina calcula el tiempo que un proceso lleva en memoria */

tomatiempo()
{
int i;

for(i=0;i<30;i++){
	if(tiempo[i]>0) tiempo[i]++;
	}

return 0;
}

redibuja()
{
int i,j,k,l,m;

dib_mem();

for(i=0;i<5;i++)
	for(j=0;j<5;j++){
		if(modulos[i][j]>0){
			sprintf(cad,"%d",modulos[i][j]);
			outtextxy(30+i*20,307+j*20,cad);
				}
			}

for(i=0;i<30;i++){
	if(taux[i]!=0){
		switch(virtual[i]){
			case 1:
				for(k=0;k<5;k++)
					for(l=0;l<5;l++){
						if(modulos[k][l]==taux[i]){
							j=k;
							m=l;
								}
							}
				setfillstyle(1,1);
				bar(29+j*20,301+m*20,47+j*20,318+m*20);
				bar(201,55+i*13,229,67+i*13);
				bar(281,56+i*13,379,67+i*13);
				sprintf(cad,"%d",modulos[j][m]);
				outtextxy(30+j*20,308+m*20,cad);
				sprintf(cad,"%d",taux[i]);
				outtextxy(210,58+i*13,cad);
				outtextxy(300,59+i*13,"PROGRAMA");
				bar(431,56+i*13,459,67+i*13);
				break;
			case 2:
				for(k=0;k<2;k++)
					for(l=0;l<2;l++){
						if(memaux[k][l]==taux[i]){
							j=k;
							m=l;
							     }
							}
				setfillstyle(1,10);
				bar(201,56+i*13,229,67+i*13);
				bar(281,56+i*13,379,67+i*13);
				bar(51+j*20,91+m*20,69+j*20,109+m*20);

				setfillstyle(1,5);
				bar(431,56+i*13,459,67+i*13);
				sprintf(cad,"%d",taux[i]);
				outtextxy(54+j*20,96+m*20,cad);
				outtextxy(209,59+i*13,cad);
				outtextxy(315,60+i*13,"AUX");
				outtextxy(440,60+i*13,"*");
				break;

			case 3:
				switch(tpag[i]){
					case(1):
						for(k=0;k<10;k++)
							if(taux[i]==memreal[k]) m=k;

						setfillstyle(1,4);
						bar(201,56+i*13,229,67+i*13);
						bar(281,56+i*13,379,67+i*13);
						bar(431,56+i*13,459,67+i*13);
						bar(541,101+m*30,599,129+m*30);
						sprintf(cad,"%d",memreal[m]);

						outtextxy(209,59+i*13,cad);
						outtextxy(565,110+m*30,cad);
						outtextxy(313,60+i*13,"REAL");
						setfillstyle(1,5);
						bar(431,56+i*13,459,67+i*13);
						break;
					case(2):
						for(l=0;l<2;l++){
						if(memaux[k][l]==taux[i]){
							j=k;
							m=l;
							     }
							}

						for(k=0;k<10;k++)
							if(taux[i]==memreal[k]) l=k;

						setfillstyle(1,1);
						bar(51+j*20,91+m*20,69+j*20,109+m*20);
						setfillstyle(1,0);
						bar(201,56+i*13,229,67+i*13);
						bar(281,56+i*13,379,67+i*13);
						bar(431,56+i*13,459,67+i*13);
						bar(541,101+l*30,599,129+l*30);
						sprintf(cad,"%d",memreal[l]);
						outtextxy(209,59+i*13,cad);
						outtextxy(565,110+l*30,cad);
						outtextxy(313,60+i*13,"REAL");
						break;
					}
				    break;


				}
			}
		}

return 0;
}