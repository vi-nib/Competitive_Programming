#include <bits/stdc++.h>
using namespace std;

vector<int> l;

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin>>T;

  while (T--) {
    int N;
    cin>>N;
    stack<int> s;
    l.resize(N);
    int curr = 1;
    int ingredient;
    for (int i = 0; i < N; i++) {
      cin>>l[i];
    }
    reverse(l.begin(), l.end());
    
    for (int i = 0; i < N; i++) {
        ingredient = l[i];
        while (!s.empty()) {
            if (s.top() == curr) {
                curr++;
                s.pop();
            }
            else {
                break;
            }
            
        }
        if (ingredient > curr) {
            s.push(ingredient);
        }
        if (ingredient == curr) {
                curr++;
        }
    }
    
    
    bool done = false;
    
    
    while (!s.empty()) {
        int top1 = s.top();
        s.pop();
        if (top1 != curr) {
            cout<<"N\n";
            done = true;
            break;
        }
        else {
            curr++;
        }
    }
    if (!done) {
        cout<<"Y\n";
    }
}

  return 0;

}