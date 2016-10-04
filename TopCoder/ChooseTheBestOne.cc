#include <iostream>
#include <vector>

using namespace std;

class ChooseTheBestOne {
public:
  int countNumber(int N) {
    vector<int> circle;
    for (int i = 1; i <= N; ++i)
      circle.push_back(i);

    long long pos = 0;
    for (long long t = 1; t < N; ++t) {
      pos = (pos + t * t * t - 1) % circle.size();
      circle.erase(circle.begin() + pos);
      if (pos > circle.size()) pos = 0;
    }
    return circle.front();
  }
};

//int main() {
//  ChooseTheBestOne c;
//  cout << c.countNumber(4999) << endl;
//}