#!/python27/python


print("Content_type: 'text/html' \n\n")
print (''' 

<html>

<head>

<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>

</head>

<body>

<script type="text/javascript">

function validateFname (){
            //alert("validateFname");//Debugging technique

            var fname,span;
            var retValue=true;

            var input=document.getElementsByTagName("input");
            var fname=input[0].value;
            //Create a span element only if a span with id "idSpanFname" does not exist
            //(i.e. it had not already been created during a previous call to this function)
            var span=document.getElementById("idSpanFname");

            if (span==null){
                        var br=document.getElementsByTagName("br");
                        var brFname=br[0];
                        span=document.createElement("span");
                        var parentBrFname = brFname.parentNode;
                        parentBrFname.insertBefore(span, brFname);
                        span.style.color="red";
                        span.id = "idSpanFname";
            }
            span.innerHTML = "";
            
            //alert("fname" + fname);
            
            if (fname==null || fname=="")
            {                     
                        span.innerHTML = "Required field. Enter value.";
                        retValue = false;
            }
            else if (!fname.match(/^[A-Za-z]+$/)){ 
                        span.innerHTML = "Letters only field. Re-enter value.";
                        retValue = false;           
            }
            return retValue;
}

function validateLname (){
            //alert("validateLname");

            var retValue=true;

            var input=document.getElementsByTagName("input");
            var lname=input[1].value;

            var span=document.getElementById("idSpanLname");

            if (span==null){
                        var br=document.getElementsByTagName("br");
                        var brLname=br[1];
                        span=document.createElement("span");
                        var parentBrLname = brLname.parentNode;
                        parentBrLname.insertBefore(span, brLname);
                        span.style.color="red";
                        span.id = "idSpanLname";
            }

            span.innerHTML = "";
            
            //alert("lname" + lname);
            
            if (lname==null || lname=="")
            {                     
                        span.innerHTML = "Required field. Enter value.";
                        retValue = false;
            }
            else if (!lname.match(/^[A-Za-z]+$/)){ 
                        span.innerHTML = "Letters only field. Re-enter value.";
                        retValue = false;           
            }
            return retValue;
}

function validatePhone (){
            //alert("validatePhone");

            var retValue=true;
            
            var input=document.getElementsByTagName("input");
            var phone1=input[2].value;
            var phone2=input[3].value;
            var phone3=input[4].value;

            var span=document.getElementById("idSpanPhone");

            if (span==null){
                        var br=document.getElementsByTagName("br");
                        var brPhone=br[2];
                        span=document.createElement("span");
                        var parentBrPhone = brPhone.parentNode;
                        parentBrPhone.insertBefore(span, brPhone);
                        span.style.color="red";
                        span.id = "idSpanPhone";
            }

            span.innerHTML = "";
            
            //alert('phoneArea: ' + phone1 + ' phonePrefix: ' + phone2 + ' phoneFour: ' + phone3);
            if ((phone1==null || phone1=="") || (phone2==null || phone2=="") || (phone3==null || phone3==""))
            {                     
                        span.innerHTML = "Required field. Enter value.";
                        retValue = false;
                        return retValue;
            }
            else if ((!phone1.match(/^\d+$/)) || (!phone2.match(/^\d+$/)) || (!phone3.match(/^\d+$/))){ 
                        span.innerHTML = "Numbers only field. Re-enter value.";
                        retValue = false;           
            }
            return retValue;
}

function validateEmail(){
            //alert("validateEmail");

            var retValue=true;

            var input=document.getElementsByTagName("input");
            var email=input[5].value;

            var span=document.getElementById("idSpanEmail");

            if (span==null){
                        var br=document.getElementsByTagName("br");
                        var brEmail=br[3];
                        span=document.createElement("span");
                        var parentBrEmail = brEmail.parentNode;
                        parentBrEmail.insertBefore(span, brEmail);
                        span.style.color="red";
                        span.id = "idSpanEmail";
            }

            span.innerHTML = "";
            
            
            //alert("email: " + email);
            if (email==null || email=="")
            {                     
                        span.innerHTML = "Required field. Enter value.";
                        retValue = false;
            }
            else if (!email.match(/\S+@\S+\.\S+/)){ 
                        span.innerHTML = "Must be in email@domain.com format. Re-enter value.";
                        retValue = false;           
            }
            return retValue;
}

function validate (){
            var ret1=true, ret2=true, ret3=true, ret4=true;
            ret1=validateFname ();
            ret2=validateLname ();
            ret3=validatePhone ();
            ret4=validateEmail ();
            return (ret1&&ret2&&ret3&&ret4);
}
</script>

<form name="frmInfo" onsubmit="return validate()" action="Response.py"  method="post">
      
First Name
<span style="color:red">*</span>
<input type="text" name="fname" cols="10"
       onchange="validateFname()">
<br />

Last Name
<span style="color:red">*</span>
<input type="text" name="lname" cols="10"
        onchange = "validateLname()">
<br/>

Phone Number
<span style="color:red">*</span>
<input type="text" name="phoneArea" maxlength="3" size="3" placeholder="Area"
        onchange = "validatePhone()">
<input type="text" name="phonePrefix" maxlength="3" size="3" placeholder="Prefix"
        onchange = "validatePhone()">
<input type="text" name="phoneFour" maxlength="4" size="4" placeholder="Last Four"
        onchange = "validatePhone()">
<br/>

Email
<span style="color:red">*</span>
<input type="text" name="email" cols="10"
        onchange = "validateEmail()">
<br/>

<input type="submit" name="submit" value="Submit">

</form>

</body>

</html>
''')