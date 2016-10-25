#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class FriendScore {
public:
  int score;
  int highestScore(vector<string> friends) {
    score = 0;
    for (int i = 0; i < friends.size(); ++i)
      score = max(score, bfs(friends, i));
    return score;
  }

  int bfs(vector<string>& friends, int start) {
    vector<int> distance(friends.size(), -1);
    distance[start] = 0;
    queue<int> q;
    q.push(start);

    int count = 0;  
    while (!q.empty()) {
      int v = q.front(); q.pop();

      if (distance[v] + 1 > 2) continue;
      for (int i = 0; i < friends.size(); ++i) {
        if (friends[v][i] == 'N' || v == i || distance[i] != -1) continue;
        q.push(i);
        distance[i] = distance[v] + 1;
        count++;
      }
    }
    return count;
  }
private:
};


//int main() {
//  FriendScore fs;
//  cout << fs.highestScore(
//  { "NYNNN",
//    "YNYNN",
//    "NYNYN",
//    "NNYNY",
//    "NNNYN" }
//  ) << endl;
//}