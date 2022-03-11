#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int A, K;
    cin>>A>>K;

    vector<pair<int, string>> assignments;

    while (A--) {
        int day;
        string assignment;
        cin>>day>>assignment;
        assignments.push_back({day, assignment});
    }

    int last = 0;
    int current;

    while (K--) {
        cin>>current;
        for (int i = 0; i < (int)assignments.size(); i++) {
            if (assignments[i].first > last && assignments[i].first <= current) {
                cout<<assignments[i].second<<"\n";
            }
        }
        last = current;
    }

    return 0;

}