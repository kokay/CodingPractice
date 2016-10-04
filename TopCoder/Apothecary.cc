#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Apothecary {
public:
  vector<int> balance(int W) {
    set<int> used;
    int leftTotal = W;
    int rightTotal = getClosestBiggerWeight(W);
    used.insert(rightTotal);

    int theWeight = 0;
    while (leftTotal != rightTotal) {
      if (leftTotal > rightTotal) {
        theWeight = findWeight(leftTotal - rightTotal, used);
        rightTotal += theWeight;
        used.insert(theWeight);
      }
      else {
        theWeight = findWeight(rightTotal - leftTotal, used);
        leftTotal += theWeight;
        used.insert(-theWeight);
      }
    }
    return vector<int>(used.begin(), used.end());
  }

private:
  int findWeight(int diff, set<int>& used) {
    int numBigger = getClosestBiggerWeight(diff);
    while (used.find(numBigger) != used.end() || used.find(-numBigger) != used.end())
      numBigger *= 3;

    int numSmaller = numBigger / 3;
    while (used.find(numSmaller) != used.end() || used.find(-numSmaller) != used.end())
      numSmaller /= 3;

    int diffBigger = numBigger - diff;
    int diffSmaller = diff - numSmaller;

    if (diffBigger < diffSmaller)
      return numBigger;
    else
      return numSmaller;
  }

  int getClosestBiggerWeight(int W) {
    int num = 1;
    while (num < W) {
      num *= 3;
    }
    return num;
  }
};

//int main() {
//  Apothecary apothecary;
//  for (int weight : apothecary.balance(1000000)) {
//    cout << weight << endl;
//  }
//}