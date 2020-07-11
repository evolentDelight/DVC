<?php

// Fill the array with stock symbols
$list[]="aapl";
$list[]="msft";
$list[]="goog";
$list[]="ibm";
$list[]="wfm";
$list[]="sfm";
$list[]="tfm";
$list[]="bac";
$list[]="wfc";
$list[]="hpq";
$list[]="orcl";
$list[]="intc";
$list[]="angi";
$list[]="bbry";
$list[]="fb";
$list[]="hd";
$list[]="m";

 

//get the partial symbol if provided
if (isset ($_REQUEST["symbol"])){
            $symbol=$_REQUEST["symbol"];
}
else {
            $response="no match";
            exit;
}

$matches="";

//check for all matches in the list array with user supplied symbol 
if (strlen($symbol) > 0){
            for($i=0; $i<count($list); $i++){
                        if (strtolower($symbol)
                        == strtolower(substr($list[$i],0,strlen($symbol)))){
                                    if ($matches==""){
                                                $matches=$list[$i];
                                    }
                                    else{
                                                $matches=$matches." , ".$list[$i];
                                    }
                        }
            }
}

// Set output to "no match" if no matches were found

// Otherwise set output to the matched list.

if ($matches == ""){
            $response="no match";
}

else{
            $response=$matches;
}

//output the response

print $response;

?>