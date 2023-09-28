#include <iostream.h>
#include<conio.h>

class LLENAR{
private:
char nom[20];
float nota;
char cod[20];
public:
friend  void definitiva(LLENAR& p,float not1,float not2,float not3,float not4);
};
void definitiva(LLENAR&p,float not1,float not2,float not3,float not4)
{
cout<<"DE NOTA 1";cin>>not1;
cout<<"DE NOTA 2";cin>>not2;
cout<<"DE NOTA 3";cin>>not3;
cout<<"DE NOTA 4";cin>>not4;
p.nota=(not1*0.25)+(not2*0.25)+(not3*020)+(not4*0.30);
cout<<"DEFINITA = "<<p.nota;
}
void main()
{
LLENAR obj;
obj.definitiva();
getch();
}