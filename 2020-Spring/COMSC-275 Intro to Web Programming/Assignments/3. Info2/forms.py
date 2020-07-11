#! /Python36/Python

import cgi

def infoForm() :
    print('''
        <form action=info2.py>
        <input type='text' name='fname' /> <br/>
        <input type='text' name='lname' /> <br/>
        <input type='text' name='email' /> <br/>
        <input type='text' name='phone' /> <br/>
        <input type='submit' name='submit value='Submit' />
        </form
    ''')

def infoFormInput() :
    f = cgi.FieldStorage()
    fname = f.getvalue('fname', default='')
    lname = f.getvalue('lname', default='')
    email = f.getvalue('email', default='')
    phone = f.getvalue('phone', default='')
    return fname, lname, email, phone