#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin>>a>>b;

    map<char, int> frequency_a;
    map<char, int> frequency_b;

    for (int i = 0; i < (int)a.size(); i++) {
        frequency_a[a[i]]++;
    }

    for (int i = 0; i < (int)b.size(); i++) {
        frequency_b[b[i]]++;
    }

    for (auto i : frequency_b) {
        char c = i.first;
        int frequency = i.second;

        if (c != '*' && frequency > frequency_a[c]) {
            cout<<"N\n";
            return 0;
        }
    }

    int countAsterix = frequency_b['*'];

    for (auto i : frequency_a) {
        char c = i.first;
        int frequency = i.second;

        countAsterix -= frequency - frequency_b[c];
    }

    if (countAsterix == 0) {
        cout<<"A\n";
    }
    else {
        cout<<"N\n";
    }

    return 0;

}


