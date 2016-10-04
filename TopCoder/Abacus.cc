#include <iostream>
#include <vector>

using namespace std;

class Abacus {
public:
  vector<string> add(vector<string> original, int val) {
    int originalValue = read(original);
    return makeNew(originalValue + val);
  }

private:
  int read(vector<string>& theOne){
    int value = 0;
    for (int i = 0; i < theOne.size(); ++i) {
      value += 9 - theOne[i].find("---");
      value *= 10;
    }
    return value / 10;
  }

  vector<string> makeNew(int value) {
    vector<string> newOne;
    int count = 6;
    while (value > 0) {
      int num = value % 10;
      value /= 10;
      newOne.push_back(string(9 - num, 'o') + string(3, '-') + string(num, 'o'));
      --count;
    }

    for (int i = 0; i < count; ++i) 
      newOne.push_back("ooooooooo---");

    return vector<string>(newOne.rbegin(), newOne.rend());
  }
};
