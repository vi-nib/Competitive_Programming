#include <bits/stdc++.h>
using namespace std;

bool sorting(pair<int, int> x, pair<int, int> y) {

    int secondX = x.second;

    int secondY = y.second;

    return secondX > secondY;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;

    // Creating frequency map

    map<int, int> frequency;

    for (int i = 0; i < N; i++) {
        int x;
        cin>>x;
        frequency[x]++;
    }

    // Converting frequency map to vector of pairs

    vector<pair<int, int>> measurements;

    for (auto i : frequency) {
        int first = i.first;
        int second = i.second;
        measurements.push_back(make_pair(first, second));
    }

    // Sorting vector of pairs into ascending order

    sort(measurements.begin(), measurements.end(), sorting);

    if (measurements[0].second > measurements[1].second) {
        if (measurements[1].second > measurements[2].second) {
            cout<<abs(measurements[0].first - measurements[1].first)<<"\n";
        }

        else {

            // The case where there are multiple readings with the second highest frequency. We must pick the reading that has the largest absolute difference than the first reading.

            vector<int> tiedSecond;
            int size = measurements.size();
            int index = 1;
            
            while (index < size) {
                if (measurements[index].second == measurements[1].second) {
                    tiedSecond.push_back(measurements[index].first);
                }
                index++;
            }
            
            int answer = 0;
            
            for (int i = 0; i < (int)tiedSecond.size(); i++) {
                int sub = abs(tiedSecond[i] - measurements[0].first);
                answer = max(answer, sub);
            }
            cout<<answer<<"\n";
        }
            
    }

    if (measurements[0].second == measurements[1].second) {
        int largeAnswer = measurements[0].first;
        int minAnswer = measurements[0].first;
        for (int i = 1; i < (int)measurements.size(); i++) {
            if (measurements[i].second == measurements[0].second) {
                largeAnswer = max(largeAnswer, measurements[i].first);
                minAnswer = min(minAnswer, measurements[i].first);
            }
        }
        cout<<abs(largeAnswer - minAnswer)<<"\n";
    }

    return 0;

}