#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;

int dp[3005][3005];
bool dp_solved[3005][3005];

int largest_value(int start, int end) {

    if (dp_solved[start][end]) {
        return dp[start][end];
    }

    if (start == end) {
        return a[start];
    }

    // Option 1: taking from start

    int option1 = a[start] - largest_value(start + 1, end);

    // Option 2: taking from end

    int option2 = a[end] - largest_value(start, end - 1);

    dp_solved[start][end] = true;

    return dp[start][end] = max(option1, option2);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    a.resize(N+1);

    for (int i = 1; i <= N; i++) {
        cin>>a[i];
    }

    cout<<largest_value(1, N)<<"\n";

    return 0;

}