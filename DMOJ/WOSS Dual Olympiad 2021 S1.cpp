#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    map<char, char> cipher;

    string a;
    getline(cin, a);

    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] == ' ') {
            a.erase(a.begin()+i);
            i -= 1;
        }
    }

    cin>>ws;

    for (int i = 0; i < 10; i++) {
        cipher['0'+i] = a[i];
    }

    int N;
    cin>>N;

    cin>>ws;

    string b;
    getline(cin, b);

    for (int i = 0; i < (int)b.length(); i++) {
        if (b[i] == ' ') {
            b.erase(b.begin()+i);
            i -= 1;
        }
    }

    for (int i = 0; i < N; i++) {
        char l = b[i];
        cout<<cipher[l];
    }
    cout<<"\n";

    return 0;
}