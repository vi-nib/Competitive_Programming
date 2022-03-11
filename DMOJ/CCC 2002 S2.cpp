#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int numerator, denominator;
  cin>>numerator>>denominator;

  if (numerator == 0) {
    cout<<0<<"\n";
    return 0;
  }

  if (numerator == denominator) {
    cout<<1<<"\n";
    return 0;
  }

  if (numerator > denominator) {

    int whole = numerator / denominator;
    int remainder = numerator % denominator;

    if (remainder == 0) {
      cout << numerator/denominator << "\n";
    }

    else {
      for (int i = remainder; i >= 2; i--) {
        if (remainder % i == 0 && denominator % i == 0) {
          remainder /= i;
          denominator /= i;
        }
      }
      if (whole != 0) {
        cout << whole << " " << remainder << "/" << denominator << "\n";
      }
      else {
        cout << remainder << "/" << denominator << "\n";
      }
  }

  return 0;

}

if (denominator > numerator) {

  for (int i = numerator; i >= 2; i--) {
    if (numerator % i == 0 && denominator % i == 0) {
      numerator /= i;
      denominator /= i;
    }
  }

    cout << numerator << "/" << denominator << "\n";

}

  return 0;
  
}