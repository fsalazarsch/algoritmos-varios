PROGRAM VEINTE;

USES CRT;
CONST
   MAXIMO=10;
TYPE
   TIPOINFO=INTEGER;
   TIPOINF=REAL;
   NODO=^X;
   X=RECORD
       INFO:INTEGER;
       IZQ:NODO;
       DER:NODO;
     END;
   LIFO=RECORD
          T:INTEGER;
          B:ARRAY[0..MAXIMO] OF NODO;
        END;
   ARBOL=^Y;
   Y=RECORD
       INF:REAL;
       IZ:ARBOL;
       DR:ARBOL;
     END;

VAR
  A:NODO;
  Z:ARBOL;
  N:NODO;
  ELEM:TIPOINFO;
  ENT:TIPOINF;
  OPCIONES:CHAR;

PROCEDURE INSERTAR1(X:TIPOINFO; VAR P:NODO);
BEGIN
   IF P=NIL THEN
      BEGIN
         NEW(P);
         P^.INFO:=X;
         P^.IZQ:=NIL;
         P^.DER:=NIL;
      END
   ELSE
   IF X<(P^.INFO) THEN
      INSERTAR1(X,P^.IZQ)
   ELSE
      INSERTAR1(X,P^.DER);
END;

PROCEDURE BUSCAR1(ELEM:TIPOINFO; VAR P:NODO);
BEGIN
   IF P=NIL THEN
      WRITELN('NO SE ENCONTRO')
   ELSE
   IF ELEM=P^.INFO THEN
      WRITELN('SE ENCONTRO ELEMENTO')
   ELSE
   IF ELEM<P^.INFO THEN
      BEGIN
         P:=P^.IZQ;
         BUSCAR1(ELEM,P^.IZQ);
      END
   ELSE
   IF ELEM>P^.INFO THEN
      BEGIN
         P:=P^.DER;
         BUSCAR1(ELEM,P^.DER);
      END;
END;

PROCEDURE BUSCAR2(P:NODO; ELEM:TIPOINFO);
VAR
  AUX:NODO;
BEGIN
   IF P=NIL THEN
      WRITELN('NO SE ENCONTRO ELEMENTO')
   ELSE
   REPEAT
         IF ELEM=P^.INFO THEN
            WRITELN('SE ENCONTRO ELEMENTO')
         ELSE
         IF ELEM<P^.INFO THEN
            P:=P^.IZQ
         ELSE
         IF ELEM>P^.INFO THEN
            P:=P^.DER;
   UNTIL P<>NIL
END;

PROCEDURE LEER1(X:TIPOINFO);
VAR
  N,I:TIPOINFO;
BEGIN
   WRITE('CUANTOS NUMEROS ESCRIBIRA?...');
   READLN(N);
   FOR I:=1 TO N DO
       READLN(X);
END;

PROCEDURE LEER2(X:TIPOINFO);
BEGIN
   WRITE('DIGITE EL NUMERO A ELIMINAR... ');
   READLN(X);
END;

PROCEDURE LEER3(J:TIPOINF);
VAR
  N,I:INTEGER;
BEGIN
   WRITE('CUANTOS NUMEROS ESCRIBIRA ?...');
   READLN(N);
   FOR I:=1 TO N DO
       READLN(J);
END;

PROCEDURE LEER_OPCION(OP:CHAR);
BEGIN
  READ(OP);
END;

PROCEDURE ELEMENTO(ELEM:TIPOINFO);
BEGIN
   WRITELN('DIGITE EL NUMERO A BUSCAR...');
   READLN(ELEM);
END;

PROCEDURE INICIAR_PILA(VAR P:LIFO);
BEGIN
  P.T:=0;
END;

FUNCTION PILA_VACIA(P:LIFO):BOOLEAN;
BEGIN
   PILA_VACIA:=P.T=0;
END;

PROCEDURE INSERTAR_PILA(VAR P:LIFO; S:NODO);
BEGIN
   IF P.T>MAXIMO THEN
      WRITELN('LA PILA NO SOPORTA MAS ELEMENTO')
   ELSE
   BEGIN
      P.T:=P.T+1;
      P.B[P.T-1]:=S;
   END;
