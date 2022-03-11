#include <bits/stdc++.h>
using namespace std;

vector<int> next_nodes;
vector<int> sizes;

int find_parent(int node) {
  while (next_nodes[node] != node) {
    node = next_nodes[node];
  }
  return node;
}

void merge(int node1, int node2) {
  if (sizes[node1] < sizes[node2]) {
    swap(node1, node2);
  }
  next_nodes[node2] = node1;
  sizes[node1] += sizes[node2];


}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  next_nodes.resize(N+1);
  sizes.resize(N+1);

  for (int i = 1; i <= N; i++) {
    next_nodes[i] = i;
    sizes[i] = 1;
  }

  int M;
  cin>>M;

  vector<int> answer;

  for (int i = 1; i <= M; i++) {
    int u_i, v_i;
    cin>>u_i>>v_i;

    int root1 = find_parent(u_i);
    int root2 = find_parent(v_i);

    if (root1 != root2) {
      answer.push_back(i);
      merge(root1, root2);
    }
  }

  if ((int)answer.size() < N - 1) {
    cout<<"Disconnected Graph"<<"\n";
  }

  else {
    for (int i : answer) {
      cout<<i<<"\n";
  }

  }

  return 0;
}