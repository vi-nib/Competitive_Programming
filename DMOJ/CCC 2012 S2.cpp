#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;

    string input;

    getline(cin, input);

    int length = input.length();

    int half = length / 2;

    int arabic[half];

    char roman[half];

    int romanValues[half];

    int finalValues[length];

    int counterA = 0;
    int counterR = 0;
    
    for (int i = 0; i < length; i += 2) {
        stringstream x(input.substr(i, 1));
        arabic[counterA] = 0;
        x >> arabic[counterA];
        counterA++;
    }

    for (int j = 1; j < length; j += 2) {
        roman[counterR] = input[j];
        if (roman[counterR] == 'I') {
            romanValues[counterR] = 1;
        }
        else if (roman[counterR] == 'V') {
            romanValues[counterR] = 5;
        }
        else if (roman[counterR] == 'X') {
            romanValues[counterR] = 10;
        }
        else if (roman[counterR] == 'L') {
            romanValues[counterR] = 50;
        }
        else if (roman[counterR] == 'C') {
            romanValues[counterR] = 100;
        }
        else if (roman[counterR] == 'D') {
            romanValues[counterR] = 500;
        }
        else {
            romanValues[counterR] = 1000;
        }

        counterR++;

    }

    int counterFinalA = 0;
    int counterFinalR = 1;

    for (int t = 0; t < half; t++) {
        finalValues[counterFinalA] = arabic[t];
        finalValues[counterFinalR] = romanValues[t];
        counterFinalA += 2;
        counterFinalR += 2;
    }

    for (int w = 0; w < length-1; w += 2) {
            sum += (finalValues[w] * finalValues[w+1]);
    }

    for (int q = 1; q < length-2; q += 2) {
        if (finalValues[q] < finalValues[q+2]) {
            sum -= (2 * (finalValues[q-1] * finalValues[q]));
        }
    }

   cout<<sum<<endl;

   return 0;

}