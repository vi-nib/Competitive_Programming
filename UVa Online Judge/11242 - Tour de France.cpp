#include <bits/stdc++.h>
using namespace std;

int front[1000001];
int back[1000001];
double driveRatio[1000001];

int findDriveRatios(int n, int m) {

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double a = double(back[i]) / double(front[j]);
            driveRatio[index] = a;
            index++;
        }
    }

    sort(driveRatio, driveRatio + index);
    return index;

}

double findSpread(int length) {

    double maxSpread = 0, spread = 0;

    for (int i = 0; i < length-1; i++) {
        spread = driveRatio[i+1] / driveRatio[i];
        maxSpread = max(maxSpread, spread);
    }

    return maxSpread;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int f, r, ft, rt;
    while (cin>>f && f != 0) {

        memset(front, 0, sizeof(front));
        memset(back, 0, sizeof(back));
        memset(driveRatio, 0, sizeof(driveRatio));

        cin>>r;

        for (int i = 0; i < f; i++) {
            cin>>front[i];
        }
        for (int i = 0; i < r; i++) {
            cin>>back[i];
        }

        int length = findDriveRatios(r, f);
        double ans = findSpread(length);
        printf("%.2f\n", ans);

    }

    return 0;
    
}