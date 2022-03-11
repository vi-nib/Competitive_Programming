#include <bits/stdc++.h>
using namespace std;

int grid[3][3];
int transformGrid[3][3];

void print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
}

void transform() {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      transformGrid[i][j] = grid[i][j];
    }
  }

  transformGrid[0][0] = (grid[0][1] + grid[1][0]) % 2;
  transformGrid[0][1] = (grid[0][0] + grid[0][2] + grid[1][1]) % 2;
  transformGrid[0][2] = (grid[0][1] + grid[1][2]) % 2;
  transformGrid[1][0] = (grid[0][0] + grid[1][1] + grid[2][0]) % 2;
  transformGrid[1][1] = (grid[0][1] + grid[1][0] + grid[1][2] + grid[2][1]) % 2;
  transformGrid[1][2] = (grid[1][1] + grid[2][2] + grid[0][2]) % 2;
  transformGrid[2][0] = (grid[1][0] + grid[2][1]) % 2;
  transformGrid[2][1] = (grid[2][0] + grid[1][1] + grid[2][2]) % 2;
  transformGrid[2][2] = (grid[2][1] + grid[1][2]) % 2;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = transformGrid[i][j];
    }
  }

}

bool zero() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i][j] != 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N;
  cin>>N;

  while (N--) {
    char c;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin>>c;
        grid[i][j] = c-'0';
      }
    }

    int index = -1;

    for (int i = 0; i < 1e6; i++) {
      if (zero()) {
        break;
      }
      else {
        transform();
        index++;
      }
    }

    cout<<index<<"\n";

  }

  return 0;
  
}