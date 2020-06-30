<title>Brainstorm</title>
<meta charset="utf-8">
   <link href="../jquery-ui-ajax-googleapis.css" rel="stylesheet" type="text/css"/>

 <script src="../jquery-1.6.4.js"></script>
<script src="../jquery-ui.min.js"></script>	

<script type="text/javascript" src="../jquery.fancybox-1.3.4.pack.js"></script>
<script type="text/javascript" src="../jquery.mousewheel-3.0.4.pack.js"></script>
<link rel="stylesheet" href="../jquery.fancybox-1.3.4.css" type="text/css" media="screen" />	
	<style>
    .draggable2 {
	width: 130px;
	height: 130px;
	padding-top: 10;
	padding-left: 15;
	padding-bottom: 5;
	padding-right: 10;
	float: left;
	margin: 10px 0px 10px 10px;
	position:absolute;
	background-repeat:no-repeat;
	background-size: 140 140;
	font-family:Tahoma;
}
	#swimline {
	width: 75%;
	height: 150px;
	padding: 0.5em;
	float: left;
	margin: 0px;
	background-color: #C4F3FF;
	font-family:Tahoma;
	border-top-width: 1px;
	border-right-width: 1px;
	border-bottom-width: 1px;
	border-left-width: 1px;
	border-top-style: solid;
	border-right-style: solid;
	border-bottom-style: solid;
	border-left-style: solid;
}
	</style>
	<script>
	
	$(document).ready(function() 
	{
	$(".insr").fancybox();
	$(".mod").fancybox();
	$("a.group").fancybox({
	        'transitionIn'  :   'elastic',
	        'transitionOut' :   'elastic',
	        'speedIn'   :   300,
	        'speedOut'  :   200,
	        'overlayShow'   :   false
	        });
	});
	
	$(function() {
		$( ".draggable2" ).draggable({
			stop:function(){
				var p = $(this).position();
				var title = $(this).attr("title");
				$.ajax({
  				type: "POST",
  				url: "modif_post_it.php",
  				data: "id="+title+"&psx="+p.left+"&psy="+p.top
				});
				}});
		
		$( ".draggable2" ).dblclick();
});
	</script>

	<table width="100%">
  <tr >
<td width="70%"><font face="Tahoma" size="-1">
  <input type="button" value="Agregar Post-It" onclick='$(".insr").trigger("click");'/>
</font>
 </td>
</tr>
</table>
	<div id="swimline">
	  <p>Algoritmos/Programas<br />
      </p>
    </div><div id="swimline">
      <p>Secciones/Otros<br />
      </p>
    </div>
	</div><br><br><br><br><br><br><br><br><br><br>
<?php
	include ("../data.php");
	include ("../config.inc.php");
	
	$result = mysql_query('SET CHARACTER SET utf8');
	
	if($conect)
	{
	$result = mysql_query('Select * from postit'); 
	if(!$result)
		die('No se pudo ver:' . mysql_error());
	
	while($row=mysql_fetch_array($result))
	{
		echo "<div class='draggable2' style='background-image: url(../images/postit".$row['color'].".png); position:absolute; left:".$row['posicionx']."px; top:".$row['posiciony']."px;'     onmouseover=\"this.title='".$row['id']."'\"";
echo "><div style='width:100px;'>".$row['contenido']."</div></div>";
	}
	mysql_close($conect);
	}
	
?>
<div class="insr" href="form_insert.html"></div>
<div style="display:none" class="mod" href="modif.php">
<form method="POST" action="../modif_post_it.php">
<input type="text" name="cont" maxlength="50" size="50"><br>
<input type="submit" value="Modificar">
</form>
</div>

</div>