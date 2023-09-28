# include <iostream.h>
# include <stdio.h>
# include <conio.h>
  class cola{
   int val1,val2;
   public:
   cola(void);
   ~cola(void);
   int sobrecar(int i);
   double sobrecar(double i);
   long sobrecar(long i);
  };
  class cola2{
   int val12,val22;
   public:
   cola2(int i);
   ~cola2(void);
   long sobrecar(long i);
  };
  cola2 :: cola2(int i){
     val12=val22=i;
     cout<<"inicializa con valor"<<val12;
  }
  cola2 :: ~cola2(void){
     cout<<"es destructor nuevo";
  }
  int cola :: sobrecar(int i){
    return i*i;
  }
  double cola :: sobrecar(double i){
    return i*i;
  }
  long cola :: sobrecar(long i){
    return i*i;
  }
  cola :: cola(void){
    clrscr();
    cout<<"este es el tema muestra constructor\n";
  }
  cola :: ~cola(void){

    cout<<"este es el tema muestra destructor";
    getch();
  }
  main(){
    cola a;
    cola2 b(12);
    cout<<"informacion despues del constructor\n";
    cout<<a.sobrecar(5)<<"\n";
    cout<<a.sobrecar(4.5)<<"\n";
    cout<<a.sobrecar(2L)<<"\n";
  }
