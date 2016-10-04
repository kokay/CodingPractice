#include <iostream> 
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Info {
  string name;
  int gold, silver, bronze;
  static bool sortCriteria(const Info i1, const Info i2) {
    if (i1.gold != i2.gold) return i1.gold > i2.gold;
    if (i1.silver != i2.silver) return i1.silver > i2.silver;
    if (i1.bronze != i2.bronze) return i1.bronze > i2.bronze;
    return i1.name < i2.name;
  }

  bool operator==(const string name) {
    return this->name == name;
  }
};

class MedalTable {
public:
  vector<string> generate(vector<string> results) {
    string gold, silver, bronze;
    vector<Info> infos;
 
    for (string result : results) {
      stringstream ss(result);
      ss >> gold >> silver >> bronze;
      auto it = find(infos.begin(), infos.end(), gold);
      if (it != infos.end()) it->gold++;
      else infos.push_back({ gold, 1, 0, 0 });

      it = find(infos.begin(), infos.end(), silver);
      if (it != infos.end()) it->silver++;
      else infos.push_back({ silver, 0, 1, 0 });

      it = find(infos.begin(), infos.end(), bronze);
      if (it != infos.end()) it->bronze++;
      else infos.push_back({ bronze, 0, 0, 1 });
    }

    sort(infos.begin(), infos.end(), Info::sortCriteria);
    vector<string> ret;
    for (Info info : infos)
      ret.push_back(info.name + " " + to_string(info.gold) + " " + 
        to_string(info.silver) + " " + to_string(info.bronze));

    return ret;
  }
};