<?php
	include ("../data.php");
	include ("../config.inc.php");
if(isset($_POST['psx']) || isset($_POST['psy']))
$query_modificar = "Update postit set posicionx = ".$_POST['psx'].", posiciony = ".$_POST['psy']." where id = ".$_POST['id']; 

if(isset($_POST['cont']))
$query_modificar = "Update postit set contenido = '".$_POST['cont']."' where id = ".$_POST['id']; 

mysql_query($query_modificar);

?>
<!--html><head>
<link rel="stylesheet" href="estilo.css" type="text/css">
	<meta http-equiv="Refresh" content="5;url=./sugs.php">
	</head><body><br><br><br><br><br>
	
    <center><table id="modif" class="tablaaviso"><tr>
	<td>La nota se ha modificado correctamente<br> Si no eres dirigido en 5 segundos.<br>Puedes acceder haciendo click <a class="linkerror" href="sugs.php">aquí</a><br>
</body></td></tr></table><center></html-->