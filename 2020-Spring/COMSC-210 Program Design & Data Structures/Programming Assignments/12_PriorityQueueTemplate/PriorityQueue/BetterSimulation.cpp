#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Queue.h"
#include "PriorityQueue.h"
#include "DynamicArray.h"

using namespace std;

struct Customer {
  char id;
  int arrivalTime;
};

struct serverInfo {
  Customer customer;
  bool status;
};

struct serviceEvent {
  int serverNum;
  int endTime;
};

bool operator<(const serviceEvent& a, const serviceEvent& b) {
  return a.endTime < b.endTime ? false : true;
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
  int server, wait, minService, maxService, clock;
  float arrival;//average arrival rate

  ifstream inputF;
  inputF.open("simulation.txt");
  if (!inputF.good()) cout << "I/O Error: File not found\n";

  string line;

  getline(inputF, line);
  server = stoi(line);

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
  cout << "Number of servers: " << server << "\n";
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
  DynamicArray<serverInfo> servers;
  PriorityQueue<serviceEvent> eventList;

  //clock time loop
  for (int time = 0;; time++) {


    for (int i = 0; i < server; i++) {
      if (eventList.top().endTime == time) {
        servers[eventList.top().serverNum].status = false;
        eventList.pop();
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
    for (int i = 0; i < server; i++) {
      if (servers[i].status == false && !waitLine.empty()) {
        Customer top = waitLine.front();
        waitLine.pop();

        servers[i].customer = top;
        servers[i].status = true;

        serviceEvent newCustomer;
        newCustomer.serverNum = i;
        newCustomer.endTime = time + (rand() % (maxService - minService + 1) + minService);
        
        eventList.push(newCustomer);
      }
    }

    //Output the summary
    //Output the content of waiting queue after the first server
    cout << "\n\n" << "Current Time: " << time << "\n\n";
    cout << "==================================================================================================\n";
    cout << "Server     Now Serving     Wait Line\n";
    cout << "======     ===========     ========================================================================\n";
    for (int i = 0; i < server; i++) {

      cout << "  " << i << "        " << "     ";//Initial line

      if (servers[i].status == false) {
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
        cout << servers[i].customer.id << "     ";
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
      for (int i = 0; i < server; i++) {//all servers idle
        if (servers[i].status) break;
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