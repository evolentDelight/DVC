
#include <iostream>
#include <cstdlib>
#include <vector>

#include "Stack.h"

using namespace std;


void Output(Stack<double> calc) {
  Stack<double> copy = calc;
  vector<double> output;

  for (int i = 0; i < calc.size(); i++) {
    output.push_back(copy.peek());
    copy.pop();
  }

  for (int i = output.size() - 1; i >= 0; i--) {
    cout << output[i] << " ";
  }
}

int main() {

  //Programmer ID:
  cout << "----------------------------------------------------------------------------------------------------\n";
  cout << "Programmer:\t\tBenjamin Kwon\n";
  cout << "Programmer's ID:\t1162854\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "----------------------------------------------------------------------------------------------------\n\n";

  Stack<double> calc;
  Stack<string> operand;//+, -, /, *

  string buf;
  double value, first, second, result;

  cout << "Enter Number or Operand or Enter q or Q to quit\n\n";

  while (1) {

    cout << "Contents: ";
    if (calc.peek() != 0) Output(calc);

    cin >> buf;
    if (buf[0] == 'q' || buf[0] == 'Q') break;

    if ((buf[0] == '+' || buf[0] == '-' || buf[0] == '*' || buf[0] == '/')){
      if (!calc.empty() && !(calc.size() < 2)) {

        second = calc.peek();
        calc.pop();

        first = calc.peek();
        calc.pop();

        switch (buf[0]) {
        case '+':
          result = first + second;
          calc.push(result);
          break;
        case '-':
          result = first - second;
          if (result == 0) {
            break;
          }
          calc.push(result);
          break;
        case '*':
          result = first * second;
          calc.push(result);
          break;
        case '/':
          result = first / second;
          calc.push(result);
          break;
        }

      }
    }
    else {
      value = atof(buf.c_str());
      if (value != 0) {
        calc.push(value);
      }
    }

  }

  cout << "\n\nRPNCalculator Ended\n\n";
}