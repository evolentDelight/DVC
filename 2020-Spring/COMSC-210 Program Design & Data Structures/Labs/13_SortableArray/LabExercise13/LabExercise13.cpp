#include <iomanip>
#include <iostream>

#include "LabExercise13.h"

using namespace std;

/*
void mergeSort(int* list, int size) {
  int* temp = new int[size];

  for (int delta = 1; delta < size; delta *= 2) {
    int index = 0;
    for (int i = 0; i < size; i++) {
      temp[i] = list[i];
    }
    for (int i = 0; i < size; i += 2 * delta) {
      int left = i;
      int leftMax = (size < left + delta ? size : left + delta);
      int right = leftMax;
      int rightMax = (size < right + delta ? size : right + delta);

      while (left < leftMax || right < rightMax) {
        if (left == leftMax) list[index++] = temp[right++];
        else if (right == rightMax) list[index++] = temp[left++];
        else if (temp[right] < temp[left]) list[index++] = temp[right++];
        else list[index++] = temp[left++];
      }

    }
  }

  delete[] temp;
}
*/

int main()
{

/*
  const int size = 10000;
  int a[size];

  srand(unsigned(time(0)));

  for (int i = 0; i < size; i++) {
    a[i] = rand() % 300;
  }

  cout << "\n\nBefore MergeSort: " << endl;
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }

  mergeSort(a, 5);


  cout << "\n\nAfter MergeSort: " << endl;
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }

*/

  SortableArray<int> test;
  const int size = 1000;

  srand(unsigned(time(0)));

  for (int i = 0; i < size; i++) {
    test[i] = rand() % 300;
  }

  for (int i = 125; i < size + 1; i *= 2) {


    cout << "\n\nSize: " << i << "\n";
    cout << "Before MergeSort: " << endl;
    for (int i = 0; i < size; i++) {
      cout << test[i] << " ";
    }

    test.sort(i);


    cout << "\n\nAfter MergeSort: " << endl;
    for (int i = 0; i < size; i++) {
      cout << test[i] << " ";
    }

  }
}
