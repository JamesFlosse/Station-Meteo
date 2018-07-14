<?php
    // Start MySQL Connection
    include('dbconnect.php');
//


$selected = mysql_select_db($Database, $dbh);
?>

<html>
<head>
    <title>Arduino kWh log ruwe data</title>
    <style type="text/css">
        .table_titles, .table_cells_odd, .table_cells_even {
                padding-right: 20px;
                padding-left: 20px;
                color: #000;
        }
        .table_titles {
            color: #FFF;
            background-color: #666;
        }
        .table_cells_odd {
            background-color: #CCC;
        }
        .table_cells_even {
            background-color: #FAFAFA;
        }
        table {
            border: 2px solid #333;
        }
        body { font-family: "Trebuchet MS", Arial; }
    </style>
</head>

    <body>
        <h1>Arduino kWh log ruwe data</h1>
    <table border="0" cellspacing="0" cellpadding="4">
      <tr>
            <td class="table_titles">ID</td>
            <td class="table_titles">Date and Time</td>
            <td class="table_titles">pulseTime</td>
            <td class="table_titles">mili-Wh</td>
            <td class="table_titles">Watt</td>
          </tr>
<?php
    // Retrieve all records and display them
    $result = mysql_query("SELECT * FROM kWh_meter ORDER BY id ASC");

    // Used for row color toggle
    $oddrow = true;

    // process every record
    while( $row = mysql_fetch_array($result) )
    {
        if ($oddrow)
        {
            $css_class=' class="table_cells_odd"';
        }
        else
        {
            $css_class=' class="table_cells_even"';
        }

        $oddrow = !$oddrow;

        echo '<tr>';
        echo '   <td'.$css_class.'>'.$row["id"].'</td>';
        echo '   <td'.$css_class.'>'.$row["Date-Time"].'</td>';
        echo '   <td'.$css_class.'>'.$row["pulseTime"].'</td>';
        echo '   <td'.$css_class.'>'.$row["mWh"].'</td>';
		echo '   <td'.$css_class.'>'.$row["Watt"].'</td>';
        echo '</tr>';
    }
?>
    </table>
    </body>
</html>
