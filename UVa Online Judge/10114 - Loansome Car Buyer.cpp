#include <bits/stdc++.h>
using namespace std;

bool isEqual(double a, double b) {
  return abs(a-b) < 1e-5; 
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int loanDuration, depRecords;
    double downPayment, amountLoan;

    while (cin>>loanDuration>>downPayment>>amountLoan>>depRecords) {
       
        if (loanDuration < 0) {
            break;
        }

        vector<double> depreciationRecords(loanDuration, 0.0);

        for (int i = 0; i < depRecords; i++) {
            int month;
            cin>>month;
            cin>>depreciationRecords[month];
        }

        for (int i = 0; i < depreciationRecords.size(); i++) {
            if (isEqual(depreciationRecords[i], 0.0)) {
                depreciationRecords[i] = depreciationRecords[i-1];
            }
        }

        int count = 0;
        int i = 1;

        double carValue = (amountLoan + downPayment) * (1-depreciationRecords[0]);
        double monthlyPayment = amountLoan / loanDuration;

        while (amountLoan - carValue > 1e-5) {
            carValue *= (1-depreciationRecords[i++]);
            amountLoan -= monthlyPayment;
            count++;
        }

        if (count != 1) {
            cout<<count<<" months\n";
        }
        else {
            cout<<count<<" month\n";
        }

    }

    return 0;
}