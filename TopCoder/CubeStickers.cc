#include <iostream>
#include <vector>
#include <map>

using namespace std;

class CubeStickers {
public:
  string isPossible(vector<string> sticker) {
    map<string, int> memo;
    for (string color : sticker) {
      if (memo.find(color) == memo.end()) {
        memo.insert({ color, 1 });
      }
      else if(memo[color] < 2) {
        memo[color]++;
      }
    }

    int count = 0;
    for (pair<string, int> p : memo)
      count += p.second;

    return  count >= 6 ? "YES" : "NO";
  }
};