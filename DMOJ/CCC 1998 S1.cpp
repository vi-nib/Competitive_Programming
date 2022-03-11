#include <bits/stdc++.h>
using namespace std;

string num4(string a) {
  string b = a;
  int count = 0;
  for (int i = 0; i < (int)b.length(); i++) {
    if (b[i] != ' ') {
      count++;
    }
    else {
      if (count == 4) {
        b[i-1] = '*';
        b[i-2] = '*';
        b[i-3] = '*';
        b[i-4] = '*';
      }
      count = 0;
    }
  }
  
  b.erase(b.length()-1, 1);

  return b;
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  cin>>ws;

  string x;
  string answer;

  while (n--) {
    getline(cin, x);
    x += " ";
    answer = num4(x);
    cout<<answer<<"\n";
  }

  return 0;
  
}