#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>

using namespace std;

class Xylophone {
public:
  int countKeys(vector<int> keys) {
    set<int> s;
    for (int i = 0; i < keys.size(); ++i) {
      s.insert(keys[i] % 7);
    }
    return s.size();
  }
};

//int main() {
//
//}