#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int currentSquare = 1;

    int x;
    cin>>x;

    while (currentSquare != 100 || x != 0) {

        if (x == 0) {
            cout<<"You Quit!"<<"\n";
            break;
        }

        currentSquare += x;

        if (currentSquare == 9) {
            currentSquare = 34;
        }
        if (currentSquare == 40) {
            currentSquare = 64;
        }
        if (currentSquare == 67) {
            currentSquare = 86;
        }
        if (currentSquare == 54) {
            currentSquare = 19;
        }
        if (currentSquare == 90) {
            currentSquare = 48;
        }
        if (currentSquare == 99) {
            currentSquare = 77;
        }

        if (currentSquare > 100) {
            currentSquare -= x;
        }

        if (currentSquare == 100) {
            cout<<"You are now on square 100"<<"\n";
            cout<<"You Win!"<<"\n";
            break;
        }

        cout<<"You are now on square "<<currentSquare<<"\n";

        cin>>x;

    }
    
    return 0;

}