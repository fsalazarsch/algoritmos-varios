<html>
<head><title>Resultado pedido</title></head>
<body>
<?php


$cadena=""; #va a guardar todos los pedidos
$fp = fopen("pedidos.xml","r");

	while(!feof($fp)){
	$cadena = $cadena.fread($fp,filesize("pedidos.xml"));
	#echo $cadena;	
	}
	fclose($fp);
	echo $cadena;	
	$xpc = xml_parser_create();
	xml_parse_into_struct($xpc, $cadena, $datos, $indice);
	xml_parser_free($xpc);


	echo "<br>Vals array<br>";
	$prods = array_slice(($datos),2);
	
	$aregl[] = print_r($prods);
	echo $arregl[3]["value"];

/*
	list($nom,$cantid,$prec,$stock) = split(" ",$cadena);
	echo "Nombre:".$nom."<br>";
	echo "Cantidad:".$cantid."<br>";
	echo "Precio:".$prec."<br>";
	echo "Stock:".$stock."<br>";
	*/
	

	
?>
