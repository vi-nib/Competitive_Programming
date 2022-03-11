#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // Streams are numbered from 1 to N, left to right

    int N; // number of streams initially
    cin>>N;

    vector<double> flow(N+1);

    for (int i = 1; i <= N; i++) {
        int value;
        cin>>value;
        double newValue = double(value);
        flow[i] = newValue;
    }

    int splitJoin;
    cin>>splitJoin;

    while (splitJoin != 77) {

        if (splitJoin == 99) {

            int streamNumber;
            int percentageToLeft;
            cin>>streamNumber>>percentageToLeft;

            double value = flow[streamNumber] * (double(percentageToLeft) / 100.0);

            flow[streamNumber] = flow[streamNumber] * (double(100 - percentageToLeft) / 100.0);

            flow.insert(flow.begin() + streamNumber, value);

            cin>>splitJoin;

            if (splitJoin == 77) {
                break;
            }

        }

        if (splitJoin == 88) {

            int streamNumber;
            cin>>streamNumber;

            if (streamNumber < flow.size() - 1) {

              double value = flow[streamNumber] + flow[streamNumber + 1];

              flow.erase(flow.begin() + (streamNumber+1));

              flow[streamNumber] = value;

            }

            cin>>splitJoin;

            if (splitJoin == 77) {
                break;
            }

        }

    }

    for (int i = 1; i < flow.size(); i++) {
      cout<<flow[i]<<" ";
    }

    return 0;

}