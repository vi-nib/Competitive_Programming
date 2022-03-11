#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int round;
  string correctAnswer, guess;
  set<char> correct;
  set<char> guessLetters;
  vector<char> previousGuesses;

  while (cin>>round) {
    if (round == -1) {
      break;
    }
    cout<<"Round "<<round<<"\n";
    int wrongGuessCounter = 0;
    cin>>correctAnswer>>guess;

    for (int i = 0; i < correctAnswer.size(); i++) {
      correct.insert(correctAnswer[i]);
    }

    bool verdictFound = false;

    for (int i = 0; i < guess.length(); i++) {
      char guess1 = guess[i];
      if (guessLetters.find(guess1) == guessLetters.end() && correct.find(guess1) != correct.end()) {
        guessLetters.insert(guess1);
        previousGuesses.push_back(guess1);
        if (guessLetters == correct) {
          cout<<"You win.\n";
          verdictFound = true;
          break;
        }
      }
      else {

        bool found = false;

        for (int j = 0; j < previousGuesses.size(); j++) {
          if (previousGuesses[j] == guess1) {
            found = true;
          }
        }

        if (found == false) {
          wrongGuessCounter++;
          previousGuesses.push_back(guess1);
          if (wrongGuessCounter == 7) {
            break;
          }
        }
      }
    }
    
    if (!verdictFound) {

      if (wrongGuessCounter >= 7) {
        cout<<"You lose.\n";
      }

      else if (guessLetters == correct) {
        cout<<"You win.\n";
      }

      else {
        cout<<"You chickened out.\n";
      }

    }

    previousGuesses.clear();
    guessLetters.clear();
    correct.clear();

  }

  return 0;
}