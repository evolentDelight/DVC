#!/Python27/python

import cgi

import requests

f=cgi.FieldStorage()
symbol=f.getvalue('symbol')
format=f.getvalue('format')

print("Content-type: text/txt\n\n")

#returns json
if format == 'json':

    r=requests.get(
    "https://query1.finance.yahoo.com/v7/finance/quote?symbols="+symbol)

    #status_code=r.status_code
    #s=(str(status_code))
    s=r.text

else:
    s = ""

print(s)