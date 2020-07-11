// PriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

#include "PriorityQueue.h"

using namespace std;

int main()
{
  PriorityQueue<int> test;

  cout << "Push: " << endl;
  test.push(3); cout << "Output: " << test.top() << endl;
  test.push(2); cout << "Output: " << test.top() << endl;
  test.push(1); cout << "Output: " << test.top() << endl;
  test.push(4); cout << "Output: " << test.top() << endl;
  test.push(5); cout << "Output: " << test.top() << endl;
  test.push(8); cout << "Output: " << test.top() << endl;
  test.push(7); cout << "Output: " << test.top() << endl;
  test.push(9); cout << "Output: " << test.top() << endl;

  PriorityQueue<int> copy1 = test;
  PriorityQueue<int> copy2;
  copy2 = test;

  cout << endl << "Pop: " << endl;
  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << "Output: " << test.top() << endl;
  test.pop();

  cout << endl << "copy1: " << endl;

  cout << endl << "Pop: " << endl;
  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << "Output: " << copy1.top() << endl;
  copy1.pop();

  cout << endl << "copy2: " << endl;

  cout << endl << "Pop: " << endl;
  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << "Output: " << copy2.top() << endl;
  copy2.pop();

  cout << endl << "Clear & Empty" << endl;

  test.push(3); cout << "Output: " << test.top() << endl;
  test.push(2); cout << "Output: " << test.top() << endl;
  test.push(1); cout << "Output: " << test.top() << endl;
  test.push(4); cout << "Output: " << test.top() << endl;

  test.clear();
  cout << "Empty?: " << test.empty() << endl;

  cout << "Rand: " << rand() % 100 << endl;

  for (int i = 0; i < 100; i++) {
    int push = rand() % 100;
    test.push(push);
  }

  for (int i = 0; i < 100; i++) {
    cout << test.top() << " ";
    test.pop();
  }


}

