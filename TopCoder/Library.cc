#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

class Library {
public:
  int documentAccess(vector<string> records, vector<string> userGroups, vector<string> roomRights) {
    set<string> memo;
    string docName, room, group;
    for (string record : records) {
      stringstream ss(record);
      ss >> docName >> room >> group;
      if (find(userGroups.begin(), userGroups.end(), group) != userGroups.end() &&
          find(roomRights.begin(), roomRights.end(), room) != roomRights.end())
        memo.insert(docName);
    }
    return memo.size();
  }
};