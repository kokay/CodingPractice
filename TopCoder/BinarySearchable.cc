#include <iostream>
#include <vector>

using namespace std;

class BinarySearchable {
public:
  int howMany(vector<int> sequence) {
    int count = 0;
    for (int i = 0; i < sequence.size(); ++i) {
      bool serchable = true;
      for (int j = 0; j < sequence.size(); ++j) {
        if ((i < j && sequence[i] > sequence[j] ) || (i > j && sequence[i] < sequence[j])) {
          serchable = false;
          break;
        }
      }
      count += serchable;
    }
    return count;
  }
};