END;

PROCEDURE RETIRAR_PILA(VAR P:LIFO; VAR S:NODO);
BEGIN
   IF (PILA_VACIA(P)) THEN
      BEGIN
         WRITELN('LA PILA ESTA VACIA...');
         S:=NIL;
      END
   ELSE
   BEGIN
      S:=P.B[P.T-1];
      P.T:=P.T-1;
   END;
END;

PROCEDURE PREORDEN(P:NODO);
VAR
  PILA:LIFO;
BEGIN
   INICIAR_PILA(PILA);
   WHILE (P<>NIL) DO
         BEGIN
            WRITE(P^.INFO:4);
            INSERTAR_PILA(PILA,P);
            P:=P^.IZQ;
         END;
   WHILE (NOT PILA_VACIA (PILA)) DO
         BEGIN
            RETIRAR_PILA(PILA,P);
            P:=P^.DER;
            WHILE (P<>NIL) DO
                  BEGIN
                     WRITE(P^.INFO:4);
                     INSERTAR_PILA(PILA,P);
                     P:=P^.IZQ;
                  END;
         END;
END;

PROCEDURE ELIMINAR(C:TIPOINFO; VAR P:NODO);
VAR
  AUX:NODO;

  PROCEDURE BORRAR(VAR P1:NODO);
  BEGIN
     IF P1^.DER<>NIL THEN
        BORRAR(P1^.DER)
     ELSE
     BEGIN
        AUX^.INFO:=P1^.INFO;
        AUX:=P1;
        P1:=P1^.IZQ;
     END;
  END;

BEGIN
   IF P=NIL THEN
      WRITELN('NO SE ENCUENTRA')
   ELSE
   IF C<P^.INFO THEN
      ELIMINAR(C,P^.IZQ)
   ELSE
   IF C>P^.INFO THEN
      ELIMINAR(C,P^.DER)
   ELSE
   BEGIN
      AUX:=P;
      IF AUX^.DER=NIL THEN
         P:=AUX^.IZQ

      ELSE
      IF AUX^.IZQ=NIL THEN
         P:=AUX^.DER
      ELSE
      BORRAR(AUX^.IZQ);
   END;
END;

PROCEDURE INSERTAR2(K:TIPOINF; VAR M:ARBOL);
VAR
  R:ARBOL;
  Q:ARBOL;
  I:INTEGER;

BEGIN
   WRITE('DE NUMERO A INSERTAR... ');
   READLN(K);
   NEW(M);
   M^.INF:=K;
   M^.IZ:=NIL;
   M^.DR:=NIL;
   WRITELN('DE NUMERO A INSERTAR');
   READLN(K);
   FOR I:=1 TO MAXIMO DO
       R:=M;
       Q:=M;
       WHILE (Q<>NIL) AND (R^.INF<>K) DO
             BEGIN
                R:=Q;
                IF (K<R^.INF) THEN
                   Q:=Q^.IZ
                ELSE
                   Q:=Q^.DR;

             END;
       IF (R^.INF=K) THEN
          WRITELN('NUMERO REPETIDO')
       ELSE
          IF (K<R^.INF) THEN
             INSERTAR2(K,R^.IZ)
          ELSE
             INSERTAR2(K,R^.DR);
       WRITELN('DE NUMERO A INSERTAR... ');
       READLN(K);
END;


PROCEDURE CONTAR(P:NODO; VAR X:TIPOINFO);
VAR
  I:INTEGER;
  PILA:LIFO;
BEGIN
  I:=0;
  X:=0;
  INICIAR_PILA(PILA);
  WHILE (P<>NIL) DO
        BEGIN
           INSERTAR_PILA(PILA,P);
           P:=P^.IZQ;
        END;
  WHILE (NOT PILA_VACIA(PILA)) DO
        BEGIN
           RETIRAR_PILA(PILA,P);
           IF (P^.IZQ<>NIL) AND (P^.DER<>NIL) THEN
              I:=I+1;
           P:=P^.DER;
           WHILE (P<>NIL) DO
                 BEGIN
                    INSERTAR_PILA(PILA,P);
                    P:=P^.IZQ;
                 END;
        END;
        X:=I;
