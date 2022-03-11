#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N, Q;
    cin>>N>>Q;

    int grid[N+5][N+5]; // contains num cookies
    int counter = 0; // num sprinkles

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            grid[i][j] = 0;
        }
    }

    while (Q--) {
        int type;
        cin>>type;
        if (type == 1) {
            int x, y;
            cin>>x>>y;
            grid[y][x] += 1;
        }
        if (type == 2) {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            for (int i = y1; i <= y2; i++) {
                for (int j = x1; j <= x2; j++) {
                    if (grid[i][j] > 0) {
                        counter += grid[i][j];
                    }
                }
            }
        }
    }

   cout<<counter<<"\n";

    return 0;
    
}