#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<pair<int, int>> solutions;
    int k;

    while (cin>>k) {
        for (int i = k+1 ; i <= 2*k; i++) {
            if ((k * i) % (i - k) == 0) {
                solutions.push_back({i, ((k * i) / (i - k))});
            }
        }
        cout<<solutions.size()<<"\n";
        for (int i = 0; i < (int)solutions.size(); i++) {
            cout<<"1/"<<k<<" = ";
            cout<<"1/"<<max(solutions[i].first, solutions[i].second)<<" + 1/"<<min(solutions[i].first, solutions[i].second)<<"\n";
        }
        solutions.clear();
    }




    return 0;
}