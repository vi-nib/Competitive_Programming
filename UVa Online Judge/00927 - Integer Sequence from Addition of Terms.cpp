#include <bits/stdc++.h>
using namespace std;

#define int long long

int C, d, k;
int a_n[21];

void print(int N) {
    for (int i = 0; i < N; i++) {
        cout<<a_n[i]<<" ";
    }
}

int solve(int x, int N) {
    int answer = a_n[0];
    for (int i = 1; i < N; i++) {
        answer += (a_n[i] * pow(x, i));
    }
    return answer;
}

int findKthValue(int K, int D) {

    int counter = 0;
    int answer = 0;

    for (int i = 0; i < 1e6; i++) {
        counter += i * D;
        if (K >= counter && K <= (counter + ((i+1)*D))) {
            answer = (i+1);
            break;
        }
    }

    return answer;

}

signed main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>C;

    while (C--) {
        memset(a_n, 0, sizeof(a_n));
        int numExp;
        cin>>numExp;
        for (int i = 0; i <= numExp; i++) {
            cin>>a_n[i];
        }
        cin>>d>>k;
        int x = findKthValue(k, d);
        int ans = solve(x, numExp+1);
        cout<<ans<<"\n";
    }

    return 0;

}