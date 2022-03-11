#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string code;

    while (cin>>code) {
        if (code == "#") {
            break;
        }
        bool permutationPossible = next_permutation(code.begin(), code.end());
        if (permutationPossible) {
            cout<<code<<"\n";
        }
        else {
            cout<<"No Successor\n";
        }
    }

    return 0;
    
}