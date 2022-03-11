#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin>>K;

    while (K != 0) {

        int N, M;
        cin>>N>>M;

        while (K--) {
            int x, y;
            cin>>x>>y;
            if (x == N || y == M) {
                cout<<"divisa\n";
            }
            else if (x < N && y > M) {
                cout<<"NO\n";
            }
            else if (x > N && y > M) {
                cout<<"NE\n";
            }
            else if (x < N && y < M) {
                cout<<"SO\n";
            }
            else {
                cout<<"SE\n";
            }
        }

        cin>>K;
}




    return 0;
}