#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class BrokenClock {
public:
  int fewestClicks(string clockTime, string currentTime) {
    int checked[24][60];
    memset(checked, -1, sizeof(checked));

    int hour, minute;
    sscanf_s(clockTime.c_str(), "%d:%d", &hour, &minute);
    pair<int, int> start{ hour, minute };
    sscanf_s(currentTime.c_str(), "%d:%d", &hour, &minute);
    pair<int, int> end{ hour, minute };

    queue<pair<int, int>> q;
    q.push(start);
    checked[start.first][start.second] = 0;
    while (!q.empty()) {
      pair<int, int> cTime = q.front(); q.pop();
      if (cTime == end)
        return checked[cTime.first][cTime.second];

      int newMinute = (cTime.second + 1) % 60;
      if(checked[cTime.first][newMinute] == -1) {
        checked[cTime.first][newMinute] = checked[cTime.first][cTime.second] + 1;
        q.push({ cTime.first, newMinute });
      }

      int newHour = (cTime.first + 1) % 24;
      if(checked[newHour][newMinute] == -1) {
        checked[newHour][newMinute] = checked[cTime.first][cTime.second] + 1;
        q.push({ newHour, newMinute });
      }
    }
  }
};

//int main() {
//  BrokenClock b;
//  cout << b.fewestClicks("03:12", "04:15") << endl;
//}