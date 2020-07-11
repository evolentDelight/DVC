<?php

$symbol=$_GET['symbol'];

$format=$_GET['format'];

//reurns output in JSON format

if ($format=='json') {
    
    $s = file_get_contents(
        
        "https://query1.finance.yahoo.com/v7/finance/quote?symbols="
        
        . $symbol
                
        );
    
}

else{
    
    $s = "";
    
}

print $s;

?>