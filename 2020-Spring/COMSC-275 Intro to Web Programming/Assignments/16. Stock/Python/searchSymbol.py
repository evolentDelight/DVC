#!/Python27/python

import cgi

print("Content_type: text/xml\n\n")

symList = ["aapl", "msft", "goog", "googl", "ibm", "angi"]

f = cgi.FieldStorage()

sym = f.getvalue("symbol")

matches = ""

for symbol in symList:

    if len(sym) > 0 and len(symbol) >= len(sym):
        sym = sym.lower()
        symbol = symbol.lower()

        if sym == symbol[0:len(sym)]:

            if matches == "":
                matches = symbol

            else:
                matches = matches + " " + symbol

if matches == "":
    matches = "No Match"

print(matches)