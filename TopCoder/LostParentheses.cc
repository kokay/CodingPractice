#include <iostream>
#include <sstream>

using namespace std;

class LostParentheses {
public:
  int minResult(string e) {
    stringstream ss(e);
    int total, num;
    ss >> total;
    char sign;
    bool findMinus = false;
    while (ss >> sign >> num) {
      if (sign == '-') findMinus = true;
      if (findMinus) total -= num;
      else total += num;
    }
    return total;
  }
};