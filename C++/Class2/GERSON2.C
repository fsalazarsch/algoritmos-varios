# include<conio.h>
# include<stdio.h>
# include<ctype.h>
# include<string.h>
# include<io.h>
# include<dos.h>
# include<fcntl.h>
# include<time.h>
# include <stdlib.h>
/***********************************************************************/
int id,id1,id2;
struct  date t;
/***********************************************************************/
//Estructura de Estudiante
struct estudiante
{
char cod[12];
char ced[12];
char nom[30];
char fac[30];
char fec[10];
}reg1,aux3;
/***********************************************************************/
//Estructura De Materias
struct materias
{
char cod[6];
int sem;
char nom[30];
}reg2,aux;
/***********************************************************************/
//Estructura De Notas
struct notas
{
char codest[12];
char codmat[6];
float nota1;
float nota2;
float nota3;
}reg3,aux1;
/***********************************************************************/
void menu_Modificar();
void menu_mantenimiento();
void menu_consulta();
void menu_Eliminar();
void menu_Inicializar();
void Captura_Notas();
void Captura_Estudiante();
void Captura_Materia();
int Buscar_Estudiante(char codigo[]);
int Buscar_Materia(char codigo[]);
char *ValidarNumeros(int x,int y,int tipo);
void Crear_Archivo_Estudiante();
void Crear_Archivo_Materia();
void Crear_Archivo_Nota();
void Adicionar_Estudiante();
void Adicionar_Materia();
void Adicionar_Nota();
float ValidarNota();
void Eliminar_Nota();
void Eliminar_Materia();
void Eliminar_Estudiante();
void Modificar_Notas();
void Modificar_Estudiante();
void Modificar_Materia();
void Consultar_PorMateria();
void Consultar_PorEstudiante();
void Consultar_PorNota();
/***********************************************************************/
void Consultar_PorEstudiante(){
char Codigo[10],fecha[12];
int Sw=0;
       id =_open("A:\Estudiante.dat",O_RDWR);
       if(id==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("**** Consulta    Estudiantes  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Cedula Estudiante: ");
       gotoxy(5,7);
       cprintf("Nombre Estudiante: ");
       gotoxy(5,8);
       cprintf("Facultad Estudiante: ");
       gotoxy(1,9);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(52,10);
       cprintf("Fecha De Ingreso:");
       strcpy(Codigo,ValidarNumeros(23,4,1));
       if(Codigo[0]=='*')
	 break;
	 else{
	 lseek(id,0L,SEEK_SET);
	 Sw=0;
	 while(!eof(id)&&Sw==0){
	 if(_read(id,&reg1,sizeof(reg1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(id);
	 }
	 if(strcmp(Codigo,reg1.cod)==0){
	    Sw=1;
		      aux3=reg1;
		       gotoxy(23,7);
		       cprintf("%s",aux3.ced);
		      gotoxy(23,7);
		      cprintf("%s",reg1.nom);
		      gotoxy(28,8);
		       cprintf("%s",aux3.fac);
		      getdate(&t);
		      aux3.fec[0]='\0';
		      itoa(t.da_day,fecha,10);
		      strcat(aux3.fec,fecha);
		      strcat(aux3.fec,"/");
		      itoa(t.da_mon,fecha,10);
		      strcat(aux3.fec,fecha);
		      strcat(aux3.fec,"/");
		     itoa(t.da_year,fecha,10);
		      strcat(aux3.fec,fecha);
		      gotoxy(72,10);
		      reg1=aux3;
		      cprintf("%s",aux3.fec);
		      getch();
		      fecha[0]='\0';

	}
       }

     }
if(Sw==0){
   cprintf("Los Codigos A Modificar No Existen En El Archivo");
   getch();
   }

}
  close(id);
 }
void Consultar_PorMateria(){
char Codigo[10],fecha[12];
int Sw=0;
       id2 =_open("A:\Materia.dat",O_RDWR);
       if(id2==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("*****  Consultar   Materias  *****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo De La Materia: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Nombre De La Materia: ");
       gotoxy(5,7);
       cprintf("Semestre           : ");
       gotoxy(1,8);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(26,4,2));
       if(Codigo[0]=='*')
	 break;
	 else{
lseek(id2, 0L, SEEK_SET);
Sw=0;
while(!eof(id2)&&Sw==0){
    if(_read(id2,&reg2,sizeof(reg2))==-1){
	cprintf("Error Al Leer El Archivo.......");
	 getch();
	 close(id2);
      }else{
      if(strcmp(reg2.cod,Codigo)==0){
		      aux=reg2;
		      gotoxy(27,6);
		      cprintf("%s",aux.nom);
		      gotoxy(27,7);
		      cprintf("%s",aux.sem);
		      reg2=aux;
		      Sw=1;
		      }
		   }
      }
      }
   if(Sw==0){
   cprintf("Los Codigos A Consultar No Existen En El Archivo");
   getch();

   }
 }
 close(id2);
 }
void Consultar_PorNota(){
char CodMateria[20],CodEstudiante[20];
int Sw=0;
float promedio;
    id1=_open("A:\Nota.dat",O_RDWR);
	if(id1==-1){
	cprintf("Error Al Abrir El Archivo Nota");
	getch();
	close(id1);
	}
	else
	    {
	    while(1){
	    clrscr();
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("    **** Consultar  Notas ****    ");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,9);
       cprintf("Codigo Materia.......: ");
       gotoxy(5,10);
       cprintf("Nota 1...............:");
       gotoxy(5,11);
       cprintf("Nota 2...............:");
       gotoxy(5,12);
       cprintf("Nota 3...............:");
       gotoxy(5,13);
       cprintf("Promedio.............:");
       gotoxy(1,14);
       cprintf("--------------------------------------------------------------------------------");
	    strcpy(CodEstudiante,ValidarNumeros(32,4,1));
	    if(CodEstudiante[0]=='*')
	      break;
	      else
	      {
	    strcpy(CodMateria,ValidarNumeros(32,9,1));
		 lseek(id1,0L,SEEK_SET);
		 while(!eof(id1)){
		 if(_read(id1,&reg3,sizeof(reg3))==-1){
		 cprintf("Error Al Leer El Archivo Nota");
		 getch();
		 close(id1);
		 exit(0);
		 }
  if(strcmp(CodMateria,reg3.codmat)==0 &&strcmp(CodEstudiante,reg3.codest)==0 )
  {
	Sw=1;
		
		  gotoxy(28,10);
		  cprintf("%.2f",aux1.nota1);
		  gotoxy(28,11);
		  cprintf("%.2f",aux1.nota1);
		  gotoxy(28,12);
		  cprintf("%.2f",aux1.nota1);
		  gotoxy(28,13);
		  cprintf("%.2f",aux1.nota1);
		  gotoxy(28,14);
		  cprintf("%.2f",promedio);
		    reg3=aux1;

		 }
	    }


   }
   if(Sw==0){
   cprintf("Los Codigos A Modificar No Existen En El Archivo");
   getch();
   }
   }
   }
 close(id1);
   }
