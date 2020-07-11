
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "AssociativeArray.h"
#include "Queue.h"

using namespace std;

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
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  AssociativeArray<string, AssociativeArray<string, int>> count;
  AssociativeArray<string, AssociativeArray<string, bool>> alreadySeen;

  int duplicates = 0;

  char* token;
  char buffer[1000];
  const char* const tab = "\t";

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
    


    if (alreadySeen[term][section]) {
      duplicates++;
    }
    else {
      alreadySeen[term][section] = true;
      count[subjectCode][course]++;
    }

  }

  inputF.close();

  Queue<string> subKeys = count.keys();

  vector<string> subCode;

  //Sort 
  int Qsize = subKeys.size();
  for (int i = 0; i < Qsize; i++) {
    subCode.push_back(subKeys.front());
    subKeys.pop();
  }

  sort(subCode.begin(), subCode.end(), comp);


  //Output
  Queue<string> courseKeys;
  int Csize;
  vector<string> cKeys;

  cout << "Duplicates: " << duplicates << "\n";

  for (int i = 0; i < Qsize; i++) {
  //Get Keys of subjectCode[#]
    courseKeys = count[subCode[i]].keys();

  //Sort count[subjectCode[#]].keys()
    Csize = courseKeys.size();
    for (int a = 0; a < Csize; a++) {
      cKeys.push_back(courseKeys.front());
      courseKeys.pop();
    }

    sort(cKeys.begin(), cKeys.end(), comp);

  //Full Output:
    cout << subCode[i] << ", " << Csize << " course(s)\n";

    for (int j = 0; j < Csize; j++) {
      cout << "   " << cKeys[j] << ", " << count[subCode[i]][cKeys[j]] << " section(s)\n";
    }

    cKeys.clear();
  }

}
