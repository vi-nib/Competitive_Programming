#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin>>n>>m;

  int numPiecesCastle1 = n;
  int numPiecesCastle2 = n;

  for (int i = 1; i <= m; i++) {

    int player1Score, player2Score, player3Score, player4Score;
    cin>>player1Score>>player2Score>>player3Score>>player4Score;

    int team1Score = player1Score * player2Score;
    int team2Score = player3Score * player4Score;

    numPiecesCastle1 -= team2Score;
    numPiecesCastle2 -= team1Score;

    if (numPiecesCastle1 <= 0 && numPiecesCastle2 <= 0) {
      cout<<"It's a tie at round "<<i<<"!\n";
      break;
    }

    else if (numPiecesCastle1 <= 0) {
      cout<<"Team 2 wins at round "<<i<<"!\n";
      break;
    }

    else if (numPiecesCastle2 <= 0) {
      cout<<"Team 1 wins at round "<<i<<"!\n";
      break;
    }

    else if (numPiecesCastle1 > 0 && numPiecesCastle2 > 0 && i == m) {
      cout<<"Oh no!\n";
    }

  }

  return 0;
  
}