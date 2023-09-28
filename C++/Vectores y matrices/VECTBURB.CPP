#include<iostream.h>
#include<conio.h>
void CUADRO(int ci, int cf, int fi, int ff);
void main(void)
  {
  int I,J,VECTOR[15],F,AUX,N;
  clrscr();
  CUADRO(1,80,1,24);
  gotoxy(20,3);cout<<"METODO DE ORDENAMIENTO POR BURBUJA"; gotoxy(14,5);cout<<"CAPTURA Y ORDENAMIENTO DE LOS ELEMENTOS DE UN VECTOR";
  gotoxy(15,8);cout<<"DIGITE EL NUMERO DE ELEMENTOS DE UN VECTOR:  ";cin>>N;
  gotoxy(15,11);cout<<"VECTOR INICIAL=  ";
  F=33;
  for(I=0;I<N;I++)
    {
    gotoxy(F,11);cin>>VECTOR[I];
    F+=6;
    }
    for(I=1; I<N; I++)
      for(J=N-1; J>=I; J--)
       {
	 if(VECTOR[J-I]>VECTOR[J])
	  {
	AUX=VECTOR[J-I];
	VECTOR[J-I]=VECTOR[J];
	VECTOR[J]=AUX;
	  }
	}
	gotoxy(15,13);cout<<"VECTOR ORDENADO=  ";
	for(I=0; I<N; I++)
	cout<< VECTOR[I] <<"     ";
	gotoxy(26,20);cout<<"PRESIONE CUALQUIER TECLA PARA SALIR ";
	getch();
	}
void CUADRO(int ci, int cf, int fi, int ff)
{
int o;
for(o=ci; o<=cf; o++)
{
gotoxy(o,fi); cout<<"Í";
gotoxy(o,ff); cout<<"Í";
}
for(o=fi; o<=ff; o++)
{
gotoxy(ci,o); cout<<"º";
gotoxy(cf,o); cout<<"º";
}
gotoxy(ci,fi); cout<<"É";
gotoxy(cf,fi); cout<<"»";
gotoxy(ci,ff); cout<<"È";
gotoxy(cf,ff); cout<<"¼";

}
