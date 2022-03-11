#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;
  cin>>ws;

  string x;
  int tCount = 0;
  int sCount = 0;

  for (int i = 0; i < N; i++) {
    getline(cin, x);
    for (int j = 0; j < (int)x.length(); j++) {
      if (x[j] == 't' || x[j] == 'T') {
        tCount++;
      }
      if (x[j] == 's' || x[j] == 'S') {
        sCount++;
      }
    }
  }

  if (tCount > sCount) {
    cout<<"English\n";
  }
  else {
    cout<<"French\n";
  }

  return 0;

}