#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
vector<bool> dp_solved(35);
vector<int> dp(35);

// A is min distance needed to drive per day
// B is max distance needed to drive per day

int A, B, N;

int num_ways(int currentLocation) {
    if (dp_solved[currentLocation]) {
        return dp[currentLocation];
    }
    if (currentLocation == N+13) {
        return 1;
    }

    int answer = 0;

    for (int i = currentLocation + 1; i <= N+13; i++) {
        if (motels[i] - motels[currentLocation] <= B && motels[i] - motels[currentLocation] >= A) {
            answer += num_ways(i);
        }
    }
    dp_solved[currentLocation] = true;
    return dp[currentLocation] = answer;
    
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>A>>B>>N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        motels.push_back(x);
    }

    sort(motels.begin(), motels.end());

    cout<<num_ways(0)<<"\n";

    return 0;

}