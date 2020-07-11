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
  list<pair<int, double> > neighbors;// toNeighbor, edgecost
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Node>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over neighbors
// TO DO -- write this function
  //All Nodes - set cost to zero, prev = -1 and isVisited=false
  for (int i = 0; i < database.size(); i++) {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  queue<int> todo;//to-do list

  //Mark start node as visited and store onto to-do list
  database[iStart].isVisited = true;
  todo.push(iStart);

  while (!todo.empty()) {
    int NUC = todo.front();//Node Under Consideration
    todo.pop();

    for (it = database[NUC].neighbors.begin(); it != database[NUC].neighbors.end(); ++it) {
      
      if (database[(*it).first].isVisited) continue; 

      database[(*it).first].cost = 1 + database[NUC].cost;
      database[(*it).first].prev = NUC;
      
      todo.push((*it).first);
      database[(*it).first].isVisited = true;

      if ((*it).first == iEnd) {
        int size = todo.size();
        for (int i = 0; i < size; i++) {
          todo.pop();
        }
        break;
      }
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

  cout << "Shortest Route\n"
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
    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    for (; !result.first.empty(); result.first.pop())
      cout << '-' << database[result.first.top()].name;
    cout << "\nTotal edges: " << result.second;
    cout << endl << endl;
  }
}
