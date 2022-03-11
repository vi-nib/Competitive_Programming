#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    cin>>ws;
    
    string tree;

    while (n--) {
        map<string, int> occurrences;
        vector<pair<string, double>> percents;
        int numTrees = 0;
        while (getline(cin, tree) && !tree.empty()) {
            occurrences[tree]++;
            numTrees++;
        }
        for (auto i : occurrences) {
            double x = ((double) i.second / (double) numTrees) * 100;
            percents.push_back({i.first, x});
        }

        sort(percents.begin(), percents.end());

        for (int i = 0; i < percents.size(); i++) {
            cout<<percents[i].first<<" ";
            cout << fixed << setprecision(4) << percents[i].second << "\n";
        }
        
        if (n > 0) {
            cout<<"\n";
        }

    }

    return 0;
    
}