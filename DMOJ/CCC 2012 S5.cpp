#include <bits/stdc++.h>
using namespace std;

int R, C;
bool grid[26][26];
int dp[26][26];
bool dp_solved[26][26];

int num_paths(int row, int col) {

    if (dp_solved[row][col]) {
        return dp[row][col];
    }

    if (row == R && col == C) {
        return 1;
    }
    int answer = 0;
    if (grid[row+1][col] == false && row < R) {
        answer += num_paths(row+1, col);
    }
    if (grid[row][col+1] == false && col < C) {
        answer += num_paths(row, col+1);
    }

    dp_solved[row][col] = true;

    return dp[row][col] = answer;
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;

    cin>>R>>C>>K;

    while (K--) {
        int x, y;
        cin>>x>>y;
        grid[x][y] = true;
    }

    cout<<num_paths(1, 1)<<"\n";

    return 0;

}