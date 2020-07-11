//Programmer Name: Benjamin Kwon
//Programmer ID: 1162854

#include <iostream>
#include <cstdlib>

#include "DynamicArray.h"

using namespace std;

int main() {
//Programmer ID
  cout << "\n---------------------------------------------------------------\n";
  cout << "Programmer Name: \tBenjamin Kwon\n";
  cout << "Programmer ID: \t\t1162854";
  cout << "\n---------------------------------------------------------------\n\n\n";

  DynamicArray<double> a;
  DynamicArray<bool> count;

  string buf;
  int index = 0;//Array index
  double value = 0;//Array value is double
  int unique = 0;//Amount of unique indexes

//Get Index and Value or Exit the program if called
  while (1) {
    cout << "\nInput an index and a value separated by a space [Enter Q or q to quit]: ";

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
    index = atoi(buf.c_str());

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
    value = atof(buf.c_str());

    //After each successful retrieved index and value, add one to Array count to count the unique value
    if (index > -1) {
      count[index] = 1;
      a[index] = value;
    }
  }

  //Count how many unique index there are and output it
  for (int i = 0; i < a.capacity(); i++) {
    if (count[i] == 1) unique++;
  }
  cout << "\nYou stored this many values: " << unique << "\n";

  //Output the index-value pairs, if there are some
  if (unique != 0) {
    cout << "The index-value pairs are: " << "\n\n";

    for (int i = 0; i < a.capacity(); i++) {
      if (count[i] == 1) {
        cout << i << " => " << a[i] << "\n";
      }
    }
  }

  //Look up index to output its value
  while (1) {
    cout << "\nInput an index for me to look up [Enter Q or q to quit]: ";

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
    index = atoi(buf.c_str());

    if (count[index] == 1 && index > -1) {
      cout << "Found it -- the value stored at " << index << " is " << a[index] << "\n";
    }
    else {
      cout << "I didn't find it\n";
    }
  }

}