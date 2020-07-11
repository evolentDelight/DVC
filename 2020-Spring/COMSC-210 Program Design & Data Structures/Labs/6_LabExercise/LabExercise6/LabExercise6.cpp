// DVC_Schedule.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

//Partner Name: Hwan Kim
//Parter ID:    1151832

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "DynamicArray.h"
#include "StaticArray.h"

using namespace std;

//structs
struct subject
{
  string subjectCode;
  int count;
};

struct SectionForTerm
{
  string term;
  int numberOfSectionsSeen;

  DynamicArray<string> seenSectionNumber;
};

int check_term(const string term, const StaticArray<SectionForTerm, 200>& arr, int index)//Returns the term index
{
  int i = 0;

  for (i ; i < index; i++) {
    if (arr[i].term == term) {
      break;
    }
  }

  return i;//Returns term that doesn't exist || does exist -> then create new term || check_section

};

bool check_section(const string section, const SectionForTerm& arr)
{

  for (int i = 0; i < arr.numberOfSectionsSeen; i++) {
    if (arr.seenSectionNumber[i] == section) {
      return true;
    }
  }

  return false;

};


bool comp(string a, string b) {
  return a < b;
};

int main()
{
  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n\n";

  DynamicArray<subject> subjectCount(100);//Amount of classes in each subject
  StaticArray<SectionForTerm, 200> alreadySeen;

//Parse Code Here

  //for parsing the inputfile
  char* token;
  char buffer[1000];
  const char* const tab = "\t";

  int count = 0;//How many lines read
  int duplicates = 0;//Duplicate records
  int subjectIndex = 0;//Index for subjectCount array
  int alreadySeenIndex = 0;//Index for alreadySeen array

  bool codeFound = true;//If subjectCODE found, then update subjectCount.count | If not found, then add to subjectCount

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

    codeFound = true;


    int termNumber = check_term(term, alreadySeen, alreadySeenIndex);

    if (termNumber == alreadySeenIndex) {//If equals, then term doesn't exist
     //Add new term & section
      alreadySeen[alreadySeenIndex].term = term;
      alreadySeen[alreadySeenIndex].seenSectionNumber[alreadySeen[alreadySeenIndex].numberOfSectionsSeen] = section;
      alreadySeen[alreadySeenIndex].numberOfSectionsSeen++;//Next numberofSectionsSeen is new index
      alreadySeenIndex++;
    }
    else {//If term exists, then check_section & duplicate
      if (!check_section(section, alreadySeen[termNumber])) {//If doesn't exist
        alreadySeen[termNumber].seenSectionNumber[alreadySeen[termNumber].numberOfSectionsSeen] = section;
        alreadySeen[termNumber].numberOfSectionsSeen++;

        //Check if subjectCode exists, if not add and update count
        for (int i = 0; i <= subjectIndex; i++) {
          if (subjectCount[i].subjectCode == subjectCode) {//Once found
            subjectCount[i].count++;
            codeFound = true;
            break;
          }
          else {
            codeFound = false;
          }
        }
        if (!codeFound) {//If subjectCode doesn't exist in array, then add it and increment subjectIndex
          subjectCount[subjectIndex].subjectCode = subjectCode;
          subjectCount[subjectIndex].count++;
          subjectIndex++;
        }
      }
      else {//If exists, then it is a duplicate
        duplicates++;
      }
    }

    count++;//For every successful output during the loop, there is a line. Hence +1 on count
    if (count % 1000 == 0) {
      cout << ".";
      cout.flush();
    }

  }

  inputF.close();

  //Order subjectCount alphabetically
  vector<string> place;
  for (int i = 0; i < subjectIndex; i++) {
    place.push_back(subjectCount[i].subjectCode);
  }
  sort(place.begin(), place.end(), comp);

  //Output Result
  cout << "\n\n" << "Finished!\n";

  int getCount = 0;//Get subjectCount
  for (int i = 0; i < subjectIndex; i++) {
    for (int j = 0; j < subjectIndex; j++) {
      if (subjectCount[j].subjectCode == place[i]) {
        getCount = subjectCount[j].count;
        break;
      }
    }

    cout << place[i] << ", " << getCount << " sections\n";
  }

  cout << "Total amount of duplicates: " << duplicates << "\n";
  cout << "Total count: " << count << "\n";
  cout << "Total amount of subjects: " << subjectIndex << "\n";

}
