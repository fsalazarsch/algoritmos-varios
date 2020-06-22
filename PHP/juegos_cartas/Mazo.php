<?php
class Mazo{
  $pinta = ["♥", "♦", "♠", "♣"]
  $valor = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]; 

function crear_mazo(){
	$mazo = [];
	foreach($pintas as $p){
		foreach($valor as $v){
		$c = new Carta($v, $p);
		array_push($mazo, $c);	
		}	
	}
return $mazo;
}

function barajar($mazo){
	shuffle($mazo);
	return $mazo;
}

function sacar_carta($mazo){ //saca un numero de cartas
	$carta = array_rand($mazo, 1);
	return $mazo[$carta[0]];
}

}
