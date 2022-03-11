#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  map<char, int> cipher;

  cipher['A'] = 2;
  cipher['B'] = 2;
  cipher['C'] = 2;
  cipher['D'] = 3;
  cipher['E'] = 3;
  cipher['F'] = 3;
  cipher['G'] = 4;
  cipher['H'] = 4;
  cipher['I'] = 4;
  cipher['J'] = 5;
  cipher['K'] = 5;
  cipher['L'] = 5;
  cipher['M'] = 6;
  cipher['N'] = 6;
  cipher['O'] = 6;
  cipher['P'] = 7;
  cipher['Q'] = 7;
  cipher['R'] = 7;
  cipher['S'] = 7;
  cipher['T'] = 8;
  cipher['U'] = 8;
  cipher['V'] = 8;
  cipher['W'] = 9;
  cipher['X'] = 9;
  cipher['Y'] = 9;
  cipher['Z'] = 9;

    while (t--) {

    string code;
    cin>>code;

    string number;

    for (int i = 0; i < (int)code.size(); i++) {
      if (code[i] >= 48 && code[i] <= 57) {
        number += code[i];
      }
      else if (code[i] != '-') {
        number += to_string(cipher[code[i]]);
      }
      
    }

    for (int i = 0; i < 10; i++) {
      cout<<number[i];
      if (i == 2 || i == 5) {
        cout<<"-";
      }
    }

    cout<<"\n";

  }

  return 0;
  
}