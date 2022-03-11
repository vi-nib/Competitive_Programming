#include <bits/stdc++.h>
using namespace std;

bool isPrime(int a) {
  if (a <= 1) {
    return false;
  }
  for (int i = 2; i < sqrt(a) + 1; i++) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin>>T;

  int n;

  while (T--) {

    cin>>n;

    int a, b;

    for (int i = 2; i < n; i++) {
      a = i;
      b = (2 * n) - i;

      if (isPrime(a) == true && isPrime(b) == true && (a + b == (2 * n))) {
        cout << a << " " << b << "\n";
        break;
      }
    }
  }

  return 0;
  
}