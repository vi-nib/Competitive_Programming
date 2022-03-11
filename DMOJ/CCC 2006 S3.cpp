#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int rx, ry, jx, jy;
    cin>>rx>>ry>>jx>>jy;
    
    int n;
    cin>>n;

    vector<bool> obstructBuilding(n);

    if (jy != ry && rx != jx) {

      double slope = (double) (jy - ry) / (double) (jx - rx);

      while (n--) {

      int numCorners;
      cin>>numCorners;

      vector<pair<int, int>> corners(numCorners);

      for (int i = 0; i < numCorners; i++) {
        int bx, by;
        cin>>bx>>by;
        corners[i] = {bx, by};
      }

      // This vector will store whether the integer coordinates of the corner of the building are above or below the string. For the building to not block, they must all be above or all be below.
      // 2 is above, 0 is below, and 1 is on the line
    
      vector<int> lowerOrHigher;

      for (int i = 0; i < numCorners; i++) {

        double yValue = slope * (double) corners[i].first;

        if (yValue == double (corners[i].second)) {
            lowerOrHigher.push_back(1);
        }
        else if (yValue < double (corners[i].second)) {
            lowerOrHigher.push_back(2);
        }
        else {
            lowerOrHigher.push_back(0);
        }
      }

      bool AllPointsLeftRight = true;

      for (int i = 0; i < numCorners; i++) {
        if (corners[i].first <= max(rx, jx) && corners[i].first >= min(rx, jx)) {
          AllPointsLeftRight = false;
        }
      }

      if (AllPointsLeftRight) {
        continue;
      }

      bool onLine = false;

       for (int i = 0; i < lowerOrHigher.size(); i++) {
        if (lowerOrHigher[i] == 1) {
          obstructBuilding[n] = true;
          onLine = true;
          break;
        }

      }
      if (onLine) {
        continue;
      }

      bool notAllAboveOrBelow = false;

      for (int i = 1; i < lowerOrHigher.size(); i++) {
        if (lowerOrHigher[i] != lowerOrHigher[0]) {
          obstructBuilding[n] = true;
          break;
        }
      }
    }
  }

  // Horizontal line

  else if (jy == ry) {
    
    while (n--) {

    int numCorners;
    cin>>numCorners;

    vector<pair<int, int>> corners(numCorners);

    for (int i = 0; i < numCorners; i++) {
      int bx, by;
      cin>>bx>>by;
      corners[i] = {bx, by};
    }

    // 1 will mean above, 2 will mean below, 0 will mean on

    vector<int> aboveOrBelow;

    for (int i = 0; i < numCorners; i++) {
      if (corners[i].second > ry) {
        aboveOrBelow.push_back(1);
      }
      else if (corners[i].second < ry) {
        aboveOrBelow.push_back(2);
      }
      else {
        aboveOrBelow.push_back(0);
      }
    }

    bool allPointsLeftOrRight = true;

    for (int i = 0; i < numCorners; i++) {
      if (corners[i].first <= max(rx, jx) && corners[i].first >= min(rx, jx)) {
        allPointsLeftOrRight = false;
      }
    }

    if (allPointsLeftOrRight) {
      continue;
    }


    bool onString = false;

    for (int i = 0; i < aboveOrBelow.size(); i++) {
      if (aboveOrBelow[i] == 0) {
        obstructBuilding[n] = true;
        onString = true;
        break;
      }
    }

    if (onString) {
      continue;
    }

    for (int i = 1; i < aboveOrBelow.size(); i++) {
      if (aboveOrBelow[i] != aboveOrBelow[0]) {
        obstructBuilding[n] = true;
        break;
      }
    }

  }

}

else if (rx == jx) {

    while (n--) {

    int numCorners;
    cin>>numCorners;

    vector<pair<int, int>> corners(numCorners);

    for (int i = 0; i < numCorners; i++) {
      int bx, by;
      cin>>bx>>by;
      corners[i] = {bx, by};
    }

    // 1 will mean right, 2 will mean left, 0 will mean on

    vector<int> leftOrRight;

    for (int i = 0; i < numCorners; i++) {
      if (corners[i].first > rx) {
        leftOrRight.push_back(1);
      }
      else if (corners[i].first < rx) {
        leftOrRight.push_back(2);
      }
      else {
        leftOrRight.push_back(0);
      }
    }

    bool allPointsAboveOrBelow = true;

    for (int i = 0; i < numCorners; i++) {
      if (corners[i].second <= max(ry, jy) && corners[i].second >= min(ry, jy)) {
        allPointsAboveOrBelow = false;
      }
    }

    if (allPointsAboveOrBelow) {
      continue;
    }

    bool onConnection = false;

    for (int i = 0; i < leftOrRight.size(); i++) {
      if (leftOrRight[i] == 0) {
        obstructBuilding[n] = true;
        onConnection = true;
        break;
      }
    }

    if (onConnection) {
      continue;
    }

    for (int i = 1; i < leftOrRight.size(); i++) {
      if (leftOrRight[i] != leftOrRight[0]) {
        obstructBuilding[n] = true;
        break;
      }
    }

  }
}

  int count = 0;

  for (int i = 0; i < obstructBuilding.size(); i++) {
    if (obstructBuilding[i]) {
      count++;
    }
  }
  cout<<count<<"\n";

  return 0;

}

   
