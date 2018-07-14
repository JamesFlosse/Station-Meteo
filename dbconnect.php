<?php
$Username = "root";  // enter your username for mysql
$Password = "password";  // enter your password for mysql
$Hostname = "localhost";      // this is usually "localhost" unless your database resides on a different server
$Database = "energie"; //database name

$dbh = mysql_connect($Hostname , $Username, $Password) or die (mysql_error());;
@mysql_select_db($Database) or die (mysql_error());
?>
