#! /Python36/Python

import datetime

print("Content-type: 'text/html' \n\n")

print("<html>")
print("<head>")
print("</head>")
print("<body>")

print("Today's Date and time:<br/>")

datetime_object = datetime.datetime.now()
print(datetime_object)

print("</body>")
print("</html>")