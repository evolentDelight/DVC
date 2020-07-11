// LabExercise5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Programmer Name: Benjamin Kwon
Programmer ID:   1162854

Partner Name: Lakin Moser
Partner ID:   1698930
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // for strtok and strcpy

using namespace std;

int main()
{
//Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";  
  cout << "Programmer:\t\tBenjamin Kwon\n";  
  cout << "Programmer's ID:\t1162854\n";  
  cout << "File: " << __FILE__ << "\n";  
  cout << "----------------------------------------------------------------------------------------------------\n\n";


//Parse Code Here

  //for parsing the inputfile
  char* token;
  char buffer[1000];
  const char* const tab = "\t";

  int count = 0;

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

    cout << term << "\t" << section << "\t" << course << endl;
    count++;//For every successful output during the loop, there is a line. Hence +1 on count

  }

  cout << "Total " << count << " Lines Processed\n";

  inputF.close();

}

