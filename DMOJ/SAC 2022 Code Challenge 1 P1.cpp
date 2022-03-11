#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, C;

  cin>>N>>M>>C;

  int totalGiveOut = N * M;

  int finalAnswer = C - totalGiveOut;

  cout<<finalAnswer<<"\n";

  return 0;
  
}