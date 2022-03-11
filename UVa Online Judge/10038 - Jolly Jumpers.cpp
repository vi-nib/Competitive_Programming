#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int arr[3002];
    
    
    while (cin>>n) {
        set<int> differences;
        arr[0] = n;
        for (int i = 1; i <= n; i++) {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++) {
            differences.insert(abs(arr[i] - arr[i+1]));
        }
        bool numberNotFound = false;
        for (int i = 1; i < n; i++) {
            if (find(differences.begin(), differences.end(), i) != differences.end()) {
                continue;
            }
            else {
                numberNotFound = true;
                break;
            }
        }

        if (numberNotFound) {
            cout<<"Not jolly\n";
        }
        else {
            cout<<"Jolly\n";
        }
   
    }

    return 0;
    
}