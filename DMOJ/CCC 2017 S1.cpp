#include <bits/stdc++.h>
using namespace std;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<int> swifts(N+1);
  vector<int> semaphores(N+1);

  for (int i = 1; i <= N; i++) {
    cin>>swifts[i];
  }

  for (int i = 1; i <= N; i++) {
    cin>>semaphores[i];
  }

  vector<int> prefix_sum_swifts(N+1);
  vector<int> prefix_sum_semaphores(N+1);

  for (int i = 1; i <= N; i++) {
    prefix_sum_swifts[i] = prefix_sum_swifts[i-1] + swifts[i];
    prefix_sum_semaphores[i] = prefix_sum_semaphores[i-1] + semaphores[i];
  }

  for (int i = N; i >= 1; i--) {
    if (prefix_sum_swifts[i] == prefix_sum_semaphores[i]) {
      cout<<i<<"\n";
      return 0;
    }
  }

  cout<<0<<"\n";

  return 0;
}