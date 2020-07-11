<?php
require 'Rectangle.php';

$len1 = $_REQUEST['len1'];
$wid1 = $_REQUEST['wid1'];

$len2 = $_REQUEST['len2'];
$wid2 = $_REQUEST['wid2'];

$len3 = $_REQUEST['len3'];
$wid3 = $_REQUEST['wid3'];

$op = $_POST['op'];

$rec1 = new Rectangle($len1, $wid1);
$rec2 = new Rectangle($len2, $wid2);
$rec3 = new Rectangle($len3, $wid3);

$rec = [$rec1, $rec2, $rec3];

print <<< Results
<br>Results<br>
Results;

if(in_array("area", $op)){
    $list = [$rec1->findArea(), $rec2->findArea(), $rec3->findArea()];
    $max = max($list);
    
    $key = array_search($max, $list);
    
    $recT = $rec[$key];
    
    $length = $recT->__get("length");
    $width = $recT->__get("width");
    
    print <<< Here
        Largest Area: $max length: $length width: $width<br>
    Here;
}

if(in_array("perim", $op)){
    $list = [$rec1->findPerim(), $rec2->findPerim(), $rec3->findPerim()];
    $max = max($list);
    
    $key = array_search($max, $list);
    
    $recT = $rec[$key];
    
    $length = $recT->__get("length");
    $width = $recT->__get("width");
    
    print <<< Here
        Largest Peri: $max length: $length width: $width<br>
    Here;
}

if(in_array("diag", $op)){
    $list = [$rec1->findDiag(), $rec2->findDiag(), $rec3->findDiag()];
    $max = max($list);
    
    $key = array_search($max, $list);
    
    $recT = $rec[$key];
    
    $length = $recT->__get("length");
    $width = $recT->__get("width");
    
    print <<< Here
        Largest Diag: $max length: $length width: $width<br>
    Here;
}

?>