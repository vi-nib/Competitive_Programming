#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;

    map<int, int> frequencyOfPlanets;

    for (int i = 0; i < n; i++) {
        int planetType;
        cin>>planetType;

        int frequency = frequencyOfPlanets[planetType];
        cout<<frequency<<"\n";

        frequencyOfPlanets[planetType]++;

    }

    int size;
    size = frequencyOfPlanets.size();

    cout<<size<<"\n";
    
    return 0;
    
}