#include <bits/stdc++.h>
using namespace std;

int numDigits(int n) {

  int count = 0;

  while (n > 0) {
    count++;
    n /= 10;
  }

  return count;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int year;
  cin>>year;

  set<int> digitYear;

  while (true) {

    year++;

    int newYear = year;

    digitYear.clear();

    while (newYear > 0) {
      int lastDigit = newYear % 10;
      digitYear.insert(lastDigit);
      newYear /= 10;
    }

    int length = numDigits(year);

    if (length == (int)digitYear.size()) {
      cout<<year<<"\n";
      break;
    }

  }
  
  return 0;
  
}
