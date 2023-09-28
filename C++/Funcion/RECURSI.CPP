# include <alvaro.h>
double fact(int n);
double r=1,r1=1;
main()
{
 clrscr();
 int X;
 cout<<"digite el numero";cin>>X;
 r1=fact(X);
 cout<<"el resultado es :"<<r1;getch();
}

double fact(int n)
{
 if ((n==1)) //|| (n==0))
  return(r);
 else
 return(n*fact(n-1));
}