void Modificar_Materia(){
char Codigo[10],fecha[12];
int Sw=0;
       id2 =_open("A:\Materia.dat",O_RDWR);
       if(id2==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("*****  Modificar   Materias  *****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo De La Materia: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Nombre De La Materia: ");
       gotoxy(5,7);
       cprintf("Semestre           : ");
       gotoxy(1,8);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(26,4,2));
       if(Codigo[0]=='*')
	 break;
	 else{
lseek(id2, 0L, SEEK_SET);
Sw=0;
while(!eof(id2)&&Sw==0){
    if(_read(id2,&reg2,sizeof(reg2))==-1){
	cprintf("Error Al Leer El Archivo.......");
	 getch();
	 close(id2);
      }else{
      if(strcmp(reg2.cod,Codigo)==0){
		      aux=reg2;
		      gotoxy(27,6);
		      scanf("\n");
		      gets(aux.nom);
		      aux.sem=atoi(ValidarNumeros(27,7,3));
		      reg2=aux;
		      Sw=1;
		      }
		   }
      }
      }
   if(Sw==0){
   cprintf("Los Codigos A Modificar No Existen En El Archivo");
   getch();
   } else
   if(_write(id2,&reg2,sizeof(reg2))==-1)
   {
   cprintf("Error Al Escribir En El Archivo Materia    ");
   close(id);
   getch();
   return;
   }
   }
 close(id2);
 }
void Modificar_Notas(){
char CodMateria[20],CodEstudiante[20];
int Sw=0;
float promedio;
    id1=_open("A:\Nota.dat",O_RDWR);
	if(id1==-1){
	cprintf("Error Al Abrir El Archivo Nota");
	getch();
	close(id1);
	}
	else
	    {
	    while(1){
	    clrscr();
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("    **** Modificar  Notas ****    ");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,9);
       cprintf("Codigo Materia.......: ");
       gotoxy(5,10);
       cprintf("Nota 1...............:");
       gotoxy(5,11);
       cprintf("Nota 2...............:");
       gotoxy(5,12);
       cprintf("Nota 3...............:");
       gotoxy(5,13);
       cprintf("Promedio.............:");
       gotoxy(1,14);
       cprintf("--------------------------------------------------------------------------------");
	    strcpy(CodEstudiante,ValidarNumeros(32,4,1));
	    if(CodEstudiante[0]=='*')
	      break;
	      else
	      {
	    gotoxy(5,3);
	    cprintf("Codigo De Materia:");
	    strcpy(CodMateria,ValidarNumeros(32,9,1));
		 lseek(id1,0L,SEEK_SET);
		 while(!eof(id1)){
		 if(_read(id1,&reg3,sizeof(reg3))==-1){
		 cprintf("Error Al Leer El Archivo Nota");
		 getch();
		 close(id1);
		 exit(0);
		 }
  if(strcmp(CodMateria,reg3.codmat)==0 &&strcmp(CodEstudiante,reg3.codest)==0 )
  {
	Sw=1;
		    aux1=reg3;
		    do{
		    gotoxy(28,10);
		    
		    aux1.nota1=ValidarNota();
		    }while(aux1.nota1==-1);
		     do{
		    gotoxy(28,11);
		    
		    aux1.nota2=ValidarNota();
		    }while(aux1.nota2==-1);
		     do{
		    gotoxy(28,12);
		    
		    aux1.nota3=ValidarNota();
		    }while(aux1.nota2==-1);
		    promedio=(aux1.nota1+aux1.nota2+aux1.nota3)/3;
		    gotoxy(28,13);
		    cprintf("%.2f",promedio);
		    reg3=aux1;

		 }
	    }


   }
   if(Sw==0){
   cprintf("Los Codigos A Modificar No Existen En El Archivo");
   getch();
   } else
    if(_write(id1,&reg3,sizeof(reg3))==-1)
		   {
		   cprintf("Error Al Escribir En El Archivo Estudiantes");
		   close(id2);
		   getch();
		   return;
		}
   }
   }
 close(id1);
   }

