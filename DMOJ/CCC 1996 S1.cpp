#include <bits/stdc++.h>
using namespace std;

int factorSum(int n) {

  int sum = 1;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }

  return sum;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  while (n--) {

    int x;
    cin>>x;

    int sum = factorSum(x);

    if (sum == x) {
      cout<<x<<" is a perfect number.\n";
    }
    else if (sum < x) {
      cout<<x<<" is a deficient number.\n";
    }
    else {
      cout<<x<<" is an abundant number.\n";
    }
  }

  return 0;

}