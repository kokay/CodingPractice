#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>


using namespace std;

class Cafeteria {
public:
  string latestTime(vector<int> offset, vector<int> walkingTime, vector<int> drivingTime) {
    int time = 0;
    for (int i = 0; i < offset.size(); ++i) {
      int localTime = 870;
      localTime -= drivingTime[i];
      while ((localTime % 10) != offset[i]) --localTime; 
      localTime -= walkingTime[i];
      time = max(time, localTime);
    }
    
    int hour = time / 60;
    if (hour >= 13) hour %= 12;
    int minites = time % 60;
    ostringstream ss;
    ss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minites;
    return ss.str();
  }
};