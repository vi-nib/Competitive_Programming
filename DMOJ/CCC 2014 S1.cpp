#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int K, M;
  cin>>K>>M;

  vector<int> friends(K+1);

  for (int i = 1; i <= K; i++) {
    friends[i] = i;
  }

  for (int i = 0; i < M; i++) {

    int value;
    cin>>value;

    int index = 1;

    while (index < (int)friends.size()) {
      if (index % value == 0) {
        friends[index] = 0;
      }
      index++;
    }

    int newIndex = 1;

    while (newIndex < (int)friends.size()) {
      if (friends[newIndex] == 0) {
        friends.erase(friends.begin() + newIndex);
      }
      else {
        newIndex++;
      }
    }

  }

  for (int i = 1; i < (int)friends.size(); i++) {
    cout<<friends[i]<<"\n";
  }

  return 0;

}