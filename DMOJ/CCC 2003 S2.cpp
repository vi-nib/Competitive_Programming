#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;
  cin>>ws;

  while (N--) {
      
    string line1, line2, line3, line4;
  
    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);
    getline(cin, line4);

    string lastWord1, lastWord2, lastWord3, lastWord4;

    for (int i = 0; i < line1.length(); i++) {
      if (line1[i] == ' ') {
        lastWord1 = line1.substr(i+1, line1.length());
      }
    }

    if (lastWord1.empty()) {
      lastWord1 = line1;
    }

    for (int i = 0; i < line2.length(); i++) {
      if (line2[i] == ' ') {
        lastWord2 = line2.substr(i+1, line2.length());
      }
    }

    if (lastWord2.empty()) {
      lastWord2 = line2;
    }

    for (int i = 0; i < line3.length(); i++) {
      if (line3[i] == ' ') {
        lastWord3 = line3.substr(i+1, line3.length());
      }
    }

    if (lastWord3.empty()) {
      lastWord3 = line3;
    }

    for (int i = 0; i < line4.length(); i++) {
      if (line4[i] == ' ') {
        lastWord4 = line4.substr(i+1, line4.length());
      }
    }

    if (lastWord4.empty()) {
      lastWord4 = line4;
    }

    for (int i = 0; i < lastWord1.length(); i++) {
      lastWord1[i] = tolower(lastWord1[i]);
    }
    for (int i = 0; i < lastWord2.length(); i++) {
      lastWord2[i] = tolower(lastWord2[i]);
    }
    for (int i = 0; i < lastWord3.length(); i++) {
      lastWord3[i] = tolower(lastWord3[i]);
    }
    for (int i = 0; i < lastWord4.length(); i++) {
      lastWord4[i] = tolower(lastWord4[i]);
    }

    string syllable1, syllable2, syllable3, syllable4;

    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int index4 = 0;
    
    for (int i = 0; i < lastWord1.length(); i++) {
      if (lastWord1[i] == 'a' || lastWord1[i] == 'e' || lastWord1[i] == 'i' || lastWord1[i] == 'o'|| lastWord1[i] == 'u') {
        index1 = i;
      }
    }

  syllable1 = lastWord1.substr(index1, lastWord1.length());

    for (int i = 0; i < lastWord2.length(); i++) {
      if (lastWord2[i] == 'a' || lastWord2[i] == 'e' || lastWord2[i] == 'i' || lastWord2[i] == 'o'|| lastWord2[i] == 'u') {
        index2 = i;
      }
    }

  syllable2 = lastWord2.substr(index2, lastWord2.length());

    for (int i = 0; i < lastWord3.length(); i++) {
      if (lastWord3[i] == 'a' || lastWord3[i] == 'e' || lastWord3[i] == 'i' || lastWord3[i] == 'o'|| lastWord3[i] == 'u') {
        index3 = i;
      }
    }

  syllable3 = lastWord3.substr(index3, lastWord3.length());

    for (int i = 0; i < lastWord4.length(); i++) {
      if (lastWord4[i] == 'a' || lastWord4[i] == 'e' || lastWord4[i] == 'i' || lastWord4[i] == 'o'|| lastWord4[i] == 'u') {
        index4 = i;
      }
    }

  syllable4 = lastWord4.substr(index4, lastWord4.length());

    if (syllable1 == syllable2 && syllable2 == syllable3 && syllable3 == syllable4) {
      cout<<"perfect\n";
    }
    else if (syllable1 == syllable2 && syllable3 == syllable4) {
      cout<<"even\n";
    }
    else if (syllable1 == syllable3 && syllable2 == syllable4) {
      cout<<"cross\n";
    }
    else if (syllable1 == syllable4 && syllable2 == syllable3) {
      cout<<"shell\n";
    }
    else {
      cout<<"free\n";
    }

}

  return 0;

}