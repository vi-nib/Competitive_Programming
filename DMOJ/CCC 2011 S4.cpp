#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;

bool distance(int startNode, int endNode) {

  queue<int> q;
  vector<int> distances(7);
  vector<bool> visited(7);
  q.push(startNode);
  distances[startNode] = 0;
  visited[startNode] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    for (auto next: adj[current]) {
      if (!visited[next]) {
        visited[next] = true;
        distances[next] = distances[current] + 1;
        q.push(next);
      }
    }
  }

  return visited[endNode];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    vector<int> bloodAvailable(8);
    vector<int> bloodNeeded(8);

    for (int i = 0; i < 8; i++) {
        cin>>bloodAvailable[i];
    }

    for (int i = 0; i < 8; i++) {
        cin>>bloodNeeded[i];
    }

    adj[0] = {0};
    adj[1] = {0};
    adj[2] = {0};
    adj[3] = {2, 1, 0};
    adj[4] = {0};
    adj[5] = {4, 1, 0};
    adj[6] = {4, 2, 0};
    adj[7] = {6, 5, 4, 3, 2, 1, 0};

    int count = 0;

    for (int i = 0; i < 8; i++) {

        int number = bloodAvailable[i] - bloodNeeded[i];

        if (number >= 0) {
            count += bloodNeeded[i];
            bloodNeeded[i] -= bloodNeeded[i];
            bloodAvailable[i] = number;
        }

        else {
            count += bloodAvailable[i];
            bloodAvailable[i] -= bloodAvailable[i];
            bloodNeeded[i] = abs(number);
        }
    }

        for (int i = 0; i < 8; i+=2) {

            if (bloodNeeded[i] == 0) {
                continue;
            }

            else {

                for (int j = 0; j < 8; j++) {
                    if (bloodAvailable[j] > 0 && distance(i, j)) {
                        int number = bloodAvailable[j] - bloodNeeded[i];
                        if (number <= 0) {
                            count += bloodAvailable[j];
                            bloodAvailable[j] -= bloodAvailable[j];
                            bloodNeeded[i] = abs(number);
                    }
                        else {
                            count += bloodNeeded[i];
                            bloodNeeded[i] -= bloodNeeded[i];
                            bloodAvailable[j] = number;
                            break;
                    }
                }
            }
        }
    }
        for (int i = 1; i < 8; i+=2) {
            if (bloodNeeded[i] == 0) {
                continue;
            }
            else {

                for (int j = 0; j < 8; j++) {
                    if (bloodAvailable[j] > 0 && distance(i, j)) {
                        int number = bloodAvailable[j] - bloodNeeded[i];
                        if (number <= 0) {
                            count += bloodAvailable[j];
                            bloodAvailable[j] -= bloodAvailable[j];
                            bloodNeeded[i] = abs(number);
                    }
                    else {
                        count += bloodNeeded[i];
                        bloodNeeded[i] -= bloodNeeded[i];
                        bloodAvailable[j] = number;
                        break;
                    }
                }
            }
        }  
    }


    cout<<count<<"\n";

    return 0;

}