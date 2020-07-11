
#include <iostream>
#include <cstdlib>

#include "SortableArray.h"

using namespace std;

int main()
{
    
  //Programmer ID:
    cout << "----------------------------------------------------------------------------------------------------\n";
    cout << "Programmer:\t\tBenjamin Kwon\n";
    cout << "Programmer's ID:\t1162854\n";
    cout << "File: " << __FILE__ << "\n";
    cout << "----------------------------------------------------------------------------------------------------\n\n";

    int index;
    double value;

    int MAXindex = 0;

    int count = 0;

    string buf;

    SortableArray<double> entry;
    SortableArray<bool> exist;

    cout << "\n\nFor the program to work properly, all index between to 0 and user-chosen max must be entered.\n\n";

  //Index-Value Input Loop
    while (1) {

      cout << "Input an index and a value separated by a space [Enter Q or q to stop]: ";

      cin >> buf;
      if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
      index = atoi(buf.c_str());

      cin >> buf;
      if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
      value = atof(buf.c_str());

      if (MAXindex < index) MAXindex = index;

      if (index > -1) {
        count++;
        entry[index] = value;
        exist[index] = true;
      }
    }

    MAXindex++;//Plus one to get nonprogrammatical index

  //2nd Input:
    //How many stored values
    //Output the index-value pairs
    //To what index to sort:
    int SORTindex = 0;

    cout << "\nYou have stored: [" << count << "] values\n";

    for (int i = 0; i < MAXindex; i++) {
      if (exist[i]) {
        cout << i << " => " << entry[i] << "\n";
      }
    }

    cout << "\nTo where to sort?: ";
    cin >> SORTindex;

    entry.sort(SORTindex);

    for (int i = 0; i < MAXindex; i++) {
      if (exist[i]) {
        cout << i << " => " << entry[i] << "\n";
      }
    }

    cout << endl;

    while (1) {

      cout << "Input an index to look up its value [Enter Q or q to quit]: ";

      cin >> buf;
      if (buf[0] == 'q' || buf[0] == 'Q') break;//Break if input is quit
      index = atoi(buf.c_str());

      if (!exist[index]) {
        cout << "There is no value stored in index <" << index << ">\n";
      }
      else {
        cout << "Found. Value stored at index <" << index << "> is " << entry[index] << "\n";
      }

      cout << endl;
    }
}

