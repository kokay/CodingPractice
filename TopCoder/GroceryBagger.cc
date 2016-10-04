#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class GroceryBagger {
public:
  int minimumBags(int strength, vector<string> itemType) {
    int count = 0;
    map<string, int> memo;
    for (string& item:itemType) {
      if (memo.find(item) == memo.end()) {
        memo.insert({ item, 1 });
        count++;
      }
      else if (memo[item] == strength) {
        memo[item] = 1;
        count++;
      }
      else {
        memo[item]++;
      }
    }
    return count;
  }
};