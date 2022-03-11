#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

  int P, G, R, O, total;
  cin>>P>>G>>R>>O>>total;

  int numCombination = 0;
  int minTickets = 1e9;

  for (int i = 0; i <= total; i++) {
    for (int j = 0; j <= total; j++) {
      for (int t = 0; t <= total; t++) {
        for (int l = 0; l <= total; l++) {
          if ((i * P) + (j * G) + (t * R) + (l * O) == total) {
            numCombination++;
            minTickets = min(minTickets, i + j + t + l);
            cout<<"# of PINK is "<<i<<" # of GREEN is "<<j<<" # of RED is "<<t<<" # of ORANGE is "<<l<<"\n";
          }
        }
      }
    }
  }

  cout<<"Total combinations is "<<numCombination<<".\n";
  cout<<"Minimum number of tickets to print is "<<minTickets<<".\n";



  return 0;
}