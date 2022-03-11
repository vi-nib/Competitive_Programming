#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

vector<vector<pair<int, int>>> adj;
map<string, int> nodeConversion;

void distance(int start, int end) {

    set<pair<int, int>> pq;
    vector<int> distances(n+1); 

    for (int i = 1; i <= n; i++) {
       distances[i] = 10000000000001;
    }

    pq.insert({0, start});

    distances[start] = 0;

    while (!pq.empty()) {
        pair<int, int> curr = *pq.begin();
        pq.erase(pq.begin());
        for (auto next : adj[curr.second]) {
            if (curr.first + next.second < distances[next.first]) {
                distances[next.first] = curr.first + next.second;
                pq.insert({distances[next.first], next.first});
            }
        }
    }

    if (distances[end] != 10000000000001) {
        cout<<distances[end]<<"\n";
    }
    else {
        cout<<"Roger\n";
    }

}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>n>>m;

    adj.assign(n+1, vector<pair<int, int>>());

    string x, y;
    int t, counter = 1;

    int x1 = 0, y1 = 0;

    for (int i = 0; i < m; i++) {
        cin>>x>>y>>t;
        auto it1 = nodeConversion.find(x);
        auto it2 = nodeConversion.find(y);
        if (it1 == nodeConversion.end()) {
            nodeConversion[x] = counter;
            x1 = counter;
            counter++;
        }
        else {
            x1 = nodeConversion[x];
        }

        if (it2 == nodeConversion.end()) {
            nodeConversion[y] = counter;
            y1 = counter;
            counter++;
        }
        else {
            y1 = nodeConversion[y];
        }

        adj[x1].push_back({y1, t});
    }

    int q;
    cin>>q;

    string a, b;
    int a1 = 0, b1 = 0;

    for (int i = 0; i < q; i++) {
        cin>>a>>b;
        a1 = nodeConversion[a];
        b1 = nodeConversion[b];
        distance(a1, b1);
    }

    return 0;

}