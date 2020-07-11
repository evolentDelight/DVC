#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Queue.h"
#include "DynamicArray.h"

using namespace std;

struct Customer {
  char id;
  int arrivalTime;
  int endTime;
};

int getRandomNumberofArrivals(double averageArrivalRate) {
  int arrivals = 0;
  double ProbOfArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX; (randomValue -= ProbOfArrivals) > 0.0;
    ProbOfArrivals *= averageArrivalRate / static_cast<double>(++arrivals));

  return arrivals;
}
int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  srand(time(0));
  rand();

//Declaration
  int servers, wait, minService, maxService, clock;
  float arrival;//average arrival rate

  ifstream inputF;
  inputF.open("simulation.txt");
  if (!inputF.good()) cout << "I/O Error: File not found\n";

  string line;

  getline(inputF, line);
  servers = stoi(line);

  getline(inputF, line);
  arrival = stof(line);

  getline(inputF, line);
  wait = stoi(line);

  getline(inputF, line);
  minService = stoi(line);

  getline(inputF, line);
  maxService = stoi(line);

  getline(inputF, line);
  clock = stoi(line);

  inputF.close();

//Output the inputted values
  cout << "\n\n";
  cout << "Number of servers: " << servers << "\n";
  cout << "Customer arrival rate: " << arrival << " per minute, for " << clock << " minutes" << "\n";
  cout << "Maximum queue length: " << wait << "\n";
  cout << "Minimum service time: " << minService << "\n";
  cout << "Maximum service time: " << maxService << "\n";
  cout << "\n";

//Declaration #2
  char firstID = 'A';//first ID
  char finalID = 'Z';//last ID to be used
  int count = 0;


  Queue<Customer> waitLine;
  DynamicArray<Customer> servingNow;
  DynamicArray<bool> serverStatus;
  
//clock time loop
  for (int time = 0;; time++) {

  //Update the availability of each server
    for (int i = 0; i < servers; i++) {
      if (serverStatus[i] == true) {
        if (servingNow[i].endTime == time) {
          serverStatus[i] = false;
        }
      }
    }

  //Handle new arrivals - can be turned away if wait queue is at max length
    if (time < clock) {
      int arrivalNum = getRandomNumberofArrivals(arrival);
      for (int i = 0; i < arrivalNum; i++) {
        if (waitLine.size() < wait) {

          Customer newCust;

          if (firstID + count > finalID) {
            newCust.id = firstID;
            count = 0;
          }
          else {
            newCust.id = firstID + count;
          }

          newCust.arrivalTime = time;

          waitLine.push(newCust);

          count++;

        }
      }
    }

  //for idle servers, move customer from wait queue and begin service
    for (int i = 0; i < servers; i++) {
      if (serverStatus[i] == false && !waitLine.empty()) {
        Customer top = waitLine.front();
        waitLine.pop();

        servingNow[i] = top;
        serverStatus[i] = true;

        servingNow[i].endTime = time + (rand()%(maxService - minService + 1)+minService);
      }
    }

  //Output the summary
  //Output the content of waiting queue after the first server
    cout << "\n\n" << "Current Time: " << time << "\n\n";
    cout << "==================================================================================================\n";
    cout << "Server     Now Serving     Queue\n";
    cout << "======     ===========     ========================================================================\n";
    for (int i = 0; i < servers; i++) {

      cout << "  " << i << "        " << "     ";//Initial line

      if (serverStatus[i] == false) {
        if (i == 0) {//Output the wait line
          cout << "  ";
          Queue<Customer> copy = waitLine;
          for (int i = 0; i < waitLine.size(); i++) {
            cout << copy.front().id;
            copy.pop();
          }
        }
        cout << "\n";
      }
      else {
        cout << servingNow[i].id << "     ";
        if (i == 0) {//Output the wait line
          cout << "       ";
          Queue<Customer> copy = waitLine;
          for (int i = 0; i < waitLine.size(); i++) {
            cout << copy.front().id;
            copy.pop();
          }
        }
        cout << "\n";
      }
    }

  //If clock is up, then break
    bool end = false;
    if (waitLine.size() == 0 && time >= clock) {//reach time and no waitings
      for (int i = 0; i < servers; i++) {//all servers idle
        if (serverStatus[i]) break;
        end = true;
      }
    }

    if (end) {
      cout << "\nSimulation end!\n";
      break;
    }
    
    cout << "\nPress enter to continue... \n";
    cin.get();

  }

}