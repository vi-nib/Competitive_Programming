#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> a;

bool dp_solved[100001];
bool dp[100001];

bool winning(int stones_left) {
    if (dp_solved[stones_left]) {
        return dp[stones_left];
    }

    int answer = false;

    for (int i = 0; i < N; i++) {
        if (stones_left - a[i] >= 0) {
            bool choice = winning(stones_left - a[i]);
            if (!choice) {
                answer = true;
                break;
            }
        }
    }

    dp_solved[stones_left] = true;
    return dp[stones_left] = answer;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin>>N>>K;

    a.resize(N);

    for (int i = 0; i < N; i++) {
        cin>>a[i];
    }

    if (winning(K)) {
        cout<<"First";
    }
    else {
        cout<<"Second";
    }

    cout<<"\n";

    return 0;

}