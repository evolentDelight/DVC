// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    
//Programmer ID
  cout << "\n---------------------------------------------------------------\n";
  cout << "Programmer Name: \tBenjamin Kwon\n";
  cout << "Programmer ID: \t\t1162854";
  cout << "\n---------------------------------------------------------------\n\n\n";

  cout << "\nifndef Test Passed\n";

  cout << "\nTesting Int Array====================================================\n";

  DynamicArray<int> i;//i as int

  i.capacity(25);

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << i.capacity() << "\n";

  cout << "\nTesting Setter & Auto-adjusting capacity via Setter\n";
  i[0] = 5;
  i[12] = 27;
  i[24] = 72;
  i[25] = 55;
  i[52] = 77;

  cout << "i[0]: Expected: 5\n";
  cout << "Actual: " << i[0] << "\n";
  assert(5 == i[0]);

  cout << "i[12]: Expected: 27\n";
  cout << "Actual: " << i[12] << "\n";
  assert(27 == i[12]);

  cout << "i[24]: Expected: 72\n";
  cout << "Actual: " << i[24] << "\n";
  assert(72 == i[24]);


  cout << "i[25]: Expected 55\n";
  cout << "Actual: " << i[25] << "\n";
  assert(55 == i[25]);

  cout << "i[52]: Expected 77\n";
  cout << "Actual: " << i[52] << "\n";
  assert(77 == i[52]);


  cout << "\nTesting dummy setter\n";//Dummy setter can only be done on array index that does not exist
  i[-55] = 4321;

  cout << "i[-55]: Expected: 4321\n";
  cout << "Actual: " << i[-55] << "\n";
  assert(i[-55] == 4321);

  cout << "i[-1]: Expected: 4321\n";
  cout << "Actual: " << i[-1] << "\n";
  assert(i[-1] == 4321);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert(4321 == i[-25]);//Out-of-range uses dummy
  assert(4321 == i[-555]);//Out-of-range uses dummy
  assert(4321 != i[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting Getter\n";
  const DynamicArray<int>z = i;
  for (int j = 0; j < i.capacity(); j++) {
    assert(z[j] == i[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Copy Test\n";
  DynamicArray<int>o = i;
  assert(i.capacity() == o.capacity());
  for (int j = 0; j < i.capacity(); j++) {
    assert(i[j] == o[j]);
  }
  for (int j = 0; j < i.capacity(); j++) {
    i[j]++;
    assert(i[j] != o[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Assignment Test\n";
  DynamicArray<int>p; p = i;
  assert(i.capacity() == p.capacity());
  for (int j = 0; j < i.capacity(); j++) {
    assert(i[j] == p[j]);
  }
  for (int j = 0; j < i.capacity(); j++) {
    i[j]++;
    assert(i[j] != p[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const DynamicArray<int, 25>z compiled, therefore DynamicArray constructor exists
  assert(i.capacity());//if this compiles, capacity() is a getter
  assert(z[0] == z[0]);//if this compiles, there is a getter
  assert(z[-1] == z[-1]);//tests the getter's range
  cout << "Passed\n";

  //TEST:: double
  cout << "\nTesting Double Array==================================================\n";

  DynamicArray<double> d;//d as in double

  d.capacity(25);

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << d.capacity() << "\n";


  cout << "\nTesting Setter & Auto-adjusting capacity via Setter\n";
  d[0] = 65;
  d[12] = 127;
  d[24] = 172;
  d[25] = 555.5;
  d[52] = 777.7;

  cout << "d[0]: Expected: 65\n";
  cout << "Actual: " << d[0] << "\n";
  assert(65 == d[0]);

  cout << "d[12]: Expected: 127\n";
  cout << "Actual: " << d[12] << "\n";
  assert(127 == d[12]);

  cout << "d[24]: Expected: 172\n";
  cout << "Actual: " << d[24] << "\n";
  assert(172 == d[24]);

  cout << "d[25]: Expected 555.5\n";
  cout << "Actual: " << d[25] << "\n";
  assert(555.5 == d[25]);

  cout << "d[52]: Expected 777.7\n";
  cout << "Actual: " << d[52] << "\n";
  assert(777.7 == d[52]);

  cout << "Passed\n";

  cout << "\nTesting dummy setter\n";
  d[-55] = 54321.0;

  cout << "d[-55]: Expected: 54321\n";
  cout << "Actual: " << d[-55] << "\n";
  assert(d[-55] == 54321.0);

  cout << "d[-525]: Expected: 54321\n";
  cout << "Actual: " << d[-525] << "\n";
  assert(d[-525] == 54321.0);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert(54321.0 == d[-25]);//Out-of-range uses dummy
  assert(54321.0 == d[-125]);//Out-of-range uses dummy
  assert(54321.0 != d[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const DynamicArray<double>y = d;
  for (int j = 0; j < d.capacity(); j++) {
    assert(d[j] == y[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Copy Test\n";
  DynamicArray<double>u = d;
  assert(d.capacity() == u.capacity());
  for (int j = 0; j < d.capacity(); j++) {
    assert(d[j] == u[j]);
  }
  for (int j = 0; j < d.capacity(); j++) {
    d[j]++;
    assert(d[j] != u[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Assignment Test\n";
  DynamicArray<double>t; t = d;
  assert(d.capacity() == t.capacity());
  for (int j = 0; j < d.capacity(); j++) {
    assert(d[j] == t[j]);
  }
  for (int j = 0; j < d.capacity(); j++) {
    d[j]++;
    assert(d[j] != t[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const DynamicArray<double> compiled, therefore DynamicArray constructor exists
  assert(d.capacity());//if this compiles, capacity() is a getter
  assert(y[0] == y[0]);//if this compiles, there is a getter
  assert(y[-1] == y[-1]);//tests the getter's range
  cout << "Passed\n";

  //TEST:: char
  cout << "\nTesting Char Array====================================================\n";

  DynamicArray<char> c;//c as in char

  c.capacity(26);

  cout << "\nTesting Capacity\n";
  cout << "Expected: 26\n";
  cout << "Actual: " << c.capacity() << "\n";


  cout << "\nTesting Setter & Auto-adjusting capacity Setter\n";
  c[0] = 'a';
  c[12] = 'i';
  c[25] = 'z';
  c[35] = '%';
  c[55] = '*';

  cout << "c[0]: Expected: a\n";
  cout << "Actual: " << c[0] << "\n";
  assert('a' == c[0]);

  cout << "c[12]: Expected: i\n";
  cout << "Actual: " << c[12] << "\n";
  assert('i' == c[12]);

  cout << "c[25]: Expected: z\n";
  cout << "Actual: " << c[25] << "\n";
  assert('z' == c[25]);

  cout << "c[35]: Expected %\n";
  cout << "Actual: " << c[35] << "\n";
  assert('%' == c[35]);
  
  cout << "c[55]: Expected *\n";
  cout << "Actual: " << c[55] << "\n";
  assert('*' == c[55]);

  cout << "Passed\n";


  cout << "\nTesting dummy setter\n";
  c[-55] = '+';

  cout << "c[-55]: Expected: +\n";
  cout << "Actual: " << c[-55] << "\n";
  assert('+' == c[-55]);

  cout << "c[-125]: Expected: +\n";
  cout << "Actual: " << c[-125] << "\n";
  assert('+' == c[-125]);
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert('+' == c[-25]);//Out-of-range uses dummy
  assert('+' == c[-261]);//Out-of-range uses dummy
  assert('+' != c[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const DynamicArray<char>x = c;
  for (int j = 0; j < c.capacity(); j++) {
    assert(c[j] == x[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Copy Test\n";
  DynamicArray<char>r = c;
  assert(r.capacity() == c.capacity());
  for (int j = 0; j < c.capacity(); j++) {
    assert(r[j] == c[j]);
  }
  for (int j = 0; j < c.capacity(); j++) {
    c[j]++;
    assert(c[j] != r[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Assignment Test\n";
  DynamicArray<char>e; e = c;
  assert(c.capacity() == e.capacity());
  for (int j = 0; j < c.capacity(); j++) {
    assert(c[j] == e[j]);
  }
  for (int j = 0; j < c.capacity(); j++) {
    c[j]++;
    assert(c[j] != e[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const DynamicArray<char>x compiled, therefore DynamicArray constructor exists
  assert(c.capacity());//if this compiles, capacity() is a getter
  assert(x[0] == x[0]);//if this compiles, there is a getter
  assert(x[-1] == x[-1]);//tests the getter's range
  cout << "Passed\n";

  //TEST:: string

  cout << "\nTesting Object-String Array====================================================\n";

  DynamicArray<string> s;//s as in string

  s.capacity(25);

  cout << "\nTesting Capacity\n";
  cout << "Expected: 25\n";
  cout << "Actual: " << s.capacity() << "\n";


  cout << "\nTesting Setter & Auto-adjusting capacity Setter\n";
  s[0] = "zero";
  s[12] = "twelve";
  s[24] = "twenty four";
  s[25] = "twenty five";
  s[50] = "fifty";

  cout << "s[0]: Expected: zero\n";
  cout << "Actual: " << s[0] << "\n";
  assert("zero" == s[0]);

  cout << "s[12]: Expected: twelve\n";
  cout << "Actual: " << s[12] << "\n";
  assert("twelve" == s[12]);

  cout << "s[24]: Expected: twenty four\n";
  cout << "Actual: " << s[24] << "\n";
  assert("twenty four" == s[24]);
  
  cout << "s[25]: Expected: twenty five\n";
  cout << "Actual: " << s[25] << "\n";
  assert("twenty five" == s[25]);
  
  cout << "s[50]: Expected: fifty\n";
  cout << "Actual: " << s[50] << "\n";
  assert("fifty" == s[50]);

  cout << "Passed\n";


  cout << "\nTesting dummy setter\n";
  s[-55] = "dummy";

  cout << "s[-55]: Expected: dummy\n";
  cout << "Actual: " << s[-55] << "\n";
  assert(s[-55] == "dummy");

  cout << "s[-125]: Expected: dummy\n";
  cout << "Actual: " << s[-125] << "\n";
  assert(s[-125] == "dummy");
  cout << "Passed\n";

  cout << "\nTesting range tests\n";
  assert("dummy" == s[-25]);//Out-of-range uses dummy
  assert("dummy" == s[-125]);//Out-of-range uses dummy
  assert("dummy" != s[0]);//Checks lower end of range
  cout << "Passed\n";

  cout << "\nTesting getter\n";
  const DynamicArray<string>w = s;
  for (int j = 0; j < s.capacity(); j++) {
    assert(s[j] == w[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Copy Test\n";
  DynamicArray<string>l = s;
  assert(s.capacity() == l.capacity());
  for (int j = 0; j < s.capacity(); j++) {
    assert(s[j] == l[j]);
  }
  for (int j = 0; j < s.capacity(); j++) {
    s[j]= "changed";
    assert(s[j] != l[j]);
  }
  cout << "Passed\n";

  cout << "\nObject Assignment Test\n";
  DynamicArray<string>k; k = s;
  assert(s.capacity() == k.capacity());
  for (int j = 0; j < s.capacity(); j++) {
    assert(s[j] == k[j]);
  }
  for (int j = 0; j < s.capacity(); j++) {
    s[j] = "changed5";
    assert(s[j] != k[j]);
  }
  cout << "Passed\n";

  cout << "\nConst Object Test\n";
  //const DynamicArray<string>w compiled, therefore DynamicArray constructor exists
  assert(s.capacity());//if this compiles, capacity() is a getter
  assert(w[0] == w[0]);//if this compiles, there is a getter
  assert(w[-1] == w[-1]);//tests the getter's range
  cout << "Passed\n";


}

