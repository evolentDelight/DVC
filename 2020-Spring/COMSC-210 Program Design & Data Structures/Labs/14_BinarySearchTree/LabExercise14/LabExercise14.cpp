
#include <iostream>
#include <string>

#include "LabExercise14.h"

using namespace std;

int main()
{
  BinarySearchTree<string, int> test;

  test["one"] = 1;
  test["two"] = 2;

  cout << "Contains one: " << test.containsKey("one") << endl;
  cout << "Contains two: " << test.containsKey("two") << endl;
  cout << "Size: " << test.size() << endl;

  cout << endl << "Copy & Assignment" << endl;
  BinarySearchTree<string, int> assignment = test;
  BinarySearchTree<string, int> copy;
  copy = test;

  cout << endl << "Assignment Contains-" << endl;
  cout << "Contains one: " << assignment.containsKey("one") << endl;
  cout << "Contains two: " << assignment.containsKey("two") << endl;
  cout << "Size: " << assignment.size() << endl;
  cout << "Delete one: " << endl;
  assignment.deleteKey("one");
  cout << "Does not contain one: " << assignment.containsKey("one") << endl;
  cout << "Contains two: " << assignment.containsKey("two") << endl;
  cout << "Size: " << assignment.size() << endl;

  cout << endl << "Copy Contains-" << endl;
  cout << "Contains one: " << copy.containsKey("one") << endl;
  cout << "Contains two: " << copy.containsKey("two") << endl;
  cout << "Size: " << copy.size() << endl;
  cout << "Delete one: " << endl;
  copy.deleteKey("one");
  cout << "Does not contain one: " << copy.containsKey("one") << endl;
  cout << "Contains two: " << copy.containsKey("two") << endl;
  cout << "Size: " << copy.size() << endl;

  cout << endl << "Test: size and queue after adding and deleting" << endl;
  test["three"] = 3;
  test["four"] = 4;
  test["five"] = 5;//size = 5;
  cout << "B4 Delete Size: " << test.size() << endl;
  test.deleteKey("one");
  cout << "After Delete Size: " << test.size() << endl;
  test["one"] = 1;//size = 5;
  cout << "After 1More Push Size: " << test.size() << endl;

  Queue<string> q = test.Keys();

  cout << endl << "Test's queue: value" << endl;
  int size = q.size();
  for (int i = 0; i < size; i++) {
    cout << q.front() << " : " << test[q.front()] << endl;
    q.pop();
  }
  
}

