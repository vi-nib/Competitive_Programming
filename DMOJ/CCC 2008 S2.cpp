#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int r;
  cin>>r;

  while (r != 0) {

    int count = 0;

    int doubleR = r * r;

    for (int i = 1; i <= r; i++) {
      count += (int) sqrt(doubleR - (double) i * i) + 1;
    }

    int newCount = count * 4 + 1;

    cout<<newCount<<"\n";

    cin>>r;

    if (r == 0) {
      return 0;
    }

  }

  return 0;

}