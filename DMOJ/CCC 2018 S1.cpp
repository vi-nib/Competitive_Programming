#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  int N;
  cin>>N;

  vector<double> villages(N);

  for (int i = 0; i < N; i++) {
    cin>>villages[i];
  }
  sort(villages.begin(), villages.end());

  double minVillage = 1e9;

  for (int i = 1; i < N-1; i++) {
    double left = ((double)villages[i] + (double)villages[i-1]) * 0.5;
    double right = ((double)villages[i+1] + (double)villages[i]) * 0.5;
    double total = right - left;
    if (minVillage > total) {
      minVillage = total;
    }
  }

  printf("%.1f\n", minVillage);

  return 0;
  
}