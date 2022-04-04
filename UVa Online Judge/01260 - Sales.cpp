#include <bits/stdc++.h>
using namespace std;

#define int long long

int sales[1001];

int solve(int n) {

    int sum = 0, count = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sales[j] <= sales[i]) {
                count++;
            }
        }
        sum += count;
        count = 0;
    }

    return sum;

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;

    while (T--) {
        int N;
        cin>>N;
        memset(sales, 0, sizeof(sales));
        for (int i = 0; i < N; i++) {
            cin>>sales[i];
        }
        int ans = solve(N);
        cout<<ans<<"\n";
    }




    return 0;
}