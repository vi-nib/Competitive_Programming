#include <bits/stdc++.h>
using namespace std;

int dp[255][255][255];
bool dp_solved[255][255][255];

int num_ways(int piecesLeft, int peopleLeft, int minTake) {

    if (dp_solved[piecesLeft][peopleLeft][minTake]) {
        return dp[piecesLeft][peopleLeft][minTake];
    }
    if (peopleLeft == 0) {
        if (piecesLeft == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int answer = 0;

    for (int i = minTake; i <= piecesLeft; i++) {
        answer += num_ways(piecesLeft-i, peopleLeft-1, i);
    }

    dp_solved[piecesLeft][peopleLeft][minTake] = true;

    return dp[piecesLeft][peopleLeft][minTake] = answer;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin>>n>>k;

    cout<<num_ways(n, k, 1)<<"\n";
    
    return 0;

}