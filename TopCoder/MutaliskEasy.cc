#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class MutaliskEasy {
public:
  int minimalAttacks(vector<int> x) {
    memset(memo, -1, sizeof(memo));
    memo[0][0][0] = 0;
    damege[0] = 9, damege[1] = 3, damege[2] = 1;

    if (x.size() == 1) return solve(x[0], 0, 0);
    if (x.size() == 2) return solve(x[0], x[1], 0);
    return solve(x[0], x[1], x[2]);
  }

private:
  int memo[61][61][61];
  int damege[3];

  int solve(int x, int y, int z) {
    if (memo[x][y][z] != -1) return memo[x][y][z];
    if (x == 0 && y == 0 && z == 0) return 0;

    memo[x][y][z] = 1000000;
    vector<int> order{ 0,1,2 };
    do {
      int newX = max(0, x - damege[order[0]]);
      int newY = max(0, y - damege[order[1]]);
      int newZ = max(0, z - damege[order[2]]);
      memo[x][y][z] = min(memo[x][y][z], solve(newX, newY, newZ) + 1);
    } while (next_permutation(order.begin(), order.end()));

    return memo[x][y][z];
  }
};