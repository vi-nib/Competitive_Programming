#include <bits/stdc++.h>
using namespace std;

int m, n;

int gridValues[115][115];

int dp[105][105][4];
bool dp_solved[105][105][4];

// last represents last move
// if 1, last move was up
// if 2, last move was down
// if 3, last move was right

int max_collected(int row, int col, int last) {

    if (dp_solved[row][col][last]) {
        return dp[row][col][last];
    }

    // If already in cell where princess is.

    if (row == m && col == n) {
        return gridValues[row][col];
    }

    // If in a cell that is not part of the grid or in a cell that contains an obstacle

    if (gridValues[row][col] == -1) {
        return -1000000000;
    }

    // If last move was up

    if (last == 1) {
        dp[row][col][last] = gridValues[row][col] + max(max_collected(row-1, col, 1), max_collected(row, col+1, 3));
    }

    // If last move was down

    if (last == 2) {
        dp[row][col][last] = gridValues[row][col] + max(max_collected(row+1, col, 2), max_collected(row, col+1, 3));
    }

    // If last move was right

    if (last == 3) {
        dp[row][col][last] = gridValues[row][col] + max(max_collected(row, col+1, 3), max(max_collected(row+1, col, 2), max_collected(row-1, col, 1)));
    }


    dp_solved[row][col][last] = true;
    return dp[row][col][last];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    bool notZero = true;

    while (notZero) {

        memset(gridValues, 0, sizeof(gridValues));

        memset(dp, 0, sizeof(dp));

        memset(dp_solved, false, sizeof(dp_solved));

        int localM, localN;
        cin>>localM>>localN;

        if (localM == 0 && localN == 0) {
            notZero = false;
            break;
        }

        m = localM;
        n = localN;

        char grid[105][105];

    /*
    Note the following in int gridValues matrix:
        -1 = cell has obstacle/cannot access
        0 = cell is free
        some number n = cell has n coins
    */

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin>>grid[i][j];
        }
    }

        for (int i = 0; i < 115; i++) {
            for (int j = 0; j < 115; j++) {
                gridValues[i][j] = -1;
        }
    }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == '.') {
                    gridValues[i][j] = 0;
                }
                else if (grid[i][j] == '*') {
                    gridValues[i][j] = -1;
                }
                else {
                    gridValues[i][j] = grid[i][j] - '0';
                }
            }
        }

        cout<<max_collected(m, 1, 1)<<"\n";

    }

    return 0;
  
}