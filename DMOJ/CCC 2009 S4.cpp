#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, T; // N is number of nodes (cities) and T is the number of trade routes (edges)
    cin>>N>>T;

    vector<vector<pair<int, int>>> adj(N+1);
    

    for (int i = 0; i < T; i++) {
        int x, y, c; // x is city 1, y is city 2, and c is the transportation cost between x and y
        cin>>x>>y>>c;

        adj[x].push_back({y, c});
        adj[y].push_back({x, c});

    }

    int K; // number of cities that have pencils
    cin>>K;

    vector<int> pencilPrices(N+1, -5); // Prices of pencils, where cities that don't sell pencils have a value of -5

    for (int i = 1; i <= K; i++) {
        int z, p; // z is city and p is the price of pencil in city z
        cin>>z>>p;
        pencilPrices[z] = p;
    }

    int D; // this is the destination city
    cin>>D;

   set<pair<int, int>> pq;
   vector<int> costs(N+1);

   for (int i = 1; i <= N; i++) {
       costs[i] = 1e9;
   }

   pq.insert({0, D});

   costs[D] = 0;

   while (!pq.empty()) {
       pair<int, int> curr = *pq.begin();
       pq.erase(pq.begin());
       for (auto next : adj[curr.second]) {
           if (curr.first + next.second < costs[next.first]) {
               costs[next.first] = curr.first + next.second;
               pq.insert({costs[next.first], next.first});
           }
       }
   }

   int answer = 1e9;

   for (int i = 1; i <= N; i++) {
       if (pencilPrices[i] != -5) {
           answer = min(answer, costs[i] + pencilPrices[i]);
       }
   }
   
   cout<<answer<<"\n";
   
   return 0;
   
}