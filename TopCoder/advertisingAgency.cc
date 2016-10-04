#include <iostream>
#include <vector>

using namespace std;

class AdvertisingAgency {
public:
	int numberOfRejections(vector<int>& requests) {
    vector<bool> billboards(101, false);

	  int count = 0;
	  for (int i = 0; i < requests.size(); ++i) {
      if (billboards[requests[i]]) count++;
      else billboards[requests[i]] = true;
	  }
	  return count;
	}
};