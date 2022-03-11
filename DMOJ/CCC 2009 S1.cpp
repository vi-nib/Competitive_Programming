#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a;
    cin>>a;
    ll b;
    cin>>b;

    int sRootA = sqrt(a);
    int sRootB = sqrt(b);
    int cRootA = cbrt(a);
    int cRootB = cbrt(b);

    int count = 0;

    for (int i = sRootA; i <= sRootB; i++) {
        for (int g = cRootA; g <= cRootB; g++) {
            if (i * i == g * g * g) {
                count++; 
            }
        }
    }

    cout<<count<<"\n";
    
    return 0;

}