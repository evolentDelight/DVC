#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctime>
#include <queue>

#include "HashTable.h"

using namespace std;

bool comp(string a, string b) {
  return a < b;
};

int hashCode(const string& key) {

  int result = 0;

  int i;

  if (key.length() > 3) {
    for (i = 0; i < key.length() - 4; i++) {
      result += key.at(i);
    }

    for (int j = 0; j < 4; j++) {
      result += (int)(key.at(i + j)) * pow(10, j);
    }
  }
  else {
    for (i = 0; i < key.length() - 1; i++) {
      result += key.at(i);
    }
    for (int j = 0; j < 1; j++) {
      result += (int)(key.at(i + j)) * pow(10, j);
    }
  }

  return result;
  
}

int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  HashTable<string, bool, 75000> record(hashCode);
  HashTable<string, int, 100> subClass(hashCode);

//Parse Code Here

  //for parsing the inputfile
  char* token;
  char buffer[1000];
  const char* const tab = "\t";

  int count = 0;//How many lines read
  int duplicates = 0;//Duplicate records

  clock_t startTime = clock();

  //open the input file
  ifstream inputF;//inputFile
  inputF.open("dvc-schedule.txt");
  if (!inputF.good())
    cout << "I/O Error: File not found\n";

  //read the input file
  while (inputF.good()) {

    //read the line
    string line;
    getline(inputF, line);
    strcpy(buffer, line.c_str());

    if (buffer[0] == 0) continue; // skip blank lines

    //parse the line
    const string term(token = strtok(buffer, tab));
    const string section((token = strtok(0, tab)) ? token : "");
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");

    if (course.find('-') == string::npos)
      continue; //invalid line: no dash in course name

    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    //Code Goes Here

    string classCode = term + section;
    
    if (record[classCode]) {
      duplicates++;
    }
    else {
      record[classCode] = true;
      subClass[subjectCode]++;
    }
    
    count++;

  }

  inputF.close();
  clock_t endTime = clock();
  double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

  cout << "hashTable CAP = 75000/100" << endl;

  cout << "Total runtime: " << elapsedSeconds << "\n";
  cout << "The load factor for the duplication check: " << record.loadFactor() << "\n";

  cout << "Total amount of duplicates: " << duplicates << "\n";
  cout << "Total count: " << count << "\n";

  queue<string> subKeys = subClass.keys();
  vector<string> subCode;

  int Qsize = subClass.size();
  for (int i = 0; i < Qsize; i++) {
    subCode.push_back(subKeys.front());
    subKeys.pop();
  }

  sort(subCode.begin(), subCode.end(), comp);

  for (int i = 0; i < Qsize; i++) {
    cout << subCode[i] << ", " << subClass[subCode[i]] << " section(s)\n";
  }

}