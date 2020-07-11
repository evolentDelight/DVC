// LabExercise7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "LabExercise7.h"

using namespace std;

struct Student
{
  string name;
  int studentID;
};

int main()
{

  Stack<Student> students;

  Student x = { "Joe", 1234567 };
  students.push(x);//size = 1

  x = {"Bob", 7654321};
  students.push(x);//size = 2

  cout << "Size: " << students.size() << "[Expected: 2]\n";

  cout << "Peek: " << students.peek().name << ", " << students.peek().studentID << "[Expected: Bob, 7654321]\n\n";

  students.pop();

  cout << "Size: " << students.size() << "[Expected: 1]\n";

  cout << "Peek: " << students.peek().name << ", " << students.peek().studentID << "[Expected: Joe, 1234567]\n";

  
}

