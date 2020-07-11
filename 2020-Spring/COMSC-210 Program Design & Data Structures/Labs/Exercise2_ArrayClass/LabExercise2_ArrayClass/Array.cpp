

#include <iostream>
#include <cassert>

#include "Array.h"

using namespace std;

int main()
{
  Array a;

  // Array::Array
  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);

  // Array::operator[ ] setter
  cout << "\nTesting the Array::operator[ ] setter\n";
  a[6] = 12356;
  a[7] = 7654321;
  a[99] = 5;
  cout << "\nTesting Array::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[6]\n";
  cout << "ACTUAL: " << a[6] << endl;
  assert(12356 == a[6]);
  cout << "EXPECTED: 7654321 for a[7]\n";
  cout << "ACTUAL: " << a[7] << endl;
  assert(7654321 == a[7]);
  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(12356 == a[6]);
  assert(7654321 == a[7]);
  cout << "EXPECTED: 5 for a[99]\n";
  assert(5 == a[99]);
  cout << "ACTUAL: " << a[99] << endl;

  assert(123123 == a[-6]); // any out-of-range uses dummy
  assert(123123 == a[100]); // out-of-range uses dummy
  assert(123123 != a[10]); // checks upper end of range
  assert(123123 != a[9]); // checks upper end of range
  assert(123123 != a[0]); // checks lower end of range

  a[-99] = 321321;//dummy value changed using address a[-99]
  assert(321321 == a[-5]);
  assert(123123 != a[-9]);

  cout << "a[-5]: " << a[-5] << endl;

  cout << "a[-12]: " << a[-12] << endl;

  cout << "a[-1000]: " << a[-1000] << endl;

  cout << "a[-13]: " << a[-13] << endl;

  cout << "\nTesting Array::operator[] getter \n";
  const Array b = a;
  for (int i = 0; i < 100; i++) {
    assert(a[i] == b[i]);
    }

  cout << "b[-1]: " << b[-1] << endl;

  cout << "b[-1]: " << b[-5] << endl;

  cout << "b[-1]: " << b[-1000] << endl;

  // const object test
  cout << "\nConst object test\n";
  const Array c; // if this compiles, Array::Array main constructor exists 
  assert(c.capacity()); // if this compiles, Array::capacity is a getter 
  assert(c[0] == c[0]); // if this compiles, there is an Array::operator[ ] getter 
  assert(c[-1] == c[-1]); // tests the getter's range checking 
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
