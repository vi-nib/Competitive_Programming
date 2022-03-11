#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<string> config1(N);
  vector<string> config2(N);

  for (int i = 0; i < N; i++) {
    cin>>config1[i];
  }

  for (int i = 0; i < N; i++) {
    cin>>config2[i];
  }

  vector<pair<string, string>> partners(N);

  for (int i = 0; i < N; i++) {
    partners[i] = {config1[i], config2[i]};
  }

  for (int i = 0; i < N; i++) {

    if (partners[i].first == partners[i].second) {
      cout<<"bad"<<"\n";
      return 0;
    }

    for (int j = 0; j < N; j++) {

      if (partners[i].first == partners[j].second) {
        if (partners[i].second != partners[j].first) {
          cout<<"bad"<<"\n";
          return 0;
        }
        else {
          break;
        }
      }
    }
  }

  cout<<"good"<<"\n";

  return 0;
  
}