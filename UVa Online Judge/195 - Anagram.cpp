#include <bits/stdc++.h>
using namespace std;

bool sortingLexicographic(char a, char b) {

  char aLower = tolower(a);
  char bLower = tolower(b);

  if (aLower == bLower) {
    return a < b;
  }

  return aLower < bLower;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;

  string x;

  while (n--) {
    cin>>x;
    sort(x.begin(), x.end(), sortingLexicographic);

    cout<<x<<"\n";
    while (next_permutation(x.begin(), x.end(), sortingLexicographic)) {
      cout<<x<<"\n";
    }
  }

  return 0;
}