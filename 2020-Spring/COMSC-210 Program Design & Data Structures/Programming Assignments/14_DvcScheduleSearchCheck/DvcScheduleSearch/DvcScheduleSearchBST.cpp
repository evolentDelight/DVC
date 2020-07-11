#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#include "BinarySearchTree.h"

using namespace std;

int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  BinarySearchTree<string, set<int>> allClass;

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

    string classCode = "";//Empty string to add term + 1 || 2 | 3 depending on Spring, Summer, Fall
    size_t found = term.find("2");

    if (term.find("Spring") != string::npos) {
      classCode += term[found];
      classCode += term[(found + 1)];
      classCode += term[(found + 2)];
      classCode += term[(found + 3)];
      classCode += "1";
    }
    else if (term.find("Summer") != string::npos) {
      classCode += term[found];
      classCode += term[(found + 1)];
      classCode += term[(found + 2)];
      classCode += term[(found + 3)];
      classCode += "2";
    }
    else if (term.find("Fall") != string::npos) {
      classCode += term[found];
      classCode += term[(found + 1)];
      classCode += term[(found + 2)];
      classCode += term[(found + 3)];
      classCode += "3";
    }

    int code = 0;

    stringstream placeh(classCode);

    placeh >> code;

    allClass[course].insert(code);
  }

  inputF.close();

  while (1) {
    cout << endl;
    cout << "Enter a course name[COMSC-210] to search for the first and last semester course that it was offered.[Enter X or x to quit]" << endl;

    string course;

    getline(cin, course);

    if (course == "X" || course == "x") {
      break;
    }

    if (allClass.containsKey(course)) {

      //Parse Data
      set<int>::iterator it = allClass[course].begin();//First
      set<int>::reverse_iterator rit = allClass[course].rbegin();//Last

      string s_front = to_string(*it);
      string s_back = to_string(*rit);

      string front = "";
      string back = "";

      if (s_front[s_front.length() - 1] == '1') {
        front += "Spring ";
        s_front.erase(s_front.length() - 1);
        front += s_front;
      }
      else if (s_front[s_front.length() - 1] == '2') {
        front += "Summer ";
        s_front.erase(s_front.length() - 1);
        front += s_front;
      }
      else if (s_front[s_front.length() - 1] == '3') {
        front += "Fall ";
        s_front.erase(s_front.length() - 1);
        front += s_front;
      }

      if (s_back[s_back.length() - 1] == '1') {
        back += "Spring ";
        s_back.erase(s_back.length() - 1);
        back += s_back;
      }
      else if (s_back[s_back.length() - 1] == '2') {
        back += "Summer ";
        s_back.erase(s_back.length() - 1);
        back += s_back;
      }
      else if (s_back[s_back.length() - 1] == '3') {
        back += "Fall ";
        s_back.erase(s_back.length() - 1);
        back += s_back;
      }
      //Output

      cout << course << " was first offered in " << front << endl;
      cout << course << " was last offered in  " << back << endl;

    }
    else {
      cout << course << " could not be found as far back as the year 2000" << endl;
    }
  }

  cout << "Exited" << endl;
}