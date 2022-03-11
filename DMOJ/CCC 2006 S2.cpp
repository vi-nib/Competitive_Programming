#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string understoodText;
    getline(cin, understoodText);

    string mapText;
    getline(cin, mapText);

    string cipherText;
    getline(cin, cipherText);

    map<char, char> cipher;

    for (int i = 0; i < understoodText.length(); i++) {
      char know = understoodText[i];
      char notKnow = mapText[i];

      cipher[notKnow] = know;
    }

    for (int i = 0; i < cipherText.length(); i++) {
      if (cipher.find(cipherText[i]) != cipher.end()) {
        cout<<cipher[cipherText[i]];
      }
      else {
        cout<<".";
      }
    }

    cout<<"\n";

    return 0;
    
}