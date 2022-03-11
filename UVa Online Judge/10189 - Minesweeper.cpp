#include <bits/stdc++.h>
using namespace std;

char originalGrid[205][105];
int grid[205][105];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int counter = 1;

  while (cin>>n>>m) {
    if (n == 0 && m == 0) {
      break;
    }

    if (counter != 1) {
      cout<<"\n";
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin>>originalGrid[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (originalGrid[i][j] == '*') {
          grid[i][j] = 9;
        }
        else {
          grid[i][j] = 0;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 9) {
          // top left corner
          if (i == 0 && j == 0) {
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i+1][j+1] != 9) {
              grid[i+1][j+1]++;
            }
          }
          // top right corner
          else if (i == 0 && j == (m-1)) {
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
            if (grid[i+1][j-1] != 9) {
              grid[i+1][j-1]++;
            }
          }
          // top row not corner
          else if (i == 0 && j > 0 && j < (m-1)) {
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i+1][j-1] != 9) {
              grid[i+1][j-1]++;
            }
            if (grid[i+1][j+1] != 9) {
              grid[i+1][j+1]++;
            }
          }
          //bottom left corner
          else if (i == (n-1) && j == 0) {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i-1][j+1] != 9) {
              grid[i-1][j+1]++;
            }
          }
          // bottom right corner
          else if (i == (n-1) && j == (m-1)) {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
            if (grid[i-1][j-1] != 9) {
              grid[i-1][j-1]++;
            }
          }
          // leftmost column not corner
          else if (j == 0 && i > 0 && i < (n-1)) {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i-1][j+1] != 9) {
              grid[i-1][j+1]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i+1][j+1] != 9) {
              grid[i+1][j+1]++;
            }
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
          }
          // bottom row not corner
          else if (i == (n-1) && j < (m-1) && j > 0) {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i-1][j+1] != 9) {
              grid[i-1][j+1]++;
            }
            if (grid[i-1][j-1] != 9) {
              grid[i-1][j-1]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
          }
          // rightmost column not corner
          else if (j == (m-1) && i > 0 && i < (n-1)) {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i-1][j-1] != 9) {
              grid[i-1][j-1]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
            if (grid[i+1][j-1] != 9) {
              grid[i+1][j-1]++;
            }
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
          }

          else {
            if (grid[i-1][j] != 9) {
              grid[i-1][j]++;
            }
            if (grid[i-1][j-1] != 9) {
              grid[i-1][j-1]++;
            }
            if (grid[i-1][j+1] != 9) {
              grid[i-1][j+1]++;
            }
            if (grid[i][j+1] != 9) {
              grid[i][j+1]++;
            }
            if (grid[i][j-1] != 9) {
              grid[i][j-1]++;
            }
            if (grid[i+1][j-1] != 9) {
              grid[i+1][j-1]++;
            }
            if (grid[i+1][j+1] != 9) {
              grid[i+1][j+1]++;
            }
            if (grid[i+1][j] != 9) {
              grid[i+1][j]++;
            }
          }
        }   
      }
    }

    cout<<"Field #"<<counter<<":\n";

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 9) {
          cout<<"*";
        }
        else {
          cout<<grid[i][j];
        }
      }
      cout<<"\n";
    }

    counter++;

  }

  return 0;
  
}