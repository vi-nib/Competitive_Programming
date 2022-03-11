#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;

    while (cin>>N>>M) {
        if (N == 0 && M == 0) {
            break;
        }
        set<int> collection;
        for (int i = 0; i < (N+M); i++) {
            int jack;
            cin>>jack;
            collection.insert(jack);
        }
        
        int totalSize = N+M;
        int newSize = collection.size();
        int numDuplicates = totalSize - newSize;
        cout<<numDuplicates<<"\n";
        
    }

    return 0;
    
}