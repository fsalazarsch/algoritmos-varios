<?php
	include ("../data.php");
	include ("../config.inc.php");
	$result = mysql_query('SET CHARACTER SET utf8');
	
	if($conect){
	$result = mysql_query("SELECT * FROM postit", $conect);
	$rs = mysql_query("SELECT MAX(id) AS max FROM POSTIT");
	$max=mysql_fetch_array($rs);
	$id = $max['max']+1;
	
		$str = "Insert into postit values (".$id.", '".$_POST['cont']."', ".$_POST['color'].", 400, 320)";
		mysql_query($str);
	}
?>

<html><head><title>Redireccionando...</title>
<meta http-equiv="Refresh" content="0;url=./sugs.php">
</head><body></body>
</html>