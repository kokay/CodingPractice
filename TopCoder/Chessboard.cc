#include <iostream>
#include <string>

using namespace std;

class Chessboard {
public:
  string changeNotation(string cell) {
    if (!isdigit(cell[0]))
      return to_string((cell[0] - 'a' + 1) + (cell[1] - '1') * 8);

    int num = (stoi(cell) - 1);
    return (char)((num % 8) + 'a') + to_string(num / 8 + 1);
  }
};