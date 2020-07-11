
#include <iostream>
#include <string>
#include <algorithm>

#include "LabExercise10.h"

using namespace std;

int main()
{
    
  AssociativeArray<string, string> test;

  test["one"] = "a";

  cout << test["one"] << endl;// << " " << test["one"]["a"];

  cout << "Size: " << test.size() << endl;

  cout << "\nCopy test\n";
  AssociativeArray<string, string> copy;
  copy = test;

  cout << "bool: " << copy.containsKey("one") << endl;
  cout << "\"one\": " << copy["one"] << endl;
  cout << "Size: " << copy.size() << endl;

  cout << "\nDeleting key one\n";
  copy.deleteKey("one");
  cout << "bool: " << copy.containsKey("one") << endl;
  cout << "Size: " << copy.size();

  cout << "\n\n Adding two and three\n";
  test["two"] = "b";
  test["three"] = "c";
  cout << "Size: " << test.size() << endl;

  cout << "\nkeys()\n";
  Queue<string> print;
  vector<string> Tsort;

  print = test.keys();

  for (int i = 0; i < test.size(); i++) {
    Tsort.push_back(print.front());
    print.pop();
  }

  sort(Tsort.begin(), Tsort.end());

  for (int i = 0; i < test.size(); i++) {
    cout << Tsort[i] << endl;
  }

  cout << "\nclear()\n";
  test.clear();
  cout << "Size: " << test.size() << endl;

}

