#include <bits/stdc++.h>
using namespace std;

map<string, vector<string>> adj;

int distance(string startNode, string endNode) {

  queue<string> q;
  map<string, bool> visited;
  map<string, int> distances;

  q.push(startNode);
  visited[startNode] = true;

  distances[startNode] = 0;

  while (!q.empty()) {
    string current = q.front();
    q.pop();
    for (auto next : adj[current]) {
      if (!visited[next]) {
        visited[next] = true;
        distances[next] = distances[current] + 10;
        q.push(next);
      }
    }
  }

  return distances[endNode];

}

int largestDistance(string startNode) {

  queue<string> q;
  map<string, bool> visited;
  map<string, int> distances;

  q.push(startNode);
  visited[startNode] = true;

  distances[startNode] = 0;

  while (!q.empty()) {
    string current = q.front();
    q.pop();
    for (auto next : adj[current]) {
      if (!visited[next]) {
        visited[next] = true;
        distances[next] = distances[current] + 10;
        q.push(next);
      }
    }
  }

  int maxDistance = -1;

  for (auto element : distances) {
    int length = element.second;
    maxDistance = max(maxDistance, length);
  }

  return maxDistance * 2;
  
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int L;
  cin>>L;

  int n;

  while (L--) {

    adj.clear();

    cin>>n;

    vector<string> names(n);

    for (int i = 0; i < n; i++) {
      cin>>names[i];
    }

    reverse(names.begin(), names.end());

    string startingName = names[0];

    for (int i = 0; i < n-1; i++) {
      adj[names[i]].push_back(names[i+1]);
    }

    adj[names[n-1]].push_back(names[0]);

    int oldTime = 0;

    for (int i = 0; i < n-1; i++) {
      oldTime += distance(names[i], names[i+1]);
    }

    oldTime += distance(names[n-1], names[0]);

    int newTime = largestDistance(names[0]);

    int finalAnswer = oldTime - newTime;

    cout<<finalAnswer<<"\n";

  }

  return 0;
  
}