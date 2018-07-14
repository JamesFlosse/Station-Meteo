<?php
    // Connect to MySQL
    include("dbconnect.php");

    // Prepare the SQL statement
    $query =  "INSERT INTO energie.kWh_meter (pulseTime, mWh, Watt) 
	VALUES ('$_POST[pulseTime]', '$_POST[mWh]', '$_POST[curWatts]')";    

    // Go to the review_data.php (optional)
    header("Location: review_data.php");
	
	if(!@mysql_query($query))
	{
		echo "&Answer; SQL Error - ".mysql_error();
		return;
	
	mysql_close();
	}
?>
