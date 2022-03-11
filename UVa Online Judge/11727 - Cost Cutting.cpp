#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;
    int arr[3];

    for (int i = 1; i <= T; i++) {
      int x, y, z;
      cin>>x>>y>>z;
      arr[0] = x;
      arr[1] = y;
      arr[2] = z;
      sort(arr, arr+3);
      cout<<"Case "<<i<<": "<<arr[1]<<"\n";

    }

    return 0;
}