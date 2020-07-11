#!/python37/python

import cgi
f = cgi.FieldStorage()
fname=f.getvalue("fname")
lname=f.getvalue("lname")
email=f.getvalue("email")
phone=f.getvalue("phone")

print("Content_type: 'text/html' \n\n")

print('''
      <html>
      <head>
      </head>
      <body>
''')

print("<br/>---Print using individual prints---<br/>")
print("First Name: ")
print(fname)
print("<br/>")
print("Last Name: ")
print(lname)
print("<br/>")
print("Email: ")
print(email)
print("<br/>")
print("Phone: ")
print(phone)
print("<br/>")

print("<br/>---Print using string concatenation---<br/>")
out = "First name: " + fname + "<br/>"
out += "Last name: " + lname + "<br/>"
out += "Email: " + email + "<br/>"
out += "Phone: " + phone + "<br/>"
print(out)

print("<br/>---Print using multiple line string with format method----<br/>")
out = '''
First name: {} <br/>
Last name: {} <br/>
Email: {} <br/>
Phone: {} <br/>
'''.format(fname, lname, email, phone)
print(out)

print('''
       </body>
       </html>
''')