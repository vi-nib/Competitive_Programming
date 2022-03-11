#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    int num;
    cin >> num;

    int value = 2 * num;

    char answers[value];

    for (int i = 0; i < value; i++) {
        cin >> answers[i];
    }

    for (int j = 0; j < value - num; j++) {
        if (answers[j] == answers[j + num]) {
            count++;
        }
    }

    cout<<count;

    return 0;

}