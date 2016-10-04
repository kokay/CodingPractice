#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
  int frequency;
  char original;
  char encoded;
  static bool sortCriteria(const Info& i1, const Info& i2) {
    if (i1.frequency == i2.frequency) return i1.encoded < i2.encoded;
    return i1.frequency > i2.frequency;
  }
};

class Decipher {
public:
  vector<string> decipher(vector<string> encoded, string frequencyOrder) {
    vector<Info> frequencyTable;
    for (int i = 0; i < encoded.size(); ++i) {
      for (int j = 0; j < encoded[i].size(); ++j) {
        if (encoded[i][j] == ' ') continue;
        int idx = findIdx(frequencyTable, encoded[i][j]);
        if (idx == -1) frequencyTable.push_back({ 1,' ', encoded[i][j] });
        else frequencyTable[idx].frequency++;
      }
    }
    sort(frequencyTable.begin(), frequencyTable.end(), Info::sortCriteria);
    for (int i = 0; i < frequencyTable.size(); ++i)
      frequencyTable[i].original = frequencyOrder[i];
    
    for (int i = 0; i < encoded.size(); ++i) {
      for (int j = 0; j < encoded[i].size(); ++j) {
        if (encoded[i][j] == ' ') continue;
        int idx = findIdx(frequencyTable, encoded[i][j]);
        encoded[i][j] = frequencyTable[idx].original;
      }
    }
    return encoded;
  }

private:
  int findIdx(vector<Info>& frequencyTable, char encoded) {
    for (int i = 0; i < frequencyTable.size(); ++i)
      if (frequencyTable[i].encoded == encoded) return i;
    return -1;
  }
};