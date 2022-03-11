#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> heights(n+1);
    vector<int> widths(n);

    long double area = 0.0;

    for (int i = 0; i <= n; i++) {
        cin>>heights[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>widths[i];
    }

    for (int i = 0; i < n; i++) {
        double bottom = min(heights[i], heights[i+1]) * widths[i]; 
        double top = abs(heights[i] - heights[i+1]) * widths[i]; 
        area += (double) bottom + 0.5 * top;
    }

    printf("%Lf\n", area);

    return 0;
    
}