#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;

bool connected(int start, int end) {
    queue<int> q;
    vector<bool> visited(2100);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next: adj[current]) {
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

    int N, M, A, B;
    cin>>N>>M>>A>>B;

    int X, Y;

    for (int i = 0; i < M; i++) {
        cin>>X>>Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    if (connected(A, B)) {
        cout<<"GO SHAHIR!\n";
    }
    else {
        cout<<"NO SHAHIR!\n";
    }

    return 0;
    
}