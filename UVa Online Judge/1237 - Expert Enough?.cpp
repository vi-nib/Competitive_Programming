#include <bits/stdc++.h>
using namespace std;

struct carModel {

    string name;
    int lowestPrice;
    int highestPrice;

};

vector<carModel> database;

string solver(int price, int numCars) {
    string answer = "";
    for (int i = 0; i < numCars; i++) {
        if (database[i].lowestPrice <= price && database[i].highestPrice >= price) {
            if (answer.size() == 0) {
                answer = database[i].name;
            }
            else {
                return "UNDETERMINED";
            }
        }
    }
    if (answer.size() > 0) {
        return answer;
    }

    return "UNDETERMINED";
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, D, L, H, Q, P;
    string M;
    cin>>T;

    for (int r = 0; r < T; r++) {
        cin>>D;
        database.resize(D);
        for (int i = 0; i < D; i++) {
            cin>>M>>L>>H;
            database[i].name = M;
            database[i].lowestPrice = L;
            database[i].highestPrice = H;
        }
        cin>>Q;
        for (int i = 1; i <= Q; i++) {
            cin>>P;
            string ans = solver(P, D);
            cout<<ans<<"\n";
        }
        if (r != T-1) {
            cout<<"\n";
        }
        database.clear();
    }

    return 0;
}