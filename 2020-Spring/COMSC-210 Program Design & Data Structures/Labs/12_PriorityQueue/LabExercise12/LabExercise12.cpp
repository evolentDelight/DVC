// LabExercise12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LabExercise12.h"

using namespace std;

int main()
{

  PriorityQueue<int> test;

  cout << "Testing Push: \n";
  cout << "Push1:" << endl;
  test.push(1); cout << "top: " << test.top() << "| (1)\n";
  cout << "Push1:" << endl;
  test.push(2); cout << "top: " << test.top() << "| (2)\n";
  cout << "Push1:" << endl;
  test.push(3); cout << "top: " << test.top() << "| (3)\n\n";

  cout << "Size: " << test.size() << "| (3)\n\n";

  cout << "Testing Pop: \n";
  cout << "top: " << test.top() << "| (3)\n";

  test.pop();
  cout << "top: " << test.top() << "| (2)\n";

  test.pop();
  cout << "top: " << test.top() << "| (1)\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging men