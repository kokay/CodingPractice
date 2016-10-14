#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SwimmersDelight {
public:
  int longestJump(vector<int> x, vector<int> y) {
    int longest = 100;
    longest = min(longest, s1t(x, y));
    longest = min(longest, s12t(x, y));
    longest = min(longest, s2t(x, y));
    longest = min(longest, s21t(x, y));
    return longest;
  }

  int getDistance(int x1, int x2, int y1, int y2) {
    return round(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
  }

  int s1t(vector<int> x, vector<int> y) {
    int longest = 0;
    longest = max(longest, getDistance(0, x[0], y[0], y[0]));
    longest = max(longest, getDistance(x[0], 10, y[0], y[0]));
    return longest;
  }

  int s12t(vector<int> x, vector<int> y) {
    int longest = 0;
    longest = max(longest, getDistance(0, x[0], y[0], y[0]));
    longest = max(longest, getDistance(x[0], x[1], y[0], y[1]));
    longest = max(longest, getDistance(x[1], 10, y[1], y[1]));
    return longest;
  }

  int s2t(vector<int> x, vector<int> y) {
    int longest = 0;
    longest = max(longest, getDistance(0, x[1], y[1], y[1]));
    longest = max(longest, getDistance(x[1], 10, y[1], y[1]));
    return longest;
  }

  int s21t(vector<int> x, vector<int> y) {
    int longest = 0;
    longest = max(longest, getDistance(0, x[1], y[1], y[1]));
    longest = max(longest, getDistance(x[1], x[0], y[1], y[0]));
    longest = max(longest, getDistance(x[0], 10, y[0], y[0]));
    return longest;
  }
};