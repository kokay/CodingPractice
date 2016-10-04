#include <iostream>

using namespace std;

class Dubs {
public:
  long count(long L, long R) {
    long c = 0;
    while (1) {
      c += (L % 10) == ((L / 10) % 10);
      if (L % 100 == R % 100) break;
      L++;
    }
    return c + ((R - L) / 100) * 10;
  }
};