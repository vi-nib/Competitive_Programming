#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    vector<int> numsEven;
    vector<int> numsOdd;

    int num;

    for (int i = 0; i < N; i++) {
        cin>>num;
        if (num % 2 == 0) {
            numsEven.push_back(num);
        }
        else {
            numsOdd.push_back(num);
        }
    }

    int count = ((int)numsEven.size() / 2) + ((int)numsOdd.size() / 2);

    cout<<count<<"\n";

    return 0;
    
}