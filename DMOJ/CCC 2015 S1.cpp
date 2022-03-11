#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int K;
  cin>>K;

  int sum = 0;
  
  stack<int> commands;

  while (K--) {
    int number;
    cin>>number;
    if (number == 0) {
      commands.pop();
    }
    else {
      commands.push(number);
    }
  }

  if (commands.empty()) {
    cout<<0<<"\n";
    return 0;
  }

  else {
    while (!commands.empty()) {
      sum += commands.top();
      commands.pop();
    }
  }

  cout<<sum<<"\n";

  return 0;

}