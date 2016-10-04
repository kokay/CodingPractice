#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

class ReportAccess {
public:
  vector<string> whoCanSee(vector<string> userNames, vector<string> allowedData, vector<string> reportData) {
    vector<string> names;
    for (int i = 0; i < userNames.size(); ++i) {
      istringstream ss(allowedData[i]);
      vector<string> allowed((istream_iterator<string>(ss)), {});

      bool canAccess = true;
      for (int j = 0; j < reportData.size(); ++j) {
        if (find(allowed.begin(), allowed.end(), reportData[j]) == allowed.end()) {
          canAccess = false; break;
        }
      }
      if (canAccess) names.push_back(userNames[i]);
    }

    sort(names.begin(), names.end());
    return names;
  }
};