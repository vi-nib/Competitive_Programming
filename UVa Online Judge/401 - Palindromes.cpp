#include <bits/stdc++.h>
using namespace std;

map<char, char> mirror;

bool palindrome(string x) {

  //string xCopy = x;
  int length = x.length();

  string firstPartString = "";
  string secondPartString = "";

  // abcba

  if (length % 2 == 0) {
    int middle = length / 2;
    for (int i = 0; i < middle; i++) {
      firstPartString += x[i];
    }
    for (int i = x.length()-1; i >= middle; i--) {
      secondPartString += x[i];
    }
    if (firstPartString == secondPartString) {
      return true;
    }
    // abba
  }

  else {
    int middle = length / 2;
    for (int i = 0; i < middle; i++) {
      firstPartString += x[i];
    }
    for (int i = x.length()-1; i > middle; i--) {
      secondPartString += x[i];
    }
    if (firstPartString == secondPartString) {
      return true;
    }
  }

  return false;

}

bool mirroredString(string y) {

  string original = y;
  string newString = y;

  for (int i = 0; i < y.length(); i++) {
    newString[i] = mirror[newString[i]];
  }

  string answer;

  for (int i = y.length()-1; i >= 0; i--) {
    answer += newString[i];
  }

  if (answer == original) {
    return true;
  }

  return false;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  mirror['A'] = 'A';
  mirror['E'] = '3';
  mirror['H'] = 'H';
  mirror['I'] = 'I';
  mirror['J'] = 'L';
  mirror['L'] = 'J';
  mirror['M'] = 'M';
  mirror['O'] = 'O';
  mirror['S'] = '2';
  mirror['T'] = 'T';
  mirror['U'] = 'U';
  mirror['V'] = 'V';
  mirror['W'] = 'W';
  mirror['X'] = 'X';
  mirror['Y'] = 'Y';
  mirror['Z'] = '5';
  mirror['1'] = '1';
  mirror['2'] = 'S';
  mirror['3'] = 'E';
  mirror['5'] = 'Z';
  mirror['8'] = '8';

  string word;
  
  while (cin>>word) {
    if (!palindrome(word) && !mirroredString(word)) {
      cout<<word<<" -- is not a palindrome.\n";
    }
    else if (!palindrome(word) && mirroredString(word)) {
      cout<<word<<" -- is a mirrored string.\n";
    }
    else if (palindrome(word) && !mirroredString(word)) {
      cout<<word<<" -- is a regular palindrome.\n";
    }
    else {
      cout<<word<<" -- is a mirrored palindrome.\n";
    }
    cout<<"\n";
  }

  return 0;
  
}