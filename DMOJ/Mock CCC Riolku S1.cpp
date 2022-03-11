#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, consonant, vowel;
    cin>>n>>consonant>>vowel;

    string word;

    cin>>word;

    int countC = 0;
    int countV = 0;

    bool no = false;

    for (int i = 0; i < n; i++) {
        char letter = word[i];
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
            countV++;
            countC = 0;
            if (countV > vowel) {
                cout<<"NO"<<"\n";
                no = true;
                break;
            }
        }
        else if (letter == 'y') {
            countV++;
            countC++;
            if (countV > vowel) {
                cout<<"NO"<<"\n";
                no = true;
                break;
            }
            else if (countC > consonant) {
                cout<<"NO"<<"\n";
                no = true;
                break;
            }
        }
        else {
            countC++;
            countV = 0;
            if (countC > consonant) {
                cout<<"NO"<<"\n";
                no = true; 
                break;
            }
        }
    }

    if (no == false) {
        cout<<"YES"<<"\n";
    } 

    return 0;

}