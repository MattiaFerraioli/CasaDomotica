<?php

	$connessione=mysqli_connect("localhost","root","");
	//stabilisco una connessione con il server (nome server,utente,psw)
	if(!$connessione)
	{
		print("<h1>Connessione al server Mysql fallita </h1>");
		exit;
	}

	$db = mysqli_select_db($connessione, "domotica");

	if(!$db)
	{
		print("<h1>Connessione al database fallita </h1>");
		exit;
	}

?>