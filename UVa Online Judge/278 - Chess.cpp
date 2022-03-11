#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  while (t--) {
    char piece;
    cin>>piece;
    int numRows, numCols;
    cin>>numRows>>numCols;
    if (piece == 'r') {
      cout<<min(numRows, numCols)<<"\n";
    }
    else if (piece == 'k') {
      int value = numRows * numCols;
      value /= 2;
      cout<<value<<"\n";
    }
    else if (piece == 'K') {
      int answer =  int((numRows + 1)/2) * int((numCols+1)/2);
      cout<<answer<<"\n";
    }
    else {
      cout<<min(numRows, numCols)<<"\n";
    }
  }

  return 0;

}