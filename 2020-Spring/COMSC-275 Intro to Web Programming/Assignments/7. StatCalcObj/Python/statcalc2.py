#!/Python27/python

import cgi

from headTail import headHtml
from headTail import tailHtml
from forms import getInput

import statcalc


def main():
    headHtml()

    dataList, opList = getInput()

    # create object

    statCalc = statcalc.StatCalc(dataList)

    statCalc.showResults()

    print('<br>Individual Values:<br>')
    for op in opList:

        if op == 'min':

            min = statCalc.findMin()

            print('min:' + str(min) + '<br>')

        elif op == 'max':

            max = statCalc.findMax()

            print('max: ' + str(max) + '<br>')

        elif op == 'mean':

            mean = statCalc.findMean()

            print('mean: ' + str(mean) + '<br>')

        elif op == 'median':
            median = statCalc.findMedian()

            print('median: ' + str(median) + '<br>')

    dictOpRes = statCalc.calcValues(opList)

    print(dictOpRes)
    tailHtml()
    return


if __name__ == "__main__":

    try:
        main()

    except:
        cgi.print_exception()
