#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int gates, planes;
    cin>>gates>>planes;

    set<int> freeGates;

    for (int i = 1; i <= gates; i++) {
        freeGates.insert(-i);
    }

    int planesAccomodated = 0;

    for (int i = 1; i <= planes; i++) {
        int gateI;
        cin>>gateI;

        if (freeGates.lower_bound(-gateI) != freeGates.end() && *freeGates.lower_bound(-gateI) >= -gateI) {
            planesAccomodated++;
            freeGates.erase(freeGates.lower_bound(-gateI));
        }
        else {
            break;
        }
    }

    cout<<planesAccomodated<<"\n";

    return 0;
    
}