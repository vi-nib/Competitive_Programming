#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin>>N>>W;

    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin>>weights[i]>>values[i];
    }

    vector<int> dp(W+1);

    for (int i = N - 1; i >= 0; i--) {
        vector<int> new_dp(W+1);
        for (int j = 0; j <= W; j++) {
            int notTake = dp[j];
            int take = -1;
            if (j - weights[i] >= 0) {
                take = values[i] + dp[j - weights[i]];
            }
            new_dp[j] = max(notTake, take);
        }
        dp = new_dp;
    }

    cout<<dp[W]<<"\n";
    
    return 0;

}