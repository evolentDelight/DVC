#include <iostream>
#include <cstdlib>

#include "Array.h"

using namespace std;

int main() {

  Array a;
  Array count;

  string buf;
  int index, value = 0;//Array index and value
  int unique = 0;//Amount of unique indexes

//Get Index and Value or Exit the program if called
  while (1) {
    cout << "\nInput an index and a value separated by a space [Enter Q or q to quit]: ";

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
    index = atoi(buf.c_str());

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
    value = atoi(buf.c_str());

  //After each successful retrieved index and value, add one to Array count to count the unique value
    if (index < 100 && index > -1) {
      count[index] = 1;
      a[index] = value;
    }
  }

//Count how many unique index there are and output it
  for (int i = 0; i < 100; i++) {
    if (count[i] == 1) unique++;
  }
  cout << "\nYou stored this many values: " << unique << "\n";

//Output the index-value pairs, if there are some
  if (unique != 0) {
    cout << "The index-value pairs are: " << "\n\n";

    for (int i = 0; i < 100; i++) {
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

    if (count[index] == 1 && index < 100 && index > -1) {
      cout << "Found it -- the value stored at " << index << " is " << a[index] << "\n";
    }
    else {
      cout << "I didn't find it\n";
    }
  }

}