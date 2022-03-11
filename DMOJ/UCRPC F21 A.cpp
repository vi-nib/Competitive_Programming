#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin>>n>>m;

  char trainCar[n][m];

  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin>>trainCar[i][j];
      if (trainCar[i][j] == 't') {
        count++;
      }
    }
  }

  cout<<count<<"\n";

  return 0;
  
}