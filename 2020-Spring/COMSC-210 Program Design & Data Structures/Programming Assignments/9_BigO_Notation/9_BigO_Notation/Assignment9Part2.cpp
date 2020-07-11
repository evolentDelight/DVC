#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "DynamicArray.h"

using namespace std;

bool check_duplication(const string subject, const DynamicArray<string>& arr, int index) {

  bool result = false;

  for (int i = 0; i <= index; i++) {
    if (subject == arr[i]) {
      result = true;
    }
  }

  return result;

};

int main()
{
  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n\n";

  DynamicArray<string> nonDuplicateClasses(100);

  ifstream inputF;
  char* token;
  char buffer[1000];
  const char* const tab = "\t";

  int duplicates = 0;
  int classIndex = 0;

  double On;//O(n)
  int n = 800;
  int count = -1;

  bool codeFound;

  //Four timing cycle loop
  for (int i = 0; i < 4; i++) {

    //Start the timer
    clock_t startTime = clock();

    //open the input file
    inputF.open("dvc-schedule.txt");
    if (!inputF.good())
      cout << "I/O Error: File not found\n";

    //read the input file
    while (inputF.good() && count != n) {

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

      string record = term + " " + section;

      codeFound = true;

      if (!check_duplication(record, nonDuplicateClasses, classIndex)) {//If doesn't exists, then update the arrays
        nonDuplicateClasses[classIndex] = record;
        classIndex++;
      }
      else {//Duplicate does exist
        duplicates++;
      }

      count++;
    }

    //Close file
    inputF.close();

    //Stop and Record the timer
    clock_t endTime = clock();
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    //Reset
    count = -1;
    n *= 2;//Increase by 2 times for next iteration of timing test

    //Output
    if (i == 0) {//1st output
      On = elapsedSeconds;
      cout << On << " (expected O(n squared)) for n = 800" << endl;
    }
    else if (i == 1) {//2nd
      cout << elapsedSeconds << " (expected " << (On * 4) << ") for n = 1600" << endl;
    }
    else if (i == 2) {//3rd
      cout << elapsedSeconds << " (expected " << (On * 16) << ") for n = 3200" << endl;
    }
    else if (i == 3) {//4th
      cout << elapsedSeconds << " (expected " << (On * 64) << ") for n = 6400" << endl;
    }

  }

}
