#!/python37/python

import cgi
import headTail
import forms

headTail.headHtml()

fname, lname, email, phone = forms.infoFormInput()

out = '''
First name: {} <br/>
Last name: {} <br/>
Email: {} <br/>
Phone: {} <br/>
'''.format(fname, lname, email, phone)
print(out)

headTail.tailHtml()