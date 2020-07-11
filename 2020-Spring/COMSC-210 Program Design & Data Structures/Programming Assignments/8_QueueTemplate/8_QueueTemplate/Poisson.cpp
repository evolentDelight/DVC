#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int getRandomNumberofArrivals(double averageArrivalRate) {
  int arrivals = 0;
  double ProbOfArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX; (randomValue -= ProbOfArrivals) > 0.0;
    ProbOfArrivals *= averageArrivalRate / static_cast<double>(++arrivals));

  return arrivals;
}

int main(){
    for( int i = 0; i < 50; i++){
        cout << getRandomNumberofArrivals(2.5) << endl;
    }
}