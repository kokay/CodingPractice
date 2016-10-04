#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BinaryCardinality {
public:
  vector<int> arrange(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), sortCriteria);
    return numbers;
  }

private:
  static bool sortCriteria(const int n1, const int n2) {
    int num1 = getNumOnes(n1);
    int num2 = getNumOnes(n2);
    if (num1 == num2) return n1 < n2;
    else return num1 < num2;
  }

  static int getNumOnes(int n) {
    int count = 0;
    while (n) {
      count += (n & 1);
      n >>= 1;
    }
    return count;
  }
};