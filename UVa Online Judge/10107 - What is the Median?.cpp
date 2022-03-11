#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int x;
  vector<int> arr;

  while (cin>>x) {
    arr.push_back(x);
    if (arr.size() % 2 == 0) {
      nth_element(arr.begin(), arr.begin() + arr.size()/2, arr.end());
      nth_element(arr.begin(), arr.begin() + (arr.size() - 1) / 2, arr.end());
      cout<<(arr[arr.size()/2] + arr[(arr.size()-1)/2])/2<<"\n";

    }
    else {
      nth_element(arr.begin(), arr.begin() + arr.size()/2, arr.end());
      cout<<arr[arr.size()/2]<<"\n";
    }

  }

  return 0;
  
}