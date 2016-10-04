#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Stitch {
public:
  vector<string> stitch(vector<string> A, vector<string> B, int overlap) {
    vector<string> ret(A.size());
    for (int i = 0; i < A.size(); ++i) {
      ret[i] += A[i].substr(0, A[i].size() - overlap);

      for (int j = 1; j <= overlap; ++j) {
        int idxA = A[i].size() - overlap + j - 1;
        int idxB = j - 1;
        ret[i] += round(((overlap + 1 - j) * A[i][idxA] + (j * B[i][idxB])) / double((overlap + 1)));
      }

      ret[i] += B[i].substr(overlap);
    }
    return ret;
  }
};