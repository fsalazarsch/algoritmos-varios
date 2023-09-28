#include <time.h>
#include <stdio.h>
#include <dos.h>

int main(void)
{  float x;
   clock_t start, end;
   start = clock();

   delay(2000);

   end = clock();
   x=(end - start) / CLK_TCK;
   printf("The time was: %f\n",x);

   return (x);
}

