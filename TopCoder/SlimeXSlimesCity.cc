#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

class SlimeXSlimesCity {
public:
  int merge(vector<int> population) {
    int count = 1;
    sort(population.begin(), population.end(), greater<int>());
    for (int i = 1; i < population.size();++i) {
      long long total = 0;
      for (int j = i; j < population.size(); ++j) total += population[j];
      if (total >= population[0]) {
        ++count;
      }
      else {
        for (int j = i - 1; j > 0; --j) {
          if (total >= population[j]) total += population[j];
          else break;

          if (total >= population[0]) {
            ++count;
            break;
          }
        }
      }
    }
    return count;
  }
};