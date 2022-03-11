#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;

int findDistance(int startNode, int endNode) {

  queue<int> q;
  vector<int> distances(100001);
  vector<bool> visited(100001);

  q.push(startNode);
  distances[startNode] = 1;
  visited[startNode] = true;

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

  if (distances[endNode] == 0) {
    return -1;
  }

  return distances[endNode]; 

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;
  
  while (t--) {
      
    adj.clear();
      
    int r, c;
    cin>>r>>c;

    char grid[r][c];

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin>>grid[i][j];
      }
    }

    int numberGrid[r][c];

    int count = 1;

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        numberGrid[i][j] = count;
        count++;
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == '*') {
          continue;
        }
        else if (grid[i][j] == '+') {
          if (grid[i-1][j] != '*' && i > 0) {
            adj[numberGrid[i][j]].push_back(numberGrid[i-1][j]);
          }
          if (grid[i+1][j] != '*' && i < (r-1)) {
            adj[numberGrid[i][j]].push_back(numberGrid[i+1][j]);
          }
          if (grid[i][j+1] != '*' && j < (c-1)) {
            adj[numberGrid[i][j]].push_back(numberGrid[i][j+1]);
          }
          if (grid[i][j-1] != '*' && j > 0) {
            adj[numberGrid[i][j]].push_back(numberGrid[i][j-1]);
          }
        }

        else if (grid[i][j] == '-') {
          if (grid[i][j+1] != '*' && j < (c-1)) {
            adj[numberGrid[i][j]].push_back(numberGrid[i][j+1]);
          }
          if (grid[i][j-1] != '*' && j > 0) {
            adj[numberGrid[i][j]].push_back(numberGrid[i][j-1]);
          }
        }

        else {
          if (grid[i-1][j] != '*' && i > 0) {
            adj[numberGrid[i][j]].push_back(numberGrid[i-1][j]);
          }
          if (grid[i+1][j] != '*' && i < (r-1)) {
            adj[numberGrid[i][j]].push_back(numberGrid[i+1][j]);
          }
        }
      }
    }

    cout<<findDistance(1, (count-1))<<"\n";
 
  }

  return 0;

}