#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class FairWorkload {
public:
  int MAX = 1000000;
  int getMostWork(vector<int> folders, int workers) {
    theMax = MAX;
    checkAll(folders, vector<int>(workers, 0), 0, 0);
    return theMax;
  }
  
private:
  void checkAll(vector<int>& folders, vector<int> workerLoad, int workerIdx, int divisor) {
    if (workerIdx == workerLoad.size() - 1) {
      workerLoad[workerIdx] = accumulate(folders.begin() + divisor, folders.end(), 0);
      theMax = min(theMax, *max_element(workerLoad.begin(), workerLoad.end()));
      return;
    }

    int lastPlace = folders.size() - (workerLoad.size() - 1 - workerIdx);
    for (int i = divisor; i <= lastPlace; ++i) {
      workerLoad[workerIdx] += folders[i];
      checkAll(folders, workerLoad, workerIdx + 1, i + 1);
    }
  }

  int theMax;
};

//int main() {
//  FairWorkload fairWorkload;
//  cout << fairWorkload.getMostWork({ 759, 746, 460, 92, 283, 739, 502, 501, 980, 86, 212, 276, 306, 571, 940 }, 8) << endl;
//}