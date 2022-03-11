#include <bits/stdc++.h>
using namespace std;

struct store {

  string product;
  int price;
  int quantity;

};

bool storeSorting(store a, store b) {
  if (a.product != b.product) {
    return a.product < b.product;
  }
  else if (a.price != b.price) {
    return a.price < b.price;
  }
  return a.quantity > b.quantity;
}

void solver(vector<store>& options, vector<pair<string, int>> &need) {

  int i = 0;
  int answer = 0;

  while (i < (int)need.size()) {
    int q = need[i].second;
    for (int j = 0; j < (int)options.size(); j++) {
      if (options[j].product == need[i].first) {
        if (options[j].quantity >= q) {
          answer += (q * options[j].price);
          break;
        }
        else {
          answer += (options[j].price * options[j].quantity);
          q -= options[j].quantity;
        }
      }
    }
    i++;
  }

  cout<<answer<<"\n";

}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin>>T;

  int N, M, P, Q;
  string S;

  int K;

  string name;
  int quantity;

  while (T--) {
    cin>>N;
    vector<store> stuff;
    while (N--) {
      cin>>M;
      for (int i = 0; i < M; i++) {
        cin>>S>>P>>Q;
        store s = {S, P, Q};
        stuff.push_back(s);
      }
    }
    sort(stuff.begin(), stuff.end(), storeSorting);
    cin>>K;
    vector<pair<string, int>> want;
    for (int i = 0; i < K; i++) {
      cin>>name>>quantity;
      want.push_back({name, quantity});
    }
    sort(want.begin(), want.end());
    solver(stuff, want);

  }

  return 0;

}