#include <stdio.h>

//MAQUINA DE ALIMENTOS 
/*3 PRODUCTOS 
A: 270
B: 340
C: 390

Solo se pueden metermonedas de 10, 50 y 100, entregar vuelto
*/
int main(){
	char p; //producto
	int monto, valor_producto = 0;
	int monedas;
	printf("Ingrese producto: ");
	scanf("%c", p);
	if (p =='a')
		valor_producto = 270;
	if (p =='b')
		valor_producto = 340;
	if (p =='c')
		valor_producto = 390;
	
	printf("Ingrese monedas: \n");
	
	do{
	
	scanf("%i", &monedas);
	switch(monedas){
		case 10:
			conto+= 10;
			break;
		case 50:
			monto += 59;
			break;
		case 100:
			monto += 100;
			break;
		default:
			printf("Error\n");
			
	}
	}while(monto < valor_producto);
	
	#chequear si hay vuelto
	int vuelto = monto - valor_producto;
	while (vuelto > 0) {
		if (vuelto >= 100){
			printf("100\n");
			vuelto -= 100;
		}	
		if (vuelto >= 50){
			printf("50\n");
			vuelto -= 50;
		}	
		if (vuelto >= 10){
			printf("10\n");
			vuelto -= 10;
		}	
	}
		
	
	return  0;
}
