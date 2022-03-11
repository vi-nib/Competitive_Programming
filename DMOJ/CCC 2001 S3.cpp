#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char, vector<char>> adj;
    vector<string> roads;

    while (true) {
        string road;
        cin>>road;
        roads.push_back(road);

        if (road == "**") {
            break;
        }

        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);

    }

    int count = 0;

    for (auto road: roads) {

        map<char, bool> visited;
        queue<char> q;

        q.push('A');
        visited['A'] = true;

        while (!q.empty()) {
            char current = q.front();
            q.pop();
            for (auto next: adj[current]) {
                if (current == road[0] && next == road[1]) {
                    continue;
                }
                if (current == road[1] && next == road[0]) {
                    continue;
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
            }

            }
        }

        if (!visited['B']) {
            cout<<road<<"\n";
            count++;
        }   

    }

    cout<<"There are "<<count<<" disconnecting roads.\n";

    return 0;

}