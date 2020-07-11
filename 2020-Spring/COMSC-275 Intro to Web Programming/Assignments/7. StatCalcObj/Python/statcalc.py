class StatCalc:
    def __init__(self,dataList):
        self.dataList=dataList
        self.sdataList=[]+ self.dataList
        self.sdataList.sort()

    def showResults(self):
        print("Original Values: <br>")
        for item in self.dataList:
            print(item)
            print(" ")

        print("<br><br>")
        print("Sorted Values: <br>")
        for item in self.sdataList:
            print(item)
        print("<br>")

    def findMin(self):
        return self.sdataList[0]

    def findMax(self):
        return self.sdataList \
            [len(self.sdataList)-1]

    def findMean(self):
        mean = sum(self.sdataList) / \
               len(self.sdataList)
        return mean

    def findMedian(self):
        mid = len(self.sdataList) / 2
        if len(self.sdataList) % 2 == 0:  # if even set
            result = (self.sdataList[int(mid)] + self.sdataList[int(mid - 1)]) / 2
        else:
            result = self.sdataList[int(mid - 0.5)]
        return result

    def calcValues(self,opList):
        dictOpRes = {}
        for op in opList:
            if op == "min":
                dictOpRes[op] = self.findMin()
            if op == "max":
                dictOpRes[op] = self.findMax()
            if op == "mean":
                dictOpRes[op] = self.findMean()
            if op == "median":
                dictOpRes[op] = self.findMedian()

        return dictOpRes
