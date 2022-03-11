#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<pair<int, int>> speeds;

  int t, p;

  for (int i = 0; i < N; i++) {
    cin>>t>>p;
    speeds.push_back({t, p});
  }

  sort(speeds.begin(), speeds.end());

  double maxSpeed = 0.0;
  double curr;

  for (int i = 0; i < N-1; i++) {
    curr = (double)abs(speeds[i+1].second - speeds[i].second) / (double)(speeds[i+1].first - speeds[i].first);
    maxSpeed = max(maxSpeed, curr);
  }

  printf("%.1f\n", maxSpeed);

  return 0;
  
}