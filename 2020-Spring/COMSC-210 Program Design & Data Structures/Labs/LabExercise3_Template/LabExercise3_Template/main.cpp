// LabExercise3_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

#include "LabExercise3.h"
#include "Array.h"

using namespace std;

int main()
{
  StaticArray<int, 25> a;

  a[5] = 65;
  a[24] = 55;
  assert(65 == a[5]);
  assert(55 == a[24]);

  a[-1] = 6789;//dummy value initialized
  cout << "Expected dummy value: 6789\n";
  cout << "a[-1] value: " << a[-1] << "\n";
  cout << "a[-66] value: " << a[-66] << "\n";
  
  cout << "Out of Range Test\n";
  cout << "a[25]: " << a[25] << " | Expected dummy value: 6789\n";
  cout << "a[-1]: " << a[-1] << " | Expected dummy value: 6789\n";
  a[0] = 999;
  cout << "a[0]: " << a[0] << " | Expected value: 999\n";

  cout << "Capacity Test\n";
  assert(25 == a.capacity());

  /*
  Array<int, 50> b;
  Array<string, 100> s;
  Array<Array<int, 50>, 30>;//<row, column>
  */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
