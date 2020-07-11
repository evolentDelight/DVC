<?php
class StatCalc {
    
    private $data;
    
    private $sdata;
    
    public function __construct ($d){
        
        
        
        $this->data = $d;
        
        $this->sdata = $this->data;
        
        sort ($this->sdata);
        
    }
    
    public function findMin(){
        
        return $this->sdata[0];
        
    }
    
    public function findMax (){
        
        return $this->sdata[count($this->sdata)-1];
        
    }
    
    public function findMean (){
        
        $sum = array_sum($this->sdata);
        
        $mean = $sum / count ($this->sdata);
        
        return $mean;
        
    }
    
    public function findMedian (){
        
        //Determine if the length is odd or even.
        
        if ( (count($this->sdata) % 2) != 0 ){
            
            $index = count ($this->sdata) / 2;
            
            $median = $this->sdata [$index];
            
        }
        
        else{
            
            $indexHi = count ($this->sdata) / 2;           
            $indexLo = $indexHi - 1;
            
            $median = ($this->sdata[$indexLo] +
                
                $this->sdata [$indexHi]) / 2;
                
        }
        
        return $median;        
    }
    
    public function getOrigData(){
        
        return $this->data;        
    }
    
    public function getSdataData(){
        
        return $this->sdata; 
    }
    
}

?>