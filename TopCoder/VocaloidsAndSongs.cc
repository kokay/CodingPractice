#include <iostream>
#include <string.h>

using namespace std;

class VocaloidsAndSongs {
public:
  int count(int S, int gumi, int ia, int mayu) {
    memset(memo, -1, sizeof(memo));
    MOD = 1000000007;
    return tryAll(S, gumi, ia, mayu);
  }

private:
  long long memo[51][51][51][51];
  int MOD;

  long long tryAll(int S, int gumi, int ia, int mayu) {
    if (S == 0) {
      if (gumi + ia + mayu == 0) return 1;
      return 0;
    }
    if (gumi + ia + mayu < S) return 0;
    if (memo[S][gumi][ia][mayu] != -1) return memo[S][gumi][ia][mayu];

    memo[S][gumi][ia][mayu] = 0;
    if (gumi) memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi - 1, ia, mayu) % MOD;
    if (ia)   memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi, ia - 1, mayu) % MOD;
    if (mayu) memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi, ia, mayu - 1) % MOD;
    if (gumi && ia)   memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi - 1, ia - 1, mayu) % MOD;
    if (gumi && mayu) memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi - 1, ia, mayu - 1) % MOD;
    if (ia && mayu)   memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi, ia - 1, mayu - 1) % MOD;
    if (gumi && ia && mayu)   memo[S][gumi][ia][mayu] += tryAll(S - 1, gumi - 1, ia - 1, mayu - 1) % MOD;
    return memo[S][gumi][ia][mayu];
  }
};