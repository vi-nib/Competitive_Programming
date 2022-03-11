#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int H, S, Q;
    cin>>H>>S>>Q;

    for (int i = 0; i < Q; i++) {
        H -= S;
        cout<<H<<"\n";
    }

    return 0;

}