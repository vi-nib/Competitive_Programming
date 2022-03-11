#include <bits/stdc++.h>
using namespace std;

char s[1005][1005];
char l[1008][1008];

int N, n;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin>>N>>n) {
    if (N == 0 && n == 0) {
      break;
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin>>l[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin>>s[i][j];
      }
    }

    int rotationCount = 0;

    while (rotationCount <= 3) {
        
        if (rotationCount != 0) {
            cout<<" ";
        }

      int count = 0;
      for (int i = 0; i <= N-n; i++) {
        for (int j = 0; j <= N-n; j++) {
          bool found = true;
          for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
              if (s[x][y] != l[i+x][j+y]) {
                found = false;
              }
            }
          }
          if (found) {
            count++;
          }
        }
      }

      cout<<count;

      char rotate[n+1][n+1]; // use this grid to copy into other grid

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          rotate[j][n-i-1] = s[i][j];
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          s[i][j] = rotate[i][j];
        }
      }

      rotationCount++;

    }

    cout<<"\n";

  }
 
  return 0;
  
}