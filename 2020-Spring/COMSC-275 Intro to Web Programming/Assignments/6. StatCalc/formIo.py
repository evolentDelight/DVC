#!/Python37/python

import cgi

def dispForm():
    print('''
<form action='statcalc.py' method='get'>
<br>Data Values:
<br><input type='text' name='data' />
<br>Data Values Separating Charactor:
<br><input type="text" name='sep' />
<br><br>Operations:
<br><input type='checkbox' name='op[]' value='min' checked />Min
<input type='checkbox' name='op[]' value='max' checked />Max
<input type='checkbox' name='op[]' value='mean' checked />Mean
<input type='checkbox' name='op[]' value='median' checked />Median
<br><br><input type='submit' name='submit' value='Submit' /><br><br>
</form>
''')


def getInput():
    f = cgi.FieldStorage()
    data = f.getvalue('data')
    sep = f.getvalue('sep')
    opList = f.getvalue('op[]')
    dataList = data.split(sep)

    i = 0
    for item in dataList:
        dataList[i] = float(item)
        i = i + 1
    return dataList, opList