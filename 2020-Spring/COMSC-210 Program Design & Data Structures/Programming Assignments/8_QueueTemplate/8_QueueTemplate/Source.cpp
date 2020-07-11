#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  srand(time(0));
  rand();

  for (int i = 0; i < 100; i++) {
    std::cout << rand() % (8) + 3 << "\n";
  }
}