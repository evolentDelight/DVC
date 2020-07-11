#!/Python27/python

import cgi

print("Content_type: text/html\n\n")
print('''

<html>

<head>

<script>

// create XMLHttpRequest object as a global variable
var myReq = new XMLHttpRequest();

// The function below is invoked on pressing any key and releasing it
// in text field.
// It communicates with object XMLHttpRequest to perform ajax
// It sets up in the object the callback method to be called and the
// url of the script to be invoked and query string to be passed to it.
// The query string contains partially typed symbol and a random number.
// The random number is used to make the url unique and avoid
// getting the cached response.
function searchStock(value,event) {
            //alert ("searchStock");
            myReq.onreadystatechange = searchStockCallback;

            var       thePage = "SearchStock.py";
            var       theURL = thePage +"?symbol=" + value;

            myRand = parseInt(Math.random()*999999999999999);

            theURL = theURL +"&rand="+myRand;

            myReq.open("GET", theURL, true);
            //alert ("searchStock2");
            myReq.send(null);
            //alert ("searchStock3");
}


// The following callback function is called by object XMLHttpRequest
// whenever its ready state changes. When ready state is 4
// (i.e. request is completed) and HTTP status is 200 (i.e. OK),
// it copies the script response in the span.
function searchStockCallback() {
            //alert ("searchStockCallback "+myReq.readyState);
            //alert ("searchStockCallback "+myReq.status);
            if (myReq.readyState == 4 && myReq.status == 200) {
                        //alert ("searchStockCallback");
                        document.getElementById("idStockGuess").innerHTML =
                                    myReq.responseText;
            }
}


//The following function is invoked on clicking the span.
//It copies the content of the span (i.e. script response) to text field.
function setStock(stock){
            document.getElementById("idStock").value = stock;
}

</script>

</head>

<body>

Enter a part of a stock symbol.<br>
You will see the complete matching symbols below it.<br>
<br>

Symbol: <input type="text" id="idStock" 
             onkeyup="searchStock(this.value,event);" /><br>
Match :  <span id="idStockGuess"
            onclick="setStock(this.innerHTML);"></span><br>

</body>

</html>
''')