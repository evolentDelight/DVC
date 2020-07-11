<?php
class Rectangle {
    
    private $length;   
    private $width;
 
    public function __construct ($length, $width) {
        $this->length=$length;
        $this->width=$width;   
    }
    public function __get ($name) {
        switch ($name) {
            case "length":
                return $this->length;
                break;
            case "width":
                return $this->width;
                break;       
        }    
    }
    
    public function findArea(){
        $area = $this->length * $this->width;
        
        return $area;
    }
    
    public function findPerim(){
        $perim = 2 * ($this->length) + 2 * ($this->width);
        
        return $perim;
    }
    
    public function findDiag(){
        $power = pow($this->length, 2) + pow($this->width, 2);
        
        $diag = sqrt($power);
        
        return $diag;
    }

    //If need be, function __set ($name,$value) method can be written similarly
    //In this assignment, we don’t need this method
}

?>