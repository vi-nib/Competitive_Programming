#include <bits/stdc++.h>
using namespace std;

bool oldEnough(int year, int month, int day) {
  if (year < 1989 || (year == 1989 && month < 2) || (year == 1989 && month == 2 && day <= 27)) {
    return true;
  }
  else {
    return false;
  }
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  while (n--) {

    int year, month, day;
    cin>>year>>month>>day;

    bool allowed = oldEnough(year, month, day);

    if (allowed) {
      cout << "Yes" << "\n";
    }

    else {
      cout << "No" << "\n";
    }

  }

  return 0;

}