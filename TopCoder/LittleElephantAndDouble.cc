#include <iostream>
#include <vector>

using namespace std;
class LittleElephantAndDouble {
public:
  string getAnswer(vector<int> A) {
    for (int i = 0; i < A.size(); ++i) {
      while (!(A[i] & 1))
        A[i] >>= 1;
    }

    int test = A[0];
    for (int i = 1; i < A.size(); ++i)
      if (test != A[i]) return "NO";
    return "YES";
  }
};
