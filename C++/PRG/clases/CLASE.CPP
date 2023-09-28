#include "iostream.h"
#include "conio.h"
class uno {
  int i;
public:
 void f (int j) {  i=j;  }
 int h(){ return i*+3;}
};
class dos {
    uno a;
 public:
    void g(int k) {a.f(k);}
    int l () {return a.h() ;}
 };
 main(){
    int ty;
    dos b;
    clrscr();
    cout<<"digite un valor ";cin>>ty;
	b.g (ty);
    cout<< b.l()<<endl;
    getch();
}

