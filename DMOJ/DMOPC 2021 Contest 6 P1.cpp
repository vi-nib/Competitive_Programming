#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> arr;

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string num;
    int D;
    cin>>D>>num;
    arr.resize(D);

    for (int i = 0; i < D; i++) {
        arr[i] = num[i] - '0';
    }

    for (int i = 0; i < D-1; i++) {
        if (arr[i+1] > arr[i]) {
            swap(arr[i], arr[i+1]);
            break;
        }
    }

    for (int i = 0; i < D; i++) {
        cout<<arr[i];
    }
    cout<<"\n";

    return 0;

}