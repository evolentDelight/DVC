#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  map<string, set<string>> allKeys;

  //Parse Code

      //for parsing the inputfile
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

    //Code Goes Here

    string classCode = term + "-" + section;//Empty string to add term + 1 || 2 | 3 depending on Spring, Summer, Fall

    allKeys[classCode].insert(course);
  }

  inputF.close();

  cout << endl;

  map<string, set<string>>::const_iterator it;

  for (it = allKeys.begin(); it != allKeys.end(); it++) {
    if (it->second.size() > 1) {
      cout << "Multiple Courses found for key: " << it->first << ": \n";

      set<string>::iterator it2;

      for (it2 = it->second.begin(); it2 != it->second.end(); it2++) {
        cout << *it2 << "\n";
      }
    }
  }

}