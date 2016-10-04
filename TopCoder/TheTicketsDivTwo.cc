#include <iostream>
#include <deque>

using namespace std;

class TheTicketsDivTwo {
public:
  double find(int n, int m, int k) {
    deque<bool> placeOfTheFriend(n, false);
    placeOfTheFriend[m - 1] = true;
    return tryAll(placeOfTheFriend, k);
  }

private:
  double tryAll(deque<bool> placeOfTheFriend, int k) {
    if (placeOfTheFriend.size() == 1) return 1;
    if (k == 1) {
      if (placeOfTheFriend.front()) return 1 / 6.0;
      if (placeOfTheFriend[1]) return 5 / 6.0;
      return 0;
    }

    double prob = 0;
    if (placeOfTheFriend.front()) {
      prob += 1 / 6.0;
      placeOfTheFriend.push_back(placeOfTheFriend.front());
      placeOfTheFriend.pop_front();
      prob += tryAll(placeOfTheFriend, k - 1) * 1 / 2.0;
    }
    else {
      placeOfTheFriend.push_back(placeOfTheFriend.front());
      placeOfTheFriend.pop_front();
      prob += tryAll(placeOfTheFriend, k - 1) * 1 / 2.0;

      placeOfTheFriend.pop_back();
      prob += tryAll(placeOfTheFriend, k - 1) * 1 / 3.0;
    }
    return prob;
  }
};