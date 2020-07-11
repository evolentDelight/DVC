// LabExercise11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LabExercise11.h"

int hashCode(const string& key){
  int result = 0;
  for (int i = 0; i < key.length(); i++) {
    result += key.at(i);
  }
  return result;
}

int main()
{
  HashTable<string, int, 100> test(hashCode);

  test["one"] = 1;
  cout << "Size: " << test.size() << endl;
  cout << "Data: \"one\": " << test["one"] << endl << endl;

  test.deleteKey("one");
  cout << "Test deleteKey\n";
  cout << "Size: " << test.size() << endl << endl;

  cout << "Test clear()\n";
  test["one"] = 1;
  test["two"] = 2;
  test["three"] = 3;
  cout << "Size: " << test.size() << endl;
  test.clear();
  cout << "Cleared\n";
  cout << "Size: " << test.size() << endl;

  cout << "\nTest keys()\n";
  test["one"] = 1;
  test["two"] = 2;
  test["three"] = 3;
  cout << "Size: " << test.size() << endl;

  queue<string> copy = test.keys();

  for (int i = 0; i < test.size(); i++) {
    cout << "Queue: " << copy.front() << endl;
    cout << "Value: " << test[copy.front()] << endl << endl;
    copy.pop();
  }

}


