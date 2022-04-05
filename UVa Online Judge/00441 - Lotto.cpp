#include <bits/stdc++.h>
using namespace std;

int S[14];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int k;

    int iterations = 0;
    
    while (cin>>k && k != 0) {
        
        if (iterations != 0) {
            cout<<"\n";
        }
        iterations++;

        memset(S, 0, sizeof(S));

        for (int i = 0; i < k; i++) {
            cin>>S[i];
        }

        for (int i = 0; i < k; i++) {
            for (int j = i+1; j < k; j++) {
                for (int t = j+1; t < k; t++) {
                    for (int l = t+1; l < k; l++) {
                        for (int w = l+1; w < k; w++) {
                            for (int v = w+1; v < k; v++) {
                                cout<<S[i]<<" "<<S[j]<<" "<<S[t]<<" "<<S[l]<<" "<<S[w]<<" "<<S[v]<<"\n";
                            }
                        }
                    }
                }
            }
        }

    }

    return 0;
    
}