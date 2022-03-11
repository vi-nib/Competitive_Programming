#include <bits/stdc++.h>
using namespace std;

int n;
map<int, vector<int>> adj;

int dp[10000];
bool dp_solved[100000];

int num_options(int current) {

    if (current == n) {
        return 1;
    }

    if (dp_solved[current]) {
        return dp[current];
    }

    int count = 0;

    for (auto next : adj[current]) {
        count += num_options(next);
    }

    dp_solved[current] = true;

    return dp[current] = count;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    bool allowed = true;

    while (true) {
        int x, y;
        cin>>x>>y;
        if (x == 0 && y == 0) {
            allowed = false;
            break;
        }
        adj[x].push_back(y);
    }

    cout << num_options(1) << "\n";

    return 0;

}