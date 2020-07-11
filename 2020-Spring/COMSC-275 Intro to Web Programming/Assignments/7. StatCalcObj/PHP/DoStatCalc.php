<form action='DoStatCalc.php' method='post'>

Data <input type='text' name='data' /><br>

Values Separator<input type="text" name='separator'><br><br><br>

Operations<br><br>

<input type='checkbox' name='op[]' value='min' checked />Min 
<input type='checkbox' name='op[]' value='max' checked />Max
<input type='checkbox' name='op[]' value='mean' checked />Mean
<input type='checkbox' name='op[]' value='median' checked />Median<br><br>

                        
<input type='submit' name='submit' value='Submit' /><br><br>

</form>

<?php
require "StatCalc.php";


//if it is the first invocation of the script, exit the script.

if (!isset($_REQUEST['submit']))
    
    exit();

    //It is not the first invocation of the script. So process input.
    
    //Validate input.
    
    $str = $_REQUEST ['data'];
    
    $separator = $_REQUEST ['separator'];
    
    $op = $_REQUEST ['op'];
    
    
    
    if (empty($str) || empty($separator)){
        
        print "Enter Data and Values Separator";
        
        exit (0);
        
    }
    
    if (empty($op)){
        
        print ("Check one or more operations");
        
        exit(0);
        
    }
    

    //Input validated.
    
    //Convert data to an array
    
    $ar = explode($separator, $str);
    
    
    //create a statCalc object
    
    $statCalc = new StatCalc ($ar);
    
   
    //Utilize the above object to do the rest of the assignment
    
    print('<br>Original Data:<br>');
    
    $list = $statCalc->getOrigData();
    
    foreach($list as $value){
        echo $value . " ";
    }
    print('<br><br>');
    
    print('Sorted Data:<br>');
    
    $listS = $statCalc->getSdataData();
    
    foreach($listS as $value){
        echo $value . " ";
    }
    print('<br><br>');
    
    if(in_array("min", $op)){
        print('Min: ');
        print($statCalc->findMin());
        print('<br>');
    }
    if(in_array("max", $op)){
        print('Max: ');
        print($statCalc->findMax());
        print('<br>');
    }
    if(in_array("mean", $op)){
        print('Mean: ');
        print($statCalc->findMean());
        print('<br>');
    }
    if(in_array("median", $op)){
        print('Median: ');
        print($statCalc->findMedian());
    }

?>