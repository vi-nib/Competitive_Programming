#include <bits/stdc++.h>
using namespace std; 

// negate entries so that it acts as a minimum priority queue

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    string r;
    int Q, P, K;
    priority_queue<pair<pair<int, int>, int>> queries;
    
    // first will contain actual period, second will contain id number, third will contain incremental period

    while (cin>>r) {
        if (r == "#") {
            cin>>K;
            break;
        }
        cin>>Q>>P;
        queries.push({{-P, -Q}, -P});
    }
    
    pair<pair<int, int>, int> values;
    
    for (int i = 0; i < K; i++) {
      values = queries.top();
      queries.pop();
      cout<<-1 * values.first.second<<"\n";
      queries.push({{values.first.first + values.second, values.first.second}, values.second});
    }
    
    return 0;

}