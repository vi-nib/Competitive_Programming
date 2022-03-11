#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<int> player1(N);
  vector<int> player2(N);

  for (int i = 0; i < N; i++) {
    cin>>player1[i];
  }

  for (int i = 0; i < N; i++) {
    cin>>player2[i];
  }

  bool war = false;

  int count = 0;

  for (int i = 0; i < N; i++) {
    if (player1[i] == player2[i] && !war) {
      count++;
      war = true;
    }
    if (player1[i] != player2[i]) {
      war = false;
    }
  }

  cout<<count<<"\n";

  return 0;
  
}