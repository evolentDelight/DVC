
#include <iostream>
#include <cassert>

#include "Stack.h"

using namespace std;

int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  Stack<double> testD;//testDouble

  cout << "Stack Test: Type Double-----------------------------------------------------------------------------\n\n";

  cout << "Stack::size()\n";
  cout << "Expected: 0\n";
  cout << "Actual: " << testD.size() << "\n\n";

  cout << "Stack::push and Stack::peek\n";
  testD.push(1.23);
  testD.push(4.56);
  cout << "Expected: 4.56\n";
  cout << "Actual: " << testD.peek() << "\n\n";

  cout << "Stack::pop\n";
  testD.pop();
  cout << "Expected: 1.23\n";
  cout << "Actual: " << testD.peek() << "\n\n";

  cout << "Test Copy Constructor\n";
  testD.push(4.56);
  testD.push(7.89);
  Stack<double> copyD = testD;
  int size = copyD.size();
  for (int i = 0; i < size; i++) {
    assert(copyD.peek() == testD.peek());
    copyD.pop();
    testD.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Test Assignment Operator\n";
  testD.push(1.23);
  testD.push(4.56);
  testD.push(7.89);
  Stack<double> assignD;
  assignD = testD;
  size = assignD.size();
  for (int i = 0; i < size; i++) {
    assert(assignD.peek() == testD.peek());
    assignD.pop();
    testD.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Stack::size()\n";
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

  cout << "Stack::clear() and empty()\n";
  testD.clear();
  assert(testD.empty());
  cout << "Passed" << "\n\n";

  cout << "Constant Object Test\n";
  const Stack<double> constD = testD;//constDouble test
  cout << "Passed" << "\n\n";


  Stack<string> testS;//testString

  cout << "Stack Test: Type String-----------------------------------------------------------------------------\n\n";

  cout << "Stack::size()\n";
  cout << "Expected: 0\n";
  cout << "Actual: " << testS.size() << "\n\n";

  cout << "Stack::push and Stack::peek\n";
  testS.push("abc");
  testS.push("def");
  cout << "Expected: def\n";
  cout << "Actual: " << testS.peek() << "\n\n";

  cout << "Stack::pop\n";
  testS.pop();
  cout << "Expected: abc\n";
  cout << "Actual: " << testS.peek() << "\n\n";

  cout << "Test Copy Constructor\n";
  testS.push("def");
  testS.push("ghi");
  Stack<string> copyS = testS;
  size = copyS.size();
  for (int i = 0; i < size; i++) {
    assert(copyS.peek() == testS.peek());
    copyS.pop();
    testS.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Test Assignment Operator\n";
  testS.push("abc");
  testS.push("def");
  testS.push("ghi");
  Stack<string> assignS;
  assignS = testS;
  size = assignS.size();
  for (int i = 0; i < size; i++) {
    assert(assignS.peek() == testS.peek());
    assignS.pop();
    testS.pop();
  }
  cout << "Passed" << "\n\n";

  cout << "Stack::size()\n";
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

  cout << "Stack::clear() and empty()\n";
  testS.clear();
  assert(testS.empty());
  cout << "Passed" << "\n\n";

  cout << "Constant Object Test\n";
  const Stack<string> constS = testS;//constDouble test
  cout << "Passed" << "\n\n";
}