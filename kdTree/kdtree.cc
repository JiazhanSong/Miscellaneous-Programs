#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point {
  int x;
  int y;
};

bool xCompare (Point i,Point j) { 
  return (i.x < j.x); 
}

bool yCompare (Point i,Point j) { 
  return (i.y < j.y); 
}

void preOrder(vector<Point> xArray, vector<Point> yArray, int orientation) {
  if (orientation == 0) { // vertical split
    int median = xArray.size() / 2;
    cout << xArray[median].x << " " << xArray[median].y;

    if (xArray.size() == 2) { // recurse on last point
      vector<Point> xleft;
      xleft.emplace_back(xArray[0]);
      cout << " ";
      preOrder(xleft, xleft, 1);
    }
    else if (median != 0) { // recurse on both arrays, splitting takes 2n linear time
      vector<Point> xleft(xArray.begin(), xArray.begin() + median);
      vector<Point> xright(xArray.begin() + median + 1, xArray.end());

      vector<Point> yleft;
      vector<Point> yright;
      for (int i=0; i<yArray.size(); i++) { // iterate through and partition around median point (linear)
        if (xArray[median].x > yArray[i].x) {
          yleft.emplace_back(yArray[i]);
        }
        else if (xArray[median].x == yArray[i].x && xArray[median].y != yArray[i].y) {
          yleft.emplace_back(yArray[i]);
        }
        else if (xArray[median].x < yArray[i].x) {
          yright.emplace_back(yArray[i]);
        }
      }
      cout << " ";
      preOrder(xleft, yleft, 1);
      cout << " ";
      preOrder(xright, yright, 1);
    }
  }
  else { // horizontal split
    int median = yArray.size() / 2;
    cout << yArray[median].x << " " << yArray[median].y;

    if (yArray.size() == 2) { // recurse on last point
      vector<Point> ydown;
      ydown.emplace_back(yArray[0]);
      cout << " ";
      preOrder(ydown, ydown, 0);
    }
    else if (median != 0) { // ,splitting takes 2n linear time
      vector<Point> ydown(yArray.begin(), yArray.begin() + median);
      vector<Point> yup(yArray.begin() + median + 1, yArray.end());
      vector<Point> xdown;
      vector<Point> xup;
      for (int i=0; i<yArray.size(); i++) {
        if (yArray[median].y > xArray[i].y) {
          xdown.emplace_back(xArray[i]);
        }
        else if (yArray[median].y == xArray[i].y && yArray[median].x != xArray[i].x) {
            xdown.emplace_back(xArray[i]);
        }
        else if (yArray[median].y < xArray[i].y) {
          xup.emplace_back(xArray[i]);
        }
      }
      cout << " ";
      preOrder(xdown, ydown, 0);
      cout << " ";
      preOrder(xup, yup, 0);
    }
  }
}

int main() {
  int numPoints;
  cin >> numPoints;

  int x_value;
  int y_value;
  vector<Point> xVector; // create x and y sorted arrays
  vector<Point> yVector;
  for (int i=0; i<numPoints; i++) {
    cin >> x_value >> y_value;
    Point point = {x_value,y_value};

    xVector.emplace_back(point);
    yVector.emplace_back(point);
  }

  sort(xVector.begin(), xVector.end(), xCompare);
  sort(yVector.begin(), yVector.end(), yCompare);

  preOrder(xVector,yVector,0);
  cout << endl;
}