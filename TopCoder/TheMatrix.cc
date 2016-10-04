#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TheMatrix {
public:
  int MaxArea(vector<string> board) {
    int maxArea = 1, area = 0;
    for (int startY = 0; startY < board.size(); ++startY) {
      for (int startX = 0; startX < board[0].size(); ++startX) {
        int lastY = board.size(), lastX = board[0].size();
        for (int endY = startY; endY < lastY; ++endY) {
          if (endY != startY && board[endY][startX] == board[endY - 1][startX]) {
            lastY = endY;
            break;
          }
          for (int endX = startX; endX < lastX; ++endX) {
            if (endX != startX && board[endY][endX] == board[endY][endX - 1]) {
              lastX = endX;
              break;
            }

            area = (endY - startY + 1) * (endX - startX + 1);
            maxArea = max(maxArea, area);
          }
        }
      }
    }
    return maxArea;
  }
};