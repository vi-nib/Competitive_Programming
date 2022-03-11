#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int numQuarters;
    cin>>numQuarters;

    int numTimesPlayedSincePayingMachine1;
    cin>>numTimesPlayedSincePayingMachine1;

    int numTimesPlayedSincePayingMachine2;
    cin>>numTimesPlayedSincePayingMachine2;

    int numTimesPlayedSincePayingMachine3;
    cin>>numTimesPlayedSincePayingMachine3;

    int count = 0;

    while (numQuarters > 0) {
        count++;
        numQuarters--;
        if (numQuarters == 0) {
            break;
        }
        numTimesPlayedSincePayingMachine1++;
        if (numTimesPlayedSincePayingMachine1 % 35 == 0) {
            numQuarters += 30;
        }
        count++;
        numQuarters--;
        if (numQuarters == 0) {
            break;
        }
        numTimesPlayedSincePayingMachine2++;
        if (numTimesPlayedSincePayingMachine2 % 100 == 0) {
            numQuarters += 60;
        }
        count++;
        numQuarters--;
        if (numQuarters == 0) {
            break;
        }
        numTimesPlayedSincePayingMachine3++;
        if (numTimesPlayedSincePayingMachine3 % 10 == 0) {
            numQuarters += 9;
        }

    }

    cout<<"Martha plays "<<count<<" times before going broke."<<"\n";

    return 0;

}