#include <ctime>
#include <iostream>
#include <cassert>

using namespace std;

int main() {

  double* array1 = new double[5000];
  double* array2 = new double[10000];
  double* array3 = new double[20000];
  double* array4 = new double[40000];

  srand(time(0));
  rand();

  double O;//
  double temp;

  //Fill double array
  for (int i = 0; i < 5000; i++) {
    array1[i] = (double)rand() / (double(RAND_MAX));
  }
  for (int i = 0; i < 10000; i++) {
    array2[i] = (double)rand() / (double(RAND_MAX));
  }
  for (int i = 0; i < 20000; i++) {
    array3[i] = (double)rand() / (double(RAND_MAX));
  }
  for (int i = 0; i < 40000; i++) {
    array4[i] = (double)rand() / (double(RAND_MAX));
  }

  for (int i = 0; i < 4; i++) {

    //Start the timer
    clock_t startTime = clock();

    if (i == 0) {
      for (int j = 0; j < 5000 - 1; j++) {
        for (int k = 0; k < 5000 - 1 - j; k++) {
          if (array1[k + 1] < array1[k]) {
            temp = array1[k];
            array1[k] = array1[k + 1];
            array1[k + 1] = temp;
          }
        }
      }
    }
    else if (i == 1) {
      for (int j = 0; j < 10000 - 1; j++) {
        for (int k = 0; k < 10000 - 1 - j; k++) {
          if (array2[k + 1] < array2[k]) {
            temp = array2[k];
            array2[k] = array2[k + 1];
            array2[k + 1] = temp;
          }
        }
      }
    }
    else if (i == 2) {
      for (int j = 0; j < 20000 - 1; j++) {
        for (int k = 0; k < 20000 - 1 - j; k++) {
          if (array3[k + 1] < array3[k]) {
            temp = array3[k];
            array3[k] = array3[k + 1];
            array3[k + 1] = temp;
          }
        }
      }
    }
    else if (i == 3) {
      for (int j = 0; j < 40000 - 1; j++) {
        for (int k = 0; k < 40000 - 1 - j; k++) {
          if (array4[k + 1] < array4[k]) {
            temp = array4[k];
            array4[k] = array4[k + 1];
            array4[k + 1] = temp;
          }
        }
      }
    }

    //Stop and Record the timer
    clock_t endTime = clock();
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    //Output
    if (i == 0) {//1st output
      O = elapsedSeconds;
      cout << O << " (expected O(n squared)) for n = 5000" << endl;
    }
    else if (i == 1) {//2nd
      cout << elapsedSeconds << " (expected " << (O * 4) << ") for n = 10000" << endl;
    }
    else if (i == 2) {//3rd
      cout << elapsedSeconds << " (expected " << (O * 16) << ") for n = 20000" << endl;
    }
    else if (i == 3) {//4th
      cout << elapsedSeconds << " (expected " << (O * 64) << ") for n = 40000" << endl;
    }

    for (int i = 1; i < 5000; i++) assert(array1[i - 1] <= array1[i]);
    for (int i = 1; i < 10000; i++) assert(array2[i - 1] <= array2[i]);
    for (int i = 1; i < 20000; i++) assert(array3[i - 1] <= array3[i]);
    for (int i = 1; i < 40000; i++) assert(array4[i - 1] <= array4[i]);

  }

  delete []array1;
  delete[] array2;
  delete[] array3;
  delete[] array4;
}