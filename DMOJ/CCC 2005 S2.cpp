#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, r;
  cin>>c>>r;

  int initialX = 0;
  int initialY = 0;

  while (true) {

    int x,y;
    cin>>x>>y;

    if (x == 0 && y == 0) {
      break;
    }

    initialX += x;
    initialY += y;

    if (initialX > c) {
      initialX = c;
    }
    if (initialX < 0) {
      initialX = 0;
    }
    if (initialY > r) {
      initialY = r;
    }
    if (initialY < 0) {
      initialY = 0;
    }

    cout<<initialX<<" "<<initialY<<"\n";

  }

  return 0;
  
}