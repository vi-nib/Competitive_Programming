#include <bits/stdc++.h>
using namespace std;

int R, L;

int grid[30][8];

string finalRowOptions(int startingRow) {

  int newGrid[R][L];

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < L; j++) {
      newGrid[i][j] = grid[i][j];
    }
  }

  int begin = R - startingRow;

  for (int i = begin; i < R; i++) {
    for (int j = 0; j < L; j++) {
      if (newGrid[i][j] == newGrid[i-1][j]) {
        newGrid[i][j] = 0;
      }
      else {
        newGrid[i][j] = 1;
      }
    }
  }

  string lastRow;

  for (int j = 0; j < L; j++) {
    lastRow += to_string(newGrid[R-1][j]);
  }

  return lastRow;

} 

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>R>>L;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < L; j++) {
      cin>>grid[i][j];
    }
  }

  string initialLastRow;

  for (int j = 0; j < L; j++) {
    initialLastRow += to_string(grid[R-1][j]);
  }
  
  set<string> options;
  
  options.insert(initialLastRow);

  for (int i = 1; i < R; i++) {
    
    string last = finalRowOptions(i);
    
    options.insert(last);

  }

  cout<<options.size()<<"\n";

  return 0;
  
}