/***********************************************************************/
void Modificar_Estudiante(){
char Codigo[10],fecha[12];
int Sw=0;
       id =_open("A:\Estudiante.dat",O_RDWR);
       if(id==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("**** Modificar   Estudiantes  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Cedula Estudiante: ");
       gotoxy(5,7);
       cprintf("Nombre Estudiante: ");
       gotoxy(5,8);
       cprintf("Facultad Estudiante: ");
       gotoxy(1,9);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(52,10);
       cprintf("Fecha De Ingreso:");
       strcpy(Codigo,ValidarNumeros(23,4,1));
       if(Codigo[0]=='*')
	 break;
	 else{
	 lseek(id,0L,SEEK_SET);
	 Sw=0;
	 while(!eof(id)&&Sw==0){
	 if(_read(id,&reg1,sizeof(reg1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(id);
	 }
	 if(strcmp(Codigo,reg1.cod)==0){
	    Sw=1;
		      aux3=reg1;
		       gotoxy(23,7);
		       cprintf("%s",aux3.ced);
		      gotoxy(23,7);
		      scanf("\n");
		      gets(reg1.nom);
		      gotoxy(28,8);
		      scanf("\n");
		      gets(aux3.fac);
		      getdate(&t);
		      aux3.fec[0]='\0';
		      itoa(t.da_day,fecha,10);
		      strcat(aux3.fec,fecha);
		      strcat(aux3.fec,"/");
		      itoa(t.da_mon,fecha,10);
		      strcat(aux3.fec,fecha);
		      strcat(aux3.fec,"/");
		     itoa(t.da_year,fecha,10);
		      strcat(aux3.fec,fecha);
		      gotoxy(72,10);
		      reg1=aux3;
		      cprintf("%s",fecha);
		      getch();
		      fecha[0]='\0';

	}
       }

     }
if(Sw==0){
   cprintf("Los Codigos A Modificar No Existen En El Archivo");
   getch();
   }
   else
	if(_write(id,&reg1,sizeof(reg1))==-1)
		   {
	   cprintf("Error Al Escribir En El Archivo Estudiantes");
	   close(id);
	   getch();
	   return;
		  }
}
  close(id);
 }
void Eliminar_Nota(){
char Codigo[50];
int Sw=0;
int idaux;

       while(1){
	id2 =_open("A:\Nota.dat",O_RDWR);
       clrscr();
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("****  Eliminacion De Notas  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(25,4,1));
       if(Codigo[0]=='*')
	   break;
	else{
	if(id2==-1){
	cprintf("Error Al Leer El Archivo");
	getch();
	close(id2);
	exit(0);
	}
	else
	{
	Sw=0;
	while(!eof(id2)&&Sw==0){
	if(_read(id2,&reg3,sizeof(reg3))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id2);
	exit(0);
	}
       if(strcmp(reg3.codest,Codigo)==0)
	  Sw=1;
       }
       if(Sw==0){
       cprintf("Este  Codigo No Se Encuentran En El Archivo...");
       getch();
       }else{
       idaux=_creat("A:\Eliminar.dat",FA_ARCH);
       if(idaux==-1){
       cprintf("Error Al Crear El Archivo...");
       getch();
       close(idaux);
       exit(0);
       }else
	 {
	  close(idaux);
	 idaux=_open("A:\Eliminar.dat",O_RDWR);
	  if(idaux==-1){
       cprintf("Error Al Abrir El Archivo...");
       getch();
       close(idaux);
       exit(0);
       }
       close(id2);
	id2 =_open("A:\Nota.dat",O_RDWR);
	if(id2==-1){
	cprintf("Error Al Leer El Archivo");
	getch();
	close(id2);
	exit(0);
	}
	  while(!eof(id2)){
	 if(_read(id2,&reg3,sizeof(reg3))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id2);
	exit(0);
	}
       if(strcmp(reg3.codest,Codigo)!=0){
       strcpy(aux1.codest,reg3.codest);
       strcpy(aux1.codmat,reg3.codmat);
       aux1.nota1=reg3.nota1;
       aux1.nota2=reg3.nota2;
       aux1.nota3=reg3.nota3;
	if(write(idaux,&aux1,sizeof(aux1))==-1){
	cprintf("Error De Escritura En El Archivo....");
	getch();
	close(id2);
	close(idaux);
	exit(0);
	}
     }
      }
       close(id2);
      remove("a:\Nota.dat");
     
      id2 = _creat ("a:\Nota.dat",FA_ARCH);
      close (id2);
      id2=_open("a:\Nota.dat",O_RDWR);
      if(id2==-1){
      cprintf("Error Al Abrir El Archivo");
      getch();
      exit(0);
		 }

      lseek(idaux,0L,0);
      while(!eof(idaux)){
      if(_read(idaux,&aux1,sizeof(aux1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(idaux);
	 exit(0);
	 }

	 strcpy(reg3.codest,aux1.codest);
	 strcpy(reg3.codmat,aux1.codmat);
	 reg3.nota1=aux1.nota1;
	 reg3.nota2=aux1.nota2;
	 reg3.nota3=aux1.nota3;
	 if(_write(id2,&reg3,sizeof(reg3))){
	 cprintf("Error Al Escribir El Archivo");
	 getch();
	 close(id2);
	 exit(0);
	 }
	 }
      close(id2);
      close(idaux);

       }
    }
    }
    }
close(id2);
}
close(id2);
remove("A:\Eliminar.dat");
}

void Eliminar_Estudiante(){
char Codigo[50];
int Sw=0,Sw1=0;
int idaux,idaux1;

       while(1){
	id2 =_open("A:\Nota.dat",O_RDWR);
	id1=_open("A:\Estudiante.dat",O_RDWR);
       clrscr();
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("****  Eliminacion De Notas  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(25,4,1));
       if(Codigo[0]=='*')
	   break;
	else{
	if(id2==-1||id1==-1){
	cprintf("Error Al Leer El Archivo");
	getch();
	close(id2);
	exit(0);
	}
	else
	{
	Sw=0;
	while(!eof(id2)&&Sw==0){
	if(_read(id2,&reg3,sizeof(reg3))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id2);
	exit(0);
	}
       if(strcmp(reg3.codest,Codigo)==0)
	  Sw=1;
       }
	Sw1=0;
	while(!eof(id1)&&Sw1==0){
	if(_read(id1,&reg1,sizeof(reg1))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id1);
	exit(0);
	}
       if(strcmp(reg1.cod,Codigo)==0)
	  Sw1=1;
       }
       if(Sw1==0){
       cprintf("Este  Codigo No Se Encuentran En El Archivo...");
       getch();
       }else{
       idaux=_creat("A:\Eliminar.dat",FA_ARCH);
       idaux1=_creat("A:\Eliminar1.dat",FA_ARCH);
       if((Sw==1&&idaux==-1)||(idaux1==-1)){
       cprintf("Error Al Crear El Archivo...");
       getch();
       close(idaux);
       close(idaux1);
       exit(0);
       }else
	 {
	  close(idaux);
	  close(idaux1);
	 idaux=_open("A:\Eliminar.dat",O_RDWR);
	 idaux=_open("A:\Eliminar1.dat",O_RDWR);
	  if(idaux==-1||idaux1==-1){
       cprintf("Error Al Abrir El Archivo...");
       getch();
       close(idaux);
       close(idaux1);
       exit(0);
       }
       close(id2);
       close(id1);
	id2 =_open("A:\Nota.dat",O_RDWR);
	id1 =_open("A:\Estudiante.dat",O_RDWR);
	if(id2==-1){
	cprintf("Error Al Leer El Archivo");
	getch();
	close(id2);
	exit(0);
	}
	  while(!eof(id2)){
	 if(_read(id2,&reg3,sizeof(reg3))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id2);
	exit(0);
	}
       if(strcmp(reg3.codest,Codigo)!=0){
       strcpy(aux1.codest,reg3.codest);
       strcpy(aux1.codmat,reg3.codmat);
       aux1.nota1=reg3.nota1;
       aux1.nota2=reg3.nota2;
       aux1.nota3=reg3.nota3;
	if(write(idaux,&aux1,sizeof(aux1))==-1){
	cprintf("Error De Escritura En El Archivo....");
	getch();
	close(id2);
	close(idaux);
	exit(0);
	}
     }
      }
	 close(id2);
	  while(!eof(id1)){
	 if(_read(id1,&reg1,sizeof(reg1))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id1);
	exit(0);
	}
       if(strcmp(reg1.cod,Codigo)!=0){
       strcpy(aux3.cod,reg1.cod);
       strcpy(aux3.nom,reg1.nom);
       strcpy(aux3.fac,reg1.fac);
       strcpy(aux3.fec,reg1.fec);
	if(write(idaux1,&aux3,sizeof(aux3))==-1){
	cprintf("Error De Escritura En El Archivo....");
	getch();
	close(id1);
	close(idaux1);
	exit(0);
	}
     }
      }
       close(id1);
      remove("a:\Nota.dat");
      remove("a:\Estudiante.dat");
      id2 = _creat ("a:\Nota.dat",FA_ARCH);
      close (id2);
      id1 = _creat ("a:\Estudiante.dat",FA_ARCH);
       close (id1);
      id2=_open("a:\Nota.dat",O_RDWR);
      id1=_open("a:\Estudiante.dat",O_RDWR);
      if(id2==-1||id1==-1){
      cprintf("Error Al Abrir El Archivo");
      getch();
      exit(0);
		 }

      lseek(idaux,0L,0);
      while(!eof(idaux)){
      if(_read(idaux,&aux1,sizeof(aux1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(idaux);
	 exit(0);
	 }

	 strcpy(reg3.codest,aux1.codest);
	 strcpy(reg3.codmat,aux1.codmat);
	 reg3.nota1=aux1.nota1;
	 reg3.nota2=aux1.nota2;
	 reg3.nota3=aux1.nota3;
	 if(_write(id2,&reg3,sizeof(reg3))){
	 cprintf("Error Al Escribir El Archivo");
	 getch();
	 close(id2);
	 exit(0);
	 }
	 }
      close(id2);
      close(idaux);
      lseek(idaux1,0L,0);
      while(!eof(idaux1)){
      if(_read(idaux1,&aux3,sizeof(aux3))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(idaux1);
	 exit(0);
	 }
	 if(_write(id1,&aux3,sizeof(aux3))){
	 cprintf("Error Al Escribir El Archivo");
	 getch();
	 close(id1);
	 exit(0);
	 }
	 }
      close(id1);
      close(idaux1);


       }
    }
    }
    }
close(id2);
close(id1);
}
close(id2);
close(id1);
remove("A:\Eliminar.dat");
remove("A:\Eliminar1.dat");
}

void Eliminar_Materia(){
char Codigo[50];
int Sw=0;
int idaux;

       while(1){
	id1 =_open("A:\Materia.dat",O_RDWR);
       clrscr();
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("****  Eliminacion De Materias  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Materia   : ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(25,4,1));
       if(Codigo[0]=='*')
	   break;
	else{
	Sw=0;
	while(!eof(id1)&&Sw==0){
	if(_read(id1,&reg2,sizeof(reg2))==-1){
	cprintf("Error Al Leer El Achivo");
	getch();
	close(id1);
	exit(0);
					    }
	if(strcmp(reg2.cod,Codigo)==0)
	       Sw=1;
	     }


	  if(Sw==0)
	  {
	  cprintf("El Codigo No Existe ......");
	  getch();
	  }
	  else
	     {
	    
	     idaux=_creat("Eliminar.dat",O_RDWR);
	      if(idaux==-1)
	      {
	       cprintf("Error Al Crear El Archivo...");
	       getch();
	       close(idaux);
	       exit(0);
	       }
	       close(idaux);
		 idaux=_open("Eliminar.dat",O_RDWR);
		  if(idaux==-1){
	       cprintf("Error Al Abrir El Archivo...");
	       getch();
	       close(idaux);
	       exit(0);
		}
		lseek(id1,0L,SEEK_SET);
	 while(!eof(id1)){
	 if(_read(id1,&reg2,sizeof(reg2))==-1){
	cprintf("Error De Lectura En El Archivo...");
	getch();
	close(id1);
	exit(0);
	}
       if(strcmp(reg2.cod,Codigo)!=0)
       {
       strcpy(aux.cod,reg2.cod);
       strcpy(aux.nom,reg2.nom);
       aux.sem=reg2.sem;
	if(_write(idaux,&aux,sizeof(aux))==-1)
	{
	cprintf("Error De Escritura En El Archivo....");
	getch();
	close(id1);
	close(idaux);
	exit(0);
	}
	}
	}
    close(id1);
      close(idaux);
      remove("a:\Materia.dat");
     
      id1 = _creat ("a:\Materia.dat",FA_ARCH);
      close (id1);
      id1=_open("a:\Materia.dat",O_RDWR);
      if(id1==-1){
      cprintf("Error Al Abrir El Archivo");
      getch();
      exit(0);
		 }
 idaux=_open("Eliminar.dat",O_RDWR);
		  if(idaux==-1){
	       cprintf("Error Al Abrir El Archivo...");
	       getch();
	       close(idaux);
	       exit(0);
		}
     
      while(!eof(idaux)){
      if(_read(idaux,&aux,sizeof(aux))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(idaux);
	 exit(0);
	 }
	 if(_write(id1,&aux,sizeof(aux))==-1){
	 cprintf("Error Al Escribir El Archivo");
	 getch();
	 close(id1);
	 exit(0);
	 }
	 }
      close(id1);
      close(idaux);

       }
    }
    close(id1);
    }
    close(id1);
    }

/***********************************************************************/
void Crear_Archivo_Estudiante(){
	id = _creat ("a:\Estudiante.dat",FA_ARCH);
	close (id);
}
/***********************************************************************/
void Crear_Archivo_Materia(){
	id1 = _creat ("a:\Materia.dat",FA_ARCH);
	close (id1);
}
/***********************************************************************/
void Crear_Archivo_Nota(){
	id2 = _creat ("a:\Nota.dat",FA_ARCH);
	close (id2);
}
/***********************************************************************/

char *ValidarNumeros(int x,int y,int tipo){
			 char a[20];
			 int z,p;
			  do{
			  z=0;p=0;
			  gotoxy(x,y);
			  clreol();
			  scanf("\n");
			  gets(a);
			 while(a[z]!='\0'){
			 if((a[0]=='*')&& (tipo==1||tipo==2))
			    return(a);
			 if(a[z]<'0'|| a[z] > '9' ) p=-1;

			 z++;
			 }
			 if((a[0]=='0')&&(tipo==0||tipo==1||tipo==3))
			     p=-1;
			     if(strlen(a)>12&&tipo==1)
			     p=-1;
			     if(strlen(a)>8&&tipo==0)
			     p=-1;
			    if(strlen(a)>6&&tipo==2)
			     p=-1;
			   if(strlen(a)>2&&tipo==3)
			     p=-1;

		       }while(p==-1);
			return(a);
			 }
/***********************************************************************/
void Adicionar_Estudiante(){
char Codigo[10],fecha[12];
int Sw=0,i;
       id =_open("A:\Estudiante.dat",O_RDWR);
       if(id==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("****  Captura De Estudiantes  ****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Cedula Estudiante: ");
       gotoxy(5,7);
       cprintf("Nombre Estudiante: ");
       gotoxy(5,8);
       cprintf("Facultad Estudiante: ");
       gotoxy(1,9);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(52,10);
       cprintf("Fecha De Ingreso:");
       strcpy(Codigo,ValidarNumeros(23,4,1));
       if(Codigo[0]=='*')
	 break;
	 else{
	 Sw=Buscar_Estudiante(Codigo);
	 lseek(id, 0L, SEEK_CUR);
	 if(Sw==2)
	  break;
	  else
	     {
	     if(Sw==1){
	     cprintf("El Codigo Digitado Ya Existe......");
	     getch();
		      }
		      else{
                         strcpy(reg1.cod,Codigo);
			 strcpy(reg1.ced,ValidarNumeros(23,6,0));
			 Sw=Buscar_Cedula(reg1.ced);
			  lseek(id, 0L, SEEK_CUR);
	 if(Sw==2)
	  break;
	  else
	     {
	     if(Sw==1){
	     cprintf("La Cedula Digitada Ya Existe......");
	     getch();
		      }
		      else{
		      do{
	     Sw=1;
		   
		   gotoxy(23,7);
		      scanf("\n");
		      gets(reg1.nom);

	     for(i=0;i<strlen(reg1.nom);i++){
	     if(isdigit(reg1.nom[i])){
		 Sw=0;
		 break;
		 }
	       }

	      }while(Sw!=1);

			      do{
	     Sw=1;
		   
		   gotoxy(23,8);
		      scanf("\n");
		      gets(reg1.fac);

	     for(i=0;i<strlen(reg1.fac);i++){
	     if(isdigit(reg1.fac[i])){
		 Sw=0;
		 break;
		 }
	       }

	      }while(Sw!=1);
		      getdate(&t);
		      reg1.fec[0]='\0';
		      itoa(t.da_day,fecha,10);
		      strcat(reg1.fec,fecha);
		      strcat(reg1.fec,"/");
		      itoa(t.da_mon,fecha,10);
		      strcat(reg1.fec,fecha);
		      strcat(reg1.fec,"/");
		     itoa(t.da_year,fecha,10);
		      strcat(reg1.fec,fecha);
		      gotoxy(72,10);
		      cprintf("%s",reg1.fec);
		      getch();
		      fecha[0]='\0';
		      strcpy(fecha,reg1.fec);
if(_write(id,&reg1,sizeof(reg1))==-1)
   {
   cprintf("Error Al Escribir En El Archivo Estudiantes");
   close(id);
   getch();
   return;
   }
		     reg1.cod[0]='\0';
		     reg1.ced[0]='\0';
		     reg1.nom[0]='\0';
		     reg1.fac[0]='\0';
		     reg1.fec[0]='\0';
		      }
	       }

  }

  }
  }
	 



}
}	 

/***********************************************************************/
void Adicionar_Materia(){
char Codigo[10],fecha[12];
int Sw=0,i;
       id1 =_open("A:\Materia.dat",O_RDWR);
       if(id1==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("*****  Captura De Materias  *****");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo De La Materia: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Nombre De La Materia: ");
       gotoxy(5,7);
       cprintf("Semestre           : ");
       gotoxy(1,8);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(26,4,2));
       if(Codigo[0]=='*')
	 break;
	 else{
	 Sw=Buscar_Materia(Codigo);
	 lseek(id, 0L, SEEK_CUR);
	 if(Sw==2)
	  break;
	  else
	     {
	     if(Sw==1){
	     cprintf("El Codigo Digitado Ya Existe......");
	     getch();
		      }
		      else{
			 strcpy(reg2.cod,Codigo);
	     do{
	     Sw=1;
	     gotoxy(27,6);
	    scanf("\n");
	    gets(reg2.nom);
	     for(i=0;i<strlen(reg2.nom);i++){
	     if(isdigit(reg2.nom[i])){
		 Sw=0;
		 break;
		 }
	       }

	      }while(Sw!=1);

		     
		      reg2.sem=atoi(ValidarNumeros(27,7,3));
if(_write(id1,&reg2,sizeof(reg2))==-1)
   {
   cprintf("Error Al Escribir En El Archivo Materia    ");
   close(id);
   getch();
   return;
   }
		     reg2.cod[0]='\0';
		     reg2.nom[0]='\0';
		      }
	       }

  }


	 



}
}	 
/***********************************************************************/
void Adicionar_Nota(){
char Codigo[10],fecha[12];

float promedio=0;
int Sw=0;
       id2 =_open("A:\Nota.dat",O_RDWR);
       id =_open("A:\Estudiante.dat",O_RDWR);
       id1 =_open("A:\Materia.dat",O_RDWR);
       if(id2==-1||id1==-1||id==-1){
       cprintf("Error Al Abrir El Archivo........");
       getch();
       }
       else
       while(1){
       clrscr();
       gotoxy(1,1);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(23,2);
       cprintf("    **** Captura De Notas ****    ");
       gotoxy(1,3);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,4);
       cprintf("Codigo Estudiante: ");
       gotoxy(1,5);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,6);
       cprintf("Nombre Estudiante: ");
       gotoxy(5,7);
       cprintf("Facultad..............: ");
       gotoxy(1,8);
       cprintf("--------------------------------------------------------------------------------");
       gotoxy(5,9);
       cprintf("Codigo Materia.......: ");
       gotoxy(5,10);
       cprintf("Nota 1...............:");
       gotoxy(5,11);
       cprintf("Nota 2...............:");
       gotoxy(5,12);
       cprintf("Nota 3...............:");
       gotoxy(5,13);
       cprintf("Promedio.............:");
       gotoxy(1,14);
       cprintf("--------------------------------------------------------------------------------");
       strcpy(Codigo,ValidarNumeros(25,4,1));
       if(Codigo[0]=='*')
	 break;
	 else{
	 Sw=0;
       lseek(id,0L,SEEK_SET);
	 while(!eof(id)&&Sw==0){
	 if(_read(id,&reg1,sizeof(reg1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(id);
	 exit(0);
					     }
	 else
	    if(strcmp(reg1.cod,Codigo)==0){
	    gotoxy(25,6);
	    cprintf("%s",reg1.nom);
	    gotoxy(25,7);
	    cprintf("%s",reg1.fac);
	    Sw=1;
	  }
	 }
	  if(Sw==0){
	  cprintf("Este Codigo No Se Puede Insertar No Existe");
	  getch();
	  }else
	    { 
	  strcpy(Codigo,ValidarNumeros(27,9,1));
	  lseek(id2,0L,SEEK_SET);
	 Sw=0;
	 while(!eof(id2)&&Sw==0){
	 if(_read(id2,&aux1,sizeof(aux1))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(id2);
	 exit(0);
					     }
	 else
	    if(strcmp(reg1.cod,aux1.codest)==0&&strcmp(aux1.codmat,Codigo)==0)
	    Sw=1;
	  }
	  if(Sw==1){
	  cprintf("Este Codigo No Se Puede Insertar Ya Tiene Notas");
	  getch();
	  }else
	  {
	  lseek(id,0L,SEEK_SET);
	  Sw=0;
	  lseek(id1,0L,SEEK_SET);
	  Sw=0;
	 while(!eof(id1)&&Sw==0){
	 if(_read(id1,&reg2,sizeof(reg2))==-1){
	 cprintf("Error Al Leer El Archivo");
	 getch();
	 close(id1);
	 exit(0);
					     }
	 else
	    if(strcmp(reg2.cod,Codigo)==0){
	    gotoxy(50,9);
	    cprintf("%s",reg2.nom);
	    gotoxy(50,6);
	    cprintf("%d",reg2.sem);
	    Sw=1;
	  }
	 }
	if(Sw==0){
	cprintf("Este Codigo No Se Puede Insertar No Existe Materia");
	getch();
	       }
	else   {
	 lseek(id2,0L,SEEK_END);
		  do{
		    gotoxy(28,10);
		    clreol();
		    reg3.nota1=ValidarNota();
		    }while(reg3.nota1==-1);
		     do{
		    gotoxy(28,11);
		    clreol();
		    reg3.nota2=ValidarNota();
		    }while(reg3.nota2==-1);
		     do{
		    gotoxy(28,12);
		    clreol();
		    reg3.nota3=ValidarNota();
		    }while(reg3.nota2==-1);
		    promedio=(reg3.nota1+reg3.nota2+reg3.nota3)/3;
		    gotoxy(28,13);
		    cprintf("%.2f",promedio);
		    Codigo[0]='\0';
		    strcpy(reg3.codest,reg1.cod);
		    strcpy(reg3.codmat,reg2.cod);
		   if(_write(id2,&reg3,sizeof(reg3))==-1)
		   {
		   cprintf("Error Al Escribir En El Archivo Estudiantes");
		   close(id2);
		   getch();
		   return;
		}
		 reg3.codest[0]='\0';   
		 reg3.codmat[0]='\0';   

	      }
	 }
     }
    }
  }
close(id2);
close(id1);
close(id);
}
/***********************************************************************/


/***********************************************************************/
int Buscar_Cedula(char cedula[]){
struct estudiante Reg;
lseek(id, 0L, SEEK_SET);
while(!eof(id)){
    if(_read(id,&Reg,sizeof(Reg))==-1){
	cprintf("Error Al Leer El Archivo.......");
	 getch();
	 close(id);
	return(2);
      }else{
      if(strcmp(Reg.ced,cedula)==0){
      return(1);
      }
      }
   }
   return(0);
 }
/***********************************************************************/
int Buscar_Estudiante(char codigo[]){
struct estudiante Reg;
lseek(id, 0L, SEEK_SET);
while(!eof(id)){
    if(_read(id,&Reg,sizeof(Reg))==-1){
	cprintf("Error Al Leer El Archivo.......");
	 getch();
	 close(id);
	return(2);
      }else{
      if(strcmp(Reg.cod,codigo)==0){
      return(1);
      }
      }
   }
   return(0);
 }
/***********************************************************************/
int Buscar_Materia(char codigo[]){
struct materias Reg;
lseek(id1, 0L, SEEK_SET);

while(!eof(id1)){
    if(_read(id1,&Reg,sizeof(Reg))==-1){
	cprintf("Error Al Leer El Archivo.......");
	 getch();
	 close(id1);
	return(2);
      }else{
      if(strcmp(Reg.cod,codigo)==0){
      close(id1);
      return(1);
      }
      }
   }
   return(0);
   }
 
/***********************************************************************/      
 float ValidarNota(){
			 char a[20];int z=0,sw1=0;
			 float p=0;
			 scanf("\n");gets(a);
			 while(a[z]!='\0'&& p!= -1){
			 if(a[z]< '0' || a[z]>'9')p=-1;
			 if(a[z]== '.' && sw1==0){
			 p=0;sw1=1;
						    }
			 z++;
			 }
			 if((atof(a)>5)||(strlen(a)>3))p=-1;
			 if(p!=-1)return(atof(a));
			 else if(p==-1)return(p);
			 return(p);
			 }
//******************************************************//



void main()
{char opci;
clrscr();
while(1){
clrscr();
textbackground(9);
textcolor(15);
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("_______________MENU PRINCIPAL_______________");
gotoxy(18,10);cprintf("1.MANTENIMIENTO DE TABLA");
gotoxy(18,11);cprintf("2.CONSULTAS             ");
gotoxy(18,12);cprintf("3.MODIFICAR             ");
gotoxy(18,13);cprintf("4.ELIMINAR              ");
gotoxy(18,14);cprintf("5.INICIALIZAR           ");
gotoxy(18,15);cprintf("6.SALIR");
gotoxy(18,17);cprintf ("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,17);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':menu_mantenimiento();break;
   case '2':menu_consulta();break;
   case '3':menu_Modificar();break;
   case '4':menu_Eliminar();break;
   case '5':menu_Inicializar();break;
   case '6':exit(0);
}
}
}
void menu_mantenimiento(){
char opci;
clrscr();
while(1){
clrscr();
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("____________MENU MANTENIMIENTO_____________");
gotoxy(18,10);cprintf("1.CREACION DE ESTUDIANTES");
gotoxy(18,11);cprintf("2.CREACION DE MATERIAS  ");
gotoxy(18,12);cprintf("3.CREACION DE NOTAS     ");
gotoxy(18,13);cprintf("4.SALIR");
gotoxy(18,15);cprintf ("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,15);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':Adicionar_Estudiante();break;
   case '2':Adicionar_Materia();break;
   case '3':Adicionar_Nota();break;
   case '4':return;
}
}
}
void menu_consulta(){
char opci;
clrscr();
while(1){
clrscr();
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("____________MENU CONSULTA___________________");
gotoxy(18,10);cprintf("1.CONSULTA DE ESTUDIANTES");
gotoxy(18,11);cprintf("2.CONSULTA DE MATERIAS  ");
gotoxy(18,12);cprintf("3.CONSULTA DE NOTAS     ");
gotoxy(18,13);cprintf("4.SALIR");
gotoxy(18,15);cprintf ("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,15);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':Consultar_PorEstudiante();break;
   case '2':Consultar_PorMateria();break;
   case '3':Consultar_PorNota();break;
   case '4':return;
}
}
}
void menu_Modificar(){
char opci;
clrscr();
while(1){
clrscr();
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("____________MENU MODIFICAR__________________");
gotoxy(18,10);cprintf("1.MODIFICAR   ESTUDIANTES");
gotoxy(18,11);cprintf("2.MODIFICAR   MATERIAS  ");
gotoxy(18,12);cprintf("3.MODIFICAR   NOTAS     ");
gotoxy(18,13);cprintf("4.SALIR");
gotoxy(18,15);cprintf ("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,15);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':Modificar_Estudiante();break;
   case '2':Modificar_Materia();break;
   case '3':Modificar_Notas();break;
   case '4':return;
}
}
}
void menu_Eliminar(){
char opci;
clrscr();
while(1){
clrscr();
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("____________MENU ELIMINAR___________________");
gotoxy(18,10);cprintf("1.ELIMINAR    ESTUDIANTES");
gotoxy(18,11);cprintf("2.ELIMINAR    MATERIAS  ");
gotoxy(18,12);cprintf("3.ELIMINAR    NOTAS     ");
gotoxy(18,13);cprintf("4.SALIR");
gotoxy(18,15);cprintf ("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,15);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':Eliminar_Estudiante();break;
   case '2':Eliminar_Materia();break;
   case '3':Eliminar_Nota();break;
   case '4':return;
}
}
}
void menu_Inicializar(){
char opci;
clrscr();
while(1){
clrscr();
gotoxy(18,8);cprintf("___________________________________________ ");
gotoxy(18,9);cprintf("____________MENU INICIALIZAR________________");
gotoxy(18,10);cprintf("1.CREAR ARCHIVO ESTUDIANTES");
gotoxy(18,11);cprintf("2.CREAR ARCHIVO MATERIAS   ");
gotoxy(18,12);cprintf("3.CREAR ARCHIVO NOTAS      ");
gotoxy(18,13);cprintf("4.SALIR");
gotoxy(18,15);cprintf("ELIJA UNA OPCION  [  ] << ENTER >>");
gotoxy(38,15);opci=getch();opci=toupper(opci);
putchar(opci);
switch(opci)
	{

   case '1':Crear_Archivo_Estudiante();break;
   case '2':Crear_Archivo_Materia();break;
   case '3':Crear_Archivo_Nota();break;
   case '4':return;
}
}
}



