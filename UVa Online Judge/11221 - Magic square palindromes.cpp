#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string phrase) {

  string word = phrase;

  int length = word.length();
  string firstPart = "";
  string secondPart = "";
  int middle = length / 2;

  
  if (length % 2 == 0) {
    for (int i = 0; i < middle; i++) {
      firstPart += word[i];
    }
    for (int i = length-1; i >= middle; i--) {
      secondPart += word[i];
    }
    if (firstPart == secondPart) {
      return true;
    }
  }
  else {
    
    for (int i = 0; i < middle; i++) {
      firstPart += word[i];
    }
    for (int i = length-1; i > middle; i--) {
      secondPart += word[i];
    }
    if (firstPart == secondPart) {
      return true;
    }
  }
  return false;
}

string removeCharacters(string sentence) {

  string word = sentence;

  for (int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }

  for (int i = 0; i < word.length(); i++) {
    if (word[i] == ' ' || word[i] == '.' || word[i] == ',' || word[i] == '!' || word[i] == '?' || word[i] == '(' || word[i] == ')') {
      word.erase(i, 1);
      i -= 1;
    }
  }

  return word;

}

int checkSize(string word) {
  int length = word.length();
  for (int i = 1; i <= length; i++) {
    if (pow(i, 2) == length) {
      return i;
    }
  }
  return -1;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin>>n;
  cin>>ws;

  string phrase;

  for (int i = 1; i <= n; i++) {
    getline(cin, phrase);
    string x = removeCharacters(phrase);
    cout<<"Case #"<<i<<":\n";
    
    bool sizeEmpty = false;
    if (x.empty()) {
        cout<<0<<"\n";
        sizeEmpty = true;
    }
    
    bool palindrome = isPalindrome(x);
    
    if (palindrome) {
        int y = checkSize(x);
        if (y != -1) {
            cout<<y<<"\n";
        }
        else {
            if (!sizeEmpty) {
                cout<<"No magic :(\n";
            }
            
        }
    }
    
    else {
        if (!sizeEmpty) {
           cout<<"No magic :(\n"; 
        }
    }
  }

  return 0;
  
}