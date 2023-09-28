PROGRAM EXAMEN;

USES
  CRT;

TYPE

   HOJA=RECORD
            NOMBRE:STRING[20];
            APELLIDO:STRING[20];
            DIRECCION:STRING[20];
            CEDULA:STRING[8];
            EXPEDIDA:STRING[20];
            CIVIL:STRING[7];
            SEXO:STRING[9];
            DIA:STRING[2];
            MES:STRING[2];
            ANNO:BYTE;
            CARGO:STRING[20];
            ANT,SALARIO:LONGINT;
            ENTRA:WORD;
       END;


VAR
   ARCH,AUX1,AUX2:FILE OF HOJA;
   REG:HOJA;
   REG1:HOJA;
   REG2:HOJA;
   CUANTOS,A,I,J,JJ,X,Y,Z,XX,YY:WORD;
   OP,R,NO:CHAR;
   NOMBRE,APELLIDO,DIRECCION,EXPEDIDA,CARGO,VAR2:STRING[20];
   ANNO:BYTE;
   CEDULA,SALARIO:STRING[8];
   CIVIL:STRING[7];
   SEXO:CHAR;
   DIA,MES:STRING[2];
   YEYA:WORD;
   ANT:LONGINT;

PROCEDURE CREAR;

BEGIN
    CLRSCR;
    ASSIGN(ARCH,'A:JORGE.DAT');
    REWRITE(ARCH);
    R:='S';
    WHILE (R='S') OR (R='s') DO
        BEGIN
            CLRSCR;
            GOTOXY(35,8);WRITE('DIGITE EL NOMBRE: ');
            READLN(REG.NOMBRE);
            GOTOXY(35,9);WRITE('DIGITE EL APELLIDO: ');
            READLN(REG.APELLIDO);
            GOTOXY(35,10);WRITE('DIGITE LA CEDULA: ');
            READLN(REG.CEDULA);
            GOTOXY(35,11);WRITE('DIGITE LA DIRECCION: ');
            READLN(REG.DIRECCION);
            GOTOXY(35,12);WRITE('DIGITE EL CARGO: ');
            READLN(REG.CARGO);
            REPEAT
               BEGIN
                  REG.SEXO:='  ';
                  GOTOXY(35,13);WRITE('DIGITE EL SEXO (HOMBRE=1 MUJER=2): ');
                  READLN(SEXO);
               END;
            UNTIL (SEXO='1') OR (SEXO='2');
            IF (SEXO='1')  THEN
               REG.SEXO:='MASCULINO'
            ELSE
               IF (REG.CIVIL='2')  THEN
                  REG.SEXO:='FEMENINO';
            GOTOXY(35,14);WRITE('DIGITE EL ESTADO CIVIL ');
            REPEAT
               BEGIN
                  GOTOXY(35,15);WRITE('CASADO=C SOLTERO=S OTRO=O : ');
                  READLN(REG.CIVIL);
               END;
            UNTIL(REG.CIVIL='C')OR(REG.CIVIL='c')OR(REG.CIVIL='S')OR(REG.CIVIL='s')OR(REG.CIVIL='O')OR(REG.CIVIL='o');
            IF (REG.CIVIL='C') OR (REG.CIVIL='c') THEN
               REG.CIVIL:='CASADO'
            ELSE
               IF (REG.CIVIL='S') OR (REG.CIVIL='s') THEN
                  REG.CIVIL:='SOLTERO'
               ELSE
                  IF (REG.CIVIL='O') OR (REG.CIVIL='o') THEN
                     REG.CIVIL:='OTRO';
            REPEAT
               BEGIN
                  GOTOXY(35,17);WRITE('DIGITE EL A¥O DE INGRESO: ');
                  READLN(REG.ANNO);
               END;
            UNTIL REG.ANNO<=97;
                  CUANTOS:=97-REG.ANNO;
                    IF (CUANTOS>=5) AND (CUANTOS<10) THEN
                        ANT:=10000
                    ELSE
                       IF (CUANTOS>=10) AND (CUANTOS<=15) THEN
                          ANT:=30000
                       ELSE
                          IF (CUANTOS>15) THEN
                             ANT:=70000;
                  GOTOXY(35,18);WRITE('DIGITE EL SALARIO: ');
                  READLN(REG.SALARIO);
                  REG.SALARIO:=REG.SALARIO+ANT;
                  WRITE(ARCH,REG);
            REPEAT
               BEGIN
                  GOTOXY(30,23);WRITE('DESEA INGRESAR OTRO REGISTRO (S/N)?');
                  R:=READKEY;
               END;
            UNTIL (R='S') OR (R='s') OR (R='N') OR (R='n');
        END;
    CLOSE(ARCH);
