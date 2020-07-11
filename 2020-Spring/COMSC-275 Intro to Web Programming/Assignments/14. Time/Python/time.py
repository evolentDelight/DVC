#!/Python27/Python


from datetime import datetime

dateTime = datetime.now()

time = dateTime.time().strftime('%H:%M:%S')

print("Content-type: 'text/txt' \n\n")
print("Current Time: ")
print(time)