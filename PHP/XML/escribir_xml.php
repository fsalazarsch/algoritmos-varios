<html>
<head><title>Resultado pedido</title></head>
<body>
<?php


$cadena=""; #va a guardar todos los pedidos
$fp = fopen("pedidos.xml","a+");
flock($fp,2);

	$cadena ="<pedido><producto>".
	"<nombre>".$nom."</nombre>".
	"<cantidad>".$cant."</cantidad>".
	"<precio>".$prec."</precio>".
	"<stock>".$stock."</stock>".
	"</pedido></producto>";
	fwrite($fp, $cadena);
	
	flock($fp, 3);
	fclose($fp);

	echo $cadena;

?>
