#include <ctime>
#include <cassert>
#include <iostream>
#include <stdlib.h>

#include "PriorityQueue.h"

int main() {

  PriorityQueue<int> test;

  srand(time(0)); rand();

  int n = 1000000;
  const int reps = n / 100;

  cout.setf(ios::fixed);
  cout.precision(4);

  double elapsedSecondsNorm = 0.0;

  for (int cycle = 0; cycle < 4; cycle++, n *= 2) {

    for (int i = test.size(); i < n; i++) {
      test.push(rand() % 100);
    }

    assert(test.size() == n);

//Start Time
    clock_t startTime = clock();

    for (int rep = 0; rep < reps; rep++) {
      test.push(rand() % 100);
    }

    clock_t endTime = clock();
//End Time

    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));

    if (cycle == 0) elapsedSecondsNorm = elapsedSeconds;
    double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

    if(cycle == 0) cout << elapsedSeconds << " (expected) for n = " << n << endl;
    if(cycle != 0) cout << elapsedSeconds << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ") for n = " << n << endl;

//Testing the high-to-low order using assertion
    int size = test.size();
    int popped = test.top();
    for (int i = 0; i < size; i++) {
      assert(popped >= test.top());
      popped = test.top();
      test.pop();
    }

  }

}