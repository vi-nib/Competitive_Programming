#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p; // n is number of requirements and p is number of proposals
    string dummy; // requirements
    string otherDummy; // requirementsSatisfied
    string proposalName;
    double d = 1e6; // price of best proposal
    int r = -1; // numSatisfied

    int index = 1;

    while (cin>>n>>p) {
        if (n == 0 && p == 0) {
            break;
        }
        if (index != 1) {
          cout<<"\n";
        }
        cin.ignore();
        while (n--) {
            getline(cin, dummy);
        }

        for (int i = 0; i < p; i++) {
            string name;
            double price;
            int satisfied;
            getline(cin, name);
            cin>>price>>satisfied;
            if (satisfied > r) {
                proposalName = name;
                d = price;
                r = satisfied;
            }
            if (satisfied == r && price < d) {
                proposalName = name;
                d = price;
                r = satisfied;
            }

            while (satisfied--) {
                cin.ignore();
                getline(cin, otherDummy);
            }

        }
        cout<<"RFP #"<<index<<"\n";
        cout<<proposalName<<"\n";
        index++;
        d = 1e6;
        r = -1;
    }

    

    return 0;
}