<?php
include('phpgraphlib.php');
include('phpgraphlib_pie.php');
include("connettiDB.php");

$graph = new PHPGraphLibPie(400, 200);
//$graph = new PHPGraphLib(650,200);
$query = "SELECT count(*) as conta 
			FROM azione join dispositivo on azione.iddispositivo = dispositivo.id 
			where 1
			group by azione.iddispositivo";

$res=mysqli_query($connessione,$query) or die("errore query");

while($result_row = mysqli_fetch_array($res))
{
	$data[$result_row['conta']];
}


$graph->addData($data);
$graph->setTitle('Utilizzo Sensori');
$graph->setLabelTextColor('50,50,50');
$graph->setLegendTextColor('50,50,50');
$graph->createGraph();
?>