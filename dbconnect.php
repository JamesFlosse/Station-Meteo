<?php

$Username = "arduino";  // enter your username for mysql

$Password = "password";  // enter your password for mysql

$Hostname = "localhost";      // this is usually "localhost" unless your database resides on a different server


$dbh = mysql_connect($Hostname , $Username, $Password);

$selected = mysql_select_db("energie",$dbh);


?>
