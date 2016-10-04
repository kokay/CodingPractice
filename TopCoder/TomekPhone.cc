#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class TomekPhone {
public:
  int minKeystrokes(vector<int> frequencies, vector<int> keySize) {
    sort(frequencies.begin(), frequencies.end(), greater<int>());
    vector<int> layer = makeLayer(keySize);
    if (layer.size() < frequencies.size()) return -1;
    int count = 0;
    for (int i = 0; i < frequencies.size(); ++i)
      count += frequencies[i] * layer[i];

    return count;
  }

  vector<int> makeLayer(vector<int> keySize) {
    vector<int> layer;
    for (int i = 0; i < keySize.size(); ++i) {
      for (int j = 1; j <= keySize[i]; ++j)
        layer.push_back(j);
    }
    sort(layer.begin(), layer.end());
    return layer;
  }
};