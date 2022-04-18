#include <bits/stdc++.h>
using namespace std;

#define int long long

struct xy {
    int xPos, yPos;
};

string grid[10000][1];

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int M;
    vector<xy> locs1;
    vector<xy> locs3;
    vector<int> minDistances;

    while (cin>>M) {
        for (int i = 0; i < M; i++) {
            cin>>grid[i][0];
            for (int j = 0; j < M; j++) {
                if (grid[i][0][j] == '1') {
                    xy one = {j, i};
                    locs1.push_back(one);
                }
                else if (grid[i][0][j] == '3') {
                    xy three = {j, i};
                    locs3.push_back(three);
                }
            }
        }

        int minDist = 1e6, currDist = 0;

        for (int i = 0; i < (int)locs1.size(); i++) {
            for (int j = 0; j < (int)locs3.size(); j++) {
                currDist = abs(locs1[i].xPos - locs3[j].xPos) + abs(locs1[i].yPos - locs3[j].yPos);
                minDist = min(currDist, minDist);
            }
            minDistances.push_back(minDist);
            minDist = 1e6;
        }

        int maxDist = 0;
        
        for (int i = 0; i < (int)minDistances.size(); i++) {
            maxDist = max(maxDist, minDistances[i]);
        }

        cout<<maxDist<<"\n";

        locs1.clear();
        locs3.clear();
        minDistances.clear();

    }

    return 0;

}