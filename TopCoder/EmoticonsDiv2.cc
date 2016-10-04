#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class EmoticonsDiv2 {
public:
  int printSmiles(int smiles) {
    vector<int> best(smiles + 1, 100000);
    best[1] = 0;

    for (int i = 1; i * 2 <= smiles; ++i) {
      for (int j = 2;  i * j <= smiles; ++j)
        best[i * j] = min(best[i * j], best[i] + j);
    }
    return best[smiles];
  }
};