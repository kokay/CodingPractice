#include <iostream>
#include <vector>

using namespace std;

class RedSquare {
public:
  int countTheEmptyReds(int maxRank, int maxFile, vector<int> rank, vector<int> file) {
    vector<vector<bool>> checkerBoard(maxRank + 1, vector<bool>(maxFile + 1, false));
    
    bool color = true;
    for (int i = 1; i <= maxRank; ++i) {
      color = !color;
      checkerBoard[i][maxFile] = color;
      for (int j = maxFile - 1; j > 0; --j)
        checkerBoard[i][j] = !checkerBoard[i][j + 1];
    }

    for (int i = 0; i < rank.size(); ++i)
        checkerBoard[rank[i]][file[i]] = false;

    int count = 0;
    for (int i = 1; i <= maxRank; ++i) {
      for (int j = 1; j <= maxFile; ++j)
        count += checkerBoard[i][j];
    }
    return count;
  }
};

//int main() {
//  RedSquare redSqure;
//  cout << redSqure.countTheEmptyReds(3, 5, { 1, 2, 2 }, { 4, 1, 2 }) << endl;
//}