END;


PROCEDURE MODIFICAR;


BEGIN
   CLRSCR;
   ASSIGN(ARCH,'A:/JORGE.DAT');
   ASSIGN(AUX1,'A:/RUSSO.DAT');
   ASSIGN (AUX2,'A:/MU¥OZ.DAT');
   RESET(ARCH);
   REWRITE(AUX1);
   REWRITE(AUX2);
   GOTOXY(35,12);WRITE('DIGITE EL NOMBRE: ');
   READ(NOMBRE);
   WHILE NOT EOF(ARCH) DO
      BEGIN
         READ(ARCH,REG);
         IF NOMBRE=REG.NOMBRE THEN
               BEGIN
                  CLRSCR;
                  GOTOXY(35,8);WRITE('NOMBRE: ');
                  WRITELN(REG.NOMBRE);
                  GOTOXY(35,9);WRITE('APELLIDO: ');
                  WRITELN(REG.APELLIDO);
                  GOTOXY(35,10);WRITE('CEDULA: ');
                  WRITELN(REG.CEDULA);
                  GOTOXY(35,11);WRITE('DIRECCION: ');
                  WRITELN(REG.DIRECCION);
                  GOTOXY(35,12);WRITE('CARGO: ');
                  WRITELN(REG.CARGO);
                  GOTOXY(35,13);WRITE('SEXO: ');
                  WRITELN(REG.SEXO);
                  GOTOXY(35,14);WRITE('ESTADO CIVIL ');
                  WRITELN(REG.CIVIL);
                  GOTOXY(35,17);WRITE('A¥O DE INGRESO: ');
                  WRITELN(REG.ANNO);
                  GOTOXY(35,18);WRITE('SALARIO: ');
                  WRITELN(REG.SALARIO);
                  IF READKEY<>#13 THEN
                     BEGIN
                        GOTOXY(43,8);READLN(REG1.NOMBRE);
                     END;
                  IF READKEY<>#13 THEN
                     BEGIN
                        GOTOXY(45,9);READLN(REG1.APELLIDO);
                     END;
                  IF READKEY<>#13 THEN
                     BEGIN
                        GOTOXY(43,10);READLN(REG1.CEDULA);
                     END;
                  IF READKEY<>#13 THEN
                     BEGIN
                        GOTOXY(47,11);READLN(REG1.DIRECCION);
                     END;
                  IF READKEY<>#13 THEN
                     BEGIN
                        GOTOXY(42,12);READLN(REG1.CARGO);
                     END;
                  IF READKEY<> #13 THEN
                     BEGIN
                        GOTOXY(42,13);READLN(REG1.SEXO);
                     END;
                  IF READKEY<> #13 THEN
                     BEGIN
                        GOTOXY(48,14);READLN(REG1.CIVIL);
                     END;
                  IF READKEY<> #13 THEN
                     BEGIN
                        GOTOXY(52,17);READLN(REG1.ANNO);
                     END;
                  IF READKEY<> #13 THEN
                    BEGIN
                       GOTOXY(44,18);READLN(REG1.SALARIO);
                    END;
                  WRITE(AUX1,REG1);
               END;
         IF (REG.NOMBRE=REG1.NOMBRE) THEN
            REG2.NOMBRE:=REG.NOMBRE
         ELSE
            REG2.NOMBRE:=REG1.NOMBRE;
         IF REG.APELLIDO=REG1.APELLIDO THEN
            REG2.APELLIDO:=REG.APELLIDO
         ELSE
            REG2.APELLIDO:=REG1.APELLIDO;
         IF REG.CEDULA=REG1.CEDULA THEN
            REG2.CEDULA:=REG.CEDULA
         ELSE
            REG2.CEDULA:=REG1.CEDULA;
         IF REG.DIRECCION=REG1.DIRECCION THEN
            REG2.DIRECCION:=REG.DIRECCION
         ELSE
            REG2.DIRECCION:=REG1.DIRECCION;
         IF REG.CARGO=REG1.CARGO THEN
            REG2.CARGO:=REG.CARGO
         ELSE
            REG2.CARGO:=REG1.CARGO;
         IF REG.SEXO=REG1.SEXO THEN
            REG2.SEXO:=REG.SEXO
         ELSE
            REG2.SEXO:=REG1.SEXO;
         IF REG.CIVIL=REG1.CIVIL THEN
            REG2.CIVIL:=REG.CIVIL
         ELSE
            REG2.CIVIL:=REG1.CIVIL;
         IF REG.ANNO=REG1.ANNO THEN
            REG2.ANNO:=REG.ANNO
         ELSE
            REG2.ANNO:=REG1.ANNO;
         IF REG.SALARIO=REG1.SALARIO THEN
            REG2.SALARIO:=REG.SALARIO
         ELSE
            REG2.SALARIO:=REG1.SALARIO;
            WRITE(AUX2,REG2);
         END;
         CLOSE(ARCH);CLOSE(AUX1);CLOSE(AUX2);
         ERASE(ARCH);
         ERASE(AUX1);
         RENAME(AUX2,'A:JORGE.DAT');
