#include <bits/stdc++.h>
using namespace std;

// n is number of bowling pins, k is number of bowling balls, w is the width of the bowling ball.

int n, k, w;
vector<int> pins;
vector<int> prefix_sum;
int dp[30005][505];
bool dp_solved[30005][505];

int max_score(int index, int balls_left) {

    if (dp_solved[index][balls_left]) {
        return dp[index][balls_left];
    }

    if (index > n || balls_left == 0) {
        return 0;
    }

    int leave = max_score(index+1, balls_left);

    int take = (prefix_sum[min(n, index + w - 1)] - prefix_sum[index - 1]) + max_score(index + w, balls_left - 1);

    dp_solved[index][balls_left] = true;

    return dp[index][balls_left] = max(leave, take);

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--) {

    cin>>n>>k>>w;

    pins.clear();
    prefix_sum.clear();

    pins.resize(n+1);
    prefix_sum.resize(n+1);

    for (int i = 1; i <= n; i++) {
        cin>>pins[i];
    }

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + pins[i];
    }

    cout<<max_score(1, k)<<"\n";

    memset(dp, 0, sizeof(dp));
    memset(dp_solved, false, sizeof(dp_solved));

}

    return 0;

}