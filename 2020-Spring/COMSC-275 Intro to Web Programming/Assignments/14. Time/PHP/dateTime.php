 <?php

date_default_timezone_set('US/Pacific');

$dateTime=date('l F j, Y H:i:s a e');

header('Content-type: text/xml');

print "<?xml version=\"1.0\" ?>";

print "Curren Date and Time: <dateTime>$dateTime</dateTime>";

?>