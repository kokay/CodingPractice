#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Quorum {
public:
  int count(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());

    int count = 0;
    for (int i = 0; i < k; ++i)
      count += arr[i];
    return count;
  }
};