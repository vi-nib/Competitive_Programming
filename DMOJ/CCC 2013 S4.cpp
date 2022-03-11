#include <bits/stdc++.h>
using namespace std;

int N;
map<int, vector<int>> adj;

bool taller(int person1, int person2) {

    queue<int> q;
    q.push(person1);
    vector<bool> visited(N + 1);
    visited[person1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next: adj[current]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }

    return visited[person2];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int M;

    cin>>N>>M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    int v, n;
    cin>>v>>n;

    if (taller(v, n)) {
        cout<<"yes";
    }
    else if (taller(n, v)) {
        cout<<"no";
    }
    else {
        cout<<"unknown";
    }

    cout<<"\n";

    return 0;

}