END;








PROCEDURE ELIMINAR;

BEGIN
   CLRSCR;
   ASSIGN(ARCH,'A:/JORGE.DAT');
   ASSIGN(AUX1,'A:/RUSSO.DAT');
   RESET(ARCH);
   REWRITE(AUX1);
   NO:='N';
   GOTOXY(35,12);WRITE('DIGITE EL NOMBRE :');
   READLN(NOMBRE);
   X:=0;
   WHILE NOT EOF(ARCH) DO
      BEGIN
         READ(ARCH,REG);
         IF NOMBRE<>REG.NOMBRE THEN
            WRITE(AUX1,REG)
         ELSE
            IF NOMBRE=REG.NOMBRE THEN
               BEGIN
                  GOTOXY(35,23);WRITE('EL REGISTRO FUE ELIMINADO');
                  GOTOXY(25,24);WRITE('PRESIONE CUALQUIER TECLA PARA CONTINUAR');
                  READKEY;
                  NO:='S';
                  X:=X+1;
              END;
            IF X=0 THEN
            BEGIN
               IF NO='N' THEN
                  BEGIN
                     CLRSCR;
                     GOTOXY(35,23);WRITE('EL NOMBRE NO EXISTE');
                     GOTOXY(25,24);WRITE('PRESIONE CUALQUIER TECLA PARA CONTINUAR');
                     READKEY;
                  END;
            END;
      END;
      CLOSE(ARCH);
      CLOSE(AUX1);
      ERASE(ARCH);
      RENAME(AUX1,'A:JORGE.DAT');
END;








PROCEDURE ADICION;

