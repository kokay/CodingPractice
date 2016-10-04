#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Point {
  int x, y;
};

class BestTriangulation {
public:
  double maxArea(vector<string> vertices) {
    vector<Point> points = getPoints(vertices);
    return checkAll(points, vector<Point>(), 0, 0.0);
  }
private:
  double checkAll(vector<Point>& points, vector<Point> triangle, int currentIdx, double maxArea) {
    if (triangle.size() == 3) return max(maxArea, getArea(triangle));

    for (int i = currentIdx; i < points.size(); ++i) {
      triangle.push_back(points[i]);
      maxArea = max(maxArea, checkAll(points, triangle, i + 1, maxArea));
      triangle.pop_back();
    }
    return maxArea;
  }

  double getArea(vector<Point> trianble) {

  }

  vector<Point> getPoints(vector<string> vertices) {
    vector<Point> points;
    for (int i = 0; i < vertices.size(); ++i) {
      stringstream ss(vertices[i]);
      int x, y;
      ss >> x >> y;
      points.push_back({ x,y });
    }
    return points;
  }
};
