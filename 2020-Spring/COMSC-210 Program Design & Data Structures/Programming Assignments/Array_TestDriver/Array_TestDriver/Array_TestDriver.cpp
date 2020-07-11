// Array_TestDriver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

#include "Array.h"

using namespace std;

int main()
{
  Array a;

  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);
  cout << "Test Array::Array Passed\n";

  // Array::operator[ ] setter
  cout << "\nTesting the Array::operator[ ] setter\n";
  a[6] = 12356;
  a[97] = 7654321;
  cout << "1st Setter Test Passed\n";
  cout << "\nTesting Array::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[6]\n";
  cout << "ACTUAL: " << a[6] << endl;
  assert(12356 == a[6]);
  cout << "EXPECTED: 7654321 for a[7]\n";
  cout << "ACTUAL: " << a[97] << endl;
  assert(7654321 == a[97]);
  a[-99] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-99] << endl;
  assert(12356 == a[6]);
  assert(7654321 == a[97]);
  assert(123123 == a[-6]); // any out-of-range uses dummy
  assert(123123 == a[100]); // out of range uses dummy
  assert(123123 != a[99]); // checks upper end of range
  assert(123123 != a[0]); // checks lower end of range
  cout << "2nd Setter Test Passed\n";


  // Array::operator[ ] getter
  cout << "\nTesting the Array::operator[ ] getter\n";
  const Array b = a;
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);
  cout << "Test Passed\n";

  // const object test
  cout << "\nConst object test\n";
  const Array c; // if this compiles, Array::Array main constructor exists 
  assert(c.capacity() == 100); // if this compiles, Array::capacity is a getter 
  assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter 
  assert(c[-1] == c[-1]); // tests the getter's range checking 
  cout << "Test Passed\n";

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
