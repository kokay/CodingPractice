#include <iostream>
#include <vector>

using namespace std;

class CorporationSalary {
public:
  vector<long long> salaries;
  long long totalSalary(vector<string> relations) {
    salaries = vector<long long>(relations.size(), -1);
    long long total = 0;
    for (int i = 0; i < relations.size();++i)
      total += dfs(relations, i);

    return total;
  }

  long long dfs(vector<string>& relations, int idx) {
    if (salaries[idx] != -1) return salaries[idx];

    salaries[idx] = 0;
    for (int i = 0; i < relations[idx].size(); ++i) {
      if (relations[idx][i] == 'Y')
        salaries[idx] += dfs(relations, i);
    }
    if (salaries[idx] == 0) salaries[idx] = 1;
    return salaries[idx];
  }
};
