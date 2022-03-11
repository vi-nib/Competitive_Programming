#include <bits/stdc++.h>
using namespace std;

bool dp[35][35][35][35];
bool dp_solved[35][35][35][35];

/*

Option 1: AABDD
Option 2: ABCD
Option 3: CCD
Option 4: BBB
Option 5: AD

*/

// True means a win for the person who didn't do the last move, false means a loss for the person who didn't do the last move

bool game(int numA, int numB, int numC, int numD) {

    if (numA < 0 || numB < 0 || numC < 0 || numD < 0) {
        return true;
    }

    if (numA + numB + numC + numD == 0) {
        return false;
    }

    if (dp_solved[numA][numB][numC][numD]) {
        return dp[numA][numB][numC][numD];
    }

    bool option1 = game(numA - 2, numB - 1, numC, numD - 2);
    bool option2 = game(numA - 1, numB - 1, numC - 1, numD - 1);
    bool option3 = game(numA, numB, numC - 2, numD - 1);
    bool option4 = game(numA, numB - 3, numC, numD);
    bool option5 = game(numA - 1, numB, numC, numD - 1);

    bool answer = false;

    if (!option1 || !option2 || !option3 || !option4 || !option5) {
        answer = true;
    }

    dp_solved[numA][numB][numC][numD] = true;
    return dp[numA][numB][numC][numD] = answer;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--) {

    int A, B, C, D;

    cin>>A>>B>>C>>D;

    bool choice = game(A, B, C, D);

    if (choice) {
        cout<<"Patrick"<<"\n";
    }
    else {
        cout<<"Roland"<<"\n";
    }

    }

    return 0;

}