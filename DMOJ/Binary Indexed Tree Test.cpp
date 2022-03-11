#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, M;

int elements[100001];
int bit_sum[100001];
int bit_freq[100001];


void change(int place, int changeAmount) {
  while (place <= N) {
    bit_sum[place] += changeAmount;
    place += place& - place;
  }
}

int prefix_sum(int place) {
  int sum = 0;
  while (place >= 1) {
    sum += bit_sum[place];
    place -= place& - place;
  }
  return sum;
}

int prefix_frequency(int value) {
  int frequency = 0;
  while (value >= 1) {
    frequency += bit_freq[value];
    value -= value& - value;
  }
  return frequency;
}

void increment_frequency(int place) {
  while (place <= 100000) {
    bit_freq[place]++;
    place += place& - place;
  }
}

void decrement_frequency(int place) {
  while (place <= 100000) {
    bit_freq[place]--;
    place += place& - place;
  }
}


signed main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  cin>>N>>M;

  for (int i = 1; i <= N; i++) {
    cin>>elements[i];
    change(i, elements[i]);
    increment_frequency(elements[i]);
  }

  while (M--) {
    char option;
    cin>>option;
    
    if (option == 'C') {
      int x, y;
      cin>>x>>y;
      change(x, y - elements[x]);
      increment_frequency(y);
      decrement_frequency(elements[x]);
      elements[x] = y;
    }
    else if (option == 'S') {
      int l, r;
      cin>>l>>r;
      int sum = prefix_sum(r) - prefix_sum(l-1);
      cout<<sum<<"\n";
    }
    else {
      int v;
      cin>>v;
      int frequency = prefix_frequency(v);
      cout<<frequency<<"\n";
    }

  }

  return 0;
  
}