#!/Python37/python
import cgi

def login():
    print('''
    <form action=password.py>
    Please Enter Login ID: <input type='text' name='login' placeholder='Login' required/> <br/>
    <input type='submit' value='submit' name='Submit' />
    </form>
    ''')

def password():
    print('''
    <form action=input.py>
    Please Enter Password: <input type='text' name='password' placeholder='Password' required/> <br/>
    <input type='submit' value='submit' name='Submit' />
    </form>
    ''')

def infoFormLogin():
    f = cgi.FieldStorage()
    login = f.getvalue('login', default='')
    return login

def infoFormPass():
    f = cgi.FieldStorage()
    password = f.getvalue('password', default='')
    return password

def infoForm() :
    print('''
        <form action=info.py>
        First Name: <input type='text' name='fname' /> <br/>
        Last Name: <input type='text' name='lname' /> <br/>
        Email: <input type='text' name='email' /> <br/>
        Phone: <input type='text' name='phone' /> <br/>
        <input type='submit' name='submit value='Submit' />
        </form>
    ''')

def infoFormInput() :
    f = cgi.FieldStorage()
    fname = f.getvalue('fname', default='')
    lname = f.getvalue('lname', default='')
    email = f.getvalue('email', default='')
    phone = f.getvalue('phone', default='')
    return fname, lname, email, phone

def InvalidInput():
    print('''
        Invalid Input!!! Try Again.
    ''')