BEGIN
    CLRSCR;
    ASSIGN(ARCH,'A:JORGE.DAT');
    RESET(ARCH);
    WHILE NOT EOF(ARCH) DO
       READ(ARCH,REG);
    R:='S';
    WHILE (R='S') OR (R='s') DO
        BEGIN
            CLRSCR;
            GOTOXY(35,8);WRITE('DIGITE EL NOMBRE: ');
            READLN(REG.NOMBRE);
            GOTOXY(35,9);WRITE('DIGITE EL APELLIDO: ');
            READLN(REG.APELLIDO);
            GOTOXY(35,10);WRITE('DIGITE LA CEDULA: ');
            READLN(REG.CEDULA);
            GOTOXY(35,11);WRITE('DIGITE LA DIRECCION: ');
            READLN(REG.DIRECCION);
            GOTOXY(35,12);WRITE('DIGITE EL CARGO: ');
            READLN(REG.CARGO);
            REPEAT
               BEGIN
                  REG.SEXO:='  ';
                  GOTOXY(35,13);WRITE('DIGITE EL SEXO (HOMBRE=1 MUJER=2): ');
                  READLN(REG.SEXO);
               END;
            UNTIL (REG.SEXO='1') OR (REG.SEXO='2');
            GOTOXY(35,14);WRITE('DIGITE EL ESTADO CIVIL ');
            REPEAT
               BEGIN
                  GOTOXY(35,15);WRITE('CASADO=C SOLTERO=S OTRO=O : ');
                  READLN(REG.CIVIL);
               END;
            UNTIL(REG.CIVIL='C')OR(REG.CIVIL='c')OR(REG.CIVIL='S')OR(REG.CIVIL='s')OR(REG.CIVIL='O')OR(REG.CIVIL='o');
            IF (REG.CIVIL='C') OR (REG.CIVIL='c') THEN
               REG.CIVIL:='CASADO'
            ELSE
               IF (REG.CIVIL='S') OR (REG.CIVIL='s') THEN
                  REG.CIVIL:='SOLTERO'
               ELSE
                  IF (REG.CIVIL='O') OR (REG.CIVIL='o') THEN
                     REG.CIVIL:='OTRO';
            REPEAT
               BEGIN
                  GOTOXY(35,17);WRITE('DIGITE EL A¥O DE INGRESO: ');
                  READLN(REG.ANNO);
               END;
            UNTIL REG.ANNO<=97;
                  CUANTOS:=97-REG.ANNO;
                    IF (CUANTOS>=5) AND (CUANTOS<10) THEN
                        ANT:=10000
                    ELSE
                       IF (CUANTOS>=10) AND (CUANTOS<=15) THEN
                          ANT:=30000
                       ELSE
                          IF (CUANTOS>15) THEN
                             ANT:=70000;
                  GOTOXY(35,18);WRITE('DIGITE EL SALARIO: ');
                  READLN(REG.SALARIO);
                  REG.SALARIO:=REG.SALARIO+ANT;
                  WRITE(ARCH,REG);
            REPEAT
               BEGIN
                  GOTOXY(30,23);WRITE('DESEA INGRESAR OTRO REGISTRO (S/N)?');
                  R:=READKEY;
               END;
            UNTIL (R='S') OR (R='s') OR (R='N') OR (R='n');
        END;
    CLOSE(ARCH);
END;




PROCEDURE PORCEDULA;

BEGIN
   CLRSCR;
   GOTOXY(35,12);WRITE('DIGITE NUMERO DE CEDULA: ');
   READLN(CEDULA);
   ASSIGN(ARCH,'A:/JORGE.DAT');
   RESET(ARCH);
   X:=0;
   WHILE NOT EOF(ARCH) DO
      BEGIN
         READ(ARCH,REG);
         IF CEDULA=REG.CEDULA THEN
            BEGIN
               CLRSCR;
               GOTOXY(35,8);WRITE('NOMBRE: ');
               WRITELN(REG.NOMBRE);
               GOTOXY(35,9);WRITE('APELLIDO: ');
               WRITELN(REG.APELLIDO);
               GOTOXY(35,10);WRITE('CEDULA: ');
               WRITELN(REG.CEDULA);
               GOTOXY(35,11);WRITE('DIRECCION: ');
               WRITELN(REG.DIRECCION);
               GOTOXY(35,12);WRITE('CARGO: ');
               WRITELN(REG.CARGO);
               GOTOXY(35,13);WRITE('SEXO: ');
               WRITELN(REG.SEXO);
               GOTOXY(35,14);WRITE('ESTADO CIVIL ');
               WRITELN(REG.CIVIL);
               GOTOXY(35,17);WRITE('A¥O DE INGRESO: ');
               WRITELN(REG.ANNO);
               GOTOXY(35,18);WRITE('SALARIO: ');
               WRITELN(REG.SALARIO);
               X:=X+1;
            END
      END;
   IF X=0 THEN
      BEGIN
         GOTOXY(35,23);WRITE('CEDULA NO EXISTE');
      END;
   GOTOXY(25,24);WRITE('PRESIONE CUALQUIER TECLA PARA CONTINUAR');
   READKEY;
   OP:='3';
