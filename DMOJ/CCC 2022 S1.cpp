#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    cin>>N;
    int count = 0;

    for (int i = 0; i <= (N/4); i++) {
        if ((N - (4 * i)) % 5 == 0) {
            count++;
        }
    }

    cout<<count<<"\n";

    return 0;
    
}