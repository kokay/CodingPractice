#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ColoredStrokes {
public:
  int getLeast(vector<string> picture) {
    int count = 0;
    for (int i = 0; i < picture.size(); ++i) {
      for (int j = 0; j < picture[i].size(); ++j) {
        if (picture[i][j] == 'B') {
          deleteVerticalLine(picture, i, j);
          count++;
        }
        else if (picture[i][j] == 'R') {
          deleteHorizontalLine(picture, i, j);
          count++;
        }
        else if(picture[i][j] == 'G') {
          deleteVerticalLine(picture, i, j);
          deleteHorizontalLine(picture, i, j);
          count += 2;
        }
      }
    }
    return count;
  }

private:
  void deleteVerticalLine(vector<string>& picture, int y, int x) {
    for (int i = y; i < picture.size(); ++i) {
      if (picture[i][x] == 'G')
        picture[i][x] = 'R';
      else if (picture[i][x] == 'B')
        picture[i][x] = '.';
      else
        break;
    }
  }
  void deleteHorizontalLine(vector<string>& picture, int y, int x) {
    for (int i = x; i < picture[y].size(); ++i) {
      if (picture[y][i] == 'G')
        picture[y][i] = 'B';
      else if (picture[y][i] == 'R')
        picture[y][i] = '.';
      else
        break;
    }
  }
};