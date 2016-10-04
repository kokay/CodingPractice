#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

class DivisorInc {
public:
  int countOperations(int N, int M) { //DFS
    vector<int> distance(M + 1, -1);
    distance[N] = 0;
    queue<int> q;
    q.push(N);
    
    while (!q.empty()) {
      int num = q.front();
      q.pop();

      if (num == M) break;

      for (int divisor : getDivisor(num)) {
        if (num + divisor <= M && distance[num + divisor] == -1) {
          q.push(num + divisor);
          distance[num + divisor] = distance[num] + 1;
        }
      }
    }
    return distance[M];
  }

private:
  vector<int> getDivisor(int num) {
    vector<int> divisors;
    for(int divisor = 2; divisor <= sqrt(num);++divisor) {
      if (num % divisor == 0) {
        divisors.push_back(num / divisor);
        divisors.push_back(divisor);
      }
    }
    return divisors;
  }
};

//int main() {
//  DivisorInc divisorInc;
//  cout << divisorInc.countOperations(4, 24) << endl;
//}