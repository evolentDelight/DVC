#! /Python37/Python

import cgi

from headTail import headHtml

from headTail import tailHtml

from formIo import getInput


def calcResults(dataList, opList):
    dictOpRes = {}
    sortedDataList = [] + dataList
    sortedDataList.sort()
    for op in opList:
        if op == "min":
            res = min(sortedDataList)
            dictOpRes[op] = res

        if op == "max":
            res = max(sortedDataList)
            dictOpRes[op] = res

        if op == "mean":
            res = sum(sortedDataList) / len(sortedDataList)
            dictOpRes[op] = res

        if op == "median":
            # code to be written
            mid = len(sortedDataList)/2
            if len(sortedDataList) % 2 == 0: #if even set
                dictOpRes[op] = (sortedDataList[int(mid)] + sortedDataList[int(mid-1)])/2
            else:
                dictOpRes[op] = sortedDataList[int(mid - 0.5)]

    return dictOpRes


def showResults(dataList, dictOpRes):
    print("Original Values: <br>")
    for item in dataList:
        print(item, " ", end="")

    dataList.sort();
    print("<br>")
    print("Sorted Values: <br>")
    for item in dataList:
        print(item, " ", end="")
    print("<br>")

    print("<br>")
    for op in dictOpRes:
        print(op + ": ")
        print(dictOpRes[op])
        print("<br>")


def main():
    headHtml()
    dataList, opList = getInput()

    dictOpRes = calcResults(dataList, opList)

    showResults(dataList, dictOpRes)

    tailHtml()
    return


if __name__ == "__main__":

    try:

        main()

    except:

        cgi.print_exception()

