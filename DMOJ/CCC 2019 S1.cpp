#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  string commands;
  getline(cin, commands);

  int countH = 0, countV = 0;

  for (int i = 0; i < (int)commands.length(); i++) {
    if (commands[i] == 'H') {
      countH++;
    }
    else {
      countV++;
    }
  }

  if (countV % 2 == 0 && countH % 2 == 0) {
    cout<<"1 2\n";
    cout<<"3 4\n";
  }

  else if (countV % 2 == 0 && countH % 2 != 0) {
    cout<<"3 4\n";
    cout<<"1 2\n";
  }

  else if (countV % 2 != 0 && countH % 2 == 0) {
    cout<<"2 1\n";
    cout<<"4 3\n";
  }

  else {
    cout<<"4 3\n";
    cout<<"2 1\n";
  }

  return 0;
  
}