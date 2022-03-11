#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("input.txt", "w", stdout);

    int N;
    cin>>N;

    multiset<int> blue;
    multiset<int> green;

    while (N--) {
        int B, SG, SB;
        cin>>B>>SG>>SB;

        for (int i = 0; i < SG; i++) {
            int gr;
            cin>>gr;
            green.insert(gr);
        }
        for (int i = 0; i < SB; i++) {
            int bl;
            cin>>bl;
            blue.insert(bl);
        }
        while (!green.empty() && !blue.empty()) {
            vector<int> gWin;
            vector<int> bWin;
            for (int i = 0; i < B; i++) {
                auto g = green.end();
                auto b = blue.end();
                g--;
                b--;
                int gVal = *g;
                int bVal = *b;
                if (gVal > bVal) {
                    gWin.push_back(gVal-bVal);
                    green.erase(g);
                    blue.erase(b);
                }
                else if (bVal > gVal) {
                    bWin.push_back(bVal-gVal);
                    green.erase(g);
                    blue.erase(b);
                }
                else {
                    green.erase(g);
                    blue.erase(b);
                }
                if (green.empty() || blue.empty()) {
                break;
                }
            }
            
            for (int i = 0; i < gWin.size(); i++) {
                green.insert(gWin[i]);
            }
            for (int i = 0; i < bWin.size(); i++) {
                blue.insert(bWin[i]);
            }
            
            int count = 0;
            auto bC = blue.rbegin();
            auto gC = green.rbegin();
            if (green.empty() && blue.empty()) {
                cout<<"green and blue died\n";
            }
            else if (green.empty()) {
                cout<<"blue wins\n";
                while (bC != blue.rend()) {
                    cout<<*bC<<"\n";
                    bC++;
                }
               
            }
            else if (blue.empty()) {
                cout<<"green wins\n";
                while (gC != green.rend()) {
                    cout<<*gC<<"\n";
                    gC++;
                }

            }
        }
        blue.clear();
        green.clear();

        if (N > 0) {
            cout<<"\n";
        }

    }

    return 0;
    
}