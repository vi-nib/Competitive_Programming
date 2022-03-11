#include <bits/stdc++.h>
using namespace std;

string removingCharacters(string line) {
  string word = line;
  for (int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }
  for (int i = 0; i < word.length(); i++) {
    if (word[i] == ' ' || word[i] == '!' || word[i] == '.' || word[i] == ',' || word[i] == '?') {
      word.erase(i, 1);
      i -= 1;
    }
  }
  return word;
}

bool isPalindrome(string word) {

  int length = word.length();
  int middle = length / 2;

  string firstPart = "";
  string secondPart = "";

  if (length % 2 == 0) {
    for (int i = 0; i < middle; i++) {
      firstPart += word[i];
    }
    for (int i = length - 1; i >= middle; i--) {
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

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  string sentence;
  
  while (true) {
    getline(cin, sentence);
    if (sentence == "DONE") {
      break;
    }
    
    string x = removingCharacters(sentence);

    if (isPalindrome(x)) {
      cout<<"You won't be eaten!\n";
    }
    else {
      cout<<"Uh oh..\n";
    }
  }

  return 0;
  
}