#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> P;
vector<int> W;
vector<int> D;

int N;

int totalWalkingTime(int position) {

    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (P[i] + D[i] >= position && P[i] - D[i] <= position) {
            continue;
        }
        else if (P[i] + D[i] < position) {
            sum += W[i] * (position - (P[i] + D[i]));
        }
        else if (P[i] - D[i] > position) {
            sum += W[i] * ((P[i] - D[i]) - position);
        }
    }

    return sum;

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>N;

    P.resize(N);
    W.resize(N);
    D.resize(N);

    for (int i = 0; i < N; i++) {
        cin>>P[i]>>W[i]>>D[i];
    }

    int low = 1e9;
    int high = -1;

    for (int i = 0; i < N; i++) {
        high = max(high, P[i]);
        low = min(low, P[i]);
    }

    int time;

    while (low <= high) {
        int mid = (low + high) / 2;
        time = totalWalkingTime(mid);
        int time1 = totalWalkingTime(mid+1);
        int time2 = totalWalkingTime(mid-1);
        if (time <= time1 && time <= time2) {
            break;
        }
        if (time2 < time) {
            high = mid - 1;
        }
        if (time1 < time) {
            low = mid + 1;
        }
    }

    cout<<time<<"\n";
    
    return 0;

}