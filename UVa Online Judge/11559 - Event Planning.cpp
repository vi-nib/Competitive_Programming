#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, B, H, W;
    
    while (cin>>N>>B>>H>>W) {
        int cost = B+1;
        for (int i = 0; i < H; i++) {
            int roomCost;
            cin>>roomCost;
            for (int i = 0; i < W; i++) {
                int numRoomsAvailable;
                cin>>numRoomsAvailable;
                if (numRoomsAvailable >= N) {
                    int potentialCost = N * roomCost;
                    cost = min(cost, potentialCost);
                }
            }
        }
        if (cost == B + 1) {
            cout<<"stay home\n";
        }
        else {
            cout<<cost<<"\n";
        }
    }


    return 0;
}