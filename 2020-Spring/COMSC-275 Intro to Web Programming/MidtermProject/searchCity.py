#!/Python27/Python

import cgi
import requests

print("Content_type: text/xml\n\n")

f = cgi.FieldStorage()

city = f.getvalue("city")

matches = "<br>"

temp = requests.get("https://www.metaweather.com/api/location/search/?query=" + city)
jsonResponse = temp.json()

for value in jsonResponse:
    matches += value[u'title'] + "<br>"

print(matches)