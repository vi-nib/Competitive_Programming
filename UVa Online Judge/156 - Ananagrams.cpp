#include <bits/stdc++.h>
using namespace std;

vector<bool> checkAnagram(vector<string> &words) {

  vector<string> wordsCopy = words;
  vector<bool> isAnagram;

  for (int i = 0; i < wordsCopy.size(); i++) {
    string x = wordsCopy[i];
    for (int j = 0; j < wordsCopy[i].length(); j++) {
      wordsCopy[i][j] = tolower(wordsCopy[i][j]);
    }
  }

  for (int i = 0; i < wordsCopy.size(); i++) {
    sort(wordsCopy[i].begin(), wordsCopy[i].end());
  }

  for (int i = 0; i < wordsCopy.size(); i++) {
    string x = wordsCopy[i];
    wordsCopy[i] += ' ';
    if (find(wordsCopy.begin(), wordsCopy.end(), x) == wordsCopy.end()) {
      isAnagram.push_back(true);
    }
    else {
      isAnagram.push_back(false);
    }
    wordsCopy[i].pop_back();
    
  }

  return isAnagram;

}


vector<string> cleanString(string words) {

  string newString = words;

  vector<string> newWords;

  for (int i = 0; i < newString.length(); i++) {
    if (newString[0] == ' ') {
      newString.erase(0, 1);
      i -= 1;
    }
    if (newString[i] == ' ' && newString[i+1] == ' ') {
      newString.erase(i, 1);
      i -= 1;
    }
  }

  int indexFirstSpace = newString.find(' ');
  string firstWord = newString.substr(0, indexFirstSpace);
  newWords.push_back(firstWord);

  newString.erase(0, indexFirstSpace);

  for (int i = 0; i < newString.length(); i++) {
    if (newString[i] == ' ') {
      int nextSpace = newString.find(" ", i+1, 1);
      string word = newString.substr(i+1, nextSpace - (i+1));
      newWords.push_back(word);
    }
  }

  newWords.erase(newWords.end()-1, newWords.end());

  return newWords;

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  string line;

  string allWords;
  
  while (getline(cin, line)) {
    if (line[0] == '#') {
      break;
    }
    line += ' ';
    allWords += line;
  }

  vector<string> newWords = cleanString(allWords);
  sort(newWords.begin(), newWords.end());

  vector<bool> anagrams = checkAnagram(newWords);

  for (int i = 0; i < newWords.size(); i++) {
    if (anagrams[i]) {
      cout<<newWords[i]<<"\n";
    }
  }

  return 0;
}