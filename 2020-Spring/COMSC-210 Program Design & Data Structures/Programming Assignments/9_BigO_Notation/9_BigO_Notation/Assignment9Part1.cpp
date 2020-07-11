#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n\n";

  ifstream inputF;
  char* token;
  char buffer[1000];
  const char* const tab = "\t";

  double On;//O(n)
  int n = 10000;
  int count = -1;

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
      cout << On << " (expected O(n)) for n = 10,000" << endl;
    }
    else if (i == 1) {//2nd
      cout << elapsedSeconds << " (expected " << (On * 2) << ") for n = 20,000" << endl;
    }
    else if (i == 2) {//3rd
      cout << elapsedSeconds << " (expected " << (On * 4) << ") for n = 40,000" << endl;
    }
    else if (i == 3) {//4th
      cout << elapsedSeconds << " (expected " << (On * 8) << ") for n = 80,000" << endl;
    }

  }

}
