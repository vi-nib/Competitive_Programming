#include <bits/stdc++.h>
using namespace std;

vector<int> next_node;
vector<int> sizes;

int find_parent(int node) {
  while (next_node[node] != node) {
    node = next_node[node];
  }
  return node;
}

void merge(int node1, int node2) {
  if (sizes[node1] < sizes[node2]) {
    swap(node1, node2);
  }
  next_node[node2] = node1;
  sizes[node1] += sizes[node2];
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  next_node.resize(N+1);
  sizes.resize(N+1);

  for (int i = 1; i <= N; i++) {
    next_node[i] = i;
    sizes[i] = 1;
  }

  int M;
  cin>>M;

  while (M--) {
    int K_i;
    cin>>K_i;
    vector<int> students(K_i);
    for (int i = 0; i < K_i; i++) {
      cin>>students[i];
    }
    for (int i = 1; i < K_i; i++) {
      int student1 = find_parent(students[i]);
      int student2 = find_parent(students[i-1]);
      if (student1 != student2) {
        merge(student1, student2);
      }
    }
  }

  int infectedStudent = find_parent(1);

  cout<<sizes[infectedStudent]<<"\n";

  for (int i = 1; i <= N; i++) {
    if (infectedStudent == find_parent(i)) {
      cout<<i<<" ";
    }
  }

  cout<<"\n";

  return 0;
  
}