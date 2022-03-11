#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    
    while (cin>>n) {
        if (n == 0) {
            break;
        }
        multiset<int> bills;
        int count = 0;
        while (n--) {
            cin>>k;
            for (int i = 0; i < k; i++) {
                int bill;
                cin>>bill;
                bills.insert(bill);
            }
            auto start = bills.begin();
            auto end = bills.end();
            end--;
            count += *end - *start;
            bills.erase(end);
            bills.erase(start);
        }
        cout<<count<<"\n";
    }

    return 0;
    
}