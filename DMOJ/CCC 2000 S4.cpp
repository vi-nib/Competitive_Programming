#include <bits/stdc++.h>
using namespace std;

vector<int> clubs;
int N;

int dp[5300];
bool dp_solved[5300];

int min_strokes(int distanceLeft) {

    if (dp_solved[distanceLeft]) {
        return dp[distanceLeft];
    }

    if (distanceLeft == 0) {
        return 0;
    }
    int answer = 5300;
    for (int i = 0; i < N; i++) {
        if (distanceLeft - clubs[i] >= 0) {
            int current_option = 1 + min_strokes(distanceLeft - clubs[i]);
            answer = min(answer, current_option); 
        }
    }

    dp_solved[distanceLeft] = true;

    return dp[distanceLeft] = answer;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int distance;

    cin>>distance;
    cin>>N;

    clubs.resize(N);

    for (int i = 0; i < N; i++) {
        cin>>clubs[i];
    }

    int solution = min_strokes(distance);

    if (solution >= 5300) {
        cout<<"Roberta acknowledges defeat."<<"\n";
    }
    else {
        cout<<"Roberta wins in "<<solution<<" strokes."<<"\n";
    }

    return 0;

}