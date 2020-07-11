// COMSC 210
// Module 15 Assignment 15
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Node
{
  string name;

  bool isVisited;
  list<pair<int, double> > neighbors;
  int prev;
  double cost;
};

struct Terminus { //the path to a node and the cost of that path
  int index;
  int prev;
  double cost;
};

bool operator<(const Terminus& a, const Terminus& b) {
  return b.cost < a.cost;//reverse logic for lo-to-hi
}

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Node>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over neighbors
// TO DO -- write this function
  for (int i = 0; i < database.size(); i++) {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  priority_queue<Terminus> todo;//to-do list

  Terminus startn;//Start Node
  startn.index = iStart;
  startn.cost = 0;
  startn.prev = -1;

  todo.push(startn);

  while (!todo.empty()) {
    Terminus NUC = todo.top();//Node Under Consideration
    todo.pop();

    if (database[NUC.index].isVisited) continue;

    database[NUC.index].isVisited = true;
    database[NUC.index].cost = NUC.cost;
    database[NUC.index].prev = NUC.prev;
    
    if (NUC.index == iEnd) break;

    for (it = database[NUC.index].neighbors.begin(); it != database[NUC.index].neighbors.end(); ++it) {

      Terminus neighbor;
      neighbor.index = it->first;
      neighbor.prev = NUC.index;
      neighbor.cost = it->second + NUC.cost;

      todo.push(neighbor);
    }
  }
  int index = iEnd;
  result.second = database[index].cost;
  while (index != iStart) {
    result.first.push(index);
    index = database[index].prev;
  }
  result.first.push(iStart);

  return result;
}

int main()
{

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  cout << "Cheapest Route\n"
    << "File: " << __FILE__ << "\n\n";

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Node> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add nodes for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = { fromCity };
      database.push_back(fromNode);
    }
    iFromNode = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = { toCity };
      database.push_back(toNode);
    }
    iToNode = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromNode].neighbors.push_back(pair<int, double>(iToNode, edgeCost));
    database[iToNode].neighbors.push_back(pair<int, double>(iFromNode, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    cout << "|\nRoute=";
    pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
    for (; !result.first.empty(); result.first.pop())
      cout << '-' << database[result.first.top()].name;
    cout << "\nTotal miles: " << result.second;
    cout << endl << endl;
  }
}
