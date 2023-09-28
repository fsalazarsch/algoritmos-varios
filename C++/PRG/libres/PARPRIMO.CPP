   n=i;con=0;
   while(n!=0)
    {
     if (i%n==0)
     con=con+1;
     n--;
    }
    if((con==2)||(con==1))
      printf("%d Es primo :\n:",i);
     else
      printf("%d No primo :\n:",i);
   i--;
   delay(500);
  }
