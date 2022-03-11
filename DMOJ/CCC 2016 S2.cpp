#include <bits/stdc++.h>
using namespace std;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);

  int questionType;
  cin>>questionType;

  int N;
  cin>>N;
  vector<int> dSpeeds(N);
  vector<int> pSpeeds(N);

  for (int i = 0; i < N; i++) {
    cin>>dSpeeds[i];
  }

  for (int i = 0; i < N; i++) {
    cin>>pSpeeds[i];
  }

  sort(dSpeeds.rbegin(), dSpeeds.rend());
  sort(pSpeeds.rbegin(), pSpeeds.rend());

  if (questionType == 1) {

    int minTotalSpeed = 0;

    for (int i = 0; i < N; i++) {
      int speed = max(dSpeeds[i], pSpeeds[i]);
      minTotalSpeed += speed;
    }

    cout<<minTotalSpeed<<"\n";

  }

  if (questionType == 2) {

    int maxTotalSpeed = 0;

    sort(pSpeeds.begin(), pSpeeds.end());

    for (int i = 0; i < N; i++) {
      int speed = max(dSpeeds[i], pSpeeds[i]);
      maxTotalSpeed += speed;
    }

    cout<<maxTotalSpeed<<"\n";

  }

  return 0;
  
}