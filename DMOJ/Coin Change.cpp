#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> coins(100);

bool dp_solved[10001];
int dp[10001];

int least_coins(int sum) {

  if (sum < 0) {
    return 100000;
  }

  if (sum == 0) {
    return 0;
  }

  if (dp_solved[sum]) {
    return dp[sum];
  }

  int best = 1000000;

  for (int i = 0; i < N; i++) {
    best = min(best, least_coins(sum-coins[i])+1);
  }

  dp_solved[sum] = true;

  return dp[sum] = best;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int x;
  cin>>x;

  cin>>N;

  coins.resize(N);

  for (int i = 0; i < N; i++) {
    cin>>coins[i];
  }

  cout<<least_coins(x)<<"\n";

  return 0;
  
}