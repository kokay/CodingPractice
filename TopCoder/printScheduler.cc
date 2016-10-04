#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class PrintScheduler {
public:
  string getOutput(vector<string> threads, vector<string> slices) {
    string output;
    
    vector<int> idxs(threads.size(), 0);
    for (int i = 0; i < slices.size(); ++i) {
      stringstream ss(slices[i]);
      int threadNum, timeSlice;
      ss >> threadNum >> timeSlice;
      
      int count = 0;
      while (count < timeSlice) {
        output.push_back(threads[threadNum][idxs[threadNum]]);
        idxs[threadNum] = (idxs[threadNum] + 1) % threads[threadNum].size();
        ++count;
      }
    }
    return output;
  }
};


//int main() {
//  PrintScheduler printScheduler;
//  cout << printScheduler.getOutput({ "AB","CD" }, {"0 1", "1 1", "0 1", "1 2"}) << endl;
//}