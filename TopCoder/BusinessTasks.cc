#include <iostream>
#include <vector>

using namespace std;

class BusinessTasks {
public:
  string getTask(vector<string> list, int n) {
    int pos = 0;
    while (list.size() != 1) {
      pos = (pos + n - 1) % list.size();
      list.erase(list.begin() + pos);
    }
    return list.front();
  }
};