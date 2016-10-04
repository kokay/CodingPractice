#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WhiteHats {
public:
  int whiteNumber(vector<int> c) {
    int n = c.size();
    sort(c.begin(), c.end());
    for (int w = 0; w <= n; w++) {
      vector<int> d;
      for (int i = 0; i < w; i++)
        d.push_back(w - 1);

      for (int i = w; i < n; i++) 
        d.push_back(w);

      sort(d.begin(), d.end());
      if (c == d) return w;
    }
    return -1;
  }
};


//int main() {
//  WhiteHats w;
//  cout << w.whiteNumber({ 4,4,4,4,4 }) << endl;
//}