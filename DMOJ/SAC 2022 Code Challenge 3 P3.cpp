#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> nums;

string findRightMostDigit(int a, int r) {

    string a1 = to_string(a);

    a1.insert(0, "0000000000");
    int l = (int)a1.length();

    return a1.substr(l-r, r);

}

bool sortingFunction(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void bobSort(int r) {

    for (int i = 0; i < N; i++) {
        int digit = stoi(findRightMostDigit(nums[i].first, r));
        nums[i].second = digit;
    }
    
    sort(nums.begin(), nums.end(), sortingFunction);
    for (int i = 0; i < N; i++) {
        cout<<nums[i].first;
        if (i != N-1) {
            cout<<" ";
        }
    }
    cout<<"\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    cin>>N;
    nums.assign(N, pair<int, int>());

    int a;

    for (int i = 0; i < N; i++) {
        cin>>a;
        nums[i] = {a, 0};
    }
    int maxVal = 0;
    for (int i = 0; i < N; i++) {
        maxVal = max(maxVal, nums[i].first);
    }

    int iterations = floor(log10((double)maxVal) + 1);
    
    for (int i = 1; i <= iterations; i++) {
        bobSort(i);
    }

    return 0;
    
}