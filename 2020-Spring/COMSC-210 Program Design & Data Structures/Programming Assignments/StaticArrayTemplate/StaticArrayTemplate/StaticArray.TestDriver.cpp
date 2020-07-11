
//Programmer Name: Benjamin Kwon
//Programmer ID:   1162854

#include <iostream>
#include <cassert>

#include "StaticArray.h"

using namespace std;

int main()
{
//TEST:: int
  cout << "\nTesting Int Array====================================================\n";

  StaticArray<int, 25> i;//i as int

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << i.capacity() << "\n";
  
  cout << "\nTesting StaticArray::StaticArray\n";
  for (int j = 0; j < i.capacity(); j++) {
    assert( i[j] == 0 );
  }
  cout << "Passed\n";

  cout << "\nTesting Setter\n";
  i[0] = 5;
  i[12] = 27;
  i[24] = 72;

  cout << "i[0]: Expected: 5\n";
  cout << "Actual: " << i[0] << "\n";
  assert(5 == i[0]);

  cout << "i[12]: Expected: 27\n";
  cout << "Actual: " << i[12] << "\n";
  assert(27 == i[12]);

  cout << "i[24]: Expected: 72\n";
  cout << "Actual: " << i[24] << "\n";
  assert(72 == i[24]);

  cout << "\nTesting dummy setter\n";
  i[-55] = 4321;

  cout << "i[-55]: Expected: 4321\n";
  cout << "Actual: " << i[-55] << "\n";
  assert(i[-55] == 4321);

  cout << "i[125]: Expected: 4321\n";
  cout << "Actual: " << i[125] << "\n";
  assert(i[125] == 4321);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert(4321 == i[-25]);//Out-of-range uses dummy
  assert(4321 == i[26]);//Out-of-range uses dummy
  assert(4321 != i[24]);//Checks upper end of range
  assert(4321 != i[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const StaticArray<int, 25>z = i;
  for (int j = 0; j < i.capacity(); j++) {
    assert(i[j] == z[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  const StaticArray<int, 25> h;
  //const StaticArray<int, 25>z compiled, therefore StaticArray constructor exists
  assert(i.capacity());//if this compiles, capacity() is a getter
  assert(z[0] == z[0]);//if this compiles, there is a getter
  assert(z[-1] == z[-1]);//tests the getter's range
  cout << "Passed\n";

//TEST:: double
  cout << "\nTesting Double Array==================================================\n";

  StaticArray<double, 25> d;//d as in double

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << d.capacity() << "\n";

  cout << "\nTesting StaticArray::StaticArray\n";
  for (int j = 0; j < d.capacity(); j++) {
    assert(d[j] == 0);
  }
  cout << "Passed\n";

  cout << "\nTesting Setter\n";
  d[0] = 65.0;
  d[12] = 127.0;
  d[24] = 172.0;

  cout << "d[0]: Expected: 65\n";
  cout << "Actual: " << d[0] << "\n";
  assert(65 == d[0]);

  cout << "d[12]: Expected: 127\n";
  cout << "Actual: " << d[12] << "\n";
  assert(127 == d[12]);

  cout << "d[24]: Expected: 172\n";
  cout << "Actual: " << d[24] << "\n";
  assert(172 == d[24]);

  cout << "\nTesting dummy setter\n";
  d[-55] = 54321.0;

  cout << "d[-55]: Expected: 54321\n";
  cout << "Actual: " << d[-55] << "\n";
  assert(d[-55] == 54321.0);

  cout << "d[125]: Expected: 54321\n";
  cout << "Actual: " << d[125] << "\n";
  assert(d[125] == 54321.0);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert(54321.0 == d[-25]);//Out-of-range uses dummy
  assert(54321.0 == d[25]);//Out-of-range uses dummy
  assert(54321.0 != d[24]);//Checks upper end of range
  assert(54321.0 != d[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const StaticArray<double, 25>y = d;
  for (int j = 0; j < d.capacity(); j++) {
    assert(d[j] == y[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const StaticArray<double, 25>y compiled, therefore StaticArray constructor exists
  assert(d.capacity());//if this compiles, capacity() is a getter
  assert(y[0] == y[0]);//if this compiles, there is a getter
  assert(y[-1] == y[-1]);//tests the getter's range
  cout << "Passed\n";

//TEST:: char
  cout << "\nTesting Char Array====================================================\n";

  StaticArray<char, 26> c;//c as in char

  cout << "\nTesting Capacity\n";
  cout << "Expected: 26\n";
  cout << "Actual: " << c.capacity() << "\n";

  cout << "\nTesting StaticArray::StaticArray\n";
  for (int j = 0; j < c.capacity(); j++) {
    assert(c[j] == 0);
  }
  cout << "Passed\n";

  cout << "\nTesting Setter\n";
  c[0] = 'a';
  c[12] = 'i';
  c[25] = 'z';

  cout << "c[0]: Expected: a\n";
  cout << "Actual: " << c[0] << "\n";
  assert('a' == c[0]);

  cout << "c[12]: Expected: i\n";
  cout << "Actual: " << c[12] << "\n";
  assert('i' == c[12]);

  cout << "c[25]: Expected: z\n";
  cout << "Actual: " << c[25] << "\n";
  assert('z' == c[25]);

  cout << "\nTesting dummy setter\n";
  c[-55] = '%';

  cout << "c[-55]: Expected: %\n";
  cout << "Actual: " << c[-55] << "\n";
  assert('%' == c[-55]);

  cout << "c[125]: Expected: %\n";
  cout << "Actual: " << c[125] << "\n";
  assert('%' == c[125]);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert('%' == c[-25]);//Out-of-range uses dummy
  assert('%' == c[26]);//Out-of-range uses dummy
  assert('%' != c[25]);//Checks upper end of range
  assert('%' != c[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const StaticArray<char, 26>x = c;
  for (int j = 0; j < c.capacity(); j++) {
    assert(c[j] == x[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const StaticArray<char, 26>x compiled, therefore StaticArray constructor exists
  assert(c.capacity());//if this compiles, capacity() is a getter
  assert(x[0] == x[0]);//if this compiles, there is a getter
  assert(x[-1] == x[-1]);//tests the getter's range
  cout << "Passed\n";

//TEST:: string

  cout << "\nTesting Object-String Array====================================================\n";

  StaticArray<string, 25> s;//s as in string

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << s.capacity() << "\n";

  cout << "\nTesting StaticArray::StaticArray\n";
  for (int j = 0; j < s.capacity(); j++) {
    assert(s[j] == "");
  }
  cout << "Passed\n";

  cout << "\nTesting Setter\n";
  s[0] = "zero";
  s[12] = "twelve";
  s[24] = "twenty four";

  cout << "s[0]: Expected: zero\n";
  cout << "Actual: " << s[0] << "\n";
  assert("zero" == s[0]);

  cout << "s[12]: Expected: twelve\n";
  cout << "Actual: " << s[12] << "\n";
  assert("twelve" == s[12]);

  cout << "s[24]: Expected: twenty four\n";
  cout << "Actual: " << s[24] << "\n";
  assert("twenty four" == s[24]);

  cout << "\nTesting dummy setter\n";
  s[-55] = "dummy";

  cout << "s[-55]: Expected: dummy\n";
  cout << "Actual: " << s[-55] << "\n";
  assert(s[-55] == "dummy");

  cout << "s[125]: Expected: dummy\n";
  cout << "Actual: " << s[125] << "\n";
  assert(s[125] == "dummy");
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert("dummy" == s[-25]);//Out-of-range uses dummy
  assert("dummy" == s[25]);//Out-of-range uses dummy
  assert("dummy" != s[24]);//Checks upper end of range
  assert("dummy" != s[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const StaticArray<string, 25>w = s;
  for (int j = 0; j < s.capacity(); j++) {
    assert(s[j] == w[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const StaticArray<string, 25>w compiled, therefore StaticArray constructor exists
  assert(s.capacity());//if this compiles, capacity() is a getter
  assert(w[0] == w[0]);//if this compiles, there is a getter
  assert(w[-1] == w[-1]);//tests the getter's range
  cout << "Passed\n";

}

