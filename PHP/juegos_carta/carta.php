<?php
class Carta{
	var $valor;
	var $pinta;

	function __construct($valor, $pinta){
	$this->valor = $valor;  //2,3,4,5 ... J, Q, K, A
	$this->pinta = $pinta; //C, D, P, T
	}
	
	function devolver_carta(){
	return $this->valor.$this->pinta;	
	}
}
?>
