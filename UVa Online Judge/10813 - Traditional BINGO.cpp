#include <bits/stdc++.h>
using namespace std;

int grid[5][5];

bool numberFound(int number) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (grid[i][j] == number) {
        grid[i][j] = -1;
        return true;
      }
    }
  }
  return false;
}

bool bingo() {

// checking rows and columns
  for (int i = 0; i < 5; i++) {
    if (grid[i][0] == -1 && grid[i][1] == -1 && grid[i][2] == -1 && grid[i][3] == -1 && grid[i][4] == -1) {
      return true;
    }
    if (grid[0][i] == -1 && grid[1][i] == -1 && grid[2][i] == -1 && grid[3][i] == -1 && grid[4][i] == -1) {
      return true;
    }
  }

// checking left diagonal (top left to bottom right)

  if (grid[0][0] == -1 && grid[1][1] == -1 && grid[2][2] == -1 && grid[3][3] == -1 && grid[4][4] == -1) {
    return true;
  }

// checking right diagonal (bottom left to top right)

  if (grid[4][0] == -1 && grid[3][1] == -1 && grid[2][2] == -1 && grid[1][3] == -1 && grid[0][4] == -1) {
    return true;
  }

return false;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  while (n--) {

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (i != 2 || j != 2) {
          cin>>grid[i][j];
        }
      }
    }

    grid[2][2] = -1;

    int alreadyWon = -1;
    int turn = 1;
    int temp;

    for (int i = 1; i <= 75; i++) {
      cin>>temp;
      if (alreadyWon == -1 && numberFound(temp) && bingo()) {
        alreadyWon = i;
      }
    }

    cout<<"BINGO after "<<alreadyWon<<" numbers announced\n";

  }
  return 0;
}