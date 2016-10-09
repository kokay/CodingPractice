#include <iostream>

using namespace std;

class PikachuEasy {
public:
  string check (string word) {
    size_t idx = 0;
    while (idx < word.size()) {
      if (word.substr(idx, 2) == "pi") idx += 2;
      else if (word.substr(idx, 2) == "ka") idx += 2;
      else if (word.substr(idx, 3) == "chu") idx += 3;
      else return "No";
    }
    return "YES";
  }
};

//int main() {
//  PrefixCode p;
//  cout << p.isOne({ "10001", "011", "100", "001", "10" }
//  ) << endl;
//