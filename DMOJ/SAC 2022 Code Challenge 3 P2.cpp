#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int M;
    cin>>M;

    int constant = 1 - M;

    double answer = (double)5 + sqrt(25 - 4*12*constant);

    answer /= 24.0;

    printf("%.6f\n", answer);

    return 0;

}