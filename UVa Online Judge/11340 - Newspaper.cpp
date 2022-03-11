#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K, M;
    cin>>N;

    while (N--) {
        cin>>K;
        map<char, int> costs;
        
        for (int i = 0; i < K; i++) {
            char character;
            int fee;
            cin>>character>>fee;
            costs[character] = fee;
        }
        cin>>M;
        int counter = 0;
        string line;
        for (int j = 0; j <= M; j++) {
            getline(cin, line);
            for (int i = 0; i < line.length(); i++) {
                if (costs.find(line[i]) != costs.end()) {
                    counter += costs[line[i]];
                }
            }
        }

        int remainder = counter%100;
        int dollars = counter/100;

        if (dollars == 0) {
            if (remainder < 10) {
                cout<<"0.0"<<remainder<<"$\n";
            }
            else {
                cout<<"0."<<remainder<<"$\n";
            }
        }

        else {
            if (remainder < 10) {
                cout<<dollars<<".0"<<remainder<<"$\n";
            }
            else {
                cout<<dollars<<"."<<remainder<<"$\n";
            }
        }

    }

    return 0;
    
}