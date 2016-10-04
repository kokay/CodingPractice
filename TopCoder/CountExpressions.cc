#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountExpressions {
public:
  int calcExpressions(int x, int y, int val) {
    vector<int> e({ x, x, y, y });
    sort(e.begin(), e.end());
    int count = 0;
    do {
      count += checkAll(e, vector<char>(), val);
    } while (next_permutation(e.begin(), e.end()));
    return count;
  }

private:
  int checkAll(vector<int> e, vector<char> op, int val) {
    if (op.size() == 3) {
      int calc = e[0];
      for (int i = 0; i < op.size(); ++i) {
        if (op[i] == '+') calc += e[i + 1];
        else if (op[i] == '-') calc -= e[i + 1];
        else if (op[i] == '*') calc *= e[i + 1];
      }
      if (calc == val) return 1;
      else return 0;
    }

    int count = 0;
    for (char o : string("+-*")) {
      op.push_back(o);
      count += checkAll(e, op, val);
      op.pop_back();
    }
    return count;
  }
};

//int main() {
//  CountExpressions countExpressions;
//  cout << countExpressions.calcExpressions(7, 8, 16) << endl;
//}