#!/python27/python

import cgi;


f = cgi.FieldStorage()
fname = f.getvalue('fname')
lname = f.getvalue('lname')
phone1 = f.getvalue('phoneArea')
phone2 = f.getvalue('phonePrefix')
phone3 = f.getvalue('phoneFour')
email = f.getvalue('email')


print("Content_type: 'text/html' \n\n")

print('''
<br>
First Name: {} <br>
Last Name: {} <br>
Phone Number: {}-{}-{} <br>
Email: {} <br>
'''.format(fname, lname, phone1, phone2, phone3, email))