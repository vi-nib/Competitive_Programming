#include <bits/stdc++.h>
using namespace std;

int N;
int distances[1501][1501];

int dp[1501][1501];
bool dp_solved[1501][1501];

int min_duration(int left_value, int right_value) {
  
  int current_value = max(left_value, right_value) + 1;

  if (current_value == N + 1) {
    return 0;
  }

  if (dp_solved[left_value][right_value]) {
    return dp[left_value][right_value];
  }

  int option_left = distances[left_value][current_value] + min_duration(current_value, right_value);

  int option_right = distances[right_value][current_value] + min_duration(left_value, current_value);

  dp_solved[left_value][right_value] = true;

  return dp[left_value][right_value] = min(option_left, option_right);
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin>>distances[i][j];
    }
  }

  cout << min_duration(1, 1) << "\n";
  

  return 0;

}