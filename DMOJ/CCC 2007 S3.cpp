#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin>>N;
    map<int, vector<int>> adj;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin>>x>>y;

        adj[x].push_back(y);
    }

    int p, t;
    cin>>p>>t;

    while (p != 0 && t != 0) {

   vector<int> distance(N + 1);
   queue<int> q;

   distance[p] = 0;

   q.push(p);

   vector<bool> visited(N + 1);

   visited[p] = true;

   while (!q.empty()) {
       int current = q.front();
       q.pop();
       for (auto next: adj[current]) {
           if (!visited[next]) {
           distance[next] = distance[current] + 1;
           q.push(next);
           visited[next] = true;
           }
       }
   }

   if (distance[t] - 1 < 0) {
       cout<<"No";
   }
   else {
       cout<<"Yes "<<distance[t] - 1;
   }

   cout<<"\n";

   cin>>p>>t;

   if (p == 0 && t == 0) {
       break;
   }

   }
   
   return 0;

}