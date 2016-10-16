#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class EllysCoprimesDiv2 {
public:
  int getCount(vector<int> numbers) {
    memset(memo, -1, sizeof(memo));
    sort(numbers.begin(), numbers.end());
    int count = 0;
    for (int i = 0; i < numbers.size() - 1; ++i)
      count += bfs(numbers[i], numbers[i + 1]);
    return count;
  }

private:
  int memo[100001];

  int bfs(int n1, int n2) {
    memo[n1] = 0;
    queue<int> q;
    q.push(n1);
    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (gcd(t, n2) == 1) return memo[t];
      for (int i = t; i < n2; ++i) {
        if (memo[i] == -1 && (gcd(t, i) == 1)) {
          memo[i] = memo[t] + 1;
          q.push(i);
        }
      }
    }
    return 0;
  }

  int gcd(int n1, int n2) {
    if (n2 == 0) return n1;
    return gcd(n2, n1 % n2);
  }
};
//
//int main() {
//  EllysCoprimesDiv2 e;
//  cout << e.getCount(
//  { 55780, 44918, 55653, 4762, 41536, 40083, 79260, 7374, 24124, 91858, 7856,
//    12999, 64025, 12706, 19770, 71495, 32817, 79309, 53779, 8421, 97984, 34586,
//    893, 64549, 77792, 12143, 52732, 94416, 54207, 51811, 80845, 67079, 14829,
//    25350, 22976, 23932, 62273, 58871, 82358, 13283, 33667, 64263, 1337, 42666 }
//  ) << endl;
//}
