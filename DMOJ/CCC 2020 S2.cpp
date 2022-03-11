#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int M, N;
  cin>>M>>N;

  map<int, vector<int>> adj;
  vector<bool> visited(M * N + 1);

  int first_value;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      int value;
      cin>>value;
      if (i == 1 && j == 1) {
        first_value = value;
      }
      adj[i * j].push_back(value);
    }
  }

  queue<int> q;
  q.push(first_value);
  visited[first_value] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (auto next : adj[current]) {
      if (!visited[next]) {
        q.push(next);
        visited[next] = true;
      }
    }
  }

  if (visited[M * N]) {
    cout<<"yes"<<"\n";
  }

  else {
    cout<<"no"<<"\n";
  }

  return 0;

}