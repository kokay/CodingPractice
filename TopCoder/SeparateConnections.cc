#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SeparateConnections {
public:
  int howMany(vector<string> mat) {
    vector<int> s;
    for (int i = 0; i < mat.size(); ++i) s.push_back(i);
    return tryAll(mat, s, 0);
  }
private:
  int tryAll(vector<string> mat, vector<int> unprocessed, int numConnected) {
    if (unprocessed.empty()) return numConnected;

    int count = 0;
    vector<int> nextSet = unprocessed;
    for (int i = 0; i < unprocessed.size(); ++i) {
      int node = unprocessed[i];
      nextSet.erase(find(nextSet.begin(), nextSet.end(), node));
      bool p = false;
      for (int j = 0; j < mat[node].size(); ++j) {
        if (mat[node][j] == 'Y') {

          p = true;
          count = max(count, tryAll(mat, nextSet, numConnected + 2));
        }
      }
      if(!p)
          count = max(count, tryAll(mat, nextSet, numConnected));
      nextSet.push_back(node);
    }

    return count;
  }
};