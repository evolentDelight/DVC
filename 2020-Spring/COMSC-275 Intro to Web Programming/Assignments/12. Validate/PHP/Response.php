<?php

$fname = $_REQUEST['fname'];
$lname = $_REQUEST['lname'];
$phone1 = $_REQUEST['phoneArea'];
$phone2 = $_REQUEST['phonePrefix'];
$phone3 = $_REQUEST['phoneFour'];
$email = $_REQUEST['email'];

print(
"
First Name: $fname<br>
Last Name: $lname<br>
Phone Number: $phone1-$phone2-$phone3<br>
Email: $email
");


?>