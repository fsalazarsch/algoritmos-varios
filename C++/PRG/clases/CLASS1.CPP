#include <iostream.h>
#include <conio.h>
class rectangulo{
	    int largo;
	    int ancho;
	    public:
	    rectangulo(void);  //constructor
	    void cambiar(int lar, int anc);
	    int area(void)
		    {
		      return(largo*ancho);}
		      ~rectangulo(void); //destruvtor
	       };
	       rectangulo::rectangulo(void)  //implementa el constructor
	       {
	       largo=8;
	       ancho=8;
	       }
	       //cambia la caja atendiendo los dos parametros
   void rectangulo:: cambiar(int lar, int anc)
		  {
		   largo=lar;
		   ancho=anc;
		   }
  rectangulo::~rectangulo(void) //implementa el destructor
		  {
		  largo=0;
		  ancho=0;
		  }

		  main()
		      {
		       clrscr();
		       rectangulo mini,medio,grande;//def tres rect
		       mini.cambiar(5,7);
		       grande.cambiar(15,20);
		       cout<< "el are del peque¤o"<<mini.area()<<endl;
		       cout<< "el are del grande"<<grande.area()<<endl;
		       // el rect medio utliza los val def por el const
		       cout<< "el are del medio"<<medio.area()<<endl;
			getch();
		       }
