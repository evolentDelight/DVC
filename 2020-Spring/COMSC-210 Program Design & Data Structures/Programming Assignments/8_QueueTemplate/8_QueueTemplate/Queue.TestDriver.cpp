
#include <iostream>
#include <cassert>

#include "Queue.h"

using namespace std;

int main()
{
  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  Queue<double> testD;//testDouble

  cout << "Queue Test: Type Double-----------------------------------------------------------------------------\n\n";

  cout << "Queue::size()\n";
  cout << "Expected: 0\n";
  cout << "Actual: " << testD.size() << "\n\n";

  cout << "Queue::push and Queue::front() and Queue::back()\n";
  testD.push(1.23);
  testD.push(4.56);
  assert(testD.front() == 1.23);
  assert(testD.back() == 4.56);
  cout << "Passed!\n\n";

  cout << "Queue::pop\n";
  testD.pop();
  cout << "Expected: 4.56\n";
  cout << "Actual: " << testD.front() << "\n\n";

  cout << "Test Copy Constructor\n";
  testD.push(4.56);
  testD.push(7.89);
  Queue<double> copyD = testD;
  int size = copyD.size();
  for (int i = 0; i < size; i++) {
    assert(copyD.front() == testD.front());
    copyD.pop();
    testD.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Test Assignment Operator\n";
  testD.push(1.23);
  testD.push(4.56);
  testD.push(7.89);
  Queue<double> assignD;
  assignD = testD;
  size = assignD.size();
  cout << "AssignD Size: " << assignD.size() << "\n\n";
  for (int i = 0; i < size; i++) {
    assert(assignD.front() == testD.front());
    assignD.pop();
    testD.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Queue::size()\n";
  testD.push(1.23);
  testD.push(4.56);
  testD.push(7.89);
  testD.push(0.98);
  testD.push(7.65);
  testD.push(4.32);
  testD.push(1.11);
  cout << "Pushed 7 new elements\n";
  cout << "Expected: 7\n";
  cout << "Actual: " << testD.size() << "\n\n";

  cout << "Queue::clear() and empty()\n";
  testD.clear();
  assert(testD.empty());
  cout << "Passed" << "\n\n";

  cout << "Constant Object Test\n";
  const Queue<double> constD = testD;//constDouble test
  cout << "Passed" << "\n\n";


  Queue<string> testS;//testString

  cout << "Queue Test: Type String-----------------------------------------------------------------------------\n\n";

  cout << "Queue::size()\n";
  cout << "Expected: 0\n";
  cout << "Actual: " << testS.size() << "\n\n";

  cout << "Queue::push and Queue::front() and Queue::back()\n";
  testS.push("abc");
  testS.push("def");
  assert(testS.front() == "abc");
  assert(testS.back() == "def");
  cout << "Passed!\n\n";

  cout << "Queue::pop\n";
  testS.pop();
  cout << "Expected: def\n";
  cout << "Actual: " << testS.front() << "\n\n";

  cout << "Test Copy Constructor\n";
  testS.push("def");
  testS.push("ghi");
  Queue<string> copyS = testS;
  size = copyS.size();
  for (int i = 0; i < size; i++) {
    assert(copyS.front() == testS.front());
    copyS.pop();
    testS.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Test Assignment Operator\n";
  testS.push("abc");
  testS.push("def");
  testS.push("ghi");
  Queue<string> assignS;
  assignS = testS;
  size = assignS.size();
  for (int i = 0; i < size; i++) {
    assert(assignS.front() == testS.front());
    assignS.pop();
    testS.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Queue::size()\n";
  testS.push("abc");
  testS.push("def");
  testS.push("ghi");
  testS.push("jkl");
  testS.push("mno");
  testS.push("pqr");
  testS.push("stu");
  cout << "Pushed 7 new elements\n";
  cout << "Expected: 7\n";
  cout << "Actual: " << testS.size() << "\n\n";

  cout << "Queue::clear() and empty()\n";
  testS.clear();
  assert(testS.empty());
  cout << "Passed" << "\n\n";

  cout << "Constant Object Test\n";
  const Queue<string> constS = testS;//constDouble test
  cout << "Passed" << "\n\n";
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
