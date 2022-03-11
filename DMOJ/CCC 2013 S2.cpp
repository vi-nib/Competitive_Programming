#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int W, N;
  cin>>W>>N;

  vector<int> cars;

  for (int i = 0; i < 3; i++) {
    cars.push_back(0);
  }

  for (int i = 0; i < N; i++) {
    int value;
    cin>>value;
    cars.push_back(value);
  }

  cars.push_back(W+5);

  int count = 0;
  int index = 3; 

  int combinedWeight = cars[index] + cars[index-1] + cars[index-2] + cars[index-3];

  while (combinedWeight <= W) {
    count++;
    index++;
    combinedWeight = cars[index] + cars[index-1] + cars[index-2] + cars[index-3];
  }

  cout<<count<<"\n";

  return 0;

}