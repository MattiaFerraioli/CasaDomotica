<html>
  <head></head>
  <body>
    <?php
		include "connettiDB.php";
        //leggo user e password della login
		$username=$_POST['usernameL'];
		$password = MD5($_POST['passwordL']);
		
		$query =" SELECT * FROM utenti WHERE Username = \"".$username."\" AND Password =\"".$password."\"";
	
		$risultato = mysqli_query($connessione,$query);
		
		$rigHe = mysqli_fetch_row($risultato);
		
		$destinazione="";
		
		if(mysqli_num_rows($risultato) == 0){
			$destinazione = "Location: Login.php";
					
			}
		else{
			$queryInsert = " INSERT INTO sessione
						(Data,Ora,IDUtente) values (\"".date("Y-m-j", time())."\",\"".date("H:i", time())."\",\"".
						$_SESSION['IDUtente']."\"";
			//echo $queryInsert;
			$aggiungi = mysqli_query($connessione,$queryInsert);
			
		}
		echo $destinazione;
		header($destinazione);
	  ?>
  </body>
</html>