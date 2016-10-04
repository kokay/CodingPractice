#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FlowerGarden {
public:
  vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {
    vector<Flower> flowers;
    for (int i = 0; i < height.size(); ++i)
      flowers.push_back({ height[i], bloom[i], wilt[i] });

    vector<bool> used(flowers.size(), false);
    vector<int> order;
    for (int i = 0; i < flowers.size(); ++i) {
      int best = -1;
      for (int j = 0; j < flowers.size(); ++j) {
        if (used[j]) continue;

        bool ok = true;
        for (int k = 0; k < flowers.size(); ++k) {
          if (k == j || used[k]) continue;
          if (flowers[k].hight < flowers[j].hight && flowers[k].bloom <= flowers[j].wilt && flowers[k].wilt >= flowers[j].bloom) {
            ok = false;
            break;
          }
        }
        if (ok && (best == -1 || flowers[j].hight > flowers[best].hight))
          best = j;
      }
      order.push_back(flowers[best].hight);
      used[best] = true;
    }
    return order;
  }

private:
  struct Flower {
    int hight, bloom, wilt;
    bool isBlockedBy(const Flower& f) {
      if (this->bloom >= f.bloom && this->bloom <= f.wilt) return true;
      if (this->wilt  >= f.bloom && this->wilt  <= f.wilt) return true;
      if (this->bloom <  f.bloom && this->wilt  >  f.wilt) return true;
      return false;
    }
    
    static bool Sort(const Flower& f1, const Flower& f2) {
      return f1.hight > f2.hight;
    }
  };
};