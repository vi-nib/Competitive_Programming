#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;

bool connected(string start, string end) {
    queue<string> q;
    map<string, bool> visited;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        for (auto next : adj[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return visited[end];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int X;
    cin>>X;

    vector<pair<string, string>> together(X);

    string a, b, c;    

    for (int i = 0; i < X; i++) {
        cin>>a>>b;
        together[i] = {a, b};
    }
    
    int Y;
    cin>>Y;

    vector<pair<string, string>> away(Y);

    for (int i = 0; i < Y; i++) {
        cin>>a>>b;
        away[i] = {a, b};
    }

    int G;
    cin>>G;

    for (int i = 0; i < G; i++) {
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adj[a].push_back(c);
        adj[c].push_back(a);
        adj[b].push_back(c);
        adj[c].push_back(b);
    }

    int count = 0;

    for (int i = 0; i < X; i++) {
        bool a = connected(together[i].first, together[i].second);
        if (!a) {
            count++;
        }
    }

    for (int j = 0; j < Y; j++) {
         bool b = connected(away[j].first, away[j].second);
         if (b) {
             count++;
         }
    }

    cout<<count<<"\n";

    return 0;

}