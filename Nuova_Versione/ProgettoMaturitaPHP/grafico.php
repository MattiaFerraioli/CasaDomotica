<?php
include("phpgraphlib.php");
include("connettiDB.php");
//mysqli_select_DB("domotica");

$graph = new PHPGraphLib(1000,800);
//$data="2016-05-07";
$query = "SELECT count(*) as conta,data 
			FROM sessione 
			where 1 
			group by id";
//data='2016-05-07' 
$res=mysqli_query($connessione,$query) or die("errore query");

while($result_row = mysqli_fetch_array($res))
{
	$data[$result_row['data']] =  $result_row['conta'] ;
}


$graph->addData($data);

$graph->setTitle("Sessioni");
$graph->setTextColor("red");
$graph->createGraph();
?>