#include <bits/stdc++.h>
using namespace std;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin>>N;

  vector<int> measurements(N);

  for (int i = 0; i < N; i++) {
    cin>>measurements[i];
  }

  sort(measurements.begin(), measurements.end());

  vector<int> lowTide;
  vector<int> highTide;


  if (N % 2 == 0) {

    for (int i = 0; i < N / 2; i++) {
      lowTide.push_back(measurements[i]);
      }
      sort(lowTide.rbegin(), lowTide.rend());

    for (int i = N/2; i < N; i++) {
      highTide.push_back(measurements[i]);
      }

    for (int i = 0; i < N/2; i++) {
      cout<<lowTide[i]<<" "<<highTide[i]<<" ";
    }

}

  if (N % 2 != 0) {

    int middle = N / 2;

    for (int i = 0; i <= middle; i++) {
      lowTide.push_back(measurements[i]);
    }
    sort(lowTide.rbegin(), lowTide.rend());

    for (int i = middle + 1; i < N; i++) {
      highTide.push_back(measurements[i]);
    }

    for (int i = 0; i < middle; i++) {
      cout<<lowTide[i]<<" "<<highTide[i]<<" ";
    }
    cout<<lowTide[middle]<<"\n";

  }

  return 0;
  
}