#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long 

signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  int n1;

  while (N--) {
    cin>>n1;
    bool done = false;
    for (int i = 0; i < 62; i++) {
      if (n1 == 1) {
        cout<<"T\n";
        done = true;
        break;
      }
      else if (n1 % 2 != 0) {
        break;
      }
      else if (n1 != 2) {
        n1 /= 2;
      }
      else {
        cout<<"T\n";
        done = true;
        break;
      }
    }
    if (!done) {
      cout<<"F\n";
    }
  }

  return 0;
}