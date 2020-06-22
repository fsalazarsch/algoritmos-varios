package main

import(
	"fmt"
)

func parsear( letra string, pos int)(x string){
	alfabeto := "abdefghijklmnñopqrstuvxxyz"
	var i int;
	for i=0; i< len(alfabeto); i++{
		if alfabeto[i:i+1] == letra{
			
			break
		}
	}
	i = (i +pos)%27
	x = alfabeto[i:i+1]
	return x
}

func main(){
	var cadena string 
	var posicion, i int

	fmt.Println("Cadena a cifrar:")
	fmt.Scanf("%s\n", &cadena)
	
	fmt.Println("Posicion:")
	fmt.Scanf("%d\n", &posicion)


     for i =0; i< len(cadena); i ++{
     	x := cadena[i:i+1]
     
     	fmt.Print(parsear( x, posicion ))
  	
     }

}
