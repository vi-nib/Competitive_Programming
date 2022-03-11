#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  vector<int> numbers(5);

  for (int i = 1; i <= 5; i++) {
    if (i == 3) {
      numbers[i] = 5;
    }
    else {
      numbers[i] = 0;
    }
  }

  while (n--) {
    int position1, position2;
    cin>>position1>>position2;
    swap(numbers[position1], numbers[position2]);
  }

  for (int i = 1; i <= 5; i++) {
    if (numbers[i] == 5) {
      cout<<i<<"\n";
    }
  }

  return 0;

}