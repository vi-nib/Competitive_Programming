#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  vector<pair<int, int>> snakesAndLadders;
  vector<int> playersScores(1000005);

  while (t--) {
    int a, b, c;
    cin>>a>>b>>c;
    for (int i = 1; i <= a; i++) {
      playersScores[i] = 1;
    }
    bool gameOver = false;
    while (b--) {
      int start, end;
      cin>>start>>end;
      snakesAndLadders.push_back({start, end});
    }

    int index = 1;
    while (c--) {

        int points;
        cin>>points;
        playersScores[index] += points;

        int bottomSnakeTopLadder; 
        bool foundSnakeLadder = false;

        for (int i = 0; i < snakesAndLadders.size(); i++) {
          if (snakesAndLadders[i].first == playersScores[index]) {
            bottomSnakeTopLadder = snakesAndLadders[i].second;
            foundSnakeLadder = true;
          }
        }

        if (!foundSnakeLadder) {
          bottomSnakeTopLadder = -1;
        }

        if (bottomSnakeTopLadder != -1) {
          playersScores[index] = bottomSnakeTopLadder;
        }

        if (playersScores[index] >= 100) {
          playersScores[index] = 100;
          gameOver = true;
        }

        if (!gameOver) {
          index++;
          if (index > a) {
            index = 1;
          }
        }

        else {
          playersScores[1000003] = -1e6;
          index = 1000003;
        }
        
    }

    for (int i = 1; i <= a; i++) {
      cout<<"Position of player "<<i<<" is "<<playersScores[i]<<".\n";
    }

    snakesAndLadders.clear();
    playersScores.clear();

  }

  return 0;
  
}