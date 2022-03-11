#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N, K;
  cin>>M>>N>>K;

  vector<int> rows(M+1);
  vector<int> cols(N+1);

  for (int i = 1; i <= M; i++) {
    rows[i] = 0;
  }

  for (int i = 1; i <= N; i++) {
    cols[i] = 0;
  }

  char type;
  int location;

  for (int i = 0; i < K; i++) {
    cin>>type>>location;
    if (type == 'R') {
      rows[location]++;
    }
    else {
      cols[location]++;
    }
  }

  int count = 0;
  int val = 0;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      val = rows[i] + cols[j];
      if (val % 2 == 1) {
        count++;
      }
    }
  }

  cout<<count<<"\n";

  return 0;
  
}