#!/python37/python

print("Content_type: 'text/html' \n\n")

print('''
      <html>
      <head>
      </head>
      <body>
''')
print('''

<form action="info.py">

First Name: <input type="text" name="fname"/><br/>
Last Name:  <input type="text" name="lname"/><br/>
Email: <input type="text" name="email"/><br/>
Phone: <input type="text" name="phone"/><br/>

<input type=submit name="submit" value="Submit" /><br/><br/>

</form>

''')
print('''
       </body>
       </html>
''')


