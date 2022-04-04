#include <bits/stdc++.h>
using namespace std;

#define int long long

int numbers[1001];

void minSum(int sum, int n) {

    int best = 1e6;
    int current;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            current = numbers[i] + numbers[j];
            if (abs(current - sum) < abs(best - sum)) {
                best = current;
            }
        }
    }
    cout<<"Closest sum to "<<sum<<" is "<<best<<".\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, q;

    int caseNum = 1;

    while (cin>>n && n != 0) {
        memset(numbers, 0, sizeof(numbers));
        for (int i = 0; i < n; i++) {
            cin>>numbers[i];
        }
        sort(numbers, numbers+n);
        cin>>m;
        cout<<"Case "<<caseNum<<":\n";
        for (int i = 0; i < m; i++) {
            cin>>q;
            minSum(q, n);
        }
        caseNum++;
    } 

    return 0;
    
}