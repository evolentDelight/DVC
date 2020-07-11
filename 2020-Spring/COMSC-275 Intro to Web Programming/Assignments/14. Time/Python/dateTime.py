#! /Python27/Python


from datetime import datetime

dateTime = datetime.now()

print("Content-type: 'text/xml' \n\n")

print("<?xml version='1.0' ?>")

print("Current Date and Time: ")

print("<dateTime>")

print(dateTime)

print("</dateTime>")