END;



PROCEDURE PORAPELLIDO;

BEGIN
   CLRSCR;
   GOTOXY(35,12);WRITE('DIGITE EL APELLIDO: ');
   READLN(APELLIDO);
   ASSIGN(ARCH,'A:/JORGE.DAT');
   RESET(ARCH);
   X:=0;
   WHILE NOT EOF(ARCH) DO
      BEGIN
         READ(ARCH,REG);
         IF APELLIDO=REG.APELLIDO THEN
            BEGIN
               CLRSCR;
               GOTOXY(35,8);WRITE('NOMBRE: ');
               WRITELN(REG.NOMBRE);
               GOTOXY(35,9);WRITE('APELLIDO: ');
               WRITELN(REG.APELLIDO);
               GOTOXY(35,10);WRITE('CEDULA: ');
               WRITELN(REG.CEDULA);
               GOTOXY(35,11);WRITE('DIRECCION: ');
               WRITELN(REG.DIRECCION);
               GOTOXY(35,12);WRITE('CARGO: ');
               WRITELN(REG.CARGO);
               GOTOXY(35,13);WRITE('SEXO: ');
               WRITELN(REG.SEXO);
               GOTOXY(35,14);WRITE('ESTADO CIVIL ');
               WRITELN(REG.CIVIL);
               GOTOXY(35,17);WRITE('A¥O DE INGRESO: ');
               WRITELN(REG.ANNO);
               GOTOXY(35,18);WRITE('SALARIO: ');
               WRITELN(REG.SALARIO);
               X:=X+1;
            END
      END;
   IF X=0 THEN
      BEGIN
         GOTOXY(35,23);WRITE('APELLIDO NO EXISTE');
      END;
   GOTOXY(25,24);WRITE('PRESIONE CUALQUIER TECLA PARA CONTINUAR');
   READKEY;
   OP:='3';
END;



PROCEDURE MENUCONSULTA;

BEGIN
   CLRSCR;
   GOTOXY(35,10);WRITE('1. CONSULTA POR CEDULA');
   GOTOXY(35,12);WRITE('2. CONSULTA POR APELLIDO');
   GOTOXY(35,14);WRITE('3. REGRESAR A MENU PRINCIPAL');
   GOTOXY(35,18);WRITE('DIGITE UN NUMERO (1-3)');
   REPEAT
         OP:=READKEY;
         CASE OP OF
            '1':PORCEDULA;
            '2':PORAPELLIDO;
         END;
   UNTIL OP='3';
END;



PROCEDURE CONSULTAR;

BEGIN
   MENUCONSULTA;
END;






PROCEDURE MENU;


begin
   repeat
      begin
         clrscr;
         textbackground(black);
         GOTOXY(17,6);
         TEXTCOLOR(white);
         write('              MENU PRINCIPAL             ');
         textbackground(BLACK);
         textcolor(YELLOW);
         gotoxy(30,11);write('1.CREAR    ');
         gotoxy(30,12);write('2.CONSULTAR');
         gotoxy(30,13);write('3.MODIFICAR');
         gotoxy(30,14);write('4.ELIMINAR ');
         gotoxy(30,15);write('5.ADICIONAR');
         gotoxy(30,16);write('6.EXIT     ');
         textbackground(11);
         textcolor(black);
         gotoxy(1,24);
         write('    DIGITE EL NUMERO DE LA OPCION                                              ');
         gotoxy(35,24);
         OP:=READKEY;
         CASE OP OF
            '1':CREAR;
            '2':CONSULTAR;
            '3':MODIFICAR;
            '4':ELIMINAR;
            '5':ADICION;
          END;
      END;
   UNTIL  OP='6';
END;


BEGIN
   MENU;
END.