#include "stdio.h"
#include "conio.h"
#include "varios.h"
#include "string.h"

#define T 2

// Captura datos en una factura y la visualiza. factu.cpp
// realizado por: Jenis Sagbini

struct factura
{
 char empresa[20];
 char num[3];
 char fec[8];
 int cant;
 char concepto[30];
 int vrunit;
 int subtot;
 int vrtotal;
 int iva;
 int total;
}fact[T];

int i;

main()
 {
  clrscr();
  pos(2,55);printf("** CAPTURA **");

  for (i=0;i<T;i++)
  {
  pos(4,5);printf(" Nombre Empresa ...:");
  pos(6,5);printf(" Fecha (DDMMAA) ...:");
  pos(8,5);printf(" Número  ...:");
  pos(12,5);printf(" Cantidad..:");
  pos(10,5);printf(" Concepto..:");
  pos(14,5);printf(" Valor Unitario..:");
  pos(16,5);printf(" Subtotal..:");
  pos(18,5);printf(" I.V.A...:");
  pos(20,5);printf(" Total ..:");
  pos(4,30);gets(fact[i].empresa);
  pos(6,30);gets(fact[i].fec);
  pos(8,30);gets(fact[i].num);
  pos(10,30);gets(fact[i].concepto);
  pos(12,30);scanf("%d",& fact[i].cant);
  pos(14,30);scanf("%d",& fact[i].vrunit);
  pos(16,30);scanf("%d",& fact[i].subtot);
  pos(18,30);scanf("%d",& fact[i].iva);
  pos(20,30);scanf("%d",& fact[i].total);
  getchar();
 }
 clrscr();
 

 // Visualiza factura por factura. Nota;falta implementarlo!
 clrscr();
 pos(2,55);printf("** CONSULTA **");

 for (i=0;i<T;i++)
 {
  pos(4,5);printf(" Nombre Empresa ...:");
  pos(6,5);printf(" Fecha (DDMMAA) ...:");
  pos(8,5);printf(" Número  ...:");
  pos(12,5);printf(" Cantidad..:");
  pos(10,5);printf(" Concepto..:");
  pos(14,5);printf(" Valor Unitario..:");
  pos(16,5);printf(" Subtotal..:");
  pos(18,5);printf(" I.V.A...:");
  pos(20,5);printf(" Total ..:");
  pos(4,30);puts(fact[i].empresa);
  pos(6,30);puts(fact[i].fec);
  pos(8,30);puts(fact[i].num);
  pos(10,30);puts(fact[i].concepto);
  pos(12,30);printf("%d",& fact[i].cant);
  pos(14,30);printf("%d",& fact[i].vrunit);
  pos(16,30);printf("%d",& fact[i].subtot);
  pos(18,30);printf("%d",& fact[i].iva);
  pos(20,30);printf("%d",& fact[i].total);
 }
}    