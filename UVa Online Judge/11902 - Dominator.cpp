#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, vector<int>> adj;

vector<bool> visited;
vector<bool> initial;

int N;

void bfs(int stopper) {

    fill_n(visited.begin(), N, false);
    queue<int> q;
    q.push(0);

    if (stopper == 0) {
        return;
    }

    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next : adj[current]) {
            if (next == stopper) {
                continue;
            }
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void printDivider(int n) {
    cout<<"+";
    for (int i = 0; i < (2*n)-1; i++) {
        cout<<"-";
    }
    cout<<"+\n";
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    for (int w = 1; w <= T; w++) {
        cin>>N;

        int connected;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin>>connected;
                if (connected == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        visited.resize(N);
        initial.resize(N);

        bfs(N+1);
        for (int i = 0; i < (int)visited.size(); i++) {
            initial[i] = visited[i];
        }

        cout<<"Case "<<w<<":\n";

        for (int i = 0; i < N; i++) {
            bfs(i);
            printDivider(N);
            for (int j = 0; j < N; j++) {
                if (initial[j] == 0 || visited[j] == 1) {
                    cout<<"|N";
                }
                else {
                    cout<<"|Y";
                }
            }
            cout<<"|\n";
        }
        printDivider(N);

        adj.clear();

    }

    return 0;
    
}