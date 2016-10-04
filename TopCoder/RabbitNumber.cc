#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

class RabbitNumber {
public:
  int theCount(int low, int high) {
    int count = 0;
    for (long long i = low; i <= high; ++i) {
      count += s(i * i) == (s(i) * s(i));
    }
    return count;
  }

private:
  long long s(long long num) {
    long long sum = 0;
    while (num) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
};

//int main() {
//  RabbitNumber rabbitNumber;
//  cout << rabbitNumber.theCount(1, 999999999) << endl;
//}