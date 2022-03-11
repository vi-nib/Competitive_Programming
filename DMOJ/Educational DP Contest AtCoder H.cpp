#include <bits/stdc++.h>
using namespace std;

int H, W;
bool grid[10001][1001];
int dp[10001][1001];
bool dp_solved[10001][1001];

int solve(int r, int c) {

  int m = 1e9 + 7;

  if (r == H && c == W) {
    return 1;
  }

  if (dp_solved[r][c]) {
    return dp[r][c];
  }

  int answer = 0;

  if (grid[r+1][c] == false && r < H) {
    answer += solve(r+1, c);
    answer %= m;
  }

  if (grid[r][c+1] == false && c < W) {
    answer += solve(r, c+1);
    answer %= m;
  }

  dp_solved[r][c] = true;
  return dp[r][c] = answer;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>H>>W;

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char character;
      cin>>character;
      if (character == '.') {
        grid[i][j] = false;
      }
      else {
        grid[i][j] = true;
      }
    }
  }

  cout<<solve(1, 1)<<"\n";

  return 0;
  
}