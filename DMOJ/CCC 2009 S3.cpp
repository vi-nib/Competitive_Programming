#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;

vector<int> friendFinder(int start) {
    queue<int> q;
    vector<bool> visited(51);
    vector<int> distances(51);
    q.push(start);
    visited[start] = true;
    distances[start] = 0;   

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next : adj[current]) {
            if (!visited[next]) {
                visited[next] = true;
                distances[next] = distances[current] + 1;
                q.push(next);
            }
        }
    }

    return distances;

}

int degSeparation(int start, int end) {
    queue<int> q;
    vector<bool> visited(51);
    vector<int> distances(51);
    q.push(start);
    visited[start] = true;
    distances[start] = 0;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto next : adj[current]) {
            if (!visited[next]) {
                visited[next] = true;
                distances[next] = distances[current] + 1;
                q.push(next);
            }
        }
    }
    return distances[end];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    adj[1] = {6};
    adj[2] = {6};
    adj[3] = {6, 4, 5, 15};
    adj[4] = {6, 3, 15};
    adj[5] = {3, 4, 6};
    adj[6] = {1, 2, 7, 3, 4, 5};
    adj[7] = {6, 8};
    adj[8] = {7, 9};
    adj[9] = {8, 12, 10};
    adj[10] = {9, 11};
    adj[11] = {10, 12};
    adj[12] = {9, 11, 13};
    adj[13] = {12, 15, 14};
    adj[14] = {13};
    adj[15] = {3, 13};
    adj[16] = {17, 18};
    adj[17] = {16, 18};
    adj[18] = {16, 17};

    char option;
    
    while (cin>>option) {
        if (option == 'q') {
            break;
        }
        else if (option == 'i') {
            int x, y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        else if (option == 'd') {
            int x, y;
            cin>>x>>y;
            for (int i = 0; i < (int)adj[x].size(); i++) {
                if (adj[x][i] == y) {
                    adj[x].erase(adj[x].begin() + i);
                }
            }
            for (int j = 0; j < (int)adj[y].size(); j++) {
                if (adj[y][j] == x) {
                    adj[y].erase(adj[y].begin() + j);
                }
            }
        }
        else if (option == 'n') {
            int x;
            cin>>x;
            int count = 0;
            vector<int> connections = friendFinder(x);
            for (int i = 0; i < (int)connections.size(); i++) {
                if (connections[i] == 1) {
                    count++;
                }
            }
            cout<<count<<"\n";
        }
        else if (option == 'f') {
            int x;
            cin>>x;
            int count = 0;
            vector<int> friendsOfFriends = friendFinder(x);
            for (int i = 0; i < (int)friendsOfFriends.size(); i++) {
                if (friendsOfFriends[i] == 2) {
                    count++;
                }
            }
            cout<<count<<"\n";
        }
        else if (option == 's') {
            int x, y;
            cin>>x>>y;
            int distance = degSeparation(x, y);
            if (distance > 0) {
                cout<<distance<<"\n";
            }
            else {
                cout<<"Not connected\n";
            }
        }
    }

    return 0;
    
}