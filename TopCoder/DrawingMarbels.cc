#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DrawingMarbles {
public:
  double sameColor(vector<int> colors, int n) {
    double probability = 0;
    int total = accumulate(colors.begin(), colors.end(), 0);

    for (int num : colors) {
      double local = 1;
      for (int i = 0; i < n; ++i) {
        local *= double(num - i) / (total - i);
      }
      probability += local;
    }
    return probability;
  }
};

//int main() {
//  DrawingMarbles drawingMarbels;
//  cout << drawingMarbels.sameColor({ 12, 2, 34, 13, 17 }, 4 ) << endl;
//}