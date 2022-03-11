#include <bits/stdc++.h>
using namespace std;

#define int long long

int product(int i, int j) {
  cout<<"? "<<i<<" "<<j<<"\n";
  cout << flush;
  int x;
  cin>>x;
  return x;
}

signed main() {

    int N;
    cin>>N;

    vector<int> P(N+3);

    int x;

    for (int i = 2; i <= N; i++) {
        x = product(1, i);
        P[i] = x;
    }

    int maxVal = 0;
    int minVal = 1e8;

    for (int i = 2; i <= N; i++) {
        minVal = min(minVal, P[i]);
        maxVal = max(maxVal, P[i]);
    }

    int a_1 = 0;

    if (maxVal == N) {
        a_1 = 1;
    }

    else {
        a_1 = minVal;
    }

    P[1] = a_1;

    for (int i = 2; i <= N; i++) {
        P[i] /= a_1;
    }

    cout<<"!";

    for (int i = 1; i <= N; i++) {
        cout<<" "<<P[i];
    }

    cout<<"\n";

    return 0;

}