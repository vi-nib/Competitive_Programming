#include <bits/stdc++.h>
using namespace std;

void performShift(string word, int numTimes, string target) {
    string a = word;
    if ((int)target.find(a) != -1) {
        cout<<"yes\n";
        return;
    }

    while (numTimes--) {
        a += a[0];
        a.erase(a.begin());
        if ((int)target.find(a) != -1) {
            cout<<"yes\n";
            return;
        }
    }

    cout<<"no\n";

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string T, S;
    cin>>T>>S;

    performShift(S, (int)S.length()-1, T);

    return 0;

}