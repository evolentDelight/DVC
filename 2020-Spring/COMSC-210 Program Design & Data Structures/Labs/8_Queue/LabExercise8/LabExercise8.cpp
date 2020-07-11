
#include <iostream>
#include <cassert>

#include "LabExercise8.h"

using namespace std;

int main()
{
  Queue<int> test;

  test.push(1);
  test.push(2);
  test.push(3);

  cout << "\nTesting Size:\n";
  cout << "Expected: 3 - Actual: " << test.size() << "\n\n";

  cout << "Testing front()\n";
  cout << "Expected: 1 - Actual: " << test.front() << "\n\n";

  cout << "Testing back()\n";
  cout << "Expected: 3 - Actual: " << test.back() << "\n\n";

  cout << "Testing clear()\n";
  test.clear();
  cout << "Expected: 0 - Actual: " << test.size() << "\n\n";

  test.push(1);
  test.push(2);
  test.push(3);

  cout << "Testing pop()\n";
  test.pop();
  cout << "Expected: 2 - Actual: " << test.size() << "\n";
  cout << "Expected: 2 - Actual: " << test.front() << "\n\n";

  cout << "Testing Copy Constructor\n";
  Queue<int> copy = test;
  assert(copy.front() == test.front());
  assert(copy.back() == test.back());
  cout << "Passed!\n\n";

  cout << "Testing Assignment Operator\n";
  Queue<int> assign; assign = test;
  assert(assign.front() == test.front());
  assert(assign.back() == test.back());
  cout << "Passed!\n\n";
}

