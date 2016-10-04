#include <iostream>
#include <vector>
#include <sstream>
#include <string.h>

using namespace std;

class ParallelepipedUnion {
public:
  int getVolume(vector<string> parallelepipeds) {
    bool geo[101][101][101];
    memset(geo, false, sizeof(geo));

    setObject(parallelepipeds[0], geo);
    setObject(parallelepipeds[1], geo);

    int volume = 0;
    for (int i = 1; i <= 100; ++i) {
      for (int j = 1; j <= 100; ++j)
        for (int k = 1; k <= 100; ++k)
          volume += geo[i][j][k];
    }
    return volume;
  }

private:
  void setObject(string object, bool geo[101][101][101]) {
    stringstream ss(object);
    int x1, x2, y1, y2, z1, z2;
    ss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    for (int i = x1; i < x2; ++i) {
      for (int j = y1; j < y2; ++j)
        for (int k = z1; k < z2; ++k)
          geo[i][j][k] = true;
    }
  }
};