 do

  { 
    gotoxy(i+1,1);
    clreol();
    t[i]=getche();
    if(t[i]=='\b'&&i>0) i-=2;
    else
     {
     if(t[i]=='\r'&&i>0) break;
     if(!isdigit(validacion[i])) i--;
     }
    i++;
  }while(i<2);
