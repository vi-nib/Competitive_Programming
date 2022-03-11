#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin>>T;

    for (int i = 1; i <= T; i++) {
        int N;
        cin>>N;
        int maxVal = 0;
        for (int i = 0; i < N; i++) {
            int speed;
            cin>>speed;
            maxVal = max(maxVal, speed);
        }
        cout<<"Case "<<i<<": "<<maxVal<<"\n";
    }

    return 0;
}