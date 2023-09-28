#include<iostream.h>
#include<ctype.h>
#include<alloc.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
typedef struct BUFFER BUFFER;
	struct BUFFER{
	int inf;
	int sig;
      };
#define LON sizeof(BUFFER)
#define grabar(id,a) _write(id,(char *)&a,LON)
#define lea(id,a) _read(id,(char *)&a,LON)
#define ubicar(id,a)lseek(id,(long)a*,LON,SEEK_SET)
//*******inicializa archivo*******/

init_archivo()
 {
 int i,id;
      BUFFER a;
      id=creat(" lista",32);
      close(id);
      id=_open("lista",O_RDWR);
      a.info=0;
      for(i=0;i<MAXIMO;i++){
      a.sig=i+1;
      grabar(id,a);
      }
      a.sig=0;
      grabar(id,a);
      return(id);
     }
disp(int id BUFFER *r0);  //funcion dispo
    {
     int i;
     BUFFER r1;
     i=r0->sig;
     if(i==0)
     return(-1);
      else{
	    ubicar(id,i);
	    lea(id,r1);
	    r0->sig=r1.sig;
	    return(i);
	    }
       }

 //******** irserccion de codigos  ********/

insertar(int id, int n)
{
   int p,q,enc,prox;
   BUFFER pc,qc,r0,proxc;

   ubicar(id,0);
   lea(id,r0);
   p=r0.info;
   p=enc=0;
   while(p!=0 && !enc){
	ubicar(id,p);
	lea(id,pc);
	 if(n>pc.info){
	       q=p;
	       qc=pc;
	       p=pc.sig;
	       }
	     else
	     enc=1;
	   }
	   if(enc==1)
		if(pc.info==n)                 
		  printf(" ya existe el archivo ");
		  return(-1);
		  prox=disp(id,&r0); //llamamos funcion dispo y asignamos a prox
		  if(prox!=-1){
		       proxc.info=n;
		       proxc.sig=p;
		       ubicar(id,prox);
		       grabar(id,proxc);
		       if(q==0)
			 r0.inf=prox;
			 else{
			 qc=prox;
			 ubicar(id,q);
			 grabar(id,qc);
			}
		     }
		   printf(" lista llena .  se debe ampliar el archivo..\n");
		   getch();
		   exit(1);
		  }
		  ubicar(id,0);
		  grabar(id,r0);

	      }
main()
{
  int n,id;
  id=init_archivo();
  printf(" digite numeros \n");
  n=lea1();
  while(n!=9999){
     if(insertar(id,n)==-1)
	   printf(" codigo repedo \n");
	   else
	   printf(" codigo insertado....%n\n",n);
	 printf(" digite numero \n");
	 n=lea1();
       }
       escribir(id);
       close(id);
}

  
			 



