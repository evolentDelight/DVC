#!/Python27/python

import cgi
import requests

print("Content-type: text/txt\n\n")

#city and ID ordered by index number
cityList = ["San Francisco", "Los Angeles", "Hong Kong", "Seoul", "Tokyo", "London", "New York"]
cityID = [2487956, 2442047, 2165352, 1132599, 1118370, 44418, 2459115]

f = cgi.FieldStorage()
city = f.getvalue('city')

send = " "

if city in cityList:
    index = cityList.index(city)

    r = requests.get("https://www.metaweather.com/api/location/" + str(cityID[index]))

    send += r.text
else:
    temp = requests.get("https://www.metaweather.com/api/location/search/?query=" + city)
    jsonResponse = temp.json()

    if len(jsonResponse) == 1:
        ID = jsonResponse[0][u'woeid']

        r = requests.get("https://www.metaweather.com/api/location/" + str(ID))

        send += r.text

print(send)
