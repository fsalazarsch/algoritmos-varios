# include<alvaro.h>
void BORRAR(int ci,int cf,int fi,int ff);
main()
 {
 alv BI;
 textbackground(7);BORRAR(1,80,1,24);
 window(1,1,80,25);
 BI.BOTON(0,50,60,22,22,1,2,7,"Aceptar"); 
//coli,colf,fili,fifi,fondo,cara,fondo de atras, nombre

}
//**********************************************

void BORRAR(int ci,int cf,int fi,int ff)
{
 int i,j;
 for(j=fi;j<=ff;j++)
  for(i=ci;i<=cf;i++)
  cout<<" ";
}
