#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PaperFold {
public:
  int numFolds(vector<int> paper, vector<int> box) {
    int numFold = tryAll(paper[0], paper[1], box[0], box[1], 0);
    return numFold == 9 ? -1 : numFold;
  }

private:
  int tryAll(double pWidth, double pHeight, double bWidth, double bHeight, int numFold) {
    if (numFold == 9) return 9;
    if ((pWidth <= bWidth && pHeight <= bHeight) || (pHeight <= bWidth && pWidth <= bHeight))
      return numFold;

    int foldWidth = tryAll(pWidth / 2, pHeight, bWidth, bHeight, numFold + 1);
    int foldHeight = tryAll(pWidth, pHeight / 2, bWidth, bHeight, numFold + 1);
    return min(foldWidth, foldHeight);
  }
};