END;

PROCEDURE MENU(VAR OPCION:CHAR);
BEGIN
   OPCION:=' ';
   TEXTBACKGROUND(1);
   CLRSCR;
   GOTOXY(10,2);
   TEXTCOLOR(5);
   WRITELN(' M E N U ');
   GOTOXY(18,6);
   TEXTCOLOR(2);
   WRITELN('1. BUSCAR ELEMENTO CON PROCESO  RECURSIVO');
   GOTOXY(18,8);
   WRITELN('2. BUSCAR ELEMENTO CON PROCESO REPETITIVO');
   GOTOXY(18,10);
   WRITELN('3. LISTAR NODOS EN PREORDEN');
   GOTOXY(18,12);
   WRITELN('4. ELIMINAR UN NODO');
   GOTOXY(18,14);
   WRITELN('5. INSERTAR UN NODO');
   GOTOXY(18,16);
   WRITELN('6. CONOCER EL NUMERO DE NODOS DE UN ARBOL');
   GOTOXY(18,18);
   WRITELN('7. SALIR');
   GOTOXY(18,20);
   TEXTCOLOR(7);
   WRITE('ESCOJA SU OPCION...');
   LEER_OPCION(OPCIONES);
   TEXTBACKGROUND(0);
   TEXTCOLOR(11);
END;


PROCEDURE BUSQUEDA1(X:TIPOINFO; VAR P:NODO);
BEGIN
   LEER1(X);
   WRITELN;
   INSERTAR1(X,P);
   WRITELN;
   ELEMENTO(X);
   WRITELN;
   BUSCAR1(X,P);
END;

PROCEDURE BUSQUEDA2(X:TIPOINFO; VAR P:NODO);
BEGIN
   LEER1(X);
   WRITELN;
   INSERTAR1(X,P);
   WRITELN;
   ELEMENTO(X);
   WRITELN;
   BUSCAR2(P,X);
END;

PROCEDURE LISTAR(X:TIPOINFO; VAR P:NODO);
BEGIN
   LEER1(X);
   WRITELN;
   INSERTAR1(X,P);
   WRITELN;
   PREORDEN(P);
END;

PROCEDURE ELIMINA(X:TIPOINFO; VAR P:NODO);
BEGIN
   LEER1(X);
   WRITELN;
   INSERTAR1(X,P);
   WRITELN;
   LEER2(X);
   WRITELN;
   ELIMINAR(X,P);
END;

PROCEDURE INSERTAR_NODO(K:TIPOINF; VAR M:ARBOL);
BEGIN
   LEER3(K);
   WRITELN;
   INSERTAR2(K,M);
END;

PROCEDURE LONGITUD(P:NODO; X:TIPOINFO);
BEGIN
   LEER1(X);
   WRITELN;
   INSERTAR1(X,P);
   WRITELN;
   LISTAR(X,P);
END;

PROCEDURE PRINCIPAL;
VAR
  ESCOGER:CHAR;
  CONTINUA:BOOLEAN;
BEGIN
   CONTINUA:=TRUE;
   WHILE (CONTINUA) DO
         BEGIN
            MENU(OPCIONES);
            CASE OPCIONES OF
                 '1':BEGIN
                        CLRSCR;
                        BUSQUEDA1(ELEM,A);
                     END;
                 '2':BEGIN
                        CLRSCR;
                        BUSQUEDA2(ELEM,A);
                     END;
                 '3':BEGIN
                        CLRSCR;
                        LISTAR(ELEM,A);
                     END;
                 '4':BEGIN
                        CLRSCR;
                        ELIMINA(ELEM,A);
                     END;
                 '5':BEGIN
                        CLRSCR;
                        INSERTAR_NODO(ENT,Z);
                     END;
                 '6':BEGIN
                        CLRSCR;
                        LONGITUD(A,ELEM);
                     END;
                 '7':BEGIN
                        CLRSCR;
                        CONTINUA:=FALSE;
                     END;
            END;
         END;
END;

BEGIN
  CLRSCR;
  BUSQUEDA2(ELEM,A);
END.
END.