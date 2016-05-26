<?php
include('phpgraphlib.php');
include("connettiDB.php");

$graph = new PHPGraphLib(650,200);
$query = "SELECT Valore,data FROM azione where 1";

$res=mysqli_query($connessione,$query) or die("errore query");


while($result_row = mysqli_fetch_array($res))
{
	$data[$result_row['data']] =  $result_row['Valore'] ;
}

$graph->addData($data);
$graph->addData($data);
$graph->setTitle('Valori Temperatura');
$graph->setBars(false);
$graph->setLine(true);
$graph->setDataPoints(true);
$graph->setDataPointColor('green');
$graph->setDataValues(true);
$graph->setDataValueColor('red');
$graph->setGoalLine(.0025);
//$graph->setGoalLineColor('red');
$graph->createGraph();

?>